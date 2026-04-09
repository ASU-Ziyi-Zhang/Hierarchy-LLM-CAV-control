/*
 * longitudinal_mpc.cpp
 *
 * Code generation for model "longitudinal_mpc".
 *
 * Model version              : 2.14
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Tue Dec 16 13:38:12 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Passed (7), Warnings (2), Error (0)
 */

#include "longitudinal_mpc.h"
#include "rtwtypes.h"
#include "longitudinal_mpc_types.h"
#include "coder_array.h"
#include <cstring>
#include <cmath>
#include <emmintrin.h>
#include "longitudinal_mpc_private.h"
#include "cmath"

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

void longitudinal_mpc::lon_PCCMPC_checkErrorParameters(solver_longitudinal_mpc_T
  *b_this)
{
  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% Check parameters for the MPC */
  /*  Desired forward velocity [m/s] */
  /*  Maximum allowed forward velocity [m/s] */
  /*  Maximum allowed forward range from the current position [s] */
  /*  Safe standstill gap [m] */
  /*  Reference time headway gap [s] */
  /*  Safe min time headway gap [s] */
  /*  Allowed max time headway gap [s] */
  /*  Allowable first-stage probability of enforcing constraint [-] */
  /*  Acceleration action process covariance during prediction of PV [m/s2] */
  /*  Measurement noise covariance on initial state measurement of PV [SI] */
  /*  Measurement noise covariance on initial state measurement of ego [SI] */
  /*  Allowable probability of a cut-in [-] */
  /*  Scale of gap acceptance function [s] */
  /* %% Report */
  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if ((!(b_this->vel_des >= 0.0)) || (!(b_this->vel_des <= 40.0))) {
    std::printf("%s\n", "Error: vdes value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if ((!(b_this->vel_max >= 0.0)) || (!(b_this->vel_max <= 40.0))) {
    std::printf("%s\n", "Error: vmax value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->pos_max >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: smax value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->d0 >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: d0 value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->THref >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: thref value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->THsafe >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: thsafe value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->THmax >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: thmax value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->qh >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: qh value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->qv >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: qv value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->qu > 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: qu value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->qdu >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: qdu value not in permissible range.");
    std::fflush(stdout);
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if ((!(b_this->alpha_proc >= 0.0)) || (!(b_this->alpha_proc <= 1.0))) {
    std::printf("%s\n", "Error: alpha_proc value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->sigma_proc >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: sigma_proc value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->sigma_meas >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: sigma_meas value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->sigma_loca >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: sigma_loca value not in permissible range.");
    std::fflush(stdout);
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if ((!(b_this->alpha_acceptance >= 0.0)) || (!(b_this->alpha_acceptance <= 1.0)))
  {
    std::printf("%s\n", "Error: alpha_acc value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(b_this->scale_acceptance >= 0.0)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::printf("%s\n", "Error: scale_acc value not in permissible range.");
    std::fflush(stdout);
  }

  /*  Return */
  b_this->is_parameter_errored = false;
}

void longitudinal_mpc::longitudin_PCCMPC_setParameters(solver_longitudinal_mpc_T
  *b_this)
{
  /*         %% MPC functions */
  /* %% SETPARAMETERS Set MPC parameters as assigned from inputs. If a parameter is changed trigger an update */
  /*  Check inputs and assign defaults */
  /*  Is in additional eco-features added */
  /*  Desired forward velocity to track [m/s] */
  /*  Maximum allowed forward velocity [m/s] */
  /*  Maximum allowed forward range from the current position [s] */
  /*  Safe standstill gap [m] */
  /*  Reference time headway gap [s] */
  /*  Safe min time headway gap [s] */
  /*  Allowed max time headway gap [s] */
  /*  Choose dual mode MPC in which the terminal cost is determined from LQR solution */
  /*  Choose MPC to enforce state reference tracking only on the terminal stage, otherwise reference tracking on inhorizon stages too */
  /*  Allowable first-stage probability of enforcing constraint [-] */
  /*  Acceleration action process covariance during prediction of PV [m/s2] */
  /*  Measurement noise covariance on initial state measurement of PV [SI] */
  /*  Measurement noise covariance on initial state measurement of ego [SI] */
  /*  Allowable probability of a cut-in [-] */
  /*  Mean of gap acceptance function [s] */
  /*  Scale of gap acceptance function [s] */
  /*  Assign parameters if update detected */
  if (b_this->is_needs_update || (std::abs(b_this->is_eco) > 0.001) || (std::abs
       (b_this->vel_des - 19.0) > 0.001) || (std::abs(b_this->vel_max - 20.0) >
       0.001) || (std::abs(b_this->pos_max - 2000.0) > 0.001) || (std::abs
       (b_this->d0 - 3.0) > 0.001) || (std::abs(b_this->THref - 1.1) > 0.001) ||
      (std::abs(b_this->THsafe - 0.5) > 0.001) || (std::abs(b_this->THmax - 15.0)
       > 0.001) || (std::abs(b_this->qh - 1.0) > 0.001) || (std::abs(b_this->qv
        - 0.5) > 0.001) || (std::abs(b_this->qu - 3000.0) > 0.001) || (std::abs
       (b_this->qdu - 1.0) > 0.001) || (std::abs(b_this->dual_mode - 1.0) >
       0.001) || (std::abs(b_this->term_tracking_only) > 0.001) || (std::abs
       (b_this->alpha_proc - 0.9999) > 0.001) || (std::abs(b_this->sigma_proc -
        0.89) > 0.001) || (std::abs(b_this->sigma_meas) > 0.001) || (std::abs
       (b_this->sigma_loca) > 0.001) || (std::abs(b_this->alpha_acceptance - 0.5)
       > 0.001) || (std::abs(b_this->mean_acceptance - 5.415) > 0.001) || (std::
       abs(b_this->scale_acceptance - 4.566) > 0.001)) {
    b_this->is_needs_update = true;
  }

  if (b_this->is_needs_update) {
    b_this->is_eco = 0.0;
    b_this->vel_des = 19.0;
    b_this->vel_max = 20.0;
    b_this->pos_max = 2000.0;
    b_this->d0 = 3.0;
    b_this->THref = 1.1;
    b_this->THsafe = 0.5;
    b_this->THmax = 15.0;
    b_this->qh = 1.0;
    b_this->qv = 0.5;
    b_this->qu = 3000.0;
    b_this->qdu = 1.0;
    b_this->dual_mode = 1.0;
    b_this->term_tracking_only = 0.0;
    b_this->alpha_proc = 0.9999;
    b_this->sigma_proc = 0.89;
    b_this->sigma_meas = 0.0;
    b_this->sigma_loca = 0.0;
    b_this->alpha_acceptance = 0.5;
    b_this->mean_acceptance = 5.415;
    b_this->scale_acceptance = 4.566;
  }

  /*  Check for errors */
  lon_PCCMPC_checkErrorParameters(b_this);
}

real_T longitudinal_mpc::longitudinal_mpc_norm(const real_T x[16])
{
  real_T y;
  int32_T b_j;
  boolean_T exitg1;
  y = 0.0;
  b_j = 0;
  exitg1 = false;
  while ((!exitg1) && (b_j < 4)) {
    real_T s;
    int32_T s_tmp;
    s_tmp = b_j << 2;
    s = ((std::abs(x[s_tmp + 1]) + std::abs(x[s_tmp])) + std::abs(x[s_tmp + 2]))
      + std::abs(x[s_tmp + 3]);
    if (std::isnan(s)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      b_j++;
    }
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (std::isinf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

void longitudinal_mpc::longitudinal_mpc_mpower(const real_T a[16], real_T b,
  real_T c[16])
{
  real_T aBuffer[16];
  real_T a_0[16];
  real_T cBuffer[16];
  real_T cBuffer_0[16];
  real_T cBuffer_1[16];
  real_T tmp_3[2];
  real_T e;

  /* Start for MATLABSystem: '<S1>/solver' */
  e = std::abs(b);
  if (e <= 2.147483647E+9) {
    int32_T n;
    int32_T n_0;
    int32_T nb;
    int32_T nbitson;
    std::memcpy(&a_0[0], &a[0], sizeof(real_T) << 4U);
    n = static_cast<int32_T>(e);
    n_0 = static_cast<int32_T>(e);
    nbitson = 0;
    nb = -1;
    while (n_0 > 0) {
      nb++;
      if ((static_cast<uint32_T>(n_0) & 1U) != 0U) {
        nbitson++;
      }

      n_0 >>= 1;
    }

    if (static_cast<int32_T>(e) <= 2) {
      if (b == 2.0) {
        for (nb = 0; nb < 4; nb++) {
          for (int32_T i{0}; i <= 2; i += 2) {
            int32_T tmp_4;
            tmp_4 = nb << 2;
            _mm_storeu_pd(&c[i + tmp_4], _mm_add_pd(_mm_add_pd(_mm_add_pd
              (_mm_mul_pd(_mm_set1_pd(a[tmp_4 + 1]), _mm_loadu_pd(&a[i + 4])),
               _mm_mul_pd(_mm_set1_pd(a[tmp_4]), _mm_loadu_pd(&a[i]))),
              _mm_mul_pd(_mm_set1_pd(a[tmp_4 + 2]), _mm_loadu_pd(&a[i + 8]))),
              _mm_mul_pd(_mm_set1_pd(a[tmp_4 + 3]), _mm_loadu_pd(&a[i + 12]))));
          }
        }
      } else {
        boolean_T firstmult;
        firstmult = false;
        for (n = 0; n < 16; n++) {
          if (firstmult || std::isnan(a[n])) {
            firstmult = true;
          }
        }

        if (firstmult) {
          for (nb = 0; nb < 16; nb++) {
            c[nb] = (rtNaN);
          }
        } else {
          std::memset(&c[0], 0, sizeof(real_T) << 4U);
          c[0] = 1.0;
          c[5] = 1.0;
          c[10] = 1.0;
          c[15] = 1.0;
        }
      }
    } else {
      real_T c_0;
      real_T c_1;
      real_T c_2;
      real_T ed2;
      int32_T tmp_4;
      boolean_T aBufferInUse;
      boolean_T cBufferInUse;
      boolean_T firstmult;
      firstmult = true;
      aBufferInUse = false;
      cBufferInUse = ((static_cast<uint32_T>(nbitson) & 1U) == 0U);
      n_0 = nb - 1;
      for (nbitson = 0; nbitson <= n_0; nbitson++) {
        int32_T tmp_5;
        if ((static_cast<uint32_T>(n) & 1U) != 0U) {
          if (firstmult) {
            firstmult = false;
            if (cBufferInUse) {
              if (aBufferInUse) {
                std::memcpy(&cBuffer[0], &aBuffer[0], sizeof(real_T) << 4U);
              } else {
                std::memcpy(&cBuffer[0], &a_0[0], sizeof(real_T) << 4U);
              }
            } else if (aBufferInUse) {
              std::memcpy(&c[0], &aBuffer[0], sizeof(real_T) << 4U);
            } else {
              std::memcpy(&c[0], &a_0[0], sizeof(real_T) << 4U);
            }
          } else {
            if (aBufferInUse) {
              if (cBufferInUse) {
                for (nb = 0; nb < 4; nb++) {
                  ed2 = cBuffer[nb + 4];
                  e = cBuffer[nb];
                  c_0 = cBuffer[nb + 8];
                  c_1 = cBuffer[nb + 12];
                  for (int32_T i{0}; i <= 2; i += 2) {
                    tmp_4 = (i + 1) << 2;
                    tmp_5 = i << 2;
                    _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                      (_mm_mul_pd(_mm_set_pd(aBuffer[tmp_4 + 1], aBuffer[tmp_5 +
                      1]), _mm_set1_pd(ed2)), _mm_mul_pd(_mm_set_pd
                      (aBuffer[tmp_4], aBuffer[tmp_5]), _mm_set1_pd(e))),
                      _mm_mul_pd(_mm_set_pd(aBuffer[tmp_4 + 2], aBuffer[tmp_5 +
                      2]), _mm_set1_pd(c_0))), _mm_mul_pd(_mm_set_pd
                      (aBuffer[tmp_4 + 3], aBuffer[tmp_5 + 3]), _mm_set1_pd(c_1))));
                    c[nb + tmp_5] = tmp_3[0];
                    c[nb + tmp_4] = tmp_3[1];
                  }
                }
              } else {
                for (nb = 0; nb < 4; nb++) {
                  e = c[nb + 4];
                  c_0 = c[nb];
                  c_1 = c[nb + 8];
                  c_2 = c[nb + 12];
                  for (int32_T i{0}; i <= 2; i += 2) {
                    tmp_4 = (i + 1) << 2;
                    tmp_5 = i << 2;
                    _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                      (_mm_mul_pd(_mm_set_pd(aBuffer[tmp_4 + 1], aBuffer[tmp_5 +
                      1]), _mm_set1_pd(e)), _mm_mul_pd(_mm_set_pd(aBuffer[tmp_4],
                      aBuffer[tmp_5]), _mm_set1_pd(c_0))), _mm_mul_pd(_mm_set_pd
                      (aBuffer[tmp_4 + 2], aBuffer[tmp_5 + 2]), _mm_set1_pd(c_1))),
                      _mm_mul_pd(_mm_set_pd(aBuffer[tmp_4 + 3], aBuffer[tmp_5 +
                      3]), _mm_set1_pd(c_2))));
                    cBuffer[nb + tmp_5] = tmp_3[0];
                    cBuffer[nb + tmp_4] = tmp_3[1];
                  }
                }
              }
            } else if (cBufferInUse) {
              for (nb = 0; nb < 4; nb++) {
                ed2 = cBuffer[nb + 4];
                e = cBuffer[nb];
                c_0 = cBuffer[nb + 8];
                c_1 = cBuffer[nb + 12];
                for (int32_T i{0}; i <= 2; i += 2) {
                  tmp_4 = (i + 1) << 2;
                  tmp_5 = i << 2;
                  _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                    (_mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 1], a_0[tmp_5 + 1]),
                                _mm_set1_pd(ed2)), _mm_mul_pd(_mm_set_pd
                    (a_0[tmp_4], a_0[tmp_5]), _mm_set1_pd(e))), _mm_mul_pd
                    (_mm_set_pd(a_0[tmp_4 + 2], a_0[tmp_5 + 2]), _mm_set1_pd(c_0))),
                    _mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 3], a_0[tmp_5 + 3]),
                               _mm_set1_pd(c_1))));
                  c[nb + tmp_5] = tmp_3[0];
                  c[nb + tmp_4] = tmp_3[1];
                }
              }
            } else {
              for (nb = 0; nb < 4; nb++) {
                e = c[nb + 4];
                c_0 = c[nb];
                c_1 = c[nb + 8];
                c_2 = c[nb + 12];
                for (int32_T i{0}; i <= 2; i += 2) {
                  tmp_4 = (i + 1) << 2;
                  tmp_5 = i << 2;
                  _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                    (_mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 1], a_0[tmp_5 + 1]),
                                _mm_set1_pd(e)), _mm_mul_pd(_mm_set_pd(a_0[tmp_4],
                    a_0[tmp_5]), _mm_set1_pd(c_0))), _mm_mul_pd(_mm_set_pd
                    (a_0[tmp_4 + 2], a_0[tmp_5 + 2]), _mm_set1_pd(c_1))),
                    _mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 3], a_0[tmp_5 + 3]),
                               _mm_set1_pd(c_2))));
                  cBuffer[nb + tmp_5] = tmp_3[0];
                  cBuffer[nb + tmp_4] = tmp_3[1];
                }
              }
            }

            cBufferInUse = !cBufferInUse;
          }
        }

        n >>= 1;
        if (aBufferInUse) {
          for (nb = 0; nb < 4; nb++) {
            for (int32_T i{0}; i <= 2; i += 2) {
              tmp_4 = (i + 1) << 2;
              tmp_5 = i << 2;
              _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                (_mm_mul_pd(_mm_set_pd(aBuffer[tmp_4 + 1], aBuffer[tmp_5 + 1]),
                            _mm_set1_pd(aBuffer[nb + 4])), _mm_mul_pd(_mm_set_pd
                (aBuffer[tmp_4], aBuffer[tmp_5]), _mm_set1_pd(aBuffer[nb]))),
                _mm_mul_pd(_mm_set_pd(aBuffer[tmp_4 + 2], aBuffer[tmp_5 + 2]),
                           _mm_set1_pd(aBuffer[nb + 8]))), _mm_mul_pd(_mm_set_pd
                (aBuffer[tmp_4 + 3], aBuffer[tmp_5 + 3]), _mm_set1_pd(aBuffer[nb
                + 12]))));
              a_0[nb + tmp_5] = tmp_3[0];
              a_0[nb + tmp_4] = tmp_3[1];
            }
          }
        } else {
          for (nb = 0; nb < 4; nb++) {
            for (int32_T i{0}; i <= 2; i += 2) {
              tmp_4 = (i + 1) << 2;
              tmp_5 = i << 2;
              _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                (_mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 1], a_0[tmp_5 + 1]),
                            _mm_set1_pd(a_0[nb + 4])), _mm_mul_pd(_mm_set_pd
                (a_0[tmp_4], a_0[tmp_5]), _mm_set1_pd(a_0[nb]))), _mm_mul_pd
                (_mm_set_pd(a_0[tmp_4 + 2], a_0[tmp_5 + 2]), _mm_set1_pd(a_0[nb
                + 8]))), _mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 3], a_0[tmp_5 + 3]),
                                    _mm_set1_pd(a_0[nb + 12]))));
              aBuffer[nb + tmp_5] = tmp_3[0];
              aBuffer[nb + tmp_4] = tmp_3[1];
            }
          }
        }

        aBufferInUse = !aBufferInUse;
      }

      for (nb = 0; nb < 4; nb++) {
        real_T a_1;
        real_T a_2;
        real_T a_3;
        n = nb << 2;
        ed2 = aBuffer[n];
        e = aBuffer[n + 1];
        c_0 = aBuffer[n + 2];
        c_1 = aBuffer[n + 3];
        c_2 = a_0[n];
        a_1 = a_0[n + 1];
        a_2 = a_0[n + 2];
        a_3 = a_0[n + 3];
        for (int32_T i{0}; i <= 2; i += 2) {
          __m128d tmp;
          __m128d tmp_0;
          __m128d tmp_1;
          __m128d tmp_2;
          tmp = _mm_loadu_pd(&cBuffer[i]);
          tmp_0 = _mm_loadu_pd(&cBuffer[i + 4]);
          tmp_1 = _mm_loadu_pd(&cBuffer[i + 8]);
          tmp_2 = _mm_loadu_pd(&cBuffer[i + 12]);
          tmp_4 = i + n;
          _mm_storeu_pd(&cBuffer_1[tmp_4], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(a_3),
            tmp_2), _mm_add_pd(_mm_mul_pd(_mm_set1_pd(a_2), tmp_1), _mm_add_pd
                               (_mm_mul_pd(_mm_set1_pd(a_1), tmp_0), _mm_mul_pd
                                (_mm_set1_pd(c_2), tmp)))));
          _mm_storeu_pd(&cBuffer_0[tmp_4], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(c_1),
            tmp_2), _mm_add_pd(_mm_mul_pd(_mm_set1_pd(c_0), tmp_1), _mm_add_pd
                               (_mm_mul_pd(_mm_set1_pd(e), tmp_0), _mm_mul_pd
                                (_mm_set1_pd(ed2), tmp)))));
        }
      }

      for (nb = 0; nb < 16; nb++) {
        if (firstmult) {
          if (aBufferInUse) {
            c[nb] = aBuffer[nb];
          } else {
            c[nb] = a_0[nb];
          }
        } else if (aBufferInUse) {
          c[nb] = cBuffer_0[nb];
        } else {
          c[nb] = cBuffer_1[nb];
        }
      }
    }
  } else {
    std::memcpy(&a_0[0], &a[0], sizeof(real_T) << 4U);
    if ((!std::isinf(b)) && (!std::isnan(b))) {
      boolean_T firstmult;
      firstmult = true;
      real_T ed2;
      int32_T exitg1;
      do {
        int32_T tmp_4;
        int32_T tmp_5;
        exitg1 = 0;
        ed2 = std::floor(e / 2.0);
        if (2.0 * ed2 != e) {
          if (firstmult) {
            std::memcpy(&c[0], &a_0[0], sizeof(real_T) << 4U);
            firstmult = false;
          } else {
            for (int32_T nb{0}; nb < 4; nb++) {
              real_T c_0;
              real_T c_1;
              real_T c_2;
              e = c[nb + 4];
              c_0 = c[nb];
              c_1 = c[nb + 8];
              c_2 = c[nb + 12];
              for (int32_T i{0}; i <= 2; i += 2) {
                tmp_4 = (i + 1) << 2;
                tmp_5 = i << 2;
                _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                  (_mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 1], a_0[tmp_5 + 1]),
                              _mm_set1_pd(e)), _mm_mul_pd(_mm_set_pd(a_0[tmp_4],
                  a_0[tmp_5]), _mm_set1_pd(c_0))), _mm_mul_pd(_mm_set_pd
                  (a_0[tmp_4 + 2], a_0[tmp_5 + 2]), _mm_set1_pd(c_1))),
                  _mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 3], a_0[tmp_5 + 3]),
                             _mm_set1_pd(c_2))));
                cBuffer[nb + tmp_5] = tmp_3[0];
                cBuffer[nb + tmp_4] = tmp_3[1];
              }
            }

            std::memcpy(&c[0], &cBuffer[0], sizeof(real_T) << 4U);
          }
        }

        if (ed2 == 0.0) {
          exitg1 = 1;
        } else {
          e = ed2;
          for (int32_T nb{0}; nb < 4; nb++) {
            for (int32_T i{0}; i <= 2; i += 2) {
              tmp_4 = (i + 1) << 2;
              tmp_5 = i << 2;
              _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd
                (_mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 1], a_0[tmp_5 + 1]),
                            _mm_set1_pd(a_0[nb + 4])), _mm_mul_pd(_mm_set_pd
                (a_0[tmp_4], a_0[tmp_5]), _mm_set1_pd(a_0[nb]))), _mm_mul_pd
                (_mm_set_pd(a_0[tmp_4 + 2], a_0[tmp_5 + 2]), _mm_set1_pd(a_0[nb
                + 8]))), _mm_mul_pd(_mm_set_pd(a_0[tmp_4 + 3], a_0[tmp_5 + 3]),
                                    _mm_set1_pd(a_0[nb + 12]))));
              cBuffer[nb + tmp_5] = tmp_3[0];
              cBuffer[nb + tmp_4] = tmp_3[1];
            }
          }

          std::memcpy(&a_0[0], &cBuffer[0], sizeof(real_T) << 4U);
        }
      } while (exitg1 == 0);
    } else {
      for (int32_T nb{0}; nb < 16; nb++) {
        c[nb] = (rtNaN);
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

real_T longitudinal_mpc::longitudinal_mpc_log2(real_T x)
{
  real_T f;
  int32_T eint;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (x == 0.0) {
    f = (rtMinusInf);
  } else if ((!std::isinf(x)) && (!std::isnan(x))) {
    real_T t;
    t = std::frexp(x, &eint);
    if (t == 0.5) {
      f = static_cast<real_T>(eint) - 1.0;
    } else if ((eint == 1) && (t < 0.75)) {
      f = std::log(2.0 * t) / 0.69314718055994529;
    } else {
      f = std::log(t) / 0.69314718055994529 + static_cast<real_T>(eint);
    }
  } else {
    f = x;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return f;
}

void longitudinal_mpc::longitudinal__padeApproximation(const real_T A[16], const
  real_T A2[16], const real_T A4[16], const real_T A6[16], int32_T m, real_T F
  [16])
{
  __m128d tmp;
  __m128d tmp_0;
  real_T A6_0[16];
  real_T V[16];
  real_T tmp_2[2];
  real_T d;
  real_T s;
  int32_T A6_tmp;
  int32_T iy;
  int32_T jA;
  int32_T jBcol;
  int32_T jj;
  int32_T jp1j;
  int32_T kAcol;
  int8_T b_ipiv[4];
  if (m == 3) {
    std::memcpy(&F[0], &A2[0], sizeof(real_T) << 4U);
    tmp = _mm_set1_pd(60.0);
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[5], F[0]), tmp));
    F[0] = tmp_2[0];
    F[5] = tmp_2[1];
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[15], F[10]), tmp));
    F[10] = tmp_2[0];
    F[15] = tmp_2[1];
    for (jj = 0; jj < 4; jj++) {
      real_T A6_1;
      real_T A6_2;

      /* Start for MATLABSystem: '<S1>/solver' */
      jp1j = jj << 2;
      d = F[jp1j + 1];
      s = F[jp1j];
      A6_1 = F[jp1j + 2];
      A6_2 = F[jp1j + 3];
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&A6_0[g_k + jp1j], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_set1_pd(d), _mm_loadu_pd(&A[g_k + 4])), _mm_mul_pd
           (_mm_set1_pd(s), _mm_loadu_pd(&A[g_k]))), _mm_mul_pd(_mm_set1_pd(A6_1),
          _mm_loadu_pd(&A[g_k + 8]))), _mm_mul_pd(_mm_set1_pd(A6_2),
          _mm_loadu_pd(&A[g_k + 12]))));
      }
    }

    for (jj = 0; jj <= 14; jj += 2) {
      tmp = _mm_loadu_pd(&A6_0[jj]);
      _mm_storeu_pd(&F[jj], tmp);

      /* Start for MATLABSystem: '<S1>/solver' */
      _mm_storeu_pd(&V[jj], _mm_mul_pd(_mm_set1_pd(12.0), _mm_loadu_pd(&A2[jj])));
    }

    d = 120.0;
  } else if (m == 5) {
    for (jj = 0; jj <= 14; jj += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      _mm_storeu_pd(&F[jj], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(420.0),
        _mm_loadu_pd(&A2[jj])), _mm_loadu_pd(&A4[jj])));
    }

    tmp = _mm_set1_pd(15120.0);
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[5], F[0]), tmp));
    F[0] = tmp_2[0];
    F[5] = tmp_2[1];
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[15], F[10]), tmp));
    F[10] = tmp_2[0];
    F[15] = tmp_2[1];
    for (jj = 0; jj < 4; jj++) {
      real_T A6_1;
      real_T A6_2;

      /* Start for MATLABSystem: '<S1>/solver' */
      jp1j = jj << 2;
      d = F[jp1j + 1];
      s = F[jp1j];
      A6_1 = F[jp1j + 2];
      A6_2 = F[jp1j + 3];
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&A6_0[g_k + jp1j], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_set1_pd(d), _mm_loadu_pd(&A[g_k + 4])), _mm_mul_pd
           (_mm_set1_pd(s), _mm_loadu_pd(&A[g_k]))), _mm_mul_pd(_mm_set1_pd(A6_1),
          _mm_loadu_pd(&A[g_k + 8]))), _mm_mul_pd(_mm_set1_pd(A6_2),
          _mm_loadu_pd(&A[g_k + 12]))));
      }
    }

    for (jj = 0; jj <= 14; jj += 2) {
      tmp = _mm_loadu_pd(&A6_0[jj]);
      _mm_storeu_pd(&F[jj], tmp);

      /* Start for MATLABSystem: '<S1>/solver' */
      _mm_storeu_pd(&V[jj], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(30.0),
        _mm_loadu_pd(&A4[jj])), _mm_mul_pd(_mm_set1_pd(3360.0), _mm_loadu_pd
        (&A2[jj]))));
    }

    d = 30240.0;
  } else if (m == 7) {
    for (jj = 0; jj <= 14; jj += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      _mm_storeu_pd(&F[jj], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(1512.0),
        _mm_loadu_pd(&A4[jj])), _mm_loadu_pd(&A6[jj])), _mm_mul_pd(_mm_set1_pd
        (277200.0), _mm_loadu_pd(&A2[jj]))));
    }

    tmp = _mm_set1_pd(8.64864E+6);
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[5], F[0]), tmp));
    F[0] = tmp_2[0];
    F[5] = tmp_2[1];
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[15], F[10]), tmp));
    F[10] = tmp_2[0];
    F[15] = tmp_2[1];
    for (jj = 0; jj < 4; jj++) {
      real_T A6_1;
      real_T A6_2;

      /* Start for MATLABSystem: '<S1>/solver' */
      jp1j = jj << 2;
      d = F[jp1j + 1];
      s = F[jp1j];
      A6_1 = F[jp1j + 2];
      A6_2 = F[jp1j + 3];
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&A6_0[g_k + jp1j], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_set1_pd(d), _mm_loadu_pd(&A[g_k + 4])), _mm_mul_pd
           (_mm_set1_pd(s), _mm_loadu_pd(&A[g_k]))), _mm_mul_pd(_mm_set1_pd(A6_1),
          _mm_loadu_pd(&A[g_k + 8]))), _mm_mul_pd(_mm_set1_pd(A6_2),
          _mm_loadu_pd(&A[g_k + 12]))));
      }
    }

    for (jj = 0; jj <= 14; jj += 2) {
      tmp = _mm_loadu_pd(&A6_0[jj]);
      _mm_storeu_pd(&F[jj], tmp);

      /* Start for MATLABSystem: '<S1>/solver' */
      _mm_storeu_pd(&V[jj], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(56.0),
        _mm_loadu_pd(&A6[jj])), _mm_mul_pd(_mm_set1_pd(25200.0), _mm_loadu_pd
        (&A4[jj]))), _mm_mul_pd(_mm_set1_pd(1.99584E+6), _mm_loadu_pd(&A2[jj]))));
    }

    d = 1.729728E+7;
  } else if (m == 9) {
    real_T A6_1;
    real_T A6_2;
    for (jj = 0; jj < 4; jj++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      A6_tmp = jj << 2;
      d = A2[A6_tmp + 1];
      s = A2[A6_tmp];
      A6_1 = A2[A6_tmp + 2];
      A6_2 = A2[A6_tmp + 3];
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&V[g_k + A6_tmp], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_set1_pd(d), _mm_loadu_pd(&A6[g_k + 4])), _mm_mul_pd
           (_mm_set1_pd(s), _mm_loadu_pd(&A6[g_k]))), _mm_mul_pd(_mm_set1_pd
          (A6_1), _mm_loadu_pd(&A6[g_k + 8]))), _mm_mul_pd(_mm_set1_pd(A6_2),
          _mm_loadu_pd(&A6[g_k + 12]))));
      }
    }

    for (jj = 0; jj <= 14; jj += 2) {
      tmp = _mm_loadu_pd(&V[jj]);

      /* Start for MATLABSystem: '<S1>/solver' */
      _mm_storeu_pd(&F[jj], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
        (_mm_set1_pd(3960.0), _mm_loadu_pd(&A6[jj])), tmp), _mm_mul_pd
        (_mm_set1_pd(2.16216E+6), _mm_loadu_pd(&A4[jj]))), _mm_mul_pd
        (_mm_set1_pd(3.027024E+8), _mm_loadu_pd(&A2[jj]))));
    }

    tmp = _mm_set1_pd(8.8216128E+9);
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[5], F[0]), tmp));
    F[0] = tmp_2[0];
    F[5] = tmp_2[1];
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[15], F[10]), tmp));
    F[10] = tmp_2[0];
    F[15] = tmp_2[1];
    for (jj = 0; jj < 4; jj++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      jp1j = jj << 2;
      d = F[jp1j + 1];
      s = F[jp1j];
      A6_1 = F[jp1j + 2];
      A6_2 = F[jp1j + 3];
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&A6_0[g_k + jp1j], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_set1_pd(d), _mm_loadu_pd(&A[g_k + 4])), _mm_mul_pd
           (_mm_set1_pd(s), _mm_loadu_pd(&A[g_k]))), _mm_mul_pd(_mm_set1_pd(A6_1),
          _mm_loadu_pd(&A[g_k + 8]))), _mm_mul_pd(_mm_set1_pd(A6_2),
          _mm_loadu_pd(&A[g_k + 12]))));
      }
    }

    for (jj = 0; jj <= 14; jj += 2) {
      tmp = _mm_loadu_pd(&A6_0[jj]);
      _mm_storeu_pd(&F[jj], tmp);

      /* Start for MATLABSystem: '<S1>/solver' */
      tmp = _mm_loadu_pd(&V[jj]);
      _mm_storeu_pd(&V[jj], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
        (_mm_set1_pd(90.0), tmp), _mm_mul_pd(_mm_set1_pd(110880.0), _mm_loadu_pd
        (&A6[jj]))), _mm_mul_pd(_mm_set1_pd(3.027024E+7), _mm_loadu_pd(&A4[jj]))),
        _mm_mul_pd(_mm_set1_pd(2.0756736E+9), _mm_loadu_pd(&A2[jj]))));
    }

    d = 1.76432256E+10;
  } else {
    real_T A6_1;
    real_T A6_2;

    /* Start for MATLABSystem: '<S1>/solver' */
    for (jj = 0; jj <= 14; jj += 2) {
      __m128d tmp_1;
      tmp = _mm_loadu_pd(&A6[jj]);
      tmp_0 = _mm_loadu_pd(&A4[jj]);
      tmp_1 = _mm_loadu_pd(&A2[jj]);
      _mm_storeu_pd(&F[jj], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (3.352212864E+10), tmp), _mm_mul_pd(_mm_set1_pd(1.05594705216E+13),
        tmp_0)), _mm_mul_pd(_mm_set1_pd(1.1873537964288E+15), tmp_1)));
      _mm_storeu_pd(&V[jj], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(16380.0),
        tmp_0), tmp), _mm_mul_pd(_mm_set1_pd(4.08408E+7), tmp_1)));
    }

    tmp = _mm_set1_pd(3.238237626624E+16);
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[5], F[0]), tmp));
    F[0] = tmp_2[0];
    F[5] = tmp_2[1];
    _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[15], F[10]), tmp));
    F[10] = tmp_2[0];
    F[15] = tmp_2[1];

    /* Start for MATLABSystem: '<S1>/solver' */
    for (jj = 0; jj < 4; jj++) {
      d = A6[jj + 4];
      s = A6[jj];
      A6_1 = A6[jj + 8];
      A6_2 = A6[jj + 12];
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        A6_tmp = (g_k + 1) << 2;
        kAcol = g_k << 2;
        iy = kAcol + jj;
        jA = A6_tmp + jj;
        _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_set_pd(V[A6_tmp + 1], V[kAcol + 1]), _mm_set1_pd(d)),
           _mm_mul_pd(_mm_set_pd(V[A6_tmp], V[kAcol]), _mm_set1_pd(s))),
          _mm_mul_pd(_mm_set_pd(V[A6_tmp + 2], V[kAcol + 2]), _mm_set1_pd(A6_1))),
          _mm_mul_pd(_mm_set_pd(V[A6_tmp + 3], V[kAcol + 3]), _mm_set1_pd(A6_2))),
          _mm_set_pd(F[jA], F[iy])));
        A6_0[iy] = tmp_2[0];
        A6_0[jA] = tmp_2[1];
      }
    }

    for (jj = 0; jj < 4; jj++) {
      A6_tmp = jj << 2;

      /* Start for MATLABSystem: '<S1>/solver' */
      d = A6_0[A6_tmp + 1];
      s = A6_0[A6_tmp];

      /* Start for MATLABSystem: '<S1>/solver' */
      A6_1 = A6_0[A6_tmp + 2];
      A6_2 = A6_0[A6_tmp + 3];
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&F[g_k + A6_tmp], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_set1_pd(d), _mm_loadu_pd(&A[g_k + 4])), _mm_mul_pd
           (_mm_set1_pd(s), _mm_loadu_pd(&A[g_k]))), _mm_mul_pd(_mm_set1_pd(A6_1),
          _mm_loadu_pd(&A[g_k + 8]))), _mm_mul_pd(_mm_set1_pd(A6_2),
          _mm_loadu_pd(&A[g_k + 12]))));
      }
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    for (jj = 0; jj <= 14; jj += 2) {
      _mm_storeu_pd(&A6_0[jj], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (182.0), _mm_loadu_pd(&A6[jj])), _mm_mul_pd(_mm_set1_pd(960960.0),
        _mm_loadu_pd(&A4[jj]))), _mm_mul_pd(_mm_set1_pd(1.32324192E+9),
        _mm_loadu_pd(&A2[jj]))));
    }

    for (jj = 0; jj < 4; jj++) {
      for (int32_T g_k{0}; g_k <= 2; g_k += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        A6_tmp = (g_k + 1) << 2;
        kAcol = g_k << 2;
        iy = A6_tmp + jj;
        jA = kAcol + jj;
        _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set_pd(A6_0[A6_tmp + 1],
          A6_0[kAcol + 1]), _mm_set1_pd(A6[jj + 4])), _mm_mul_pd(_mm_set_pd
          (A6_0[A6_tmp], A6_0[kAcol]), _mm_set1_pd(A6[jj]))), _mm_mul_pd
                      (_mm_set_pd(A6_0[A6_tmp + 2], A6_0[kAcol + 2]),
                       _mm_set1_pd(A6[jj + 8]))), _mm_mul_pd(_mm_set_pd
          (A6_0[A6_tmp + 3], A6_0[kAcol + 3]), _mm_set1_pd(A6[jj + 12]))),
          _mm_mul_pd(_mm_set_pd(A6[iy], A6[jA]), _mm_set1_pd(6.704425728E+11))),
          _mm_mul_pd(_mm_set_pd(A4[iy], A4[jA]), _mm_set1_pd(1.29060195264E+14))),
          _mm_mul_pd(_mm_set_pd(A2[iy], A2[jA]), _mm_set1_pd(7.7717703038976E+15))));
        V[jA] = tmp_2[0];
        V[iy] = tmp_2[1];
      }
    }

    d = 6.476475253248E+16;
  }

  tmp = _mm_set1_pd(d);
  _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(V[5], V[0]), tmp));
  V[0] = tmp_2[0];
  V[5] = tmp_2[1];
  _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(V[15], V[10]), tmp));
  V[10] = tmp_2[0];
  V[15] = tmp_2[1];
  for (jA = 0; jA <= 14; jA += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp = _mm_loadu_pd(&V[jA]);
    tmp_0 = _mm_loadu_pd(&F[jA]);
    _mm_storeu_pd(&V[jA], _mm_sub_pd(tmp, tmp_0));
    _mm_storeu_pd(&F[jA], _mm_mul_pd(_mm_set1_pd(2.0), tmp_0));
  }

  b_ipiv[0] = 1;
  b_ipiv[1] = 2;
  b_ipiv[2] = 3;
  b_ipiv[3] = 4;
  for (int32_T g_k{0}; g_k < 3; g_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    A6_tmp = g_k * 5 + 2;
    jj = g_k * 5;
    kAcol = 4 - g_k;
    iy = 1;

    /* Start for MATLABSystem: '<S1>/solver' */
    d = std::abs(V[jj]);
    for (jA = 2; jA <= kAcol; jA++) {
      s = std::abs(V[(A6_tmp + jA) - 3]);
      if (s > d) {
        iy = jA;
        d = s;
      }
    }

    if (V[(A6_tmp + iy) - 3] != 0.0) {
      if (iy - 1 != 0) {
        kAcol = g_k + iy;
        b_ipiv[g_k] = static_cast<int8_T>(kAcol);
        d = V[g_k];
        V[g_k] = V[kAcol - 1];
        V[kAcol - 1] = d;
        d = V[g_k + 4];
        V[g_k + 4] = V[kAcol + 3];
        V[kAcol + 3] = d;
        d = V[g_k + 8];
        V[g_k + 8] = V[kAcol + 7];
        V[kAcol + 7] = d;
        d = V[g_k + 12];
        V[g_k + 12] = V[kAcol + 11];
        V[kAcol + 11] = d;
      }

      iy = A6_tmp - g_k;
      for (jA = A6_tmp; jA <= iy + 2; jA++) {
        V[jA - 1] /= V[jj];
      }
    }

    jA = jj;
    jj += 4;
    iy = 3 - g_k;
    for (jp1j = 0; jp1j < iy; jp1j++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      d = V[(jp1j << 2) + jj];
      if (d != 0.0) {
        /* Start for MATLABSystem: '<S1>/solver' */
        kAcol = jA + 6;
        jBcol = (jA - g_k) + 8;
        for (int32_T ijA{kAcol}; ijA <= jBcol; ijA++) {
          /* Start for MATLABSystem: '<S1>/solver' */
          V[ijA - 1] += V[((A6_tmp + ijA) - jA) - 7] * -d;
        }
      }

      /* Start for MATLABSystem: '<S1>/solver' */
      jA += 4;
    }
  }

  for (iy = 0; iy < 3; iy++) {
    int8_T b_ipiv_0;

    /* Start for MATLABSystem: '<S1>/solver' */
    b_ipiv_0 = b_ipiv[iy];
    if (iy + 1 != b_ipiv_0) {
      d = F[iy];
      F[iy] = F[b_ipiv_0 - 1];
      F[b_ipiv_0 - 1] = d;
      d = F[iy + 4];
      F[iy + 4] = F[b_ipiv_0 + 3];
      F[b_ipiv_0 + 3] = d;
      d = F[iy + 8];
      F[iy + 8] = F[b_ipiv_0 + 7];
      F[b_ipiv_0 + 7] = d;
      d = F[iy + 12];
      F[iy + 12] = F[b_ipiv_0 + 11];
      F[b_ipiv_0 + 11] = d;
    }
  }

  for (int32_T g_k{0}; g_k < 4; g_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    jBcol = (g_k << 2) - 1;
    for (A6_tmp = 0; A6_tmp < 4; A6_tmp++) {
      kAcol = (A6_tmp << 2) - 1;
      jj = (A6_tmp + jBcol) + 1;
      if (F[jj] != 0.0) {
        for (jA = A6_tmp + 2; jA < 5; jA++) {
          jp1j = jA + jBcol;

          /* Start for MATLABSystem: '<S1>/solver' */
          F[jp1j] -= V[jA + kAcol] * F[jj];
        }
      }
    }
  }

  for (int32_T g_k{0}; g_k < 4; g_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    jBcol = g_k << 2;
    for (jA = 3; jA >= 0; jA--) {
      kAcol = jA << 2;
      jj = jA + jBcol;
      d = F[jj];
      if (d != 0.0) {
        F[jj] = d / V[jA + kAcol];
        A6_tmp = jA - 1;
        for (iy = 0; iy <= A6_tmp; iy++) {
          jp1j = iy + jBcol;
          F[jp1j] -= V[iy + kAcol] * F[jj];
        }
      }
    }
  }

  tmp = _mm_set1_pd(1.0);
  _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[5], F[0]), tmp));
  F[0] = tmp_2[0];
  F[5] = tmp_2[1];
  _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_set_pd(F[15], F[10]), tmp));
  F[10] = tmp_2[0];
  F[15] = tmp_2[1];
}

void longitudinal_mpc::longitudinal_recomputeBlockDiag(const real_T A[16],
  real_T F[16], const int32_T blockFormat[3])
{
  real_T tmp[2];
  real_T delta;
  real_T expa;
  real_T sinchdelta;
  real_T x;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (blockFormat[0] != 0) {
    if (blockFormat[0] == 1) {
      delta = std::exp(A[0]);
      expa = std::exp(A[5]);
      sinchdelta = (A[0] + A[5]) / 2.0;
      if (std::fmax(sinchdelta, std::abs(A[0] - A[5]) / 2.0) < 709.782712893384)
      {
        x = (A[5] - A[0]) / 2.0;
        if (x == 0.0) {
          x = 1.0;
        } else {
          x = std::sinh(x) / x;
        }

        sinchdelta = A[4] * std::exp(sinchdelta) * x;
      } else {
        sinchdelta = (expa - delta) * A[4] / (A[5] - A[0]);
      }

      F[0] = delta;
      F[4] = sinchdelta;
      F[5] = expa;
    } else {
      delta = std::sqrt(std::abs(A[1] * A[4]));
      expa = std::exp(A[0]);
      if (delta == 0.0) {
        sinchdelta = 1.0;
      } else {
        sinchdelta = std::sin(delta) / delta;
      }

      F[0] = expa * std::cos(delta);
      _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_mul_pd(_mm_set1_pd(expa), _mm_set_pd
        (A[4], A[1])), _mm_set1_pd(sinchdelta)));
      F[1] = tmp[0];
      F[4] = tmp[1];
      F[5] = F[0];
    }
  }

  if (blockFormat[1] != 0) {
    if (blockFormat[1] == 1) {
      delta = std::exp(A[5]);
      expa = std::exp(A[10]);
      sinchdelta = (A[5] + A[10]) / 2.0;
      if (std::fmax(sinchdelta, std::abs(A[5] - A[10]) / 2.0) < 709.782712893384)
      {
        x = (A[10] - A[5]) / 2.0;
        if (x == 0.0) {
          x = 1.0;
        } else {
          x = std::sinh(x) / x;
        }

        sinchdelta = A[9] * std::exp(sinchdelta) * x;
      } else {
        sinchdelta = (expa - delta) * A[9] / (A[10] - A[5]);
      }

      F[5] = delta;
      F[9] = sinchdelta;
      F[10] = expa;
    } else {
      delta = std::sqrt(std::abs(A[6] * A[9]));
      expa = std::exp(A[5]);
      if (delta == 0.0) {
        sinchdelta = 1.0;
      } else {
        sinchdelta = std::sin(delta) / delta;
      }

      F[5] = expa * std::cos(delta);
      _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_mul_pd(_mm_set1_pd(expa), _mm_set_pd
        (A[9], A[6])), _mm_set1_pd(sinchdelta)));
      F[6] = tmp[0];
      F[9] = tmp[1];
      F[10] = F[5];
    }
  }

  if (blockFormat[2] != 0) {
    if (blockFormat[2] == 1) {
      delta = std::exp(A[10]);
      expa = std::exp(A[15]);
      sinchdelta = (A[10] + A[15]) / 2.0;
      if (std::fmax(sinchdelta, std::abs(A[10] - A[15]) / 2.0) <
          709.782712893384) {
        x = (A[15] - A[10]) / 2.0;
        if (x == 0.0) {
          x = 1.0;
        } else {
          x = std::sinh(x) / x;
        }

        sinchdelta = A[14] * std::exp(sinchdelta) * x;
      } else {
        sinchdelta = (expa - delta) * A[14] / (A[15] - A[10]);
      }

      F[10] = delta;
      F[14] = sinchdelta;
      F[15] = expa;
    } else {
      delta = std::sqrt(std::abs(A[11] * A[14]));
      expa = std::exp(A[10]);
      if (delta == 0.0) {
        sinchdelta = 1.0;
      } else {
        sinchdelta = std::sin(delta) / delta;
      }

      F[10] = expa * std::cos(delta);
      _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_mul_pd(_mm_set1_pd(expa), _mm_set_pd
        (A[14], A[11])), _mm_set1_pd(sinchdelta)));
      F[11] = tmp[0];
      F[14] = tmp[1];
      F[15] = F[10];
    }
  }

  if (blockFormat[2] == 0) {
    F[15] = std::exp(A[15]);
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

real_T longitudinal_mpc::longitudinal_mpc_xnrm2(int32_T n, const real_T x[16],
  int32_T ix0)
{
  real_T y;
  y = 0.0;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      for (int32_T k{ix0}; k <= ix0 + 1; k++) {
        real_T absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else if (std::isnan(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

void longitudinal_mpc::longitudinal_mpc_xzlascl(real_T cfrom, real_T cto,
  int32_T m, real_T A[4], int32_T iA0)
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  /* Start for MATLABSystem: '<S1>/solver' */
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    int32_T scalarLB;
    int32_T tmp_0;
    int32_T vectorUB;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((std::abs(cfrom1) > std::abs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (std::abs(cto1) > std::abs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    scalarLB = (m / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T b_i{0}; b_i <= vectorUB; b_i += 2) {
      __m128d tmp;
      tmp_0 = (b_i + iA0) - 1;
      tmp = _mm_loadu_pd(&A[tmp_0]);
      _mm_storeu_pd(&A[tmp_0], _mm_mul_pd(tmp, _mm_set1_pd(mul)));
    }

    for (int32_T b_i{scalarLB}; b_i < m; b_i++) {
      tmp_0 = (b_i + iA0) - 1;
      A[tmp_0] *= mul;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xzlascl_b(real_T cfrom, real_T cto,
  int32_T m, real_T A[3], int32_T iA0)
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  /* Start for MATLABSystem: '<S1>/solver' */
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    int32_T scalarLB;
    int32_T tmp_0;
    int32_T vectorUB;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((std::abs(cfrom1) > std::abs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (std::abs(cto1) > std::abs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    scalarLB = (m / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T b_i{0}; b_i <= vectorUB; b_i += 2) {
      __m128d tmp;
      tmp_0 = (b_i + iA0) - 1;
      tmp = _mm_loadu_pd(&A[tmp_0]);
      _mm_storeu_pd(&A[tmp_0], _mm_mul_pd(tmp, _mm_set1_pd(mul)));
    }

    for (int32_T b_i{scalarLB}; b_i < m; b_i++) {
      tmp_0 = (b_i + iA0) - 1;
      A[tmp_0] *= mul;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xzlartg(real_T f, real_T g, real_T *cs,
  real_T *sn, real_T *r)
{
  real_T f1;

  /* Start for MATLABSystem: '<S1>/solver' */
  /* Start for MATLABSystem: '<S1>/solver' */
  f1 = std::abs(f);
  *r = std::abs(g);
  if (g == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
    *r = f;
  } else if (f == 0.0) {
    *cs = 0.0;

    /* Start for MATLABSystem: '<S1>/solver' */
    if (g >= 0.0) {
      *sn = 1.0;
    } else {
      *sn = -1.0;
    }
  } else if ((f1 > 1.4916681462400413E-154) && (f1 < 4.7403759540545887E+153) &&
             (*r > 1.4916681462400413E-154) && (*r < 4.7403759540545887E+153)) {
    /* Start for MATLABSystem: '<S1>/solver' */
    *r = std::sqrt(f * f + g * g);
    *cs = f1 / *r;

    /* Start for MATLABSystem: '<S1>/solver' */
    if (!(f >= 0.0)) {
      *r = -*r;
    }

    *sn = g / *r;
  } else {
    real_T fs;
    real_T gs;

    /* Start for MATLABSystem: '<S1>/solver' */
    f1 = std::fmin(4.49423283715579E+307, std::fmax(2.2250738585072014E-308, std::
      fmax(f1, *r)));
    fs = f / f1;
    gs = g / f1;

    /* Start for MATLABSystem: '<S1>/solver' */
    *r = std::sqrt(fs * fs + gs * gs);
    *cs = std::abs(fs) / *r;
    if (!(f >= 0.0)) {
      *r = -*r;
    }

    *sn = gs / *r;
    *r *= f1;
  }
}

void longitudinal_mpc::longitudinal_mpc_rotateRight_b(int32_T n, real_T z[16],
  int32_T iz0, const real_T cs[6], int32_T ic0, int32_T is0)
{
  int32_T b;

  /* Start for MATLABSystem: '<S1>/solver' */
  b = n - 2;
  for (int32_T b_j{0}; b_j <= b; b_j++) {
    real_T ctemp;
    real_T stemp;
    int32_T offsetj;
    int32_T offsetjp1;
    ctemp = cs[(b_j + ic0) - 1];
    stemp = cs[(b_j + is0) - 1];
    offsetj = ((b_j << 2) + iz0) - 2;
    offsetjp1 = (((b_j + 1) << 2) + iz0) - 2;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      real_T temp;
      real_T z_0;
      temp = z[offsetjp1 + 1];
      z_0 = z[offsetj + 1];
      z[offsetjp1 + 1] = ctemp * temp - z_0 * stemp;
      z[offsetj + 1] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 2];
      z_0 = z[offsetj + 2];
      z[offsetjp1 + 2] = ctemp * temp - z_0 * stemp;
      z[offsetj + 2] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 3];
      z_0 = z[offsetj + 3];
      z[offsetjp1 + 3] = ctemp * temp - z_0 * stemp;
      z[offsetj + 3] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 4];
      z_0 = z[offsetj + 4];
      z[offsetjp1 + 4] = ctemp * temp - z_0 * stemp;
      z[offsetj + 4] = z_0 * ctemp + stemp * temp;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xdlaev2(real_T a, real_T b, real_T c,
  real_T *rt1, real_T *rt2, real_T *cs1, real_T *sn1)
{
  real_T ab;
  real_T acmn;
  real_T acmx;
  real_T adf;
  real_T df;
  real_T sm;
  real_T tb;
  int32_T sgn1;
  int32_T sgn2;
  sm = a + c;
  df = a - c;

  /* Start for MATLABSystem: '<S1>/solver' */
  adf = std::abs(df);
  tb = b + b;

  /* Start for MATLABSystem: '<S1>/solver' */
  ab = std::abs(tb);
  if (std::abs(a) > std::abs(c)) {
    acmx = a;
    acmn = c;
  } else {
    acmx = c;
    acmn = a;
  }

  if (adf > ab) {
    real_T a_0;
    a_0 = ab / adf;

    /* Start for MATLABSystem: '<S1>/solver' */
    adf *= std::sqrt(a_0 * a_0 + 1.0);
  } else if (adf < ab) {
    real_T a_0;
    a_0 = adf / ab;

    /* Start for MATLABSystem: '<S1>/solver' */
    adf = std::sqrt(a_0 * a_0 + 1.0) * ab;
  } else {
    adf = ab * 1.4142135623730951;
  }

  if (sm < 0.0) {
    *rt1 = (sm - adf) * 0.5;
    sgn1 = -1;
    *rt2 = acmx / *rt1 * acmn - b / *rt1 * b;
  } else if (sm > 0.0) {
    *rt1 = (sm + adf) * 0.5;
    sgn1 = 1;
    *rt2 = acmx / *rt1 * acmn - b / *rt1 * b;
  } else {
    *rt1 = 0.5 * adf;
    *rt2 = -0.5 * adf;
    sgn1 = 1;
  }

  if (df >= 0.0) {
    df += adf;
    sgn2 = 1;
  } else {
    df -= adf;
    sgn2 = -1;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  if (std::abs(df) > ab) {
    tb = -tb / df;
    *sn1 = 1.0 / std::sqrt(tb * tb + 1.0);
    *cs1 = tb * *sn1;
  } else if (ab == 0.0) {
    *cs1 = 1.0;
    *sn1 = 0.0;
  } else {
    tb = -df / tb;
    *cs1 = 1.0 / std::sqrt(tb * tb + 1.0);
    *sn1 = tb * *cs1;
  }

  if (sgn1 == sgn2) {
    tb = *cs1;
    *cs1 = -*sn1;
    *sn1 = tb;
  }
}

void longitudinal_mpc::longitudinal_mpc_rotateRight(int32_T n, real_T z[16],
  int32_T iz0, const real_T cs[6], int32_T ic0, int32_T is0)
{
  /* Start for MATLABSystem: '<S1>/solver' */
  for (int32_T j{n - 1}; j >= 1; j--) {
    real_T ctemp;
    real_T stemp;
    int32_T offsetj;
    int32_T offsetjp1;
    ctemp = cs[(ic0 + j) - 2];
    stemp = cs[(is0 + j) - 2];
    offsetj = (((j - 1) << 2) + iz0) - 2;
    offsetjp1 = ((j << 2) + iz0) - 2;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      real_T temp;
      real_T z_0;
      temp = z[offsetjp1 + 1];
      z_0 = z[offsetj + 1];
      z[offsetjp1 + 1] = ctemp * temp - z_0 * stemp;
      z[offsetj + 1] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 2];
      z_0 = z[offsetj + 2];
      z[offsetjp1 + 2] = ctemp * temp - z_0 * stemp;
      z[offsetj + 2] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 3];
      z_0 = z[offsetj + 3];
      z[offsetjp1 + 3] = ctemp * temp - z_0 * stemp;
      z[offsetj + 3] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 4];
      z_0 = z[offsetj + 4];
      z[offsetjp1 + 4] = ctemp * temp - z_0 * stemp;
      z[offsetj + 4] = z_0 * ctemp + stemp * temp;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

int32_T longitudinal_mpc::longitudinal_mpc_xzsteqr(real_T d[4], real_T e[3],
  real_T z[16])
{
  real_T work[6];
  real_T anorm;
  real_T b;
  real_T c;
  real_T c_s;
  real_T e_0;
  real_T p;
  real_T r;
  real_T s;
  real_T tst;
  int32_T exitg1;
  int32_T exitg3;
  int32_T exitg4;
  int32_T i;
  int32_T info;
  int32_T iscale;
  int32_T iscale_tmp;
  int32_T jtot;
  int32_T l;
  int32_T l1;
  int32_T lend;
  int32_T lendsv;
  int32_T lsv;
  int32_T m;
  boolean_T exitg2;

  /* Start for MATLABSystem: '<S1>/solver' */
  info = 0;
  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  jtot = 0;
  l1 = 1;
  do {
    exitg1 = 0;
    if (l1 > 4) {
      for (jtot = 0; jtot < 3; jtot++) {
        l1 = jtot;
        p = d[jtot];
        for (m = jtot + 2; m < 5; m++) {
          tst = d[m - 1];
          if (tst < p) {
            l1 = m - 1;
            p = tst;
          }
        }

        if (l1 != jtot) {
          d[l1] = d[jtot];
          d[jtot] = p;
          m = jtot << 2;
          l = l1 << 2;
          tst = z[m];
          z[m] = z[l];
          z[l] = tst;
          tst = z[m + 1];
          z[m + 1] = z[l + 1];
          z[l + 1] = tst;
          tst = z[m + 2];
          z[m + 2] = z[l + 2];
          z[l + 2] = tst;
          tst = z[m + 3];
          z[m + 3] = z[l + 3];
          z[l + 3] = tst;
        }
      }

      exitg1 = 1;
    } else {
      if (l1 > 1) {
        e[l1 - 2] = 0.0;
      }

      m = l1;
      exitg2 = false;
      while ((!exitg2) && (m < 4)) {
        tst = std::abs(e[m - 1]);
        if (tst == 0.0) {
          exitg2 = true;
        } else if (tst <= std::sqrt(std::abs(d[m - 1])) * std::sqrt(std::abs(d[m]))
                   * 2.2204460492503131E-16) {
          e[m - 1] = 0.0;
          exitg2 = true;
        } else {
          m++;
        }
      }

      l = l1 - 1;
      lsv = l1;
      lend = m;
      lendsv = m;
      l1 = m + 1;
      if (l + 1 == m) {
      } else {
        iscale_tmp = m - l;
        if (iscale_tmp <= 0) {
          tst = 0.0;
        } else {
          tst = std::abs(d[(l + iscale_tmp) - 1]);
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i <= iscale_tmp - 2)) {
            iscale = l + i;
            anorm = std::abs(d[iscale]);
            if (std::isnan(anorm)) {
              tst = (rtNaN);
              exitg2 = true;
            } else {
              if (anorm > tst) {
                tst = anorm;
              }

              anorm = std::abs(e[iscale]);
              if (std::isnan(anorm)) {
                tst = (rtNaN);
                exitg2 = true;
              } else {
                if (anorm > tst) {
                  tst = anorm;
                }

                i++;
              }
            }
          }
        }

        iscale = 0;
        if (tst == 0.0) {
        } else if (std::isinf(tst) || std::isnan(tst)) {
          d[0] = (rtNaN);
          d[1] = (rtNaN);
          d[2] = (rtNaN);
          d[3] = (rtNaN);
          for (i = 0; i < 16; i++) {
            z[i] = (rtNaN);
          }

          exitg1 = 1;
        } else {
          if (tst > 2.2346346549904327E+153) {
            iscale = 1;
            longitudinal_mpc_xzlascl(tst, 2.2346346549904327E+153, iscale_tmp, d,
              l + 1);
            longitudinal_mpc_xzlascl_b(tst, 2.2346346549904327E+153, iscale_tmp
              - 1, e, l + 1);
          } else if (tst < 3.02546243347603E-123) {
            iscale = 2;
            longitudinal_mpc_xzlascl(tst, 3.02546243347603E-123, iscale_tmp, d,
              l + 1);
            longitudinal_mpc_xzlascl_b(tst, 3.02546243347603E-123, iscale_tmp -
              1, e, l + 1);
          }

          if (std::abs(d[m - 1]) < std::abs(d[l])) {
            lend = lsv;
            l = m - 1;
          }

          if (lend > l + 1) {
            do {
              exitg4 = 0;
              if (l + 1 != lend) {
                m = l + 1;
                exitg2 = false;
                while ((!exitg2) && (m < lend)) {
                  anorm = std::abs(e[m - 1]);
                  if (anorm * anorm <= std::abs(d[m - 1]) *
                      4.9303806576313238E-32 * std::abs(d[m]) +
                      2.2250738585072014E-308) {
                    exitg2 = true;
                  } else {
                    m++;
                  }
                }
              } else {
                m = lend;
              }

              if (m < lend) {
                e[m - 1] = 0.0;
              }

              if (l + 1 == m) {
                l++;
                if (l + 1 > lend) {
                  exitg4 = 1;
                }
              } else if (l + 2 == m) {
                longitudinal_mpc_xdlaev2(d[l], e[l], d[l + 1], &d[l], &anorm,
                  &work[l], &s);
                d[l + 1] = anorm;
                work[l + 3] = s;
                longitudinal_mpc_rotateRight(2, z, (l << 2) + 1, work, l + 1, l
                  + 4);
                e[l] = 0.0;
                l += 2;
                if (l + 1 > lend) {
                  exitg4 = 1;
                }
              } else if (jtot == 120) {
                exitg4 = 1;
              } else {
                jtot++;
                anorm = (d[l + 1] - d[l]) / (2.0 * e[l]);
                if (anorm >= 0.0) {
                  s = rt_hypotd_snf(anorm, 1.0);
                } else {
                  s = -rt_hypotd_snf(anorm, 1.0);
                }

                anorm = (d[m - 1] - d[l]) + e[l] / (anorm + s);
                s = 1.0;
                c = 1.0;
                p = 0.0;
                for (i = m - 1; i >= l + 1; i--) {
                  e_0 = e[i - 1];
                  b = c * e_0;
                  longitudinal_mpc_xzlartg(anorm, s * e_0, &c, &c_s, &r);
                  s = c_s;
                  if (m - 1 != i) {
                    e[i] = r;
                  }

                  anorm = d[i] - p;
                  r = (d[i - 1] - anorm) * c_s + 2.0 * c * b;
                  p = c_s * r;
                  d[i] = anorm + p;
                  anorm = c * r - b;
                  work[i - 1] = c;
                  work[i + 2] = -c_s;
                }

                longitudinal_mpc_rotateRight(m - l, z, (l << 2) + 1, work, l + 1,
                  l + 4);
                d[l] -= p;
                e[l] = anorm;
              }
            } while (exitg4 == 0);
          } else {
            do {
              exitg3 = 0;
              if (l + 1 != lend) {
                m = l + 1;
                exitg2 = false;
                while ((!exitg2) && (m > lend)) {
                  anorm = std::abs(e[m - 2]);
                  if (anorm * anorm <= std::abs(d[m - 1]) *
                      4.9303806576313238E-32 * std::abs(d[m - 2]) +
                      2.2250738585072014E-308) {
                    exitg2 = true;
                  } else {
                    m--;
                  }
                }
              } else {
                m = lend;
              }

              if (m > lend) {
                e[m - 2] = 0.0;
              }

              if (l + 1 == m) {
                l--;
                if (l + 1 < lend) {
                  exitg3 = 1;
                }
              } else if (m == l) {
                longitudinal_mpc_xdlaev2(d[l - 1], e[l - 1], d[l], &d[l - 1],
                  &anorm, &work[m - 1], &s);
                d[l] = anorm;
                work[m + 2] = s;
                longitudinal_mpc_rotateRight_b(2, z, ((l - 1) << 2) + 1, work, m,
                  m + 3);
                e[l - 1] = 0.0;
                l -= 2;
                if (l + 1 < lend) {
                  exitg3 = 1;
                }
              } else if (jtot == 120) {
                exitg3 = 1;
              } else {
                jtot++;
                p = e[l - 1];
                anorm = (d[l - 1] - d[l]) / (p * 2.0);
                if (anorm >= 0.0) {
                  s = rt_hypotd_snf(anorm, 1.0);
                } else {
                  s = -rt_hypotd_snf(anorm, 1.0);
                }

                anorm = (d[m - 1] - d[l]) + p / (anorm + s);
                s = 1.0;
                c = 1.0;
                p = 0.0;
                for (i = m; i <= l; i++) {
                  e_0 = e[i - 1];
                  b = c * e_0;
                  longitudinal_mpc_xzlartg(anorm, s * e_0, &c, &c_s, &r);
                  s = c_s;
                  if (i != m) {
                    e[i - 2] = r;
                  }

                  anorm = d[i - 1] - p;
                  r = (d[i] - anorm) * c_s + 2.0 * c * b;
                  p = c_s * r;
                  d[i - 1] = anorm + p;
                  anorm = c * r - b;
                  work[i - 1] = c;
                  work[i + 2] = c_s;
                }

                longitudinal_mpc_rotateRight_b((l - m) + 2, z, ((m - 1) << 2) +
                  1, work, m, m + 3);
                d[l] -= p;
                e[l - 1] = anorm;
              }
            } while (exitg3 == 0);
          }

          if (iscale == 1) {
            i = lendsv - lsv;
            longitudinal_mpc_xzlascl(2.2346346549904327E+153, tst, i + 1, d, lsv);
            longitudinal_mpc_xzlascl_b(2.2346346549904327E+153, tst, i, e, lsv);
          } else if (iscale == 2) {
            i = lendsv - lsv;
            longitudinal_mpc_xzlascl(3.02546243347603E-123, tst, i + 1, d, lsv);
            longitudinal_mpc_xzlascl_b(3.02546243347603E-123, tst, i, e, lsv);
          }

          if (jtot >= 120) {
            if (e[0] != 0.0) {
              info = 1;
            }

            if (e[1] != 0.0) {
              info++;
            }

            if (e[2] != 0.0) {
              info++;
            }

            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return info;
}

void longitudinal_mpc::longitudinal_mpc_xsyheev(const real_T A[16], int32_T
  *info, real_T W[4], real_T b_A[16])
{
  __m128d tmp;
  __m128d tmp_0;
  real_T work[4];
  real_T e[3];
  real_T tau[3];
  real_T tmp_1[2];
  real_T absx;
  real_T anrm;
  real_T beta1;
  real_T cto1;
  real_T ctoc;
  real_T mul;
  int32_T b_A_tmp;
  int32_T ctoc_tmp;
  int32_T ctoc_tmp_tmp_tmp;
  int32_T exitg1;
  int32_T i;
  int32_T ia0;
  int32_T itau;
  int32_T ix;
  int32_T jy;
  int32_T knt;
  int32_T lastv;
  int32_T vectorUB;
  boolean_T exitg2;
  boolean_T iscale;
  boolean_T notdone;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  *info = 0;
  anrm = 0.0;
  for (ix = 0; ix < 4; ix++) {
    for (itau = 0; itau <= ix; itau++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      absx = std::abs(A[(ix << 2) + itau]);
      if (absx > anrm) {
        anrm = absx;
      }
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  if (std::isinf(anrm)) {
    W[0] = (rtNaN);
    W[1] = (rtNaN);
    W[2] = (rtNaN);
    W[3] = (rtNaN);
    for (knt = 0; knt < 16; knt++) {
      b_A[knt] = (rtNaN);
    }
  } else {
    iscale = false;
    if ((anrm > 0.0) && (anrm < 1.0010415475915505E-146)) {
      iscale = true;
      anrm = 1.0010415475915505E-146 / anrm;
      absx = 1.0;
      ctoc = anrm;
      notdone = true;
      while (notdone) {
        beta1 = absx * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((std::abs(beta1) > ctoc) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          absx = beta1;
        } else if (cto1 > std::abs(absx)) {
          mul = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          mul = ctoc / absx;
          notdone = false;
        }

        for (ix = 0; ix < 4; ix++) {
          b_A_tmp = ix << 2;
          b_A[b_A_tmp] *= mul;
          b_A[b_A_tmp + 1] *= mul;
          b_A[b_A_tmp + 2] *= mul;
          b_A[b_A_tmp + 3] *= mul;
        }
      }
    }

    for (itau = 0; itau < 3; itau++) {
      if (itau + 3 <= 4) {
        knt = itau + 3;
      } else {
        knt = 4;
      }

      lastv = itau << 2;
      ia0 = lastv + knt;
      ctoc_tmp_tmp_tmp = lastv + itau;
      ctoc = b_A[ctoc_tmp_tmp_tmp + 1];
      absx = 0.0;
      beta1 = longitudinal_mpc_xnrm2(2 - itau, b_A, ia0);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(ctoc, beta1);
        if (ctoc >= 0.0) {
          beta1 = -beta1;
        }

        if (std::abs(beta1) < 1.0020841800044864E-292) {
          knt = -1;
          do {
            knt++;
            jy = ia0 - itau;
            i = ((((jy - ia0) + 2) / 2) << 1) + ia0;
            vectorUB = i - 2;
            for (ix = ia0; ix <= vectorUB; ix += 2) {
              tmp = _mm_loadu_pd(&b_A[ix - 1]);
              _mm_storeu_pd(&b_A[ix - 1], _mm_mul_pd(tmp, _mm_set1_pd
                (9.9792015476736E+291)));
            }

            for (ix = i; ix <= jy + 1; ix++) {
              b_A[ix - 1] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            ctoc *= 9.9792015476736E+291;
          } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt + 1 < 20));

          beta1 = rt_hypotd_snf(ctoc, longitudinal_mpc_xnrm2(2 - itau, b_A, ia0));
          if (ctoc >= 0.0) {
            beta1 = -beta1;
          }

          absx = (beta1 - ctoc) / beta1;
          ctoc = 1.0 / (ctoc - beta1);
          for (ix = ia0; ix <= vectorUB; ix += 2) {
            tmp = _mm_loadu_pd(&b_A[ix - 1]);
            _mm_storeu_pd(&b_A[ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(ctoc)));
          }

          for (ix = i; ix <= jy + 1; ix++) {
            b_A[ix - 1] *= ctoc;
          }

          for (ix = 0; ix <= knt; ix++) {
            beta1 *= 1.0020841800044864E-292;
          }

          ctoc = beta1;
        } else {
          absx = (beta1 - ctoc) / beta1;
          ctoc = 1.0 / (ctoc - beta1);
          i = ia0 - itau;
          jy = ((((i - ia0) + 2) / 2) << 1) + ia0;
          vectorUB = jy - 2;
          for (ix = ia0; ix <= vectorUB; ix += 2) {
            tmp = _mm_loadu_pd(&b_A[ix - 1]);
            _mm_storeu_pd(&b_A[ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(ctoc)));
          }

          for (ix = jy; ix <= i + 1; ix++) {
            b_A[ix - 1] *= ctoc;
          }

          ctoc = beta1;
        }
      }

      e[itau] = ctoc;
      if (absx != 0.0) {
        b_A[ctoc_tmp_tmp_tmp + 1] = 1.0;
        for (ia0 = itau + 1; ia0 < 4; ia0++) {
          tau[ia0 - 1] = 0.0;
        }

        vectorUB = 2 - itau;
        jy = 3 - itau;
        for (ia0 = 0; ia0 <= vectorUB; ia0++) {
          ctoc_tmp = itau + ia0;
          ctoc = b_A[(ctoc_tmp + lastv) + 1] * absx;
          beta1 = 0.0;
          i = ((ctoc_tmp + 1) << 2) + itau;
          tau[ctoc_tmp] += b_A[(i + ia0) + 1] * ctoc;
          for (ix = ia0 + 2; ix <= jy; ix++) {
            knt = itau + ix;
            _mm_storeu_pd(&tmp_1[0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(b_A[i +
              ix]), _mm_set_pd(b_A[knt + lastv], ctoc)), _mm_set_pd(beta1,
              tau[knt - 1])));
            tau[knt - 1] = tmp_1[0];
            beta1 = tmp_1[1];
          }

          tau[ctoc_tmp] += absx * beta1;
        }

        ctoc = 0.0;
        for (ix = 0; ix < jy; ix++) {
          ctoc += b_A[(ctoc_tmp_tmp_tmp + ix) + 1] * tau[itau + ix];
        }

        ctoc *= -0.5 * absx;
        if (!(ctoc == 0.0)) {
          for (ix = 0; ix < jy; ix++) {
            i = itau + ix;
            tau[i] += b_A[(ctoc_tmp_tmp_tmp + ix) + 1] * ctoc;
          }
        }

        for (i = 0; i <= vectorUB; i++) {
          knt = i + 1;
          ctoc_tmp = i + itau;
          ctoc = b_A[(ctoc_tmp + lastv) + 1];
          beta1 = tau[ctoc_tmp];
          cto1 = beta1 * ctoc;
          b_A_tmp = (ctoc_tmp + 1) << 2;
          b_A[(ctoc_tmp + b_A_tmp) + 1] = (b_A[((b_A_tmp + i) + itau) + 1] -
            cto1) - cto1;
          for (ix = knt + 1; ix <= jy; ix++) {
            ia0 = itau + ix;
            b_A[ia0 + b_A_tmp] = (b_A[(b_A_tmp + itau) + ix] - tau[ia0 - 1] *
                                  ctoc) - b_A[ia0 + lastv] * beta1;
          }
        }
      }

      b_A[ctoc_tmp_tmp_tmp + 1] = e[itau];
      W[itau] = b_A[ctoc_tmp_tmp_tmp];
      tau[itau] = absx;
    }

    W[3] = b_A[15];
    for (ia0 = 2; ia0 >= 0; ia0--) {
      b_A_tmp = (ia0 + 1) << 2;
      b_A[b_A_tmp] = 0.0;
      for (itau = ia0 + 3; itau < 5; itau++) {
        b_A[(itau + b_A_tmp) - 1] = b_A[((ia0 << 2) + itau) - 1];
      }
    }

    b_A[0] = 1.0;
    b_A[1] = 0.0;
    b_A[2] = 0.0;
    b_A[3] = 0.0;
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    work[3] = 0.0;
    for (itau = 2; itau >= 0; itau--) {
      knt = ((itau << 2) + itau) + 10;
      if (itau + 1 < 3) {
        b_A[knt - 5] = 1.0;
        if (tau[itau] != 0.0) {
          lastv = 3 - itau;
          i = (knt - itau) - 3;
          while ((lastv > 0) && (b_A[i] == 0.0)) {
            lastv--;
            i--;
          }

          ia0 = 2 - itau;
          exitg2 = false;
          while ((!exitg2) && (ia0 > 0)) {
            i = ((ia0 - 1) << 2) + knt;
            jy = i;
            do {
              exitg1 = 0;
              if (jy <= (i + lastv) - 1) {
                if (b_A[jy - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  jy++;
                }
              } else {
                ia0--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = 0;
          ia0 = 0;
        }

        if (lastv > 0) {
          if (ia0 != 0) {
            std::memset(&work[0], 0, static_cast<uint32_T>((ia0 - 1) + 1) *
                        sizeof(real_T));
            ix = ((ia0 - 1) << 2) + knt;
            for (ctoc_tmp_tmp_tmp = knt; ctoc_tmp_tmp_tmp <= ix;
                 ctoc_tmp_tmp_tmp += 4) {
              absx = 0.0;
              i = ctoc_tmp_tmp_tmp + lastv;
              for (jy = ctoc_tmp_tmp_tmp; jy < i; jy++) {
                absx += b_A[((knt + jy) - ctoc_tmp_tmp_tmp) - 5] * b_A[jy - 1];
              }

              i = (ctoc_tmp_tmp_tmp - knt) >> 2;
              work[i] += absx;
            }
          }

          if (!(-tau[itau] == 0.0)) {
            jy = knt;
            i = ia0 - 1;
            for (ia0 = 0; ia0 <= i; ia0++) {
              absx = work[ia0];
              if (absx != 0.0) {
                absx *= -tau[itau];
                ix = (lastv + jy) - 1;
                for (ctoc_tmp_tmp_tmp = jy; ctoc_tmp_tmp_tmp <= ix;
                     ctoc_tmp_tmp_tmp++) {
                  b_A[ctoc_tmp_tmp_tmp - 1] += b_A[((knt + ctoc_tmp_tmp_tmp) -
                    jy) - 5] * absx;
                }
              }

              jy += 4;
            }
          }
        }

        i = knt - itau;
        jy = (((((i - knt) + 2) / 2) << 1) + knt) - 3;
        vectorUB = jy - 2;
        for (ix = knt - 3; ix <= vectorUB; ix += 2) {
          tmp = _mm_loadu_pd(&b_A[ix - 1]);
          _mm_storeu_pd(&b_A[ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(-tau[itau])));
        }

        for (ix = jy; ix <= i - 2; ix++) {
          b_A[ix - 1] *= -tau[itau];
        }
      }

      b_A[knt - 5] = 1.0 - tau[itau];
      ia0 = itau - 1;
      for (ix = 0; ix <= ia0; ix++) {
        b_A[(knt - ix) - 6] = 0.0;
      }
    }

    *info = longitudinal_mpc_xzsteqr(W, e, b_A);
    if (*info != 0) {
      W[0] = (rtNaN);
      W[1] = (rtNaN);
      W[2] = (rtNaN);
      W[3] = (rtNaN);
      for (knt = 0; knt < 16; knt++) {
        b_A[knt] = (rtNaN);
      }
    } else if (iscale) {
      tmp = _mm_set1_pd(1.0 / anrm);
      tmp_0 = _mm_mul_pd(tmp, _mm_loadu_pd(&W[0]));
      _mm_storeu_pd(&W[0], tmp_0);
      tmp = _mm_mul_pd(tmp, _mm_loadu_pd(&W[2]));
      _mm_storeu_pd(&W[2], tmp);
    }
  }
}

void longitudinal_mpc::longitudinal_mpc_expm(real_T A[16], real_T F[16])
{
  __m128d tmp_5;
  __m128d tmp_6;
  __m128d tmp_7;
  __m128d tmp_8;
  real_T A2[16];
  real_T A4[16];
  real_T A4_0[16];
  real_T A6[16];
  real_T T[16];
  real_T tmp_c[16];
  real_T w[4];
  real_T tmp[2];
  real_T tmp_0[2];
  real_T tmp_1[2];
  real_T tmp_2[2];
  real_T tmp_3[2];
  real_T tmp_4[2];
  real_T tmp_9[2];
  real_T A4_1;
  real_T A4_2;
  real_T A6_0;
  real_T d6;
  real_T eta1;
  real_T exptj;
  int32_T blockFormat[3];
  int32_T b_i;
  int32_T b_j;
  int32_T eint;
  int32_T exitg1;
  int32_T i;
  int32_T tmp_a;
  int32_T tmp_b;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  boolean_T recomputeDiags;
  recomputeDiags = true;
  b_j = 1;
  exitg2 = false;
  while ((!exitg2) && (b_j - 1 < 4)) {
    b_i = 1;
    do {
      exitg1 = 0;
      if (b_i - 1 < 4) {
        if ((b_i != b_j) && (!(A[(((b_j - 1) << 2) + b_i) - 1] == 0.0))) {
          recomputeDiags = false;
          exitg1 = 1;
        } else {
          b_i++;
        }
      } else {
        b_j++;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  if (recomputeDiags) {
    std::memset(&F[0], 0, sizeof(real_T) << 4U);

    /* Start for MATLABSystem: '<S1>/solver' */
    F[0] = std::exp(A[0]);
    F[5] = std::exp(A[5]);
    F[10] = std::exp(A[10]);
    F[15] = std::exp(A[15]);
  } else {
    recomputeDiags = true;
    b_j = 0;
    exitg2 = false;
    while ((!exitg2) && (b_j < 4)) {
      b_i = 0;
      do {
        exitg1 = 0;
        if (b_i <= b_j) {
          if (!(A[(b_j << 2) + b_i] == A[(b_i << 2) + b_j])) {
            recomputeDiags = false;
            exitg1 = 1;
          } else {
            b_i++;
          }
        } else {
          b_j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (recomputeDiags) {
      longitudinal_mpc_xsyheev(A, &b_j, w, A2);
      for (b_j = 0; b_j <= 2; b_j += 2) {
        b_i = b_j << 2;
        i = (b_j + 1) << 2;

        /* Start for MATLABSystem: '<S1>/solver' */
        tmp_5 = _mm_set_pd(std::exp(w[b_j + 1]), std::exp(w[b_j]));
        _mm_storeu_pd(&tmp_9[0], _mm_mul_pd(_mm_set_pd(A2[i], A2[b_i]), tmp_5));
        F[b_i] = tmp_9[0];
        F[i] = tmp_9[1];
        _mm_storeu_pd(&tmp_9[0], _mm_mul_pd(_mm_set_pd(A2[i + 1], A2[b_i + 1]),
          tmp_5));
        F[b_i + 1] = tmp_9[0];
        F[i + 1] = tmp_9[1];
        _mm_storeu_pd(&tmp_9[0], _mm_mul_pd(_mm_set_pd(A2[i + 2], A2[b_i + 2]),
          tmp_5));
        F[b_i + 2] = tmp_9[0];
        F[i + 2] = tmp_9[1];
        _mm_storeu_pd(&tmp_9[0], _mm_mul_pd(_mm_set_pd(A2[i + 3], A2[b_i + 3]),
          tmp_5));
        F[b_i + 3] = tmp_9[0];
        F[i + 3] = tmp_9[1];
      }

      for (b_i = 0; b_i < 4; b_i++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        exptj = F[b_i + 4];
        d6 = F[b_i];
        eta1 = F[b_i + 8];
        A4_1 = F[b_i + 12];
        for (i = 0; i <= 2; i += 2) {
          /* Start for MATLABSystem: '<S1>/solver' */
          tmp_5 = _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(exptj),
            _mm_loadu_pd(&A2[i + 4])), _mm_mul_pd(_mm_set1_pd(d6), _mm_loadu_pd(
            &A2[i]))), _mm_mul_pd(_mm_set1_pd(eta1), _mm_loadu_pd(&A2[i + 8]))),
                             _mm_mul_pd(_mm_set1_pd(A4_1), _mm_loadu_pd(&A2[i +
            12])));
          _mm_storeu_pd(&tmp_9[0], tmp_5);

          /* Start for MATLABSystem: '<S1>/solver' */
          A4[b_i + (i << 2)] = tmp_9[0];
          A4[b_i + ((i + 1) << 2)] = tmp_9[1];
        }
      }

      std::memcpy(&F[0], &A4[0], sizeof(real_T) << 4U);
      for (b_i = 0; b_i <= 2; b_i += 2) {
        i = b_i << 2;
        tmp_a = (b_i + 1) << 2;
        tmp_5 = _mm_set1_pd(2.0);
        tmp_6 = _mm_div_pd(_mm_add_pd(_mm_set_pd(F[tmp_a], F[i]), _mm_loadu_pd
          (&F[b_i])), tmp_5);
        _mm_storeu_pd(&tmp_9[0], tmp_6);
        A4[i] = tmp_9[0];
        A4[tmp_a] = tmp_9[1];
        tmp_6 = _mm_div_pd(_mm_add_pd(_mm_set_pd(F[tmp_a + 1], F[i + 1]),
          _mm_loadu_pd(&F[b_i + 4])), tmp_5);
        _mm_storeu_pd(&tmp_9[0], tmp_6);
        A4[i + 1] = tmp_9[0];
        A4[tmp_a + 1] = tmp_9[1];
        tmp_6 = _mm_div_pd(_mm_add_pd(_mm_set_pd(F[tmp_a + 2], F[i + 2]),
          _mm_loadu_pd(&F[b_i + 8])), tmp_5);
        _mm_storeu_pd(&tmp_9[0], tmp_6);
        A4[i + 2] = tmp_9[0];
        A4[tmp_a + 2] = tmp_9[1];
        tmp_5 = _mm_div_pd(_mm_add_pd(_mm_set_pd(F[tmp_a + 3], F[i + 3]),
          _mm_loadu_pd(&F[b_i + 12])), tmp_5);
        _mm_storeu_pd(&tmp_9[0], tmp_5);
        A4[i + 3] = tmp_9[0];
        A4[tmp_a + 3] = tmp_9[1];
      }

      std::memcpy(&F[0], &A4[0], sizeof(real_T) << 4U);
    } else {
      recomputeDiags = true;
      b_j = 3;

      /* Start for MATLABSystem: '<S1>/solver' */
      while (recomputeDiags && (b_j <= 4)) {
        b_i = b_j;
        while (recomputeDiags && (b_i <= 4)) {
          recomputeDiags = (A[(((b_j - 3) << 2) + b_i) - 1] == 0.0);
          b_i++;
        }

        b_j++;
      }

      if (recomputeDiags) {
        b_j = 1;
        exitg2 = false;
        while ((!exitg2) && (b_j - 1 < 3)) {
          b_i = ((b_j - 1) << 2) + b_j;
          d6 = A[b_i];
          if (d6 != 0.0) {
            if ((b_j != 3) && (A[((b_j << 2) + b_j) + 1] != 0.0)) {
              recomputeDiags = false;
              exitg2 = true;
            } else {
              i = (b_j << 2) + b_j;
              if (A[b_i - 1] != A[i]) {
                recomputeDiags = false;
                exitg2 = true;
              } else {
                exptj = A[i - 1];
                if (std::isnan(d6)) {
                  d6 = (rtNaN);
                } else if (d6 < 0.0) {
                  d6 = -1.0;
                } else {
                  d6 = (d6 > 0.0);
                }

                if (std::isnan(exptj)) {
                  exptj = (rtNaN);
                } else if (exptj < 0.0) {
                  exptj = -1.0;
                } else {
                  exptj = (exptj > 0.0);
                }

                if (d6 * exptj != -1.0) {
                  recomputeDiags = false;
                  exitg2 = true;
                } else {
                  b_j++;
                }
              }
            }
          } else {
            b_j++;
          }
        }
      }

      exptj = 0.0;
      for (b_i = 0; b_i < 4; b_i++) {
        for (i = 0; i <= 2; i += 2) {
          /* Start for MATLABSystem: '<S1>/solver' */
          tmp_5 = _mm_loadu_pd(&A[i + 4]);
          tmp_a = b_i << 2;
          tmp_6 = _mm_loadu_pd(&A[i]);
          tmp_7 = _mm_loadu_pd(&A[i + 8]);
          tmp_8 = _mm_loadu_pd(&A[i + 12]);
          _mm_storeu_pd(&A2[i + tmp_a], _mm_add_pd(_mm_add_pd(_mm_add_pd
            (_mm_mul_pd(_mm_set1_pd(A[tmp_a + 1]), tmp_5), _mm_mul_pd
             (_mm_set1_pd(A[tmp_a]), tmp_6)), _mm_mul_pd(_mm_set1_pd(A[tmp_a + 2]),
            tmp_7)), _mm_mul_pd(_mm_set1_pd(A[tmp_a + 3]), tmp_8)));
        }
      }

      for (b_i = 0; b_i < 4; b_i++) {
        for (i = 0; i <= 2; i += 2) {
          /* Start for MATLABSystem: '<S1>/solver' */
          tmp_a = (i + 1) << 2;
          tmp_b = i << 2;
          _mm_storeu_pd(&tmp_9[0], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
            (_mm_set_pd(A2[tmp_a + 1], A2[tmp_b + 1]), _mm_set1_pd(A2[b_i + 4])),
            _mm_mul_pd(_mm_set_pd(A2[tmp_a], A2[tmp_b]), _mm_set1_pd(A2[b_i]))),
            _mm_mul_pd(_mm_set_pd(A2[tmp_a + 2], A2[tmp_b + 2]), _mm_set1_pd
                       (A2[b_i + 8]))), _mm_mul_pd(_mm_set_pd(A2[tmp_a + 3],
            A2[tmp_b + 3]), _mm_set1_pd(A2[b_i + 12]))));
          A4[b_i + tmp_b] = tmp_9[0];
          A4[b_i + tmp_a] = tmp_9[1];
        }

        /* Start for MATLABSystem: '<S1>/solver' */
        d6 = A4[b_i + 4];
        eta1 = A4[b_i];
        A4_1 = A4[b_i + 8];
        A4_2 = A4[b_i + 12];
        for (i = 0; i <= 2; i += 2) {
          /* Start for MATLABSystem: '<S1>/solver' */
          tmp_a = (i + 1) << 2;
          tmp_b = i << 2;
          _mm_storeu_pd(&tmp_9[0], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
            (_mm_set_pd(A2[tmp_a + 1], A2[tmp_b + 1]), _mm_set1_pd(d6)),
            _mm_mul_pd(_mm_set_pd(A2[tmp_a], A2[tmp_b]), _mm_set1_pd(eta1))),
            _mm_mul_pd(_mm_set_pd(A2[tmp_a + 2], A2[tmp_b + 2]), _mm_set1_pd
                       (A4_1))), _mm_mul_pd(_mm_set_pd(A2[tmp_a + 3], A2[tmp_b +
            3]), _mm_set1_pd(A4_2))));
          A6[b_i + tmp_b] = tmp_9[0];
          A6[b_i + tmp_a] = tmp_9[1];
        }
      }

      /* Start for MATLABSystem: '<S1>/solver' */
      d6 = rt_powd_snf(longitudinal_mpc_norm(A6), 0.16666666666666666);
      eta1 = std::fmax(rt_powd_snf(longitudinal_mpc_norm(A4), 0.25), d6);
      guard1 = false;
      guard2 = false;
      guard3 = false;
      guard4 = false;
      if (eta1 <= 0.01495585217958292) {
        /* Start for MATLABSystem: '<S1>/solver' */
        for (b_j = 0; b_j <= 14; b_j += 2) {
          tmp[0] = std::abs(A[b_j]);
          tmp[1] = std::abs(A[b_j + 1]);
          tmp_5 = _mm_loadu_pd(&tmp[0]);
          _mm_storeu_pd(&A4_0[b_j], _mm_mul_pd(_mm_set1_pd(0.19285012468241128),
            tmp_5));
        }

        longitudinal_mpc_mpower(A4_0, 7.0, tmp_c);
        if (std::fmax(std::ceil(longitudinal_mpc_log2(longitudinal_mpc_norm
               (tmp_c) / longitudinal_mpc_norm(A) * 2.0 / 2.2204460492503131E-16)
              / 6.0), 0.0) == 0.0) {
          eint = 3;
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }

      if (guard4) {
        if (eta1 <= 0.253939833006323) {
          /* Start for MATLABSystem: '<S1>/solver' */
          for (b_j = 0; b_j <= 14; b_j += 2) {
            tmp_0[0] = std::abs(A[b_j]);
            tmp_0[1] = std::abs(A[b_j + 1]);
            tmp_5 = _mm_loadu_pd(&tmp_0[0]);
            _mm_storeu_pd(&A4_0[b_j], _mm_mul_pd(_mm_set1_pd(0.12321872304378752),
              tmp_5));
          }

          longitudinal_mpc_mpower(A4_0, 11.0, tmp_c);
          if (std::fmax(std::ceil(longitudinal_mpc_log2(longitudinal_mpc_norm
                 (tmp_c) / longitudinal_mpc_norm(A) * 2.0 /
                 2.2204460492503131E-16) / 10.0), 0.0) == 0.0) {
            eint = 5;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }
      }

      if (guard3) {
        /* Start for MATLABSystem: '<S1>/solver' */
        longitudinal_mpc_mpower(A4, 2.0, tmp_c);
        eta1 = rt_powd_snf(longitudinal_mpc_norm(tmp_c), 0.125);
        d6 = std::fmax(d6, eta1);
        if (d6 <= 0.95041789961629319) {
          /* Start for MATLABSystem: '<S1>/solver' */
          for (b_j = 0; b_j <= 14; b_j += 2) {
            tmp_1[0] = std::abs(A[b_j]);
            tmp_1[1] = std::abs(A[b_j + 1]);
            tmp_5 = _mm_loadu_pd(&tmp_1[0]);
            _mm_storeu_pd(&A4_0[b_j], _mm_mul_pd(_mm_set1_pd
              (0.090475336558796943), tmp_5));
          }

          longitudinal_mpc_mpower(A4_0, 15.0, tmp_c);
          if (std::fmax(std::ceil(longitudinal_mpc_log2(longitudinal_mpc_norm
                 (tmp_c) / longitudinal_mpc_norm(A) * 2.0 /
                 2.2204460492503131E-16) / 14.0), 0.0) == 0.0) {
            eint = 7;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
      }

      if (guard2) {
        if (d6 <= 2.097847961257068) {
          /* Start for MATLABSystem: '<S1>/solver' */
          for (b_j = 0; b_j <= 14; b_j += 2) {
            tmp_2[0] = std::abs(A[b_j]);
            tmp_2[1] = std::abs(A[b_j + 1]);
            tmp_5 = _mm_loadu_pd(&tmp_2[0]);
            _mm_storeu_pd(&A4_0[b_j], _mm_mul_pd(_mm_set1_pd
              (0.071467735648795785), tmp_5));
          }

          longitudinal_mpc_mpower(A4_0, 19.0, tmp_c);
          if (std::fmax(std::ceil(longitudinal_mpc_log2(longitudinal_mpc_norm
                 (tmp_c) / longitudinal_mpc_norm(A) * 2.0 /
                 2.2204460492503131E-16) / 18.0), 0.0) == 0.0) {
            eint = 9;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }

      if (guard1) {
        /* Start for MATLABSystem: '<S1>/solver' */
        for (b_i = 0; b_i < 4; b_i++) {
          b_j = b_i << 2;
          exptj = A6[b_j + 1];
          A4_1 = A6[b_j];
          A4_2 = A6[b_j + 2];
          A6_0 = A6[b_j + 3];
          for (i = 0; i <= 2; i += 2) {
            tmp_5 = _mm_loadu_pd(&A4[i + 4]);
            tmp_6 = _mm_loadu_pd(&A4[i]);
            tmp_7 = _mm_loadu_pd(&A4[i + 8]);
            tmp_8 = _mm_loadu_pd(&A4[i + 12]);
            _mm_storeu_pd(&A4_0[i + b_j], _mm_add_pd(_mm_add_pd(_mm_add_pd
              (_mm_mul_pd(_mm_set1_pd(exptj), tmp_5), _mm_mul_pd(_mm_set1_pd
              (A4_1), tmp_6)), _mm_mul_pd(_mm_set1_pd(A4_2), tmp_7)), _mm_mul_pd
              (_mm_set1_pd(A6_0), tmp_8)));
          }
        }

        exptj = std::fmax(std::ceil(longitudinal_mpc_log2(std::fmin(d6, std::
          fmax(eta1, rt_powd_snf(longitudinal_mpc_norm(A4_0), 0.1))) /
          5.3719203511481517)), 0.0);
        d6 = rt_powd_snf(2.0, exptj);
        for (b_j = 0; b_j <= 14; b_j += 2) {
          tmp_5 = _mm_loadu_pd(&A[b_j]);
          tmp_5 = _mm_div_pd(tmp_5, _mm_set1_pd(d6));
          _mm_storeu_pd(&T[b_j], tmp_5);
          _mm_storeu_pd(&tmp_4[0], tmp_5);
          tmp_3[0] = std::abs(tmp_4[0]);
          tmp_3[1] = std::abs(tmp_4[1]);
          tmp_5 = _mm_loadu_pd(&tmp_3[0]);
          _mm_storeu_pd(&A4_0[b_j], _mm_mul_pd(_mm_set1_pd(0.05031554467093536),
            tmp_5));
        }

        longitudinal_mpc_mpower(A4_0, 27.0, tmp_c);
        exptj += std::fmax(std::ceil(longitudinal_mpc_log2(longitudinal_mpc_norm
          (tmp_c) / longitudinal_mpc_norm(T) * 2.0 / 2.2204460492503131E-16) /
          26.0), 0.0);
        if (std::isinf(exptj)) {
          d6 = longitudinal_mpc_norm(A) / 5.3719203511481517;
          if ((!std::isinf(d6)) && (!std::isnan(d6))) {
            d6 = std::frexp(d6, &eint);
            exptj = eint;
          } else {
            exptj = 0.0;
          }

          if (d6 == 0.5) {
            exptj--;
          }
        }

        eint = 13;
      }

      /* Start for MATLABSystem: '<S1>/solver' */
      if (exptj != 0.0) {
        d6 = rt_powd_snf(2.0, exptj);
        for (b_i = 0; b_i <= 14; b_i += 2) {
          tmp_5 = _mm_loadu_pd(&A[b_i]);
          _mm_storeu_pd(&A[b_i], _mm_div_pd(tmp_5, _mm_set1_pd(d6)));
        }

        d6 = rt_powd_snf(2.0, 2.0 * exptj);
        for (b_i = 0; b_i <= 14; b_i += 2) {
          tmp_5 = _mm_loadu_pd(&A2[b_i]);
          _mm_storeu_pd(&A2[b_i], _mm_div_pd(tmp_5, _mm_set1_pd(d6)));
        }

        d6 = rt_powd_snf(2.0, 4.0 * exptj);
        for (b_i = 0; b_i <= 14; b_i += 2) {
          tmp_5 = _mm_loadu_pd(&A4[b_i]);
          _mm_storeu_pd(&A4[b_i], _mm_div_pd(tmp_5, _mm_set1_pd(d6)));
        }

        d6 = rt_powd_snf(2.0, 6.0 * exptj);
        for (b_i = 0; b_i <= 14; b_i += 2) {
          tmp_5 = _mm_loadu_pd(&A6[b_i]);
          _mm_storeu_pd(&A6[b_i], _mm_div_pd(tmp_5, _mm_set1_pd(d6)));
        }
      }

      if (recomputeDiags) {
        blockFormat[0] = 0;
        blockFormat[1] = 0;
        blockFormat[2] = 0;
        b_j = 0;
        while (b_j + 1 < 3) {
          d6 = A[((b_j << 2) + b_j) + 1];
          if (d6 != 0.0) {
            blockFormat[b_j] = 2;
            blockFormat[b_j + 1] = 0;
            b_j += 2;
          } else if ((d6 == 0.0) && (A[(((b_j + 1) << 2) + b_j) + 2] == 0.0)) {
            blockFormat[b_j] = 1;
            b_j++;
          } else {
            blockFormat[b_j] = 0;
            b_j++;
          }
        }

        /* Start for MATLABSystem: '<S1>/solver' */
        if (A[11] != 0.0) {
          blockFormat[2] = 2;
        } else if ((blockFormat[1] == 0) || (blockFormat[1] == 1)) {
          blockFormat[2] = 1;
        }
      }

      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal__padeApproximation(A, A2, A4, A6, eint, F);
      if (recomputeDiags) {
        /* Start for MATLABSystem: '<S1>/solver' */
        longitudinal_recomputeBlockDiag(A, F, blockFormat);
      }

      /* Start for MATLABSystem: '<S1>/solver' */
      eint = static_cast<int32_T>(exptj) - 1;
      for (b_j = 0; b_j <= eint; b_j++) {
        for (b_i = 0; b_i < 4; b_i++) {
          for (i = 0; i <= 2; i += 2) {
            /* Start for MATLABSystem: '<S1>/solver' */
            tmp_a = (i + 1) << 2;
            tmp_b = i << 2;
            _mm_storeu_pd(&tmp_9[0], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
              (_mm_set_pd(F[tmp_a + 1], F[tmp_b + 1]), _mm_set1_pd(F[b_i + 4])),
              _mm_mul_pd(_mm_set_pd(F[tmp_a], F[tmp_b]), _mm_set1_pd(F[b_i]))),
              _mm_mul_pd(_mm_set_pd(F[tmp_a + 2], F[tmp_b + 2]), _mm_set1_pd
                         (F[b_i + 8]))), _mm_mul_pd(_mm_set_pd(F[tmp_a + 3],
              F[tmp_b + 3]), _mm_set1_pd(F[b_i + 12]))));
            A4[b_i + tmp_b] = tmp_9[0];
            A4[b_i + tmp_a] = tmp_9[1];
          }
        }

        std::memcpy(&F[0], &A4[0], sizeof(real_T) << 4U);
        if (recomputeDiags) {
          for (b_i = 0; b_i <= 14; b_i += 2) {
            /* Start for MATLABSystem: '<S1>/solver' */
            tmp_5 = _mm_loadu_pd(&A[b_i]);
            _mm_storeu_pd(&A[b_i], _mm_mul_pd(_mm_set1_pd(2.0), tmp_5));
          }

          /* Start for MATLABSystem: '<S1>/solver' */
          longitudinal_recomputeBlockDiag(A, F, blockFormat);
        }
      }
    }
  }
}

void longitudinal_mpc::longitudina_PCCMPC_setObjective(solver_longitudinal_mpc_T
  *b_this)
{
  real_T Pold[16];
  real_T b_tmp[16];
  real_T b_tmp_1[16];
  real_T q[16];
  real_T y[16];
  real_T b_tmp_0[4];
  real_T v[4];
  real_T v_0[4];
  real_T tmp_3[2];
  int32_T i;
  boolean_T b_this_0;
  static const int32_T v_1[5]{ 10000, 100000, 100000, 10000000, 100000 };

  static const int8_T tmp_5[5]{ 0, 0, 0, 1, 1 };

  static const int8_T tmp_6[4]{ 0, 0, 0, 1 };

  static const real_T tmp_7[16]{ 1.0, 0.5, 0.09196986029286057, 0.0, 0.0, 1.0,
    0.31606027941427883, 0.0, 0.0, 0.0, 0.36787944117144233, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const real_T Bd[4]{ 0.033030139707139416, 0.18393972058572114,
    0.63212055882855767, 1.0 };

  static const real_T Ad[16]{ 1.0, 0.0, 0.0, 0.0, 0.5, 1.0, 0.0, 0.0,
    0.09196986029286057, 0.31606027941427883, 0.36787944117144233, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  /*  setModel */
  /*  Handle input arguments */
  /*  Cost matrices */
  std::memset(&q[0], 0, sizeof(real_T) << 4U);
  q[0] = b_this->qh;
  q[5] = b_this->qv;
  q[10] = b_this->qu;
  q[15] = b_this->qdu;
  b_this->R = b_this->qu;

  /*  Set terminal objective weight */
  if (b_this->dual_mode > 2.2204460492503131E-16) {
    real_T b_this_1;
    real_T b_this_2;
    real_T b_this_3;
    real_T b_this_4;
    real_T b_tmp_2;
    real_T s;
    int32_T b_tmp_tmp;
    int32_T iter;
    int32_T tmp_4;
    int32_T y_tmp;

    /* Start for MATLABSystem: '<S1>/solver' */
    b_tmp_2 = 0.0;
    for (i = 0; i < 4; i++) {
      iter = i << 2;
      b_this_1 = b_this->C[iter + 1];
      b_this_2 = b_this->C[iter];
      b_this_3 = b_this->C[iter + 2];
      b_this_4 = b_this->C[iter + 3];
      for (b_tmp_tmp = 0; b_tmp_tmp <= 2; b_tmp_tmp += 2) {
        y_tmp = (b_tmp_tmp + 1) << 2;
        tmp_4 = b_tmp_tmp << 2;
        _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
          (_mm_set1_pd(b_this_1), _mm_set_pd(q[y_tmp + 1], q[tmp_4 + 1])),
          _mm_mul_pd(_mm_set1_pd(b_this_2), _mm_set_pd(q[y_tmp], q[tmp_4]))),
          _mm_mul_pd(_mm_set1_pd(b_this_3), _mm_set_pd(q[y_tmp + 2], q[tmp_4 + 2]))),
          _mm_mul_pd(_mm_set1_pd(b_this_4), _mm_set_pd(q[y_tmp + 3], q[tmp_4 + 3]))));
        Pold[i + tmp_4] = tmp_3[0];
        Pold[i + y_tmp] = tmp_3[1];
      }

      b_this_1 = Pold[i + 4];
      b_this_2 = Pold[i];
      b_this_3 = Pold[i + 8];
      b_this_4 = Pold[i + 12];
      s = 0.0;
      for (b_tmp_tmp = 0; b_tmp_tmp < 4; b_tmp_tmp++) {
        y_tmp = b_tmp_tmp << 2;
        y[i + y_tmp] = ((b_this->C[y_tmp + 1] * b_this_1 + b_this->C[y_tmp] *
                         b_this_2) + b_this->C[y_tmp + 2] * b_this_3) +
          b_this->C[y_tmp + 3] * b_this_4;
        s += q[iter + b_tmp_tmp] * static_cast<real_T>(tmp_6[b_tmp_tmp]);
      }

      b_tmp_2 += s * static_cast<real_T>(tmp_6[i]);
    }

    b_this_1 = b_this->R + b_tmp_2;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %% Tyler Ard                %%% */
    /* %% Argonne National Lab     %%% */
    /* %% Vehicle Mobility Systems %%% */
    /* %% tard(at)anl.gov          %%% */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /*  See also https://math.stackexchange.com/questions/3636650/how-to-solve-lqr-if-regulating-outputs-instead-of-states */
    /*  SOLVEDLQR Computes infinite-horizon lqr solution and gain matrix */
    /*  */
    /*  Args: */
    /*    Ad (matrix): discrete state update matrix */
    /*    Bd (matrix): discrete control update matrix */
    /*    Q (matrix): state weighting matrix */
    /*    R (matrix): control weighting matrix */
    /*    N (matrix): coupling weighting matrix between state and control */
    /*    e.g. cost 2 xk' N uk */
    /*        The default is zero. */
    /*  */
    /*  Returns: */
    /*    P (matrix): discrete time algebraic ricatti equation solution matrix */
    /*    F (matrix): optimal input gain matrix s.t. u_k = -F_k x_k */
    /*  */
    /*  See also: https://en.wikipedia.org/wiki/Linear%E2%80%93quadratic_regulator#Infinite-horizon.2C_discrete-time_LQR */
    /*  Check inputs */
    /*  Setup */
    /*  Time horizon */
    std::memcpy(&b_this->S[0], &y[0], sizeof(real_T) << 4U);

    /*  Terminal condition P_Hp == Q_Hp */
    /*  Update by iterating the solution backwards in time from stages Hp, Hp-1, ... */
    iter = 1;

    /*  Maximum allowed ricatti update equations */
    for (i = 0; i < 1000; i++) {
      longitudinal_mpc_B.e[i] = (rtInf);
    }

    while ((longitudinal_mpc_B.e[iter - 1] > 1.0E-6) && (iter < 1000)) {
      __m128d tmp_0;
      boolean_T exitg1;

      /*  Update P and F */
      std::memcpy(&Pold[0], &b_this->S[0], sizeof(real_T) << 4U);

      /* %% Internal functions */
      /*  ITERATEF Return Fk given Pk+1 and discrete lqr matrices */
      /*  inv(A)*b */
      /*  ITERATEP Returns Pk-1 given Pk and discrete lqr matrices */
      b_this_2 = 0.0;
      for (i = 0; i < 4; i++) {
        real_T tmp;
        b_this_3 = 0.0;
        b_tmp_2 = tmp_7[i + 4];
        s = tmp_7[i];
        b_this_4 = tmp_7[i + 8];
        tmp = tmp_7[i + 12];
        for (b_tmp_tmp = 0; b_tmp_tmp < 4; b_tmp_tmp++) {
          b_this_3 += b_this->S[(i << 2) + b_tmp_tmp] * Bd[b_tmp_tmp];
          y_tmp = b_tmp_tmp << 2;
          b_tmp[i + y_tmp] = ((b_this->S[y_tmp + 1] * b_tmp_2 + b_this->S[y_tmp]
                               * s) + b_this->S[y_tmp + 2] * b_this_4) +
            b_this->S[y_tmp + 3] * tmp;
        }

        v[i] = b_this_3;
        b_this_2 += b_this_3 * Bd[i];
      }

      b_this_2 += b_this_1;
      for (i = 0; i < 4; i++) {
        b_tmp_2 = 0.0;
        s = 0.0;
        for (b_tmp_tmp = 0; b_tmp_tmp < 4; b_tmp_tmp++) {
          y_tmp = b_tmp_tmp << 2;
          tmp_4 = y_tmp + i;
          _mm_storeu_pd(&tmp_3[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(Ad[(i << 2)
            + b_tmp_tmp], b_tmp[tmp_4]), _mm_set_pd(v[b_tmp_tmp], Bd[b_tmp_tmp])),
            _mm_set_pd(s, b_tmp_2)));
          b_tmp_2 = tmp_3[0];
          s = tmp_3[1];
          b_tmp_1[tmp_4] = ((Ad[y_tmp + 1] * b_tmp[i + 4] + Ad[y_tmp] * b_tmp[i])
                            + Ad[y_tmp + 2] * b_tmp[i + 8]) + Ad[y_tmp + 3] *
            b_tmp[i + 12];
        }

        b_tmp_0[i] = b_tmp_2 / b_this_2;
        v_0[i] = s;
      }

      b_tmp_2 = b_tmp_0[0];
      s = b_tmp_0[1];
      b_this_2 = b_tmp_0[2];
      b_this_3 = b_tmp_0[3];
      for (i = 0; i <= 2; i += 2) {
        tmp_0 = _mm_mul_pd(_mm_set1_pd(b_tmp_2), _mm_loadu_pd(&v_0[i]));
        _mm_storeu_pd(&tmp_3[0], tmp_0);
        y_tmp = i << 2;
        b_tmp[y_tmp] = tmp_3[0];
        b_tmp_tmp = (i + 1) << 2;
        b_tmp[b_tmp_tmp] = tmp_3[1];
        tmp_0 = _mm_mul_pd(_mm_set1_pd(s), _mm_loadu_pd(&v_0[i]));
        _mm_storeu_pd(&tmp_3[0], tmp_0);
        b_tmp[y_tmp + 1] = tmp_3[0];
        b_tmp[b_tmp_tmp + 1] = tmp_3[1];
        tmp_0 = _mm_mul_pd(_mm_set1_pd(b_this_2), _mm_loadu_pd(&v_0[i]));
        _mm_storeu_pd(&tmp_3[0], tmp_0);
        b_tmp[y_tmp + 2] = tmp_3[0];
        b_tmp[b_tmp_tmp + 2] = tmp_3[1];
        tmp_0 = _mm_mul_pd(_mm_set1_pd(b_this_3), _mm_loadu_pd(&v_0[i]));
        _mm_storeu_pd(&tmp_3[0], tmp_0);
        b_tmp[y_tmp + 3] = tmp_3[0];
        b_tmp[b_tmp_tmp + 3] = tmp_3[1];
      }

      /*  Iterate */
      iter++;
      for (i = 0; i <= 14; i += 2) {
        __m128d tmp_1;
        __m128d tmp_2;
        tmp_0 = _mm_loadu_pd(&b_tmp_1[i]);
        tmp_1 = _mm_loadu_pd(&b_tmp[i]);
        tmp_2 = _mm_loadu_pd(&y[i]);
        tmp_0 = _mm_add_pd(_mm_sub_pd(tmp_0, tmp_1), tmp_2);
        _mm_storeu_pd(&b_this->S[i], tmp_0);
        tmp_1 = _mm_loadu_pd(&Pold[i]);
        _mm_storeu_pd(&Pold[i], _mm_sub_pd(tmp_0, tmp_1));
      }

      b_tmp_2 = 0.0;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 4)) {
        s = ((std::abs(Pold[i + 4]) + std::abs(Pold[i])) + std::abs(Pold[i + 8]))
          + std::abs(Pold[i + 12]);
        if (std::isnan(s)) {
          b_tmp_2 = (rtNaN);
          exitg1 = true;
        } else {
          if (s > b_tmp_2) {
            b_tmp_2 = s;
          }

          i++;
        }
      }

      longitudinal_mpc_B.e[iter - 1] = b_tmp_2;
    }

    /*  Check quality */
    /*  Terminal output weighting matrix */
  } else {
    for (i = 0; i <= 14; i += 2) {
      __m128d tmp_0;
      tmp_0 = _mm_loadu_pd(&q[i]);
      _mm_storeu_pd(&b_this->S[i], _mm_mul_pd(_mm_set1_pd(10.0), tmp_0));
    }

    /*  Terminal output weighting matrix */
  }

  /*  Choose if in-horizon objective */
  b_this_0 = (b_this->term_tracking_only > 2.2204460492503131E-16);
  for (i = 0; i < 16; i++) {
    if (b_this_0) {
      b_this->Q[i] = 0.0 * q[i];
    } else {
      b_this->Q[i] = q[i];
    }
  }

  /*  Slack variables quadratic and linear inf norm */
  std::memset(&b_this->eps_quad[0], 0, 25U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this->eps_quad[i + 5 * i] = v_1[i];
    b_this->eps_inf[i] = tmp_5[i];
  }
}

void longitudinal_mpc::longit_PCCMPC_setRecursiveModel(solver_longitudinal_mpc_T
  *b_this)
{
  __m128d tmp_0;
  __m128d tmp_1;
  real_T PhiP[512];
  real_T PhiP_data[512];
  real_T PhiP_data_0[496];
  real_T tmp[16];
  real_T tmp_4[2];
  real_T b_this_0;
  real_T b_this_1;
  real_T b_this_2;
  real_T bkj;
  int32_T b_k;
  int32_T b_this_tmp;
  int32_T d;
  int32_T e;
  int32_T k;
  int32_T kidx;
  int32_T loop_ub;
  int32_T y_tmp;
  int16_T kidx_0[2];
  int8_T A;
  static const real_T tmp_5[16]{ 1.0, 0.0, 0.0, 0.0, 0.5, 1.0, 0.0, 0.0,
    0.09196986029286057, 0.31606027941427883, 0.36787944117144233, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const int8_T A_0[1024]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const int8_T A_1[961]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1 };

  /* %% Build MPC matrices */
  /*  Control model with parametric disturbances */
  std::memset(&PhiP[0], 0, sizeof(real_T) << 9U);
  PhiP[0] = 1.0;
  PhiP[129] = 1.0;
  PhiP[258] = 1.0;
  PhiP[387] = 1.0;
  for (b_k = 0; b_k < 31; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    kidx = (b_k + 1) << 2;
    b_this_tmp = static_cast<int32_T>(((static_cast<real_T>(b_k) + 2.0) - 2.0) *
      4.0 + 1.0);
    if (b_this_tmp > kidx) {
      e = 0;
      d = 0;
    } else {
      e = b_this_tmp - 1;
      d = kidx;
    }

    kidx = (b_k + 2) << 2;
    b_this_tmp = static_cast<int32_T>(((static_cast<real_T>(b_k) + 2.0) - 1.0) *
      4.0 + 1.0);
    if (b_this_tmp > kidx) {
      k = 0;
      kidx = 0;
    } else {
      k = b_this_tmp - 1;
    }

    loop_ub = d - e;
    for (b_this_tmp = 0; b_this_tmp < 4; b_this_tmp++) {
      for (y_tmp = 0; y_tmp < loop_ub; y_tmp++) {
        PhiP_data_0[y_tmp + loop_ub * b_this_tmp] = PhiP[(e + y_tmp) +
          (b_this_tmp << 7)];
      }
    }

    for (b_this_tmp = 0; b_this_tmp < 4; b_this_tmp++) {
      bkj = tmp_5[b_this_tmp + 4];
      b_this_0 = tmp_5[b_this_tmp];
      b_this_1 = tmp_5[b_this_tmp + 8];
      b_this_2 = tmp_5[b_this_tmp + 12];
      for (y_tmp = 0; y_tmp <= 2; y_tmp += 2) {
        e = (y_tmp + 1) << 2;
        d = y_tmp << 2;
        _mm_storeu_pd(&tmp_4[0], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
          (_mm_set_pd(PhiP_data_0[e + 1], PhiP_data_0[d + 1]), _mm_set1_pd(bkj)),
          _mm_mul_pd(_mm_set_pd(PhiP_data_0[e], PhiP_data_0[d]), _mm_set1_pd
                     (b_this_0))), _mm_mul_pd(_mm_set_pd(PhiP_data_0[e + 2],
          PhiP_data_0[d + 2]), _mm_set1_pd(b_this_1))), _mm_mul_pd(_mm_set_pd
          (PhiP_data_0[e + 3], PhiP_data_0[d + 3]), _mm_set1_pd(b_this_2))));
        tmp[b_this_tmp + d] = tmp_4[0];
        tmp[b_this_tmp + e] = tmp_4[1];
      }
    }

    int16_T kidx_1;
    kidx_1 = static_cast<int16_T>(kidx - k);
    kidx_0[0] = kidx_1;
    loop_ub = kidx_1;
    for (b_this_tmp = 0; b_this_tmp < 4; b_this_tmp++) {
      for (y_tmp = 0; y_tmp < loop_ub; y_tmp++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        PhiP[(k + y_tmp) + (b_this_tmp << 7)] = tmp[kidx_0[0] * b_this_tmp +
          y_tmp];
      }
    }
  }

  std::memset(&b_this->Omega[0], 0, sizeof(real_T) << 14U);
  for (b_k = 0; b_k < 128; b_k++) {
    b_this->Omega[b_k + (b_k << 7)] = 1.0;
  }

  for (k = 0; k < 31; k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_k = (k << 2) + 1;
    kidx = (k + 1) << 2;
    b_this_tmp = static_cast<int32_T>(((static_cast<real_T>(k) + 1.0) - 1.0) *
      4.0 + 1.0);
    if (b_this_tmp > kidx) {
      e = 0;
      d = 0;
    } else {
      e = b_this_tmp - 1;
      d = kidx;
    }

    loop_ub = (32 - k) << 2;
    for (b_this_tmp = 0; b_this_tmp < 4; b_this_tmp++) {
      for (y_tmp = 0; y_tmp < loop_ub; y_tmp++) {
        PhiP_data[y_tmp + loop_ub * b_this_tmp] = PhiP[(b_this_tmp << 7) + y_tmp];
      }
    }

    kidx_0[0] = static_cast<int16_T>(129 - b_k);
    kidx_0[1] = static_cast<int16_T>(d - e);
    loop_ub = kidx_0[1];
    for (b_this_tmp = 0; b_this_tmp < loop_ub; b_this_tmp++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      kidx = 129 - b_k;
      for (y_tmp = 0; y_tmp < kidx; y_tmp++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        b_this->Omega[((b_k + y_tmp) + ((e + b_this_tmp) << 7)) - 1] =
          PhiP_data[kidx_0[0] * b_this_tmp + y_tmp];
      }
    }
  }

  for (b_this_tmp = 0; b_this_tmp < 4; b_this_tmp++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    y_tmp = b_this_tmp << 2;
    bkj = tmp_5[y_tmp + 1];
    b_this_0 = tmp_5[y_tmp];
    b_this_1 = tmp_5[y_tmp + 2];
    b_this_2 = tmp_5[y_tmp + 3];
    for (y_tmp = 0; y_tmp <= 126; y_tmp += 2) {
      __m128d tmp_2;
      __m128d tmp_3;

      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_0 = _mm_loadu_pd(&PhiP[y_tmp + 128]);
      tmp_1 = _mm_loadu_pd(&PhiP[y_tmp]);
      tmp_2 = _mm_loadu_pd(&PhiP[y_tmp + 256]);
      tmp_3 = _mm_loadu_pd(&PhiP[y_tmp + 384]);
      _mm_storeu_pd(&b_this->Phi[y_tmp + (b_this_tmp << 7)], _mm_add_pd
                    (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(bkj), tmp_0),
        _mm_mul_pd(_mm_set1_pd(b_this_0), tmp_1)), _mm_mul_pd(_mm_set1_pd
        (b_this_1), tmp_2)), _mm_mul_pd(_mm_set1_pd(b_this_2), tmp_3)));
    }
  }

  kidx = -1;
  for (k = 0; k < 32; k++) {
    for (b_k = 0; b_k < 32; b_k++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      A = A_0[(k << 5) + b_k];
      longitudinal_mpc_B.y_f[kidx + 1] = static_cast<real_T>(A) *
        0.033030139707139416;
      longitudinal_mpc_B.y_f[kidx + 2] = static_cast<real_T>(A) *
        0.18393972058572114;
      longitudinal_mpc_B.y_f[kidx + 3] = static_cast<real_T>(A) *
        0.63212055882855767;
      longitudinal_mpc_B.y_f[kidx + 4] = A;
      kidx += 4;
    }
  }

  for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 128; y_tmp++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      e = b_this_tmp << 7;
      d = y_tmp + e;
      b_this->Gamma[d] = 0.0;
      for (b_k = 0; b_k < 128; b_k++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        b_this->Gamma[d] += b_this->Omega[(b_k << 7) + y_tmp] *
          longitudinal_mpc_B.y_f[e + b_k];
      }
    }
  }

  /*  Affine Disturbances */
  std::memset(&b_this->Omega[0], 0, sizeof(real_T) << 14U);
  for (b_k = 0; b_k < 128; b_k++) {
    b_this->Omega[b_k + (b_k << 7)] = 1.0;
  }

  for (k = 0; k < 31; k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_k = (k << 2) + 1;
    kidx = (k + 1) << 2;
    b_this_tmp = static_cast<int32_T>(((static_cast<real_T>(k) + 1.0) - 1.0) *
      4.0 + 1.0);
    if (b_this_tmp > kidx) {
      e = 0;
      d = 0;
    } else {
      e = b_this_tmp - 1;
      d = kidx;
    }

    loop_ub = (32 - k) << 2;
    for (b_this_tmp = 0; b_this_tmp < 4; b_this_tmp++) {
      for (y_tmp = 0; y_tmp < loop_ub; y_tmp++) {
        PhiP_data[y_tmp + loop_ub * b_this_tmp] = PhiP[(b_this_tmp << 7) + y_tmp];
      }
    }

    kidx_0[0] = static_cast<int16_T>(129 - b_k);
    kidx_0[1] = static_cast<int16_T>(d - e);
    loop_ub = kidx_0[1];
    for (b_this_tmp = 0; b_this_tmp < loop_ub; b_this_tmp++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      kidx = 129 - b_k;
      for (y_tmp = 0; y_tmp < kidx; y_tmp++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        b_this->Omega[((b_k + y_tmp) + ((e + b_this_tmp) << 7)) - 1] =
          PhiP_data[kidx_0[0] * b_this_tmp + y_tmp];
      }
    }
  }

  for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 128; y_tmp++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      e = (b_this_tmp << 7) + y_tmp;
      b_this->GammaWa[e] = 0.0;
      for (d = 0; d < 128; d++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        b_this->GammaWa[e] += b_this->Omega[(d << 7) + y_tmp] * 0.0;
      }
    }
  }

  /*  Observables */
  kidx = -1;
  for (k = 0; k < 32; k++) {
    for (d = 0; d < 4; d++) {
      for (b_k = 0; b_k < 32; b_k++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        tmp_0 = _mm_set1_pd(static_cast<real_T>(A_0[(k << 5) + b_k]));
        b_this_tmp = d << 2;
        tmp_1 = _mm_mul_pd(tmp_0, _mm_loadu_pd(&b_this->C[b_this_tmp]));
        _mm_storeu_pd(&b_this->Omega[kidx + 1], tmp_1);

        /* Start for MATLABSystem: '<S1>/solver' */
        tmp_0 = _mm_mul_pd(tmp_0, _mm_loadu_pd(&b_this->C[b_this_tmp + 2]));
        _mm_storeu_pd(&b_this->Omega[kidx + 3], tmp_0);
        kidx += 4;
      }
    }
  }

  std::memcpy(&b_this->GammaC[0], &b_this->Omega[0], sizeof(real_T) << 14U);
  kidx = -1;
  for (k = 0; k < 32; k++) {
    for (b_k = 0; b_k < 32; b_k++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal_mpc_B.Fp[kidx + 1] = 0.0;
      longitudinal_mpc_B.Fp[kidx + 2] = 0.0;
      longitudinal_mpc_B.Fp[kidx + 3] = 0.0;
      longitudinal_mpc_B.Fp[kidx + 4] = A_0[(k << 5) + b_k];
      kidx += 4;
    }
  }

  for (b_this_tmp = 0; b_this_tmp < 4096; b_this_tmp++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this->GammaD[b_this_tmp] = longitudinal_mpc_B.Fp[b_this_tmp];
    b_this->GammaVa[b_this_tmp] = 0.0;
  }

  /* %% Block form of cost function */
  kidx = -1;
  for (k = 0; k < 31; k++) {
    for (d = 0; d < 4; d++) {
      b_this_tmp = d << 2;
      bkj = b_this->Q[b_this_tmp];

      /* Start for MATLABSystem: '<S1>/solver' */
      b_this_0 = b_this->Q[b_this_tmp + 1];
      b_this_1 = b_this->Q[b_this_tmp + 2];
      b_this_2 = b_this->Q[b_this_tmp + 3];
      for (b_k = 0; b_k < 31; b_k++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        A = A_1[31 * k + b_k];
        longitudinal_mpc_B.K_p[kidx + 1] = static_cast<real_T>(A) * bkj;
        longitudinal_mpc_B.K_p[kidx + 2] = static_cast<real_T>(A) * b_this_0;
        longitudinal_mpc_B.K_p[kidx + 3] = static_cast<real_T>(A) * b_this_1;
        longitudinal_mpc_B.K_p[kidx + 4] = static_cast<real_T>(A) * b_this_2;
        kidx += 4;
      }
    }
  }

  std::memset(&b_this->Omega[0], 0, sizeof(real_T) << 14U);
  for (b_this_tmp = 0; b_this_tmp < 124; b_this_tmp++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&b_this->Omega[b_this_tmp << 7],
                &longitudinal_mpc_B.K_p[b_this_tmp * 124], 124U * sizeof(real_T));
  }

  for (b_this_tmp = 0; b_this_tmp < 4; b_this_tmp++) {
    y_tmp = b_this_tmp << 2;

    /* Start for MATLABSystem: '<S1>/solver' */
    e = (b_this_tmp + 124) << 7;
    b_this->Omega[e + 124] = b_this->S[y_tmp];
    b_this->Omega[e + 125] = b_this->S[y_tmp + 1];
    b_this->Omega[e + 126] = b_this->S[y_tmp + 2];
    b_this->Omega[e + 127] = b_this->S[y_tmp + 3];
  }

  kidx = -1;
  for (k = 0; k < 32; k++) {
    for (b_k = 0; b_k < 32; b_k++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal_mpc_B.H_p[(kidx + b_k) + 1] = static_cast<real_T>(A_0[(k << 5)
        + b_k]) * b_this->R;
    }

    kidx += 32;
  }

  std::memcpy(&b_this->Psi[0], &longitudinal_mpc_B.H_p[0], sizeof(real_T) << 10U);

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  J = 1/2 U' H U + 2 U' (F x(0) - Ty Yr - Tu Ur) */
  std::memcpy(&longitudinal_mpc_B.Fp[0], &b_this->Gamma[0], sizeof(real_T) <<
              12U);
  for (e = 0; e < 128; e++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    kidx = (e << 5) - 1;
    std::memset(&longitudinal_mpc_B.y_f[kidx + 1], 0, sizeof(real_T) << 5U);
    for (b_k = 0; b_k < 128; b_k++) {
      bkj = b_this->GammaC[(b_k << 7) + e];
      for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        y_tmp = (kidx + b_this_tmp) + 1;
        longitudinal_mpc_B.y_f[y_tmp] += longitudinal_mpc_B.Fp[(b_this_tmp << 7)
          + b_k] * bkj;
      }
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&longitudinal_mpc_B.Fp[0], &b_this->GammaD[0], sizeof(real_T) <<
              12U);
  for (b_this_tmp = 0; b_this_tmp < 128; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 32; y_tmp++) {
      longitudinal_mpc_B.H_tmp[y_tmp + (b_this_tmp << 5)] = b_this->GammaD
        [(y_tmp << 7) + b_this_tmp];
    }
  }

  for (b_this_tmp = 0; b_this_tmp <= 4094; b_this_tmp += 2) {
    tmp_0 = _mm_loadu_pd(&longitudinal_mpc_B.H_tmp[b_this_tmp]);
    tmp_1 = _mm_loadu_pd(&longitudinal_mpc_B.y_f[b_this_tmp]);
    _mm_storeu_pd(&longitudinal_mpc_B.y_g[b_this_tmp], _mm_add_pd(_mm_mul_pd
      (_mm_set1_pd(2.0), tmp_0), tmp_1));
  }

  for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 128; y_tmp++) {
      bkj = 0.0;
      for (e = 0; e < 128; e++) {
        bkj += longitudinal_mpc_B.y_g[(e << 5) + b_this_tmp] * b_this->Omega
          [(y_tmp << 7) + e];
      }

      longitudinal_mpc_B.y_f[b_this_tmp + (y_tmp << 5)] = bkj;
    }

    for (y_tmp = 0; y_tmp < 128; y_tmp++) {
      bkj = 0.0;
      for (e = 0; e < 128; e++) {
        bkj += longitudinal_mpc_B.y_f[(e << 5) + b_this_tmp] * b_this->GammaC
          [(y_tmp << 7) + e];
      }

      longitudinal_mpc_B.y_g1[b_this_tmp + (y_tmp << 5)] = bkj;
    }
  }

  for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 128; y_tmp++) {
      b_this_0 = 0.0;
      for (e = 0; e < 128; e++) {
        b_this_0 += longitudinal_mpc_B.H_tmp[(e << 5) + b_this_tmp] *
          b_this->Omega[(y_tmp << 7) + e];
      }

      longitudinal_mpc_B.y_f[b_this_tmp + (y_tmp << 5)] = b_this_0;
    }

    for (y_tmp = 0; y_tmp < 32; y_tmp++) {
      bkj = 0.0;
      b_this_0 = 0.0;
      for (e = 0; e < 128; e++) {
        d = (e << 5) + b_this_tmp;
        b_k = (y_tmp << 7) + e;
        _mm_storeu_pd(&tmp_4[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd
          (longitudinal_mpc_B.y_f[d], longitudinal_mpc_B.y_g1[d]), _mm_set_pd
          (longitudinal_mpc_B.Fp[b_k], b_this->Gamma[b_k])), _mm_set_pd(b_this_0,
          bkj)));
        bkj = tmp_4[0];
        b_this_0 = tmp_4[1];
      }

      b_k = (y_tmp << 5) + b_this_tmp;
      longitudinal_mpc_B.H_tmp_j[b_k] = b_this_0;
      longitudinal_mpc_B.b_this_l[b_k] = b_this->Psi[b_k] + bkj;
    }
  }

  for (b_this_tmp = 0; b_this_tmp <= 1022; b_this_tmp += 2) {
    tmp_0 = _mm_loadu_pd(&longitudinal_mpc_B.b_this_l[b_this_tmp]);
    tmp_1 = _mm_loadu_pd(&longitudinal_mpc_B.H_tmp_j[b_this_tmp]);

    /* Start for MATLABSystem: '<S1>/solver' */
    _mm_storeu_pd(&longitudinal_mpc_B.H_p[b_this_tmp], _mm_mul_pd(_mm_add_pd
      (tmp_0, tmp_1), _mm_set1_pd(2.0)));
  }

  for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
    for (y_tmp = 0; y_tmp <= 30; y_tmp += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      e = (b_this_tmp << 5) + y_tmp;
      tmp_0 = _mm_mul_pd(_mm_add_pd(_mm_loadu_pd(&longitudinal_mpc_B.H_p[e]),
        _mm_set_pd(longitudinal_mpc_B.H_p[((y_tmp + 1) << 5) + b_this_tmp],
                   longitudinal_mpc_B.H_p[(y_tmp << 5) + b_this_tmp])),
                         _mm_set1_pd(0.5));
      _mm_storeu_pd(&b_this->G[e], tmp_0);
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&longitudinal_mpc_B.Fp[0], &b_this->Gamma[0], sizeof(real_T) <<
              12U);
  for (e = 0; e < 128; e++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    kidx = (e << 5) - 1;
    std::memset(&longitudinal_mpc_B.y_f[kidx + 1], 0, sizeof(real_T) << 5U);
    for (b_k = 0; b_k < 128; b_k++) {
      bkj = b_this->GammaC[(b_k << 7) + e];
      for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        y_tmp = (kidx + b_this_tmp) + 1;
        longitudinal_mpc_B.y_f[y_tmp] += longitudinal_mpc_B.Fp[(b_this_tmp << 7)
          + b_k] * bkj;
      }
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  for (b_this_tmp = 0; b_this_tmp <= 4094; b_this_tmp += 2) {
    tmp_0 = _mm_loadu_pd(&longitudinal_mpc_B.y_f[b_this_tmp]);
    tmp_1 = _mm_loadu_pd(&longitudinal_mpc_B.H_tmp[b_this_tmp]);
    _mm_storeu_pd(&longitudinal_mpc_B.y_f[b_this_tmp], _mm_add_pd(tmp_0, tmp_1));
  }

  for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 128; y_tmp++) {
      bkj = 0.0;
      for (e = 0; e < 128; e++) {
        bkj += longitudinal_mpc_B.y_f[(e << 5) + b_this_tmp] * 2.0 *
          b_this->Omega[(y_tmp << 7) + e];
      }

      longitudinal_mpc_B.y_g1[b_this_tmp + (y_tmp << 5)] = bkj;
    }

    for (y_tmp = 0; y_tmp < 128; y_tmp++) {
      bkj = 0.0;
      for (e = 0; e < 128; e++) {
        bkj += longitudinal_mpc_B.y_g1[(e << 5) + b_this_tmp] * b_this->GammaC
          [(y_tmp << 7) + e];
      }

      longitudinal_mpc_B.Fp[b_this_tmp + (y_tmp << 5)] = bkj;
    }

    for (y_tmp = 0; y_tmp < 4; y_tmp++) {
      e = (y_tmp << 5) + b_this_tmp;
      b_this->Fx[e] = 0.0;
      for (d = 0; d < 128; d++) {
        b_this->Fx[e] += longitudinal_mpc_B.Fp[(d << 5) + b_this_tmp] *
          b_this->Phi[(y_tmp << 7) + d];
      }
    }

    for (y_tmp = 0; y_tmp < 32; y_tmp++) {
      e = (y_tmp << 5) + b_this_tmp;
      b_this->Fw[e] = 0.0;
      for (d = 0; d < 128; d++) {
        b_this->Fw[e] += longitudinal_mpc_B.Fp[(d << 5) + b_this_tmp] *
          b_this->GammaWa[(y_tmp << 7) + d];
      }
    }
  }

  std::memcpy(&longitudinal_mpc_B.Fp[0], &b_this->Gamma[0], sizeof(real_T) <<
              12U);
  for (e = 0; e < 128; e++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    kidx = (e << 5) - 1;
    std::memset(&longitudinal_mpc_B.y_f[kidx + 1], 0, sizeof(real_T) << 5U);
    for (b_k = 0; b_k < 128; b_k++) {
      bkj = b_this->GammaC[(b_k << 7) + e];
      for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        y_tmp = (kidx + b_this_tmp) + 1;
        longitudinal_mpc_B.y_f[y_tmp] += longitudinal_mpc_B.Fp[(b_this_tmp << 7)
          + b_k] * bkj;
      }
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  for (b_this_tmp = 0; b_this_tmp <= 4094; b_this_tmp += 2) {
    tmp_0 = _mm_loadu_pd(&longitudinal_mpc_B.y_f[b_this_tmp]);
    tmp_1 = _mm_loadu_pd(&longitudinal_mpc_B.H_tmp[b_this_tmp]);
    _mm_storeu_pd(&longitudinal_mpc_B.y_f[b_this_tmp], _mm_add_pd(tmp_0, tmp_1));
  }

  for (b_this_tmp = 0; b_this_tmp < 128; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 32; y_tmp++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      e = (b_this_tmp << 5) + y_tmp;
      b_this->Ty[e] = 0.0;
      for (d = 0; d < 128; d++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        b_this->Ty[e] += longitudinal_mpc_B.y_f[(d << 5) + y_tmp] * 2.0 *
          b_this->Omega[(b_this_tmp << 7) + d];
      }
    }
  }

  for (b_this_tmp = 0; b_this_tmp <= 1022; b_this_tmp += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_0 = _mm_loadu_pd(&b_this->Psi[b_this_tmp]);
    _mm_storeu_pd(&b_this->Tu[b_this_tmp], _mm_mul_pd(_mm_set1_pd(2.0), tmp_0));
  }

  for (b_this_tmp = 0; b_this_tmp < 32; b_this_tmp++) {
    for (y_tmp = 0; y_tmp < 32; y_tmp++) {
      e = (b_this_tmp << 5) + y_tmp;
      b_this->To[e] = 0.0;
      for (d = 0; d < 128; d++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        b_this->To[e] += b_this->Ty[(d << 5) + y_tmp] * b_this->GammaVa
          [(b_this_tmp << 7) + d];
      }
    }
  }
}

void longitudinal_mpc::longitudinal_mpc_PCCMPC_initMPC(solver_longitudinal_mpc_T
  *b_this)
{
  real_T K[384];
  int32_T i;
  int32_T i1;
  int32_T kidx;
  static const real_T tmp[16]{ 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5,
    -1.0, 0.0, 0.0, 0.0, 1.0, 0.0 };

  static const int8_T tmp_0[5]{ 6, 15, 31, 46, 59 };

  real_T tmp_1[16];
  real_T unusedExpr[16];

  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% INITMPC Perform one-time calculations for controller */
  std::printf("Initializing PCC MPC\n");
  std::fflush(stdout);

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Set control model */
  /* %% Input arguments */
  /* %% Input lag parameters */
  /*  [s] default 0.275; */
  /*  First order lag on acceleration \dot{a} = tauinv (u - a) */
  /*  Error check */
  /*  Make Control Model */
  /*  Continuous time state transition matrice */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %% Tyler Ard                %%% */
  /* %% Argonne National Lab     %%% */
  /* %% Vehicle Mobility Systems %%% */
  /* %% tard(at)anl.gov          %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Get matrix dimensions */
  /*  Make square matrix S = [A, B; 0, 0] */
  /*  Perform zero order hold */
  std::memcpy(&tmp_1[0], &tmp[0], sizeof(real_T) << 4);
  longitudinal_mpc_expm(tmp_1, unusedExpr);

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Extract */
  /*  Add in delta u = u_k - u_{k-1} */
  /*  model_type */
  /*  Outputs y = Cx + Du + V_a */
  b_this->C[0] = 1.0;
  b_this->C[4] = b_this->THref;
  b_this->C[8] = 0.0;
  b_this->C[12] = 0.0;
  b_this->C[1] = 0.0;
  b_this->C[2] = 0.0;
  b_this->C[3] = 0.0;
  b_this->C[5] = 1.0;
  b_this->C[6] = 0.0;
  b_this->C[7] = 0.0;
  b_this->C[9] = 0.0;
  b_this->C[10] = 1.0;
  b_this->C[11] = 0.0;
  b_this->C[13] = 0.0;
  b_this->C[14] = 0.0;
  b_this->C[15] = -1.0;

  /*  Output state matrix */
  /*  y1 = S + V TH */
  /*  y4 = u_k - u_{k-1} */
  /*  Output control matrix */
  /*  State disturbances */
  /*  Affine state disturbance */
  /*  Parametric state disturbance */
  /*  Output Disturbances */
  /*  Affine output disturbance measurement */
  /*  y1 - d0 */
  /*  Set objective weights */
  longitudina_PCCMPC_setObjective(b_this);

  /*  Set dimensions */
  /*  Number of states, number of controls */
  /*  Number of outputs */
  /*  Number of extra affine constraints mx + eu \leq b */
  /*  Number of softened decision variables */
  /*  Number of integer decision variables */
  /*  Variable types char array */
  /*  % Inputs cib */
  /*  % Slacks c */
  /*  % Betas b */
  /* %% MPC model */
  longit_PCCMPC_setRecursiveModel(b_this);

  /* %% Softened constraints */
  std::memset(&b_this->upsi[0], 0, 60U * sizeof(real_T));

  /*  % Standard lower and upper bounds on control */
  /*  % Standard lower and upper bounds on outputs */
  /*  % Affine constraints */
  /* % Integer constraints */
  /*  Select the rows of constraint stages i that are softened */
  /*  Which rows and columns have a softened constraint */
  /*  s max */
  /*  v min */
  /*  v max */
  /*  gap violation */
  /*  following violation */
  /*  Assign slack variable stage matrix */
  for (i1 = 0; i1 < 5; i1++) {
    b_this->upsi[tmp_0[i1]] = 1.0;
  }

  kidx = -1;
  for (i = 0; i < 5; i++) {
    std::memcpy(&b_this->upsn[i * 10], &b_this->upsi[i * 12 + 2], 10U * sizeof
                (real_T));
    for (i1 = 0; i1 < 32; i1++) {
      std::memcpy(&longitudinal_mpc_B.K_m[kidx + 1], &b_this->upsi[i * 12], 12U *
                  sizeof(real_T));
      kidx += 12;
    }
  }

  for (i1 = 0; i1 < 5; i1++) {
    std::memcpy(&b_this->Upsilon[i1 * 394], &longitudinal_mpc_B.K_m[i1 * 384],
                384U * sizeof(real_T));
    std::memcpy(&b_this->Upsilon[i1 * 394 + 384], &b_this->upsn[i1 * 10], 10U *
                sizeof(real_T));
  }

  std::memset(&b_this->UpsilonI[0], 0, 25U * sizeof(real_T));

  /*  Lower bound selection matrix on eps */
  for (i1 = 0; i1 < 5; i1++) {
    b_this->UpsilonI[i1 + 5 * i1] = 1.0;
    b_this->Upsilonb[i1] = 0.0;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Allowed lower bounds on eps variables */
  /*  if nsoft */
  /* %% Integer constraints */
  /*  Standard lower and upper bounds on control */
  /*  Standard lower and upper bounds on outputs */
  /*  Affine constraints */
  /*  Integer constraints */
  std::memset(&b_this->betaci[0], 0, 12U * sizeof(real_T));

  /*  Standard lower and upper bounds on control */
  /*  Standard lower and upper bounds on outputs */
  /*  Affine constraints */
  /*  Integer constraints */
  std::memcpy(&b_this->betacn[0], &b_this->betaci[2], 10U * sizeof(real_T));
  kidx = -1;
  for (i = 0; i < 32; i++) {
    std::memcpy(&K[kidx + 1], &b_this->betaci[0], 12U * sizeof(real_T));
    kidx += 12;
  }

  std::memcpy(&b_this->beta_c[0], &K[0], 384U * sizeof(real_T));
  std::memcpy(&b_this->beta_c[384], &b_this->betacn[0], 10U * sizeof(real_T));

  /*  if nint */
  /* %% Set initial output signals */
  std::memset(&b_this->U[0], 0, sizeof(real_T) << 5U);
  std::memset(&b_this->X[0], 0, sizeof(real_T) << 7U);
  std::memset(&b_this->Y[0], 0, sizeof(real_T) << 7U);
  for (i = 0; i < 5; i++) {
    b_this->E[i] = 0.0;
  }

  b_this->Ref[0] = 0.0;
  b_this->Ref[1] = 0.0;
  b_this->Ref[2] = 0.0;
  b_this->Ref[3] = 0.0;
  b_this->Con = 0.0;

  /*  Set to update */
  b_this->is_needs_update = true;

  /* %% Check Error */
  /*  Model */
  /*  Cost function */
  /*  Softened constraints */
  /*  Decision variables */
  /* %% Report */
  /*  Return */
  b_this->is_init_errored = false;
}

real_T longitudinal_mpc::longitudinal_mpc_eml_erfcore(real_T x)
{
  real_T R;
  real_T absx;
  real_T s;
  real_T y;
  real_T z;
  int32_T b_e;

  /* Start for MATLABSystem: '<S1>/solver' */
  /* ========================== COPYRIGHT NOTICE ============================ */
  /*  The algorithms for calculating ERF(X) and ERFC(X) are derived           */
  /*  from FDLIBM, which has the following notice:                            */
  /*                                                                          */
  /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.       */
  /*                                                                          */
  /*  Developed at SunSoft, a Sun Microsystems, Inc. business.                */
  /*  Permission to use, copy, modify, and distribute this                    */
  /*  software is freely granted, provided that this notice                   */
  /*  is preserved.                                                           */
  /* =============================    END    ================================ */
  absx = std::abs(x);
  if (std::isnan(x)) {
    y = (rtNaN);
  } else if (std::isinf(x)) {
    if (x < 0.0) {
      y = 2.0;
    } else {
      y = 0.0;
    }
  } else if (absx < 0.84375) {
    if (absx < 1.3877787807814457E-17) {
      y = 1.0 - x;
    } else {
      z = x * x;
      if (x < 0.25) {
        y = 1.0 - (((((z * -2.3763016656650163E-5 - 0.0057702702964894416) * z -
                      0.02848174957559851) * z - 0.3250421072470015) * z +
                    0.12837916709551256) / (((((z * -3.9602282787753681E-6 +
          0.00013249473800432164) * z + 0.0050813062818757656) * z +
          0.0650222499887673) * z + 0.39791722395915535) * z + 1.0) * x + x);
      } else {
        y = 0.5 - (((((z * -2.3763016656650163E-5 - 0.0057702702964894416) * z -
                      0.02848174957559851) * z - 0.3250421072470015) * z +
                    0.12837916709551256) / (((((z * -3.9602282787753681E-6 +
          0.00013249473800432164) * z + 0.0050813062818757656) * z +
          0.0650222499887673) * z + 0.39791722395915535) * z + 1.0) * x + (x -
                    0.5));
      }
    }
  } else if (absx < 1.25) {
    if (x >= 0.0) {
      y = 0.15493708848953247 - (((((((absx - 1.0) * -0.0021663755948687908 +
        0.035478304325618236) * (absx - 1.0) - 0.11089469428239668) * (absx -
        1.0) + 0.31834661990116175) * (absx - 1.0) - 0.37220787603570132) *
        (absx - 1.0) + 0.41485611868374833) * (absx - 1.0) -
        0.0023621185607526594) / (((((((absx - 1.0) * 0.011984499846799107 +
        0.013637083912029051) * (absx - 1.0) + 0.12617121980876164) * (absx -
        1.0) + 0.071828654414196266) * (absx - 1.0) + 0.540397917702171) * (absx
        - 1.0) + 0.10642088040084423) * (absx - 1.0) + 1.0);
    } else {
      y = ((((((((absx - 1.0) * -0.0021663755948687908 + 0.035478304325618236) *
                (absx - 1.0) - 0.11089469428239668) * (absx - 1.0) +
               0.31834661990116175) * (absx - 1.0) - 0.37220787603570132) *
             (absx - 1.0) + 0.41485611868374833) * (absx - 1.0) -
            0.0023621185607526594) / (((((((absx - 1.0) * 0.011984499846799107 +
                 0.013637083912029051) * (absx - 1.0) + 0.12617121980876164) *
               (absx - 1.0) + 0.071828654414196266) * (absx - 1.0) +
              0.540397917702171) * (absx - 1.0) + 0.10642088040084423) * (absx -
             1.0) + 1.0) + 0.84506291151046753) + 1.0;
    }
  } else if (x < -6.0) {
    y = 2.0;
  } else if (x >= 28.0) {
    y = 0.0;
  } else {
    s = 1.0 / (absx * absx);
    if (absx < 2.8571414947509766) {
      R = ((((((s * -9.8143293441691455 - 81.2874355063066) * s -
               184.60509290671104) * s - 162.39666946257347) * s -
             62.375332450326006) * s - 10.558626225323291) * s -
           0.69385857270718176) * s - 0.0098649440348471482;
      s = (((((((s * -0.0604244152148581 + 6.5702497703192817) * s +
                108.63500554177944) * s + 429.00814002756783) * s +
              645.38727173326788) * s + 434.56587747522923) * s +
            137.65775414351904) * s + 19.651271667439257) * s + 1.0;
    } else {
      R = (((((s * -483.5191916086514 - 1025.0951316110772) * s -
              637.56644336838963) * s - 160.63638485582192) * s -
            17.757954917754752) * s - 0.799283237680523) * s -
        0.0098649429247001;
      s = ((((((s * -22.440952446585818 + 474.52854120695537) * s +
               2553.0504064331644) * s + 3199.8582195085955) * s +
             1536.729586084437) * s + 325.79251299657392) * s +
           30.338060743482458) * s + 1.0;
    }

    if ((!std::isinf(absx)) && (!std::isnan(absx))) {
      z = std::frexp(absx, &b_e);
    } else {
      z = absx;
      b_e = 0;
    }

    z = std::floor(z * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
      static_cast<real_T>(b_e));
    y = std::exp((z - absx) * (z + absx) + R / s) * std::exp(-z * z - 0.5625) /
      absx;
    if (x < 0.0) {
      y = 2.0 - y;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return y;
}

void longitudinal_mpc::longitudinal_m_binary_expand_op(real_T in1[160], const
  coder::array<real_T, 1U> &in2, const coder::array<real_T, 1U> &in3)
{
  int32_T stride_0_0;
  int32_T stride_1_0;
  stride_0_0 = (in2.size(0) != 1);

  /* Start for MATLABSystem: '<S1>/solver' */
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < 160; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    in1[i] = in3[i * stride_1_0] * 1.4142135623730951 * in1[i] + in2[i *
      stride_0_0];
  }
}

void longitudinal_mpc::longitudinal_mpc_norminv_approx(const real_T p[160],
  const coder::array<real_T, 1U> &mu, const coder::array<real_T, 1U> &sigma,
  real_T x[160])
{
  __m128d tmp;
  real_T R;
  real_T nIterations;
  real_T s;
  real_T y;
  real_T y_0;
  real_T z;
  int32_T b_k;
  int32_T c_k;
  int32_T d;
  int32_T eint;
  boolean_T guard1;

  /*  Approximate inverse normal CDF using erfcinv */
  for (b_k = 0; b_k < 160; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    y_0 = (1.0 - p[b_k]) * 2.0;
    nIterations = 2.0;

    /* Start for MATLABSystem: '<S1>/solver' */
    if ((y_0 > 2.0) || (y_0 < 0.0) || std::isnan(y_0)) {
      y = (rtNaN);
    } else if (y_0 == 0.0) {
      y = (rtInf);
    } else if (y_0 == 2.0) {
      y = (rtMinusInf);
    } else {
      guard1 = false;
      if (y_0 > 1.7) {
        z = std::sqrt(-std::log((2.0 - y_0) / 2.0));
        y = -(((1.641345311 * z + 3.429567803) * z - 1.624906493) * z -
              1.970840454) / ((1.6370678 * z + 3.5438892) * z + 1.0);
        guard1 = true;
      } else if (y_0 < 0.3) {
        z = std::sqrt(0.69314718055994529 - std::log(y_0));
        if (y_0 < 1.0947644252537633E-47) {
          if (y_0 < 7.7532508072625747E-267) {
            nIterations = 4.0;
          } else {
            nIterations = 3.0;
          }
        }

        y = (((1.641345311 * z + 3.429567803) * z - 1.624906493) * z -
             1.970840454) / ((1.6370678 * z + 3.5438892) * z + 1.0);
        d = static_cast<int32_T>(nIterations) - 1;
        for (c_k = 0; c_k <= d; c_k++) {
          nIterations = -(longitudinal_mpc_eml_erfcore(y) - y_0) / (std::exp(-y *
            y) * 1.1283791670955126);
          y -= nIterations / (y * nIterations + 1.0);
        }
      } else {
        z = (1.0 - y_0) * (1.0 - y_0);
        y = (((-0.140543331 * z + 0.914624893) * z - 1.645349621) * z +
             0.886226899) * (1.0 - y_0) / ((((0.012229801 * z - 0.329097515) * z
          + 1.442710462) * z - 2.118377725) * z + 1.0);
        guard1 = true;
      }

      if (guard1) {
        if (y_0 > 1.7) {
          for (c_k = 0; c_k < 2; c_k++) {
            nIterations = (longitudinal_mpc_eml_erfcore(-y) - (2.0 - y_0)) /
              (std::exp(-y * y) * 1.1283791670955126);
            y -= nIterations / (y * nIterations + 1.0);
          }
        } else {
          for (c_k = 0; c_k < 2; c_k++) {
            /* ========================== COPYRIGHT NOTICE ============================ */
            /*  The algorithms for calculating ERF(X) and ERFC(X) are derived           */
            /*  from FDLIBM, which has the following notice:                            */
            /*                                                                          */
            /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.       */
            /*                                                                          */
            /*  Developed at SunSoft, a Sun Microsystems, Inc. business.                */
            /*  Permission to use, copy, modify, and distribute this                    */
            /*  software is freely granted, provided that this notice                   */
            /*  is preserved.                                                           */
            /* =============================    END    ================================ */
            nIterations = std::abs(y);
            if (std::isnan(y)) {
              nIterations = (rtNaN);
            } else if (std::isinf(y)) {
              if (y < 0.0) {
                nIterations = -1.0;
              } else {
                nIterations = 1.0;
              }
            } else if (nIterations < 0.84375) {
              if (nIterations < 3.7252902984619141E-9) {
                if (nIterations < 2.8480945388892178E-306) {
                  nIterations = (8.0 * y + 1.0270333367641007 * y) * 0.125;
                } else {
                  nIterations = 0.12837916709551259 * y + y;
                }
              } else {
                z = y * y;
                nIterations = ((((z * -2.3763016656650163E-5 -
                                  0.0057702702964894416) * z -
                                 0.02848174957559851) * z - 0.3250421072470015) *
                               z + 0.12837916709551256) / (((((z *
                  -3.9602282787753681E-6 + 0.00013249473800432164) * z +
                  0.0050813062818757656) * z + 0.0650222499887673) * z +
                  0.39791722395915535) * z + 1.0) * y + y;
              }
            } else if (nIterations < 1.25) {
              if (y >= 0.0) {
                nIterations = (((((((nIterations - 1.0) * -0.0021663755948687908
                                    + 0.035478304325618236) * (nIterations - 1.0)
                                   - 0.11089469428239668) * (nIterations - 1.0)
                                  + 0.31834661990116175) * (nIterations - 1.0) -
                                 0.37220787603570132) * (nIterations - 1.0) +
                                0.41485611868374833) * (nIterations - 1.0) -
                               0.0023621185607526594) / (((((((nIterations - 1.0)
                  * 0.011984499846799107 + 0.013637083912029051) * (nIterations
                  - 1.0) + 0.12617121980876164) * (nIterations - 1.0) +
                  0.071828654414196266) * (nIterations - 1.0) +
                  0.540397917702171) * (nIterations - 1.0) + 0.10642088040084423)
                  * (nIterations - 1.0) + 1.0) + 0.84506291151046753;
              } else {
                nIterations = -0.84506291151046753 - (((((((nIterations - 1.0) *
                  -0.0021663755948687908 + 0.035478304325618236) * (nIterations
                  - 1.0) - 0.11089469428239668) * (nIterations - 1.0) +
                  0.31834661990116175) * (nIterations - 1.0) -
                  0.37220787603570132) * (nIterations - 1.0) +
                  0.41485611868374833) * (nIterations - 1.0) -
                  0.0023621185607526594) / (((((((nIterations - 1.0) *
                  0.011984499846799107 + 0.013637083912029051) * (nIterations -
                  1.0) + 0.12617121980876164) * (nIterations - 1.0) +
                  0.071828654414196266) * (nIterations - 1.0) +
                  0.540397917702171) * (nIterations - 1.0) + 0.10642088040084423)
                  * (nIterations - 1.0) + 1.0);
              }
            } else if (nIterations > 6.0) {
              if (y < 0.0) {
                nIterations = -1.0;
              } else {
                nIterations = 1.0;
              }
            } else {
              s = 1.0 / (nIterations * nIterations);
              if (nIterations < 2.8571434020996094) {
                R = ((((((s * -9.8143293441691455 - 81.2874355063066) * s -
                         184.60509290671104) * s - 162.39666946257347) * s -
                       62.375332450326006) * s - 10.558626225323291) * s -
                     0.69385857270718176) * s - 0.0098649440348471482;
                s = (((((((s * -0.0604244152148581 + 6.5702497703192817) * s +
                          108.63500554177944) * s + 429.00814002756783) * s +
                        645.38727173326788) * s + 434.56587747522923) * s +
                      137.65775414351904) * s + 19.651271667439257) * s + 1.0;
              } else {
                R = (((((s * -483.5191916086514 - 1025.0951316110772) * s -
                        637.56644336838963) * s - 160.63638485582192) * s -
                      17.757954917754752) * s - 0.799283237680523) * s -
                  0.0098649429247001;
                s = ((((((s * -22.440952446585818 + 474.52854120695537) * s +
                         2553.0504064331644) * s + 3199.8582195085955) * s +
                       1536.729586084437) * s + 325.79251299657392) * s +
                     30.338060743482458) * s + 1.0;
              }

              if (!std::isnan(nIterations)) {
                z = std::frexp(nIterations, &eint);
                d = eint;
              } else {
                z = (rtNaN);
                d = 0;
              }

              z = std::floor(z * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0,
                static_cast<real_T>(d));
              nIterations = std::exp((z - nIterations) * (z + nIterations) + R /
                s) * std::exp(-z * z - 0.5625) / nIterations;
              if (y < 0.0) {
                nIterations--;
              } else {
                nIterations = 1.0 - nIterations;
              }
            }

            nIterations = (nIterations - (1.0 - y_0)) / (std::exp(-y * y) *
              1.1283791670955126);
            y -= nIterations / (y * nIterations + 1.0);
          }
        }
      }
    }

    x[b_k] = y;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  if ((sigma.size(0) == 160) && (mu.size(0) == 160)) {
    for (b_k = 0; b_k <= 158; b_k += 2) {
      tmp = _mm_loadu_pd(&x[b_k]);
      _mm_storeu_pd(&x[b_k], _mm_add_pd(_mm_mul_pd(_mm_mul_pd(_mm_loadu_pd
        (&(*(coder::array<real_T, 1U> *)&sigma)[b_k]), _mm_set1_pd
        (1.4142135623730951)), tmp), _mm_loadu_pd(&(*(coder::array<real_T, 1U> *)
        &mu)[b_k])));
    }
  } else {
    longitudinal_m_binary_expand_op(x, mu, sigma);
  }
}

void longitudinal_mpc::longitudinal_m_PCCMPC_getChance(real_T alpha_0, real_T
  u_var, real_T s_p[160], real_T v_p[160], real_T alphas[160])
{
  coder::array<real_T, 1U> b_x;
  real_T GammaB[320];
  int32_T b_k;
  int32_T c;
  int32_T d;
  int32_T kidx;
  int32_T nx;
  static const real_T tmp[4]{ 1.0, 0.0, 0.1, 1.0 };

  __m128d tmp_3;
  coder::array<real_T, 1U> Mean;
  coder::array<uint16_T, 1U> tmp_0;
  coder::array<uint16_T, 1U> tmp_1;
  real_T tmp_2[4];
  real_T Gamma;
  real_T PhiP;
  int32_T i;
  int32_T loop_ub;
  int32_T partialTrueCount_tmp;
  int16_T h[2];
  int16_T h_0;
  int8_T A;
  static const int8_T A_0[25600]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1
  };

  static const real_T tmp_4[4]{ 1.0, 0.0, 0.1, 1.0 };

  static const int8_T B[4]{ 1, 0, 0, 0 };

  static const int8_T B_0[4]{ 0, 0, 0, 1 };

  __m128d tmp_5;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %% Tyler Ard                %%% */
  /* %% Argonne National Lab     %%% */
  /* %% Vehicle Mobility Systems %%% */
  /* %% tard(at)anl.gov          %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  GETCHANCE */
  /* %% Prediction model */
  /*  \hat{x} = Ax + Bu */
  /*  u = \bar{u} + \var{u} */
  /*  Model discretization size [s] */
  /* %% Forward stages */
  /*  Parameters */
  /*  Choose the confidence - old version: alphas = linspace(0.9999, 0.5001, N); */
  std::memset(&alphas[0], 0, 160U * sizeof(real_T));

  /*  Trajectory of a-priori decided confidence values to meet the constraint margin */
  alphas[0] = alpha_0;

  /*  First value */
  for (kidx = 0; kidx < 159; kidx++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    alphas[kidx + 1] = std::fmax(rt_powd_snf(0.95, ((static_cast<real_T>(kidx) +
      2.0) - 1.0) * 0.1 + 1.0) * alphas[0], 0.5);

    /*  Geometrically decrease the confidence as the trajectory time increases */
  }

  /*  Model forward */
  std::memset(&longitudinal_mpc_B.PhiP[0], 0, 640U * sizeof(real_T));
  longitudinal_mpc_B.PhiP[0] = 1.0;
  longitudinal_mpc_B.PhiP[321] = 1.0;
  for (b_k = 0; b_k < 159; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    c = (b_k + 1) << 1;
    partialTrueCount_tmp = static_cast<int32_T>(((static_cast<real_T>(b_k) + 2.0)
      - 2.0) * 2.0 + 1.0);
    if (partialTrueCount_tmp > c) {
      nx = 0;
      d = 0;
    } else {
      nx = partialTrueCount_tmp - 1;
      d = c;
    }

    c = (b_k + 2) << 1;
    partialTrueCount_tmp = static_cast<int32_T>(((static_cast<real_T>(b_k) + 2.0)
      - 1.0) * 2.0 + 1.0);
    if (partialTrueCount_tmp > c) {
      kidx = 0;
      c = 0;
    } else {
      kidx = partialTrueCount_tmp - 1;
    }

    loop_ub = d - nx;
    for (partialTrueCount_tmp = 0; partialTrueCount_tmp < 2;
         partialTrueCount_tmp++) {
      for (i = 0; i < loop_ub; i++) {
        longitudinal_mpc_B.PhiP_data_d[i + loop_ub * partialTrueCount_tmp] =
          longitudinal_mpc_B.PhiP[(nx + i) + 320 * partialTrueCount_tmp];
      }
    }

    for (partialTrueCount_tmp = 0; partialTrueCount_tmp <= 0;
         partialTrueCount_tmp += 2) {
      tmp_3 = _mm_set_pd(static_cast<real_T>(static_cast<int32_T>
        (tmp_4[partialTrueCount_tmp + 1])), static_cast<real_T>
                         (static_cast<int32_T>(tmp_4[partialTrueCount_tmp])));
      tmp_5 = _mm_loadu_pd(&tmp[partialTrueCount_tmp + 2]);
      _mm_storeu_pd(&tmp_2[partialTrueCount_tmp], _mm_add_pd(_mm_mul_pd
        (_mm_set1_pd(longitudinal_mpc_B.PhiP_data_d[0]), tmp_3), _mm_mul_pd
        (tmp_5, _mm_set1_pd(longitudinal_mpc_B.PhiP_data_d[1]))));
      _mm_storeu_pd(&tmp_2[partialTrueCount_tmp + 2], _mm_add_pd(_mm_mul_pd
        (_mm_set1_pd(longitudinal_mpc_B.PhiP_data_d[2]), tmp_3), _mm_mul_pd
        (tmp_5, _mm_set1_pd(longitudinal_mpc_B.PhiP_data_d[3]))));
    }

    h_0 = static_cast<int16_T>(c - kidx);
    h[0] = h_0;
    loop_ub = h_0;
    for (partialTrueCount_tmp = 0; partialTrueCount_tmp < 2;
         partialTrueCount_tmp++) {
      for (i = 0; i < loop_ub; i++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        longitudinal_mpc_B.PhiP[(kidx + i) + 320 * partialTrueCount_tmp] =
          tmp_2[h[0] * partialTrueCount_tmp + i];
      }
    }
  }

  std::memset(&longitudinal_mpc_B.GammaP[0], 0, 102400U * sizeof(real_T));
  for (b_k = 0; b_k < 320; b_k++) {
    longitudinal_mpc_B.GammaP[b_k + 320 * b_k] = 1.0;
  }

  for (kidx = 0; kidx < 159; kidx++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_k = (kidx << 1) + 1;
    c = (kidx + 1) << 1;
    partialTrueCount_tmp = static_cast<int32_T>(((static_cast<real_T>(kidx) +
      1.0) - 1.0) * 2.0 + 1.0);
    if (partialTrueCount_tmp > c) {
      nx = 0;
      d = 0;
    } else {
      nx = partialTrueCount_tmp - 1;
      d = c;
    }

    loop_ub = (160 - kidx) << 1;
    for (partialTrueCount_tmp = 0; partialTrueCount_tmp < 2;
         partialTrueCount_tmp++) {
      for (i = 0; i < loop_ub; i++) {
        longitudinal_mpc_B.PhiP_data[i + loop_ub * partialTrueCount_tmp] =
          longitudinal_mpc_B.PhiP[320 * partialTrueCount_tmp + i];
      }
    }

    h[0] = static_cast<int16_T>(321 - b_k);
    h[1] = static_cast<int16_T>(d - nx);
    loop_ub = h[1];
    for (partialTrueCount_tmp = 0; partialTrueCount_tmp < loop_ub;
         partialTrueCount_tmp++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      d = 321 - b_k;
      for (i = 0; i < d; i++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        longitudinal_mpc_B.GammaP[((b_k + i) + 320 * (nx + partialTrueCount_tmp))
          - 1] = longitudinal_mpc_B.PhiP_data[h[0] * partialTrueCount_tmp + i];
      }
    }
  }

  kidx = -1;
  for (b_k = 0; b_k < 160; b_k++) {
    for (d = 0; d < 160; d++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      A = A_0[160 * b_k + d];
      longitudinal_mpc_B.b[kidx + 1] = static_cast<real_T>(A) *
        0.005000000000000001;
      longitudinal_mpc_B.b[kidx + 2] = static_cast<real_T>(A) * 0.1;
      kidx += 2;
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Mean */
  for (partialTrueCount_tmp = 0; partialTrueCount_tmp < 320;
       partialTrueCount_tmp++) {
    for (i = 0; i < 160; i++) {
      Gamma = 0.0;
      for (b_k = 0; b_k < 320; b_k++) {
        Gamma += longitudinal_mpc_B.GammaP[320 * b_k + partialTrueCount_tmp] *
          longitudinal_mpc_B.b[320 * i + b_k];
      }

      longitudinal_mpc_B.Gamma[partialTrueCount_tmp + 320 * i] = Gamma;
    }

    Gamma = longitudinal_mpc_B.PhiP[partialTrueCount_tmp + 320];
    PhiP = longitudinal_mpc_B.PhiP[partialTrueCount_tmp];
    GammaB[partialTrueCount_tmp] = (PhiP * 0.1 + Gamma) * 0.0 + (Gamma * 0.0 +
      PhiP) * 0.0;
  }

  for (partialTrueCount_tmp = 0; partialTrueCount_tmp < 160;
       partialTrueCount_tmp++) {
    for (i = 0; i <= 318; i += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      b_k = 320 * partialTrueCount_tmp + i;
      tmp_3 = _mm_loadu_pd(&longitudinal_mpc_B.Gamma[b_k]);
      tmp_5 = _mm_loadu_pd(&GammaB[i]);

      /* Start for MATLABSystem: '<S1>/solver' */
      _mm_storeu_pd(&longitudinal_mpc_B.Mean[b_k], _mm_add_pd(_mm_mul_pd(tmp_3,
        _mm_set1_pd(0.0)), tmp_5));
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Covariance */
  Gamma = std::sqrt(u_var);
  for (partialTrueCount_tmp = 0; partialTrueCount_tmp < 320;
       partialTrueCount_tmp++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    PhiP = 0.0;
    for (i = 0; i < 160; i++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      PhiP += longitudinal_mpc_B.Gamma[320 * i + partialTrueCount_tmp] * Gamma;
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    GammaB[partialTrueCount_tmp] = PhiP;
  }

  for (partialTrueCount_tmp = 0; partialTrueCount_tmp < 320;
       partialTrueCount_tmp++) {
    for (i = 0; i <= 318; i += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_3 = _mm_loadu_pd(&GammaB[i]);
      _mm_storeu_pd(&longitudinal_mpc_B.Cov[i + 320 * partialTrueCount_tmp],
                    _mm_mul_pd(tmp_3, _mm_set1_pd(GammaB[partialTrueCount_tmp])));
    }
  }

  /* %% Uncertainty */
  kidx = -1;
  for (b_k = 0; b_k < 160; b_k++) {
    for (d = 0; d < 160; d++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal_mpc_B.b[kidx + 1] = A_0[160 * b_k + d];
      longitudinal_mpc_B.b[kidx + 2] = 0.0;
      kidx += 2;
    }
  }

  kidx = -1;
  for (b_k = 0; b_k < 160; b_k++) {
    for (nx = 0; nx < 2; nx++) {
      for (d = 0; d < 160; d++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        longitudinal_mpc_B.GammaP[kidx + 1] = A_0[160 * b_k + d] * B[nx << 1];
        longitudinal_mpc_B.GammaP[kidx + 2] = 0.0;
        kidx += 2;
      }
    }
  }

  nx = 0;
  for (b_k = 0; b_k < 102400; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.GammaP[b_k] != 0.0) {
      nx++;
    }
  }

  b_x.set_size(nx);
  nx = 0;
  partialTrueCount_tmp = 0;
  for (b_k = 0; b_k < 102400; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.GammaP[b_k] != 0.0) {
      b_x[nx] = longitudinal_mpc_B.Cov[b_k];
      partialTrueCount_tmp = nx + 1;
      nx++;
    }
  }

  nx = partialTrueCount_tmp - 1;
  partialTrueCount_tmp = (partialTrueCount_tmp / 2) << 1;
  kidx = partialTrueCount_tmp - 2;
  for (b_k = 0; b_k <= kidx; b_k += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_3 = _mm_loadu_pd(&b_x[b_k]);
    _mm_storeu_pd(&b_x[b_k], _mm_sqrt_pd(tmp_3));
  }

  for (b_k = partialTrueCount_tmp; b_k <= nx; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_x[b_k] = std::sqrt(b_x[b_k]);
  }

  nx = 0;
  for (b_k = 0; b_k < 51200; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.b[b_k] != 0.0) {
      nx++;
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  tmp_0.set_size(nx);
  nx = 0;
  for (b_k = 0; b_k < 51200; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.b[b_k] != 0.0) {
      tmp_0[nx] = static_cast<uint16_T>(b_k);
      nx++;
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  loop_ub = tmp_0.size(0);
  Mean.set_size(tmp_0.size(0));
  for (partialTrueCount_tmp = 0; partialTrueCount_tmp < loop_ub;
       partialTrueCount_tmp++) {
    Mean[partialTrueCount_tmp] =
      longitudinal_mpc_B.Mean[tmp_0[partialTrueCount_tmp]];
  }

  longitudinal_mpc_norminv_approx(alphas, Mean, b_x, s_p);

  /*  Velocity covariance trace */
  kidx = -1;
  for (b_k = 0; b_k < 160; b_k++) {
    for (d = 0; d < 160; d++) {
      longitudinal_mpc_B.b[kidx + 1] = 0.0;

      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal_mpc_B.b[kidx + 2] = A_0[160 * b_k + d];
      kidx += 2;
    }
  }

  kidx = -1;
  for (b_k = 0; b_k < 160; b_k++) {
    for (nx = 0; nx < 2; nx++) {
      for (d = 0; d < 160; d++) {
        longitudinal_mpc_B.GammaP[kidx + 1] = 0.0;

        /* Start for MATLABSystem: '<S1>/solver' */
        longitudinal_mpc_B.GammaP[kidx + 2] = A_0[160 * b_k + d] * B_0[(nx << 1)
          + 1];
        kidx += 2;
      }
    }
  }

  nx = 0;
  for (b_k = 0; b_k < 102400; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.GammaP[b_k] != 0.0) {
      nx++;
    }
  }

  b_x.set_size(nx);
  nx = 0;
  partialTrueCount_tmp = 0;
  for (b_k = 0; b_k < 102400; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.GammaP[b_k] != 0.0) {
      b_x[nx] = longitudinal_mpc_B.Cov[b_k];
      partialTrueCount_tmp = nx + 1;
      nx++;
    }
  }

  nx = partialTrueCount_tmp - 1;
  partialTrueCount_tmp = (partialTrueCount_tmp / 2) << 1;
  kidx = partialTrueCount_tmp - 2;
  for (b_k = 0; b_k <= kidx; b_k += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_3 = _mm_loadu_pd(&b_x[b_k]);
    _mm_storeu_pd(&b_x[b_k], _mm_sqrt_pd(tmp_3));
  }

  for (b_k = partialTrueCount_tmp; b_k <= nx; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_x[b_k] = std::sqrt(b_x[b_k]);
  }

  nx = 0;
  for (b_k = 0; b_k < 51200; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.b[b_k] != 0.0) {
      nx++;
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  tmp_1.set_size(nx);
  nx = 0;
  for (b_k = 0; b_k < 51200; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    if (longitudinal_mpc_B.b[b_k] != 0.0) {
      tmp_1[nx] = static_cast<uint16_T>(b_k);
      nx++;
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  loop_ub = tmp_1.size(0);
  Mean.set_size(tmp_1.size(0));
  for (partialTrueCount_tmp = 0; partialTrueCount_tmp < loop_ub;
       partialTrueCount_tmp++) {
    Mean[partialTrueCount_tmp] =
      longitudinal_mpc_B.Mean[tmp_1[partialTrueCount_tmp]];
  }

  longitudinal_mpc_norminv_approx(alphas, Mean, b_x, v_p);

  /* %% Debugging */
}

void longitudinal_mpc::longitudinal_mpc_interp1_b(const real_T varargin_2[160],
  real_T Vq[33])
{
  real_T slopes[160];
  real_T del[159];
  real_T h[159];
  real_T del_0;
  real_T h_0;
  real_T u;
  real_T w1;
  real_T w2;
  int32_T low_i;
  for (int32_T b_k{0}; b_k < 159; b_k++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    w1 = (static_cast<real_T>(b_k) + 1.0) * 0.1 - 0.1 * static_cast<real_T>(b_k);
    h[b_k] = w1;

    /* Start for MATLABSystem: '<S1>/solver' */
    del[b_k] = (varargin_2[b_k + 1] - varargin_2[b_k]) / w1;
  }

  for (int32_T b_k{0}; b_k < 158; b_k++) {
    h_0 = h[b_k + 1];
    w2 = h[b_k];
    w1 = h_0 * 2.0 + w2;
    w2 = w2 * 2.0 + h_0;
    slopes[b_k + 1] = 0.0;

    /* Start for MATLABSystem: '<S1>/solver' */
    del_0 = del[b_k];
    h_0 = del[b_k + 1];
    u = del_0 * h_0;
    if (std::isnan(u)) {
      u = (rtNaN);
    } else if (u < 0.0) {
      u = -1.0;
    } else {
      u = (u > 0.0);
    }

    if (u > 0.0) {
      slopes[b_k + 1] = (w1 + w2) / (w1 / del_0 + w2 / h_0);
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  w1 = ((2.0 * h[0] + h[1]) * del[0] - h[0] * del[1]) / (h[0] + h[1]);
  if (std::isnan(del[0])) {
    w2 = (rtNaN);
  } else if (del[0] < 0.0) {
    w2 = -1.0;
  } else {
    w2 = (del[0] > 0.0);
  }

  if (std::isnan(w1)) {
    u = (rtNaN);
  } else if (w1 < 0.0) {
    u = -1.0;
  } else {
    u = (w1 > 0.0);
  }

  if (u != w2) {
    w1 = 0.0;
  } else {
    if (std::isnan(del[1])) {
      u = (rtNaN);
    } else if (del[1] < 0.0) {
      u = -1.0;
    } else {
      u = (del[1] > 0.0);
    }

    if ((w2 != u) && (std::abs(w1) > std::abs(3.0 * del[0]))) {
      w1 = 3.0 * del[0];
    }
  }

  slopes[0] = w1;

  /* Start for MATLABSystem: '<S1>/solver' */
  w1 = ((2.0 * h[158] + h[157]) * del[158] - del[157] * h[158]) / (h[157] + h
    [158]);
  if (std::isnan(del[158])) {
    w2 = (rtNaN);
  } else if (del[158] < 0.0) {
    w2 = -1.0;
  } else {
    w2 = (del[158] > 0.0);
  }

  if (std::isnan(w1)) {
    u = (rtNaN);
  } else if (w1 < 0.0) {
    u = -1.0;
  } else {
    u = (w1 > 0.0);
  }

  if (u != w2) {
    w1 = 0.0;
  } else {
    if (std::isnan(del[157])) {
      u = (rtNaN);
    } else if (del[157] < 0.0) {
      u = -1.0;
    } else {
      u = (del[157] > 0.0);
    }

    if ((w2 != u) && (std::abs(w1) > std::abs(3.0 * del[158]))) {
      w1 = 3.0 * del[158];
    }
  }

  slopes[159] = w1;
  for (low_i = 0; low_i <= 156; low_i += 2) {
    __m128d tmp;
    __m128d tmp_0;
    __m128d tmp_1;
    __m128d tmp_2;
    __m128d tmp_3;

    /* Start for MATLABSystem: '<S1>/solver' */
    tmp = _mm_loadu_pd(&del[low_i]);
    tmp_0 = _mm_loadu_pd(&slopes[low_i]);
    tmp_1 = _mm_loadu_pd(&h[low_i]);
    tmp_2 = _mm_div_pd(_mm_sub_pd(tmp, tmp_0), tmp_1);

    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_3 = _mm_loadu_pd(&slopes[low_i + 1]);
    tmp = _mm_div_pd(_mm_sub_pd(tmp_3, tmp), tmp_1);

    /* Start for MATLABSystem: '<S1>/solver' */
    _mm_storeu_pd(&longitudinal_mpc_B.pp_coefs_g[low_i], _mm_div_pd(_mm_sub_pd
      (tmp, tmp_2), tmp_1));
    _mm_storeu_pd(&longitudinal_mpc_B.pp_coefs_g[low_i + 159], _mm_sub_pd
                  (_mm_mul_pd(_mm_set1_pd(2.0), tmp_2), tmp));
    _mm_storeu_pd(&longitudinal_mpc_B.pp_coefs_g[low_i + 318], tmp_0);
    _mm_storeu_pd(&longitudinal_mpc_B.pp_coefs_g[low_i + 477], _mm_loadu_pd
                  (&varargin_2[low_i]));
  }

  for (low_i = 158; low_i < 159; low_i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    del_0 = del[low_i];
    u = slopes[low_i];
    h_0 = h[low_i];
    w1 = (del_0 - u) / h_0;
    w2 = (slopes[low_i + 1] - del_0) / h_0;
    longitudinal_mpc_B.pp_coefs_g[low_i] = (w2 - w1) / h_0;
    longitudinal_mpc_B.pp_coefs_g[low_i + 159] = 2.0 * w1 - w2;
    longitudinal_mpc_B.pp_coefs_g[low_i + 318] = u;
    longitudinal_mpc_B.pp_coefs_g[low_i + 477] = varargin_2[low_i];
  }

  for (int32_T b_k{0}; b_k < 33; b_k++) {
    int32_T high_i;
    int32_T low_ip1;
    low_i = 0;
    low_ip1 = 1;
    high_i = 160;
    while (high_i > low_ip1 + 1) {
      int32_T mid_i;

      /* Start for MATLABSystem: '<S1>/solver' */
      mid_i = ((low_i + high_i) + 1) >> 1;
      if (0.5 * static_cast<real_T>(b_k) >= (static_cast<real_T>(mid_i) - 1.0) *
          0.1) {
        low_i = mid_i - 1;
        low_ip1 = mid_i;
      } else {
        high_i = mid_i;
      }
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    w1 = 0.5 * static_cast<real_T>(b_k) - 0.1 * static_cast<real_T>(low_i);
    Vq[b_k] = ((w1 * longitudinal_mpc_B.pp_coefs_g[low_i] +
                longitudinal_mpc_B.pp_coefs_g[low_i + 159]) * w1 +
               longitudinal_mpc_B.pp_coefs_g[low_i + 318]) * w1 +
      longitudinal_mpc_B.pp_coefs_g[low_i + 477];
  }
}

boolean_T longitudinal_mpc::longitudinal_mpc_vectorAny(const boolean_T x_data[],
  const int32_T x_size[1])
{
  int32_T b_k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= x_size[0] - 1)) {
    if (x_data[b_k]) {
      y = true;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return y;
}

void longitudinal_mpc::longitudinal_m_PCCMPC_updateMPC(solver_longitudinal_mpc_T
  *b_this)
{
  __m128d tmp;
  __m128d tmp_1;
  real_T K[384];
  real_T a__4[160];
  real_T p[160];
  real_T p_v[160];
  real_T K_1[40];
  real_T dchance[33];
  real_T A[32];
  real_T s_vary_ind[12];
  real_T K_0[10];
  real_T tmp_0[2];
  real_T dchance_0;
  real_T p_0;
  int32_T b_i1;
  int32_T b_i2;
  int32_T i;
  int32_T kidx;
  int32_T xoffset;
  boolean_T s_vary_ind_data[394];
  static const real_T tmp_2[16]{ 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,
    0.5, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0 };

  static const int8_T tmp_3[12]{ -1, 1, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0 };

  static const int8_T tmp_4[32]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T A_0[992]{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const int8_T A_1[1024]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  real_T tmp_5[16];
  real_T unusedExpr[16];
  int32_T s_vary_ind_size[1];

  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% Calculations that vary on input signals */
  /*  Control model */
  /* %% Input arguments */
  /* %% Input lag parameters */
  /*  [s] default 0.275; */
  /*  First order lag on acceleration \dot{a} = tauinv (u - a) */
  /*  Error check */
  /*  Make Control Model */
  /*  Continuous time state transition matrice */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %% Tyler Ard                %%% */
  /* %% Argonne National Lab     %%% */
  /* %% Vehicle Mobility Systems %%% */
  /* %% tard(at)anl.gov          %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Get matrix dimensions */
  /*  Make square matrix S = [A, B; 0, 0] */
  /*  Perform zero order hold */
  std::memcpy(&tmp_5[0], &tmp_2[0], sizeof(real_T) << 4);
  longitudinal_mpc_expm(tmp_5, unusedExpr);

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Extract */
  /*  Add in delta u = u_k - u_{k-1} */
  /*  model_type */
  /*  Outputs y = Cx + Du + V_a */
  b_this->C[0] = 1.0;
  b_this->C[4] = b_this->THref;
  b_this->C[8] = 0.0;
  b_this->C[12] = 0.0;
  b_this->C[1] = 0.0;
  b_this->C[2] = 0.0;
  b_this->C[3] = 0.0;
  b_this->C[5] = 1.0;
  b_this->C[6] = 0.0;
  b_this->C[7] = 0.0;
  b_this->C[9] = 0.0;
  b_this->C[10] = 1.0;
  b_this->C[11] = 0.0;
  b_this->C[13] = 0.0;
  b_this->C[14] = 0.0;
  b_this->C[15] = -1.0;

  /*  Output state matrix */
  /*  y1 = S + V TH */
  /*  y4 = u_k - u_{k-1} */
  /*  Output control matrix */
  /*  State disturbances */
  /*  Affine state disturbance */
  /*  Parametric state disturbance */
  /*  Output Disturbances */
  /*  Affine output disturbance measurement */
  /*  y1 - d0 */
  /*  Set objective weights */
  longitudina_PCCMPC_setObjective(b_this);

  /*  Cost function and model */
  longit_PCCMPC_setRecursiveModel(b_this);

  /* %% Set constraint matrices             */
  /*  Standard constraints */
  /*  ua; s v a */
  b_this->Mi[10] = 1.0;
  b_this->Mi[22] = b_this->THsafe;
  b_this->Mi[34] = 0.0;
  b_this->Mi[46] = 0.0;
  b_this->Mi[11] = -1.0;
  b_this->Mi[23] = -b_this->THmax;
  b_this->Mi[35] = 0.0;
  b_this->Mi[47] = 0.0;

  /*  State matrix for constraint stages */
  /*  Standard lower and upper bounds on control */
  /*  Standard lower and upper bounds on outputs */
  /*  Affine constraints */
  /*  s + v t_safe \leq E{s_pv} - d_0 - d_c: time varying parameter */
  /*  - s - v E{t_chance} \leq - E{s_pv} + d_0 + d_c: time varying parameter */
  /*  Integer constraints */
  for (b_i1 = 0; b_i1 < 4; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this->Mi[12 * b_i1] = -0.0;
    b_this->Mi[12 * b_i1 + 1] = 0.0;
    i = b_i1 << 2;
    b_this->Mi[12 * b_i1 + 2] = -b_this->C[i];
    b_this->Mi[12 * b_i1 + 6] = b_this->C[i];
    p_0 = b_this->C[i + 1];
    b_this->Mi[12 * b_i1 + 3] = -p_0;
    b_this->Mi[12 * b_i1 + 7] = p_0;
    p_0 = b_this->C[i + 2];
    b_this->Mi[12 * b_i1 + 4] = -p_0;
    b_this->Mi[12 * b_i1 + 8] = p_0;
    p_0 = b_this->C[i + 3];
    b_this->Mi[12 * b_i1 + 5] = -p_0;
    b_this->Mi[12 * b_i1 + 9] = p_0;
    std::memcpy(&b_this->Mn[b_i1 * 10], &b_this->Mi[b_i1 * 12 + 2], 10U * sizeof
                (real_T));
  }

  /*  Terminal stages are without bounded control constraints */
  for (i = 0; i < 12; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this->Ei[i] = tmp_3[i];
  }

  /*  Control matrix for constraint stages */
  /*  Standard lower and upper bounds on control */
  /*  Standard lower and upper bounds on outputs */
  /*  Affine constraints */
  /*  s + v t_safe \leq E{s_pv-s} - d_0 - d_c: time varying parameter */
  /*  -s - v t_max \leq -E{s_pv-s} + d_0 + d_c: time varying parameter */
  /*  Integer constraints */
  /*  Standard constraints - rhs */
  /*  ua; s+thv v a */
  b_this->ci[0] = 3.0;
  b_this->ci[1] = 3.0;
  b_this->ci[2] = 0.0;
  b_this->ci[3] = 0.0;
  b_this->ci[4] = (rtInf);
  b_this->ci[5] = (rtInf);
  b_this->ci[6] = b_this->pos_max - b_this->d0;
  b_this->ci[7] = b_this->vel_max;
  b_this->ci[8] = (rtInf);
  b_this->ci[9] = (rtInf);
  b_this->ci[10] = -b_this->d0;
  b_this->ci[11] = b_this->d0;

  /*  RHS bound for Mi xi + Ei ui \leq bi */
  /*  Standard lower and upper bounds on control */
  /*  -ua b */
  /*  ua t */
  /*  Standard lower and upper bounds on outputs */
  /*  -s */
  /*  -v */
  /*  -a */
  /*  -delta u */
  /*  s */
  /*  v */
  /*  a */
  /*  delta u */
  /*  Affine constraints */
  /*  s + v t_safe \leq - d_0 + E{s_pv} - d_c: time varying parameter */
  /*  -s - v E{t_chance} \leq d_0 - E{s_pv} + d_c: time varying parameter */
  /*  Integer constraints */
  std::memcpy(&b_this->cn[0], &b_this->ci[2], 10U * sizeof(real_T));
  kidx = -1;
  for (b_i1 = 0; b_i1 < 32; b_i1++) {
    std::memcpy(&K[kidx + 1], &b_this->ci[0], 12U * sizeof(real_T));
    kidx += 12;
  }

  std::memcpy(&b_this->c[0], &K[0], 384U * sizeof(real_T));
  std::memcpy(&b_this->c[384], &b_this->cn[0], 10U * sizeof(real_T));

  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% Chance constraints */
  /*  Set the chance constraint for the MPC problem */
  /*  The car-following safety gap */
  longitudinal_m_PCCMPC_getChance(b_this->alpha_proc, b_this->sigma_proc, p, p_v,
    a__4);
  longitudinal_mpc_interp1_b(p, dchance);
  for (b_i2 = 0; b_i2 < 33; b_i2++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this->s_chance[b_i2] = std::fmax(dchance[b_i2], 0.0);
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Chance constraint should not go below 0, and add standstill gap d0 here */
  longitudinal_mpc_interp1_b(p_v, b_this->v_chance);

  /*  The max headway for cut-in probability */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %% Tyler Ard                %%% */
  /* %% Argonne National Lab     %%% */
  /* %% Vehicle Mobility Systems %%% */
  /* %% tard(at)anl.gov          %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  GETCHANCE */
  /* %% Prediction model */
  /*  F = 1 ./ (1 + exp( -(x-mean) ./ var )) */
  /*  [s] */
  /* %% Forward stages */
  /*  Parameters */
  /*  Choose the confidence - alphas = lambda^i * alpha_0; */
  std::memset(&p[0], 0, 160U * sizeof(real_T));

  /*  Trajectory of a-priori decided confidence values to meet the constraint margin */
  p[0] = b_this->alpha_acceptance;

  /*  First value */
  for (b_i1 = 0; b_i1 < 159; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    p[b_i1 + 1] = std::fmin(std::fmax(p[0], 0.0), 1.0);

    /*  Geometrically decrease the confidence as the trajectory time increases */
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Model forward */
  /* %% Uncertainty */
  /*  Approximate inverse normal CDF using erfcinv */
  for (b_i2 = 0; b_i2 < 160; b_i2++) {
    p_0 = p[b_i2];
    p_0 = std::log(p_0 / (1.0 - p_0));
    p[b_i2] = p_0;
    p_v[b_i2] = b_this->scale_acceptance * p_0 + b_this->mean_acceptance;
  }

  longitudinal_mpc_interp1_b(p_v, dchance);
  p_0 = b_this->THref + b_this->THsafe;
  for (b_i2 = 0; b_i2 <= 30; b_i2 += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_0[0] = std::fmin(std::fmax(dchance[b_i2], p_0), b_this->THmax);
    tmp_0[1] = std::fmin(std::fmax(dchance[b_i2 + 1], p_0), b_this->THmax);
    tmp_1 = _mm_loadu_pd(&tmp_0[0]);
    _mm_storeu_pd(&dchance[b_i2], tmp_1);
    _mm_storeu_pd(&b_this->TH_chance[b_i2], _mm_sub_pd(tmp_1, _mm_set1_pd
      (b_this->THmax)));
  }

  for (b_i2 = 32; b_i2 < 33; b_i2++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    dchance_0 = std::fmin(std::fmax(dchance[b_i2], p_0), b_this->THmax);
    dchance[b_i2] = dchance_0;
    b_this->TH_chance[b_i2] = dchance_0 - b_this->THmax;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Add THmax to cancel from Mi */
  /*  Set indices for chance constraints */
  /*  Safety Gap */
  std::memset(&b_this->ci_s_vary_ind[0], 0, 12U * sizeof(real_T));
  b_this->ci_s_vary_ind[10] = 1.0;
  b_this->ci_s_vary_ind[11] = -1.0;
  std::memcpy(&b_this->cn_s_vary_ind[0], &b_this->ci_s_vary_ind[2], 10U * sizeof
              (real_T));
  kidx = -1;
  for (b_i1 = 0; b_i1 < 32; b_i1++) {
    for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->ci_s_vary_ind[b_i2]);
      _mm_storeu_pd(&K[(kidx + b_i2) + 1], _mm_mul_pd(_mm_set1_pd
        (b_this->s_chance[b_i1]), tmp_1));
    }

    kidx += 12;
  }

  kidx = -1;
  for (b_i2 = 0; b_i2 <= 8; b_i2 += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_1 = _mm_loadu_pd(&b_this->cn_s_vary_ind[b_i2]);
    _mm_storeu_pd(&K_0[b_i2], _mm_mul_pd(_mm_set1_pd(b_this->s_chance[32]),
      tmp_1));
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&b_this->s_chance_vary[0], &K[0], 384U * sizeof(real_T));
  std::memcpy(&b_this->s_chance_vary[384], &K_0[0], 10U * sizeof(real_T));

  /*  s_chance vary will be used in getMPC by adding to constraint matrix b in Mx + Eu < b */
  for (b_i1 = 0; b_i1 < 32; b_i1++) {
    for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->ci_s_vary_ind[b_i2]);
      _mm_storeu_pd(&K[(kidx + b_i2) + 1], _mm_mul_pd(_mm_set1_pd
        (b_this->v_chance[b_i1]), tmp_1));
    }

    kidx += 12;
  }

  kidx = -1;
  for (b_i2 = 0; b_i2 <= 8; b_i2 += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_1 = _mm_loadu_pd(&b_this->cn_s_vary_ind[b_i2]);
    _mm_storeu_pd(&K_0[b_i2], _mm_mul_pd(_mm_set1_pd(b_this->v_chance[32]),
      tmp_1));
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&b_this->v_chance_vary[0], &K[0], 384U * sizeof(real_T));
  std::memcpy(&b_this->v_chance_vary[384], &K_0[0], 10U * sizeof(real_T));

  /*  v_chance used to deactivate chance constraint at low speeds */
  /*  Gap acceptance */
  std::memset(&b_this->Mi_th_vary_ind[0], 0, 48U * sizeof(real_T));
  b_this->Mi_th_vary_ind[23] = -1.0;
  for (b_i1 = 0; b_i1 < 4; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&b_this->Mn_th_vary_ind[b_i1 * 10], &b_this->Mi_th_vary_ind[b_i1
                * 12 + 2], 10U * sizeof(real_T));
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  A[0] = b_this->TH_chance[0];
  std::memset(&A[1], 0, 31U * sizeof(real_T));
  for (i = 0; i < 4; i++) {
    for (b_i1 = 0; b_i1 < 32; b_i1++) {
      for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
        /* Start for MATLABSystem: '<S1>/solver' */
        tmp_1 = _mm_loadu_pd(&b_this->Mi_th_vary_ind[12 * i + b_i2]);
        _mm_storeu_pd(&longitudinal_mpc_B.K_n[(kidx + b_i2) + 1], _mm_mul_pd
                      (tmp_1, _mm_set1_pd(A[b_i1])));
      }

      kidx += 12;
    }
  }

  kidx = -1;
  for (i = 0; i < 4; i++) {
    for (b_i2 = 0; b_i2 <= 8; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->Mn_th_vary_ind[10 * i + b_i2]);
      _mm_storeu_pd(&K_1[(kidx + b_i2) + 1], _mm_mul_pd(tmp_1, _mm_set1_pd(0.0)));
    }

    kidx += 10;

    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&b_this->THcal0_chance_vary[i * 394], &longitudinal_mpc_B.K_n[i *
                384], 384U * sizeof(real_T));
  }

  for (b_i1 = 0; b_i1 < 4; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&b_this->THcal0_chance_vary[b_i1 * 394 + 384], &K_1[b_i1 * 10],
                10U * sizeof(real_T));
  }

  std::memset(&longitudinal_mpc_B.d[0], 0, 961U * sizeof(real_T));
  for (b_i1 = 0; b_i1 < 31; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    longitudinal_mpc_B.d[b_i1 + 31 * b_i1] = b_this->TH_chance[b_i1 + 1];
    longitudinal_mpc_B.A[b_i1 << 5] = 0.0;
  }

  for (b_i1 = 0; b_i1 < 31; b_i1++) {
    std::memcpy(&longitudinal_mpc_B.A[(b_i1 << 5) + 1],
                &longitudinal_mpc_B.d[b_i1 * 31], 31U * sizeof(real_T));
  }

  kidx = -1;
  for (xoffset = 0; xoffset < 31; xoffset++) {
    for (i = 0; i < 4; i++) {
      for (b_i1 = 0; b_i1 < 32; b_i1++) {
        for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
          /* Start for MATLABSystem: '<S1>/solver' */
          tmp_1 = _mm_loadu_pd(&b_this->Mi_th_vary_ind[12 * i + b_i2]);
          _mm_storeu_pd(&longitudinal_mpc_B.K[(kidx + b_i2) + 1], _mm_mul_pd
                        (_mm_set1_pd(longitudinal_mpc_B.A[(xoffset << 5) + b_i1]),
                         tmp_1));
        }

        kidx += 12;
      }
    }
  }

  kidx = -1;
  for (i = 0; i < 4; i++) {
    for (b_i2 = 0; b_i2 <= 8; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->Mn_th_vary_ind[10 * i + b_i2]);
      _mm_storeu_pd(&K_1[(kidx + b_i2) + 1], _mm_mul_pd(tmp_1, _mm_set1_pd
        (b_this->TH_chance[32])));
    }

    kidx += 10;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memset(&b_this->TH_chance_vary[0], 0, 50432U * sizeof(real_T));
  for (b_i1 = 0; b_i1 < 124; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&b_this->TH_chance_vary[b_i1 * 394], &longitudinal_mpc_B.K[b_i1 *
                384], 384U * sizeof(real_T));
  }

  /* %% MPC Constraint Matrices */
  kidx = -1;
  for (i = 0; i < 4; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&b_this->TH_chance_vary[i * 394 + 49240], &K_1[i * 10], 10U *
                sizeof(real_T));
    for (b_i1 = 0; b_i1 < 32; b_i1++) {
      for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
        tmp_1 = _mm_loadu_pd(&b_this->Mi[12 * i + b_i2]);

        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&longitudinal_mpc_B.K_n[(kidx + b_i2) + 1], _mm_mul_pd
                      (tmp_1, _mm_set1_pd(static_cast<real_T>(tmp_4[b_i1]))));
      }

      kidx += 12;
    }
  }

  for (b_i1 = 0; b_i1 < 4; b_i1++) {
    for (i = 0; i <= 382; i += 2) {
      tmp_1 = _mm_loadu_pd(&longitudinal_mpc_B.K_n[384 * b_i1 + i]);
      kidx = 394 * b_i1 + i;
      tmp = _mm_loadu_pd(&b_this->THcal0_chance_vary[kidx]);
      _mm_storeu_pd(&b_this->Mcal0[kidx], _mm_add_pd(tmp_1, tmp));
    }

    std::memcpy(&b_this->Mcal0[b_i1 * 394 + 384], &b_this->
                THcal0_chance_vary[b_i1 * 394 + 384], 10U * sizeof(real_T));
  }

  /*  Add TH_chance_vary to modify based on chance constraint */
  kidx = -1;
  for (xoffset = 0; xoffset < 31; xoffset++) {
    for (i = 0; i < 4; i++) {
      for (b_i1 = 0; b_i1 < 32; b_i1++) {
        for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
          tmp_1 = _mm_loadu_pd(&b_this->Mi[12 * i + b_i2]);

          /* Start for MATLABSystem: '<S1>/solver' */
          _mm_storeu_pd(&longitudinal_mpc_B.K[(kidx + b_i2) + 1], _mm_mul_pd
                        (_mm_set1_pd(static_cast<real_T>(A_0[(xoffset << 5) +
            b_i1])), tmp_1));
        }

        kidx += 12;
      }
    }
  }

  std::memset(&longitudinal_mpc_B.y[0], 0, 50432U * sizeof(real_T));
  for (b_i1 = 0; b_i1 < 124; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&longitudinal_mpc_B.y[b_i1 * 394], &longitudinal_mpc_B.K[b_i1 *
                384], 384U * sizeof(real_T));
  }

  for (b_i1 = 0; b_i1 < 4; b_i1++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&longitudinal_mpc_B.y[b_i1 * 394 + 49240], &b_this->Mn[b_i1 * 10],
                10U * sizeof(real_T));
  }

  for (b_i1 = 0; b_i1 <= 50430; b_i1 += 2) {
    tmp_1 = _mm_loadu_pd(&longitudinal_mpc_B.y[b_i1]);
    tmp = _mm_loadu_pd(&b_this->TH_chance_vary[b_i1]);
    _mm_storeu_pd(&b_this->M[b_i1], _mm_add_pd(tmp_1, tmp));
  }

  /*  Add TH_chance_vary to modify based on chance constraint */
  kidx = -1;
  for (xoffset = 0; xoffset < 32; xoffset++) {
    for (b_i1 = 0; b_i1 < 32; b_i1++) {
      for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
        tmp_1 = _mm_loadu_pd(&b_this->Ei[b_i2]);

        /* Start for MATLABSystem: '<S1>/solver' */
        _mm_storeu_pd(&longitudinal_mpc_B.K_c[(kidx + b_i2) + 1], _mm_mul_pd
                      (_mm_set1_pd(static_cast<real_T>(A_1[(xoffset << 5) + b_i1])),
                       tmp_1));
      }

      kidx += 12;
    }
  }

  for (b_i1 = 0; b_i1 < 32; b_i1++) {
    std::memcpy(&b_this->Sigma[b_i1 * 394], &longitudinal_mpc_B.K_c[b_i1 * 384],
                384U * sizeof(real_T));
    std::memset(&b_this->Sigma[b_i1 * 394 + 384], 0, 10U * sizeof(real_T));
  }

  for (b_i1 = 0; b_i1 < 394; b_i1++) {
    for (i = 0; i < 4; i++) {
      p_0 = 0.0;
      for (kidx = 0; kidx < 128; kidx++) {
        p_0 += b_this->M[394 * kidx + b_i1] * b_this->Phi[(i << 7) + kidx];
      }

      kidx = 394 * i + b_i1;
      b_this->Wcal0[kidx] = b_this->Mcal0[kidx] + p_0;
    }

    for (i = 0; i < 32; i++) {
      p_0 = 0.0;
      for (kidx = 0; kidx < 128; kidx++) {
        p_0 += b_this->M[394 * kidx + b_i1] * b_this->Gamma[(i << 7) + kidx];
      }

      kidx = 394 * i + b_i1;
      b_this->A0[kidx] = b_this->Sigma[kidx] + p_0;
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% Terminal Stage Constraint Matrices */
  /*  Set the terminal constraint for the MPC problem */
  /*  Default */
  /*  Construct terminal constraints based on sensor range and coasting */
  /*  this.is_eco */
  /* %% Assign MPC terminal sets     */
  /*  In MPC A = M Gamma + Sigma */
  /*  In MPC b = c - (Mcal0 + M Phi) x_0 - M GammaW W */
  /*  Terminal softening matrix */
  /*  Terminal integer matrix */
  /*  MPC terminal constraint matrices */
  /* %% Error check the setup */
  /* %% Check constraints */
  /*  Standard linear constraints */
  std::memcpy(&s_vary_ind[0], &b_this->upsi[0], 12U * sizeof(real_T));
  for (b_i1 = 0; b_i1 < 4; b_i1++) {
    xoffset = (b_i1 + 1) * 12 - 1;
    for (i = 0; i <= 10; i += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->upsi[(xoffset + i) + 1]);
      tmp = _mm_loadu_pd(&s_vary_ind[i]);
      _mm_storeu_pd(&s_vary_ind[i], _mm_add_pd(tmp_1, tmp));
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Softened constraints */
  /*  Chance constraints */
  /*  Binary constraints */
  /* %% Report */
  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  s_vary_ind_size[0] = 12;
  for (b_i1 = 0; b_i1 < 12; b_i1++) {
    s_vary_ind_data[b_i1] = (s_vary_ind[b_i1] > 1.0);
  }

  if (longitudinal_mpc_vectorAny(s_vary_ind_data, s_vary_ind_size)) {
    std::printf("%s\n",
                "Error: more than one slack variable detected in constraint.");
    std::fflush(stdout);
  }

  /*  Return */
  b_this->is_update_errored = false;

  /* %% Reset update flag */
  b_this->is_needs_update = false;
}

solver_longitudinal_mpc_T *longitudinal_mpc::longitudinal_mpc_solver_solver
  (solver_longitudinal_mpc_T *b_this)
{
  solver_longitudinal_mpc_T *c_this;

  /* Start for MATLABSystem: '<S1>/solver' */
  b_this->ego_state[0] = 0.0;
  b_this->ego_state[1] = 0.0;
  b_this->ego_state[2] = 0.0;
  b_this->ego_state[3] = 0.0;
  b_this->vel_des = 19.0;
  b_this->vel_max = 20.0;
  b_this->pos_max = 2000.0;
  b_this->is_eco = 0.0;
  b_this->d0 = 3.0;
  b_this->THref = 1.2;
  b_this->THsafe = 0.5;
  b_this->THmax = 10.0;
  b_this->qh = 1.0;
  b_this->qv = 0.5;
  b_this->qu = 3000.0;
  b_this->qdu = 0.0;
  b_this->dual_mode = 1.0;
  b_this->term_tracking_only = 0.0;
  b_this->alpha_proc = 0.9999;
  b_this->sigma_proc = 0.89;
  b_this->sigma_meas = 0.0;
  b_this->sigma_loca = 0.0;
  b_this->alpha_acceptance = 0.5;
  b_this->mean_acceptance = 5.415;
  b_this->scale_acceptance = 4.566;
  b_this->is_needs_update = true;

  /*  Constructor */
  c_this = b_this;
  b_this->isInitialized = 0;
  longitudin_PCCMPC_setParameters(b_this);
  longitudinal_mpc_PCCMPC_initMPC(b_this);
  longitudinal_m_PCCMPC_updateMPC(b_this);
  return c_this;
}

void longitudinal_mpc::longitudinal__solver_initSolver(solver_longitudinal_mpc_T
  *b_this)
{
  /* Start for MATLABSystem: '<S1>/solver' */
  std::printf("Initializing Solver\n");
  std::fflush(stdout);

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Properties */
  /*  Settings */
  /*  GETSETTINGS structure constructor */
  /*  Message importance for printing to terminal */
  /*  Solver verbosity 'on' or 'off' */
  /*  Standard settings */
  /*  1e-8 default */
  /*  Integral problem settings */
  /*  Number of branch and bound iterations - At most will need 2^n branches in a binary search */
  /*  Optimality tolerance on integer variables */
  /*  Optimality gap tolerance between dual and primal */
  /*  Default upper and lower bounds on integer variables */
  /*  Maximum number of nodes to expand in search tree - correlate this with coder.varsize 'leaves' dimension in solve() method */
  /*  Initialize solver */
  std::memset(&b_this->Xk[0], 0, 37U * sizeof(real_T));
  std::memset(&b_this->Xopt[0], 0, 37U * sizeof(real_T));
  b_this->J = (rtInf);
  b_this->flag = flags::UNSOLVED;
  b_this->iters = 0.0;

  /*  Error check */
}

void longitudinal_mpc::longitudinal_mpc_interp1(const real_T varargin_1[201],
  const real_T varargin_2[201], const real_T varargin_3[81], real_T Vq[81])
{
  real_T x[201];
  real_T y[201];
  int32_T i;
  std::memcpy(&y[0], &varargin_2[0], 201U * sizeof(real_T));
  std::memcpy(&x[0], &varargin_1[0], 201U * sizeof(real_T));
  for (i = 0; i < 81; i++) {
    Vq[i] = (rtNaN);
  }

  i = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (i < 201) {
      if (std::isnan(varargin_1[i])) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      real_T xtmp;
      if (varargin_1[1] < varargin_1[0]) {
        for (i = 0; i < 100; i++) {
          xtmp = x[i];
          x[i] = x[200 - i];
          x[200 - i] = xtmp;
          xtmp = y[i];
          y[i] = y[200 - i];
          y[200 - i] = xtmp;
        }
      }

      for (i = 0; i < 81; i++) {
        Vq[i] = (rtNaN);
        xtmp = varargin_3[i];
        if (std::isnan(xtmp)) {
          Vq[i] = (rtNaN);
        } else if ((!(xtmp > x[200])) && (!(xtmp < x[0]))) {
          int32_T high_i;
          int32_T low_i;
          int32_T low_ip1;
          low_i = 0;
          low_ip1 = 1;
          high_i = 201;
          while (high_i > low_ip1 + 1) {
            int32_T mid_i;
            mid_i = ((low_i + high_i) + 1) >> 1;
            if (varargin_3[i] >= x[mid_i - 1]) {
              low_i = mid_i - 1;
              low_ip1 = mid_i;
            } else {
              high_i = mid_i;
            }
          }

          xtmp = (varargin_3[i] - x[low_i]) / (x[low_i + 1] - x[low_i]);
          if (xtmp == 0.0) {
            Vq[i] = y[low_i];
          } else if (xtmp == 1.0) {
            Vq[i] = y[low_i + 1];
          } else {
            real_T tmp;
            tmp = y[low_i + 1];
            if (tmp == y[low_i]) {
              Vq[i] = y[low_i];
            } else {
              Vq[i] = (1.0 - xtmp) * y[low_i] + tmp * xtmp;
            }
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void longitudinal_mpc::longitudinal_mpc_pchip(const real_T x[81], const real_T
  y[81], real_T v_breaks[81], real_T v_coefs[320])
{
  __m128d tmp_3;
  real_T slopes[81];
  real_T del[80];
  real_T h[80];
  real_T u;
  real_T w1;
  real_T w2;
  for (int32_T b_k{0}; b_k <= 78; b_k += 2) {
    tmp_3 = _mm_sub_pd(_mm_loadu_pd(&x[b_k + 1]), _mm_loadu_pd(&x[b_k]));
    _mm_storeu_pd(&h[b_k], tmp_3);

    /* Start for MATLABSystem: '<S1>/solver' */
    _mm_storeu_pd(&del[b_k], _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&y[b_k + 1]),
      _mm_loadu_pd(&y[b_k])), tmp_3));
  }

  for (int32_T b_k{0}; b_k < 79; b_k++) {
    real_T del_0;
    real_T h_0;
    w2 = h[b_k + 1];
    h_0 = h[b_k];
    w1 = w2 * 2.0 + h_0;
    w2 += h_0 * 2.0;
    slopes[b_k + 1] = 0.0;

    /* Start for MATLABSystem: '<S1>/solver' */
    h_0 = del[b_k];
    del_0 = del[b_k + 1];
    u = h_0 * del_0;
    if (std::isnan(u)) {
      u = (rtNaN);
    } else if (u < 0.0) {
      u = -1.0;
    } else {
      u = (u > 0.0);
    }

    if (u > 0.0) {
      slopes[b_k + 1] = (w1 + w2) / (w1 / h_0 + w2 / del_0);
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  w1 = ((2.0 * h[0] + h[1]) * del[0] - h[0] * del[1]) / (h[0] + h[1]);
  if (std::isnan(del[0])) {
    w2 = (rtNaN);
  } else if (del[0] < 0.0) {
    w2 = -1.0;
  } else {
    w2 = (del[0] > 0.0);
  }

  if (std::isnan(w1)) {
    u = (rtNaN);
  } else if (w1 < 0.0) {
    u = -1.0;
  } else {
    u = (w1 > 0.0);
  }

  if (u != w2) {
    w1 = 0.0;
  } else {
    if (std::isnan(del[1])) {
      u = (rtNaN);
    } else if (del[1] < 0.0) {
      u = -1.0;
    } else {
      u = (del[1] > 0.0);
    }

    if ((w2 != u) && (std::abs(w1) > std::abs(3.0 * del[0]))) {
      w1 = 3.0 * del[0];
    }
  }

  slopes[0] = w1;

  /* Start for MATLABSystem: '<S1>/solver' */
  w1 = ((2.0 * h[79] + h[78]) * del[79] - del[78] * h[79]) / (h[78] + h[79]);
  if (std::isnan(del[79])) {
    w2 = (rtNaN);
  } else if (del[79] < 0.0) {
    w2 = -1.0;
  } else {
    w2 = (del[79] > 0.0);
  }

  if (std::isnan(w1)) {
    u = (rtNaN);
  } else if (w1 < 0.0) {
    u = -1.0;
  } else {
    u = (w1 > 0.0);
  }

  if (u != w2) {
    w1 = 0.0;
  } else {
    if (std::isnan(del[78])) {
      u = (rtNaN);
    } else if (del[78] < 0.0) {
      u = -1.0;
    } else {
      u = (del[78] > 0.0);
    }

    if ((w2 != u) && (std::abs(w1) > std::abs(3.0 * del[79]))) {
      w1 = 3.0 * del[79];
    }
  }

  slopes[80] = w1;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&v_breaks[0], &x[0], 81U * sizeof(real_T));
  for (int32_T b_k{0}; b_k <= 78; b_k += 2) {
    __m128d tmp;
    __m128d tmp_0;
    __m128d tmp_1;
    __m128d tmp_2;

    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_3 = _mm_loadu_pd(&del[b_k]);
    tmp = _mm_loadu_pd(&slopes[b_k]);
    tmp_0 = _mm_loadu_pd(&h[b_k]);
    tmp_1 = _mm_div_pd(_mm_sub_pd(tmp_3, tmp), tmp_0);

    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_2 = _mm_loadu_pd(&slopes[b_k + 1]);
    tmp_3 = _mm_div_pd(_mm_sub_pd(tmp_2, tmp_3), tmp_0);

    /* Start for MATLABSystem: '<S1>/solver' */
    _mm_storeu_pd(&v_coefs[b_k], _mm_div_pd(_mm_sub_pd(tmp_3, tmp_1), tmp_0));
    _mm_storeu_pd(&v_coefs[b_k + 80], _mm_sub_pd(_mm_mul_pd(_mm_set1_pd(2.0),
      tmp_1), tmp_3));
    _mm_storeu_pd(&v_coefs[b_k + 160], tmp);
    _mm_storeu_pd(&v_coefs[b_k + 240], _mm_loadu_pd(&y[b_k]));
  }
}

real_T longitudinal_mpc::longitudinal_mpc_ppval(const real_T pp_breaks[81],
  const real_T pp_coefs[320], real_T x)
{
  real_T v;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (std::isnan(x)) {
    v = (rtNaN);
  } else {
    int32_T high_i;
    int32_T low_i;
    int32_T low_ip1;
    low_i = 0;
    low_ip1 = 1;
    high_i = 81;
    while (high_i > low_ip1 + 1) {
      int32_T mid_i;
      mid_i = ((low_i + high_i) + 1) >> 1;
      if (x >= pp_breaks[mid_i - 1]) {
        low_i = mid_i - 1;
        low_ip1 = mid_i;
      } else {
        high_i = mid_i;
      }
    }

    real_T xloc;
    xloc = x - pp_breaks[low_i];
    v = ((xloc * pp_coefs[low_i] + pp_coefs[low_i + 80]) * xloc + pp_coefs[low_i
         + 160]) * xloc + pp_coefs[low_i + 240];
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return v;
}

void longitudinal_mpc::longitudinal_mpc_interp1_b4tv(const real_T varargin_1[81],
  const real_T varargin_2[81], const real_T varargin_3[33], real_T Vq[33])
{
  real_T pp_coefs[320];
  real_T pp_breaks[81];
  real_T x[81];
  real_T y[81];
  real_T xtmp;
  int32_T exitg1;
  int32_T i;
  std::memcpy(&y[0], &varargin_2[0], 81U * sizeof(real_T));
  std::memcpy(&x[0], &varargin_1[0], 81U * sizeof(real_T));
  std::memset(&Vq[0], 0, 33U * sizeof(real_T));
  i = 0;
  do {
    exitg1 = 0;
    if (i < 81) {
      if (std::isnan(varargin_1[i])) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      if (varargin_1[1] < varargin_1[0]) {
        for (i = 0; i < 40; i++) {
          xtmp = x[i];
          x[i] = x[80 - i];
          x[80 - i] = xtmp;
          xtmp = y[i];
          y[i] = y[80 - i];
          y[80 - i] = xtmp;
        }
      }

      longitudinal_mpc_pchip(x, y, pp_breaks, pp_coefs);
      for (i = 0; i < 33; i++) {
        Vq[i] = 0.0;
        xtmp = varargin_3[i];
        if (std::isnan(xtmp)) {
          Vq[i] = (rtNaN);
        } else {
          Vq[i] = longitudinal_mpc_ppval(pp_breaks, pp_coefs, xtmp);
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void longitudinal_mpc::longitudinal_mpc_interp1_b4(const real_T varargin_1[81],
  const real_T varargin_2[324], const real_T varargin_3[32], real_T Vq[128])
{
  real_T slopes[324];
  real_T yp[324];
  real_T del[320];
  real_T x[81];
  real_T h[80];
  real_T tmp_1[2];
  int32_T c1;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&slopes[0], &varargin_2[0], 324U * sizeof(real_T));
  std::memcpy(&x[0], &varargin_1[0], 81U * sizeof(real_T));
  std::memset(&Vq[0], 0, sizeof(real_T) << 7U);
  c1 = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (c1 < 81) {
      if (std::isnan(varargin_1[c1])) {
        exitg1 = 1;
      } else {
        c1++;
      }
    } else {
      __m128d tmp;
      __m128d tmp_0;
      real_T divdifij;
      real_T w2;
      real_T xtmp;
      real_T xtmp_tmp;
      real_T xtmp_tmp_0;
      real_T yit_idx_1;
      real_T yit_idx_3;
      int32_T c2;
      int32_T i;
      int32_T joffset;
      int32_T low_i;
      if (varargin_1[1] < varargin_1[0]) {
        for (joffset = 0; joffset < 40; joffset++) {
          xtmp = x[joffset];
          x[joffset] = x[80 - joffset];
          x[80 - joffset] = xtmp;
        }

        for (low_i = 0; low_i < 4; low_i++) {
          i = low_i * 81 - 1;
          for (c1 = 0; c1 < 40; c1++) {
            joffset = (c1 + i) + 1;
            xtmp = slopes[joffset];
            c2 = (i - c1) + 81;
            slopes[joffset] = slopes[c2];
            slopes[c2] = xtmp;
          }
        }
      }

      std::memset(&Vq[0], 0, sizeof(real_T) << 7U);
      for (i = 0; i < 81; i++) {
        joffset = i << 2;
        yp[joffset] = slopes[i];
        yp[joffset + 1] = slopes[i + 81];
        yp[joffset + 2] = slopes[i + 162];
        yp[joffset + 3] = slopes[i + 243];
      }

      for (c1 = 0; c1 <= 78; c1 += 2) {
        tmp = _mm_loadu_pd(&x[c1 + 1]);
        tmp_0 = _mm_loadu_pd(&x[c1]);
        _mm_storeu_pd(&h[c1], _mm_sub_pd(tmp, tmp_0));
      }

      for (joffset = 0; joffset <= 78; joffset += 2) {
        i = (joffset + 1) << 2;
        yit_idx_1 = yp[i];
        c1 = joffset << 2;
        low_i = (joffset + 2) << 2;
        tmp = _mm_div_pd(_mm_sub_pd(_mm_set_pd(yp[low_i], yit_idx_1), _mm_set_pd
          (yit_idx_1, yp[c1])), _mm_loadu_pd(&h[joffset]));
        _mm_storeu_pd(&tmp_1[0], tmp);
        del[c1] = tmp_1[0];
        del[i] = tmp_1[1];
        yit_idx_1 = yp[i + 1];
        tmp = _mm_div_pd(_mm_sub_pd(_mm_set_pd(yp[low_i + 1], yit_idx_1),
          _mm_set_pd(yit_idx_1, yp[c1 + 1])), _mm_loadu_pd(&h[joffset]));
        _mm_storeu_pd(&tmp_1[0], tmp);
        del[c1 + 1] = tmp_1[0];
        del[i + 1] = tmp_1[1];
        yit_idx_1 = yp[i + 2];
        tmp = _mm_div_pd(_mm_sub_pd(_mm_set_pd(yp[low_i + 2], yit_idx_1),
          _mm_set_pd(yit_idx_1, yp[c1 + 2])), _mm_loadu_pd(&h[joffset]));
        _mm_storeu_pd(&tmp_1[0], tmp);
        del[c1 + 2] = tmp_1[0];
        del[i + 2] = tmp_1[1];
        yit_idx_1 = yp[i + 3];
        tmp = _mm_div_pd(_mm_sub_pd(_mm_set_pd(yp[low_i + 3], yit_idx_1),
          _mm_set_pd(yit_idx_1, yp[c1 + 3])), _mm_loadu_pd(&h[joffset]));
        _mm_storeu_pd(&tmp_1[0], tmp);
        del[c1 + 3] = tmp_1[0];
        del[i + 3] = tmp_1[1];
      }

      for (i = 0; i < 79; i++) {
        w2 = h[i + 1];
        yit_idx_1 = h[i];
        xtmp = w2 * 2.0 + yit_idx_1;
        w2 += 2.0 * yit_idx_1;
        c1 = (i << 2) - 1;
        c2 = ((i + 1) << 2) - 1;
        divdifij = del[c1 + 1];
        yit_idx_3 = del[c2 + 1];
        slopes[c2 + 1] = 0.0;
        yit_idx_1 = divdifij * yit_idx_3;
        if (std::isnan(yit_idx_1)) {
          yit_idx_1 = (rtNaN);
        } else if (yit_idx_1 < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (yit_idx_1 > 0.0);
        }

        if (yit_idx_1 > 0.0) {
          slopes[c2 + 1] = (xtmp + w2) / (xtmp / divdifij + w2 / yit_idx_3);
        }

        divdifij = del[c1 + 2];
        yit_idx_3 = del[c2 + 2];
        slopes[c2 + 2] = 0.0;
        yit_idx_1 = divdifij * yit_idx_3;
        if (std::isnan(yit_idx_1)) {
          yit_idx_1 = (rtNaN);
        } else if (yit_idx_1 < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (yit_idx_1 > 0.0);
        }

        if (yit_idx_1 > 0.0) {
          slopes[c2 + 2] = (xtmp + w2) / (xtmp / divdifij + w2 / yit_idx_3);
        }

        divdifij = del[c1 + 3];
        yit_idx_3 = del[c2 + 3];
        slopes[c2 + 3] = 0.0;
        yit_idx_1 = divdifij * yit_idx_3;
        if (std::isnan(yit_idx_1)) {
          yit_idx_1 = (rtNaN);
        } else if (yit_idx_1 < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (yit_idx_1 > 0.0);
        }

        if (yit_idx_1 > 0.0) {
          slopes[c2 + 3] = (xtmp + w2) / (xtmp / divdifij + w2 / yit_idx_3);
        }

        divdifij = del[c1 + 4];
        yit_idx_3 = del[c2 + 4];
        slopes[c2 + 4] = 0.0;
        yit_idx_1 = divdifij * yit_idx_3;
        if (std::isnan(yit_idx_1)) {
          yit_idx_1 = (rtNaN);
        } else if (yit_idx_1 < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (yit_idx_1 > 0.0);
        }

        if (yit_idx_1 > 0.0) {
          slopes[c2 + 4] = (xtmp + w2) / (xtmp / divdifij + w2 / yit_idx_3);
        }
      }

      divdifij = 2.0 * h[0] + h[1];
      yit_idx_3 = h[0] + h[1];
      xtmp = (divdifij * del[0] - h[0] * del[4]) / yit_idx_3;
      if (std::isnan(del[0])) {
        w2 = (rtNaN);
      } else if (del[0] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[0] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[4])) {
          yit_idx_1 = (rtNaN);
        } else if (del[4] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[4] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[0]))) {
          xtmp = 3.0 * del[0];
        }
      }

      slopes[0] = xtmp;
      xtmp_tmp = 2.0 * h[79] + h[78];
      xtmp_tmp_0 = h[78] + h[79];
      xtmp = (xtmp_tmp * del[316] - h[79] * del[312]) / xtmp_tmp_0;
      if (std::isnan(del[316])) {
        w2 = (rtNaN);
      } else if (del[316] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[316] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[312])) {
          yit_idx_1 = (rtNaN);
        } else if (del[312] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[312] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[316]))) {
          xtmp = 3.0 * del[316];
        }
      }

      slopes[320] = xtmp;
      xtmp = (divdifij * del[1] - h[0] * del[5]) / yit_idx_3;
      if (std::isnan(del[1])) {
        w2 = (rtNaN);
      } else if (del[1] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[1] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[5])) {
          yit_idx_1 = (rtNaN);
        } else if (del[5] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[5] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[1]))) {
          xtmp = 3.0 * del[1];
        }
      }

      slopes[1] = xtmp;
      xtmp = (xtmp_tmp * del[317] - h[79] * del[313]) / xtmp_tmp_0;
      if (std::isnan(del[317])) {
        w2 = (rtNaN);
      } else if (del[317] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[317] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[313])) {
          yit_idx_1 = (rtNaN);
        } else if (del[313] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[313] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[317]))) {
          xtmp = 3.0 * del[317];
        }
      }

      slopes[321] = xtmp;
      xtmp = (divdifij * del[2] - h[0] * del[6]) / yit_idx_3;
      if (std::isnan(del[2])) {
        w2 = (rtNaN);
      } else if (del[2] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[2] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[6])) {
          yit_idx_1 = (rtNaN);
        } else if (del[6] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[6] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[2]))) {
          xtmp = 3.0 * del[2];
        }
      }

      slopes[2] = xtmp;
      xtmp = (xtmp_tmp * del[318] - h[79] * del[314]) / xtmp_tmp_0;
      if (std::isnan(del[318])) {
        w2 = (rtNaN);
      } else if (del[318] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[318] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[314])) {
          yit_idx_1 = (rtNaN);
        } else if (del[314] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[314] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[318]))) {
          xtmp = 3.0 * del[318];
        }
      }

      slopes[322] = xtmp;
      xtmp = (divdifij * del[3] - h[0] * del[7]) / yit_idx_3;
      if (std::isnan(del[3])) {
        w2 = (rtNaN);
      } else if (del[3] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[3] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[7])) {
          yit_idx_1 = (rtNaN);
        } else if (del[7] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[7] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[3]))) {
          xtmp = 3.0 * del[3];
        }
      }

      slopes[3] = xtmp;
      xtmp = (xtmp_tmp * del[319] - h[79] * del[315]) / xtmp_tmp_0;
      if (std::isnan(del[319])) {
        w2 = (rtNaN);
      } else if (del[319] < 0.0) {
        w2 = -1.0;
      } else {
        w2 = (del[319] > 0.0);
      }

      if (std::isnan(xtmp)) {
        yit_idx_1 = (rtNaN);
      } else if (xtmp < 0.0) {
        yit_idx_1 = -1.0;
      } else {
        yit_idx_1 = (xtmp > 0.0);
      }

      if (yit_idx_1 != w2) {
        xtmp = 0.0;
      } else {
        if (std::isnan(del[315])) {
          yit_idx_1 = (rtNaN);
        } else if (del[315] < 0.0) {
          yit_idx_1 = -1.0;
        } else {
          yit_idx_1 = (del[315] > 0.0);
        }

        if ((w2 != yit_idx_1) && (std::abs(xtmp) > std::abs(3.0 * del[319]))) {
          xtmp = 3.0 * del[319];
        }
      }

      slopes[323] = xtmp;
      for (i = 0; i < 80; i++) {
        joffset = (i << 2) - 1;
        divdifij = del[joffset + 1];
        xtmp = slopes[joffset + 1];
        w2 = (divdifij - xtmp) / h[i];
        divdifij = (slopes[joffset + 5] - divdifij) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 1] = (divdifij - w2) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 321] = 2.0 * w2 - divdifij;
        longitudinal_mpc_B.pp_coefs[joffset + 641] = xtmp;
        longitudinal_mpc_B.pp_coefs[joffset + 961] = yp[joffset + 1];
        divdifij = del[joffset + 2];
        xtmp = slopes[joffset + 2];
        w2 = (divdifij - xtmp) / h[i];
        divdifij = (slopes[joffset + 6] - divdifij) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 2] = (divdifij - w2) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 322] = 2.0 * w2 - divdifij;
        longitudinal_mpc_B.pp_coefs[joffset + 642] = xtmp;
        longitudinal_mpc_B.pp_coefs[joffset + 962] = yp[joffset + 2];
        divdifij = del[joffset + 3];
        xtmp = slopes[joffset + 3];
        w2 = (divdifij - xtmp) / h[i];
        divdifij = (slopes[joffset + 7] - divdifij) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 3] = (divdifij - w2) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 323] = 2.0 * w2 - divdifij;
        longitudinal_mpc_B.pp_coefs[joffset + 643] = xtmp;
        longitudinal_mpc_B.pp_coefs[joffset + 963] = yp[joffset + 3];
        divdifij = del[joffset + 4];
        xtmp = slopes[joffset + 4];
        w2 = (divdifij - xtmp) / h[i];
        divdifij = (slopes[joffset + 8] - divdifij) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 4] = (divdifij - w2) / h[i];
        longitudinal_mpc_B.pp_coefs[joffset + 324] = 2.0 * w2 - divdifij;
        longitudinal_mpc_B.pp_coefs[joffset + 644] = xtmp;
        longitudinal_mpc_B.pp_coefs[joffset + 964] = yp[joffset + 4];
      }

      for (c1 = 0; c1 < 32; c1++) {
        xtmp = varargin_3[c1];
        if (std::isnan(xtmp)) {
          Vq[c1] = (rtNaN);
          Vq[c1 + 32] = (rtNaN);
          Vq[c1 + 64] = (rtNaN);
          Vq[c1 + 96] = (rtNaN);
        } else {
          low_i = 0;
          i = 1;
          c2 = 81;
          while (c2 > i + 1) {
            joffset = ((low_i + c2) + 1) >> 1;
            if (xtmp >= x[joffset - 1]) {
              low_i = joffset - 1;
              i = joffset;
            } else {
              c2 = joffset;
            }
          }

          i = low_i << 2;
          xtmp = varargin_3[c1] - x[low_i];
          w2 = longitudinal_mpc_B.pp_coefs[i];
          yit_idx_1 = longitudinal_mpc_B.pp_coefs[i + 1];
          divdifij = longitudinal_mpc_B.pp_coefs[i + 2];
          yit_idx_3 = longitudinal_mpc_B.pp_coefs[i + 3];
          for (joffset = 0; joffset < 3; joffset++) {
            low_i = ((joffset + 1) * 320 + i) - 1;
            tmp = _mm_set1_pd(xtmp);
            tmp_0 = _mm_add_pd(_mm_mul_pd(tmp, _mm_set_pd(yit_idx_1, w2)),
                               _mm_loadu_pd(&longitudinal_mpc_B.pp_coefs[low_i +
              1]));
            _mm_storeu_pd(&tmp_1[0], tmp_0);
            w2 = tmp_1[0];
            yit_idx_1 = tmp_1[1];
            tmp = _mm_add_pd(_mm_mul_pd(tmp, _mm_set_pd(yit_idx_3, divdifij)),
                             _mm_loadu_pd(&longitudinal_mpc_B.pp_coefs[low_i + 3]));
            _mm_storeu_pd(&tmp_1[0], tmp);
            divdifij = tmp_1[0];
            yit_idx_3 = tmp_1[1];
          }

          Vq[c1] = w2;
          Vq[c1 + 32] = yit_idx_1;
          Vq[c1 + 64] = divdifij;
          Vq[c1 + 96] = yit_idx_3;
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void longitudinal_mpc::longitudinal_mpc_interp1_b4t(const real_T varargin_1[81],
  const real_T varargin_2[81], const real_T varargin_3[32], real_T Vq[32])
{
  real_T pp_coefs[320];
  real_T pp_breaks[81];
  real_T x[81];
  real_T y[81];
  real_T xtmp;
  int32_T exitg1;
  int32_T i;
  std::memcpy(&y[0], &varargin_2[0], 81U * sizeof(real_T));
  std::memcpy(&x[0], &varargin_1[0], 81U * sizeof(real_T));
  std::memset(&Vq[0], 0, sizeof(real_T) << 5U);
  i = 0;
  do {
    exitg1 = 0;
    if (i < 81) {
      if (std::isnan(varargin_1[i])) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      if (varargin_1[1] < varargin_1[0]) {
        for (i = 0; i < 40; i++) {
          xtmp = x[i];
          x[i] = x[80 - i];
          x[80 - i] = xtmp;
          xtmp = y[i];
          y[i] = y[80 - i];
          y[80 - i] = xtmp;
        }
      }

      longitudinal_mpc_pchip(x, y, pp_breaks, pp_coefs);
      for (i = 0; i < 32; i++) {
        Vq[i] = 0.0;
        xtmp = varargin_3[i];
        if (std::isnan(xtmp)) {
          Vq[i] = (rtNaN);
        } else {
          Vq[i] = longitudinal_mpc_ppval(pp_breaks, pp_coefs, xtmp);
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void longitudinal_mpc::longitudinal_m_factoryConstruct
  (sSQjeS6UA6ous3QrgyAXHyC_longi_T *obj)
{
  obj->ldm = 38;
  obj->ndims = 0;
  obj->info = 0;
  obj->scaleFactor = 1.0;
  obj->ConvexCheck = true;
  obj->regTol_ = 0.0;
}

void longitudinal_mpc::longitudinal_mpc_compressBounds(int32_T indexLB[38],
  int32_T indexUB[38], int32_T indexFixed[38], const real_T ub[37], int32_T *mLB,
  int32_T *mUB, int32_T *mFixed)
{
  static const int8_T lb[37]{ -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
    -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
    0, 0, 0, 0, 0 };

  /* Start for MATLABSystem: '<S1>/solver' */
  *mLB = 0;
  *mUB = 0;
  *mFixed = 0;
  for (int32_T b_idx{0}; b_idx < 37; b_idx++) {
    real_T ub_0;
    ub_0 = ub[b_idx];
    if (std::abs(static_cast<real_T>(lb[b_idx]) - ub_0) < 1.0E-5) {
      (*mFixed)++;
      indexFixed[*mFixed - 1] = b_idx + 1;
    } else {
      (*mLB)++;
      indexLB[*mLB - 1] = b_idx + 1;
      if ((!std::isinf(ub_0)) && (!std::isnan(ub_0))) {
        (*mUB)++;
        indexUB[*mUB - 1] = b_idx + 1;
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_loadProblem(const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, const real_T Aineq[14763], const real_T
  bineq[399], int32_T mLB, int32_T mUB, const real_T ub[37], int32_T mFixed,
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_obj)
{
  int32_T i;
  static const int8_T lb[37]{ -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
    -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
    0, 0, 0, 0, 0 };

  *b_obj = *obj;
  i = ((mLB + mUB) + mFixed) + 399;
  b_obj->mConstr = i;
  b_obj->mConstrOrig = i;
  b_obj->mConstrMax = 474;

  /* Start for MATLABSystem: '<S1>/solver' */
  b_obj->sizes[0] = mFixed;
  b_obj->sizes[1] = 0;
  b_obj->sizes[2] = 399;
  b_obj->sizes[3] = mLB;
  b_obj->sizes[4] = mUB;
  for (i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_obj->sizesNormal[i] = b_obj->sizes[i];
  }

  b_obj->sizesPhaseOne[0] = mFixed;
  b_obj->sizesPhaseOne[1] = 0;
  b_obj->sizesPhaseOne[2] = 399;
  b_obj->sizesPhaseOne[3] = mLB + 1;
  b_obj->sizesPhaseOne[4] = mUB;
  b_obj->sizesRegularized[0] = mFixed;
  b_obj->sizesRegularized[1] = 0;
  b_obj->sizesRegularized[2] = 399;
  b_obj->sizesRegularized[3] = mLB + 399;
  b_obj->sizesRegularized[4] = mUB;
  b_obj->sizesRegPhaseOne[0] = mFixed;
  b_obj->sizesRegPhaseOne[1] = 0;
  b_obj->sizesRegPhaseOne[2] = 399;
  b_obj->sizesRegPhaseOne[3] = mLB + 400;
  b_obj->sizesRegPhaseOne[4] = mUB;

  /* Start for MATLABSystem: '<S1>/solver' */
  b_obj->isActiveIdxNormal[0] = 1;
  b_obj->isActiveIdxNormal[1] = mFixed;
  b_obj->isActiveIdxNormal[2] = 0;
  b_obj->isActiveIdxNormal[3] = 399;
  b_obj->isActiveIdxNormal[4] = mLB;
  b_obj->isActiveIdxNormal[5] = mUB;
  for (i = 0; i < 6; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_obj->isActiveIdxRegPhaseOne[i] = b_obj->isActiveIdxNormal[i];
  }

  for (i = 0; i < 5; i++) {
    b_obj->isActiveIdxRegPhaseOne[i + 1] += b_obj->isActiveIdxRegPhaseOne[i];
  }

  for (i = 0; i < 6; i++) {
    b_obj->isActiveIdx[i] = b_obj->isActiveIdxRegPhaseOne[i];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  b_obj->isActiveIdxRegPhaseOne[0] = 1;
  b_obj->isActiveIdxRegPhaseOne[1] = mFixed;
  b_obj->isActiveIdxRegPhaseOne[2] = 0;
  b_obj->isActiveIdxRegPhaseOne[3] = 399;
  b_obj->isActiveIdxRegPhaseOne[4] = mLB + 1;
  b_obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    b_obj->isActiveIdxNormal[i + 1] += b_obj->isActiveIdxNormal[i];
    b_obj->isActiveIdxRegPhaseOne[i + 1] += b_obj->isActiveIdxRegPhaseOne[i];
  }

  for (i = 0; i < 6; i++) {
    b_obj->isActiveIdxPhaseOne[i] = b_obj->isActiveIdxRegPhaseOne[i];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  b_obj->isActiveIdxRegPhaseOne[0] = 1;
  b_obj->isActiveIdxRegPhaseOne[1] = mFixed;
  b_obj->isActiveIdxRegPhaseOne[2] = 0;
  b_obj->isActiveIdxRegPhaseOne[3] = 399;
  b_obj->isActiveIdxRegPhaseOne[4] = mLB + 399;
  b_obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    b_obj->isActiveIdxRegPhaseOne[i + 1] += b_obj->isActiveIdxRegPhaseOne[i];
  }

  for (i = 0; i < 6; i++) {
    b_obj->isActiveIdxRegularized[i] = b_obj->isActiveIdxRegPhaseOne[i];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  b_obj->isActiveIdxRegPhaseOne[0] = 1;
  b_obj->isActiveIdxRegPhaseOne[1] = mFixed;
  b_obj->isActiveIdxRegPhaseOne[2] = 0;
  b_obj->isActiveIdxRegPhaseOne[3] = 399;
  b_obj->isActiveIdxRegPhaseOne[4] = mLB + 400;
  b_obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (i = 0; i < 5; i++) {
    b_obj->isActiveIdxRegPhaseOne[i + 1] += b_obj->isActiveIdxRegPhaseOne[i];
  }

  for (i = 0; i < 399; i++) {
    for (int32_T b_idx_row{0}; b_idx_row < 37; b_idx_row++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      b_obj->Aineq[b_idx_row + 38 * i] = Aineq[399 * b_idx_row + i];
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    b_obj->bineq[i] = bineq[i];
  }

  for (i = 0; i < 37; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_obj->lb[i] = -static_cast<real_T>(lb[i]);
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&b_obj->ub[0], &obj->ub[0], 38U * sizeof(real_T));
  std::memcpy(&b_obj->ub[0], &ub[0], 37U * sizeof(real_T));
}

void longitudinal_mpc::longitu_modifyOverheadPhaseOne_
  (svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj)
{
  int32_T d;
  int32_T idxStartIneq;

  /* Start for MATLABSystem: '<S1>/solver' */
  idxStartIneq = static_cast<uint8_T>(obj->sizes[0]) - 1;
  for (int32_T b_idx{0}; b_idx <= idxStartIneq; b_idx++) {
    obj->ATwset[38 * b_idx + 37] = 0.0;
  }

  for (int32_T b_idx{0}; b_idx < 399; b_idx++) {
    obj->Aineq[38 * b_idx + 37] = -1.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = 38;
  obj->lb[37] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  d = obj->nActiveConstr;
  for (int32_T b_idx{idxStartIneq}; b_idx <= d; b_idx++) {
    obj->ATwset[38 * (b_idx - 1) + 37] = -1.0;
  }

  idxStartIneq = obj->isActiveIdx[4] - 2;
  if (obj->nWConstr[4] > 0) {
    d = obj->sizesNormal[4];
    for (int32_T b_idx{d - 1}; b_idx >= 0; b_idx--) {
      int32_T tmp;
      tmp = idxStartIneq + b_idx;
      obj->isActiveConstr[tmp + 1] = obj->isActiveConstr[tmp];
    }
  } else {
    obj->isActiveConstr[(obj->isActiveIdx[4] + obj->sizesNormal[4]) - 1] = false;
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_setProblemType
  (svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, int32_T PROBLEM_TYPE)
{
  int32_T b_idx;
  int32_T idxStartIneq;
  int32_T idxUpperExisting;
  int32_T idx_lb;
  int32_T j_tmp;

  /* Start for MATLABSystem: '<S1>/solver' */
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 37;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      idxUpperExisting = obj->isActiveIdx[4] - 2;
      idxStartIneq = static_cast<uint8_T>(obj->sizesNormal[4]) - 1;
      for (b_idx = 0; b_idx <= idxStartIneq; b_idx++) {
        idx_lb = (b_idx + idxUpperExisting) + 1;
        obj->isActiveConstr[(obj->isActiveIdxNormal[4] + b_idx) - 1] =
          obj->isActiveConstr[idx_lb];
        obj->isActiveConstr[idx_lb] = false;
      }
    }

    for (idx_lb = 0; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesNormal[idx_lb];
    }

    for (idx_lb = 0; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxNormal[idx_lb];
    }
    break;

   case 1:
    obj->nVar = 38;
    obj->mConstr = obj->mConstrOrig + 1;
    for (idx_lb = 0; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesPhaseOne[idx_lb];
    }

    longitu_modifyOverheadPhaseOne_(obj);
    for (idx_lb = 0; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxPhaseOne[idx_lb];
    }
    break;

   case 2:
    obj->nVar = 37;
    obj->mConstr = 473;
    for (idx_lb = 0; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesRegularized[idx_lb];
    }

    if (obj->probType != 4) {
      for (b_idx = 0; b_idx < 399; b_idx++) {
        idxUpperExisting = 38 * b_idx - 1;
        for (idxStartIneq = 38; idxStartIneq <= b_idx + 37; idxStartIneq++) {
          obj->Aineq[idxStartIneq + idxUpperExisting] = 0.0;
        }

        obj->Aineq[(b_idx + idxUpperExisting) + 38] = -1.0;
      }

      idx_lb = 37;
      idxStartIneq = obj->sizesNormal[3];
      idxUpperExisting = obj->sizesRegularized[3];
      for (b_idx = idxStartIneq + 1; b_idx <= idxUpperExisting; b_idx++) {
        idx_lb++;
        obj->indexLB[b_idx - 1] = idx_lb;
      }

      if (obj->nWConstr[4] > 0) {
        idxStartIneq = static_cast<uint8_T>(obj->sizesRegularized[4]) - 1;
        for (b_idx = 0; b_idx <= idxStartIneq; b_idx++) {
          obj->isActiveConstr[obj->isActiveIdxRegularized[4] + b_idx] =
            obj->isActiveConstr[(obj->isActiveIdx[4] + b_idx) - 1];
        }
      }

      idxStartIneq = obj->isActiveIdx[4];
      idx_lb = obj->isActiveIdxRegularized[4];
      if (idxStartIneq <= idx_lb - 1) {
        std::memset(&obj->isActiveConstr[idxStartIneq + -1], 0,
                    static_cast<uint32_T>(idx_lb - idxStartIneq) * sizeof
                    (boolean_T));
      }

      obj->lb[37] = 0.0;
      idxStartIneq = obj->isActiveIdx[2];
      idx_lb = obj->nActiveConstr;
      for (b_idx = idxStartIneq; b_idx <= idx_lb; b_idx++) {
        idxUpperExisting = (b_idx - 1) * 38 - 1;
        if (obj->Wid[b_idx - 1] == 3) {
          j_tmp = obj->Wlocalidx[b_idx - 1];
          if (j_tmp + 36 >= 38) {
            std::memset(&obj->ATwset[idxUpperExisting + 38], 0,
                        static_cast<uint32_T>(((j_tmp + idxUpperExisting) -
              idxUpperExisting) - 1) * sizeof(real_T));
          }

          obj->ATwset[(j_tmp + idxUpperExisting) + 37] = -1.0;
          if (j_tmp + 38 <= 37) {
            std::memset(&obj->ATwset[(j_tmp + idxUpperExisting) + 38], 0,
                        static_cast<uint32_T>((idxUpperExisting - j_tmp) -
              idxUpperExisting) * sizeof(real_T));
          }
        }
      }
    }

    for (idx_lb = 0; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxRegularized[idx_lb];
    }
    break;

   default:
    obj->nVar = 38;
    obj->mConstr = 474;
    for (idx_lb = 0; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesRegPhaseOne[idx_lb];
    }

    longitu_modifyOverheadPhaseOne_(obj);
    for (idx_lb = 0; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxRegPhaseOne[idx_lb];
    }
    break;
  }

  obj->probType = PROBLEM_TYPE;

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

real_T longitudinal_mpc::longitudinal_mpc_xnrm2_b(int32_T n, const real_T x
  [18012], int32_T ix0)
{
  real_T y;
  y = 0.0;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int32_T k{ix0}; k < kend; k++) {
        real_T absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return y;
}

void longitudinal_mpc::longitudinal_mpc_xzlarfg(int32_T n, real_T alpha1, real_T
  x[18012], int32_T ix0, real_T *b_alpha1, real_T *tau)
{
  __m128d tmp;
  real_T beta1;
  int32_T k;
  int32_T knt;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vectorUB_tmp;

  /* Start for MATLABSystem: '<S1>/solver' */
  *b_alpha1 = alpha1;
  *tau = 0.0;
  if (n > 0) {
    beta1 = longitudinal_mpc_xnrm2_b(n - 1, x, ix0);
    if (beta1 != 0.0) {
      beta1 = rt_hypotd_snf(alpha1, beta1);
      if (alpha1 >= 0.0) {
        beta1 = -beta1;
      }

      if (std::abs(beta1) < 1.0020841800044864E-292) {
        knt = -1;
        do {
          knt++;
          scalarLB = ix0 + n;
          vectorUB = ((((scalarLB - ix0) - 1) / 2) << 1) + ix0;
          vectorUB_tmp = vectorUB - 2;
          for (k = ix0; k <= vectorUB_tmp; k += 2) {
            tmp = _mm_loadu_pd(&x[k - 1]);
            _mm_storeu_pd(&x[k - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (k = vectorUB; k <= scalarLB - 2; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          *b_alpha1 *= 9.9792015476736E+291;
        } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt + 1 < 20));

        beta1 = rt_hypotd_snf(*b_alpha1, longitudinal_mpc_xnrm2_b(n - 1, x, ix0));
        if (*b_alpha1 >= 0.0) {
          beta1 = -beta1;
        }

        *tau = (beta1 - *b_alpha1) / beta1;
        *b_alpha1 = 1.0 / (*b_alpha1 - beta1);
        for (k = ix0; k <= vectorUB_tmp; k += 2) {
          tmp = _mm_loadu_pd(&x[k - 1]);
          _mm_storeu_pd(&x[k - 1], _mm_mul_pd(tmp, _mm_set1_pd(*b_alpha1)));
        }

        for (k = vectorUB; k <= scalarLB - 2; k++) {
          x[k - 1] *= *b_alpha1;
        }

        for (k = 0; k <= knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }

        *b_alpha1 = beta1;
      } else {
        *tau = (beta1 - alpha1) / beta1;
        *b_alpha1 = 1.0 / (alpha1 - beta1);
        knt = ix0 + n;
        scalarLB = ((((knt - ix0) - 1) / 2) << 1) + ix0;
        vectorUB = scalarLB - 2;
        for (k = ix0; k <= vectorUB; k += 2) {
          tmp = _mm_loadu_pd(&x[k - 1]);
          _mm_storeu_pd(&x[k - 1], _mm_mul_pd(tmp, _mm_set1_pd(*b_alpha1)));
        }

        for (k = scalarLB; k <= knt - 2; k++) {
          x[k - 1] *= *b_alpha1;
        }

        *b_alpha1 = beta1;
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xzlarf(int32_T m, int32_T n, int32_T iv0,
  real_T tau, real_T C[18012], int32_T ic0, real_T work[474])
{
  int32_T coltop;
  int32_T ia;
  int32_T lastc;
  int32_T lastv;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = (iv0 + m) - 2;
    while ((lastv > 0) && (C[lastc] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n - 1;
    exitg2 = false;
    while ((!exitg2) && (lastc + 1 > 0)) {
      int32_T exitg1;
      coltop = lastc * 38 + ic0;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= (coltop + lastv) - 1) {
          if (C[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = -1;
  }

  if (lastv > 0) {
    real_T c;
    int32_T jy;
    if (lastc + 1 != 0) {
      if (lastc >= 0) {
        std::memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof
                    (real_T));
      }

      coltop = 38 * lastc + ic0;
      for (int32_T iac{ic0}; iac <= coltop; iac += 38) {
        c = 0.0;
        jy = iac + lastv;
        for (ia = iac; ia < jy; ia++) {
          c += C[((iv0 + ia) - iac) - 1] * C[ia - 1];
        }

        ia = div_nde_s32_floor(iac - ic0, 38);
        work[ia] += c;
      }
    }

    if (!(-tau == 0.0)) {
      coltop = ic0;
      for (ia = 0; ia <= lastc; ia++) {
        c = work[ia];
        if (c != 0.0) {
          c *= -tau;
          jy = (lastv + coltop) - 1;
          for (int32_T iac{coltop}; iac <= jy; iac++) {
            C[iac - 1] += C[((iv0 + iac) - coltop) - 1] * c;
          }
        }

        coltop += 38;
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_qrf(real_T A[18012], int32_T m, int32_T
  n, int32_T nfxd, real_T tau[38])
{
  real_T work[474];
  real_T b_atmp;
  int32_T c;
  int32_T i;
  int32_T ii;
  int32_T mmi;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memset(&work[0], 0, 474U * sizeof(real_T));
  c = static_cast<uint16_T>(nfxd) - 1;
  for (i = 0; i <= c; i++) {
    ii = i * 38 + i;
    mmi = m - i;
    if (i + 1 < m) {
      longitudinal_mpc_xzlarfg(mmi, A[ii], A, ii + 2, &b_atmp, &tau[i]);
      A[ii] = b_atmp;
    } else {
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      longitudinal_mpc_xzlarf(mmi, (n - i) - 1, ii + 1, tau[i], A, ii + 39, work);
      A[ii] = b_atmp;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xgeqp3_b(real_T A[18012], int32_T m,
  int32_T n, int32_T jpvt[474], real_T tau[38])
{
  real_T vn1[474];
  real_T vn2[474];
  real_T work[474];
  real_T s;
  real_T t;
  real_T temp;
  real_T vn1_0;
  int32_T i;
  int32_T ii;
  int32_T ip1;
  int32_T itemp;
  int32_T iy;
  int32_T minmn_tmp;
  int32_T mmi;
  int32_T nfxd;
  int32_T nmi;
  int32_T pvt;
  static const int32_T offsets[4]{ 0, 1, 2, 3 };

  int32_T temp_tmp;
  int32_T tmp;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (m <= n) {
    minmn_tmp = m;
  } else {
    minmn_tmp = n;
  }

  std::memset(&tau[0], 0, 38U * sizeof(real_T));
  if (minmn_tmp < 1) {
    /* Start for MATLABSystem: '<S1>/solver' */
    nfxd = (n / 4) << 2;
    itemp = nfxd - 4;
    for (i = 0; i <= itemp; i += 4) {
      _mm_storeu_si128((__m128i *)&jpvt[i], _mm_add_epi32(_mm_add_epi32
        (_mm_set1_epi32(i), _mm_loadu_si128((const __m128i *)&offsets[0])),
        _mm_set1_epi32(1)));
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    for (i = nfxd; i < n; i++) {
      jpvt[i] = i + 1;
    }
  } else {
    /* Start for MATLABSystem: '<S1>/solver' */
    nfxd = -1;
    for (ip1 = 0; ip1 < n; ip1++) {
      if (jpvt[ip1] != 0) {
        nfxd++;
        if (ip1 + 1 != nfxd + 1) {
          i = ip1 * 38;
          iy = nfxd * 38;
          for (itemp = 0; itemp < m; itemp++) {
            temp_tmp = i + itemp;
            temp = A[temp_tmp];
            tmp = iy + itemp;
            A[temp_tmp] = A[tmp];
            A[tmp] = temp;
          }

          jpvt[ip1] = jpvt[nfxd];
          jpvt[nfxd] = ip1 + 1;
        } else {
          jpvt[ip1] = ip1 + 1;
        }
      } else {
        jpvt[ip1] = ip1 + 1;
      }
    }

    if (nfxd + 1 <= minmn_tmp) {
      nfxd++;
    } else {
      nfxd = minmn_tmp;
    }

    std::memset(&tau[0], 0, 38U * sizeof(real_T));
    longitudinal_mpc_qrf(A, m, n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      std::memset(&work[0], 0, 474U * sizeof(real_T));
      std::memset(&vn1[0], 0, 474U * sizeof(real_T));
      std::memset(&vn2[0], 0, 474U * sizeof(real_T));

      /* Start for MATLABSystem: '<S1>/solver' */
      for (ip1 = nfxd + 1; ip1 <= n; ip1++) {
        vn1_0 = longitudinal_mpc_xnrm2_b(m - nfxd, A, ((ip1 - 1) * 38 + nfxd) +
          1);
        vn1[ip1 - 1] = vn1_0;
        vn2[ip1 - 1] = vn1_0;
      }

      ip1 = nfxd;
      for (nfxd = ip1 + 1; nfxd <= minmn_tmp; nfxd++) {
        /* Start for MATLABSystem: '<S1>/solver' */
        iy = (nfxd - 1) * 38;
        ii = (iy + nfxd) - 1;
        nmi = (n - nfxd) + 1;
        mmi = m - nfxd;
        if (nmi < 1) {
          pvt = -1;
        } else {
          pvt = 0;
          if (nmi > 1) {
            temp = std::abs(vn1[nfxd - 1]);
            for (itemp = 2; itemp <= nmi; itemp++) {
              s = std::abs(vn1[(nfxd + itemp) - 2]);
              if (s > temp) {
                pvt = itemp - 1;
                temp = s;
              }
            }
          }
        }

        pvt = (nfxd + pvt) - 1;
        if (pvt + 1 != nfxd) {
          i = pvt * 38;
          for (itemp = 0; itemp < m; itemp++) {
            temp_tmp = i + itemp;
            temp = A[temp_tmp];
            tmp = iy + itemp;
            A[temp_tmp] = A[tmp];
            A[tmp] = temp;
          }

          itemp = jpvt[pvt];
          jpvt[pvt] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = itemp;
          vn1[pvt] = vn1[nfxd - 1];
          vn2[pvt] = vn2[nfxd - 1];
        }

        if (nfxd < m) {
          longitudinal_mpc_xzlarfg(mmi + 1, A[ii], A, ii + 2, &temp, &tau[nfxd -
            1]);
          A[ii] = temp;
        } else {
          tau[nfxd - 1] = 0.0;
        }

        if (nfxd < n) {
          temp = A[ii];
          A[ii] = 1.0;
          longitudinal_mpc_xzlarf(mmi + 1, nmi - 1, ii + 1, tau[nfxd - 1], A, ii
            + 39, work);
          A[ii] = temp;
        }

        for (i = nfxd + 1; i <= n; i++) {
          itemp = (i - 1) * 38 + nfxd;
          vn1_0 = vn1[i - 1];
          if (vn1_0 != 0.0) {
            temp = std::abs(A[itemp - 1]) / vn1_0;
            temp = 1.0 - temp * temp;
            if (temp < 0.0) {
              temp = 0.0;
            }

            s = vn1_0 / vn2[i - 1];
            s = s * s * temp;
            if (s <= 1.4901161193847656E-8) {
              if (nfxd < m) {
                iy = itemp;
                temp = 0.0;
                if (mmi >= 1) {
                  if (mmi == 1) {
                    temp = std::abs(A[itemp]);
                  } else {
                    s = 3.3121686421112381E-170;
                    ii = itemp + mmi;
                    for (itemp = iy + 1; itemp <= ii; itemp++) {
                      vn1_0 = std::abs(A[itemp - 1]);
                      if (vn1_0 > s) {
                        t = s / vn1_0;
                        temp = temp * t * t + 1.0;
                        s = vn1_0;
                      } else {
                        t = vn1_0 / s;
                        temp += t * t;
                      }
                    }

                    temp = s * std::sqrt(temp);
                  }
                }

                vn1[i - 1] = temp;
                vn2[i - 1] = temp;
              } else {
                vn1[i - 1] = 0.0;
                vn2[i - 1] = 0.0;
              }
            } else {
              vn1[i - 1] = vn1_0 * std::sqrt(temp);
            }
          }
        }
      }
    }
  }
}

void longitudinal_mpc::longitudinal_mpc_computeQ_
  (sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *obj, int32_T nrows)
{
  real_T work[38];
  int32_T b_idx;
  int32_T i;
  int32_T iQR0;
  int32_T lastv;

  /* Start for MATLABSystem: '<S1>/solver' */
  lastv = obj->minRowCol - 1;
  for (b_idx = 0; b_idx <= lastv; b_idx++) {
    iQR0 = 38 * b_idx + b_idx;
    i = (obj->mrows - b_idx) - 2;
    if (i >= 0) {
      std::memcpy(&obj->Q[iQR0 + 1], &obj->QR[iQR0 + 1], static_cast<uint32_T>
                  (((i + iQR0) - iQR0) + 1) * sizeof(real_T));
    }
  }

  b_idx = obj->mrows;
  lastv = obj->minRowCol;
  if (nrows >= 1) {
    int32_T itau;
    for (itau = lastv; itau < nrows; itau++) {
      iQR0 = itau * 38;
      std::memset(&obj->Q[iQR0], 0, static_cast<uint32_T>((b_idx + iQR0) - iQR0)
                  * sizeof(real_T));
      obj->Q[iQR0 + itau] = 1.0;
    }

    itau = obj->minRowCol - 1;
    std::memset(&work[0], 0, 38U * sizeof(real_T));
    for (i = obj->minRowCol; i >= 1; i--) {
      int32_T i_0;
      int32_T iaii;
      iaii = (i - 1) * 38 + i;
      if (i < nrows) {
        int32_T ia;
        int32_T lastc;
        obj->Q[iaii - 1] = 1.0;
        lastv = b_idx - i;
        iQR0 = iaii + 38;
        if (obj->tau[itau] != 0.0) {
          boolean_T exitg2;
          i_0 = (iaii + lastv) - 1;
          while ((lastv + 1 > 0) && (obj->Q[i_0] == 0.0)) {
            lastv--;
            i_0--;
          }

          lastc = (nrows - i) - 1;
          exitg2 = false;
          while ((!exitg2) && (lastc + 1 > 0)) {
            int32_T exitg1;
            i_0 = (lastc * 38 + iaii) + 38;
            ia = i_0;
            do {
              exitg1 = 0;
              if (ia <= i_0 + lastv) {
                if (obj->Q[ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  ia++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = -1;
          lastc = -1;
        }

        if (lastv + 1 > 0) {
          real_T c;
          int32_T jy;
          if (lastc + 1 != 0) {
            if (lastc >= 0) {
              std::memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof
                          (real_T));
            }

            i_0 = (38 * lastc + iaii) + 38;
            for (int32_T iac{iQR0}; iac <= i_0; iac += 38) {
              c = 0.0;
              jy = iac + lastv;
              for (ia = iac; ia <= jy; ia++) {
                c += obj->Q[((iaii + ia) - iac) - 1] * obj->Q[ia - 1];
              }

              ia = div_nde_s32_floor((iac - iaii) - 38, 38);
              work[ia] += c;
            }
          }

          if (!(-obj->tau[itau] == 0.0)) {
            jy = iaii;
            for (ia = 0; ia <= lastc; ia++) {
              c = work[ia];
              if (c != 0.0) {
                c *= -obj->tau[itau];
                i_0 = jy + 38;
                iQR0 = (lastv + jy) + 38;
                for (int32_T iac{i_0}; iac <= iQR0; iac++) {
                  obj->Q[iac - 1] += obj->Q[((iaii + iac) - jy) - 39] * c;
                }
              }

              jy += 38;
            }
          }
        }
      }

      if (i < b_idx) {
        i_0 = (iaii + b_idx) - i;
        for (lastv = iaii + 1; lastv <= i_0; lastv++) {
          obj->Q[lastv - 1] *= -obj->tau[itau];
        }
      }

      obj->Q[iaii - 1] = 1.0 - obj->tau[itau];
      iQR0 = static_cast<uint8_T>(i - 1) - 1;
      for (i_0 = 0; i_0 <= iQR0; i_0++) {
        obj->Q[(iaii - i_0) - 2] = 0.0;
      }

      itau--;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

int32_T longitudinal_mpc::longitud_ComputeNumDependentEq_
  (sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, const real_T beqf[474], int32_T
   mConstr, int32_T nVar)
{
  real_T qtb;
  real_T tol;
  int32_T b;
  int32_T ix;
  int32_T numDependent;
  int32_T totalRank;
  boolean_T exitg1;

  /* Start for MATLABSystem: '<S1>/solver' */
  numDependent = mConstr - nVar;
  if (numDependent <= 0) {
    numDependent = 0;
  }

  std::memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>((static_cast<uint8_T>
    (nVar) - 1) + 1) * sizeof(int32_T));
  if (mConstr * nVar == 0) {
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    qrmanager->minRowCol = 0;
  } else {
    qrmanager->usedPivoting = true;
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    if (mConstr <= nVar) {
      qrmanager->minRowCol = mConstr;
    } else {
      qrmanager->minRowCol = nVar;
    }

    longitudinal_mpc_xgeqp3_b(qrmanager->QR, mConstr, nVar, qrmanager->jpvt,
      qrmanager->tau);
  }

  tol = 100.0 * static_cast<real_T>(nVar) * 2.2204460492503131E-16;
  if (nVar <= mConstr) {
    totalRank = nVar;
  } else {
    totalRank = mConstr;
  }

  totalRank += (totalRank - 1) * 38;
  while ((totalRank > 0) && (std::abs(qrmanager->QR[totalRank - 1]) < tol)) {
    totalRank -= 39;
    numDependent++;
  }

  if (numDependent > 0) {
    longitudinal_mpc_computeQ_(qrmanager, qrmanager->mrows);
    b = 1;
    exitg1 = false;
    while ((!exitg1) && (b - 1 <= numDependent - 1)) {
      qtb = 0.0;
      ix = (mConstr - b) * 38;
      for (totalRank = 0; totalRank < mConstr; totalRank++) {
        qtb += qrmanager->Q[ix + totalRank] * beqf[totalRank];
      }

      if (std::abs(qtb) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        b++;
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return numDependent;
}

void longitudinal_mpc::longitudina_IndexOfDependentEq_(int32_T depIdx[474],
  int32_T mFixed, int32_T nDep, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager,
  int32_T mRows, int32_T nCols)
{
  int32_T b_idx;

  /* Start for MATLABSystem: '<S1>/solver' */
  for (b_idx = 0; b_idx < mFixed; b_idx++) {
    qrmanager->jpvt[b_idx] = 1;
  }

  if (mFixed + 1 <= nCols) {
    std::memset(&qrmanager->jpvt[mFixed], 0, static_cast<uint32_T>(nCols -
      mFixed) * sizeof(int32_T));
  }

  if (mRows * nCols == 0) {
    qrmanager->mrows = mRows;
    qrmanager->ncols = nCols;
    qrmanager->minRowCol = 0;
  } else {
    qrmanager->usedPivoting = true;
    qrmanager->mrows = mRows;
    qrmanager->ncols = nCols;
    if (mRows <= nCols) {
      qrmanager->minRowCol = mRows;
    } else {
      qrmanager->minRowCol = nCols;
    }

    longitudinal_mpc_xgeqp3_b(qrmanager->QR, mRows, nCols, qrmanager->jpvt,
      qrmanager->tau);
  }

  for (b_idx = 0; b_idx < nDep; b_idx++) {
    depIdx[b_idx] = qrmanager->jpvt[(nCols - nDep) + b_idx];
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_countsort(int32_T x[474], int32_T xLen,
  int32_T workspace[474], int32_T xMin, int32_T xMax)
{
  /* Start for MATLABSystem: '<S1>/solver' */
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T c;
    int32_T idxEnd;
    int32_T idxFill;
    int32_T idxStart;
    int32_T maxOffset;
    maxOffset = xMax - xMin;
    if (maxOffset >= 0) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>(maxOffset + 1) *
                  sizeof(int32_T));
    }

    for (idxStart = 0; idxStart < xLen; idxStart++) {
      idxFill = x[idxStart] - xMin;
      workspace[idxFill]++;
    }

    for (idxStart = 2; idxStart <= maxOffset + 1; idxStart++) {
      workspace[idxStart - 1] += workspace[idxStart - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    c = maxOffset - 1;
    for (maxOffset = 0; maxOffset <= c; maxOffset++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = maxOffset + xMin;
      }

      idxStart = workspace[maxOffset] + 1;
      idxEnd = workspace[maxOffset + 1];
    }

    for (maxOffset = idxStart; maxOffset <= idxEnd; maxOffset++) {
      x[maxOffset - 1] = xMax;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_removeEqConstr(const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, int32_T idx_global)
{
  int32_T totalEq;

  /* Start for MATLABSystem: '<S1>/solver' */
  totalEq = obj->nWConstr[0] + obj->nWConstr[1];
  if ((totalEq != 0) && (idx_global <= totalEq)) {
    /* Check node always fails. would cause program termination and was eliminated */
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_RemoveDependentEq_
  (srUNuce4MmfvHoJodBzBujH_longi_T *memspace, const
   svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, int32_T *nDepInd,
   sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager)
{
  int32_T b_idx_col;
  int32_T f_tmp;
  int32_T i;
  int32_T offsetQR_tmp;

  /* Start for MATLABSystem: '<S1>/solver' */
  qrmanager->ldq = 38;
  std::memset(&qrmanager->QR[0], 0, 18012U * sizeof(real_T));
  std::memset(&qrmanager->Q[0], 0, 1444U * sizeof(real_T));
  std::memset(&qrmanager->jpvt[0], 0, 474U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  std::memset(&qrmanager->tau[0], 0, 38U * sizeof(real_T));
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  *nDepInd = 0;
  if (workingset->nWConstr[0] > 0) {
    offsetQR_tmp = static_cast<uint8_T>(workingset->nWConstr[0]) - 1;
    f_tmp = static_cast<uint8_T>(workingset->nVar) - 1;
    for (i = 0; i <= offsetQR_tmp; i++) {
      for (b_idx_col = 0; b_idx_col <= f_tmp; b_idx_col++) {
        qrmanager->QR[i + 38 * b_idx_col] = workingset->ATwset[38 * i +
          b_idx_col];
      }
    }

    *nDepInd = longitud_ComputeNumDependentEq_(qrmanager, workingset->bwset,
      workingset->nWConstr[0], workingset->nVar);
    if (*nDepInd > 0) {
      for (i = 0; i <= offsetQR_tmp; i++) {
        b_idx_col = 38 * i - 1;
        std::memcpy(&qrmanager->QR[b_idx_col + 1], &workingset->ATwset[b_idx_col
                    + 1], static_cast<uint32_T>(((f_tmp + b_idx_col) - b_idx_col)
          + 1) * sizeof(real_T));
      }

      longitudina_IndexOfDependentEq_(memspace->workspace_int,
        workingset->nWConstr[0], *nDepInd, qrmanager, workingset->nVar,
        workingset->nWConstr[0]);
      longitudinal_mpc_countsort(memspace->workspace_int, *nDepInd,
        memspace->workspace_sort, 1, workingset->nWConstr[0]);
      for (i = *nDepInd; i >= 1; i--) {
        longitudinal_mpc_removeEqConstr(workingset, memspace->workspace_int[i -
          1]);
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_removeConstr
  (svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, int32_T idx_global)
{
  int32_T TYPE_tmp;

  /* Start for MATLABSystem: '<S1>/solver' */
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  if (idx_global < obj->nActiveConstr) {
    int32_T c;
    obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
    obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
    c = static_cast<uint8_T>(obj->nVar) - 1;
    for (int32_T b_idx{0}; b_idx <= c; b_idx++) {
      obj->ATwset[b_idx + 38 * (idx_global - 1)] = obj->ATwset
        [(obj->nActiveConstr - 1) * 38 + b_idx];
    }

    obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  }

  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudin_RemoveDependentIneq_
  (svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *
   qrmanager, srUNuce4MmfvHoJodBzBujH_longi_T *memspace, real_T tolfactor)
{
  real_T tol;
  int32_T idxPosQR_tmp;
  int32_T nActiveConstr;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  int32_T nVar;

  /* Start for MATLABSystem: '<S1>/solver' */
  nFixedConstr = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = tolfactor * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    for (nDepIneq = 0; nDepIneq <= nFixedConstr - 2; nDepIneq++) {
      qrmanager->jpvt[nDepIneq] = 1;
    }

    if (nFixedConstr <= workingset->nActiveConstr) {
      std::memset(&qrmanager->jpvt[nFixedConstr + -1], 0, static_cast<uint32_T>
                  ((workingset->nActiveConstr - nFixedConstr) + 1) * sizeof
                  (int32_T));
    }

    nActiveConstr = workingset->nActiveConstr - 1;
    for (nDepIneq = 0; nDepIneq <= nActiveConstr; nDepIneq++) {
      idxPosQR_tmp = 38 * nDepIneq - 1;
      std::memcpy(&qrmanager->QR[idxPosQR_tmp + 1], &workingset->
                  ATwset[idxPosQR_tmp + 1], static_cast<uint32_T>((((
        static_cast<uint8_T>(nVar) - 1) + idxPosQR_tmp) - idxPosQR_tmp) + 1) *
                  sizeof(real_T));
    }

    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      if (workingset->nVar <= workingset->nActiveConstr) {
        qrmanager->minRowCol = workingset->nVar;
      } else {
        qrmanager->minRowCol = workingset->nActiveConstr;
      }

      longitudinal_mpc_xgeqp3_b(qrmanager->QR, workingset->nVar,
        workingset->nActiveConstr, qrmanager->jpvt, qrmanager->tau);
    }

    nDepIneq = -1;
    for (nActiveConstr = workingset->nActiveConstr; nActiveConstr > nVar;
         nActiveConstr--) {
      nDepIneq++;
      memspace->workspace_int[nDepIneq] = qrmanager->jpvt[nActiveConstr - 1];
    }

    if (nActiveConstr <= workingset->nVar) {
      nVar = ((nActiveConstr - 1) * 38 + nActiveConstr) - 1;
      while ((nActiveConstr > nFixedConstr - 1) && (std::abs(qrmanager->QR[nVar])
              < tol)) {
        nDepIneq++;
        memspace->workspace_int[nDepIneq] = qrmanager->jpvt[nActiveConstr - 1];
        nActiveConstr--;
        nVar -= 39;
      }
    }

    longitudinal_mpc_countsort(memspace->workspace_int, nDepIneq + 1,
      memspace->workspace_sort, nFixedConstr, workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq + 1; nFixedConstr >= 1; nFixedConstr--) {
      longitudinal_mpc_removeConstr(workingset, memspace->
        workspace_int[nFixedConstr - 1]);
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_factorQR(sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
  *obj, const real_T A[18012], int32_T mrows, int32_T ncols)
{
  int32_T b_idx;
  int32_T i;
  static const int32_T offsets[4]{ 0, 1, 2, 3 };

  int32_T vectorUB;
  boolean_T guard1;

  /* Start for MATLABSystem: '<S1>/solver' */
  vectorUB = mrows * ncols;
  guard1 = false;
  if (vectorUB > 0) {
    for (b_idx = 0; b_idx < ncols; b_idx++) {
      vectorUB = 38 * b_idx - 1;
      std::memcpy(&obj->QR[vectorUB + 1], &A[vectorUB + 1], static_cast<uint32_T>
                  ((((static_cast<uint8_T>(mrows) - 1) + vectorUB) - vectorUB) +
                   1) * sizeof(real_T));
    }

    guard1 = true;
  } else if (vectorUB == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    i = (ncols / 4) << 2;
    vectorUB = i - 4;
    for (b_idx = 0; b_idx <= vectorUB; b_idx += 4) {
      _mm_storeu_si128((__m128i *)&obj->jpvt[b_idx], _mm_add_epi32(_mm_add_epi32
        (_mm_set1_epi32(b_idx), _mm_loadu_si128((const __m128i *)&offsets[0])),
        _mm_set1_epi32(1)));
    }

    for (b_idx = i; b_idx < ncols; b_idx++) {
      obj->jpvt[b_idx] = b_idx + 1;
    }

    if (mrows <= ncols) {
      b_idx = mrows;
    } else {
      b_idx = ncols;
    }

    obj->minRowCol = b_idx;
    std::memset(&obj->tau[0], 0, 38U * sizeof(real_T));
    if (b_idx >= 1) {
      std::memset(&obj->tau[0], 0, 38U * sizeof(real_T));
      longitudinal_mpc_qrf(obj->QR, mrows, ncols, b_idx, obj->tau);
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xgemv(int32_T m, const real_T A[15162],
  const real_T x[18012], real_T y[474])
{
  /* Start for MATLABSystem: '<S1>/solver' */
  for (int32_T b_iy{0}; b_iy <= 396; b_iy += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[b_iy]);
    _mm_storeu_pd(&y[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (int32_T b_iy{398}; b_iy < 399; b_iy++) {
    y[b_iy] = -y[b_iy];
  }

  for (int32_T b_iy{0}; b_iy <= 15124; b_iy += 38) {
    real_T c;
    int32_T b;
    int32_T ia;
    c = 0.0;
    b = b_iy + m;
    for (ia = b_iy + 1; ia <= b; ia++) {
      c += x[(ia - b_iy) - 1] * A[ia - 1];
    }

    ia = div_nde_s32_floor(b_iy, 38);
    y[ia] += c;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitud_maxConstraintViolation(const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, const real_T x[18012], real_T *v,
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_obj)
{
  real_T b_obj_0;
  int32_T b;
  int32_T b_k;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (obj->probType == 2) {
    *b_obj = *obj;
    *v = 0.0;
    std::memcpy(&b_obj->maxConstrWorkspace[0], &b_obj->bineq[0], 399U * sizeof
                (real_T));
    longitudinal_mpc_xgemv(37, b_obj->Aineq, x, b_obj->maxConstrWorkspace);
    for (b_k = 0; b_k < 399; b_k++) {
      b_obj_0 = b_obj->maxConstrWorkspace[b_k] - x[b_k + 37];
      b_obj->maxConstrWorkspace[b_k] = b_obj_0;
      *v = std::fmax(*v, b_obj_0);
    }
  } else {
    *b_obj = *obj;
    *v = 0.0;
    std::memcpy(&b_obj->maxConstrWorkspace[0], &b_obj->bineq[0], 399U * sizeof
                (real_T));
    longitudinal_mpc_xgemv(b_obj->nVar, b_obj->Aineq, x,
      b_obj->maxConstrWorkspace);
    for (b_k = 0; b_k < 399; b_k++) {
      *v = std::fmax(*v, b_obj->maxConstrWorkspace[b_k]);
    }
  }

  if (obj->sizes[3] > 0) {
    b = static_cast<uint16_T>(obj->sizes[3]) - 1;
    for (b_k = 0; b_k <= b; b_k++) {
      *v = std::fmax(*v, -x[b_obj->indexLB[b_k] - 1] - b_obj->lb[b_obj->
                     indexLB[b_k] - 1]);
    }
  }

  if (obj->sizes[4] > 0) {
    b_k = static_cast<uint8_T>(obj->sizes[4]) - 1;
    for (b = 0; b <= b_k; b++) {
      *v = std::fmax(*v, x[b_obj->indexUB[b] - 1] - b_obj->ub[b_obj->indexUB[b]
                     - 1]);
    }
  }

  if (obj->sizes[0] > 0) {
    b_k = static_cast<uint8_T>(obj->sizes[0]) - 1;
    for (b = 0; b <= b_k; b++) {
      *v = std::fmax(*v, std::abs(x[b_obj->indexFixed[b] - 1] - b_obj->ub
        [b_obj->indexFixed[b] - 1]));
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xgemv_b(int32_T m, const real_T A[15162],
  const real_T x[18012], real_T y[474])
{
  /* Start for MATLABSystem: '<S1>/solver' */
  for (int32_T b_iy{0}; b_iy <= 396; b_iy += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[b_iy]);
    _mm_storeu_pd(&y[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (int32_T b_iy{398}; b_iy < 399; b_iy++) {
    y[b_iy] = -y[b_iy];
  }

  for (int32_T b_iy{0}; b_iy <= 15124; b_iy += 38) {
    real_T c;
    int32_T b;
    int32_T ia;
    c = 0.0;
    b = b_iy + m;
    for (ia = b_iy + 1; ia <= b; ia++) {
      c += x[(ia - b_iy) + 473] * A[ia - 1];
    }

    ia = div_nde_s32_floor(b_iy, 38);
    y[ia] += c;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longit_maxConstraintViolation_b(const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, const real_T x[18012], real_T *v,
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_obj)
{
  real_T b_obj_0;
  int32_T b;
  int32_T b_k;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (obj->probType == 2) {
    *b_obj = *obj;
    *v = 0.0;
    std::memcpy(&b_obj->maxConstrWorkspace[0], &b_obj->bineq[0], 399U * sizeof
                (real_T));
    longitudinal_mpc_xgemv_b(37, b_obj->Aineq, x, b_obj->maxConstrWorkspace);
    for (b_k = 0; b_k < 399; b_k++) {
      b_obj_0 = b_obj->maxConstrWorkspace[b_k] - x[b_k + 511];
      b_obj->maxConstrWorkspace[b_k] = b_obj_0;
      *v = std::fmax(*v, b_obj_0);
    }
  } else {
    *b_obj = *obj;
    *v = 0.0;
    std::memcpy(&b_obj->maxConstrWorkspace[0], &b_obj->bineq[0], 399U * sizeof
                (real_T));
    longitudinal_mpc_xgemv_b(b_obj->nVar, b_obj->Aineq, x,
      b_obj->maxConstrWorkspace);
    for (b_k = 0; b_k < 399; b_k++) {
      *v = std::fmax(*v, b_obj->maxConstrWorkspace[b_k]);
    }
  }

  if (obj->sizes[3] > 0) {
    b = static_cast<uint16_T>(obj->sizes[3]) - 1;
    for (b_k = 0; b_k <= b; b_k++) {
      *v = std::fmax(*v, -x[b_obj->indexLB[b_k] + 473] - b_obj->lb
                     [b_obj->indexLB[b_k] - 1]);
    }
  }

  if (obj->sizes[4] > 0) {
    b_k = static_cast<uint8_T>(obj->sizes[4]) - 1;
    for (b = 0; b <= b_k; b++) {
      *v = std::fmax(*v, x[b_obj->indexUB[b] + 473] - b_obj->ub[b_obj->indexUB[b]
                     - 1]);
    }
  }

  if (obj->sizes[0] > 0) {
    b_k = static_cast<uint8_T>(obj->sizes[0]) - 1;
    for (b = 0; b <= b_k; b++) {
      *v = std::fmax(*v, std::abs(x[b_obj->indexFixed[b] + 473] - b_obj->
        ub[b_obj->indexFixed[b] - 1]));
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

boolean_T longitudinal_mpc::longitu_feasibleX0ForWorkingSet(real_T workspace
  [18012], real_T xCurrent[38], svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset,
  sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T c;
  real_T constrViolation_basicX;
  int32_T b_idx;
  int32_T br;
  int32_T d;
  int32_T i;
  int32_T iAcol;
  int32_T ix;
  int32_T iy;
  int32_T mWConstr;
  int32_T vectorUB;
  boolean_T nonDegenerateWset;
  static const int32_T offsets[4]{ 0, 1, 2, 3 };

  int32_T exitg1;
  int32_T mWConstr_tmp_tmp;
  int32_T nVar_tmp_tmp;

  /* Start for MATLABSystem: '<S1>/solver' */
  mWConstr_tmp_tmp = workingset->nActiveConstr - 1;
  nVar_tmp_tmp = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (b_idx = 0; b_idx <= mWConstr_tmp_tmp; b_idx++) {
      workspace[b_idx] = workingset->bwset[b_idx];
      workspace[b_idx + 474] = workingset->bwset[b_idx];
    }

    if (workingset->nActiveConstr != 0) {
      i = (workingset->nActiveConstr - 1) * 38 + 1;
      for (mWConstr = 1; mWConstr <= i; mWConstr += 38) {
        c = 0.0;
        d = mWConstr + nVar_tmp_tmp;
        for (b_idx = mWConstr; b_idx < d; b_idx++) {
          c += workingset->ATwset[b_idx - 1] * xCurrent[b_idx - mWConstr];
        }

        iAcol = div_nde_s32_floor(mWConstr - 1, 38);
        workspace[iAcol] -= c;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      i = static_cast<uint8_T>(workingset->nVar) - 1;
      for (b_idx = 0; b_idx <= i; b_idx++) {
        iy = 38 * b_idx - 1;
        for (d = 0; d <= mWConstr_tmp_tmp; d++) {
          qrmanager->QR[(d + iy) + 1] = workingset->ATwset[38 * d + b_idx];
        }
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      d = (static_cast<uint8_T>(workingset->nVar) / 4) << 2;
      vectorUB = d - 4;
      for (b_idx = 0; b_idx <= vectorUB; b_idx += 4) {
        _mm_storeu_si128((__m128i *)&qrmanager->jpvt[b_idx], _mm_add_epi32
                         (_mm_add_epi32(_mm_set1_epi32(b_idx), _mm_loadu_si128((
          const __m128i *)&offsets[0])), _mm_set1_epi32(1)));
      }

      for (b_idx = d; b_idx <= i; b_idx++) {
        qrmanager->jpvt[b_idx] = b_idx + 1;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        b_idx = workingset->nActiveConstr;
      } else {
        b_idx = workingset->nVar;
      }

      qrmanager->minRowCol = b_idx;
      std::memcpy(&longitudinal_mpc_B.B[0], &qrmanager->QR[0], 18012U * sizeof
                  (real_T));
      std::memset(&qrmanager->tau[0], 0, 38U * sizeof(real_T));
      if (b_idx >= 1) {
        std::memcpy(&longitudinal_mpc_B.B[0], &qrmanager->QR[0], 18012U * sizeof
                    (real_T));
        std::memset(&qrmanager->tau[0], 0, 38U * sizeof(real_T));
        longitudinal_mpc_qrf(longitudinal_mpc_B.B, workingset->nActiveConstr,
                             workingset->nVar, b_idx, qrmanager->tau);
      }

      std::memcpy(&qrmanager->QR[0], &longitudinal_mpc_B.B[0], 18012U * sizeof
                  (real_T));
      longitudinal_mpc_computeQ_(qrmanager, qrmanager->mrows);
      std::memcpy(&longitudinal_mpc_B.B[0], &workspace[0], 18012U * sizeof
                  (real_T));
      for (b_idx = 0; b_idx <= 474; b_idx += 474) {
        iy = b_idx + nVar_tmp_tmp;
        for (d = b_idx + 1; d <= iy; d++) {
          workspace[d - 1] = 0.0;
        }
      }

      br = -1;
      for (i = 0; i <= 474; i += 474) {
        iAcol = -1;
        iy = i + nVar_tmp_tmp;
        for (mWConstr = i + 1; mWConstr <= iy; mWConstr++) {
          c = 0.0;
          for (b_idx = 0; b_idx <= mWConstr_tmp_tmp; b_idx++) {
            c += qrmanager->Q[(b_idx + iAcol) + 1] * longitudinal_mpc_B.B[(b_idx
              + br) + 1];
          }

          workspace[mWConstr - 1] += c;
          iAcol += 38;
        }

        br += 474;
      }

      for (i = 0; i < 2; i++) {
        ix = 474 * i - 1;
        for (b_idx = nVar_tmp_tmp; b_idx >= 1; b_idx--) {
          mWConstr = (b_idx - 1) * 38 - 1;
          iAcol = b_idx + ix;
          c = workspace[iAcol];
          if (c != 0.0) {
            workspace[iAcol] = c / qrmanager->QR[b_idx + mWConstr];
            iy = static_cast<uint8_T>(b_idx - 1) - 1;
            for (d = 0; d <= iy; d++) {
              mWConstr_tmp_tmp = (d + ix) + 1;
              workspace[mWConstr_tmp_tmp] -= qrmanager->QR[(d + mWConstr) + 1] *
                workspace[iAcol];
            }
          }
        }
      }
    } else {
      longitudinal_mpc_factorQR(qrmanager, workingset->ATwset, workingset->nVar,
        workingset->nActiveConstr);
      longitudinal_mpc_computeQ_(qrmanager, qrmanager->minRowCol);
      for (i = 0; i < 2; i++) {
        ix = 474 * i - 1;
        for (d = 0; d <= mWConstr_tmp_tmp; d++) {
          iAcol = 38 * d;
          b_idx = (d + ix) + 1;
          c = workspace[b_idx];
          iy = static_cast<uint8_T>(d) - 1;
          for (mWConstr = 0; mWConstr <= iy; mWConstr++) {
            c -= workspace[(mWConstr + ix) + 1] * qrmanager->QR[mWConstr + iAcol];
          }

          workspace[b_idx] = c / qrmanager->QR[d + iAcol];
        }
      }

      std::memcpy(&longitudinal_mpc_B.B[0], &workspace[0], 18012U * sizeof
                  (real_T));
      for (b_idx = 0; b_idx <= 474; b_idx += 474) {
        iy = b_idx + nVar_tmp_tmp;
        for (d = b_idx + 1; d <= iy; d++) {
          workspace[d - 1] = 0.0;
        }
      }

      br = 1;
      for (i = 0; i <= 474; i += 474) {
        iAcol = 0;
        iy = br + mWConstr_tmp_tmp;
        for (ix = br; ix <= iy; ix++) {
          b_idx = i + nVar_tmp_tmp;
          d = ((((b_idx - i) / 2) << 1) + i) + 1;
          vectorUB = d - 2;
          for (mWConstr = i + 1; mWConstr <= vectorUB; mWConstr += 2) {
            tmp = _mm_loadu_pd(&qrmanager->Q[((iAcol + mWConstr) - i) - 1]);
            tmp_0 = _mm_loadu_pd(&workspace[mWConstr - 1]);
            _mm_storeu_pd(&workspace[mWConstr - 1], _mm_add_pd(_mm_mul_pd(tmp,
              _mm_set1_pd(longitudinal_mpc_B.B[ix - 1])), tmp_0));
          }

          for (mWConstr = d; mWConstr <= b_idx; mWConstr++) {
            workspace[mWConstr - 1] += qrmanager->Q[((iAcol + mWConstr) - i) - 1]
              * longitudinal_mpc_B.B[ix - 1];
          }

          iAcol += 38;
        }

        br += 474;
      }
    }

    mWConstr = 1;
    do {
      exitg1 = 0;
      if (mWConstr - 1 <= static_cast<uint8_T>(nVar_tmp_tmp) - 1) {
        c = workspace[mWConstr - 1];
        if (std::isinf(c) || std::isnan(c)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c = workspace[mWConstr + 473];
          if (std::isinf(c) || std::isnan(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            mWConstr++;
          }
        }
      } else {
        d = (nVar_tmp_tmp / 2) << 1;
        vectorUB = d - 2;
        for (b_idx = 0; b_idx <= vectorUB; b_idx += 2) {
          tmp = _mm_loadu_pd(&workspace[b_idx]);
          tmp_0 = _mm_loadu_pd(&xCurrent[b_idx]);
          _mm_storeu_pd(&workspace[b_idx], _mm_add_pd(tmp, tmp_0));
        }

        for (b_idx = d; b_idx < nVar_tmp_tmp; b_idx++) {
          workspace[b_idx] += xCurrent[b_idx];
        }

        longitud_maxConstraintViolation(workingset, workspace, &c,
          &longitudinal_mpc_B.c_workingset);
        longit_maxConstraintViolation_b(&longitudinal_mpc_B.c_workingset,
          workspace, &constrViolation_basicX, workingset);
        if ((c <= 2.2204460492503131E-16) || (c < constrViolation_basicX)) {
          std::memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>((
            static_cast<uint8_T>(nVar_tmp_tmp) - 1) + 1) * sizeof(real_T));
        } else {
          std::memcpy(&xCurrent[0], &workspace[474], static_cast<uint32_T>((
            static_cast<uint8_T>(nVar_tmp_tmp) - 1) + 1) * sizeof(real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return nonDegenerateWset;
}

void longitudinal_mpc::longitudinal_mpc_xgemv_b4(int32_T m, const real_T A[15162],
  const real_T x[38], real_T y[474])
{
  /* Start for MATLABSystem: '<S1>/solver' */
  for (int32_T b_iy{0}; b_iy <= 396; b_iy += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[b_iy]);
    _mm_storeu_pd(&y[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (int32_T b_iy{398}; b_iy < 399; b_iy++) {
    y[b_iy] = -y[b_iy];
  }

  for (int32_T b_iy{0}; b_iy <= 15124; b_iy += 38) {
    real_T c;
    int32_T b;
    int32_T ia;
    c = 0.0;
    b = b_iy + m;
    for (ia = b_iy + 1; ia <= b; ia++) {
      c += x[(ia - b_iy) - 1] * A[ia - 1];
    }

    ia = div_nde_s32_floor(b_iy, 38);
    y[ia] += c;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longi_maxConstraintViolation_b4(const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, const real_T x[38], real_T *v,
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_obj)
{
  real_T b_obj_0;
  int32_T b;
  int32_T b_k;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (obj->probType == 2) {
    *b_obj = *obj;
    *v = 0.0;
    std::memcpy(&b_obj->maxConstrWorkspace[0], &b_obj->bineq[0], 399U * sizeof
                (real_T));
    longitudinal_mpc_xgemv_b4(37, b_obj->Aineq, x, b_obj->maxConstrWorkspace);
    for (b_k = 0; b_k < 399; b_k++) {
      b_obj_0 = b_obj->maxConstrWorkspace[b_k] - x[37];
      b_obj->maxConstrWorkspace[b_k] = b_obj_0;
      *v = std::fmax(*v, b_obj_0);
    }
  } else {
    *b_obj = *obj;
    *v = 0.0;
    std::memcpy(&b_obj->maxConstrWorkspace[0], &b_obj->bineq[0], 399U * sizeof
                (real_T));
    longitudinal_mpc_xgemv_b4(b_obj->nVar, b_obj->Aineq, x,
      b_obj->maxConstrWorkspace);
    for (b_k = 0; b_k < 399; b_k++) {
      *v = std::fmax(*v, b_obj->maxConstrWorkspace[b_k]);
    }
  }

  if (obj->sizes[3] > 0) {
    b = static_cast<uint16_T>(obj->sizes[3]) - 1;
    for (b_k = 0; b_k <= b; b_k++) {
      *v = std::fmax(*v, -x[b_obj->indexLB[b_k] - 1] - b_obj->lb[b_obj->
                     indexLB[b_k] - 1]);
    }
  }

  if (obj->sizes[4] > 0) {
    b_k = static_cast<uint8_T>(obj->sizes[4]) - 1;
    for (b = 0; b <= b_k; b++) {
      *v = std::fmax(*v, x[b_obj->indexUB[b] - 1] - b_obj->ub[b_obj->indexUB[b]
                     - 1]);
    }
  }

  if (obj->sizes[0] > 0) {
    b_k = static_cast<uint8_T>(obj->sizes[0]) - 1;
    for (b = 0; b <= b_k; b++) {
      *v = std::fmax(*v, std::abs(x[b_obj->indexFixed[b] - 1] - b_obj->ub
        [b_obj->indexFixed[b] - 1]));
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudi_PresolveWorkingSet_b4(const
  suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, const real_T
  memspace_workspace_float[18012], const int32_T memspace_workspace_int[474],
  const int32_T memspace_workspace_sort[474], svwK1qKQ5yAVvUFh54r0LBD_longi_T
  *workingset, suKEVDQMOZ0XRzxi1HugtZH_longi_T *b_solution,
  srUNuce4MmfvHoJodBzBujH_longi_T *b_memspace, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
  *qrmanager)
{
  real_T constrViolation;
  int32_T i;
  int32_T idxEndIneq;
  int32_T idxStartIneq_tmp;
  boolean_T guard1;
  boolean_T okWorkingSet;
  *b_solution = *solution;
  b_solution->state = 82;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&b_memspace->workspace_float[0], &memspace_workspace_float[0],
              18012U * sizeof(real_T));
  std::memcpy(&b_memspace->workspace_int[0], &memspace_workspace_int[0], 474U *
              sizeof(int32_T));
  std::memcpy(&b_memspace->workspace_sort[0], &memspace_workspace_sort[0], 474U *
              sizeof(int32_T));
  longitudinal_RemoveDependentEq_(b_memspace, workingset, &i, qrmanager);
  if ((i != -1) && (workingset->nActiveConstr <= 38)) {
    longitudin_RemoveDependentIneq_(workingset, qrmanager, b_memspace, 100.0);
    std::memcpy(&b_solution->xstar[0], &solution->xstar[0], 38U * sizeof(real_T));
    okWorkingSet = longitu_feasibleX0ForWorkingSet(b_memspace->workspace_float,
      b_solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      longitudin_RemoveDependentIneq_(workingset, qrmanager, b_memspace, 1000.0);
      okWorkingSet = longitu_feasibleX0ForWorkingSet(b_memspace->workspace_float,
        b_solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        b_solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        longitudinal_mpc_B.workingset = *workingset;
        longi_maxConstraintViolation_b4(&longitudinal_mpc_B.workingset,
          b_solution->xstar, &constrViolation, workingset);
        if (constrViolation > 1.0E-5) {
          b_solution->state = -2;
        }
      }
    }
  } else {
    b_solution->state = -3;
    idxStartIneq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
    idxEndIneq = workingset->nActiveConstr;
    for (i = idxStartIneq_tmp + 1; i <= idxEndIneq; i++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->Wid[i - 1]
        - 1] + workingset->Wlocalidx[i - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = idxStartIneq_tmp;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_linearForm_(boolean_T obj_hasLinear,
  int32_T obj_nvar, real_T workspace[18012], const real_T H[1369], const real_T
  f[37], const real_T x[38])
{
  real_T fMultiplier;

  /* Start for MATLABSystem: '<S1>/solver' */
  fMultiplier = 0.0;
  if (obj_hasLinear) {
    if (static_cast<uint8_T>(obj_nvar) - 1 >= 0) {
      std::memcpy(&workspace[0], &f[0], static_cast<uint32_T>
                  ((static_cast<uint8_T>(obj_nvar) - 1) + 1) * sizeof(real_T));
    }

    fMultiplier = 1.0;
  }

  if (obj_nvar != 0) {
    int32_T d;
    int32_T ix;
    if (fMultiplier != 1.0) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>((static_cast<uint8_T>
        (obj_nvar) - 1) + 1) * sizeof(real_T));
    }

    ix = 0;
    d = (obj_nvar - 1) * obj_nvar;
    for (int32_T b_i{1}; obj_nvar < 0 ? b_i >= d + 1 : b_i <= d + 1; b_i +=
         obj_nvar) {
      int32_T e;
      fMultiplier = 0.5 * x[ix];
      e = b_i + obj_nvar;
      for (int32_T c{b_i}; c < e; c++) {
        int32_T tmp;
        tmp = c - b_i;
        workspace[tmp] += H[c - 1] * fMultiplier;
      }

      ix++;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

real_T longitudinal_mpc::longitudinal_mpc_computeFval(const
  siuq7rbPRrhRxtZY0x4sHID_longi_T *obj, real_T workspace[18012], const real_T H
  [1369], const real_T f[37], const real_T x[38])
{
  real_T val;
  int32_T b;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;

  /* Start for MATLABSystem: '<S1>/solver' */
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    longitudinal_mpc_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      b = static_cast<uint8_T>(obj->nvar) - 1;
      for (idx = 0; idx <= b; idx++) {
        val += x[idx] * workspace[idx];
      }
    }
    break;

   default:
    longitudinal_mpc_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    b = obj->nvar;
    scalarLB = ((((37 - obj->nvar) / 2) << 1) + obj->nvar) + 1;
    vectorUB = scalarLB - 2;
    for (idx = b + 1; idx <= vectorUB; idx += 2) {
      _mm_storeu_pd(&workspace[idx - 1], _mm_mul_pd(_mm_loadu_pd(&x[idx - 1]),
        _mm_set1_pd(0.0)));
    }

    for (idx = scalarLB; idx < 38; idx++) {
      workspace[idx - 1] = x[idx - 1] * 0.0;
    }

    val = 0.0;
    for (idx = 0; idx < 37; idx++) {
      val += x[idx] * workspace[idx];
    }
    break;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return val;
}

void longitudinal_mpc::longitudinal_mpc_xgemv_b4t(int32_T m, int32_T n, const
  real_T A[1369], int32_T lda, const real_T x[38], real_T y[37])
{
  /* Start for MATLABSystem: '<S1>/solver' */
  if ((m != 0) && (n != 0)) {
    int32_T d;
    int32_T ix;
    std::memset(&y[0], 0, static_cast<uint32_T>((static_cast<uint8_T>(m) - 1) +
      1) * sizeof(real_T));
    ix = 0;
    d = (n - 1) * lda;
    for (int32_T b_iy{1}; lda < 0 ? b_iy >= d + 1 : b_iy <= d + 1; b_iy += lda)
    {
      int32_T e;
      e = b_iy + m;
      for (int32_T b{b_iy}; b < e; b++) {
        int32_T tmp;
        tmp = b - b_iy;
        y[tmp] += A[b - 1] * x[ix];
      }

      ix++;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudina_computeGrad_StoreHx
  (siuq7rbPRrhRxtZY0x4sHID_longi_T *obj, const real_T H[1369], const real_T f[37],
   const real_T x[38])
{
  __m128d tmp;
  int32_T idx;
  int32_T ixlast;
  int32_T scalarLB;
  int32_T vectorUB;

  /* Start for MATLABSystem: '<S1>/solver' */
  switch (obj->objtype) {
   case 5:
    if (obj->nvar - 2 >= 0) {
      std::memset(&obj->grad[0], 0, static_cast<uint32_T>((obj->nvar - 2) + 1) *
                  sizeof(real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    longitudinal_mpc_xgemv_b4t(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    if (static_cast<uint8_T>(obj->nvar) - 1 >= 0) {
      std::memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint32_T>((
        static_cast<uint8_T>(obj->nvar) - 1) + 1) * sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp = _mm_loadu_pd(&obj->grad[idx]);
        _mm_storeu_pd(&obj->grad[idx], _mm_add_pd(tmp, _mm_loadu_pd(&f[idx])));
      }

      for (idx = scalarLB; idx < ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;

   default:
    longitudinal_mpc_xgemv_b4t(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    ixlast = obj->nvar;
    scalarLB = ((((37 - obj->nvar) / 2) << 1) + obj->nvar) + 1;
    vectorUB = scalarLB - 2;
    for (idx = ixlast + 1; idx <= vectorUB; idx += 2) {
      _mm_storeu_pd(&obj->Hx[idx - 1], _mm_mul_pd(_mm_loadu_pd(&x[idx - 1]),
        _mm_set1_pd(0.0)));
    }

    for (idx = scalarLB; idx < 38; idx++) {
      obj->Hx[idx - 1] = x[idx - 1] * 0.0;
    }

    std::memcpy(&obj->grad[0], &obj->Hx[0], 37U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ixlast = obj->nvar;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp = _mm_loadu_pd(&obj->grad[idx]);
        _mm_storeu_pd(&obj->grad[idx], _mm_add_pd(tmp, _mm_loadu_pd(&f[idx])));
      }

      for (idx = scalarLB; idx < ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

real_T longitudinal_mpc::longitudina_computeFval_ReuseHx(const
  siuq7rbPRrhRxtZY0x4sHID_longi_T *obj, real_T workspace[18012], const real_T f
  [37], const real_T x[38])
{
  real_T val;

  /* Start for MATLABSystem: '<S1>/solver' */
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T b_k;
        int32_T e;
        int32_T vectorUB;
        e = static_cast<uint8_T>(obj->nvar) - 1;
        b_k = (static_cast<uint8_T>(obj->nvar) / 2) << 1;
        vectorUB = b_k - 2;
        for (int32_T k{0}; k <= vectorUB; k += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&obj->Hx[k]);
          _mm_storeu_pd(&workspace[k], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5),
            tmp), _mm_loadu_pd(&f[k])));
        }

        for (int32_T k{b_k}; k <= e; k++) {
          workspace[k] = 0.5 * obj->Hx[k] + f[k];
        }

        val = 0.0;
        if (obj->nvar >= 1) {
          for (b_k = 0; b_k <= e; b_k++) {
            val += x[b_k] * workspace[b_k];
          }
        }
      } else {
        val = 0.0;
        if (obj->nvar >= 1) {
          int32_T e;
          e = static_cast<uint8_T>(obj->nvar) - 1;
          for (int32_T b_k{0}; b_k <= e; b_k++) {
            val += x[b_k] * obj->Hx[b_k];
          }
        }

        val *= 0.5;
      }
    }
    break;

   default:
    {
      if (obj->hasLinear) {
        int32_T k;
        if (static_cast<uint8_T>(obj->nvar) - 1 >= 0) {
          std::memcpy(&workspace[0], &f[0], static_cast<uint32_T>((static_cast<
            uint8_T>(obj->nvar) - 1) + 1) * sizeof(real_T));
        }

        k = 36 - obj->nvar;
        for (int32_T b_k{0}; b_k <= k; b_k++) {
          workspace[obj->nvar + b_k] = 0.0;
        }

        val = 0.0;
        for (k = 0; k < 37; k++) {
          real_T workspace_0;
          workspace_0 = 0.5 * obj->Hx[k] + workspace[k];
          workspace[k] = workspace_0;
          val += x[k] * workspace_0;
        }
      } else {
        int32_T k;
        val = 0.0;
        for (int32_T b_k{0}; b_k < 37; b_k++) {
          val += x[b_k] * obj->Hx[b_k];
        }

        val *= 0.5;
        k = obj->nvar;
        for (int32_T b_k{k + 1}; b_k < 38; b_k++) {
          val += x[b_k - 1] * 0.0;
        }
      }
    }
    break;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return val;
}

void longitudinal_mpc::longitudinal_mpc_xrotg(real_T a, real_T b, real_T *b_a,
  real_T *b_b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;

  /* Start for MATLABSystem: '<S1>/solver' */
  roe = b;
  absa = std::abs(a);
  absb = std::abs(b);
  if (absa > absb) {
    /* Start for MATLABSystem: '<S1>/solver' */
    roe = a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *b_a = 0.0;
    *b_b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;

    /* Start for MATLABSystem: '<S1>/solver' */
    *b_a = std::sqrt(ads * ads + bds * bds) * scale;
    if (roe < 0.0) {
      *b_a = -*b_a;
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    *c = a / *b_a;
    *s = b / *b_a;
    if (absa > absb) {
      *b_b = *s;
    } else if (*c != 0.0) {
      /* Start for MATLABSystem: '<S1>/solver' */
      *b_b = 1.0 / *c;
    } else {
      *b_b = 1.0;
    }
  }
}

void longitudinal_mpc::longitudinal_m_deleteColMoveEnd
  (sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *obj, int32_T idx)
{
  real_T b_s;
  real_T c_c;
  real_T temp;
  real_T temp_tmp_0;
  int32_T QRk0;
  int32_T c_k;
  int32_T endIdx;
  int32_T i;
  int32_T idxRotGCol;
  int32_T n;
  int32_T temp_tmp;
  int32_T tmp;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    idxRotGCol = obj->minRowCol - 1;
    for (endIdx = 0; endIdx <= idxRotGCol; endIdx++) {
      obj->QR[endIdx + 38 * (idx - 1)] = obj->QR[(obj->ncols - 1) * 38 + endIdx];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        endIdx = obj->mrows - 1;
      } else {
        endIdx = obj->ncols;
      }

      i = endIdx;
      idxRotGCol = (idx - 1) * 38;
      while (i >= idx) {
        tmp = i + idxRotGCol;
        longitudinal_mpc_xrotg(obj->QR[tmp - 1], obj->QR[tmp], &obj->QR[tmp - 1],
          &temp, &c_c, &b_s);
        obj->QR[tmp] = temp;
        tmp = (i - 1) * 38;
        obj->QR[i + tmp] = 0.0;
        QRk0 = (38 * idx + i) - 1;
        n = obj->ncols - idx;
        if (n >= 1) {
          for (c_k = 0; c_k < n; c_k++) {
            temp_tmp = c_k * 38 + QRk0;
            temp_tmp_0 = obj->QR[temp_tmp + 1];
            temp = obj->QR[temp_tmp] * c_c + temp_tmp_0 * b_s;
            obj->QR[temp_tmp + 1] = temp_tmp_0 * c_c - obj->QR[temp_tmp] * b_s;
            obj->QR[temp_tmp] = temp;
          }
        }

        n = obj->mrows;
        if (obj->mrows >= 1) {
          for (c_k = 0; c_k < n; c_k++) {
            temp_tmp = tmp + c_k;
            temp_tmp_0 = obj->Q[temp_tmp + 38];
            temp = temp_tmp_0 * b_s + obj->Q[temp_tmp] * c_c;
            obj->Q[temp_tmp + 38] = temp_tmp_0 * c_c - obj->Q[temp_tmp] * b_s;
            obj->Q[temp_tmp] = temp;
          }
        }

        i--;
      }

      for (c_k = idx + 1; c_k <= endIdx; c_k++) {
        idxRotGCol = (c_k - 1) * 38;
        tmp = c_k + idxRotGCol;
        longitudinal_mpc_xrotg(obj->QR[tmp - 1], obj->QR[tmp], &obj->QR[tmp - 1],
          &temp, &c_c, &b_s);
        obj->QR[tmp] = temp;
        QRk0 = c_k * 39 - 1;
        n = obj->ncols - c_k;
        if (n >= 1) {
          for (i = 0; i < n; i++) {
            temp_tmp = i * 38 + QRk0;
            temp = obj->QR[temp_tmp + 1] * b_s + obj->QR[temp_tmp] * c_c;
            obj->QR[temp_tmp + 1] = obj->QR[temp_tmp + 1] * c_c - obj->
              QR[temp_tmp] * b_s;
            obj->QR[temp_tmp] = temp;
          }
        }

        n = obj->mrows;
        if (obj->mrows >= 1) {
          for (i = 0; i < n; i++) {
            temp_tmp = idxRotGCol + i;
            temp = obj->Q[temp_tmp + 38] * b_s + obj->Q[temp_tmp] * c_c;
            obj->Q[temp_tmp + 38] = obj->Q[temp_tmp + 38] * c_c - obj->
              Q[temp_tmp] * b_s;
            obj->Q[temp_tmp] = temp;
          }
        }
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_fullColLDL2_
  (sSQjeS6UA6ous3QrgyAXHyC_longi_T *obj, int32_T NColsRemain, real_T REG_PRIMAL)
{
  int32_T lastDiag;

  /* Start for MATLABSystem: '<S1>/solver' */
  for (lastDiag = 0; lastDiag < NColsRemain; lastDiag++) {
    real_T neg_D;
    real_T temp;
    int32_T LD_diagOffset;
    int32_T b_k;
    int32_T ijA;
    int32_T subMatrixDim;
    LD_diagOffset = 39 * lastDiag;
    temp = obj->FMat[LD_diagOffset];
    if (std::abs(temp) <= obj->regTol_) {
      temp += REG_PRIMAL;
      obj->FMat[LD_diagOffset] = temp;
    }

    neg_D = -1.0 / temp;
    subMatrixDim = (NColsRemain - lastDiag) - 1;
    for (b_k = 0; b_k < subMatrixDim; b_k++) {
      obj->workspace_[b_k] = obj->FMat[(LD_diagOffset + b_k) + 1];
    }

    if (!(neg_D == 0.0)) {
      int32_T jA;
      jA = LD_diagOffset;
      for (int32_T k{0}; k < subMatrixDim; k++) {
        temp = obj->workspace_[k];
        if (temp != 0.0) {
          int32_T c;
          temp *= neg_D;
          b_k = jA + 40;
          c = (subMatrixDim + jA) + 39;
          for (ijA = b_k; ijA <= c; ijA++) {
            obj->FMat[ijA - 1] += obj->workspace_[(ijA - jA) - 40] * temp;
          }
        }

        jA += 38;
      }
    }

    neg_D = 1.0 / obj->FMat[LD_diagOffset];
    b_k = (LD_diagOffset + subMatrixDim) + 1;
    ijA = (((((b_k - LD_diagOffset) - 1) / 2) << 1) + LD_diagOffset) + 2;
    subMatrixDim = ijA - 2;
    for (int32_T k{LD_diagOffset + 2}; k <= subMatrixDim; k += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&obj->FMat[k - 1]);
      _mm_storeu_pd(&obj->FMat[k - 1], _mm_mul_pd(tmp, _mm_set1_pd(neg_D)));
    }

    for (int32_T k{ijA}; k <= b_k; k++) {
      obj->FMat[k - 1] *= neg_D;
    }
  }

  lastDiag = (NColsRemain - 1) * 39;
  if (std::abs(obj->FMat[lastDiag]) <= obj->regTol_) {
    obj->FMat[lastDiag] += REG_PRIMAL;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xgemv_b4tv(int32_T m, int32_T n, const
  real_T A[1444], int32_T ia0, const real_T x[18012], real_T y[38])
{
  /* Start for MATLABSystem: '<S1>/solver' */
  if (m != 0) {
    int32_T b;
    int32_T ix;
    std::memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    ix = 0;
    b = (n - 1) * 38 + ia0;
    for (int32_T b_iy{ia0}; b_iy <= b; b_iy += 38) {
      int32_T d;
      d = b_iy + m;
      for (int32_T ia{b_iy}; ia < d; ia++) {
        int32_T tmp;
        tmp = ia - b_iy;
        y[tmp] += A[ia - 1] * x[ix];
      }

      ix++;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_compute_deltax(const real_T H[1369],
  suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, srUNuce4MmfvHoJodBzBujH_longi_T
  *memspace, const sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager,
  sSQjeS6UA6ous3QrgyAXHyC_longi_T *cholmanager, const
  siuq7rbPRrhRxtZY0x4sHID_longi_T *objective)
{
  __m128d tmp;
  real_T s;
  real_T smax;
  real_T temp;
  int32_T A_maxDiag_idx;
  int32_T ar;
  int32_T br;
  int32_T e;
  int32_T exitg1;
  int32_T g;
  int32_T ia;
  int32_T ix;
  int32_T lastColC;
  int32_T mNull_tmp;
  int32_T nVar;
  int32_T nVars;
  int32_T nullStartIdx;
  int32_T nullStartIdx_tmp;
  int32_T scalarLB;
  int32_T vectorUB;

  /* Start for MATLABSystem: '<S1>/solver' */
  nVar = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    if (qrmanager->mrows - 1 >= 0) {
      std::memset(&solution->searchDir[0], 0, static_cast<uint32_T>
                  ((qrmanager->mrows - 1) + 1) * sizeof(real_T));
    }
  } else {
    scalarLB = (qrmanager->mrows / 2) << 1;
    vectorUB = scalarLB - 2;
    for (nullStartIdx = 0; nullStartIdx <= vectorUB; nullStartIdx += 2) {
      tmp = _mm_loadu_pd(&objective->grad[nullStartIdx]);
      _mm_storeu_pd(&solution->searchDir[nullStartIdx], _mm_mul_pd(tmp,
        _mm_set1_pd(-1.0)));
    }

    for (nullStartIdx = scalarLB; nullStartIdx <= nVar; nullStartIdx++) {
      solution->searchDir[nullStartIdx] = -objective->grad[nullStartIdx];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        temp = 1.4901161193847656E-6 * static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (ix = 0; ix <= nVar; ix++) {
          nullStartIdx = (nVar + 1) * ix - 1;
          A_maxDiag_idx = 38 * ix - 1;
          for (ia = 0; ia <= nVar; ia++) {
            cholmanager->FMat[(A_maxDiag_idx + ia) + 1] = H[(ia + nullStartIdx)
              + 1];
          }
        }

        if (qrmanager->mrows < 1) {
          A_maxDiag_idx = -1;
        } else {
          A_maxDiag_idx = 0;
          if (qrmanager->mrows > 1) {
            smax = std::abs(cholmanager->FMat[0]);
            for (ia = 2; ia <= nVar + 1; ia++) {
              s = std::abs(cholmanager->FMat[(ia - 1) * 39]);
              if (s > smax) {
                A_maxDiag_idx = ia - 1;
                smax = s;
              }
            }
          }
        }

        cholmanager->regTol_ = std::fmax(std::abs(cholmanager->FMat[38 *
          A_maxDiag_idx + A_maxDiag_idx]) * 2.2204460492503131E-16, std::abs
          (temp));
        longitudinal_mpc_fullColLDL2_(cholmanager, qrmanager->mrows, temp);
        if (cholmanager->ConvexCheck) {
          nullStartIdx = 1;
          do {
            exitg1 = 0;
            if (nullStartIdx - 1 <= nVar) {
              if (cholmanager->FMat[((nullStartIdx - 1) * 38 + nullStartIdx) - 1]
                  <= 0.0) {
                cholmanager->info = -nullStartIdx;
                exitg1 = 1;
              } else {
                nullStartIdx++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          nullStartIdx = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (nVars = 0; nVars < nullStartIdx; nVars++) {
              lastColC = nVars * 38 + nVars;
              A_maxDiag_idx = (nullStartIdx - nVars) - 2;
              for (ia = 0; ia <= A_maxDiag_idx; ia++) {
                ix = (ia + nVars) + 1;
                solution->searchDir[ix] -= cholmanager->FMat[(ia + lastColC) + 1]
                  * solution->searchDir[nVars];
              }
            }
          }

          A_maxDiag_idx = cholmanager->ndims - 1;
          for (ix = 0; ix <= A_maxDiag_idx; ix++) {
            solution->searchDir[ix] /= cholmanager->FMat[38 * ix + ix];
          }

          if (cholmanager->ndims != 0) {
            for (nVar = nullStartIdx; nVar >= 1; nVar--) {
              br = (nVar - 1) * 38 - 1;
              temp = solution->searchDir[nVar - 1];
              for (ia = nullStartIdx; ia >= nVar + 1; ia--) {
                temp -= cholmanager->FMat[br + ia] * solution->searchDir[ia - 1];
              }

              solution->searchDir[nVar - 1] = temp;
            }
          }
        }
      }
    } else {
      nullStartIdx_tmp = 38 * qrmanager->ncols;
      nullStartIdx = nullStartIdx_tmp + 1;
      if (objective->objtype == 5) {
        for (ia = 0; ia < mNull_tmp; ia++) {
          memspace->workspace_float[ia] = -qrmanager->Q[(qrmanager->ncols + ia) *
            38 + nVar];
        }

        longitudinal_mpc_xgemv_b4tv(qrmanager->mrows, mNull_tmp, qrmanager->Q,
          nullStartIdx_tmp + 1, memspace->workspace_float, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          nVars = qrmanager->mrows;
          if ((qrmanager->mrows != 0) && (mNull_tmp != 0)) {
            lastColC = (mNull_tmp - 1) * 474;
            for (ia = 0; ia <= lastColC; ia += 474) {
              br = ia + nVars;
              for (ix = ia + 1; ix <= br; ix++) {
                memspace->workspace_float[ix - 1] = 0.0;
              }
            }

            br = nullStartIdx_tmp;
            for (A_maxDiag_idx = 0; A_maxDiag_idx <= lastColC; A_maxDiag_idx +=
                 474) {
              ar = 0;
              e = br + nVars;
              for (ia = br + 1; ia <= e; ia++) {
                g = A_maxDiag_idx + nVars;
                scalarLB = ((((g - A_maxDiag_idx) / 2) << 1) + A_maxDiag_idx) +
                  1;
                vectorUB = scalarLB - 2;
                for (ix = A_maxDiag_idx + 1; ix <= vectorUB; ix += 2) {
                  tmp = _mm_loadu_pd(&memspace->workspace_float[ix - 1]);
                  _mm_storeu_pd(&memspace->workspace_float[ix - 1], _mm_add_pd
                                (_mm_mul_pd(_mm_loadu_pd(&H[((ar + ix) -
                    A_maxDiag_idx) - 1]), _mm_set1_pd(qrmanager->Q[ia - 1])),
                                 tmp));
                }

                for (ix = scalarLB; ix <= g; ix++) {
                  memspace->workspace_float[ix - 1] += H[((ar + ix) -
                    A_maxDiag_idx) - 1] * qrmanager->Q[ia - 1];
                }

                ar += nVars;
              }

              br += 38;
            }
          }

          if (mNull_tmp != 0) {
            lastColC = (mNull_tmp - 1) * 38;
            for (ia = 0; ia <= lastColC; ia += 38) {
              br = ia + mNull_tmp;
              for (ix = ia + 1; ix <= br; ix++) {
                cholmanager->FMat[ix - 1] = 0.0;
              }
            }

            br = -1;
            for (A_maxDiag_idx = 0; A_maxDiag_idx <= lastColC; A_maxDiag_idx +=
                 38) {
              ar = nullStartIdx_tmp - 1;
              e = A_maxDiag_idx + mNull_tmp;
              for (ix = A_maxDiag_idx + 1; ix <= e; ix++) {
                temp = 0.0;
                for (ia = 0; ia < nVars; ia++) {
                  temp += qrmanager->Q[(ia + ar) + 1] *
                    memspace->workspace_float[(ia + br) + 1];
                }

                cholmanager->FMat[ix - 1] += temp;
                ar += 38;
              }

              br += 474;
            }
          }
        }

        temp = 1.4901161193847656E-6 * static_cast<real_T>(mNull_tmp);
        cholmanager->ndims = mNull_tmp;
        A_maxDiag_idx = 0;
        if (mNull_tmp > 1) {
          smax = std::abs(cholmanager->FMat[0]);
          for (ia = 2; ia <= mNull_tmp; ia++) {
            s = std::abs(cholmanager->FMat[(ia - 1) * 39]);
            if (s > smax) {
              A_maxDiag_idx = ia - 1;
              smax = s;
            }
          }
        }

        cholmanager->regTol_ = std::fmax(std::abs(cholmanager->FMat[38 *
          A_maxDiag_idx + A_maxDiag_idx]) * 2.2204460492503131E-16, temp);
        longitudinal_mpc_fullColLDL2_(cholmanager, mNull_tmp, temp);
        if (cholmanager->ConvexCheck) {
          ix = 1;
          do {
            exitg1 = 0;
            if (ix - 1 <= mNull_tmp - 1) {
              if (cholmanager->FMat[((ix - 1) * 38 + ix) - 1] <= 0.0) {
                cholmanager->info = -ix;
                exitg1 = 1;
              } else {
                ix++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows != 0) {
            std::memset(&memspace->workspace_float[0], 0, static_cast<uint32_T>
                        (mNull_tmp) * sizeof(real_T));
            A_maxDiag_idx = ((mNull_tmp - 1) * 38 + nullStartIdx_tmp) + 1;
            for (nVars = nullStartIdx; nVars <= A_maxDiag_idx; nVars += 38) {
              temp = 0.0;
              br = nVars + nVar;
              for (ia = nVars; ia <= br; ia++) {
                temp += qrmanager->Q[ia - 1] * objective->grad[ia - nVars];
              }

              ix = div_nde_s32_floor((nVars - nullStartIdx_tmp) - 1, 38);
              memspace->workspace_float[ix] -= temp;
            }
          }

          nullStartIdx = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (nVars = 0; nVars < nullStartIdx; nVars++) {
              lastColC = nVars * 38 + nVars;
              A_maxDiag_idx = (nullStartIdx - nVars) - 2;
              for (ia = 0; ia <= A_maxDiag_idx; ia++) {
                ix = (ia + nVars) + 1;
                memspace->workspace_float[ix] -= cholmanager->FMat[(ia +
                  lastColC) + 1] * memspace->workspace_float[nVars];
              }
            }
          }

          A_maxDiag_idx = cholmanager->ndims - 1;
          for (ix = 0; ix <= A_maxDiag_idx; ix++) {
            memspace->workspace_float[ix] /= cholmanager->FMat[38 * ix + ix];
          }

          if (cholmanager->ndims != 0) {
            for (nVar = nullStartIdx; nVar >= 1; nVar--) {
              br = (nVar - 1) * 38 - 1;
              temp = memspace->workspace_float[nVar - 1];
              for (ia = nullStartIdx; ia >= nVar + 1; ia--) {
                temp -= cholmanager->FMat[br + ia] * memspace->
                  workspace_float[ia - 1];
              }

              memspace->workspace_float[nVar - 1] = temp;
            }
          }

          longitudinal_mpc_xgemv_b4tv(qrmanager->mrows, mNull_tmp, qrmanager->Q,
            nullStartIdx_tmp + 1, memspace->workspace_float, solution->searchDir);
        }
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

real_T longitudinal_mpc::longitudinal_mpc_xnrm2_b4(int32_T n, const real_T x[38])
{
  real_T y;
  y = 0.0;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[0]);
    } else {
      real_T scale;
      int32_T b;
      scale = 3.3121686421112381E-170;
      b = static_cast<uint8_T>(n) - 1;
      for (int32_T b_k{0}; b_k <= b; b_k++) {
        real_T absxk;
        absxk = std::abs(x[b_k]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return y;
}

void longitudinal_mpc::longitudinal_mpc_xgemv_b4tv3(int32_T m, const real_T A
  [15162], const real_T x[38], real_T y[18012])
{
  /* Start for MATLABSystem: '<S1>/solver' */
  for (int32_T b_iy{0}; b_iy <= 396; b_iy += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[b_iy]);
    _mm_storeu_pd(&y[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (int32_T b_iy{398}; b_iy < 399; b_iy++) {
    y[b_iy] = -y[b_iy];
  }

  for (int32_T b_iy{0}; b_iy <= 15124; b_iy += 38) {
    real_T c;
    int32_T d;
    int32_T ia;
    c = 0.0;
    d = b_iy + m;
    for (ia = b_iy + 1; ia <= d; ia++) {
      c += x[(ia - b_iy) - 1] * A[ia - 1];
    }

    ia = div_nde_s32_floor(b_iy, 38);
    y[ia] += c;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_xgemv_b4tv3e(int32_T m, const real_T A
  [15162], const real_T x[38], real_T y[18012])
{
  /* Start for MATLABSystem: '<S1>/solver' */
  std::memset(&y[474], 0, 399U * sizeof(real_T));
  for (int32_T b_iy{0}; b_iy <= 15124; b_iy += 38) {
    real_T c;
    int32_T b;
    int32_T ia;
    c = 0.0;
    b = b_iy + m;
    for (ia = b_iy + 1; ia <= b; ia++) {
      c += x[(ia - b_iy) - 1] * A[ia - 1];
    }

    ia = div_nde_s32_floor(b_iy, 38) + 474;
    y[ia] += c;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_ratiotest(const real_T solution_xstar[38],
  const real_T solution_searchDir[38], real_T workspace[18012], int32_T
  workingset_nVar, const real_T workingset_Aineq[15162], const real_T
  workingset_bineq[399], const real_T workingset_lb[38], const real_T
  workingset_ub[38], const int32_T workingset_indexLB[38], const int32_T
  workingset_indexUB[38], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[474],
  const int32_T workingset_nWConstr[5], real_T toldelta, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx, real_T
  *b_toldelta)
{
  real_T tmp[2];
  real_T alphaTemp;
  real_T denomTol;
  real_T p_max;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T pk_corrected;
  real_T workspace_0;
  int32_T b;
  int32_T b_k;
  int32_T workingset_indexLB_0;

  /* Start for MATLABSystem: '<S1>/solver' */
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  p_max = 0.0;
  denomTol = 2.2204460492503131E-13 * longitudinal_mpc_xnrm2_b4(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[2] < 399) {
    std::memcpy(&workspace[0], &workingset_bineq[0], 399U * sizeof(real_T));
    longitudinal_mpc_xgemv_b4tv3(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    longitudinal_mpc_xgemv_b4tv3e(workingset_nVar, workingset_Aineq,
      solution_searchDir, workspace);
    for (b_k = 0; b_k < 399; b_k++) {
      workspace_0 = workspace[b_k + 474];
      if ((workspace_0 > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + b_k) - 1])) {
        phaseOneCorrectionX = workspace[b_k];
        alphaTemp = std::fmin(std::abs(phaseOneCorrectionX - toldelta), (1.0E-5
          - phaseOneCorrectionX) + toldelta) / workspace_0;
        if ((alphaTemp <= *alpha) && (std::abs(workspace_0) > p_max)) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = b_k + 1;
          *newBlocking = true;
        }

        alphaTemp = std::fmin(std::abs(phaseOneCorrectionX), 1.0E-5 -
                              phaseOneCorrectionX) / workspace_0;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = b_k + 1;
          *newBlocking = true;
          p_max = std::abs(workspace_0);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set_pd
      (solution_searchDir[workingset_nVar - 1], solution_xstar[workingset_nVar -
       1]), _mm_set1_pd(0.0)));
    phaseOneCorrectionX = tmp[0];
    phaseOneCorrectionP = tmp[1];
    b = workingset_sizes[3] - 2;
    for (b_k = 0; b_k <= b; b_k++) {
      workingset_indexLB_0 = workingset_indexLB[b_k];
      pk_corrected = -solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + b_k) - 1])) {
        workspace_0 = -solution_xstar[workingset_indexLB_0 - 1] -
          workingset_lb[workingset_indexLB_0 - 1];
        alphaTemp = (workspace_0 - toldelta) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-5 - alphaTemp) /
          pk_corrected;
        if ((alphaTemp <= *alpha) && (std::abs(pk_corrected) > p_max)) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = b_k + 1;
          *newBlocking = true;
        }

        alphaTemp = workspace_0 - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-5 - alphaTemp) /
          pk_corrected;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = b_k + 1;
          *newBlocking = true;
          p_max = std::abs(pk_corrected);
        }
      }
    }

    b_k = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    phaseOneCorrectionX = solution_searchDir[b_k];
    if ((-phaseOneCorrectionX > denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      workspace_0 = -solution_xstar[b_k] - workingset_lb[b_k];
      alphaTemp = workspace_0 - toldelta;
      alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-5 - alphaTemp) /
        -phaseOneCorrectionX;
      if ((alphaTemp <= *alpha) && (std::abs(phaseOneCorrectionX) > p_max)) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      alphaTemp = std::fmin(std::abs(workspace_0), 1.0E-5 - workspace_0) /
        -phaseOneCorrectionX;
      if (alphaTemp < *alpha) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        p_max = std::abs(phaseOneCorrectionX);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set_pd
      (solution_searchDir[workingset_nVar - 1], solution_xstar[workingset_nVar -
       1]), _mm_set1_pd(0.0)));
    phaseOneCorrectionX = tmp[0];
    phaseOneCorrectionP = tmp[1];
    b = static_cast<uint8_T>(workingset_sizes[4]) - 1;
    for (b_k = 0; b_k <= b; b_k++) {
      workingset_indexLB_0 = workingset_indexUB[b_k];
      pk_corrected = solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + b_k) - 1])) {
        workspace_0 = solution_xstar[workingset_indexLB_0 - 1] -
          workingset_ub[workingset_indexLB_0 - 1];
        alphaTemp = (workspace_0 - toldelta) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-5 - alphaTemp) /
          pk_corrected;
        if ((alphaTemp <= *alpha) && (std::abs(pk_corrected) > p_max)) {
          *alpha = alphaTemp;
          *constrType = 5;
          *constrIdx = b_k + 1;
          *newBlocking = true;
        }

        alphaTemp = workspace_0 - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-5 - alphaTemp) /
          pk_corrected;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 5;
          *constrIdx = b_k + 1;
          *newBlocking = true;
          p_max = std::abs(pk_corrected);
        }
      }
    }
  }

  *b_toldelta = toldelta + 6.608625846508183E-7;
  if (p_max > 0.0) {
    *alpha = std::fmax(*alpha, 6.608625846508183E-7 / p_max);
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  *alpha = std::fmin(*alpha, 1.0);

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal__feasibleratiotest(const real_T
  solution_xstar[38], const real_T solution_searchDir[38], real_T workspace
  [18012], int32_T workingset_nVar, const real_T workingset_Aineq[15162], const
  real_T workingset_bineq[399], const real_T workingset_lb[38], const real_T
  workingset_ub[38], const int32_T workingset_indexLB[38], const int32_T
  workingset_indexUB[38], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[474],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  real_T tmp[2];
  real_T alphaTemp;
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T ratio;
  int32_T b;
  int32_T b_k;
  int32_T workingset_indexLB_0;

  /* Start for MATLABSystem: '<S1>/solver' */
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  denomTol = 2.2204460492503131E-13 * longitudinal_mpc_xnrm2_b4(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[2] < 399) {
    std::memcpy(&workspace[0], &workingset_bineq[0], 399U * sizeof(real_T));
    longitudinal_mpc_xgemv_b4tv3(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    longitudinal_mpc_xgemv_b4tv3e(workingset_nVar, workingset_Aineq,
      solution_searchDir, workspace);
    for (b_k = 0; b_k < 399; b_k++) {
      ratio = workspace[b_k + 474];
      if ((ratio > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + b_k) - 1])) {
        alphaTemp = workspace[b_k];
        alphaTemp = std::fmin(std::abs(alphaTemp), 1.0E-5 - alphaTemp) / ratio;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = b_k + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set_pd
      (solution_searchDir[workingset_nVar - 1], solution_xstar[workingset_nVar -
       1]), _mm_set1_pd(static_cast<real_T>(isPhaseOne))));
    phaseOneCorrectionX = tmp[0];
    phaseOneCorrectionP = tmp[1];
    b = workingset_sizes[3] - 2;
    for (b_k = 0; b_k <= b; b_k++) {
      workingset_indexLB_0 = workingset_indexLB[b_k];
      alphaTemp = -solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((alphaTemp > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + b_k) - 1])) {
        ratio = (-solution_xstar[workingset_indexLB_0 - 1] -
                 workingset_lb[workingset_indexLB_0 - 1]) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), 1.0E-5 - ratio) / alphaTemp;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = b_k + 1;
          *newBlocking = true;
        }
      }
    }

    b_k = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    alphaTemp = -solution_searchDir[b_k];
    if ((alphaTemp > denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar[b_k] - workingset_lb[b_k];
      alphaTemp = std::fmin(std::abs(ratio), 1.0E-5 - ratio) / alphaTemp;
      if (alphaTemp < *alpha) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set_pd
      (solution_searchDir[workingset_nVar - 1], solution_xstar[workingset_nVar -
       1]), _mm_set1_pd(static_cast<real_T>(isPhaseOne))));
    phaseOneCorrectionX = tmp[0];
    phaseOneCorrectionP = tmp[1];
    b = static_cast<uint8_T>(workingset_sizes[4]) - 1;
    for (b_k = 0; b_k <= b; b_k++) {
      workingset_indexLB_0 = workingset_indexUB[b_k];
      alphaTemp = solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((alphaTemp > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + b_k) - 1])) {
        ratio = (solution_xstar[workingset_indexLB_0 - 1] -
                 workingset_ub[workingset_indexLB_0 - 1]) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), 1.0E-5 - ratio) / alphaTemp;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 5;
          *constrIdx = b_k + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    *alpha = std::fmin(*alpha, 1.0);
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longit_checkUnboundedOrIllPosed
  (suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, const
   siuq7rbPRrhRxtZY0x4sHID_longi_T *objective)
{
  /* Start for MATLABSystem: '<S1>/solver' */
  if (objective->objtype == 5) {
    if (longitudinal_mpc_xnrm2_b4(objective->nvar, solution->searchDir) > 100.0 *
        static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8) {
      solution->state = 3;
    } else {
      solution->state = 4;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::long_addBoundToActiveSetMatrix_(const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj, int32_T TYPE, int32_T idx_local,
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_obj)
{
  int32_T colOffset;
  int32_T idx_bnd_local;

  /* Start for MATLABSystem: '<S1>/solver' */
  *b_obj = *obj;
  b_obj->nWConstr[TYPE - 1] = obj->nWConstr[TYPE - 1] + 1;
  b_obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  b_obj->nActiveConstr = obj->nActiveConstr + 1;
  b_obj->Wid[obj->nActiveConstr] = TYPE;
  b_obj->Wlocalidx[obj->nActiveConstr] = idx_local;
  colOffset = 38 * obj->nActiveConstr - 1;
  if (TYPE == 5) {
    /* Start for MATLABSystem: '<S1>/solver' */
    idx_bnd_local = obj->indexUB[idx_local - 1];
    b_obj->bwset[obj->nActiveConstr] = obj->ub[idx_bnd_local - 1];
  } else {
    /* Start for MATLABSystem: '<S1>/solver' */
    idx_bnd_local = obj->indexLB[idx_local - 1];
    b_obj->bwset[obj->nActiveConstr] = obj->lb[idx_bnd_local - 1];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  if (static_cast<uint8_T>(idx_bnd_local - 1) - 1 >= 0) {
    std::memset(&b_obj->ATwset[colOffset + 1], 0, static_cast<uint32_T>((((
      static_cast<uint8_T>(idx_bnd_local - 1) - 1) + colOffset) - colOffset) + 1)
                * sizeof(real_T));
  }

  b_obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) *
    2.0 - 1.0;

  /* Start for MATLABSystem: '<S1>/solver' */
  if (idx_bnd_local + 1 <= obj->nVar) {
    std::memset(&b_obj->ATwset[(idx_bnd_local + colOffset) + 1], 0, static_cast<
                uint32_T>(((obj->nVar + colOffset) - idx_bnd_local) - colOffset)
                * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    b_obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

void longitudinal_mpc::lo_checkStoppingAndUpdateFval_b(int32_T activeSetChangeID,
  const real_T f[37], suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution,
  srUNuce4MmfvHoJodBzBujH_longi_T *memspace, const
  siuq7rbPRrhRxtZY0x4sHID_longi_T *objective, svwK1qKQ5yAVvUFh54r0LBD_longi_T
  *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, real_T
  options_ObjectiveLimit, real_T runTimeOptions_ConstrRelTolFact, boolean_T
  updateFval, int32_T *b_activeSetChangeID, boolean_T *b_updateFval)
{
  real_T b;
  real_T tempMaxConstr;
  boolean_T nonDegenerateWset;

  /* Start for MATLABSystem: '<S1>/solver' */
  *b_updateFval = updateFval;
  *b_activeSetChangeID = activeSetChangeID;
  solution->iterations++;
  if ((solution->iterations >= 850) && ((solution->state != 1) ||
       (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    longitudinal_mpc_B.workingset_k = *workingset;
    longi_maxConstraintViolation_b4(&longitudinal_mpc_B.workingset_k,
      solution->xstar, &b, workingset);
    solution->maxConstr = b;
    tempMaxConstr = b;
    if (objective->objtype == 5) {
      tempMaxConstr = b - solution->xstar[objective->nvar - 1];
    }

    if (tempMaxConstr > 1.0E-5 * runTimeOptions_ConstrRelTolFact) {
      if (static_cast<uint8_T>(objective->nvar) - 1 >= 0) {
        std::memcpy(&solution->searchDir[0], &solution->xstar[0],
                    static_cast<uint32_T>((static_cast<uint8_T>(objective->nvar)
          - 1) + 1) * sizeof(real_T));
      }

      nonDegenerateWset = longitu_feasibleX0ForWorkingSet
        (memspace->workspace_float, solution->searchDir, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *b_activeSetChangeID = 0;
      longitudinal_mpc_B.workingset_k = *workingset;
      longi_maxConstraintViolation_b4(&longitudinal_mpc_B.workingset_k,
        solution->searchDir, &tempMaxConstr, workingset);
      if (tempMaxConstr < b) {
        if (static_cast<uint8_T>(objective->nvar) - 1 >= 0) {
          std::memcpy(&solution->xstar[0], &solution->searchDir[0],
                      static_cast<uint32_T>((static_cast<uint8_T>
            (objective->nvar) - 1) + 1) * sizeof(real_T));
        }

        solution->maxConstr = tempMaxConstr;
      }
    }
  }

  if (updateFval) {
    b = longitudina_computeFval_ReuseHx(objective, memspace->workspace_float, f,
      solution->xstar);
    solution->fstar = b;
    if ((b < options_ObjectiveLimit) && ((solution->state != 0) ||
         (objective->objtype != 5))) {
      solution->state = 2;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_iterate_b(const real_T H[1369], const
  real_T f[37], suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution,
  srUNuce4MmfvHoJodBzBujH_longi_T *memspace, svwK1qKQ5yAVvUFh54r0LBD_longi_T
  *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager,
  sSQjeS6UA6ous3QrgyAXHyC_longi_T *cholmanager, siuq7rbPRrhRxtZY0x4sHID_longi_T *
  objective, real_T options_ObjectiveLimit, real_T options_StepTolerance, real_T
  runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  boolean_T runTimeOptions_RemainFeasible)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T c;
  real_T c_tmp;
  real_T normDelta;
  real_T s;
  real_T tolDelta;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T exitg1;
  int32_T globalActiveConstrIdx;
  int32_T iAw0;
  int32_T iQR0;
  int32_T idx;
  int32_T ix;
  int32_T iyend;
  int32_T nVar_tmp_tmp;
  int32_T workingIdx;
  boolean_T guard1;
  boolean_T guard11;
  boolean_T guard2;
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;

  /* Start for MATLABSystem: '<S1>/solver' */
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  tolDelta = 6.7434957617430445E-7;
  nVar_tmp_tmp = workingset->nVar;
  globalActiveConstrIdx = 0;
  longitudina_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = longitudina_computeFval_ReuseHx(objective,
    memspace->workspace_float, f, solution->xstar);
  if (solution->iterations < 850) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  std::memset(&solution->lambda[0], 0, 474U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard11 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          workingIdx = (workingset->nActiveConstr - 1) * 38;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          iQR0 = 38 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            iyend = iQR0 + qrmanager->mrows;
            if (iQR0 + 1 <= iyend) {
              std::memset(&qrmanager->QR[iQR0], 0, static_cast<uint32_T>(iyend -
                iQR0) * sizeof(real_T));
            }

            iyend = (qrmanager->mrows - 1) * 38;
            for (idx = 1; idx <= iyend + 1; idx += 38) {
              c = 0.0;
              ix = idx + qrmanager->mrows;
              for (iAw0 = idx; iAw0 < ix; iAw0++) {
                c += workingset->ATwset[(workingIdx + iAw0) - idx] *
                  qrmanager->Q[iAw0 - 1];
              }

              ix = div_nde_s32_floor(idx - 1, 38) + iQR0;
              qrmanager->QR[ix] += c;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          for (idx = qrmanager->mrows - 2; idx + 2 > qrmanager->ncols; idx--) {
            ix = (qrmanager->ncols - 1) * 38 + idx;
            longitudinal_mpc_xrotg(qrmanager->QR[ix], qrmanager->QR[ix + 1],
              &qrmanager->QR[ix], &c, &normDelta, &s);
            qrmanager->QR[ix + 1] = c;
            workingIdx = 38 * idx;
            iAw0 = qrmanager->mrows;
            if (qrmanager->mrows >= 1) {
              for (iyend = 0; iyend < iAw0; iyend++) {
                iQR0 = workingIdx + iyend;
                c_tmp = qrmanager->Q[iQR0 + 38];
                c = c_tmp * s + qrmanager->Q[iQR0] * normDelta;
                qrmanager->Q[iQR0 + 38] = c_tmp * normDelta - qrmanager->Q[iQR0]
                  * s;
                qrmanager->Q[iQR0] = c;
              }
            }
          }
          break;

         case -1:
          longitudinal_m_deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;

         default:
          longitudinal_mpc_factorQR(qrmanager, workingset->ATwset, nVar_tmp_tmp,
            workingset->nActiveConstr);
          longitudinal_mpc_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        longitudinal_mpc_compute_deltax(H, solution, memspace, qrmanager,
          cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = longitudinal_mpc_xnrm2_b4(nVar_tmp_tmp,
            solution->searchDir);
          guard11 = true;
        }
      } else {
        if (nVar_tmp_tmp - 1 >= 0) {
          std::memset(&solution->searchDir[0], 0, static_cast<uint32_T>
                      (nVar_tmp_tmp) * sizeof(real_T));
        }

        normDelta = 0.0;
        guard11 = true;
      }

      if (guard11) {
        if ((!subProblemChanged) || (normDelta < options_StepTolerance) ||
            (workingset->nActiveConstr >= nVar_tmp_tmp)) {
          workingIdx = qrmanager->ncols;
          if (qrmanager->ncols > 0) {
            guard1 = false;
            if (objective->objtype != 4) {
              normDelta = 100.0 * static_cast<real_T>(qrmanager->mrows) *
                2.2204460492503131E-16;
              updateFval = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
              if (updateFval) {
                idx = qrmanager->ncols;
                guard2 = false;
                if (qrmanager->mrows < qrmanager->ncols) {
                  iyend = ((qrmanager->ncols - 1) * 38 + qrmanager->mrows) - 1;
                  while ((idx > qrmanager->mrows) && (std::abs(qrmanager->
                           QR[iyend]) >= normDelta)) {
                    idx--;
                    iyend -= 38;
                  }

                  updateFval = (idx == qrmanager->mrows);
                  if (!updateFval) {
                  } else {
                    guard2 = true;
                  }
                } else {
                  guard2 = true;
                }

                if (guard2) {
                  iyend = ((idx - 1) * 38 + idx) - 1;
                  while ((idx >= 1) && (std::abs(qrmanager->QR[iyend]) >=
                                        normDelta)) {
                    idx--;
                    iyend -= 39;
                  }

                  updateFval = (idx == 0);
                }
              }

              if (!updateFval) {
                solution->state = -7;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              if (qrmanager->mrows != 0) {
                std::memset(&memspace->workspace_float[0], 0, static_cast<
                            uint32_T>((qrmanager->ncols - 1) + 1) * sizeof
                            (real_T));
                iyend = (qrmanager->ncols - 1) * 38;
                for (idx = 1; idx <= iyend + 1; idx += 38) {
                  c = 0.0;
                  ix = idx + qrmanager->mrows;
                  for (iAw0 = idx; iAw0 < ix; iAw0++) {
                    c += qrmanager->Q[iAw0 - 1] * objective->grad[iAw0 - idx];
                  }

                  ix = div_nde_s32_floor(idx - 1, 38);
                  memspace->workspace_float[ix] += c;
                }
              }

              for (idx = workingIdx; idx >= 1; idx--) {
                iQR0 = ((idx - 1) * 38 + idx) - 1;
                memspace->workspace_float[idx - 1] /= qrmanager->QR[iQR0];
                iyend = idx - 2;
                for (iAw0 = 0; iAw0 <= iyend; iAw0++) {
                  ix = (idx - iAw0) - 2;
                  memspace->workspace_float[ix] -= qrmanager->QR[(iQR0 - iAw0) -
                    1] * memspace->workspace_float[idx - 1];
                }
              }

              idx = (qrmanager->ncols / 2) << 1;
              iAw0 = idx - 2;
              for (iyend = 0; iyend <= iAw0; iyend += 2) {
                tmp = _mm_loadu_pd(&memspace->workspace_float[iyend]);
                _mm_storeu_pd(&solution->lambda[iyend], _mm_mul_pd(tmp,
                  _mm_set1_pd(-1.0)));
              }

              for (iyend = idx; iyend < workingIdx; iyend++) {
                solution->lambda[iyend] = -memspace->workspace_float[iyend];
              }
            }
          }

          if ((solution->state != -7) || (workingset->nActiveConstr >
               nVar_tmp_tmp)) {
            workingIdx = 0;
            normDelta = 0.0 * runTimeOptions_ProbRelTolFactor *
              static_cast<real_T>(TYPE != 5);
            iyend = workingset->nWConstr[0] + workingset->nWConstr[1];
            iAw0 = workingset->nActiveConstr;
            for (idx = iyend + 1; idx <= iAw0; idx++) {
              c = solution->lambda[idx - 1];
              if (c < normDelta) {
                normDelta = c;
                workingIdx = idx;
              }
            }

            if (workingIdx == 0) {
              solution->state = 1;
            } else {
              activeSetChangeID = -1;
              globalActiveConstrIdx = workingIdx;
              subProblemChanged = true;
              longitudinal_mpc_removeConstr(workingset, workingIdx);
              if (workingIdx < workingset->nActiveConstr + 1) {
                solution->lambda[workingIdx - 1] = solution->lambda
                  [workingset->nActiveConstr];
              }

              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            workingIdx = workingset->nActiveConstr - 1;
            activeSetChangeID = 0;
            globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            longitudinal_mpc_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[workingIdx] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            longitudinal__feasibleratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_float, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, updateFval, &normDelta, &newBlocking, &idx,
              &workingIdx);
          } else {
            longitudinal_mpc_ratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_float, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, tolDelta, &normDelta, &newBlocking, &idx,
              &workingIdx, &tolDelta);
          }

          if (newBlocking) {
            switch (idx) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                workingIdx) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] = workingIdx;
              activeSetChangeID = (workingIdx - 1) * 38;
              iAw0 = (workingset->nActiveConstr - 1) * 38;
              iyend = workingset->nVar;
              for (idx = 0; idx < iyend; idx++) {
                workingset->ATwset[iAw0 + idx] = workingset->
                  Aineq[activeSetChangeID + idx];
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->bineq[workingIdx - 1];
              break;

             case 4:
              longitudinal_mpc_B.workingset_c = *workingset;
              long_addBoundToActiveSetMatrix_(&longitudinal_mpc_B.workingset_c,
                4, workingIdx, workingset);
              break;

             default:
              longitudinal_mpc_B.workingset_c = *workingset;
              long_addBoundToActiveSetMatrix_(&longitudinal_mpc_B.workingset_c,
                5, workingIdx, workingset);
              break;
            }

            activeSetChangeID = 1;
          } else {
            longit_checkUnboundedOrIllPosed(solution, objective);
            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(normDelta == 0.0)) {
            idx = (nVar_tmp_tmp / 2) << 1;
            iAw0 = idx - 2;
            for (iyend = 0; iyend <= iAw0; iyend += 2) {
              tmp = _mm_loadu_pd(&solution->searchDir[iyend]);
              tmp_0 = _mm_loadu_pd(&solution->xstar[iyend]);
              _mm_storeu_pd(&solution->xstar[iyend], _mm_add_pd(_mm_mul_pd
                (_mm_set1_pd(normDelta), tmp), tmp_0));
            }

            for (iyend = idx; iyend < nVar_tmp_tmp; iyend++) {
              solution->xstar[iyend] += normDelta * solution->searchDir[iyend];
            }
          }

          longitudina_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        lo_checkStoppingAndUpdateFval_b(activeSetChangeID, f, solution, memspace,
          objective, workingset, qrmanager, options_ObjectiveLimit,
          runTimeOptions_ConstrRelTolFact, updateFval, &activeSetChangeID,
          &updateFval);
      }
    } else {
      if (!updateFval) {
        solution->fstar = longitudina_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_phaseone_b4(const real_T H[1369], const
  real_T f[37], suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution,
  srUNuce4MmfvHoJodBzBujH_longi_T *memspace, const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
  *qrmanager, sSQjeS6UA6ous3QrgyAXHyC_longi_T *cholmanager, const
  sL9bDKomAYkxZSVrG9w6En_longit_T *runTimeOptions,
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_workingset, siuq7rbPRrhRxtZY0x4sHID_longi_T
  *objective, s7GW9uShiIXbHYZwohNmyqD_longi_T *options)
{
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T mConstr;
  static const char_T t0_FiniteDifferenceType[7]{ 'f', 'o', 'r', 'w', 'a', 'r',
    'd' };

  static const char_T t0_Algorithm[10]{ 'a', 'c', 't', 'i', 'v', 'e', '-', 's',
    'e', 't' };

  static const char_T t0_SolverName[8]{ 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  boolean_T exitg1;

  /* Start for MATLABSystem: '<S1>/solver' */
  options->NonFiniteSupport = true;
  options->IterDisplaySQP = false;
  options->InitDamping = 0.01;
  for (mConstr = 0; mConstr < 7; mConstr++) {
    options->FiniteDifferenceType[mConstr] = t0_FiniteDifferenceType[mConstr];
  }

  options->SpecifyObjectiveGradient = false;
  options->ScaleProblem = false;
  options->SpecifyConstraintGradient = false;
  options->FiniteDifferenceStepSize = -1.0;
  options->MaxFunctionEvaluations = -1.0;
  options->IterDisplayQP = false;
  options->PricingTolerance = 0.0;
  for (mConstr = 0; mConstr < 10; mConstr++) {
    options->Algorithm[mConstr] = t0_Algorithm[mConstr];
  }

  options->ConstraintTolerance = 1.0E-5;
  options->OptimalityTolerance = 1.0E-6;
  options->MaxIterations = 850.0;
  options->FunctionTolerance = (rtInf);
  for (mConstr = 0; mConstr < 8; mConstr++) {
    options->SolverName[mConstr] = t0_SolverName[mConstr];
  }

  options->CheckGradients = false;
  options->DiffMaxChange = (rtInf);
  options->DiffMinChange = 0.0;
  options->Diagnostics[0] = 'o';
  options->Display[0] = 'o';
  options->FunValCheck[0] = 'o';
  options->Diagnostics[1] = 'f';
  options->Display[1] = 'f';
  options->FunValCheck[1] = 'f';
  options->Diagnostics[2] = 'f';
  options->Display[2] = 'f';
  options->FunValCheck[2] = 'f';
  options->UseParallel = false;
  options->LinearSolver[0] = 'a';
  options->LinearSolver[1] = 'u';
  options->LinearSolver[2] = 't';
  options->LinearSolver[3] = 'o';
  options->SubproblemAlgorithm[0] = 'c';
  options->SubproblemAlgorithm[1] = 'g';
  solution->xstar[37] = solution->maxConstr + 1.0;
  *b_workingset = *workingset;
  longitudinal_mpc_setProblemType(b_workingset, 1);
  idxStartIneq = b_workingset->nWConstr[0] + b_workingset->nWConstr[1];
  idxEndIneq = b_workingset->nActiveConstr;
  for (mConstr = idxStartIneq + 1; mConstr <= idxEndIneq; mConstr++) {
    b_workingset->isActiveConstr[(b_workingset->isActiveIdx[b_workingset->
      Wid[mConstr - 1] - 1] + b_workingset->Wlocalidx[mConstr - 1]) - 2] = false;
  }

  b_workingset->nWConstr[2] = 0;
  b_workingset->nWConstr[3] = 0;
  b_workingset->nWConstr[4] = 0;
  b_workingset->nActiveConstr = b_workingset->nWConstr[0] +
    b_workingset->nWConstr[1];
  std::memset(&objective->grad[0], 0, 38U * sizeof(real_T));
  std::memset(&objective->Hx[0], 0, 37U * sizeof(real_T));
  objective->maxVar = 38;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->prev_objtype = 3;
  objective->prev_nvar = 37;
  objective->prev_hasLinear = true;
  objective->objtype = 5;
  objective->nvar = 38;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-5 * runTimeOptions->ConstrRelTolFactor;
  solution->fstar = longitudinal_mpc_computeFval(objective,
    memspace->workspace_float, H, f, solution->xstar);
  solution->state = 5;
  longitudinal_mpc_iterate_b(H, f, solution, memspace, b_workingset, qrmanager,
    cholmanager, objective, options->ObjectiveLimit, 1.4901161193847657E-10,
    runTimeOptions->ConstrRelTolFactor, runTimeOptions->ProbRelTolFactor,
    runTimeOptions->RemainFeasible);
  if (b_workingset->isActiveConstr[(b_workingset->isActiveIdx[3] +
       b_workingset->sizes[3]) - 2]) {
    mConstr = b_workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (mConstr + 1 <= b_workingset->nActiveConstr)) {
      if ((b_workingset->Wid[mConstr] == 4) && (b_workingset->Wlocalidx[mConstr]
           == b_workingset->sizes[3])) {
        longitudinal_mpc_removeConstr(b_workingset, mConstr + 1);
        exitg1 = true;
      } else {
        mConstr++;
      }
    }
  }

  mConstr = b_workingset->nActiveConstr;
  while ((mConstr > b_workingset->sizes[0]) && (mConstr > workingset->nVar)) {
    longitudinal_mpc_removeConstr(b_workingset, mConstr);
    mConstr--;
  }

  solution->maxConstr = solution->xstar[37];
  longitudinal_mpc_setProblemType(b_workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

int32_T longitudinal_mpc::longitudin_RemoveDependentEq__b
  (srUNuce4MmfvHoJodBzBujH_longi_T *memspace, const
   svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *
   qrmanager)
{
  int32_T b_idx_col;
  int32_T e_tmp;
  int32_T mTotalWorkingEq;
  int32_T nDepInd;
  int32_T nVar;

  /* Start for MATLABSystem: '<S1>/solver' */
  mTotalWorkingEq = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq > 0) {
    e_tmp = static_cast<uint8_T>(workingset->nVar) - 1;
    for (nVar = 0; nVar < mTotalWorkingEq; nVar++) {
      for (b_idx_col = 0; b_idx_col <= e_tmp; b_idx_col++) {
        qrmanager->QR[nVar + 38 * b_idx_col] = workingset->ATwset[38 * nVar +
          b_idx_col];
      }
    }

    nDepInd = longitud_ComputeNumDependentEq_(qrmanager, workingset->bwset,
      mTotalWorkingEq, workingset->nVar);
    if (nDepInd > 0) {
      for (nVar = 0; nVar < mTotalWorkingEq; nVar++) {
        b_idx_col = 38 * nVar - 1;
        std::memcpy(&qrmanager->QR[b_idx_col + 1], &workingset->ATwset[b_idx_col
                    + 1], static_cast<uint32_T>(((e_tmp + b_idx_col) - b_idx_col)
          + 1) * sizeof(real_T));
      }

      longitudina_IndexOfDependentEq_(memspace->workspace_int,
        workingset->nWConstr[0], nDepInd, qrmanager, workingset->nVar,
        mTotalWorkingEq);
      longitudinal_mpc_countsort(memspace->workspace_int, nDepInd,
        memspace->workspace_sort, 1, mTotalWorkingEq);
      for (nVar = nDepInd; nVar >= 1; nVar--) {
        longitudinal_mpc_removeEqConstr(workingset, memspace->workspace_int[nVar
          - 1]);
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
  return nDepInd;
}

void longitudinal_mpc::longitud_PresolveWorkingSet_b4t(const
  suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, srUNuce4MmfvHoJodBzBujH_longi_T
  *memspace, svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset,
  sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, suKEVDQMOZ0XRzxi1HugtZH_longi_T
  *b_solution)
{
  real_T constrViolation;
  int32_T i;
  int32_T idxEndIneq;
  int32_T idxStartIneq_tmp;
  boolean_T guard1;
  boolean_T okWorkingSet;

  /* Start for MATLABSystem: '<S1>/solver' */
  *b_solution = *solution;
  b_solution->state = 82;
  i = longitudin_RemoveDependentEq__b(memspace, workingset, qrmanager);
  if ((i != -1) && (workingset->nActiveConstr <= 38)) {
    longitudin_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    std::memcpy(&b_solution->xstar[0], &solution->xstar[0], 38U * sizeof(real_T));
    okWorkingSet = longitu_feasibleX0ForWorkingSet(memspace->workspace_float,
      b_solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      longitudin_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = longitu_feasibleX0ForWorkingSet(memspace->workspace_float,
        b_solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        b_solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        longitudinal_mpc_B.workingset_cx = *workingset;
        longi_maxConstraintViolation_b4(&longitudinal_mpc_B.workingset_cx,
          b_solution->xstar, &constrViolation, workingset);
        if (constrViolation > 1.0E-5) {
          b_solution->state = -2;
        }
      }
    }
  } else {
    b_solution->state = -3;
    idxStartIneq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
    idxEndIneq = workingset->nActiveConstr;
    for (i = idxStartIneq_tmp + 1; i <= idxEndIneq; i++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->Wid[i - 1]
        - 1] + workingset->Wlocalidx[i - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = idxStartIneq_tmp;
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

boolean_T longitudinal_mpc::longitudinal_mpc_strcmp(const char_T a[8])
{
  int32_T b_kstr;
  boolean_T b_bool;
  static const char_T tmp[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  static const char_T tmp_0[8]{ 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  b_bool = false;

  /* Start for MATLABSystem: '<S1>/solver' */
  b_kstr = 1;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (b_kstr - 1 < 8) {
      if (tmp[static_cast<int32_T>(a[b_kstr - 1])] != tmp[static_cast<int32_T>
          (tmp_0[b_kstr - 1])]) {
        exitg1 = 1;
      } else {
        b_kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return b_bool;
}

void longitudinal_mpc::longitudin_computeFirstOrderOpt
  (suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, const
   siuq7rbPRrhRxtZY0x4sHID_longi_T *objective, const
   svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, real_T workspace[18012])
{
  real_T infNorm;
  int32_T b_k;
  boolean_T exitg1;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&workspace[0], &objective->grad[0], static_cast<uint32_T>((
    static_cast<uint8_T>(workingset->nVar) - 1) + 1) * sizeof(real_T));
  if (workingset->nActiveConstr != 0) {
    int32_T b;
    int32_T ix;
    ix = 0;
    b = (workingset->nActiveConstr - 1) * 38;
    for (b_k = 1; b_k <= b + 1; b_k += 38) {
      int32_T d;
      d = b_k + workingset->nVar;
      for (int32_T k{b_k}; k < d; k++) {
        int32_T tmp;
        tmp = k - b_k;
        workspace[tmp] += workingset->ATwset[k - 1] * solution->lambda[ix];
      }

      ix++;
    }
  }

  infNorm = 0.0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= static_cast<uint8_T>(workingset->nVar) - 1)) {
    real_T abs_workspace_i;
    abs_workspace_i = std::abs(workspace[b_k]);
    if (std::isnan(abs_workspace_i)) {
      infNorm = (rtNaN);
      exitg1 = true;
    } else {
      infNorm = std::fmax(infNorm, abs_workspace_i);
      b_k++;
    }
  }

  solution->firstorderopt = infNorm;

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_phaseone_b4t(const real_T H[1369], const
  real_T f[37], suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution,
  srUNuce4MmfvHoJodBzBujH_longi_T *memspace, const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
  *qrmanager, sSQjeS6UA6ous3QrgyAXHyC_longi_T *cholmanager,
  siuq7rbPRrhRxtZY0x4sHID_longi_T *objective, s7GW9uShiIXbHYZwohNmyqD_longi_T
  *options, const sL9bDKomAYkxZSVrG9w6En_longit_T *runTimeOptions,
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_workingset)
{
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T mConstr;
  boolean_T exitg1;

  /* Start for MATLABSystem: '<S1>/solver' */
  solution->xstar[37] = solution->maxConstr + 1.0;
  *b_workingset = *workingset;
  if (workingset->probType == 3) {
    mConstr = 1;
  } else {
    mConstr = 4;
  }

  longitudinal_mpc_setProblemType(b_workingset, mConstr);
  idxStartIneq = b_workingset->nWConstr[0] + b_workingset->nWConstr[1];
  idxEndIneq = b_workingset->nActiveConstr;
  for (mConstr = idxStartIneq + 1; mConstr <= idxEndIneq; mConstr++) {
    b_workingset->isActiveConstr[(b_workingset->isActiveIdx[b_workingset->
      Wid[mConstr - 1] - 1] + b_workingset->Wlocalidx[mConstr - 1]) - 2] = false;
  }

  b_workingset->nWConstr[2] = 0;
  b_workingset->nWConstr[3] = 0;
  b_workingset->nWConstr[4] = 0;
  b_workingset->nActiveConstr = b_workingset->nWConstr[0] +
    b_workingset->nWConstr[1];
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = 38;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-5 * runTimeOptions->ConstrRelTolFactor;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->fstar = longitudinal_mpc_computeFval(objective,
    memspace->workspace_float, H, f, solution->xstar);
  solution->state = 5;
  longitudinal_mpc_iterate_b(H, f, solution, memspace, b_workingset, qrmanager,
    cholmanager, objective, options->ObjectiveLimit, options->StepTolerance,
    runTimeOptions->ConstrRelTolFactor, runTimeOptions->ProbRelTolFactor,
    runTimeOptions->RemainFeasible);
  if (b_workingset->isActiveConstr[(b_workingset->isActiveIdx[3] +
       b_workingset->sizes[3]) - 2]) {
    mConstr = b_workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (mConstr + 1 <= b_workingset->nActiveConstr)) {
      if ((b_workingset->Wid[mConstr] == 4) && (b_workingset->Wlocalidx[mConstr]
           == b_workingset->sizes[3])) {
        longitudinal_mpc_removeConstr(b_workingset, mConstr + 1);
        exitg1 = true;
      } else {
        mConstr++;
      }
    }
  }

  mConstr = b_workingset->nActiveConstr;
  while ((mConstr > b_workingset->sizes[0]) && (mConstr > workingset->nVar)) {
    longitudinal_mpc_removeConstr(b_workingset, mConstr);
    mConstr--;
  }

  solution->maxConstr = solution->xstar[37];
  longitudinal_mpc_setProblemType(b_workingset, workingset->probType);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_driver(const real_T H[1369], const
  real_T f[37], suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, const real_T
  memspace_workspace_float[18012], const int32_T memspace_workspace_int[474],
  const int32_T memspace_workspace_sort[474], const
  svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, sSQjeS6UA6ous3QrgyAXHyC_longi_T
  *cholmanager, sL9bDKomAYkxZSVrG9w6En_longit_T runTimeOptions,
  srUNuce4MmfvHoJodBzBujH_longi_T *b_memspace, svwK1qKQ5yAVvUFh54r0LBD_longi_T
  *b_workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager,
  siuq7rbPRrhRxtZY0x4sHID_longi_T *objective)
{
  s7GW9uShiIXbHYZwohNmyqD_longi_T e_options;
  real_T b;
  real_T tmp;
  int32_T c;
  int32_T i;
  static const char_T t2_FiniteDifferenceType[7]{ 'f', 'o', 'r', 'w', 'a', 'r',
    'd' };

  static const char_T t2_Algorithm[10]{ 'a', 'c', 't', 'i', 'v', 'e', '-', 's',
    'e', 't' };

  static const char_T t2_SolverName[8]{ 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  boolean_T guard1;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memset(&objective->grad[0], 0, 38U * sizeof(real_T));
  std::memset(&objective->Hx[0], 0, 37U * sizeof(real_T));
  objective->hasLinear = true;
  objective->nvar = 37;
  objective->maxVar = 38;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  solution->iterations = 0;
  runTimeOptions.RemainFeasible = true;
  c = static_cast<uint8_T>(workingset->sizes[0]) - 1;
  for (i = 0; i <= c; i++) {
    solution->xstar[workingset->indexFixed[i] - 1] = workingset->ub
      [workingset->indexFixed[i] - 1];
  }

  c = static_cast<uint16_T>(workingset->sizes[3]) - 1;
  for (i = 0; i <= c; i++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + i) - 1]) {
      solution->xstar[workingset->indexLB[i] - 1] = -workingset->lb
        [workingset->indexLB[i] - 1];
    }
  }

  c = static_cast<uint8_T>(workingset->sizes[4]) - 1;
  for (i = 0; i <= c; i++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[4] + i) - 1]) {
      solution->xstar[workingset->indexUB[i] - 1] = workingset->ub
        [workingset->indexUB[i] - 1];
    }
  }

  *b_workingset = *workingset;
  longitudinal_mpc_B.solution_l = *solution;
  longitudi_PresolveWorkingSet_b4(&longitudinal_mpc_B.solution_l,
    memspace_workspace_float, memspace_workspace_int, memspace_workspace_sort,
    b_workingset, solution, b_memspace, qrmanager);
  e_options.NonFiniteSupport = true;
  e_options.IterDisplaySQP = false;
  e_options.InitDamping = 0.01;
  for (i = 0; i < 7; i++) {
    e_options.FiniteDifferenceType[i] = t2_FiniteDifferenceType[i];
  }

  e_options.SpecifyObjectiveGradient = false;
  e_options.ScaleProblem = false;
  e_options.SpecifyConstraintGradient = false;
  e_options.FiniteDifferenceStepSize = -1.0;
  e_options.MaxFunctionEvaluations = -1.0;
  e_options.IterDisplayQP = false;
  e_options.PricingTolerance = 0.0;
  for (i = 0; i < 10; i++) {
    e_options.Algorithm[i] = t2_Algorithm[i];
  }

  e_options.ObjectiveLimit = -1.0E+20;
  e_options.ConstraintTolerance = 1.0E-5;
  e_options.OptimalityTolerance = 1.0E-6;
  e_options.StepTolerance = 1.0E-8;
  e_options.MaxIterations = 850.0;
  e_options.FunctionTolerance = (rtInf);
  for (i = 0; i < 8; i++) {
    e_options.SolverName[i] = t2_SolverName[i];
  }

  e_options.CheckGradients = false;
  e_options.DiffMaxChange = (rtInf);
  e_options.DiffMinChange = 0.0;
  e_options.Diagnostics[0] = 'o';
  e_options.Display[0] = 'o';
  e_options.FunValCheck[0] = 'o';
  e_options.Diagnostics[1] = 'f';
  e_options.Display[1] = 'f';
  e_options.FunValCheck[1] = 'f';
  e_options.Diagnostics[2] = 'f';
  e_options.Display[2] = 'f';
  e_options.FunValCheck[2] = 'f';
  e_options.UseParallel = false;
  e_options.LinearSolver[0] = 'a';
  e_options.LinearSolver[1] = 'u';
  e_options.LinearSolver[2] = 't';
  e_options.LinearSolver[3] = 'o';
  e_options.SubproblemAlgorithm[0] = 'c';
  e_options.SubproblemAlgorithm[1] = 'g';
  if (solution->state >= 0) {
    solution->iterations = 0;
    longitudinal_mpc_B.b_workingset = *b_workingset;
    longi_maxConstraintViolation_b4(&longitudinal_mpc_B.b_workingset,
      solution->xstar, &b, b_workingset);
    solution->maxConstr = b;
    tmp = 1.0E-5 * runTimeOptions.ConstrRelTolFactor;
    guard1 = false;
    if (b > tmp) {
      longitudinal_mpc_B.b_workingset = *b_workingset;
      longitudinal_mpc_phaseone_b4(H, f, solution, b_memspace,
        &longitudinal_mpc_B.b_workingset, qrmanager, cholmanager,
        &runTimeOptions, b_workingset, objective, &e_options);
      if (solution->state == 0) {
      } else {
        longitudinal_mpc_B.b_workingset = *b_workingset;
        longi_maxConstraintViolation_b4(&longitudinal_mpc_B.b_workingset,
          solution->xstar, &b, b_workingset);
        solution->maxConstr = b;
        if (b > tmp) {
          std::memset(&solution->lambda[0], 0, 474U * sizeof(real_T));
          solution->fstar = longitudinal_mpc_computeFval(objective,
            b_memspace->workspace_float, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (b > 0.0) {
            if (static_cast<uint8_T>(workingset->nVar) - 1 >= 0) {
              std::memcpy(&solution->searchDir[0], &solution->xstar[0],
                          static_cast<uint32_T>((static_cast<uint8_T>
                (workingset->nVar) - 1) + 1) * sizeof(real_T));
            }

            longitudinal_mpc_B.b_workingset = *b_workingset;
            longitudinal_mpc_B.solution_l = *solution;
            longitud_PresolveWorkingSet_b4t(&longitudinal_mpc_B.solution_l,
              b_memspace, &longitudinal_mpc_B.b_workingset, qrmanager, solution);
            longi_maxConstraintViolation_b4(&longitudinal_mpc_B.b_workingset,
              solution->xstar, &b, b_workingset);
            if (b >= solution->maxConstr) {
              solution->maxConstr = b;
              if (static_cast<uint8_T>(workingset->nVar) - 1 >= 0) {
                std::memcpy(&solution->xstar[0], &solution->searchDir[0],
                            static_cast<uint32_T>((static_cast<uint8_T>
                  (workingset->nVar) - 1) + 1) * sizeof(real_T));
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      longitudinal_mpc_iterate_b(H, f, solution, b_memspace, b_workingset,
        qrmanager, cholmanager, objective, e_options.ObjectiveLimit,
        e_options.StepTolerance, runTimeOptions.ConstrRelTolFactor,
        runTimeOptions.ProbRelTolFactor, true);
      if (longitudinal_mpc_strcmp(e_options.SolverName) && (solution->state !=
           -6)) {
        longitudinal_mpc_B.b_workingset = *b_workingset;
        longi_maxConstraintViolation_b4(&longitudinal_mpc_B.b_workingset,
          solution->xstar, &solution->maxConstr, b_workingset);
        longitudin_computeFirstOrderOpt(solution, objective, b_workingset,
          b_memspace->workspace_float);
        runTimeOptions.RemainFeasible = false;
        while ((solution->iterations < 850) && ((solution->state == -7) ||
                ((solution->state == 1) && ((solution->maxConstr > tmp) ||
                  (solution->firstorderopt > 1.0E-6 *
                   runTimeOptions.ProbRelTolFactor))))) {
          longitu_feasibleX0ForWorkingSet(b_memspace->workspace_float,
            solution->xstar, b_workingset, qrmanager);
          longitudinal_mpc_B.solution_l = *solution;
          longitud_PresolveWorkingSet_b4t(&longitudinal_mpc_B.solution_l,
            b_memspace, b_workingset, qrmanager, solution);
          longitudinal_mpc_phaseone_b4t(H, f, solution, b_memspace, b_workingset,
            qrmanager, cholmanager, objective, &e_options, &runTimeOptions,
            &longitudinal_mpc_B.b_workingset);
          longitudinal_mpc_iterate_b(H, f, solution, b_memspace,
            &longitudinal_mpc_B.b_workingset, qrmanager, cholmanager, objective,
            e_options.ObjectiveLimit, e_options.StepTolerance,
            runTimeOptions.ConstrRelTolFactor, runTimeOptions.ProbRelTolFactor,
            false);
          longi_maxConstraintViolation_b4(&longitudinal_mpc_B.b_workingset,
            solution->xstar, &solution->maxConstr, b_workingset);
          longitudin_computeFirstOrderOpt(solution, objective, b_workingset,
            b_memspace->workspace_float);
        }
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_linearForm__b(boolean_T obj_hasLinear,
  int32_T obj_nvar, real_T workspace[38], const real_T H[1369], const real_T f
  [37], const real_T x[38])
{
  int32_T fMultiplier;

  /* Start for MATLABSystem: '<S1>/solver' */
  fMultiplier = 0;
  if (obj_hasLinear) {
    if (static_cast<uint8_T>(obj_nvar) - 1 >= 0) {
      std::memcpy(&workspace[0], &f[0], static_cast<uint32_T>
                  ((static_cast<uint8_T>(obj_nvar) - 1) + 1) * sizeof(real_T));
    }

    fMultiplier = 1;
  }

  if (obj_nvar != 0) {
    int32_T d;
    int32_T ix;
    if (fMultiplier != 1) {
      std::memset(&workspace[0], 0, static_cast<uint32_T>((static_cast<uint8_T>
        (obj_nvar) - 1) + 1) * sizeof(real_T));
    }

    ix = 0;
    d = (obj_nvar - 1) * obj_nvar;
    for (int32_T b_i{1}; obj_nvar < 0 ? b_i >= d + 1 : b_i <= d + 1; b_i +=
         obj_nvar) {
      int32_T e;
      e = b_i + obj_nvar;
      for (fMultiplier = b_i; fMultiplier < e; fMultiplier++) {
        int32_T tmp;
        tmp = fMultiplier - b_i;
        workspace[tmp] += H[fMultiplier - 1] * x[ix];
      }

      ix++;
    }
  }

  /* End of Start for MATLABSystem: '<S1>/solver' */
}

void longitudinal_mpc::longitudinal_mpc_quadprog(const real_T H[1369], const
  real_T f[37], const real_T Aineq[14763], const real_T bineq[399], const real_T
  ub[37], const real_T x0[37], real_T x[37], real_T *fval, real_T *exitflag,
  char_T output_algorithm[10], real_T *output_firstorderopt, real_T
  *output_constrviolation, real_T *output_iterations,
  sZnXTmmXLG06QsvMaQjKaGF_longi_T *lambda)
{
  __m128d tmp;
  sL9bDKomAYkxZSVrG9w6En_longit_T expl_temp;
  siuq7rbPRrhRxtZY0x4sHID_longi_T QPObjective;
  real_T H_infnrm;
  real_T colSum;
  real_T f_infnrm;
  real_T tol;
  int32_T memspace_workspace_int[474];
  int32_T b_i;
  int32_T c;
  int32_T colPos;
  int32_T i;
  int32_T idxFillStart;
  static const char_T tmp_0[10]{ 'a', 'c', 't', 'i', 'v', 'e', '-', 's', 'e',
    't' };

  longitudinal_mpc_B.solution.fstar = 0.0;
  longitudinal_mpc_B.solution.firstorderopt = 0.0;
  std::memset(&longitudinal_mpc_B.solution.lambda[0], 0, 474U * sizeof(real_T));
  longitudinal_mpc_B.solution.state = 0;
  longitudinal_mpc_B.solution.maxConstr = 0.0;
  longitudinal_mpc_B.solution.iterations = 0;
  std::memset(&longitudinal_mpc_B.solution.searchDir[0], 0, 38U * sizeof(real_T));

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&longitudinal_mpc_B.solution.xstar[0], &x0[0], 37U * sizeof(real_T));
  longitudinal_m_factoryConstruct(&longitudinal_mpc_B.CholRegManager);
  longitudinal_mpc_B.CholRegManager.scaleFactor = 100.0;
  longitudinal_mpc_B.b_WorkingSet.mConstr = 0;
  longitudinal_mpc_B.b_WorkingSet.mConstrOrig = 0;
  longitudinal_mpc_B.b_WorkingSet.mConstrMax = 474;
  longitudinal_mpc_B.b_WorkingSet.nVar = 37;
  longitudinal_mpc_B.b_WorkingSet.nVarOrig = 37;
  longitudinal_mpc_B.b_WorkingSet.nVarMax = 38;
  longitudinal_mpc_B.b_WorkingSet.ldA = 38;
  std::memset(&longitudinal_mpc_B.b_WorkingSet.Aineq[0], 0, 15162U * sizeof
              (real_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.bineq[0], 0, 399U * sizeof(real_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.lb[0], 0, 38U * sizeof(real_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.ub[0], 0, 38U * sizeof(real_T));
  longitudinal_mpc_B.b_WorkingSet.mEqRemoved = 0;
  std::memset(&longitudinal_mpc_B.b_WorkingSet.ATwset[0], 0, 18012U * sizeof
              (real_T));
  longitudinal_mpc_B.b_WorkingSet.nActiveConstr = 0;
  std::memset(&longitudinal_mpc_B.b_WorkingSet.bwset[0], 0, 474U * sizeof(real_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.maxConstrWorkspace[0], 0, 474U *
              sizeof(real_T));
  for (i = 0; i < 5; i++) {
    longitudinal_mpc_B.b_WorkingSet.sizes[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.sizesNormal[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.sizesPhaseOne[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.sizesRegularized[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.sizesRegPhaseOne[i] = 0;
  }

  for (i = 0; i < 6; i++) {
    longitudinal_mpc_B.b_WorkingSet.isActiveIdx[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.isActiveIdxNormal[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.isActiveIdxPhaseOne[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.isActiveIdxRegularized[i] = 0;
    longitudinal_mpc_B.b_WorkingSet.isActiveIdxRegPhaseOne[i] = 0;
  }

  std::memset(&longitudinal_mpc_B.b_WorkingSet.isActiveConstr[0], 0, 474U *
              sizeof(boolean_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.Wid[0], 0, 474U * sizeof(int32_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.Wlocalidx[0], 0, 474U * sizeof
              (int32_T));
  for (i = 0; i < 5; i++) {
    longitudinal_mpc_B.b_WorkingSet.nWConstr[i] = 0;
  }

  longitudinal_mpc_B.b_WorkingSet.probType = 3;
  longitudinal_mpc_B.b_WorkingSet.SLACK0 = 1.0E-5;

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memset(&longitudinal_mpc_B.b_WorkingSet.indexLB[0], 0, 38U * sizeof
              (int32_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.indexUB[0], 0, 38U * sizeof
              (int32_T));
  std::memset(&longitudinal_mpc_B.b_WorkingSet.indexFixed[0], 0, 38U * sizeof
              (int32_T));
  longitudinal_mpc_compressBounds(longitudinal_mpc_B.b_WorkingSet.indexLB,
    longitudinal_mpc_B.b_WorkingSet.indexUB,
    longitudinal_mpc_B.b_WorkingSet.indexFixed, ub, &idxFillStart, &i, &colPos);
  longitudinal_mpc_B.b_WorkingSet_m = longitudinal_mpc_B.b_WorkingSet;
  longitudinal_mpc_loadProblem(&longitudinal_mpc_B.b_WorkingSet_m, Aineq, bineq,
    idxFillStart, i, ub, colPos, &longitudinal_mpc_B.b_WorkingSet);

  /* Start for MATLABSystem: '<S1>/solver' */
  longitudinal_mpc_setProblemType(&longitudinal_mpc_B.b_WorkingSet, 3);
  idxFillStart = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[2];
  for (i = idxFillStart; i < 475; i++) {
    longitudinal_mpc_B.b_WorkingSet.isActiveConstr[i - 1] = false;
  }

  longitudinal_mpc_B.b_WorkingSet.nWConstr[0] =
    longitudinal_mpc_B.b_WorkingSet.sizes[0];
  longitudinal_mpc_B.b_WorkingSet.nWConstr[1] = 0;
  longitudinal_mpc_B.b_WorkingSet.nWConstr[2] = 0;
  longitudinal_mpc_B.b_WorkingSet.nWConstr[3] = 0;
  longitudinal_mpc_B.b_WorkingSet.nWConstr[4] = 0;
  longitudinal_mpc_B.b_WorkingSet.nActiveConstr =
    longitudinal_mpc_B.b_WorkingSet.nWConstr[0];

  /* Start for MATLABSystem: '<S1>/solver' */
  idxFillStart = static_cast<uint8_T>(longitudinal_mpc_B.b_WorkingSet.sizes[0])
    - 1;
  for (i = 0; i <= idxFillStart; i++) {
    longitudinal_mpc_B.b_WorkingSet.Wid[i] = 1;

    /* Start for MATLABSystem: '<S1>/solver' */
    longitudinal_mpc_B.b_WorkingSet.Wlocalidx[i] = i + 1;
    longitudinal_mpc_B.b_WorkingSet.isActiveConstr[i] = true;

    /* Start for MATLABSystem: '<S1>/solver' */
    colPos = 38 * i - 1;
    c = longitudinal_mpc_B.b_WorkingSet.indexFixed[i] - 2;
    if (c >= 0) {
      std::memset(&longitudinal_mpc_B.b_WorkingSet.ATwset[colPos + 1], 0,
                  static_cast<uint32_T>(((c + colPos) - colPos) + 1) * sizeof
                  (real_T));
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    longitudinal_mpc_B.b_WorkingSet.ATwset[longitudinal_mpc_B.b_WorkingSet.indexFixed
      [i] + colPos] = 1.0;
    c = longitudinal_mpc_B.b_WorkingSet.indexFixed[i];
    b_i = longitudinal_mpc_B.b_WorkingSet.nVar;
    if (c + 1 <= b_i) {
      std::memset(&longitudinal_mpc_B.b_WorkingSet.ATwset[(c + colPos) + 1], 0,
                  static_cast<uint32_T>(((b_i + colPos) - c) - colPos) * sizeof
                  (real_T));
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    longitudinal_mpc_B.b_WorkingSet.bwset[i] =
      longitudinal_mpc_B.b_WorkingSet.ub[longitudinal_mpc_B.b_WorkingSet.indexFixed
      [i] - 1];
  }

  longitudinal_mpc_B.b_WorkingSet.SLACK0 = 0.0;
  tol = 1.0;
  for (idxFillStart = 0; idxFillStart < 399; idxFillStart++) {
    colSum = 0.0;

    /* Start for MATLABSystem: '<S1>/solver' */
    colPos = 38 * idxFillStart;
    for (i = 0; i < 37; i++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      colSum += std::abs(longitudinal_mpc_B.b_WorkingSet.Aineq[i + colPos]);
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    tol = std::fmax(tol, colSum);
  }

  H_infnrm = 0.0;
  f_infnrm = 0.0;
  for (idxFillStart = 0; idxFillStart < 37; idxFillStart++) {
    colSum = 0.0;
    for (i = 0; i < 37; i++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      colSum += std::abs(H[37 * idxFillStart + i]);
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    H_infnrm = std::fmax(H_infnrm, colSum);
    f_infnrm = std::fmax(f_infnrm, std::abs(f[idxFillStart]));
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  expl_temp.RemainFeasible = false;
  expl_temp.ProbRelTolFactor = std::fmax(std::fmax(tol, f_infnrm), H_infnrm);
  expl_temp.ConstrRelTolFactor = tol;
  expl_temp.MaxIterations = 850;
  std::memcpy(&longitudinal_mpc_B.b_memspace_b[0],
              &longitudinal_mpc_B.b_memspace.workspace_float[0], 18012U * sizeof
              (real_T));
  longitudinal_mpc_B.b_WorkingSet_m = longitudinal_mpc_B.b_WorkingSet;

  /* Start for MATLABSystem: '<S1>/solver' */
  longitudinal_mpc_driver(H, f, &longitudinal_mpc_B.solution,
    longitudinal_mpc_B.b_memspace_b, memspace_workspace_int,
    memspace_workspace_int, &longitudinal_mpc_B.b_WorkingSet_m,
    &longitudinal_mpc_B.CholRegManager, expl_temp,
    &longitudinal_mpc_B.b_memspace, &longitudinal_mpc_B.b_WorkingSet,
    &longitudinal_mpc_B.QRManager, &QPObjective);
  std::memcpy(&x[0], &longitudinal_mpc_B.solution.xstar[0], 37U * sizeof(real_T));
  if (longitudinal_mpc_B.solution.state > 0) {
    *fval = longitudinal_mpc_B.solution.fstar;
  } else {
    /* Start for MATLABSystem: '<S1>/solver' */
    *fval = longitudinal_mpc_computeFval(&QPObjective,
      longitudinal_mpc_B.b_memspace.workspace_float, H, f,
      longitudinal_mpc_B.solution.xstar);
  }

  switch (longitudinal_mpc_B.solution.state) {
   case 2:
    longitudinal_mpc_B.solution.state = -3;
    break;

   case -3:
    longitudinal_mpc_B.solution.state = -2;
    break;

   case 4:
    longitudinal_mpc_B.solution.state = -2;
    break;
  }

  *exitflag = longitudinal_mpc_B.solution.state;
  if (longitudinal_mpc_B.solution.state == -2) {
    longitudinal_mpc_B.solution.firstorderopt = (rtInf);
  } else if (longitudinal_mpc_B.solution.state <= 0) {
    longitudinal_mpc_B.b_WorkingSet_m = longitudinal_mpc_B.b_WorkingSet;
    longi_maxConstraintViolation_b4(&longitudinal_mpc_B.b_WorkingSet_m,
      longitudinal_mpc_B.solution.xstar, &colSum,
      &longitudinal_mpc_B.b_WorkingSet);
    longitudinal_mpc_B.solution.maxConstr = colSum;

    /* Start for MATLABSystem: '<S1>/solver' */
    if (colSum <= 1.0E-5 * tol) {
      switch (QPObjective.objtype) {
       case 5:
        if (QPObjective.nvar - 2 >= 0) {
          std::memset(&QPObjective.grad[0], 0, static_cast<uint32_T>
                      ((QPObjective.nvar - 2) + 1) * sizeof(real_T));
        }

        QPObjective.grad[QPObjective.nvar - 1] = QPObjective.gammaScalar;
        break;

       case 3:
        longitudinal_mpc_linearForm__b(QPObjective.hasLinear, QPObjective.nvar,
          QPObjective.grad, H, f, longitudinal_mpc_B.solution.xstar);
        break;

       default:
        longitudinal_mpc_linearForm__b(QPObjective.hasLinear, QPObjective.nvar,
          QPObjective.grad, H, f, longitudinal_mpc_B.solution.xstar);
        idxFillStart = QPObjective.nvar;
        colPos = ((((37 - QPObjective.nvar) / 2) << 1) + QPObjective.nvar) + 1;
        c = colPos - 2;
        for (i = idxFillStart + 1; i <= c; i += 2) {
          tmp = _mm_loadu_pd(&longitudinal_mpc_B.solution.xstar[i - 1]);
          _mm_storeu_pd(&QPObjective.grad[i - 1], _mm_mul_pd(tmp, _mm_set1_pd
            (0.0)));
        }

        for (i = colPos; i < 38; i++) {
          QPObjective.grad[i - 1] = longitudinal_mpc_B.solution.xstar[i - 1] *
            0.0;
        }
        break;
      }

      longitudin_computeFirstOrderOpt(&longitudinal_mpc_B.solution, &QPObjective,
        &longitudinal_mpc_B.b_WorkingSet,
        longitudinal_mpc_B.b_memspace.workspace_float);
    } else {
      longitudinal_mpc_B.solution.firstorderopt = (rtInf);
    }
  }

  for (colPos = 0; colPos < 10; colPos++) {
    output_algorithm[colPos] = tmp_0[colPos];
  }

  *output_firstorderopt = longitudinal_mpc_B.solution.firstorderopt;

  /* Start for MATLABSystem: '<S1>/solver' */
  *output_constrviolation = std::fmax(0.0, longitudinal_mpc_B.solution.maxConstr);
  *output_iterations = longitudinal_mpc_B.solution.iterations;
  std::memset(&lambda->ineqlin[0], 0, 399U * sizeof(real_T));
  std::memset(&lambda->lower[0], 0, 37U * sizeof(real_T));
  std::memset(&lambda->upper[0], 0, 37U * sizeof(real_T));
  if (longitudinal_mpc_B.b_WorkingSet.nActiveConstr > 0) {
    /* Start for MATLABSystem: '<S1>/solver' */
    idxFillStart = static_cast<uint16_T>
      (((longitudinal_mpc_B.b_WorkingSet.sizes[0] +
         longitudinal_mpc_B.b_WorkingSet.sizes[3]) +
        longitudinal_mpc_B.b_WorkingSet.sizes[4]) + 399) - 1;
    for (i = 0; i <= idxFillStart; i++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal_mpc_B.b_memspace.workspace_float[i] =
        longitudinal_mpc_B.solution.lambda[i];
      longitudinal_mpc_B.solution.lambda[i] = 0.0;
    }

    idxFillStart = 0;

    /* Start for MATLABSystem: '<S1>/solver' */
    i = 0;
    while ((i + 1 <= longitudinal_mpc_B.b_WorkingSet.nActiveConstr) &&
           (longitudinal_mpc_B.b_WorkingSet.Wid[i] <= 2)) {
      if (longitudinal_mpc_B.b_WorkingSet.Wid[i] == 1) {
        colPos = -1;
      } else {
        colPos = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[1] - 2;
      }

      longitudinal_mpc_B.solution.lambda[colPos +
        longitudinal_mpc_B.b_WorkingSet.Wlocalidx[i]] =
        longitudinal_mpc_B.b_memspace.workspace_float[idxFillStart];
      idxFillStart++;
      i++;
    }

    while (i + 1 <= longitudinal_mpc_B.b_WorkingSet.nActiveConstr) {
      switch (longitudinal_mpc_B.b_WorkingSet.Wid[i]) {
       case 3:
        colPos = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[2];
        break;

       case 4:
        colPos = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[3];
        break;

       default:
        colPos = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[4];
        break;
      }

      longitudinal_mpc_B.solution.lambda[(colPos +
        longitudinal_mpc_B.b_WorkingSet.Wlocalidx[i]) - 2] =
        longitudinal_mpc_B.b_memspace.workspace_float[idxFillStart];
      idxFillStart++;
      i++;
    }

    std::memset(&lambda->ineqlin[0], 0, 399U * sizeof(real_T));
    std::memset(&lambda->lower[0], 0, 37U * sizeof(real_T));
    std::memset(&lambda->upper[0], 0, 37U * sizeof(real_T));
    idxFillStart = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[1];
    for (i = 1; i < idxFillStart; i++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      colPos = longitudinal_mpc_B.b_WorkingSet.indexFixed[i - 1];
      tol = longitudinal_mpc_B.solution.lambda[i - 1];
      lambda->lower[colPos - 1] = tol;
      lambda->upper[colPos - 1] = tol;
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    idxFillStart = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[1];
    c = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[2];
    for (i = idxFillStart; i < c; i++) {
      /* Check node always fails. would cause program termination and was eliminated */
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    idxFillStart = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[2];
    c = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[3];
    if (idxFillStart <= c - 1) {
      /* Start for MATLABSystem: '<S1>/solver' */
      std::memcpy(&lambda->ineqlin[0],
                  &longitudinal_mpc_B.solution.lambda[idxFillStart + -1],
                  static_cast<uint32_T>(c - idxFillStart) * sizeof(real_T));
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    idxFillStart = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[3];
    b_i = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[4];
    for (i = idxFillStart; i < b_i; i++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      lambda->lower[longitudinal_mpc_B.b_WorkingSet.indexLB[i - idxFillStart] -
        1] = longitudinal_mpc_B.solution.lambda[i - 1];
    }

    /* Start for MATLABSystem: '<S1>/solver' */
    idxFillStart = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[4];
    i = longitudinal_mpc_B.b_WorkingSet.isActiveIdx[5];
    for (colPos = idxFillStart; colPos < i; colPos++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      lambda->upper[longitudinal_mpc_B.b_WorkingSet.indexUB[colPos -
        idxFillStart] - 1] = longitudinal_mpc_B.solution.lambda[colPos - 1];
    }
  }
}

boolean_T longitudinal_mpc::longitudinal_mpc_isMember(real_T a)
{
  int32_T ihi;
  int32_T ilo;
  int32_T n;
  static const int16_T s[14]{ -1235, -1234, -6, -3, -2, -1, 0, 1, 11, 12, 13, 14,
    15, 17 };

  boolean_T exitg1;
  n = 0;
  ilo = 1;
  ihi = 14;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    real_T tmp;
    int32_T imid;
    imid = ((ilo >> 1) + (ihi >> 1)) - 1;
    if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
      imid++;
    }

    tmp = s[imid];
    if (a == tmp) {
      n = imid + 1;
      exitg1 = true;
    } else {
      boolean_T p;
      if (std::isnan(a)) {
        p = false;
      } else {
        p = (a < tmp);
      }

      if (p) {
        ihi = imid;
      } else {
        ilo = imid + 2;
      }
    }
  }

  if (n > 0) {
    while ((n - 1 > 0) && (s[n - 2] == a)) {
      n--;
    }
  }

  return n > 0;
}

flags longitudinal_mpc::longitudi_convert_to_enum_flags(int32_T input)
{
  flags output;

  /* Initialize output value to default value for flags (SOLVED) */
  output = flags::SOLVED;
  if (((input >= -1235) && (input <= -1234)) || (input == -6) || ((input >= -3) &&
       (input <= 1)) || ((input >= 11) && (input <= 15)) || (input == 17)) {
    /* Set output value to input value if it is a member of flags */
    output = static_cast<flags>(input);
  }

  return output;
}

void longitudinal_mpc::longitudinal_mp_solver_stepImpl(solver_longitudinal_mpc_T
  *b_this, const real_T ego_state[3], const real_T output_ref[324], const real_T
  control_ref[81], const real_T time_ref[81], const real_T pos_pred[81], const
  real_T vel_pred[81], const real_T time_pred[81], const real_T param_vec[21],
  real_T *u, real_T X[128], real_T U[32], real_T T[32], real_T E[5], real_T R[4],
  real_T *C, real_T *J, flags *flag, real_T *iters)
{
  __m128d tmp_1;
  sZnXTmmXLG06QsvMaQjKaGF_longi_T lambda;
  real_T rhscon[399];
  real_T v_con_vary[394];
  real_T x[394];
  real_T y[394];
  real_T K[384];
  real_T K_1[384];
  real_T output_ref_0[324];
  real_T b_this_3[128];
  real_T tmp[128];
  real_T b_this_2[37];
  real_T ub[37];
  real_T b_s_pv_tmp[33];
  real_T b_v_pv_tmp[33];
  real_T xT_expected[33];
  real_T T_expected[32];
  real_T b_this_0[32];
  real_T b_this_1[32];
  real_T tmp_0[32];
  real_T K_0[10];
  real_T K_2[10];
  real_T tmp_2[2];
  real_T b_this_4;
  real_T b_this_5;
  real_T expl_temp_0;
  real_T output_ref_1;
  int32_T b_i2;
  int32_T i;
  int32_T kidx;
  char_T expl_temp[10];
  boolean_T tmp_data[394];
  static real_T tmp_3[37]{ 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0,
    3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0,
    3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T tmp_size[1];
  tmp_3[32U] = (rtInf);
  tmp_3[33U] = (rtInf);
  tmp_3[34U] = (rtInf);
  tmp_3[35U] = (rtInf);
  tmp_3[36U] = (rtInf);

  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% Reset error flags if any from last step */
  b_this->is_parameter_errored = false;

  /*  Flag if the MPC has detected error during parameter setting */
  b_this->is_init_errored = false;

  /*  Flag if the MPC has detected error during initialization */
  b_this->is_update_errored = false;

  /*  Flag if the MPC has detected error during matrix update */
  b_this->is_step_errored = false;

  /*  Flag if the MPC has detected error during step */
  b_this->is_solve_errored = false;

  /*  Flag if the MPC has detected error during optimization */
  /* %% Update inputs */
  /*  States */
  b_this->ego_state[0] = ego_state[0];
  b_this->ego_state[1] = ego_state[1];
  b_this->ego_state[2] = ego_state[2];

  /*  MPC parameters */
  /*         %% MPC functions */
  /* %% SETPARAMETERS Set MPC parameters as assigned from inputs. If a parameter is changed trigger an update */
  /*  Check inputs and assign defaults */
  /*  Error check */
  /*  Match this with above last index into param_vec */
  /*  Assign parameters if update detected */
  if (b_this->is_needs_update || (std::abs(b_this->is_eco - param_vec[0]) >
       0.001) || (std::abs(b_this->vel_des - param_vec[1]) > 0.001) || (std::abs
       (b_this->vel_max - param_vec[2]) > 0.001) || (std::abs(b_this->pos_max -
        param_vec[3]) > 0.001) || (std::abs(b_this->d0 - param_vec[4]) > 0.001) ||
      (std::abs(b_this->THref - param_vec[5]) > 0.001) || (std::abs
       (b_this->THsafe - param_vec[6]) > 0.001) || (std::abs(b_this->THmax -
        param_vec[7]) > 0.001) || (std::abs(b_this->qh - param_vec[8]) > 0.001) ||
      (std::abs(b_this->qv - param_vec[9]) > 0.001) || (std::abs(b_this->qu -
        param_vec[10]) > 0.001) || (std::abs(b_this->qdu - param_vec[11]) >
       0.001) || (std::abs(b_this->dual_mode - param_vec[12]) > 0.001) || (std::
       abs(b_this->term_tracking_only - param_vec[13]) > 0.001) || (std::abs
       (b_this->alpha_proc - param_vec[14]) > 0.001) || (std::abs
       (b_this->sigma_proc - param_vec[15]) > 0.001) || (std::abs
       (b_this->sigma_meas - param_vec[16]) > 0.001) || (std::abs
       (b_this->sigma_loca - param_vec[17]) > 0.001) || (std::abs
       (b_this->alpha_acceptance - param_vec[18]) > 0.001) || (std::abs
       (b_this->mean_acceptance - param_vec[19]) > 0.001) || (std::abs
       (b_this->scale_acceptance - param_vec[20]) > 0.001)) {
    b_this->is_needs_update = true;
  }

  if (b_this->is_needs_update) {
    b_this->is_eco = param_vec[0];
    b_this->vel_des = param_vec[1];
    b_this->vel_max = param_vec[2];
    b_this->pos_max = param_vec[3];
    b_this->d0 = param_vec[4];
    b_this->THref = param_vec[5];
    b_this->THsafe = param_vec[6];
    b_this->THmax = param_vec[7];
    b_this->qh = param_vec[8];
    b_this->qv = param_vec[9];
    b_this->qu = param_vec[10];
    b_this->qdu = param_vec[11];
    b_this->dual_mode = param_vec[12];
    b_this->term_tracking_only = param_vec[13];
    b_this->alpha_proc = param_vec[14];
    b_this->sigma_proc = param_vec[15];
    b_this->sigma_meas = param_vec[16];
    b_this->sigma_loca = param_vec[17];
    b_this->alpha_acceptance = param_vec[18];
    b_this->mean_acceptance = param_vec[19];
    b_this->scale_acceptance = param_vec[20];
  }

  /*  Check for errors */
  lon_PCCMPC_checkErrorParameters(b_this);

  /* %% Update dynamic MPC matrices for optimization */
  longitudinal_m_PCCMPC_updateMPC(b_this);

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Get the optimization matrices */
  /* %% Check inputs */
  /* %% Check inputs for forming the MPC problem to solve */
  /*  Inputs */
  /*  Cost function */
  /*  Time vector */
  /*  Constraints */
  /* %% Report */
  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(time_ref[80] >= 16.0)) {
    std::printf("%s\n",
                "Error: reference time vector and MPC dimensions different sizes or time vector too short.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  if (!(time_pred[80] >= 16.0)) {
    std::printf("%s\n",
                "Error: time-varying constraint time vector and MPC dimensions different sizes or constraint vector too short.");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  tmp_size[0] = 324;
  for (i = 0; i < 324; i++) {
    output_ref_1 = output_ref[i];
    tmp_data[i] = (std::isinf(output_ref_1) || std::isnan(output_ref_1));
  }

  if (longitudinal_mpc_vectorAny(tmp_data, tmp_size)) {
    std::printf("%s\n", "Error: non-finite output reference variable detected!");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  tmp_size[0] = 81;
  for (i = 0; i < 81; i++) {
    output_ref_1 = control_ref[i];
    tmp_data[i] = (std::isinf(output_ref_1) || std::isnan(output_ref_1));
  }

  if (longitudinal_mpc_vectorAny(tmp_data, tmp_size)) {
    std::printf("%s\n", "Error: non-finite input reference variable detected!");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  tmp_size[0] = 394;
  for (i = 0; i < 394; i++) {
    tmp_data[i] = std::isnan(b_this->c[i]);
  }

  if (longitudinal_mpc_vectorAny(tmp_data, tmp_size)) {
    std::printf("%s\n", "Error: non-finite rhs constraint variable detected!");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  tmp_size[0] = 81;
  for (i = 0; i < 81; i++) {
    output_ref_1 = pos_pred[i];
    tmp_data[i] = (std::isinf(output_ref_1) || std::isnan(output_ref_1));
  }

  if (longitudinal_mpc_vectorAny(tmp_data, tmp_size)) {
    std::printf("%s\n", "Error: non-finite prediction variable detected!");
    std::fflush(stdout);
  }

  /*  Follows the syntax of the assert statement but just prints the msg instead of erroring as well */
  tmp_size[0] = 81;
  for (i = 0; i < 81; i++) {
    output_ref_1 = time_pred[i];
    tmp_data[i] = (std::isinf(output_ref_1) || std::isnan(output_ref_1));
  }

  if (longitudinal_mpc_vectorAny(tmp_data, tmp_size)) {
    std::printf("%s\n", "Error: non-finite prediction time variable detected!");
    std::fflush(stdout);
  }

  /*  Return */
  b_this->is_step_errored = false;

  /* %% Process reference trajectory */
  /*  Check if we need to down/up sample the reference trajectory */
  output_ref_1 = time_ref[0];
  for (i = 0; i < 32; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    T_expected[i] = (0.5 * static_cast<real_T>(i) + 0.5) + output_ref_1;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% Process time varying constraint */
  /*  Check if we need to down/up sample the time varying constraint */
  output_ref_1 = time_pred[0];
  for (i = 0; i < 33; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    xT_expected[i] = 0.5 * static_cast<real_T>(i) + output_ref_1;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  longitudinal_mpc_interp1_b4tv(time_pred, pos_pred, xT_expected, b_s_pv_tmp);
  longitudinal_mpc_interp1_b4tv(time_pred, vel_pred, xT_expected, b_v_pv_tmp);

  /*  Store reference trajectory terminal output */
  b_this->Ref[0] = output_ref[320];
  b_this->Ref[1] = output_ref[321];
  b_this->Ref[2] = output_ref[322];
  b_this->Ref[3] = output_ref[323];

  /*  Build time varying constraint that is added to b later */
  kidx = -1;
  for (i = 0; i < 32; i++) {
    for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->ci_s_vary_ind[b_i2]);
      _mm_storeu_pd(&K[(kidx + b_i2) + 1], _mm_mul_pd(_mm_set1_pd(b_s_pv_tmp[i]),
        tmp_1));
    }

    kidx += 12;
  }

  kidx = -1;
  for (b_i2 = 0; b_i2 <= 8; b_i2 += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_1 = _mm_loadu_pd(&b_this->cn_s_vary_ind[b_i2]);
    _mm_storeu_pd(&K_0[b_i2], _mm_mul_pd(_mm_set1_pd(b_s_pv_tmp[32]), tmp_1));
  }

  for (i = 0; i < 32; i++) {
    for (b_i2 = 0; b_i2 <= 10; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->ci_s_vary_ind[b_i2]);
      _mm_storeu_pd(&K_1[(kidx + b_i2) + 1], _mm_mul_pd(_mm_set1_pd(b_v_pv_tmp[i]),
        tmp_1));
    }

    kidx += 12;
  }

  for (b_i2 = 0; b_i2 <= 8; b_i2 += 2) {
    /* Start for MATLABSystem: '<S1>/solver' */
    tmp_1 = _mm_loadu_pd(&b_this->cn_s_vary_ind[b_i2]);
    _mm_storeu_pd(&K_2[b_i2], _mm_mul_pd(_mm_set1_pd(b_v_pv_tmp[32]), tmp_1));
  }

  std::memcpy(&v_con_vary[0], &K_1[0], 384U * sizeof(real_T));
  std::memcpy(&v_con_vary[384], &K_2[0], 10U * sizeof(real_T));

  /*  Modify with chance constraint risk margin */
  for (i = 0; i < 394; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    y[i] = std::abs(b_this->v_chance_vary[i]);
    x[i] = std::abs(v_con_vary[i]);
  }

  for (i = 0; i < 384; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    v_con_vary[i] = K[i] - static_cast<real_T>(y[i] < x[i]) *
      b_this->s_chance_vary[i];
  }

  for (i = 0; i < 10; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    v_con_vary[i + 384] = K_0[i] - static_cast<real_T>(y[i + 384] < x[i + 384]) *
      b_this->s_chance_vary[i + 384];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Marginalized by chance constraint: E{S_pv} - chance constraint */
  /*  Store time varying constraint terminal output */
  b_this->Con = v_con_vary[393];

  /* %% Get OCP matrices */
  /*  Expected disturbance input over the horizon */
  /*  Expected output disturbance over the horizon */
  /*  Final matrices */
  std::memset(&longitudinal_mpc_B.H[0], 0, 1369U * sizeof(real_T));
  for (i = 0; i < 32; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&longitudinal_mpc_B.H[i * 37], &b_this->G[i << 5], sizeof(real_T)
                << 5U);
  }

  for (i = 0; i < 5; i++) {
    for (b_i2 = 0; b_i2 < 5; b_i2++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal_mpc_B.H[(b_i2 + 37 * (i + 32)) + 32] = b_this->eps_quad[5 * i
        + b_i2];
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&longitudinal_mpc_B.a[0], &b_this->GammaWa[0], sizeof(real_T) <<
              12U);
  for (i = 0; i < 394; i++) {
    b_this_4 = 0.0;
    for (b_i2 = 0; b_i2 < 32; b_i2++) {
      b_this_5 = 0.0;
      for (kidx = 0; kidx < 128; kidx++) {
        b_this_5 += b_this->M[394 * kidx + i] * longitudinal_mpc_B.a[(b_i2 << 7)
          + kidx];
      }

      b_this_4 += b_this_5 * 0.0;
    }

    rhscon[i] = (((b_this->c[i] + v_con_vary[i]) + b_this->beta_c[i]) -
                 (((b_this->Wcal0[i + 394] * b_this->ego_state[1] +
                    b_this->Wcal0[i] * b_this->ego_state[0]) + b_this->Wcal0[i +
                   788] * b_this->ego_state[2]) + b_this->Wcal0[i + 1182] *
                  b_this->ego_state[3])) - b_this_4;
  }

  for (i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    rhscon[i + 394] = b_this->Upsilonb[i];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Solve and then */
  /*  Xopt = [U, eps, beta] */
  /* %% Roll forward solution from previous solve for use in warm-starting solver */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %% Tyler Ard                %%% */
  /* %% Argonne National Lab     %%% */
  /* %% Vehicle Mobility Systems %%% */
  /* %% tard(at)anl.gov          %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  GETNEXTSTEPPREDICTION Get the prediction horizon for the next MPC */
  /*  stage */
  /*  U is the continuous control variables */
  /*  E is the slack variables */
  /*  B is the integer constraint variables */
  /*  ni is the number of continuous control variables in one stage */
  /*  ns is the number of slack variables in one stage */
  /*  nb is the number of integer constraint variables in one stage */
  /*  Assumes X = [U; E; B] */
  /*  Process */
  /*  Get U as vector */
  /*  Roll forward 1 stage */
  /*  zeros(ni,1); */
  /*  Construct */
  /*         %% Internal solver functions */
  std::memcpy(&b_this->Xk[0], &b_this->U[1], 31U * sizeof(real_T));
  b_this->Xk[31] = b_this->U[31];
  for (i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this->Xk[i + 32] = b_this->E[i];
  }

  /*  Check if mixed integer problem or continuous */
  std::memcpy(&ub[0], &tmp_3[0], 37U * sizeof(real_T));

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %% Tyler Ard                %%% */
  /* %% Argonne National Lab     %%% */
  /* %% Vehicle Mobility Systems %%% */
  /* %% tard(at)anl.gov          %%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  QUADPROG Run mixed-integer quadratic program through quadprog solver */
  /*  Solve a quadratic program of the form  */
  /*  min_x 1/2 x'Px + f'x */
  /*  s.t.  AU \leq b */
  /*        l \leq x \leq u */
  /*        x \in R */
  /*  Handle input arguments */
  /*  Setup workspace */
  /*  % Must use active-set with code generation */
  /*  % 1e-8 default */
  /*  % '10*(numberOfVariables + numberOfConstraints)' default */
  /*  % -1e20 default */
  /*  % 1e-8 default */
  /*  Additional options */
  /*  Bounds check */
  for (i = 0; i < 399; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    output_ref_1 = rhscon[i];
    if (output_ref_1 < -1.0E+9) {
      output_ref_1 = -1.0E+9;
      rhscon[i] = -1.0E+9;
    }

    if (output_ref_1 > 1.0E+9) {
      rhscon[i] = 1.0E+9;
    }
  }

  for (i = 0; i < 5; i++) {
    ub[i + 32] = 1.0E+9;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /* %% Solve problem */
  for (i = 0; i < 32; i++) {
    b_this_0[i] = ((b_this->Fx[i + 32] * b_this->ego_state[1] + b_this->Fx[i] *
                    b_this->ego_state[0]) + b_this->Fx[i + 64] *
                   b_this->ego_state[2]) + b_this->Fx[i + 96] *
      b_this->ego_state[3];
    b_this_4 = 0.0;
    for (b_i2 = 0; b_i2 < 32; b_i2++) {
      b_this_4 += b_this->Fw[(b_i2 << 5) + i] * 0.0;
    }

    b_this_1[i] = b_this_4;
  }

  for (i = 0; i < 4; i++) {
    for (b_i2 = 0; b_i2 < 81; b_i2++) {
      output_ref_0[b_i2 + 81 * i] = output_ref[(b_i2 << 2) + i];
    }
  }

  longitudinal_mpc_interp1_b4(time_ref, output_ref_0, T_expected, b_this_3);
  for (i = 0; i < 32; i++) {
    b_i2 = i << 2;
    tmp[b_i2] = b_this_3[i];
    tmp[b_i2 + 1] = b_this_3[i + 32];
    tmp[b_i2 + 2] = b_this_3[i + 64];
    tmp[b_i2 + 3] = b_this_3[i + 96];
  }

  longitudinal_mpc_interp1_b4t(time_ref, control_ref, T_expected, tmp_0);
  for (i = 0; i < 32; i++) {
    b_this_4 = 0.0;
    for (b_i2 = 0; b_i2 < 128; b_i2++) {
      b_this_4 += b_this->Ty[(b_i2 << 5) + i] * tmp[b_i2];
    }

    output_ref_1 = 0.0;
    b_this_5 = 0.0;
    for (b_i2 = 0; b_i2 < 32; b_i2++) {
      kidx = (b_i2 << 5) + i;
      _mm_storeu_pd(&tmp_2[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(b_this->To[kidx],
        b_this->Tu[kidx]), _mm_set_pd(0.0, tmp_0[b_i2])), _mm_set_pd
        (output_ref_1, b_this_5)));
      b_this_5 = tmp_2[0];
      output_ref_1 = tmp_2[1];
    }

    b_this_2[i] = (b_this_0[i] + b_this_1[i]) - ((b_this_4 + b_this_5) +
      output_ref_1);
  }

  for (i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this_2[i + 32] = b_this->eps_inf[i];
  }

  for (i = 0; i < 32; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    std::memcpy(&longitudinal_mpc_B.b_this[i * 399], &b_this->A0[i * 394], 394U *
                sizeof(real_T));
  }

  for (i = 0; i < 5; i++) {
    for (b_i2 = 0; b_i2 <= 392; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->Upsilon[394 * i + b_i2]);
      _mm_storeu_pd(&longitudinal_mpc_B.b_this[b_i2 + 399 * (i + 32)],
                    _mm_mul_pd(tmp_1, _mm_set1_pd(-1.0)));
    }
  }

  for (i = 0; i < 32; i++) {
    for (b_i2 = 0; b_i2 < 5; b_i2++) {
      longitudinal_mpc_B.b_this[(b_i2 + 399 * i) + 394] = 0.0;
    }
  }

  for (i = 0; i < 5; i++) {
    for (b_i2 = 0; b_i2 <= 2; b_i2 += 2) {
      /* Start for MATLABSystem: '<S1>/solver' */
      tmp_1 = _mm_loadu_pd(&b_this->UpsilonI[5 * i + b_i2]);
      _mm_storeu_pd(&longitudinal_mpc_B.b_this[(b_i2 + 399 * (i + 32)) + 394],
                    _mm_mul_pd(tmp_1, _mm_set1_pd(-1.0)));
    }

    for (b_i2 = 4; b_i2 < 5; b_i2++) {
      /* Start for MATLABSystem: '<S1>/solver' */
      longitudinal_mpc_B.b_this[(b_i2 + 399 * (i + 32)) + 394] =
        -b_this->UpsilonI[5 * i + b_i2];
    }
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  longitudinal_mpc_quadprog(longitudinal_mpc_B.H, b_this_2,
    longitudinal_mpc_B.b_this, rhscon, ub, b_this->Xk, b_this->Xopt, &b_this->J,
    &output_ref_1, expl_temp, &b_this_5, &expl_temp_0, &b_this_4, &lambda);

  /*  Pack */
  if (longitudinal_mpc_isMember(output_ref_1)) {
    output_ref_1 = std::trunc(output_ref_1);
    if (std::isnan(output_ref_1) || std::isinf(output_ref_1)) {
      output_ref_1 = 0.0;
    } else {
      output_ref_1 = std::fmod(output_ref_1, 4.294967296E+9);
    }

    if (output_ref_1 < 0.0) {
      i = -static_cast<int32_T>(static_cast<uint32_T>(-output_ref_1));
    } else {
      i = static_cast<int32_T>(static_cast<uint32_T>(output_ref_1));
    }

    b_this->flag = longitudi_convert_to_enum_flags(i);
  } else {
    b_this->flag = flags::UNKNOWN;
  }

  /*  Set solution */
  b_this->iters = b_this_4;

  /*  Sanity check */
  /* %% Post process */
  /*  Set methods */
  /*  Postprocess solution */
  std::memcpy(&b_this->U[0], &b_this->Xopt[0], sizeof(real_T) << 5U);
  std::memcpy(&longitudinal_mpc_B.a[0], &b_this->Gamma[0], sizeof(real_T) << 12U);
  for (i = 0; i < 128; i++) {
    output_ref_1 = 0.0;
    b_this_5 = 0.0;
    for (b_i2 = 0; b_i2 < 32; b_i2++) {
      kidx = (b_i2 << 7) + i;
      b_this_5 += longitudinal_mpc_B.a[kidx] * b_this->U[b_i2];
      output_ref_1 += b_this->GammaWa[kidx];
    }

    b_this->X[i] = ((((b_this->Phi[i + 128] * b_this->ego_state[1] + b_this->
                       Phi[i] * b_this->ego_state[0]) + b_this->Phi[i + 256] *
                      b_this->ego_state[2]) + b_this->Phi[i + 384] *
                     b_this->ego_state[3]) + b_this_5) + output_ref_1;
  }

  /*  Expected state trajectory from current k timestep to k+N */
  std::memcpy(&longitudinal_mpc_B.a[0], &b_this->GammaD[0], sizeof(real_T) <<
              12U);
  std::memcpy(&b_this_3[0], &b_this->X[0], sizeof(real_T) << 7U);
  for (i = 0; i < 128; i++) {
    b_this_4 = 0.0;
    for (b_i2 = 0; b_i2 < 128; b_i2++) {
      b_this_4 += b_this->GammaC[(b_i2 << 7) + i] * b_this_3[b_i2];
    }

    output_ref_1 = 0.0;
    b_this_5 = 0.0;
    for (b_i2 = 0; b_i2 < 32; b_i2++) {
      kidx = (b_i2 << 7) + i;
      b_this_5 += longitudinal_mpc_B.a[kidx] * b_this->U[b_i2];
      output_ref_1 += b_this->GammaVa[kidx];
    }

    b_this->Y[i] = (b_this_4 + b_this_5) + output_ref_1;
  }

  /*  Expected output trajectory */
  for (i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    b_this->E[i] = b_this->Xopt[i + 32];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  /*  Check errors */
  /*  Return */
  output_ref_1 = time_pred[0];
  for (i = 0; i < 32; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    T[i] = 0.5 * static_cast<real_T>(i) + output_ref_1;
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  std::memcpy(&X[0], &b_this->X[0], sizeof(real_T) << 7U);
  std::memcpy(&U[0], &b_this->U[0], sizeof(real_T) << 5U);
  for (i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S1>/solver' */
    E[i] = b_this->E[i];
  }

  /* Start for MATLABSystem: '<S1>/solver' */
  R[0] = b_this->Ref[0];
  R[1] = b_this->Ref[1];
  R[2] = b_this->Ref[2];
  R[3] = b_this->Ref[3];
  *C = b_this->Con;
  *J = b_this->J;
  *flag = b_this->flag;
  *iters = b_this->iters;

  /* Start for MATLABSystem: '<S1>/solver' */
  *u = b_this->U[0];

  /* %% Check solution */
  /* %% Debugging */
  /*  if isempty coder.target */
}

/* Model step function */
void longitudinal_mpc::step()
{
  __m128d tmp;
  real_T rtb_prediction_o1_0[324];
  real_T pos_pred[201];
  real_T pos_pred_0[201];
  real_T time_pred[201];
  real_T time_pred_0[201];
  real_T vel_pred[201];
  real_T vel_pred_0[201];
  real_T b_y1_data[200];
  real_T Sr[81];
  real_T Vr[81];
  real_T rtb_prediction_o2_0[81];
  real_T rtb_prediction_o3_0[81];
  real_T rtb_prediction_o4_0[81];
  real_T rtb_prediction_o5_0[81];
  real_T rtb_prediction_o6_0[81];
  real_T x[81];
  real_T a0;
  real_T pv_s;
  real_T pv_v;
  real_T v0;
  real_T v_max;
  int32_T c;
  int32_T i;
  int32_T idx;
  int32_T nz;
  int32_T pv_s_tmp_tmp;
  int32_T trueCount;
  uint8_T tmp_data[201];
  uint8_T tmp_data_0[201];
  boolean_T valid_inds[201];
  static const real_T tmp_0[81]{ 0.2, 0.4, 0.60000000000000009, 0.8, 1.0,
    1.2000000000000002, 1.4000000000000001, 1.6, 1.8, 2.0, 2.2,
    2.4000000000000004, 2.6, 2.8000000000000003, 3.0, 3.2, 3.4000000000000004,
    3.6, 3.8000000000000003, 4.0, 4.2, 4.4, 4.6000000000000005,
    4.8000000000000007, 5.0, 5.2, 5.4, 5.6000000000000005, 5.8000000000000007,
    6.0, 6.2, 6.4, 6.6000000000000005, 6.8000000000000007, 7.0, 7.2, 7.4,
    7.6000000000000005, 7.8000000000000007, 8.0, 8.2000000000000011, 8.4, 8.6,
    8.8, 9.0, 9.2000000000000011, 9.4, 9.6000000000000014, 9.8, 10.0,
    10.200000000000001, 10.4, 10.600000000000001, 10.8, 11.0, 11.200000000000001,
    11.4, 11.600000000000001, 11.8, 12.0, 12.200000000000001, 12.4,
    12.600000000000001, 12.8, 13.0, 13.200000000000001, 13.4, 13.600000000000001,
    13.8, 14.0, 14.200000000000001, 14.4, 14.600000000000001, 14.8, 15.0,
    15.200000000000001, 15.4, 15.600000000000001, 15.8, 16.0, 16.2 };

  int32_T b_y1_size_idx_0;
  uint8_T f_last_ind_data_idx_0;
  uint8_T ii_data_idx_0;
  boolean_T exitg1;

  /* Outputs for Atomic SubSystem: '<Root>/longitudinal_mpc' */
  /* MATLABSystem: '<S1>/prediction' incorporates:
   *  Inport: '<Root>/ego_state'
   *  Inport: '<Root>/param_vec'
   *  Inport: '<Root>/pos_pred'
   *  Inport: '<Root>/pv_state'
   *  Inport: '<Root>/t'
   *  Inport: '<Root>/time_pred'
   *  Inport: '<Root>/vel_pred'
   */
  /*  If using internal prediction */
  v_max = longitudinal_mpc_U.param_vec[2];
  for (i = 0; i < 201; i++) {
    valid_inds[i] = ((!std::isinf(longitudinal_mpc_U.time_pred[i])) && (!std::
      isnan(longitudinal_mpc_U.time_pred[i])));
  }

  nz = valid_inds[0];
  for (idx = 0; idx < 200; idx++) {
    nz += valid_inds[idx + 1];
  }

  if (nz < 5) {
    /*  this = prediction() */
    /*  Get methods */
    /* %% Check inputs */
    pv_s = longitudinal_mpc_U.ego_state[0] + longitudinal_mpc_U.pv_state[0];
    pv_v = longitudinal_mpc_U.pv_state[1];

    /* %% Parameters */
    /* %% Prediction output */
    v0 = longitudinal_mpc_U.pv_state[1];
    for (i = 0; i < 201; i++) {
      pos_pred[i] = pv_s;
      vel_pred[i] = v0;
      time_pred[i] = 0.1 * static_cast<real_T>(i) + longitudinal_mpc_U.t;
    }

    v0 = longitudinal_mpc_U.pv_state[1];
    a0 = longitudinal_mpc_U.pv_state[2];

    /*  Loop through prediction stages */
    for (idx = 0; idx < 200; idx++) {
      /*  Logic to prevent overspeeding and reversing */
      if (pv_v > v_max) {
        a0 = 0.0;
      } else if (pv_v < 0.0) {
        a0 = 0.0;
        v0 = 0.0;
      }

      /*  Logic to shut off constant acceleration assumption */
      if (time_pred[idx + 1] - longitudinal_mpc_U.t > 3.0) {
        /*  Switch to constant velocity */
        a0 = 0.0;
      }

      /*  Propagate kinematic prediction */
      v0 = std::fmin(std::fmax(0.1 * a0 + v0, 0.0), v_max);
      vel_pred[idx + 1] = v0;
      pv_s += (0.1 * a0 + v0) * 0.1;
      pos_pred[idx + 1] = pv_s;

      /*  Update */
    }
  } else {
    /*  If using externally-supplied prediction */
    std::memcpy(&pos_pred[0], &longitudinal_mpc_U.pos_pred[0], 201U * sizeof
                (real_T));
    std::memcpy(&vel_pred[0], &longitudinal_mpc_U.vel_pred[0], 201U * sizeof
                (real_T));
    std::memcpy(&time_pred[0], &longitudinal_mpc_U.time_pred[0], 201U * sizeof
                (real_T));
  }

  /*  Once PV trajectory is supplied from inputs or from internal prediction */
  /* %% Check inputs */
  /* %% Downsample prediction vectors to only the index range within the expected values */
  for (i = 0; i < 201; i++) {
    pv_s = time_pred[i];
    valid_inds[i] = ((!std::isinf(pv_s)) && (!std::isnan(pv_s)) && (!(pv_s <=
      0.001)));
    time_pred_0[i] = 0.0;
    pos_pred_0[i] = 0.0;
    vel_pred_0[i] = 0.0;
  }

  valid_inds[0] = true;

  /* End of Outputs for SubSystem: '<Root>/longitudinal_mpc' */
  trueCount = 0;
  idx = 0;
  for (i = 0; i < 201; i++) {
    /* Outputs for Atomic SubSystem: '<Root>/longitudinal_mpc' */
    /* MATLABSystem: '<S1>/prediction' */
    if (valid_inds[i]) {
      time_pred_0[i] = time_pred[i];
      pos_pred_0[i] = pos_pred[i];
      vel_pred_0[i] = vel_pred[i];
      idx = trueCount + 1;
      trueCount++;
    }

    /* End of Outputs for SubSystem: '<Root>/longitudinal_mpc' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/longitudinal_mpc' */
  /* Start for MATLABSystem: '<S1>/prediction' */
  nz = trueCount - 1;

  /* MATLABSystem: '<S1>/prediction' */
  if (idx == 0) {
    b_y1_size_idx_0 = 0;
  } else {
    if (trueCount - 1 <= 1) {
      /* Start for MATLABSystem: '<S1>/prediction' */
      i = trueCount - 1;
    } else {
      /* Start for MATLABSystem: '<S1>/prediction' */
      i = 1;
    }

    if (i < 1) {
      b_y1_size_idx_0 = 0;
    } else {
      b_y1_size_idx_0 = trueCount - 1;
      if (trueCount - 1 != 0) {
        trueCount = 0;
        for (i = 0; i < 201; i++) {
          if (valid_inds[i]) {
            tmp_data[trueCount] = static_cast<uint8_T>(i);
            trueCount++;
          }
        }

        pv_v = time_pred[tmp_data[0]];
        for (idx = 2; idx <= nz + 1; idx++) {
          trueCount = 0;
          for (i = 0; i < 201; i++) {
            if (valid_inds[i]) {
              tmp_data_0[trueCount] = static_cast<uint8_T>(i);
              trueCount++;
            }
          }

          v_max = time_pred[tmp_data_0[idx - 1]];
          pv_s = pv_v;
          pv_v = v_max;
          b_y1_data[idx - 2] = v_max - pv_s;
        }
      }
    }
  }

  /*  Extend as necessary with velocity assumption */
  idx = 0;
  i = 1;
  nz = 201;
  exitg1 = false;
  while ((!exitg1) && (nz > 0)) {
    if (valid_inds[nz - 1]) {
      idx = 1;
      ii_data_idx_0 = static_cast<uint8_T>(nz);
      exitg1 = true;
    } else {
      nz--;
    }
  }

  if (idx == 0) {
    i = 0;
  }

  if (i - 1 >= 0) {
    f_last_ind_data_idx_0 = ii_data_idx_0;
  }

  /* Start for MATLABSystem: '<S1>/prediction' */
  pv_s = time_pred_0[f_last_ind_data_idx_0 - 1];
  v0 = b_y1_data[b_y1_size_idx_0 - 1];
  trueCount = 201 - f_last_ind_data_idx_0;

  /* MATLABSystem: '<S1>/prediction' */
  for (nz = 0; nz <= trueCount; nz++) {
    time_pred_0[(f_last_ind_data_idx_0 + nz) - 1] = v0 * static_cast<real_T>(nz)
      + pv_s;
  }

  /* Start for MATLABSystem: '<S1>/prediction' */
  pv_s = vel_pred_0[f_last_ind_data_idx_0 - 1];
  b_y1_size_idx_0 = 202 - f_last_ind_data_idx_0;

  /* MATLABSystem: '<S1>/prediction' */
  for (nz = 0; nz < b_y1_size_idx_0; nz++) {
    vel_pred_0[(f_last_ind_data_idx_0 + nz) - 1] = pv_s;
  }

  idx = 1;
  if (202 - f_last_ind_data_idx_0 != 1) {
    idx = 0;
    v_max = 202.0 - static_cast<real_T>(f_last_ind_data_idx_0);
  } else {
    v_max = 1.0;
  }

  i = 1;
  nz = idx - 1;
  for (idx = 0; idx <= nz; idx++) {
    i *= 202 - f_last_ind_data_idx_0;
  }

  for (nz = 0; nz < i; nz++) {
    pv_s = 0.0;
    trueCount = (f_last_ind_data_idx_0 + nz) - 2;
    pv_v = vel_pred_0[trueCount + 1];
    pos_pred[nz] = 0.0;
    c = static_cast<int32_T>(v_max) - 2;
    for (idx = 0; idx <= c; idx++) {
      pv_s_tmp_tmp = (idx + 1) * i;
      a0 = vel_pred_0[(trueCount + pv_s_tmp_tmp) + 1];
      pv_s += (a0 + pv_v) / 2.0;
      pv_v = a0;
      pos_pred[nz + pv_s_tmp_tmp] = pv_s;
    }
  }

  /* Start for MATLABSystem: '<S1>/prediction' */
  pv_s = pos_pred_0[f_last_ind_data_idx_0 - 1];

  /* MATLABSystem: '<S1>/prediction' incorporates:
   *  Inport: '<Root>/ego_state'
   *  Inport: '<Root>/param_vec'
   *  Inport: '<Root>/t'
   */
  idx = ((202 - f_last_ind_data_idx_0) / 2) << 1;
  i = idx - 2;
  for (nz = 0; nz <= i; nz += 2) {
    tmp = _mm_loadu_pd(&pos_pred[nz]);
    _mm_storeu_pd(&pos_pred_0[(f_last_ind_data_idx_0 + nz) - 1], _mm_add_pd
                  (_mm_mul_pd(tmp, _mm_set1_pd(v0)), _mm_set1_pd(pv_s)));
  }

  for (nz = idx; nz < b_y1_size_idx_0; nz++) {
    pos_pred_0[(f_last_ind_data_idx_0 + nz) - 1] = pos_pred[nz] * v0 + pv_s;
  }

  /* %% Parameters */
  /* %% Constraint output */
  for (i = 0; i < 81; i++) {
    rtb_prediction_o6_0[i] = 0.2 * static_cast<real_T>(i) + longitudinal_mpc_U.t;
  }

  longitudinal_mpc_interp1(time_pred_0, pos_pred_0, rtb_prediction_o6_0,
    rtb_prediction_o4_0);
  longitudinal_mpc_interp1(time_pred_0, vel_pred_0, rtb_prediction_o6_0,
    rtb_prediction_o5_0);

  /* %% Reference output */
  /*  Time reference */
  /*  Control and output reference stages */
  pv_s = longitudinal_mpc_U.param_vec[1];

  /*  Build reference trajectories for case where PV is out of range */
  idx = -1;
  for (nz = 0; nz < 81; nz++) {
    pv_v = longitudinal_mpc_U.t + tmp_0[nz];
    rtb_prediction_o3_0[nz] = pv_v;
    rtb_prediction_o2_0[nz] = 0.0;
    rtb_prediction_o1_0[idx + 1] = 0.0;
    rtb_prediction_o1_0[idx + 2] = static_cast<real_T>(pv_v < (rtInf)) * pv_s;
    rtb_prediction_o1_0[idx + 3] = 0.0;
    rtb_prediction_o1_0[idx + 4] = 0.0;
    idx += 4;
  }

  std::memcpy(&x[0], &rtb_prediction_o3_0[0], 81U * sizeof(real_T));
  for (i = 0; i < 81; i++) {
    Vr[i] = rtb_prediction_o1_0[(i << 2) + 1];
  }

  pv_s = 0.0;
  pv_v = rtb_prediction_o1_0[1];
  Sr[0] = 0.0;
  for (idx = 0; idx < 80; idx++) {
    v_max = x[idx + 1] - x[idx];
    x[idx] = v_max;
    v0 = rtb_prediction_o1_0[((idx + 1) << 2) + 1];
    pv_s += (pv_v + v0) / 2.0 * v_max;
    pv_v = v0;
    Sr[idx + 1] = pv_s;
  }

  pv_s = rtb_prediction_o1_0[1] * 0.2 + longitudinal_mpc_U.ego_state[0];
  for (i = 0; i <= 78; i += 2) {
    tmp = _mm_loadu_pd(&Sr[i]);
    _mm_storeu_pd(&Sr[i], _mm_add_pd(_mm_set1_pd(pv_s), tmp));
  }

  for (i = 80; i < 81; i++) {
    Sr[i] += pv_s;
  }

  /*  Build reference trajectories if PV is in range */
  if (rtb_prediction_o4_0[80] < Sr[80]) {
    for (nz = 0; nz < 81; nz++) {
      Vr[nz] = std::fmin(rtb_prediction_o1_0[(nz << 2) + 1],
                         rtb_prediction_o5_0[nz]);
      Sr[nz] = std::fmin(Sr[nz], rtb_prediction_o4_0[nz]);
    }
  }

  /*  Build reference trajectories if end goal is in range */
  if (longitudinal_mpc_U.param_vec[3] < Sr[80]) {
    Vr[80] = 0.0;
    Sr[80] = longitudinal_mpc_U.param_vec[3];
  }

  /*  Assign reference trajectories */
  for (i = 0; i < 81; i++) {
    nz = i << 2;
    rtb_prediction_o1_0[nz] = Sr[i];
    rtb_prediction_o1_0[nz + 1] = Vr[i];
  }

  /* Outport: '<Root>/iters' incorporates:
   *  Inport: '<Root>/ego_state'
   *  Inport: '<Root>/param_vec'
   *  MATLABSystem: '<S1>/prediction'
   *  MATLABSystem: '<S1>/solver'
   *  Outport: '<Root>/acc_des'
   *  Outport: '<Root>/constraint'
   *  Outport: '<Root>/cost'
   *  Outport: '<Root>/exitflag'
   *  Outport: '<Root>/reference'
   *  Outport: '<Root>/slacks'
   * */
  longitudinal_mp_solver_stepImpl(&longitudinal_mpc_DW.obj,
    longitudinal_mpc_U.ego_state, rtb_prediction_o1_0, rtb_prediction_o2_0,
    rtb_prediction_o3_0, rtb_prediction_o4_0, rtb_prediction_o5_0,
    rtb_prediction_o6_0, longitudinal_mpc_U.param_vec,
    &longitudinal_mpc_Y.acc_des, longitudinal_mpc_Y.state_trajectory,
    longitudinal_mpc_Y.control_trajectory, longitudinal_mpc_Y.time_trajectory,
    longitudinal_mpc_Y.slacks, longitudinal_mpc_Y.reference,
    &longitudinal_mpc_Y.constraint, &longitudinal_mpc_Y.cost,
    &longitudinal_mpc_Y.exitflag, &longitudinal_mpc_Y.iters);

  /* MATLABSystem: '<S1>/solver' */
  longitudinal_mpc_DW.iters = longitudinal_mpc_DW.obj.iters;
  std::memcpy(&longitudinal_mpc_DW.Xk[0], &longitudinal_mpc_DW.obj.Xk[0], 37U *
              sizeof(real_T));
  std::memcpy(&longitudinal_mpc_DW.Xopt[0], &longitudinal_mpc_DW.obj.Xopt[0],
              37U * sizeof(real_T));
  longitudinal_mpc_DW.J = longitudinal_mpc_DW.obj.J;
  longitudinal_mpc_DW.flag = longitudinal_mpc_DW.obj.flag;

  /* End of Outputs for SubSystem: '<Root>/longitudinal_mpc' */
}

/* Model initialize function */
void longitudinal_mpc::initialize()
{
  /* Registration code */

  /* external outputs */
  longitudinal_mpc_Y.exitflag = flags::SOLVED;

  /* Start for Atomic SubSystem: '<Root>/longitudinal_mpc' */
  /* Start for MATLABSystem: '<S1>/prediction' */
  /*  Constructor */
  longitudinal_mpc_DW.objisempty_f = true;

  /* Start for MATLABSystem: '<S1>/solver' */
  /*         %% System object functions */
  /*  Perform one-time calculations, such as computing constants */
  longitudinal_mpc_solver_solver(&longitudinal_mpc_DW.obj);
  longitudinal_mpc_DW.objisempty = true;
  longitudinal_mpc_DW.obj.isInitialized = 1;

  /*  Initialize MPC parent class */
  /* %% Set default MPC problem */
  longitudin_PCCMPC_setParameters(&longitudinal_mpc_DW.obj);
  longitudinal_mpc_PCCMPC_initMPC(&longitudinal_mpc_DW.obj);
  longitudinal_m_PCCMPC_updateMPC(&longitudinal_mpc_DW.obj);

  /*  Initialize solver */
  longitudinal__solver_initSolver(&longitudinal_mpc_DW.obj);
  longitudinal_mpc_DW.iters = longitudinal_mpc_DW.obj.iters;
  std::memcpy(&longitudinal_mpc_DW.Xk[0], &longitudinal_mpc_DW.obj.Xk[0], 37U *
              sizeof(real_T));
  std::memcpy(&longitudinal_mpc_DW.Xopt[0], &longitudinal_mpc_DW.obj.Xopt[0],
              37U * sizeof(real_T));
  longitudinal_mpc_DW.J = longitudinal_mpc_DW.obj.J;
  longitudinal_mpc_DW.flag = longitudinal_mpc_DW.obj.flag;

  /* End of Start for SubSystem: '<Root>/longitudinal_mpc' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/longitudinal_mpc' */
  /* InitializeConditions for MATLABSystem: '<S1>/solver' */
  /*  Initialize / reset internal properties */
  /* %% Set default MPC problem */
  longitudin_PCCMPC_setParameters(&longitudinal_mpc_DW.obj);
  longitudinal_mpc_PCCMPC_initMPC(&longitudinal_mpc_DW.obj);
  longitudinal_m_PCCMPC_updateMPC(&longitudinal_mpc_DW.obj);

  /*  Initialize solver */
  longitudinal__solver_initSolver(&longitudinal_mpc_DW.obj);
  longitudinal_mpc_DW.iters = longitudinal_mpc_DW.obj.iters;
  std::memcpy(&longitudinal_mpc_DW.Xk[0], &longitudinal_mpc_DW.obj.Xk[0], 37U *
              sizeof(real_T));
  std::memcpy(&longitudinal_mpc_DW.Xopt[0], &longitudinal_mpc_DW.obj.Xopt[0],
              37U * sizeof(real_T));
  longitudinal_mpc_DW.J = longitudinal_mpc_DW.obj.J;
  longitudinal_mpc_DW.flag = longitudinal_mpc_DW.obj.flag;

  /* End of SystemInitialize for SubSystem: '<Root>/longitudinal_mpc' */
}

/* Model terminate function */
void longitudinal_mpc::terminate()
{
  /* Terminate for Atomic SubSystem: '<Root>/longitudinal_mpc' */
  /* Terminate for MATLABSystem: '<S1>/solver' */
  longitudinal_mpc_DW.iters = longitudinal_mpc_DW.obj.iters;
  std::memcpy(&longitudinal_mpc_DW.Xk[0], &longitudinal_mpc_DW.obj.Xk[0], 37U *
              sizeof(real_T));
  std::memcpy(&longitudinal_mpc_DW.Xopt[0], &longitudinal_mpc_DW.obj.Xopt[0],
              37U * sizeof(real_T));
  longitudinal_mpc_DW.J = longitudinal_mpc_DW.obj.J;
  longitudinal_mpc_DW.flag = longitudinal_mpc_DW.obj.flag;

  /* End of Terminate for SubSystem: '<Root>/longitudinal_mpc' */
}

/* Constructor */
longitudinal_mpc::longitudinal_mpc() :
  longitudinal_mpc_U(),
  longitudinal_mpc_Y(),
  longitudinal_mpc_B(),
  longitudinal_mpc_DW(),
  longitudinal_mpc_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
longitudinal_mpc::~longitudinal_mpc() = default;

/* Real-Time Model get method */
RT_MODEL_longitudinal_mpc_T * longitudinal_mpc::getRTM()
{
  return (&longitudinal_mpc_M);
}
