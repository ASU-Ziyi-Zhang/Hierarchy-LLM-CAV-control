from __future__ import annotations

from typing import Any

from .state_builder import SignalStateBuilder, summarize_delay


class TraCISignalStateExtractor:
    """Extract local signal-agent states from a live TraCI simulation."""

    def __init__(self, traci_module: Any, state_builder: SignalStateBuilder, conn_range: float):
        self.traci = traci_module
        self.state_builder = state_builder
        self.conn_range = conn_range

    def _get_signal_lane_groups(self, tl_info: dict, tl_id: str):
        controlled_lanes = list(dict.fromkeys(self.traci.trafficlight.getControlledLanes(tl_id)))
        phase_lane_flags = tl_info.get(tl_id, {}).get("indUnqLanes", [])

        mainline_indices = set()
        for phase_idx in (1, 5):
            if phase_idx < len(phase_lane_flags):
                flags = phase_lane_flags[phase_idx]
                for lane_idx, flag in enumerate(flags):
                    if flag and lane_idx < len(controlled_lanes):
                        mainline_indices.add(lane_idx)

        if not mainline_indices and controlled_lanes:
            mainline_indices = set(range(0, len(controlled_lanes), 2))

        side_indices = set(range(len(controlled_lanes))) - mainline_indices
        mainline_lanes = [controlled_lanes[idx] for idx in sorted(mainline_indices)]
        side_lanes = [controlled_lanes[idx] for idx in sorted(side_indices)]
        return controlled_lanes, mainline_lanes, side_lanes

    def _estimate_queue_and_delay(self, lane_ids):
        halting = 0.0
        storage = 0.0
        waiting_times = []

        for lane_id in lane_ids:
            halting += self.traci.lane.getLastStepHaltingNumber(lane_id)
            storage += self.traci.lane.getLength(lane_id)
            for veh_id in self.traci.lane.getLastStepVehicleIDs(lane_id):
                waiting_times.append(self.traci.vehicle.getWaitingTime(veh_id))

        queue_length = halting * 7.5
        storage_ratio = min(1.5, queue_length / storage) if storage > 1e-6 else 0.0
        return halting, storage_ratio, summarize_delay(waiting_times)

    def _estimate_downstream_blocking(self, tl_id: str) -> bool:
        controlled_links = self.traci.trafficlight.getControlledLinks(tl_id)
        for link_group in controlled_links:
            for link in link_group:
                if len(link) > 1:
                    out_lane = link[1]
                    if out_lane and self.traci.lane.getLength(out_lane) > 1e-6:
                        occupancy = self.traci.lane.getLastStepOccupancy(out_lane) / 100.0
                        if occupancy >= 0.85:
                            return True
        return False

    def _estimate_cav_platoon(self, lane_ids):
        cav_count = 0
        eta_candidates = []

        for lane_id in lane_ids:
            lane_length = self.traci.lane.getLength(lane_id)
            for veh_id in self.traci.lane.getLastStepVehicleIDs(lane_id):
                veh_type = self.traci.vehicle.getTypeID(veh_id)
                if not (veh_type == "cav" or veh_type.startswith("cav_")):
                    continue

                lane_pos = self.traci.vehicle.getLanePosition(veh_id)
                distance_to_stop = max(0.0, lane_length - lane_pos)
                if distance_to_stop > self.conn_range:
                    continue

                cav_count += 1
                speed = max(0.1, self.traci.vehicle.getSpeed(veh_id))
                eta_candidates.append(distance_to_stop / speed)

        cav_eta = min(eta_candidates) if eta_candidates else None
        return cav_count, cav_eta

    def build_local_signal_states(self, tl_info: dict, spat_msg: dict, sim_time: float):
        states = {}
        for tl_id in tl_info.keys():
            controlled_lanes, mainline_lanes, side_lanes = self._get_signal_lane_groups(tl_info, tl_id)
            queue_mainline, mainline_ratio, delay_main = self._estimate_queue_and_delay(mainline_lanes)
            queue_side, side_ratio, delay_side = self._estimate_queue_and_delay(side_lanes)
            delays = [delay for delay in (delay_main, delay_side) if delay is not None]
            avg_delay = summarize_delay(delays)
            cav_count, cav_eta = self._estimate_cav_platoon(mainline_lanes or controlled_lanes)

            current_phase = self.traci.trafficlight.getPhase(tl_id) + 1
            phase_count = len(tl_info.get(tl_id, {}).get("timingTable", [])) or 8
            next_phase = 1 + (current_phase % phase_count)
            remaining_green = max(0.0, self.traci.trafficlight.getNextSwitch(tl_id) - sim_time)

            states[tl_id] = self.state_builder.build_local_state(
                intersection_id=tl_id,
                current_phase=current_phase,
                remaining_green=remaining_green,
                next_phase=next_phase,
                queue_mainline=queue_mainline,
                queue_side_street=queue_side,
                avg_delay_seconds=avg_delay,
                mainline_storage_ratio=mainline_ratio,
                side_storage_ratio=side_ratio,
                downstream_blocking_flag=self._estimate_downstream_blocking(tl_id),
                cav_count_approach=cav_count,
                cav_platoon_eta=cav_eta,
                base_spat_plan={
                    "tl_info": tl_info.get(tl_id, {}),
                    "spat": spat_msg.get(tl_id, []),
                },
            )

        return states
