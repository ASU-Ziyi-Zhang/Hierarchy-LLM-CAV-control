/*
 * longitudinal_mpc_types.h
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

#ifndef longitudinal_mpc_types_h_
#define longitudinal_mpc_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_flags_
#define DEFINED_TYPEDEF_FOR_flags_

enum class flags
  : int32_T {
  SOLVED = 1,                          /* Default value */
  MAX_ITER = 0,
  PRIMAL_INFEASIBLE = -2,
  DUAL_INFEASIBLE = -3,
  NONCONVEX_DETECTED = -6,
  MI_SOLVED = 11,
  MI_PRIMAL_INFEASIBLE = 13,
  MI_DUAL_INFEASIBLE = 15,
  MI_MAX_ITER = 12,
  MI_MAX_ITER_UNSOLVED = 14,
  MI_INTEGER_INFEASIBLE = 17,
  UNSOLVED = -1,
  EMPTY = -1235,
  UNKNOWN = -1234
};

#endif

#ifndef struct_prediction_longitudinal_mpc_T
#define struct_prediction_longitudinal_mpc_T

struct prediction_longitudinal_mpc_T
{
  int32_T isInitialized;
};

#endif                                /* struct_prediction_longitudinal_mpc_T */

#ifndef struct_suKEVDQMOZ0XRzxi1HugtZH_longi_T
#define struct_suKEVDQMOZ0XRzxi1HugtZH_longi_T

struct suKEVDQMOZ0XRzxi1HugtZH_longi_T
{
  real_T xstar[38];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[474];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[38];
};

#endif                              /* struct_suKEVDQMOZ0XRzxi1HugtZH_longi_T */

#ifndef struct_siuq7rbPRrhRxtZY0x4sHID_longi_T
#define struct_siuq7rbPRrhRxtZY0x4sHID_longi_T

