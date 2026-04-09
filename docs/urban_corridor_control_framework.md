# Urban Corridor Control Framework

This document summarizes the current urban-corridor control stack in this
repository, with emphasis on the `roosevelt` scenario. It is written as a
research-facing technical note so you can modify the current algorithmic
structure rather than reverse-engineer it from `main.py` and the generated
controller code.

The discussion is organized from bottom to top:

1. SUMO and TraCI runtime loop
2. Bottom-layer vehicle-level CAV control
3. SPaT/TL abstraction used by the vehicle controller
4. Corridor-level hierarchy
5. LLM interface and execution semantics
6. Concrete research modification points

## 1. Scope and Key Files

This document focuses on the urban corridor path:

- Scenario: `roosevelt`
- Entry point: `main.py`
- Vehicle controller wrapper: `src/agents.py`
- Corridor hierarchy: `src/hierarchical_control/*`
- Current scenario config: `src/scenario_config.py`
- Generated urban CAV controller core:
  `codegen/cavctrl_codegen/CAV_mdl/CAV_ctrl_mdl_wTraJ_241219.cpp`

Important note:

- The urban corridor uses the `CAV` controller path, not the highway `PCC`
  controller path.
- The hierarchy/LLM layer currently coordinates signal timing only. It does
  not directly replace the vehicle-level controller.

## 2. Layered Architecture

The current stack is:

1. SUMO advances one simulation step with `dt = 0.1 s`.
2. Python reconstructs traffic-light state and SPaT-like information.
3. For each CAV:
   - gather ego state
   - gather leader state
   - gather V2V prediction if available
   - gather next traffic lights and current SPaT
   - call the generated urban CAV controller
4. Optionally, every `hierarchy_interval` seconds, the corridor hierarchy:
   - summarizes intersection states
   - chooses corridor mode and local intents
   - in `live` mode, applies bounded signal timing bias

At a high level:

```text
SUMO/TraCI
  -> TLInfo + SPAT reconstruction
  -> per-vehicle sensing + V2V/V2I abstraction
  -> CAV_ctrl_mdl_wTraJ_241219 (bottom layer)
  -> optional hierarchy runtime
     -> local signal states
     -> corridor summary
     -> rule-based or LLM coordinator
     -> bounded timing bias executor
```

## 3. Runtime Loop in `main.py`

For the urban corridor, the important control loop is in `simulation.step()`.

At simulation time `t_k`:

1. Advance SUMO one step:

   \[
   t_{k+1} = t_k + 0.1
   \]

2. If the scenario is traffic-light based:
   - reconstruct SPaT from current signal states
   - update hierarchy snapshot if enabled

3. For each CAV:
   - correct route-invalid lane traps near stop lines
   - compute speed limit and lane-end constraints
   - read closest leader state
   - read recent V2V prediction from the leader if available
   - call `controller.getCommand(...)`
   - apply acceleration command back to SUMO
   - push the returned planned trajectory into the V2V store

The bottom-layer controller therefore sees a fused state:

\[
x_{\text{ctrl}} =
\left[
s_e, v_e, a_e,
s_l, v_l, a_l,
\text{TLS/Intsc abstraction},
\text{SPaT abstraction},
\text{speed/lane constraints},
\text{V2V trajectory}
\right]
\]

where:

- \(s_e, v_e, a_e\): ego distance, speed, acceleration
- \(s_l, v_l, a_l\): leader relative position/speed/acceleration

## 4. Time and Range Constants

Current important constants are:

- Simulation step: `dt = 0.1 s`
- Radar range: `RADAR_RANGE = 200 m`
- V2V / V2I connectivity range: `CONN_RANGE = 450 m`
- Hierarchy default evaluation interval: `30 s`
- Traffic-light warm-up in urban scenarios: `3500` SUMO steps = `350 s`

So the hierarchy does not reason every control step. It reasons on a slower,
corridor-level timescale:

