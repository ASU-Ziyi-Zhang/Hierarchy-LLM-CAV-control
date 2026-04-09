/*
 * rtGetInf.cpp
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

#include "rtwtypes.h"

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{
  /* Return rtInf needed by the generated code. */
  real_T rtGetInf(void)
  {
    return rtInf;
  }

  /* Get rtInfF needed by the generated code. */
  real32_T rtGetInfF(void)
  {
    return rtInfF;
  }

  /* Return rtMinusInf needed by the generated code. */
  real_T rtGetMinusInf(void)
  {
    return rtMinusInf;
  }

  /* Return rtMinusInfF needed by the generated code. */
  real32_T rtGetMinusInfF(void)
  {
    return rtMinusInfF;
  }
}