struct siuq7rbPRrhRxtZY0x4sHID_longi_T
{
  real_T grad[38];
  real_T Hx[37];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                              /* struct_siuq7rbPRrhRxtZY0x4sHID_longi_T */

#ifndef struct_sSQjeS6UA6ous3QrgyAXHyC_longi_T
#define struct_sSQjeS6UA6ous3QrgyAXHyC_longi_T

struct sSQjeS6UA6ous3QrgyAXHyC_longi_T
{
  real_T FMat[1444];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[1824];
  real_T workspace2_[1824];
};

#endif                              /* struct_sSQjeS6UA6ous3QrgyAXHyC_longi_T */

#ifndef struct_sL9bDKomAYkxZSVrG9w6En_longit_T
#define struct_sL9bDKomAYkxZSVrG9w6En_longit_T

struct sL9bDKomAYkxZSVrG9w6En_longit_T
{
  int32_T MaxIterations;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
};

#endif                              /* struct_sL9bDKomAYkxZSVrG9w6En_longit_T */

#ifndef struct_sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
#define struct_sPWVfH0R9Nt4Hr7G42QZn2G_longi_T

struct sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
{
  int32_T ldq;
  real_T QR[18012];
  real_T Q[1444];
  int32_T jpvt[474];
  int32_T mrows;
  int32_T ncols;
  real_T tau[38];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                              /* struct_sPWVfH0R9Nt4Hr7G42QZn2G_longi_T */

#ifndef struct_srUNuce4MmfvHoJodBzBujH_longi_T
#define struct_srUNuce4MmfvHoJodBzBujH_longi_T

struct srUNuce4MmfvHoJodBzBujH_longi_T
{
  real_T workspace_float[18012];
  int32_T workspace_int[474];
  int32_T workspace_sort[474];
};

#endif                              /* struct_srUNuce4MmfvHoJodBzBujH_longi_T */

#ifndef struct_sZnXTmmXLG06QsvMaQjKaGF_longi_T
#define struct_sZnXTmmXLG06QsvMaQjKaGF_longi_T

struct sZnXTmmXLG06QsvMaQjKaGF_longi_T
{
  real_T ineqlin[399];
  real_T lower[37];
  real_T upper[37];
};

#endif                              /* struct_sZnXTmmXLG06QsvMaQjKaGF_longi_T */

#ifndef struct_svwK1qKQ5yAVvUFh54r0LBD_longi_T
#define struct_svwK1qKQ5yAVvUFh54r0LBD_longi_T

struct svwK1qKQ5yAVvUFh54r0LBD_longi_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aineq[15162];
  real_T bineq[399];
  real_T lb[38];
  real_T ub[38];
  int32_T indexLB[38];
  int32_T indexUB[38];
  int32_T indexFixed[38];
  int32_T mEqRemoved;
  real_T ATwset[18012];
  real_T bwset[474];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[474];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[474];
  int32_T Wid[474];
  int32_T Wlocalidx[474];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                              /* struct_svwK1qKQ5yAVvUFh54r0LBD_longi_T */

#ifndef struct_s7GW9uShiIXbHYZwohNmyqD_longi_T
#define struct_s7GW9uShiIXbHYZwohNmyqD_longi_T

struct s7GW9uShiIXbHYZwohNmyqD_longi_T
{
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  real_T InitDamping;
  char_T FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  real_T FiniteDifferenceStepSize;
  real_T MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  real_T PricingTolerance;
  char_T Algorithm[10];
  real_T ObjectiveLimit;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
  real_T MaxIterations;
  real_T FunctionTolerance;
  char_T SolverName[8];
  boolean_T CheckGradients;
  char_T Diagnostics[3];
  real_T DiffMaxChange;
  real_T DiffMinChange;
  char_T Display[3];
  char_T FunValCheck[3];
  boolean_T UseParallel;
  char_T LinearSolver[4];
  char_T SubproblemAlgorithm[2];
};

#endif                              /* struct_s7GW9uShiIXbHYZwohNmyqD_longi_T */

#ifndef struct_solver_longitudinal_mpc_T
#define struct_solver_longitudinal_mpc_T

struct solver_longitudinal_mpc_T
{
  int32_T isInitialized;
  real_T C[16];
  boolean_T __C_AssignmentSentinel;
  real_T ego_state[4];
  real_T vel_des;
  real_T vel_max;
  real_T pos_max;
  real_T is_eco;
  real_T d0;
  real_T THref;
  real_T THsafe;
  real_T THmax;
  real_T qh;
  real_T qv;
  real_T qu;
  real_T qdu;
  real_T dual_mode;
  real_T term_tracking_only;
  real_T alpha_proc;
  real_T sigma_proc;
  real_T sigma_meas;
  real_T sigma_loca;
  real_T alpha_acceptance;
  real_T mean_acceptance;
  real_T scale_acceptance;
  boolean_T is_needs_update;
  real_T Q[16];
  real_T R;
  real_T S[16];
  real_T eps_quad[25];
  real_T eps_inf[5];
  real_T Phi[512];
  real_T Gamma[4096];
  real_T GammaC[16384];
  real_T GammaD[4096];
  real_T GammaWa[4096];
  real_T GammaVa[4096];
  real_T Omega[16384];
  real_T Psi[1024];
  real_T G[1024];
  real_T Fx[128];
  real_T Fw[1024];
  real_T Ty[4096];
  real_T Tu[1024];
  real_T To[1024];
  real_T Mi[48];
  real_T Ei[12];
  real_T Mn[40];
  real_T ci[12];
  real_T cn[10];
  real_T M[50432];
  real_T Sigma[12608];
  real_T Mcal0[1576];
  real_T Wcal0[1576];
  real_T c[394];
  real_T A0[12608];
  real_T ci_s_vary_ind[12];
  real_T cn_s_vary_ind[10];
  real_T Mi_th_vary_ind[48];
  real_T Mn_th_vary_ind[40];
  real_T s_chance[33];
  real_T v_chance[33];
  real_T TH_chance[33];
  real_T s_chance_vary[394];
  real_T v_chance_vary[394];
  real_T TH_chance_vary[50432];
  real_T THcal0_chance_vary[1576];
  real_T upsi[60];
  real_T Upsilon[1970];
  real_T UpsilonI[25];
  real_T Upsilonb[5];
  real_T upsn[50];
  real_T betaci[12];
  real_T betacn[10];
  real_T beta_c[394];
  real_T X[128];
  real_T Y[128];
  real_T U[32];
  real_T E[5];
  real_T Ref[4];
  real_T Con;
  boolean_T is_parameter_errored;
  boolean_T is_init_errored;
  boolean_T is_update_errored;
  boolean_T is_step_errored;
  boolean_T is_solve_errored;
  real_T Xk[37];
  real_T Xopt[37];
  real_T J;
  flags flag;
  real_T iters;
};

#endif                                 /* struct_solver_longitudinal_mpc_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_longitudinal_mpc_T RT_MODEL_longitudinal_mpc_T;

#endif                                 /* longitudinal_mpc_types_h_ */