\[
t^{\text{hier}}_{n+1} - t^{\text{hier}}_n \approx 30 \text{ s}
\]

while the vehicle controller runs at:

\[
t^{\text{veh}}_{k+1} - t^{\text{veh}}_k = 0.1 \text{ s}
\]

## 5. Bottom-Layer Vehicle-Level Control

## 5.1 Controller Interface

The urban controller wrapper is `CAV.getCommand(...)` in `src/agents.py`.
It constructs the following inputs for the generated controller:

- `IntscInfo` of size `6 x 5`
- `SpdLimInfo` of size `2 x 2`
- `CtrlInfo` of size `14`
- `CtrlPar` of size `15`
- `StopInfo` of size `2`

The generated controller is:

```text
CAV_ctrl_mdl_wTraJ_241219(
    IntscInfo, SpdLimInfo, CtrlInfo, CtrlPar, StopInfo
) -> (aRef, vRef, sRef, UpdType, LT traj, ST traj)
```

This is the main mathematical core for urban CAV control.

## 5.2 Ego, Leader, and Constraint Signals

The Python wrapper maps live SUMO state into controller variables:

\[
s_e = \text{traci.vehicle.getDistance}(ego)
\]
\[
v_e = \text{traci.vehicle.getSpeed}(ego)
\]
\[
a_e = \text{traci.vehicle.getAcceleration}(ego)
\]

Leader state:

\[
d_{el} = \text{leader bumper gap}
\]
\[
s_l = s_e + d_{el}
\]
\[
v_l = \text{leader speed}, \quad a_l = \text{leader acceleration}
\]

Lane/speed constraints:

\[
s_{\max} = s_e + d_{\text{lane-end}}
\]
\[
v_{\max} = \min(v_{\text{engine}}, v_{\text{lane limit}})
\]

For urban traffic-light scenarios, `s_max` is usually very large unless a lane
is explicitly marked as ending.

## 5.3 V2V Intent Sharing

The `Communications` class stores a leader's predicted trajectory as:

- future times `t_i`
- future longitudinal positions `s_i`
- future speeds `v_i`

If speed is not provided, it is estimated by finite difference:

\[
v_i = \frac{s_i - s_{i-1}}{t_i - t_{i-1}}
\]

and then smoothed by a 2-point moving average.

A V2V prediction is used only if:

1. the leader is inside communication range

   \[
   d_{el} \leq 450 \text{ m}
   \]

2. the message is recent enough:

   \[
   t_{\text{msg},0} + 0.5 > t_{\text{now}}
   \]

Otherwise the controller falls back to internal leader prediction.

## 5.4 Leader Prediction Used by the Controller

If no V2V trajectory is available, the highway PCC wrapper uses constant
acceleration prediction. The urban CAV controller instead relies on its own
reference-generation logic, but the same idea applies conceptually:

\[
v_l(t+\Delta t) = \max(0, v_l(t) + a_l \Delta t)
\]
\[
s_l(t+\Delta t) = s_l(t) + v_l(t)\Delta t + a_l \Delta t^2
\]

In the PCC wrapper this prediction is truncated after `3 s`, after which
`a_l` is set to zero.

## 6. Traffic Light and SPaT Abstraction

## 6.1 `TLInfo`: Static Signal Structure

Before the urban run begins, the code extracts a per-intersection table:

- cycle length `tcyc`
- offset `toff`
- phase durations
- min green / max green
- yellow time
- red-clearance time
- unique lane masks for each phase

For phase `r`:

\[
\text{timingTable}[r] =
[
\text{phase\_id},
t_{\text{cyc}},
t_{\text{off}},
t_{\text{dur}},
t_{\min},
t_{\max},
t_{\text{vehExt}},
t_Y,
t_{RC}
]
\]

The current Roosevelt scenario injects manual timing overrides for:

- `veh_ext`
- `yellow`
- `red_clearance`

through `scenario_config.py`.

## 6.2 Online SPaT Reconstruction

