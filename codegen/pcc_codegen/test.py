#! /usr/bin/env python3
################################
### Tyler Ard                ###
### Argonne National Lab     ###
### Vehicle Mobility Systems ###
### tard(at)anl(dot)gov      ###
################################

import unittest
import os
import sys
                
from _cppwrapper import cpp_api

class TestAPI(unittest.TestCase):

    @classmethod
    def setUpClass(self):
        ### Autogen Simulink Model Interface
        folder = 'lib'

        if os.name == 'nt':
            libraryname = 'pcc_so'
        elif os.name == 'posix':
            libraryname = 'libpcc_so'
        else:
            raise ValueError('PCC class cannot determine system type!')
        
        library = os.path.join(folder, libraryname)
            
        self.api = cpp_api(library)

    def test_runs(self):
        ### Set inputs and run controller
        # Predict PV motion
        dt_pred = 0.10 # [s]
        t_pred = 0. # [s]
        
        k = 0 # First index is current PV states
        self.api.inputs_p.contents.time_pred[k] = t_pred

        for k in range(1, 51): # Future indices are predicted PV states
            # Propagate kinematic constant acceleration prediction
            t_pred += dt_pred
            self.api.inputs_p.contents.time_pred[k] = t_pred
            self.api.inputs_p.contents.pos_pred[k] = 2000.

        # Parameters
        self.api.inputs_p.contents.param_vec[0] = 0 # is_eco

        self.api.inputs_p.contents.param_vec[1] = 20.0*0.95 # vel_des - fraction of vel_max
        self.api.inputs_p.contents.param_vec[2] = 20.0 # vel_max
        self.api.inputs_p.contents.param_vec[3] = 2000 # pos_max
        
        self.api.inputs_p.contents.param_vec[4] = 3.0 # d0
        self.api.inputs_p.contents.param_vec[5] = 1.10 # THref
        self.api.inputs_p.contents.param_vec[6] = 0.60 # THsafe - constraint s + v Tsafe \geq s_pv 
        self.api.inputs_p.contents.param_vec[7] = 15.0 # THmax
        self.api.inputs_p.contents.param_vec[8] = 1.0 # qh
        self.api.inputs_p.contents.param_vec[9] = 0.5 # qv
        self.api.inputs_p.contents.param_vec[10] = 100 # qu
        self.api.inputs_p.contents.param_vec[11] = 0 # qdu
        
        self.api.inputs_p.contents.param_vec[12] = 1 # dual_mode
        self.api.inputs_p.contents.param_vec[13] = 1 # term_tracking_only
        self.api.inputs_p.contents.param_vec[14] = 0.9999 # alpha_proc
        self.api.inputs_p.contents.param_vec[15] = 0.89 # sigma_proc
        self.api.inputs_p.contents.param_vec[16] = 0.00 # sigma_meas
        self.api.inputs_p.contents.param_vec[17] = 0.00 # sigma_loca
        self.api.inputs_p.contents.param_vec[18] = 0.50 # alpha_acceptance
        self.api.inputs_p.contents.param_vec[19] = 5.415 # mean_acceptance
        self.api.inputs_p.contents.param_vec[20] = 4.566 # scale_acceptance

        ### Run the autogen controller
        self.api.step_inputs() # Reads inputs_p and writes them to controller
        self.api.step_controller() # Steps the controller
        self.api.step_outputs() # Writes the outputs from controller to outputs_p

        # Assign outputs struct properties
        acc_des = self.api.outputs_p.contents.acc_des
        exitflag = self.api.outputs_p.contents.exitflag

        ### Test output
        self.assertEqual(exitflag, 1)

def suite():
    suite = unittest.TestSuite()
    
    suite.addTest( TestAPI('test_runs') )

    return suite

if __name__ == '__main__':
    tests = unittest.TextTestRunner()
    
    tests.run(suite())
    