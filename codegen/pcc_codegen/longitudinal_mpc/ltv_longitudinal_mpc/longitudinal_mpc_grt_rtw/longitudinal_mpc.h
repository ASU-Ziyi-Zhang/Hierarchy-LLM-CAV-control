/*
 * longitudinal_mpc.h
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

#ifndef longitudinal_mpc_h_
#define longitudinal_mpc_h_
#include <cmath>
#include <cstdio>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "longitudinal_mpc_types.h"
#include "coder_array.h"

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
struct B_longitudinal_mpc_T {
  real_T GammaP[102400];
  real_T Cov[102400];
  real_T Gamma[51200];
  real_T Mean[51200];
  real_T b[51200];
  real_T y[50432];
  real_T K[47616];
  svwK1qKQ5yAVvUFh54r0LBD_longi_T b_WorkingSet;
  svwK1qKQ5yAVvUFh54r0LBD_longi_T b_WorkingSet_m;
  svwK1qKQ5yAVvUFh54r0LBD_longi_T b_workingset;
  svwK1qKQ5yAVvUFh54r0LBD_longi_T c_workingset;
  svwK1qKQ5yAVvUFh54r0LBD_longi_T workingset;
  svwK1qKQ5yAVvUFh54r0LBD_longi_T workingset_c;
  svwK1qKQ5yAVvUFh54r0LBD_longi_T workingset_k;
  svwK1qKQ5yAVvUFh54r0LBD_longi_T workingset_cx;
  sPWVfH0R9Nt4Hr7G42QZn2G_longi_T QRManager;
  srUNuce4MmfvHoJodBzBujH_longi_T b_memspace;
  real_T b_memspace_b[18012];
  real_T B[18012];
  real_T K_p[15376];
  real_T b_this[14763];
  real_T K_c[12288];
  sSQjeS6UA6ous3QrgyAXHyC_longi_T CholRegManager;
  real_T Fp[4096];
  real_T y_f[4096];
  real_T H_tmp[4096];
  real_T y_g[4096];
  real_T y_g1[4096];
  real_T a[4096];
  real_T K_m[1920];
  real_T K_n[1536];
  real_T H[1369];
  real_T pp_coefs[1280];
  real_T H_p[1024];
  real_T b_this_l[1024];
  real_T H_tmp_j[1024];
  real_T e[1000];
  real_T A[992];
  real_T d[961];
  real_T PhiP[640];
  real_T PhiP_data[640];
  real_T PhiP_data_d[636];
  real_T pp_coefs_g[636];
  suKEVDQMOZ0XRzxi1HugtZH_longi_T solution;
  suKEVDQMOZ0XRzxi1HugtZH_longi_T solution_l;
};

/* Block states (default storage) for system '<Root>' */
struct DW_longitudinal_mpc_T {
  solver_longitudinal_mpc_T obj;       /* '<S1>/solver' */
  real_T Xk[37];                       /* '<S1>/solver' */
  real_T iters;                        /* '<S1>/solver' */
  real_T Xopt[37];                     /* '<S1>/solver' */
  real_T J;                            /* '<S1>/solver' */
  flags flag;                          /* '<S1>/solver' */
  prediction_longitudinal_mpc_T obj_h; /* '<S1>/prediction' */
  boolean_T objisempty;                /* '<S1>/solver' */
  boolean_T objisempty_f;              /* '<S1>/prediction' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_longitudinal_mpc_T {
  real_T t;                            /* '<Root>/t' */
  real_T ego_state[3];                 /* '<Root>/ego_state' */
  real_T pv_state[3];                  /* '<Root>/pv_state' */
  real_T pos_pred[201];                /* '<Root>/pos_pred' */
  real_T vel_pred[201];                /* '<Root>/vel_pred' */
  real_T acc_pred[201];                /* '<Root>/acc_pred' */
  real_T time_pred[201];               /* '<Root>/time_pred' */
  real_T param_vec[21];                /* '<Root>/param_vec' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_longitudinal_mpc_T {
  real_T acc_des;                      /* '<Root>/acc_des' */
  real_T state_trajectory[128];        /* '<Root>/state_trajectory' */
  real_T control_trajectory[32];       /* '<Root>/control_trajectory' */
  real_T time_trajectory[32];          /* '<Root>/time_trajectory' */
  real_T slacks[5];                    /* '<Root>/slacks' */
  real_T reference[4];                 /* '<Root>/reference' */
  real_T constraint;                   /* '<Root>/constraint' */
  real_T cost;                         /* '<Root>/cost' */
  flags exitflag;                      /* '<Root>/exitflag' */
  real_T iters;                        /* '<Root>/iters' */
};