The code does not simply trust the current RYG string. It reconstructs an
8-phase SPaT-like object for each traffic light:

\[
\text{SPAT}[p] =
[
\text{state},
t_{\text{start}},
t_{\min\_end},
t_{\max\_end},
t_{\text{nextCycle}},
t_{\text{sample}},
\text{activeFlag}
]
\]

For inactive phases, the code reconstructs min/max phase length from prior
SPaT entries:

\[
t_{\text{rest,min}} = t_{\min\_end} - t_{\text{start}}
\]
\[
t_{\text{rest,max}} = t_{\max\_end} - t_{\text{start}}
\]
\[
T_{\min,p} = t_{\text{cyc}} - t_{\text{rest,max}}
\]
\[
T_{\max,p} = t_{\text{cyc}} - t_{\text{rest,min}}
\]

For active phases, the ring complement is used so that phase durations remain
cycle-consistent.

The resulting SPaT is then passed both to:

- the bottom-layer CAV controller
- the corridor hierarchy

## 6.3 Intersection Abstraction Passed to the CAV Controller

For each upcoming traffic light within connectivity range, the wrapper creates:

\[
\text{Info}_{\text{inp}} =
[
s_{TL}, \text{type}_{TL}, t_{\text{cyc}}, t_{\text{grn}}, t_Y, t_{RR}
]
\]

with:

\[
s_{TL} = s_e + d_{\text{rem}} - \epsilon_{TL}
\]

where currently:

\[
\epsilon_{TL} = 1 \text{ m}
\]

and entries with:

\[
d_{\text{rem}} \leq 2 \epsilon_{TL}
\]

are skipped to avoid pathological "stop line already passed" behavior.

Traffic-light state is encoded numerically as:

- green: `2`
- yellow: `1`
- red: `0`

The usable green time for the selected phase is:

\[
t_{\text{grn}} = t_{\text{phase}} - t_Y - t_{RC}
\]

The remaining-red-to-green reference timing is:

\[
t_{RR} = t_{\text{cyc}} - \left( (t_{\text{off}} + T_{\text{prev phases}}) \bmod t_{\text{cyc}} \right)
\]

This is the main V2I abstraction consumed by the urban controller.

## 7. Current Urban CAV Controller Mathematics

## 7.1 High-Level Internal Flow

Inside `CAV_ctrl_mdl_wTraJ_241219.cpp`, the flow is:

1. Build a preview set of intersections and speed limits.
2. Select feasible target green windows and desired arrival times.
3. Generate a long-horizon trajectory `TRAJ` (`4 x 1000`).
4. Run `RefUpdate_230407(...)` to produce:
   - immediate acceleration reference `aRef`
   - immediate speed reference `vRef`
   - immediate position reference `sRef`
   - short-horizon car-following trajectory `TRAJ_CF`

So the bottom layer is not a single formula. It is:

\[
\text{Urban controller} =
\text{preview filtering}
\rightarrow
\text{green-window timing selection}
\rightarrow
\text{trajectory generation}
\rightarrow
\text{reference update / safety correction}
\]

## 7.2 Preview Horizon Construction

The controller first defines a preview horizon end:

\[
s_{\text{prv}} = s_e + \text{ConnRange}
\]

Currently:

\[
\text{ConnRange} = 450 \text{ m}
\]

Intersections are included in preview if they satisfy the code's logic:

\[
s_{TL} - s_e - d_{\text{margin}} > 0
\]
\[
s_{TL} - s_{\text{prv}} < 0
\]

where `d_margin = CtrlPar[1] = 10 m` unless the current signal is red, in
which case the code sets this margin to zero.

If no future intersection is found, the controller adds a virtual point.

## 7.3 Desired Speed and Controller Parameters

The current Python wrapper sets:

\[
v_{\text{des}} = 0.95 \, v_{\max}
\]

and passes the following key parameters:

- `CtrlPar[0] = 450`: connectivity range
- `CtrlPar[1] = 10`: next-intersection counting margin
- `CtrlPar[2] = 100`: virtual point distance margin
- `CtrlPar[3] = 1`: green-start margin
- `CtrlPar[4] = 2`: green-end margin
- `CtrlPar[5] = 0.95 v_max`: desired speed
- `CtrlPar[6] = 1`: minimum timing slack
- `CtrlPar[7] = 1`: maximum timing slack
- `CtrlPar[8] = 1`: car-following mode selector
- `CtrlPar[9] = 3`: car-following horizon
- `CtrlPar[10] = 1`: desired headway `tau_d`
- `CtrlPar[11] = 3.2`: minimum spacing `d_min`
- `CtrlPar[12] = 1.5`: desired acceleration `aDes`
- `CtrlPar[13] = 0.75`: desired braking `bDes`

## 7.4 Green-Window Travel-Time Formula

The generated function `tfs_des_cal_fcn(...)` in
`GrnWndSlctr_230512.cpp` computes a desired final arrival time.

If the target final speed `v_f` is nonzero, it uses:

\[
t_f^{des} = \frac{2 d}{v_0 + v_f}
\]

If `v_f = 0`, the code switches to a stop-related regime with separate
accelerate/cruise/brake cases.

One braking-related quantity is:

\[
t_{\text{brk}} = \frac{v_0^2 / 2}{b_{Des}}
\]

and the code then chooses among:

- cruise-hold
- accelerate-cruise-brake
- accelerate-brake
- pure braking

depending on distance and speed feasibility.

This function is one of the main places to edit if you want to redesign
arrival-time selection around green windows.

## 7.5 Immediate Stop / Near-Stop Reference Update

`RefUpdate_230407.cpp` contains an explicit near-stop formula used when the
vehicle is approaching a stop or effectively stopped at a red:

\[
a_{\text{ref}} =
\max\left(
-4,\;
\min\left(
\min\left(
-\frac{v_e^2}{2 \max(0.5, s_I - s_e)},
a_{\text{prev}}
\right),
-0.2
\right)
\right)
\]

Then over one control step:

\[
\Delta t = \min\left(\max\left(0, -\frac{v_e}{a_{\text{ref}}}\right), 0.1\right)
\]
\[
v_{\text{ref}} = v_e + a_{\text{ref}} \Delta t
\]
\[
s_{\text{ref}} = s_e + v_e \Delta t + \frac{1}{2} a_{\text{ref}} \Delta t^2
\]

This is one of the clearest exact closed-form formulas in the current urban
bottom layer.

## 7.6 IDM-Like Safety Model Present in the Code

The generated `RefUpdate_230407.cpp` also contains an IDM-like branch.
Although the current wrapper uses `CtrlPar[8] = 1` rather than `0`, the IDM
branch is still useful as a reference model.

The desired gap is computed as:

\[
d_{\text{des}} =
d_{\min} +
\max\left(
0,\;
v_e \tau_d + \frac{v_e(v_e - v_l)}{5.65685424949}
\right)
\]

Using actual front gap:

\[
d_{\text{gap}} = s_l - s_e
\]

the normalized gap ratio is:

\[
r = \frac{d_{\text{des}}}{d_{\text{gap}}}
\]

and the corresponding acceleration clamp becomes:

\[
a_{cf} = \max(-4,\; 4(1 - r^2))
\]

This is a good baseline if you want to replace the current nonlinear reference
update with a more interpretable car-following model.

## 7.7 Active Current-Code Path: Boundary Optimization with PV Constraint

The current urban wrapper sets:

\[
CFopt = CtrlPar[8] = 1
\]

so the active branch is not the simple IDM branch. It is the
"boundary condition optimization considering PV" branch in
`RefUpdate_230407.cpp`.

The code comments indicate it optimizes final speed/position under a safety
constraint of the form:

\[
s_f + \tau_d v_f \leq b_0
\]

where \(b_0\) is derived from the predicted leader trajectory and minimum gap.