/* Real-time Model Data Structure */
struct tag_RTM_longitudinal_mpc_T {
  const char_T *errorStatus;
};

/* Class declaration for model longitudinal_mpc */
class longitudinal_mpc final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  longitudinal_mpc(longitudinal_mpc const&) = delete;

  /* Assignment Operator */
  longitudinal_mpc& operator= (longitudinal_mpc const&) & = delete;

  /* Move Constructor */
  longitudinal_mpc(longitudinal_mpc &&) = delete;

  /* Move Assignment Operator */
  longitudinal_mpc& operator= (longitudinal_mpc &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_longitudinal_mpc_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_longitudinal_mpc_T *pExtU_longitudinal_mpc_T)
  {
    longitudinal_mpc_U = *pExtU_longitudinal_mpc_T;
  }

  /* Root outports get method */
  const ExtY_longitudinal_mpc_T &getExternalOutputs() const
  {
    return longitudinal_mpc_Y;
  }

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  longitudinal_mpc();

  /* Destructor */
  ~longitudinal_mpc();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_longitudinal_mpc_T longitudinal_mpc_U;

  /* External outputs */
  ExtY_longitudinal_mpc_T longitudinal_mpc_Y;

  /* Block signals */
  B_longitudinal_mpc_T longitudinal_mpc_B;

  /* Block states */
  DW_longitudinal_mpc_T longitudinal_mpc_DW;

  /* private member function(s) for subsystem '<Root>'*/
  void lon_PCCMPC_checkErrorParameters(solver_longitudinal_mpc_T *b_this);
  void longitudin_PCCMPC_setParameters(solver_longitudinal_mpc_T *b_this);
  real_T longitudinal_mpc_norm(const real_T x[16]);
  void longitudinal_mpc_mpower(const real_T a[16], real_T b, real_T c[16]);
  real_T longitudinal_mpc_log2(real_T x);
  void longitudinal__padeApproximation(const real_T A[16], const real_T A2[16],
    const real_T A4[16], const real_T A6[16], int32_T m, real_T F[16]);
  void longitudinal_recomputeBlockDiag(const real_T A[16], real_T F[16], const
    int32_T blockFormat[3]);
  real_T longitudinal_mpc_xnrm2(int32_T n, const real_T x[16], int32_T ix0);
  void longitudinal_mpc_xzlascl(real_T cfrom, real_T cto, int32_T m, real_T A[4],
    int32_T iA0);
  void longitudinal_mpc_xzlascl_b(real_T cfrom, real_T cto, int32_T m, real_T A
    [3], int32_T iA0);
  void longitudinal_mpc_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn,
    real_T *r);
  void longitudinal_mpc_rotateRight_b(int32_T n, real_T z[16], int32_T iz0,
    const real_T cs[6], int32_T ic0, int32_T is0);
  void longitudinal_mpc_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1,
    real_T *rt2, real_T *cs1, real_T *sn1);
  void longitudinal_mpc_rotateRight(int32_T n, real_T z[16], int32_T iz0, const
    real_T cs[6], int32_T ic0, int32_T is0);
  int32_T longitudinal_mpc_xzsteqr(real_T d[4], real_T e[3], real_T z[16]);
  void longitudinal_mpc_xsyheev(const real_T A[16], int32_T *info, real_T W[4],
    real_T b_A[16]);
  void longitudinal_mpc_expm(real_T A[16], real_T F[16]);
  void longitudina_PCCMPC_setObjective(solver_longitudinal_mpc_T *b_this);
  void longit_PCCMPC_setRecursiveModel(solver_longitudinal_mpc_T *b_this);
  void longitudinal_mpc_PCCMPC_initMPC(solver_longitudinal_mpc_T *b_this);
  real_T longitudinal_mpc_eml_erfcore(real_T x);
  void longitudinal_m_binary_expand_op(real_T in1[160], const coder::array<
    real_T, 1U> &in2, const coder::array<real_T, 1U> &in3);
  void longitudinal_mpc_norminv_approx(const real_T p[160], const coder::array<
    real_T, 1U> &mu, const coder::array<real_T, 1U> &sigma, real_T x[160]);
  void longitudinal_m_PCCMPC_getChance(real_T alpha_0, real_T u_var, real_T s_p
    [160], real_T v_p[160], real_T alphas[160]);
  void longitudinal_mpc_interp1_b(const real_T varargin_2[160], real_T Vq[33]);
  boolean_T longitudinal_mpc_vectorAny(const boolean_T x_data[], const int32_T
    x_size[1]);
  void longitudinal_m_PCCMPC_updateMPC(solver_longitudinal_mpc_T *b_this);
  solver_longitudinal_mpc_T *longitudinal_mpc_solver_solver
    (solver_longitudinal_mpc_T *b_this);
  void longitudinal__solver_initSolver(solver_longitudinal_mpc_T *b_this);
  void longitudinal_mpc_interp1(const real_T varargin_1[201], const real_T
    varargin_2[201], const real_T varargin_3[81], real_T Vq[81]);
  void longitudinal_mpc_pchip(const real_T x[81], const real_T y[81], real_T
    v_breaks[81], real_T v_coefs[320]);
  real_T longitudinal_mpc_ppval(const real_T pp_breaks[81], const real_T
    pp_coefs[320], real_T x);
  void longitudinal_mpc_interp1_b4tv(const real_T varargin_1[81], const real_T
    varargin_2[81], const real_T varargin_3[33], real_T Vq[33]);
  void longitudinal_mpc_interp1_b4(const real_T varargin_1[81], const real_T
    varargin_2[324], const real_T varargin_3[32], real_T Vq[128]);
  void longitudinal_mpc_interp1_b4t(const real_T varargin_1[81], const real_T
    varargin_2[81], const real_T varargin_3[32], real_T Vq[32]);
  void longitudinal_m_factoryConstruct(sSQjeS6UA6ous3QrgyAXHyC_longi_T *obj);
  void longitudinal_mpc_compressBounds(int32_T indexLB[38], int32_T indexUB[38],
    int32_T indexFixed[38], const real_T ub[37], int32_T *mLB, int32_T *mUB,
    int32_T *mFixed);
  void longitudinal_mpc_loadProblem(const svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj,
    const real_T Aineq[14763], const real_T bineq[399], int32_T mLB, int32_T mUB,
    const real_T ub[37], int32_T mFixed, svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_obj);
  void longitu_modifyOverheadPhaseOne_(svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj);
  void longitudinal_mpc_setProblemType(svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj,
    int32_T PROBLEM_TYPE);
  real_T longitudinal_mpc_xnrm2_b(int32_T n, const real_T x[18012], int32_T ix0);
  void longitudinal_mpc_xzlarfg(int32_T n, real_T alpha1, real_T x[18012],
    int32_T ix0, real_T *b_alpha1, real_T *tau);
  void longitudinal_mpc_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
    real_T C[18012], int32_T ic0, real_T work[474]);
  void longitudinal_mpc_qrf(real_T A[18012], int32_T m, int32_T n, int32_T nfxd,
    real_T tau[38]);
  void longitudinal_mpc_xgeqp3_b(real_T A[18012], int32_T m, int32_T n, int32_T
    jpvt[474], real_T tau[38]);
  void longitudinal_mpc_computeQ_(sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *obj, int32_T
    nrows);
  int32_T longitud_ComputeNumDependentEq_(sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
    *qrmanager, const real_T beqf[474], int32_T mConstr, int32_T nVar);
  void longitudina_IndexOfDependentEq_(int32_T depIdx[474], int32_T mFixed,
    int32_T nDep, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, int32_T mRows,
    int32_T nCols);
  void longitudinal_mpc_countsort(int32_T x[474], int32_T xLen, int32_T
    workspace[474], int32_T xMin, int32_T xMax);
  void longitudinal_mpc_removeEqConstr(const svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *obj, int32_T idx_global);
  void longitudinal_RemoveDependentEq_(srUNuce4MmfvHoJodBzBujH_longi_T *memspace,
    const svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, int32_T *nDepInd,
    sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager);
  void longitudinal_mpc_removeConstr(svwK1qKQ5yAVvUFh54r0LBD_longi_T *obj,
    int32_T idx_global);
  void longitudin_RemoveDependentIneq_(svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager,
    srUNuce4MmfvHoJodBzBujH_longi_T *memspace, real_T tolfactor);
  void longitudinal_mpc_factorQR(sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *obj, const
    real_T A[18012], int32_T mrows, int32_T ncols);
  void longitudinal_mpc_xgemv(int32_T m, const real_T A[15162], const real_T x
    [18012], real_T y[474]);
  void longitud_maxConstraintViolation(const svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *obj, const real_T x[18012], real_T *v, svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *b_obj);
  void longitudinal_mpc_xgemv_b(int32_T m, const real_T A[15162], const real_T
    x[18012], real_T y[474]);
  void longit_maxConstraintViolation_b(const svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *obj, const real_T x[18012], real_T *v, svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *b_obj);
  boolean_T longitu_feasibleX0ForWorkingSet(real_T workspace[18012], real_T
    xCurrent[38], svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset,
    sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager);
  void longitudinal_mpc_xgemv_b4(int32_T m, const real_T A[15162], const real_T
    x[38], real_T y[474]);
  void longi_maxConstraintViolation_b4(const svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *obj, const real_T x[38], real_T *v, svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_obj);
  void longitudi_PresolveWorkingSet_b4(const suKEVDQMOZ0XRzxi1HugtZH_longi_T
    *solution, const real_T memspace_workspace_float[18012], const int32_T
    memspace_workspace_int[474], const int32_T memspace_workspace_sort[474],
    svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, suKEVDQMOZ0XRzxi1HugtZH_longi_T
    *b_solution, srUNuce4MmfvHoJodBzBujH_longi_T *b_memspace,
    sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager);
  void longitudinal_mpc_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
    real_T workspace[18012], const real_T H[1369], const real_T f[37], const
    real_T x[38]);
  real_T longitudinal_mpc_computeFval(const siuq7rbPRrhRxtZY0x4sHID_longi_T *obj,
    real_T workspace[18012], const real_T H[1369], const real_T f[37], const
    real_T x[38]);
  void longitudinal_mpc_xgemv_b4t(int32_T m, int32_T n, const real_T A[1369],
    int32_T lda, const real_T x[38], real_T y[37]);
  void longitudina_computeGrad_StoreHx(siuq7rbPRrhRxtZY0x4sHID_longi_T *obj,
    const real_T H[1369], const real_T f[37], const real_T x[38]);
  real_T longitudina_computeFval_ReuseHx(const siuq7rbPRrhRxtZY0x4sHID_longi_T
    *obj, real_T workspace[18012], const real_T f[37], const real_T x[38]);
  void longitudinal_mpc_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b,
    real_T *c, real_T *s);
  void longitudinal_m_deleteColMoveEnd(sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *obj,
    int32_T idx);
  void longitudinal_mpc_fullColLDL2_(sSQjeS6UA6ous3QrgyAXHyC_longi_T *obj,
    int32_T NColsRemain, real_T REG_PRIMAL);
  void longitudinal_mpc_xgemv_b4tv(int32_T m, int32_T n, const real_T A[1444],
    int32_T ia0, const real_T x[18012], real_T y[38]);
  void longitudinal_mpc_compute_deltax(const real_T H[1369],
    suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, srUNuce4MmfvHoJodBzBujH_longi_T
    *memspace, const sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager,
    sSQjeS6UA6ous3QrgyAXHyC_longi_T *cholmanager, const
    siuq7rbPRrhRxtZY0x4sHID_longi_T *objective);
  real_T longitudinal_mpc_xnrm2_b4(int32_T n, const real_T x[38]);
  void longitudinal_mpc_xgemv_b4tv3(int32_T m, const real_T A[15162], const
    real_T x[38], real_T y[18012]);
  void longitudinal_mpc_xgemv_b4tv3e(int32_T m, const real_T A[15162], const
    real_T x[38], real_T y[18012]);
  void longitudinal_mpc_ratiotest(const real_T solution_xstar[38], const real_T
    solution_searchDir[38], real_T workspace[18012], int32_T workingset_nVar,
    const real_T workingset_Aineq[15162], const real_T workingset_bineq[399],
    const real_T workingset_lb[38], const real_T workingset_ub[38], const
    int32_T workingset_indexLB[38], const int32_T workingset_indexUB[38], const
    int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const
    boolean_T workingset_isActiveConstr[474], const int32_T workingset_nWConstr
    [5], real_T toldelta, real_T *alpha, boolean_T *newBlocking, int32_T
    *constrType, int32_T *constrIdx, real_T *b_toldelta);
  void longitudinal__feasibleratiotest(const real_T solution_xstar[38], const
    real_T solution_searchDir[38], real_T workspace[18012], int32_T
    workingset_nVar, const real_T workingset_Aineq[15162], const real_T
    workingset_bineq[399], const real_T workingset_lb[38], const real_T
    workingset_ub[38], const int32_T workingset_indexLB[38], const int32_T
    workingset_indexUB[38], const int32_T workingset_sizes[5], const int32_T
    workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[474],
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
    boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
  void longit_checkUnboundedOrIllPosed(suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution,
    const siuq7rbPRrhRxtZY0x4sHID_longi_T *objective);
  void long_addBoundToActiveSetMatrix_(const svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *obj, int32_T TYPE, int32_T idx_local, svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *b_obj);
  void lo_checkStoppingAndUpdateFval_b(int32_T activeSetChangeID, const real_T
    f[37], suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution,
    srUNuce4MmfvHoJodBzBujH_longi_T *memspace, const
    siuq7rbPRrhRxtZY0x4sHID_longi_T *objective, svwK1qKQ5yAVvUFh54r0LBD_longi_T *
    workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, real_T
    options_ObjectiveLimit, real_T runTimeOptions_ConstrRelTolFact, boolean_T
    updateFval, int32_T *b_activeSetChangeID, boolean_T *b_updateFval);
  void longitudinal_mpc_iterate_b(const real_T H[1369], const real_T f[37],
    suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, srUNuce4MmfvHoJodBzBujH_longi_T
    *memspace, svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset,
    sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, sSQjeS6UA6ous3QrgyAXHyC_longi_T *
    cholmanager, siuq7rbPRrhRxtZY0x4sHID_longi_T *objective, real_T
    options_ObjectiveLimit, real_T options_StepTolerance, real_T
    runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
    boolean_T runTimeOptions_RemainFeasible);
  void longitudinal_mpc_phaseone_b4(const real_T H[1369], const real_T f[37],
    suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, srUNuce4MmfvHoJodBzBujH_longi_T
    *memspace, const svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset,
    sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, sSQjeS6UA6ous3QrgyAXHyC_longi_T *
    cholmanager, const sL9bDKomAYkxZSVrG9w6En_longit_T *runTimeOptions,
    svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_workingset,
    siuq7rbPRrhRxtZY0x4sHID_longi_T *objective, s7GW9uShiIXbHYZwohNmyqD_longi_T *
    options);
  int32_T longitudin_RemoveDependentEq__b(srUNuce4MmfvHoJodBzBujH_longi_T
    *memspace, const svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset,
    sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager);
  void longitud_PresolveWorkingSet_b4t(const suKEVDQMOZ0XRzxi1HugtZH_longi_T
    *solution, srUNuce4MmfvHoJodBzBujH_longi_T *memspace,
    svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T
    *qrmanager, suKEVDQMOZ0XRzxi1HugtZH_longi_T *b_solution);
  boolean_T longitudinal_mpc_strcmp(const char_T a[8]);
  void longitudin_computeFirstOrderOpt(suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution,
    const siuq7rbPRrhRxtZY0x4sHID_longi_T *objective, const
    svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, real_T workspace[18012]);
  void longitudinal_mpc_phaseone_b4t(const real_T H[1369], const real_T f[37],
    suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, srUNuce4MmfvHoJodBzBujH_longi_T
    *memspace, const svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset,
    sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager, sSQjeS6UA6ous3QrgyAXHyC_longi_T *
    cholmanager, siuq7rbPRrhRxtZY0x4sHID_longi_T *objective,
    s7GW9uShiIXbHYZwohNmyqD_longi_T *options, const
    sL9bDKomAYkxZSVrG9w6En_longit_T *runTimeOptions,
    svwK1qKQ5yAVvUFh54r0LBD_longi_T *b_workingset);
  void longitudinal_mpc_driver(const real_T H[1369], const real_T f[37],
    suKEVDQMOZ0XRzxi1HugtZH_longi_T *solution, const real_T
    memspace_workspace_float[18012], const int32_T memspace_workspace_int[474],
    const int32_T memspace_workspace_sort[474], const
    svwK1qKQ5yAVvUFh54r0LBD_longi_T *workingset, sSQjeS6UA6ous3QrgyAXHyC_longi_T
    *cholmanager, sL9bDKomAYkxZSVrG9w6En_longit_T runTimeOptions,
    srUNuce4MmfvHoJodBzBujH_longi_T *b_memspace, svwK1qKQ5yAVvUFh54r0LBD_longi_T
    *b_workingset, sPWVfH0R9Nt4Hr7G42QZn2G_longi_T *qrmanager,
    siuq7rbPRrhRxtZY0x4sHID_longi_T *objective);
  void longitudinal_mpc_linearForm__b(boolean_T obj_hasLinear, int32_T obj_nvar,
    real_T workspace[38], const real_T H[1369], const real_T f[37], const real_T
    x[38]);
  void longitudinal_mpc_quadprog(const real_T H[1369], const real_T f[37], const
    real_T Aineq[14763], const real_T bineq[399], const real_T ub[37], const
    real_T x0[37], real_T x[37], real_T *fval, real_T *exitflag, char_T
    output_algorithm[10], real_T *output_firstorderopt, real_T
    *output_constrviolation, real_T *output_iterations,
    sZnXTmmXLG06QsvMaQjKaGF_longi_T *lambda);
  boolean_T longitudinal_mpc_isMember(real_T a);
  flags longitudi_convert_to_enum_flags(int32_T input);
  void longitudinal_mp_solver_stepImpl(solver_longitudinal_mpc_T *b_this, const
    real_T ego_state[3], const real_T output_ref[324], const real_T control_ref
    [81], const real_T time_ref[81], const real_T pos_pred[81], const real_T
    vel_pred[81], const real_T time_pred[81], const real_T param_vec[21], real_T
    *u, real_T X[128], real_T U[32], real_T T[32], real_T E[5], real_T R[4],
    real_T *C, real_T *J, flags *flag, real_T *iters);

  /* Real-Time Model */
  RT_MODEL_longitudinal_mpc_T longitudinal_mpc_M;
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('longitudinal_mpc_sl/longitudinal_mpc')    - opens subsystem longitudinal_mpc_sl/longitudinal_mpc
 * hilite_system('longitudinal_mpc_sl/longitudinal_mpc/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'longitudinal_mpc_sl'
 * '<S1>'   : 'longitudinal_mpc_sl/longitudinal_mpc'
 */
#endif                                 /* longitudinal_mpc_h_ */