The code constructs a polynomial in terminal speed \(v_f\) and solves for
admissible roots. If no valid positive real root exists, it uses the explicit
fallback:

\[
v_f =
-\frac{
\left(2 c_1 \tau_d - c_3\right)b_0 + \left(c_2 \tau_d - c_4\right)
}{
2 \left(c_3 \tau_d - c_5 - c_1 \tau_d^2\right)
}
\]

Then it builds a short-horizon cubic reference over

\[
T = \max(0.1, CtrlPar[9]) = \max(0.1, 3)
\]

with coefficients equivalent to:

\[
c_5 = \frac{12(s_0 - s_f) + 6 T v_0 + 6 T v_f}{T^3}
\]
\[
c_2 = \frac{6(s_0 - s_f) + 4 T v_0 + 2 T v_f}{T^2}
\]

and uses:

\[
a_{\text{ref}}(0.1) = c_5 (0.1) - c_2
\]
\[
v_{\text{ref}}(0.1) = \frac{1}{2} c_5 (0.1)^2 - c_2 (0.1) + v_0
\]
\[
s_{\text{ref}}(0.1) = \frac{c_5 (0.1)^3}{6} - \frac{c_2 (0.1)^2}{2} + v_0 (0.1) + s_0
\]

This is one of the most important equations in the present urban controller,
because it is the immediate motion command actually sent back to SUMO.

## 7.8 Long vs Short Trajectory Outputs

The controller returns:

- Long trajectory `TRAJ`: `time_LTtraj`, `acc_LTtraj`, `vel_LTtraj`, `pos_LTtraj`
- Short trajectory `TRAJ_CF`: `time_STtraj`, `acc_STtraj`, `vel_STtraj`, `pos_STtraj`

The comments in `CAV_ctrl_mdl_wTraJ_241219.cpp` indicate the recommended speed
depends on update type:

- `UpdType == -4` or `3`: stop-related constant braking
- `UpdType == 1`: follow long trajectory
- `UpdType == 2`: follow short car-following trajectory

This means the urban controller is effectively a hybrid controller.

## 8. Vehicle-Level Urban Support Logic Outside the DLL

## 8.1 Route-Consistent Lane Guidance

Before the DLL is called, `main.py` applies route-consistent lane guidance
using `traci.vehicle.getBestLanes(...)`.

The selected target lane minimizes:

\[
\left(
|\text{offset-to-route-valid-lane}|,
|\Delta \text{lane index}|,
-\text{continuation length}
\right)
\]

in lexicographic order.

Late lane changes are suppressed when the remaining distance is too short:

\[
d_{\text{remain}} < 15 \cdot \max(|\Delta lane|, 1)
\]

Near the stop line, if the current lane is route-invalid and no normal lane
change is still feasible, the code performs a lateral rescue `moveTo(...)`.

This support logic is critical in Roosevelt because otherwise a CAV can enter a
short turn pocket and deadlock even if the longitudinal controller is correct.

## 8.2 Stuck-Vehicle Rescue

If a CAV stays near the stop line with very low speed for too long:

- threshold: `actual_speed < 0.05 m/s`
- threshold duration: `100` ticks = `10 s`

the code suspends TraCI control and allows SUMO to recover the vehicle.

This is not part of the nominal control law, but it is part of the practical
stability of the urban corridor simulation.

## 9. Corridor-Level Hierarchy

## 9.1 State Extraction

Every hierarchy update, each intersection state is built from TraCI.

### Queue and delay

For a lane group:

\[
n_{\text{halt}} = \sum_{\ell \in L} \text{HaltingNumber}(\ell)
\]

The code internally estimates queue length in meters as:

\[
q_{\text{len}} = 7.5 \, n_{\text{halt}}
\]

and storage ratio as:

\[
\rho_{\text{storage}} =
\min\left(1.5, \frac{q_{\text{len}}}{\sum_{\ell \in L} \text{LaneLength}(\ell)}\right)
\]

Average delay is:

\[
\bar{d} = \text{mean}\left(\text{waiting times of vehicles on } L\right)
\]

The local state stores `queue_mainline` and `queue_side_street` as halting
vehicle counts, not meters.

### Downstream blocking

For downstream output lanes:

\[
\text{blocking} = 1
\quad \text{if} \quad
\max_{\ell \in L_{out}} \text{Occupancy}(\ell) \geq 0.85
\]

### CAV platoon detection

For each CAV on candidate mainline lanes:

\[
d_{\text{stop}} = \max(0, L_{\ell} - s_{\ell})
\]

Only vehicles with:

\[
d_{\text{stop}} \leq 450 \text{ m}
\]

are counted.

Platoon ETA is:

\[
\eta = \min_i \frac{d_{\text{stop},i}}{\max(0.1, v_i)}
\]

and platoon count is simply the number of such CAVs.

## 9.2 Local State Classification Rules

The hierarchy then classifies raw continuous variables into symbolic levels.

### Delay

\[
\text{LOW\_DELAY} \iff \bar{d} < 20
\]
\[
\text{MODERATE\_DELAY} \iff 20 \leq \bar{d} < 55
\]
\[
\text{HIGH\_DELAY} \iff \bar{d} \geq 55
\]

### Saturation

If a direct `v/c` ratio is not available, the code falls back to total queue
pressure:

\[
q_p = q_{\text{main}} + q_{\text{side}}
\]

Classification:

- low if \(q_p < 5\)
- medium if \(5 \le q_p < 10\)
- high if \(10 \le q_p < 20\)
- oversaturated if \(q_p \ge 20\)

If a true `v/c` ratio is available, thresholds are:

- low if \(v/c < 0.85\)
- medium if \(0.85 \le v/c < 0.95\)
- high if \(0.95 \le v/c < 1.0\)
- oversaturated if \(v/c \ge 1.0\)

### Spillback

\[
\text{NO\_SPILLBACK} \iff \rho_{\text{storage}} < 0.60
\]
\[
\text{SPILLBACK\_WARNING} \iff 0.60 \le \rho_{\text{storage}} < 0.85
\]
\[
\text{SPILLBACK\_CRITICAL} \iff \rho_{\text{storage}} \ge 0.85
\]

### Platoon

Let `N_cav` be the count of detected approach CAVs.

\[
\text{NO\_PLATOON}
\iff
N_{cav} < 3
\quad \text{or} \quad
\eta > 60
\]

\[
\text{PLATOON\_CANDIDATE}
\iff
N_{cav} \ge 3
\;\text{and}\;
30 < \eta \le 60
\]

\[
\text{PLATOON\_IMMEDIATE}
\iff
N_{cav} \ge 3
\;\text{and}\;
\eta \le 30
\]

## 9.3 Corridor Summary

From all local intersection states, the hierarchy computes:

\[
\bar{d}_{corr} = \text{mean of available local delays}
\]

\[
N_{\text{high sat}} =
\sum_i \mathbf{1}[\text{saturation}_i \in \{\text{HIGH}, \text{OVERSATURATED}\}]
\]

\[
N_{\text{spill crit}} =
\sum_i \mathbf{1}[\text{spillback}_i = \text{SPILLBACK\_CRITICAL}]
\]

\[
N_{\text{platoon rel}} =
\sum_i \mathbf{1}[\text{platoon}_i \in \{\text{PLATOON\_CANDIDATE}, \text{PLATOON\_IMMEDIATE}\}]
\]

The dominant congestion region is simply the intersection with largest:

\[
q_{p,i} = q_{\text{main},i} + q_{\text{side},i}
\]

## 10. Corridor-Level Coordinator

## 10.1 Rule-Based Network Mode

The fallback coordinator chooses one corridor mode:

1. `SPILLBACK_PROTECTION` if any intersection is spillback-critical
2. `MAINLINE_PRIORITY` if any intersection is highly saturated or
   \(\bar{d}_{corr} \ge 55 s\)
3. `PLATOON_SUPPORT` if any intersection is platoon-relevant
4. otherwise `BALANCED`

Formally:

\[
\text{mode} =
\begin{cases}
\text{SPILLBACK\_PROTECTION}, & N_{\text{spill crit}} > 0 \\
\text{MAINLINE\_PRIORITY}, & N_{\text{high sat}} > 0 \text{ or } \bar{d}_{corr} \ge 55 \\
\text{PLATOON\_SUPPORT}, & N_{\text{platoon rel}} > 0 \\
\text{BALANCED}, & \text{otherwise}
\end{cases}
\]

## 10.2 Intersection Intents

Given network mode and local state, each intersection gets:

- role
- adjustment level in `{0,1,2}`

Examples:

- spillback critical -> `PROTECT_DOWNSTREAM`
- mainline queue >= side queue under mainline priority -> `FAVOR_MAINLINE`
- platoon immediate -> `PREPARE_PLATOON`
- side street more urgent under mainline-priority mode -> `SERVE_SIDE_STREET`

## 10.3 LLM Prompt and Output Contract

The LLM sees:

- compact intersection reports
- corridor summary
- a strict JSON schema

The required output schema is:

```json
{
  "network_mode": "BALANCED | MAINLINE_PRIORITY | SPILLBACK_PROTECTION | PLATOON_SUPPORT",
  "corridor_priority": "NONE | MAIN_CORRIDOR | SUB_CORRIDOR_A | SUB_CORRIDOR_B",
  "intersection_intents": {
    "<intersection_id>": {
      "intersection_role": "NEUTRAL | FAVOR_MAINLINE | SERVE_SIDE_STREET | PROTECT_DOWNSTREAM | PREPARE_PLATOON",
      "adjustment_level": 0,
      "rationale": ["short explanation"]
    }
  },
  "global_rationale": ["short explanation"]
}
```

The response parser hard-clamps:

\[
\text{adjustment\_level} \in [0, 2]
\]

and rejects invalid network modes or intersection roles.

## 11. Local Signal Agent and Execution Layer

## 11.1 Local Decision Mapping

Adjustment levels are converted to timing bias by:

\[
\text{bias}(0) = 0 \text{ s}
\]
\[
\text{bias}(1) = 2 \text{ s}
\]
\[
\text{bias}(2) = 4 \text{ s}
\]

Role-to-action mapping:

- `PROTECT_DOWNSTREAM` -> `TRUNCATE_CURRENT`
- `FAVOR_MAINLINE` -> `EXTEND_CURRENT` or `NEXT_CYCLE_BIAS`
- `PREPARE_PLATOON` -> `EXTEND_CURRENT` or `NEXT_CYCLE_BIAS`
- `SERVE_SIDE_STREET` -> `NEXT_CYCLE_BIAS`
- otherwise `NO_CHANGE`

For truncation:

\[
\Delta t_{\text{bias}} < 0
\]

For extension:

\[
\Delta t_{\text{bias}} > 0
\]

## 11.2 Bounded Execution

If the decision acts on the current phase:

\[
t_{\text{remain,new}} =
\text{clip}\left(
t_{\text{remain,current}} + \Delta t_{\text{bias}},
1.0,
\max(t_{\max,\text{phase}}, t_{\text{remain,current}})
\right)
\]

This is important:

- the hierarchy cannot arbitrarily rewrite the full cycle
- it only adjusts remaining green by a bounded amount

If the decision is `NEXT_CYCLE_BIAS`, it is queued and only applied when the
target phase group becomes active.

## 11.3 `shadow` vs `live`

- `shadow`: hierarchy computes states, intents, and logs, but does not change
  SUMO phase duration
- `live`: the execution planner calls `setPhaseDuration(...)`

So the actual control authority is:

\[
\text{shadow} \Rightarrow u_{signal} = u_{base}
\]
\[
\text{live} \Rightarrow u_{signal} = u_{base} + \Delta u_{hier}
\]

with `Delta u_hier` limited to small timing bias.

## 12. What the LLM Currently Does and Does Not Do

The current LLM does:

- choose corridor mode
- choose per-intersection intent/priority
- feed the same bounded execution layer as the rule-based coordinator

The current LLM does not:

- directly output vehicle acceleration
- directly replace the bottom-layer CAV controller
- reorder arbitrary phase sequences
- bypass hard timing bounds in the execution planner

Therefore the present system is best described as:

\[
\text{Vehicle-level CAV control}
+
\text{LLM-assisted corridor-level supervisory signal bias}
\]

not as end-to-end LLM vehicle control.

## 13. Best Research Modification Points

If your goal is research extension, the highest-value intervention points are:

## 13.1 Bottom-Layer Urban Vehicle Controller

Best files:

- `src/agents.py`
- `codegen/cavctrl_codegen/CAV_mdl/RefUpdate_230407.cpp`
- `codegen/cavctrl_codegen/CAV_mdl/RefTrjGnrtr_240503.cpp`
- `codegen/cavctrl_codegen/CAV_mdl/GrnWndSlctr_230512.cpp`

Good research directions:

- replace the current green-window timing heuristic
- replace the boundary-condition terminal-speed optimization
- redesign the short-horizon cubic reference update
- add explicit multi-objective cost: delay, comfort, energy, queue discharge

## 13.2 Hierarchy Metrics

Best files:

- `src/hierarchical_control/traci_state_extractor.py`
- `src/hierarchical_control/state_builder.py`

Good research directions:

- replace halting-count queue proxy with detector-backed queue estimation
- replace average waiting time with delay-to-freeflow or pressure metrics
- introduce network-level reward or graph state embedding
- add true platoon quality metrics instead of simple count + ETA

## 13.3 Coordinator Logic

Best files:

- `src/hierarchical_control/central_coordinator.py`
- `src/hierarchical_control/prompt_builder.py`
- `src/hierarchical_control/response_parser.py`

Good research directions:

- replace discrete mode switching with continuous priority allocation
- change the LLM output schema from symbolic intents to weighted objective terms
- add confidence estimation / fallback arbitration

## 13.4 Execution Layer

Best file:

- `src/hierarchical_control/signal_execution.py`

Good research directions:

- allow phase-group-specific bounded optimization over a whole cycle
- move from scalar bias to constrained rolling horizon signal control
- add safety guards from queue spillback and minimum green guarantees

## 14. Current Limitations

These are the main current scientific limitations of the present framework:

1. The bottom-layer urban controller is hybrid and partly opaque because the
   generated code is mathematically rich but not hand-written for interpretability.
2. Queue estimation in the hierarchy is still coarse:

   \[
   q_{\text{len}} \approx 7.5 \times n_{\text{halting}}
   \]

3. The LLM sees symbolic summaries, not raw trajectories or detector histories.
4. Signal execution is intentionally conservative:

   \[
   |\Delta t_{\text{bias}}| \le 4 \text{ s}
   \]

5. The LLM currently supervises signals only; it does not yet co-design
   vehicle-level trajectories and signal plans jointly.

## 15. Recommended Research Roadmap

If the goal is to build a publishable new algorithm on this framework, a good
progression is:

1. Keep the current bottom-layer controller fixed.
2. Replace the hierarchy state and reward design.
3. Replace the coordinator with:
   - rule optimization
   - RL
   - graph model
   - LLM + optimizer hybrid
4. Only then decide whether to redesign the bottom-layer CAV controller.

That order is practical because the current system already gives you:

- a stable microscopic vehicle controller
- a stable SPaT interface
- a safe bounded signal execution interface
- a plug-in point for higher-level reasoning

If later you want, this document can be extended into a second file that gives
you an even deeper derivation specifically for `RefTrjGnrtr_240503.cpp` and
`RefUpdate_230407.cpp`, including a variable-by-variable mapping of the
generated optimization code.
