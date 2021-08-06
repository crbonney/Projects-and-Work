/* Include files */

#include "blascompat32.h"
#include "robot_dynamics_model_sfun.h"
#include "c1_robot_dynamics_model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "robot_dynamics_model_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[12] = { "theta1", "theta2",
  "frame0_links", "frame1_links", "frame2_links", "rho", "phi_max", "f1", "f2",
  "nargin", "nargout", "x" };

static const char * c1_b_debug_family_names[4] = { "nargin", "nargout", "theta",
  "T" };

static const char * c1_c_debug_family_names[7] = { "M", "N", "P", "nargin",
  "nargout", "TM", "Pv" };

static const char * c1_d_debug_family_names[4] = { "nargin", "nargout", "theta",
  "T" };

static const char * c1_e_debug_family_names[7] = { "M", "N", "P", "nargin",
  "nargout", "TM", "Pv" };

static const char * c1_f_debug_family_names[9] = { "Phi", "Theta", "X", "Y", "Z",
  "nargin", "nargout", "Rho", "phi_max" };

/* Function Declarations */
static void initialize_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void initialize_params_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void enable_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void disable_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void ext_mode_exec_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void set_sim_state_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void sf_c1_robot_dynamics_model(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void initSimStructsc1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_b_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[15]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[16]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[20]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_f_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10000]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[100]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[75]);
static void c1_eml_scalar_eg(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance);
static void c1_TRANS0_1(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_theta, real_T c1_T[16]);
static void c1_TransformPoints(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, real_T c1_TM[16], real_T c1_Pv[15], real_T c1_P[15]);
static void c1_b_eml_scalar_eg(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance);
static void c1_b_TransformPoints(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, real_T c1_TM[16], real_T c1_Pv[6], real_T c1_P[6]);
static void c1_c_eml_scalar_eg(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance);
static void c1_WorkEnvelope2(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, real_T c1_Rho, real_T c1_phi_max);
static void c1_linspace(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_d1, real_T c1_d2, real_T c1_y[100]);
static void c1_meshgrid(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_x[100], real_T c1_y[100], real_T c1_xx[10000], real_T c1_yy[10000]);
static void c1_check_forloop_overflow_error
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance);
static void c1_sph2cart(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_az[10000], real_T c1_elev[10000], real_T c1_r, real_T c1_x[10000],
  real_T c1_y[10000], real_T c1_z[10000]);
static void c1_sin(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                   real_T c1_x[10000], real_T c1_b_x[10000]);
static void c1_cos(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                   real_T c1_x[10000], real_T c1_b_x[10000]);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_i_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_j_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_robot_dynamics_model, const
  char_T *c1_identifier);
static uint8_T c1_k_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sin(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                     real_T c1_x[10000]);
static void c1_b_cos(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                     real_T c1_x[10000]);
static void init_dsm_address_info(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_robot_dynamics_model;
  c1_is_active_c1_robot_dynamics_model = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_robot_dynamics_model = 0U;
}

static void initialize_params_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
}

static void enable_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
  c1_update_debugger_state_c1_robot_dynamics_model(chartInstance);
}

static const mxArray *get_sim_state_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T *c1_is_active_c1_robot_dynamics_model;
  c1_is_active_c1_robot_dynamics_model = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(1), FALSE);
  c1_hoistedGlobal = *c1_is_active_c1_robot_dynamics_model;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_doneDoubleBufferReInit;
  uint8_T *c1_is_active_c1_robot_dynamics_model;
  c1_is_active_c1_robot_dynamics_model = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_is_active_c1_robot_dynamics_model = c1_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "is_active_c1_robot_dynamics_model");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_robot_dynamics_model(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
}

static void sf_c1_robot_dynamics_model(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  int32_T *c1_sfEvent;
  real_T (*c1_x)[4];
  c1_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_x)[c1_i0], 0U);
  }

  *c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_robot_dynamics_model(chartInstance);
  sf_debug_check_for_state_inconsistency(_robot_dynamics_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
  int32_T c1_i1;
  real_T c1_x[4];
  uint32_T c1_debug_family_var_map[12];
  real_T c1_theta1;
  real_T c1_theta2;
  real_T c1_frame0_links[6];
  real_T c1_frame1_links[15];
  real_T c1_frame2_links[6];
  real_T c1_rho;
  real_T c1_phi_max;
  real_T c1_f1[15];
  real_T c1_f2[6];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 0.0;
  int32_T c1_i2;
  static real_T c1_dv0[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, -15.0 };

  int32_T c1_i3;
  static real_T c1_dv1[15] = { 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 6.0, -1.0,
    0.0, 6.0, 0.0, 0.0, 8.0, 0.0 };

  int32_T c1_i4;
  static real_T c1_dv2[6] = { 0.0, 0.0, 0.0, 0.0, 12.0, 0.0 };

  real_T c1_dv3[16];
  int32_T c1_i5;
  real_T c1_dv4[16];
  int32_T c1_i6;
  real_T c1_dv5[15];
  real_T c1_dv6[15];
  int32_T c1_i7;
  real_T c1_theta;
  uint32_T c1_b_debug_family_var_map[4];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_T[16];
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  int32_T c1_i8;
  int32_T c1_i9;
  static real_T c1_dv7[4] = { 0.0, 0.0, -1.0, 8.0 };

  int32_T c1_i10;
  int32_T c1_i11;
  static real_T c1_dv8[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c1_i12;
  real_T c1_b_T[16];
  int32_T c1_i13;
  real_T c1_dv9[6];
  real_T c1_dv10[6];
  int32_T c1_i14;
  real_T c1_dv11[16];
  int32_T c1_i15;
  real_T c1_dv12[6];
  real_T c1_dv13[6];
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  int32_T c1_i19;
  int32_T c1_i20;
  real_T c1_b_u[2];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_c_u[2];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i23;
  static char_T c1_cv0[3] = { 'b', 's', '-' };

  char_T c1_d_u[3];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i24;
  static char_T c1_cv1[9] = { 'L', 'i', 'n', 'e', 'W', 'i', 'd', 't', 'h' };

  char_T c1_e_u[9];
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_i25;
  static real_T c1_dv14[6] = { -15.0, 15.0, -15.0, 15.0, -15.0, 15.0 };

  real_T c1_g_u[6];
  const mxArray *c1_g_y = NULL;
  int32_T c1_i26;
  static char_T c1_cv2[2] = { 'o', 'n' };

  char_T c1_h_u[2];
  const mxArray *c1_h_y = NULL;
  int32_T c1_i27;
  char_T c1_i_u[2];
  const mxArray *c1_i_y = NULL;
  char_T c1_j_u;
  const mxArray *c1_j_y = NULL;
  char_T c1_k_u;
  const mxArray *c1_k_y = NULL;
  char_T c1_l_u;
  const mxArray *c1_l_y = NULL;
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_m_u[5];
  const mxArray *c1_m_y = NULL;
  int32_T c1_i30;
  int32_T c1_i31;
  real_T c1_n_u[5];
  const mxArray *c1_n_y = NULL;
  int32_T c1_i32;
  int32_T c1_i33;
  real_T c1_o_u[5];
  const mxArray *c1_o_y = NULL;
  int32_T c1_i34;
  static char_T c1_cv3[3] = { 'r', 's', '-' };

  char_T c1_p_u[3];
  const mxArray *c1_p_y = NULL;
  int32_T c1_i35;
  char_T c1_q_u[9];
  const mxArray *c1_q_y = NULL;
  real_T c1_r_u;
  const mxArray *c1_r_y = NULL;
  int32_T c1_i36;
  int32_T c1_i37;
  real_T c1_s_u[2];
  const mxArray *c1_s_y = NULL;
  int32_T c1_i38;
  int32_T c1_i39;
  real_T c1_t_u[2];
  const mxArray *c1_t_y = NULL;
  int32_T c1_i40;
  int32_T c1_i41;
  real_T c1_u_u[2];
  const mxArray *c1_u_y = NULL;
  int32_T c1_i42;
  static char_T c1_cv4[3] = { 'g', 'o', '-' };

  char_T c1_v_u[3];
  const mxArray *c1_v_y = NULL;
  int32_T c1_i43;
  static char_T c1_cv5[15] = { 'M', 'a', 'r', 'k', 'e', 'r', 'F', 'a', 'c', 'e',
    'C', 'o', 'l', 'o', 'r' };

  char_T c1_w_u[15];
  const mxArray *c1_w_y = NULL;
  char_T c1_x_u;
  const mxArray *c1_x_y = NULL;
  int32_T c1_i44;
  static char_T c1_cv6[10] = { 'M', 'a', 'r', 'k', 'e', 'r', 'S', 'i', 'z', 'e'
  };

  char_T c1_y_u[10];
  const mxArray *c1_y_y = NULL;
  real_T c1_ab_u;
  const mxArray *c1_ab_y = NULL;
  int32_T c1_i45;
  char_T c1_bb_u[9];
  const mxArray *c1_bb_y = NULL;
  real_T c1_cb_u;
  const mxArray *c1_cb_y = NULL;
  real_T c1_db_u;
  const mxArray *c1_db_y = NULL;
  real_T c1_eb_u;
  const mxArray *c1_eb_y = NULL;
  real_T c1_fb_u;
  const mxArray *c1_fb_y = NULL;
  int32_T c1_i46;
  char_T c1_gb_u[3];
  const mxArray *c1_gb_y = NULL;
  int32_T c1_i47;
  char_T c1_hb_u[15];
  const mxArray *c1_hb_y = NULL;
  char_T c1_ib_u;
  const mxArray *c1_ib_y = NULL;
  int32_T c1_i48;
  char_T c1_jb_u[10];
  const mxArray *c1_jb_y = NULL;
  real_T c1_kb_u;
  const mxArray *c1_kb_y = NULL;
  int32_T c1_i49;
  char_T c1_lb_u[9];
  const mxArray *c1_lb_y = NULL;
  real_T c1_mb_u;
  const mxArray *c1_mb_y = NULL;
  int32_T c1_i50;
  real_T c1_nb_u[6];
  const mxArray *c1_nb_y = NULL;
  int32_T c1_i51;
  static char_T c1_cv7[3] = { 'o', 'f', 'f' };

  char_T c1_ob_u[3];
  const mxArray *c1_ob_y = NULL;
  real_T (*c1_j_x)[4];
  int32_T *c1_sfEvent;
  c1_j_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_x[c1_i1] = (*c1_j_x)[c1_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta1, 0U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta2, 1U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_frame0_links, 2U,
    c1_c_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_frame1_links, 3U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_frame2_links, 4U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_rho, 5U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_phi_max, 6U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_f1, 7U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_f2, 8U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 9U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 10U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_x, 11U, c1_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c1_sfEvent, 3);
  c1_theta1 = c1_x[0];
  _SFD_EML_CALL(0U, *c1_sfEvent, 4);
  c1_theta2 = c1_x[1];
  _SFD_EML_CALL(0U, *c1_sfEvent, 6);
  for (c1_i2 = 0; c1_i2 < 6; c1_i2++) {
    c1_frame0_links[c1_i2] = c1_dv0[c1_i2];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 11);
  for (c1_i3 = 0; c1_i3 < 15; c1_i3++) {
    c1_frame1_links[c1_i3] = c1_dv1[c1_i3];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 16);
  for (c1_i4 = 0; c1_i4 < 6; c1_i4++) {
    c1_frame2_links[c1_i4] = c1_dv2[c1_i4];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 21);
  c1_rho = 14.422205101855956;
  _SFD_EML_CALL(0U, *c1_sfEvent, 22);
  c1_phi_max = 0.982793723247329;
  _SFD_EML_CALL(0U, *c1_sfEvent, 24);
  c1_TRANS0_1(chartInstance, c1_theta1, c1_dv3);
  for (c1_i5 = 0; c1_i5 < 16; c1_i5++) {
    c1_dv4[c1_i5] = c1_dv3[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 15; c1_i6++) {
    c1_dv5[c1_i6] = c1_dv1[c1_i6];
  }

  c1_TransformPoints(chartInstance, c1_dv4, c1_dv5, c1_dv6);
  for (c1_i7 = 0; c1_i7 < 15; c1_i7++) {
    c1_f1[c1_i7] = c1_dv6[c1_i7];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 25);
  c1_theta = c1_theta2;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_d_debug_family_names,
    c1_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargout, 1U,
    c1_b_sf_marshallOut, c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 2U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_T, 3U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, *c1_sfEvent, 4);
  c1_b_x = c1_theta;
  c1_c_x = c1_b_x;
  c1_c_x = muDoubleScalarCos(c1_c_x);
  c1_d_x = c1_theta;
  c1_e_x = c1_d_x;
  c1_e_x = muDoubleScalarSin(c1_e_x);
  c1_f_x = c1_theta;
  c1_g_x = c1_f_x;
  c1_g_x = muDoubleScalarSin(c1_g_x);
  c1_h_x = c1_theta;
  c1_i_x = c1_h_x;
  c1_i_x = muDoubleScalarCos(c1_i_x);
  c1_T[0] = c1_c_x;
  c1_T[4] = -c1_e_x;
  c1_T[8] = 0.0;
  c1_T[12] = 0.0;
  c1_i8 = 0;
  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    c1_T[c1_i8 + 1] = c1_dv7[c1_i9];
    c1_i8 += 4;
  }

  c1_T[2] = c1_g_x;
  c1_T[6] = c1_i_x;
  c1_T[10] = 0.0;
  c1_T[14] = 0.0;
  c1_i10 = 0;
  for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
    c1_T[c1_i10 + 3] = c1_dv8[c1_i11];
    c1_i10 += 4;
  }

  _SFD_SCRIPT_CALL(2U, *c1_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  c1_TRANS0_1(chartInstance, c1_theta1, c1_dv3);
  for (c1_i12 = 0; c1_i12 < 16; c1_i12++) {
    c1_b_T[c1_i12] = c1_T[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 6; c1_i13++) {
    c1_dv9[c1_i13] = c1_dv2[c1_i13];
  }

  c1_b_TransformPoints(chartInstance, c1_b_T, c1_dv9, c1_dv10);
  for (c1_i14 = 0; c1_i14 < 16; c1_i14++) {
    c1_dv11[c1_i14] = c1_dv3[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 6; c1_i15++) {
    c1_dv12[c1_i15] = c1_dv10[c1_i15];
  }

  c1_b_TransformPoints(chartInstance, c1_dv11, c1_dv12, c1_dv13);
  for (c1_i16 = 0; c1_i16 < 6; c1_i16++) {
    c1_f2[c1_i16] = c1_dv13[c1_i16];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 28);
  c1_i17 = 0;
  for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
    c1_u[c1_i18] = c1_frame0_links[c1_i17];
    c1_i17 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  c1_i19 = 0;
  for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
    c1_b_u[c1_i20] = c1_frame0_links[c1_i19 + 1];
    c1_i19 += 3;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
    c1_c_u[c1_i22] = c1_frame0_links[c1_i21 + 2];
    c1_i21 += 3;
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
    c1_d_u[c1_i23] = c1_cv0[c1_i23];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c1_i24 = 0; c1_i24 < 9; c1_i24++) {
    c1_e_u[c1_i24] = c1_cv1[c1_i24];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c1_f_u = 3.0;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 6U, 14, c1_y, 14, c1_b_y, 14, c1_c_y, 14,
                    c1_d_y, 14, c1_e_y, 14, c1_f_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 29);
  for (c1_i25 = 0; c1_i25 < 6; c1_i25++) {
    c1_g_u[c1_i25] = c1_dv14[c1_i25];
  }

  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_call_debug("axis", 0U, 1U, 14, c1_g_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 30);
  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_h_u[c1_i26] = c1_cv2[c1_i26];
  }

  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_h_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("grid", 0U, 1U, 14, c1_h_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 31);
  for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
    c1_i_u[c1_i27] = c1_cv2[c1_i27];
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("hold", 0U, 1U, 14, c1_i_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 32);
  c1_j_u = 'x';
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("xlabel", 0U, 1U, 14, c1_j_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 33);
  c1_k_u = 'y';
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_k_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("ylabel", 0U, 1U, 14, c1_k_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 34);
  c1_l_u = 'z';
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_l_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("zlabel", 0U, 1U, 14, c1_l_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 35);
  c1_i28 = 0;
  for (c1_i29 = 0; c1_i29 < 5; c1_i29++) {
    c1_m_u[c1_i29] = c1_f1[c1_i28];
    c1_i28 += 3;
  }

  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_m_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 5; c1_i31++) {
    c1_n_u[c1_i31] = c1_f1[c1_i30 + 1];
    c1_i30 += 3;
  }

  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_n_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  c1_i32 = 0;
  for (c1_i33 = 0; c1_i33 < 5; c1_i33++) {
    c1_o_u[c1_i33] = c1_f1[c1_i32 + 2];
    c1_i32 += 3;
  }

  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_o_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
    c1_p_u[c1_i34] = c1_cv3[c1_i34];
  }

  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", c1_p_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c1_i35 = 0; c1_i35 < 9; c1_i35++) {
    c1_q_u[c1_i35] = c1_cv1[c1_i35];
  }

  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", c1_q_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c1_r_u = 3.0;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 6U, 14, c1_m_y, 14, c1_n_y, 14, c1_o_y, 14,
                    c1_p_y, 14, c1_q_y, 14, c1_r_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 36);
  c1_i36 = 0;
  for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
    c1_s_u[c1_i37] = c1_f2[c1_i36];
    c1_i36 += 3;
  }

  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", c1_s_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  c1_i38 = 0;
  for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
    c1_t_u[c1_i39] = c1_f2[c1_i38 + 1];
    c1_i38 += 3;
  }

  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", c1_t_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  c1_i40 = 0;
  for (c1_i41 = 0; c1_i41 < 2; c1_i41++) {
    c1_u_u[c1_i41] = c1_f2[c1_i40 + 2];
    c1_i40 += 3;
  }

  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", c1_u_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  for (c1_i42 = 0; c1_i42 < 3; c1_i42++) {
    c1_v_u[c1_i42] = c1_cv4[c1_i42];
  }

  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", c1_v_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c1_i43 = 0; c1_i43 < 15; c1_i43++) {
    c1_w_u[c1_i43] = c1_cv5[c1_i43];
  }

  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", c1_w_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  c1_x_u = 'c';
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_x_u, 10, 0U, 0U, 0U, 0), FALSE);
  for (c1_i44 = 0; c1_i44 < 10; c1_i44++) {
    c1_y_u[c1_i44] = c1_cv6[c1_i44];
  }

  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", c1_y_u, 10, 0U, 1U, 0U, 2, 1, 10),
                FALSE);
  c1_ab_u = 5.0;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c1_i45 = 0; c1_i45 < 9; c1_i45++) {
    c1_bb_u[c1_i45] = c1_cv1[c1_i45];
  }

  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", c1_bb_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c1_cb_u = 3.0;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_cb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 10U, 14, c1_s_y, 14, c1_t_y, 14, c1_u_y, 14,
                    c1_v_y, 14, c1_w_y, 14, c1_x_y, 14, c1_y_y, 14, c1_ab_y, 14,
                    c1_bb_y, 14, c1_cb_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 37);
  c1_db_u = c1_f2[3];
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_db_u, 0, 0U, 0U, 0U, 0), FALSE);
  c1_eb_u = c1_f2[4];
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_eb_u, 0, 0U, 0U, 0U, 0), FALSE);
  c1_fb_u = c1_f2[5];
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_fb_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c1_i46 = 0; c1_i46 < 3; c1_i46++) {
    c1_gb_u[c1_i46] = c1_cv4[c1_i46];
  }

  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", c1_gb_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c1_i47 = 0; c1_i47 < 15; c1_i47++) {
    c1_hb_u[c1_i47] = c1_cv5[c1_i47];
  }

  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", c1_hb_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  c1_ib_u = 'c';
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_ib_u, 10, 0U, 0U, 0U, 0), FALSE);
  for (c1_i48 = 0; c1_i48 < 10; c1_i48++) {
    c1_jb_u[c1_i48] = c1_cv6[c1_i48];
  }

  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", c1_jb_u, 10, 0U, 1U, 0U, 2, 1, 10),
                FALSE);
  c1_kb_u = 5.0;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_kb_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c1_i49 = 0; c1_i49 < 9; c1_i49++) {
    c1_lb_u[c1_i49] = c1_cv1[c1_i49];
  }

  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", c1_lb_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c1_mb_u = 3.0;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_mb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 10U, 14, c1_db_y, 14, c1_eb_y, 14, c1_fb_y, 14,
                    c1_gb_y, 14, c1_hb_y, 14, c1_ib_y, 14, c1_jb_y, 14, c1_kb_y,
                    14, c1_lb_y, 14, c1_mb_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 38);
  for (c1_i50 = 0; c1_i50 < 6; c1_i50++) {
    c1_nb_u[c1_i50] = c1_dv14[c1_i50];
  }

  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", c1_nb_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_call_debug("axis", 0U, 1U, 14, c1_nb_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, 39);
  c1_WorkEnvelope2(chartInstance, 14.422205101855956, 0.982793723247329);
  _SFD_EML_CALL(0U, *c1_sfEvent, 40);
  for (c1_i51 = 0; c1_i51 < 3; c1_i51++) {
    c1_ob_u[c1_i51] = c1_cv7[c1_i51];
  }

  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", c1_ob_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_call_debug("hold", 0U, 1U, 14, c1_ob_y);
  _SFD_EML_CALL(0U, *c1_sfEvent, -40);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
}

static void initSimStructsc1_robot_dynamics_model
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 0U, sf_debug_get_script_id(
    "//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 1U, sf_debug_get_script_id(
    "//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TransformPoints.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 2U, sf_debug_get_script_id(
    "//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 3U, sf_debug_get_script_id(
    "//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i52;
  real_T c1_b_inData[4];
  int32_T c1_i53;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i52 = 0; c1_i52 < 4; c1_i52++) {
    c1_b_inData[c1_i52] = (*(real_T (*)[4])c1_inData)[c1_i52];
  }

  for (c1_i53 = 0; c1_i53 < 4; c1_i53++) {
    c1_u[c1_i53] = c1_b_inData[c1_i53];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  real_T c1_b_inData[6];
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i54 = 0;
  for (c1_i55 = 0; c1_i55 < 2; c1_i55++) {
    for (c1_i56 = 0; c1_i56 < 3; c1_i56++) {
      c1_b_inData[c1_i56 + c1_i54] = (*(real_T (*)[6])c1_inData)[c1_i56 + c1_i54];
    }

    c1_i54 += 3;
  }

  c1_i57 = 0;
  for (c1_i58 = 0; c1_i58 < 2; c1_i58++) {
    for (c1_i59 = 0; c1_i59 < 3; c1_i59++) {
      c1_u[c1_i59 + c1_i57] = c1_b_inData[c1_i59 + c1_i57];
    }

    c1_i57 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_b_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6])
{
  real_T c1_dv15[6];
  int32_T c1_i60;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv15, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c1_i60 = 0; c1_i60 < 6; c1_i60++) {
    c1_y[c1_i60] = c1_dv15[c1_i60];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_f2;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[6];
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_f2 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_f2), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_f2);
  c1_i61 = 0;
  for (c1_i62 = 0; c1_i62 < 2; c1_i62++) {
    for (c1_i63 = 0; c1_i63 < 3; c1_i63++) {
      (*(real_T (*)[6])c1_outData)[c1_i63 + c1_i61] = c1_y[c1_i63 + c1_i61];
    }

    c1_i61 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  real_T c1_b_inData[15];
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  real_T c1_u[15];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i64 = 0;
  for (c1_i65 = 0; c1_i65 < 5; c1_i65++) {
    for (c1_i66 = 0; c1_i66 < 3; c1_i66++) {
      c1_b_inData[c1_i66 + c1_i64] = (*(real_T (*)[15])c1_inData)[c1_i66 +
        c1_i64];
    }

    c1_i64 += 3;
  }

  c1_i67 = 0;
  for (c1_i68 = 0; c1_i68 < 5; c1_i68++) {
    for (c1_i69 = 0; c1_i69 < 3; c1_i69++) {
      c1_u[c1_i69 + c1_i67] = c1_b_inData[c1_i69 + c1_i67];
    }

    c1_i67 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 5), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[15])
{
  real_T c1_dv16[15];
  int32_T c1_i70;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv16, 1, 0, 0U, 1, 0U, 2, 3, 5);
  for (c1_i70 = 0; c1_i70 < 15; c1_i70++) {
    c1_y[c1_i70] = c1_dv16[c1_i70];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_f1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[15];
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_f1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_f1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_f1);
  c1_i71 = 0;
  for (c1_i72 = 0; c1_i72 < 5; c1_i72++) {
    for (c1_i73 = 0; c1_i73 < 3; c1_i73++) {
      (*(real_T (*)[15])c1_outData)[c1_i73 + c1_i71] = c1_y[c1_i73 + c1_i71];
    }

    c1_i71 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  real_T c1_b_inData[16];
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  real_T c1_u[16];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i74 = 0;
  for (c1_i75 = 0; c1_i75 < 4; c1_i75++) {
    for (c1_i76 = 0; c1_i76 < 4; c1_i76++) {
      c1_b_inData[c1_i76 + c1_i74] = (*(real_T (*)[16])c1_inData)[c1_i76 +
        c1_i74];
    }

    c1_i74 += 4;
  }

  c1_i77 = 0;
  for (c1_i78 = 0; c1_i78 < 4; c1_i78++) {
    for (c1_i79 = 0; c1_i79 < 4; c1_i79++) {
      c1_u[c1_i79 + c1_i77] = c1_b_inData[c1_i79 + c1_i77];
    }

    c1_i77 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[16])
{
  real_T c1_dv17[16];
  int32_T c1_i80;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv17, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c1_i80 = 0; c1_i80 < 16; c1_i80++) {
    c1_y[c1_i80] = c1_dv17[c1_i80];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_T;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[16];
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_T = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_T), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_T);
  c1_i81 = 0;
  for (c1_i82 = 0; c1_i82 < 4; c1_i82++) {
    for (c1_i83 = 0; c1_i83 < 4; c1_i83++) {
      (*(real_T (*)[16])c1_outData)[c1_i83 + c1_i81] = c1_y[c1_i83 + c1_i81];
    }

    c1_i81 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  real_T c1_b_inData[20];
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  real_T c1_u[20];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i84 = 0;
  for (c1_i85 = 0; c1_i85 < 5; c1_i85++) {
    for (c1_i86 = 0; c1_i86 < 4; c1_i86++) {
      c1_b_inData[c1_i86 + c1_i84] = (*(real_T (*)[20])c1_inData)[c1_i86 +
        c1_i84];
    }

    c1_i84 += 4;
  }

  c1_i87 = 0;
  for (c1_i88 = 0; c1_i88 < 5; c1_i88++) {
    for (c1_i89 = 0; c1_i89 < 4; c1_i89++) {
      c1_u[c1_i89 + c1_i87] = c1_b_inData[c1_i89 + c1_i87];
    }

    c1_i87 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 5), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[20])
{
  real_T c1_dv18[20];
  int32_T c1_i90;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv18, 1, 0, 0U, 1, 0U, 2, 4, 5);
  for (c1_i90 = 0; c1_i90 < 20; c1_i90++) {
    c1_y[c1_i90] = c1_dv18[c1_i90];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_P;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[20];
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_P = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_P), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_P);
  c1_i91 = 0;
  for (c1_i92 = 0; c1_i92 < 5; c1_i92++) {
    for (c1_i93 = 0; c1_i93 < 4; c1_i93++) {
      (*(real_T (*)[20])c1_outData)[c1_i93 + c1_i91] = c1_y[c1_i93 + c1_i91];
    }

    c1_i91 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  real_T c1_b_inData[8];
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  real_T c1_u[8];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i94 = 0;
  for (c1_i95 = 0; c1_i95 < 2; c1_i95++) {
    for (c1_i96 = 0; c1_i96 < 4; c1_i96++) {
      c1_b_inData[c1_i96 + c1_i94] = (*(real_T (*)[8])c1_inData)[c1_i96 + c1_i94];
    }

    c1_i94 += 4;
  }

  c1_i97 = 0;
  for (c1_i98 = 0; c1_i98 < 2; c1_i98++) {
    for (c1_i99 = 0; c1_i99 < 4; c1_i99++) {
      c1_u[c1_i99 + c1_i97] = c1_b_inData[c1_i99 + c1_i97];
    }

    c1_i97 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8])
{
  real_T c1_dv19[8];
  int32_T c1_i100;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv19, 1, 0, 0U, 1, 0U, 2, 4, 2);
  for (c1_i100 = 0; c1_i100 < 8; c1_i100++) {
    c1_y[c1_i100] = c1_dv19[c1_i100];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_P;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[8];
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_P = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_P), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_P);
  c1_i101 = 0;
  for (c1_i102 = 0; c1_i102 < 2; c1_i102++) {
    for (c1_i103 = 0; c1_i103 < 4; c1_i103++) {
      (*(real_T (*)[8])c1_outData)[c1_i103 + c1_i101] = c1_y[c1_i103 + c1_i101];
    }

    c1_i101 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i104;
  int32_T c1_i105;
  int32_T c1_i106;
  real_T c1_b_inData[10000];
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  real_T c1_u[10000];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i104 = 0;
  for (c1_i105 = 0; c1_i105 < 100; c1_i105++) {
    for (c1_i106 = 0; c1_i106 < 100; c1_i106++) {
      c1_b_inData[c1_i106 + c1_i104] = (*(real_T (*)[10000])c1_inData)[c1_i106 +
        c1_i104];
    }

    c1_i104 += 100;
  }

  c1_i107 = 0;
  for (c1_i108 = 0; c1_i108 < 100; c1_i108++) {
    for (c1_i109 = 0; c1_i109 < 100; c1_i109++) {
      c1_u[c1_i109 + c1_i107] = c1_b_inData[c1_i109 + c1_i107];
    }

    c1_i107 += 100;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10000])
{
  real_T c1_dv20[10000];
  int32_T c1_i110;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv20, 1, 0, 0U, 1, 0U, 2, 100,
                100);
  for (c1_i110 = 0; c1_i110 < 10000; c1_i110++) {
    c1_y[c1_i110] = c1_dv20[c1_i110];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Theta;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[10000];
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_Theta = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Theta), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Theta);
  c1_i111 = 0;
  for (c1_i112 = 0; c1_i112 < 100; c1_i112++) {
    for (c1_i113 = 0; c1_i113 < 100; c1_i113++) {
      (*(real_T (*)[10000])c1_outData)[c1_i113 + c1_i111] = c1_y[c1_i113 +
        c1_i111];
    }

    c1_i111 += 100;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i114;
  real_T c1_b_inData[100];
  int32_T c1_i115;
  real_T c1_u[100];
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i114 = 0; c1_i114 < 100; c1_i114++) {
    c1_b_inData[c1_i114] = (*(real_T (*)[100])c1_inData)[c1_i114];
  }

  for (c1_i115 = 0; c1_i115 < 100; c1_i115++) {
    c1_u[c1_i115] = c1_b_inData[c1_i115];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 100), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[100])
{
  real_T c1_dv21[100];
  int32_T c1_i116;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv21, 1, 0, 0U, 1, 0U, 2, 1,
                100);
  for (c1_i116 = 0; c1_i116 < 100; c1_i116++) {
    c1_y[c1_i116] = c1_dv21[c1_i116];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Phi;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[100];
  int32_T c1_i117;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_Phi = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Phi), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Phi);
  for (c1_i117 = 0; c1_i117 < 100; c1_i117++) {
    (*(real_T (*)[100])c1_outData)[c1_i117] = c1_y[c1_i117];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_robot_dynamics_model_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[75];
  c1_ResolvedFunctionInfo (*c1_b_info)[75];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i118;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info = (c1_ResolvedFunctionInfo (*)[75])c1_info;
  (*c1_b_info)[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  (*c1_b_info)[64].name = "eml_index_times";
  (*c1_b_info)[64].dominantType = "coder.internal.indexInt";
  (*c1_b_info)[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c1_b_info)[64].fileTimeLo = 1286843980U;
  (*c1_b_info)[64].fileTimeHi = 0U;
  (*c1_b_info)[64].mFileTimeLo = 0U;
  (*c1_b_info)[64].mFileTimeHi = 0U;
  (*c1_b_info)[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c1_b_info)[65].name = "eml_index_class";
  (*c1_b_info)[65].dominantType = "";
  (*c1_b_info)[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[65].fileTimeLo = 1323195778U;
  (*c1_b_info)[65].fileTimeHi = 0U;
  (*c1_b_info)[65].mFileTimeLo = 0U;
  (*c1_b_info)[65].mFileTimeHi = 0U;
  (*c1_b_info)[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  (*c1_b_info)[66].name = "eml_int_forloop_overflow_check";
  (*c1_b_info)[66].dominantType = "";
  (*c1_b_info)[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c1_b_info)[66].fileTimeLo = 1332190272U;
  (*c1_b_info)[66].fileTimeHi = 0U;
  (*c1_b_info)[66].mFileTimeLo = 0U;
  (*c1_b_info)[66].mFileTimeHi = 0U;
  (*c1_b_info)[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c1_b_info)[67].name = "intmax";
  (*c1_b_info)[67].dominantType = "char";
  (*c1_b_info)[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c1_b_info)[67].fileTimeLo = 1311280516U;
  (*c1_b_info)[67].fileTimeHi = 0U;
  (*c1_b_info)[67].mFileTimeLo = 0U;
  (*c1_b_info)[67].mFileTimeHi = 0U;
  (*c1_b_info)[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  (*c1_b_info)[68].name = "eml_index_plus";
  (*c1_b_info)[68].dominantType = "coder.internal.indexInt";
  (*c1_b_info)[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c1_b_info)[68].fileTimeLo = 1286843978U;
  (*c1_b_info)[68].fileTimeHi = 0U;
  (*c1_b_info)[68].mFileTimeLo = 0U;
  (*c1_b_info)[68].mFileTimeHi = 0U;
  (*c1_b_info)[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c1_b_info)[69].name = "eml_index_class";
  (*c1_b_info)[69].dominantType = "";
  (*c1_b_info)[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[69].fileTimeLo = 1323195778U;
  (*c1_b_info)[69].fileTimeHi = 0U;
  (*c1_b_info)[69].mFileTimeLo = 0U;
  (*c1_b_info)[69].mFileTimeHi = 0U;
  (*c1_b_info)[70].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  (*c1_b_info)[70].name = "sph2cart";
  (*c1_b_info)[70].dominantType = "double";
  (*c1_b_info)[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m";
  (*c1_b_info)[70].fileTimeLo = 1286844056U;
  (*c1_b_info)[70].fileTimeHi = 0U;
  (*c1_b_info)[70].mFileTimeLo = 0U;
  (*c1_b_info)[70].mFileTimeHi = 0U;
  (*c1_b_info)[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m";
  (*c1_b_info)[71].name = "sin";
  (*c1_b_info)[71].dominantType = "double";
  (*c1_b_info)[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c1_b_info)[71].fileTimeLo = 1286843950U;
  (*c1_b_info)[71].fileTimeHi = 0U;
  (*c1_b_info)[71].mFileTimeLo = 0U;
  (*c1_b_info)[71].mFileTimeHi = 0U;
  (*c1_b_info)[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m";
  (*c1_b_info)[72].name = "cos";
  (*c1_b_info)[72].dominantType = "double";
  (*c1_b_info)[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c1_b_info)[72].fileTimeLo = 1286843906U;
  (*c1_b_info)[72].fileTimeHi = 0U;
  (*c1_b_info)[72].mFileTimeLo = 0U;
  (*c1_b_info)[72].mFileTimeHi = 0U;
  (*c1_b_info)[73].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  (*c1_b_info)[73].name = "surf";
  (*c1_b_info)[73].dominantType = "double";
  (*c1_b_info)[73].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/surf.m";
  (*c1_b_info)[73].fileTimeLo = 1301761842U;
  (*c1_b_info)[73].fileTimeHi = 0U;
  (*c1_b_info)[73].mFileTimeLo = 0U;
  (*c1_b_info)[73].mFileTimeHi = 0U;
  (*c1_b_info)[74].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  (*c1_b_info)[74].name = "alpha";
  (*c1_b_info)[74].dominantType = "char";
  (*c1_b_info)[74].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/alpha.m";
  (*c1_b_info)[74].fileTimeLo = 1315194094U;
  (*c1_b_info)[74].fileTimeHi = 0U;
  (*c1_b_info)[74].mFileTimeLo = 0U;
  (*c1_b_info)[74].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 75), FALSE);
  for (c1_i118 = 0; c1_i118 < 75; c1_i118++) {
    c1_r0 = &c1_info[c1_i118];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i118);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i118);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i118);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i118);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i118);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i118);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i118);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i118);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[75])
{
  c1_info[0].context = "";
  c1_info[0].name = "mpower";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[0].fileTimeLo = 1286844042U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[1].name = "power";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[1].fileTimeLo = 1336547296U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[2].name = "eml_scalar_eg";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[2].fileTimeLo = 1286843996U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[3].name = "eml_scalexp_alloc";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[3].fileTimeLo = 1330633634U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[4].name = "floor";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[4].fileTimeLo = 1286843942U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[5].name = "eml_scalar_floor";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[5].fileTimeLo = 1286843926U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "";
  c1_info[6].name = "sqrt";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[6].fileTimeLo = 1286843952U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[7].name = "eml_error";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[7].fileTimeLo = 1305343200U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[8].name = "eml_scalar_sqrt";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[8].fileTimeLo = 1286843938U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "mrdivide";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[9].fileTimeLo = 1342836144U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 1319755166U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[10].name = "rdivide";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[10].fileTimeLo = 1286844044U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[11].name = "eml_div";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[11].fileTimeLo = 1313373010U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "";
  c1_info[12].name = "atan";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c1_info[12].fileTimeLo = 1305343198U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c1_info[13].name = "eml_scalar_atan";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c1_info[13].fileTimeLo = 1286843918U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context = "";
  c1_info[14].name = "TRANS0_1";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m";
  c1_info[14].fileTimeLo = 1580841057U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m";
  c1_info[15].name = "cos";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[15].fileTimeLo = 1286843906U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[16].name = "eml_scalar_cos";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[16].fileTimeLo = 1286843922U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m";
  c1_info[17].name = "sin";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[17].fileTimeLo = 1286843950U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[18].name = "eml_scalar_sin";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[18].fileTimeLo = 1286843936U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "TransformPoints";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TransformPoints.m";
  c1_info[19].fileTimeLo = 1580835490U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TransformPoints.m";
  c1_info[20].name = "mtimes";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[20].fileTimeLo = 1289544892U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[21].name = "eml_index_class";
  c1_info[21].dominantType = "";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[21].fileTimeLo = 1323195778U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[22].name = "eml_scalar_eg";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[22].fileTimeLo = 1286843996U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[23].name = "eml_xgemm";
  c1_info[23].dominantType = "char";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[23].fileTimeLo = 1299101972U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[24].name = "eml_blas_inline";
  c1_info[24].dominantType = "";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[24].fileTimeLo = 1299101968U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[25].name = "mtimes";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[25].fileTimeLo = 1289544892U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[26].name = "eml_index_class";
  c1_info[26].dominantType = "";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[26].fileTimeLo = 1323195778U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[27].name = "eml_scalar_eg";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[27].fileTimeLo = 1286843996U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[28].name = "eml_refblas_xgemm";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[28].fileTimeLo = 1299101974U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context = "";
  c1_info[29].name = "TRANS1_2";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m";
  c1_info[29].fileTimeLo = 1580841127U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m";
  c1_info[30].name = "cos";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[30].fileTimeLo = 1286843906U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m";
  c1_info[31].name = "sin";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[31].fileTimeLo = 1286843950U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context = "";
  c1_info[32].name = "plot3";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved = "[IXMB]$matlabroot$/toolbox/matlab/graph3d/plot3";
  c1_info[32].fileTimeLo = MAX_uint32_T;
  c1_info[32].fileTimeHi = MAX_uint32_T;
  c1_info[32].mFileTimeLo = MAX_uint32_T;
  c1_info[32].mFileTimeHi = MAX_uint32_T;
  c1_info[33].context = "";
  c1_info[33].name = "axis";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/axis.m";
  c1_info[33].fileTimeLo = 1334606568U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context = "";
  c1_info[34].name = "grid";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/grid.m";
  c1_info[34].fileTimeLo = 1311280766U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context = "";
  c1_info[35].name = "hold";
  c1_info[35].dominantType = "char";
  c1_info[35].resolved = "[IXE]$matlabroot$/toolbox/matlab/graphics/hold.m";
  c1_info[35].fileTimeLo = 1305061498U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context = "";
  c1_info[36].name = "xlabel";
  c1_info[36].dominantType = "char";
  c1_info[36].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/xlabel.m";
  c1_info[36].fileTimeLo = 1303582146U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context = "";
  c1_info[37].name = "ylabel";
  c1_info[37].dominantType = "char";
  c1_info[37].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/ylabel.m";
  c1_info[37].fileTimeLo = 1303582146U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context = "";
  c1_info[38].name = "zlabel";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlabel.m";
  c1_info[38].fileTimeLo = 1303582144U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context = "";
  c1_info[39].name = "WorkEnvelope2";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c1_info[39].fileTimeLo = 1581445557U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c1_info[40].name = "linspace";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[40].fileTimeLo = 1286843962U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[41].name = "eml_index_class";
  c1_info[41].dominantType = "";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[41].fileTimeLo = 1323195778U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[42].name = "eml_scalar_eg";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[42].fileTimeLo = 1286843996U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[43].name = "eml_scalar_floor";
  c1_info[43].dominantType = "coder.internal.indexInt";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[43].fileTimeLo = 1286843926U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[44].name = "realmax";
  c1_info[44].dominantType = "char";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[44].fileTimeLo = 1307676442U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[45].name = "eml_realmax";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[45].fileTimeLo = 1326753196U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[46].name = "eml_float_model";
  c1_info[46].dominantType = "char";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[46].fileTimeLo = 1326753196U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[47].name = "mtimes";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[47].fileTimeLo = 1289544892U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[48].name = "mrdivide";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[48].fileTimeLo = 1342836144U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 1319755166U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[49].name = "mtimes";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[49].fileTimeLo = 1289544892U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c1_info[50].name = "mtimes";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[50].fileTimeLo = 1289544892U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[E]//nfs.seas.wustl.edu/seaslab/home-lab/crbonney/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c1_info[51].name = "meshgrid";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c1_info[51].fileTimeLo = 1294093142U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c1_info[52].name = "repmat";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[52].fileTimeLo = 1297372434U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[53].name = "eml_assert_valid_size_arg";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[53].fileTimeLo = 1286843894U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c1_info[54].name = "isinf";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[54].fileTimeLo = 1286843960U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c1_info[55].name = "mtimes";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[55].fileTimeLo = 1289544892U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[56].name = "eml_index_class";
  c1_info[56].dominantType = "";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[56].fileTimeLo = 1323195778U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[57].name = "intmax";
  c1_info[57].dominantType = "char";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[57].fileTimeLo = 1311280516U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[58].name = "eml_index_class";
  c1_info[58].dominantType = "";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[58].fileTimeLo = 1323195778U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[59].name = "eml_index_minus";
  c1_info[59].dominantType = "coder.internal.indexInt";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[59].fileTimeLo = 1286843978U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[60].name = "eml_index_class";
  c1_info[60].dominantType = "";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[60].fileTimeLo = 1323195778U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[61].name = "eml_scalar_eg";
  c1_info[61].dominantType = "double";
  c1_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[61].fileTimeLo = 1286843996U;
  c1_info[61].fileTimeHi = 0U;
  c1_info[61].mFileTimeLo = 0U;
  c1_info[61].mFileTimeHi = 0U;
  c1_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c1_info[62].name = "eml_index_prod";
  c1_info[62].dominantType = "double";
  c1_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c1_info[62].fileTimeLo = 1286843980U;
  c1_info[62].fileTimeHi = 0U;
  c1_info[62].mFileTimeLo = 0U;
  c1_info[62].mFileTimeHi = 0U;
  c1_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c1_info[63].name = "eml_index_class";
  c1_info[63].dominantType = "";
  c1_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[63].fileTimeLo = 1323195778U;
  c1_info[63].fileTimeHi = 0U;
  c1_info[63].mFileTimeLo = 0U;
  c1_info[63].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance)
{
}

static void c1_TRANS0_1(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_theta, real_T c1_T[16])
{
  uint32_T c1_debug_family_var_map[4];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  int32_T c1_i119;
  int32_T c1_i120;
  static real_T c1_dv22[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c1_i121;
  int32_T c1_i122;
  static real_T c1_dv23[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T *c1_sfEvent;
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 2U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_T, 3U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, *c1_sfEvent, 3);
  c1_x = c1_theta;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_theta;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_e_x = c1_theta;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_g_x = c1_theta;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_T[0] = c1_b_x;
  c1_T[4] = -c1_d_x;
  c1_T[8] = 0.0;
  c1_T[12] = 0.0;
  c1_T[1] = c1_f_x;
  c1_T[5] = c1_h_x;
  c1_T[9] = 0.0;
  c1_T[13] = 0.0;
  c1_i119 = 0;
  for (c1_i120 = 0; c1_i120 < 4; c1_i120++) {
    c1_T[c1_i119 + 2] = c1_dv22[c1_i120];
    c1_i119 += 4;
  }

  c1_i121 = 0;
  for (c1_i122 = 0; c1_i122 < 4; c1_i122++) {
    c1_T[c1_i121 + 3] = c1_dv23[c1_i122];
    c1_i121 += 4;
  }

  _SFD_SCRIPT_CALL(0U, *c1_sfEvent, -3);
  sf_debug_symbol_scope_pop();
}

static void c1_TransformPoints(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, real_T c1_TM[16], real_T c1_Pv[15], real_T c1_P[15])
{
  uint32_T c1_debug_family_var_map[7];
  real_T c1_M;
  real_T c1_N;
  real_T c1_b_P[20];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  int32_T c1_i126;
  int32_T c1_i127;
  int32_T c1_i128;
  int32_T c1_i129;
  real_T c1_a[16];
  int32_T c1_i130;
  real_T c1_b[20];
  int32_T c1_i131;
  int32_T c1_i132;
  int32_T c1_i133;
  real_T c1_C[20];
  int32_T c1_i134;
  int32_T c1_i135;
  int32_T c1_i136;
  int32_T c1_i137;
  int32_T c1_i138;
  int32_T c1_i139;
  int32_T c1_i140;
  int32_T c1_i141;
  int32_T c1_i142;
  int32_T c1_i143;
  int32_T c1_i144;
  int32_T c1_i145;
  int32_T *c1_sfEvent;
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 7U, 8U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_M, 0U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_N, 1U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_b_P, MAX_uint32_T,
    c1_f_sf_marshallOut, c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 3U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 4U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_TM, 5U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Pv, 6U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_c_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 3);
  c1_M = 3.0;
  c1_N = 5.0;
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 4);
  c1_i123 = 0;
  c1_i124 = 0;
  for (c1_i125 = 0; c1_i125 < 5; c1_i125++) {
    for (c1_i126 = 0; c1_i126 < 3; c1_i126++) {
      c1_b_P[c1_i126 + c1_i123] = c1_Pv[c1_i126 + c1_i124];
    }

    c1_i123 += 4;
    c1_i124 += 3;
  }

  c1_i127 = 0;
  for (c1_i128 = 0; c1_i128 < 5; c1_i128++) {
    c1_b_P[c1_i127 + 3] = 1.0;
    c1_i127 += 4;
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 5);
  for (c1_i129 = 0; c1_i129 < 16; c1_i129++) {
    c1_a[c1_i129] = c1_TM[c1_i129];
  }

  for (c1_i130 = 0; c1_i130 < 20; c1_i130++) {
    c1_b[c1_i130] = c1_b_P[c1_i130];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i131 = 0; c1_i131 < 20; c1_i131++) {
    c1_b_P[c1_i131] = 0.0;
  }

  for (c1_i132 = 0; c1_i132 < 20; c1_i132++) {
    c1_b_P[c1_i132] = 0.0;
  }

  for (c1_i133 = 0; c1_i133 < 20; c1_i133++) {
    c1_C[c1_i133] = c1_b_P[c1_i133];
  }

  for (c1_i134 = 0; c1_i134 < 20; c1_i134++) {
    c1_b_P[c1_i134] = c1_C[c1_i134];
  }

  for (c1_i135 = 0; c1_i135 < 20; c1_i135++) {
    c1_C[c1_i135] = c1_b_P[c1_i135];
  }

  for (c1_i136 = 0; c1_i136 < 20; c1_i136++) {
    c1_b_P[c1_i136] = c1_C[c1_i136];
  }

  for (c1_i137 = 0; c1_i137 < 4; c1_i137++) {
    c1_i138 = 0;
    for (c1_i139 = 0; c1_i139 < 5; c1_i139++) {
      c1_b_P[c1_i138 + c1_i137] = 0.0;
      c1_i140 = 0;
      for (c1_i141 = 0; c1_i141 < 4; c1_i141++) {
        c1_b_P[c1_i138 + c1_i137] += c1_a[c1_i140 + c1_i137] * c1_b[c1_i141 +
          c1_i138];
        c1_i140 += 4;
      }

      c1_i138 += 4;
    }
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 6);
  c1_i142 = 0;
  c1_i143 = 0;
  for (c1_i144 = 0; c1_i144 < 5; c1_i144++) {
    for (c1_i145 = 0; c1_i145 < 3; c1_i145++) {
      c1_P[c1_i145 + c1_i142] = c1_b_P[c1_i145 + c1_i143];
    }

    c1_i142 += 3;
    c1_i143 += 4;
  }

  sf_debug_symbol_switch(2U, 7U);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, -6);
  sf_debug_symbol_scope_pop();
}

static void c1_b_eml_scalar_eg(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance)
{
}

static void c1_b_TransformPoints(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, real_T c1_TM[16], real_T c1_Pv[6], real_T c1_P[6])
{
  uint32_T c1_debug_family_var_map[7];
  real_T c1_M;
  real_T c1_N;
  real_T c1_b_P[8];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i146;
  int32_T c1_i147;
  int32_T c1_i148;
  int32_T c1_i149;
  int32_T c1_i150;
  int32_T c1_i151;
  int32_T c1_i152;
  real_T c1_a[16];
  int32_T c1_i153;
  real_T c1_b[8];
  int32_T c1_i154;
  int32_T c1_i155;
  int32_T c1_i156;
  real_T c1_C[8];
  int32_T c1_i157;
  int32_T c1_i158;
  int32_T c1_i159;
  int32_T c1_i160;
  int32_T c1_i161;
  int32_T c1_i162;
  int32_T c1_i163;
  int32_T c1_i164;
  int32_T c1_i165;
  int32_T c1_i166;
  int32_T c1_i167;
  int32_T c1_i168;
  int32_T *c1_sfEvent;
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 7U, 8U, c1_e_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_M, 0U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_N, 1U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_b_P, MAX_uint32_T,
    c1_g_sf_marshallOut, c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 3U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 4U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_TM, 5U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Pv, 6U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_P, MAX_uint32_T,
    c1_c_sf_marshallOut, c1_b_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 3);
  c1_M = 3.0;
  c1_N = 2.0;
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 4);
  c1_i146 = 0;
  c1_i147 = 0;
  for (c1_i148 = 0; c1_i148 < 2; c1_i148++) {
    for (c1_i149 = 0; c1_i149 < 3; c1_i149++) {
      c1_b_P[c1_i149 + c1_i146] = c1_Pv[c1_i149 + c1_i147];
    }

    c1_i146 += 4;
    c1_i147 += 3;
  }

  c1_i150 = 0;
  for (c1_i151 = 0; c1_i151 < 2; c1_i151++) {
    c1_b_P[c1_i150 + 3] = 1.0;
    c1_i150 += 4;
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 5);
  for (c1_i152 = 0; c1_i152 < 16; c1_i152++) {
    c1_a[c1_i152] = c1_TM[c1_i152];
  }

  for (c1_i153 = 0; c1_i153 < 8; c1_i153++) {
    c1_b[c1_i153] = c1_b_P[c1_i153];
  }

  c1_c_eml_scalar_eg(chartInstance);
  c1_c_eml_scalar_eg(chartInstance);
  for (c1_i154 = 0; c1_i154 < 8; c1_i154++) {
    c1_b_P[c1_i154] = 0.0;
  }

  for (c1_i155 = 0; c1_i155 < 8; c1_i155++) {
    c1_b_P[c1_i155] = 0.0;
  }

  for (c1_i156 = 0; c1_i156 < 8; c1_i156++) {
    c1_C[c1_i156] = c1_b_P[c1_i156];
  }

  for (c1_i157 = 0; c1_i157 < 8; c1_i157++) {
    c1_b_P[c1_i157] = c1_C[c1_i157];
  }

  for (c1_i158 = 0; c1_i158 < 8; c1_i158++) {
    c1_C[c1_i158] = c1_b_P[c1_i158];
  }

  for (c1_i159 = 0; c1_i159 < 8; c1_i159++) {
    c1_b_P[c1_i159] = c1_C[c1_i159];
  }

  for (c1_i160 = 0; c1_i160 < 4; c1_i160++) {
    c1_i161 = 0;
    for (c1_i162 = 0; c1_i162 < 2; c1_i162++) {
      c1_b_P[c1_i161 + c1_i160] = 0.0;
      c1_i163 = 0;
      for (c1_i164 = 0; c1_i164 < 4; c1_i164++) {
        c1_b_P[c1_i161 + c1_i160] += c1_a[c1_i163 + c1_i160] * c1_b[c1_i164 +
          c1_i161];
        c1_i163 += 4;
      }

      c1_i161 += 4;
    }
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, 6);
  c1_i165 = 0;
  c1_i166 = 0;
  for (c1_i167 = 0; c1_i167 < 2; c1_i167++) {
    for (c1_i168 = 0; c1_i168 < 3; c1_i168++) {
      c1_P[c1_i168 + c1_i165] = c1_b_P[c1_i168 + c1_i166];
    }

    c1_i165 += 3;
    c1_i166 += 4;
  }

  sf_debug_symbol_switch(2U, 7U);
  _SFD_SCRIPT_CALL(1U, *c1_sfEvent, -6);
  sf_debug_symbol_scope_pop();
}

static void c1_c_eml_scalar_eg(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance)
{
}

static void c1_WorkEnvelope2(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, real_T c1_Rho, real_T c1_phi_max)
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_Phi[100];
  real_T c1_Theta[100];
  static real_T c1_X[10000];
  static real_T c1_Y[10000];
  static real_T c1_Z[10000];
  static real_T c1_b_Phi[10000];
  static real_T c1_b_Theta[10000];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv24[100];
  int32_T c1_i169;
  int32_T c1_i170;
  int32_T c1_i171;
  real_T c1_c_Phi[100];
  int32_T c1_i172;
  real_T c1_dv25[100];
  static real_T c1_c_Theta[10000];
  static real_T c1_d_Phi[10000];
  int32_T c1_i173;
  int32_T c1_i174;
  int32_T c1_i175;
  static real_T c1_d_Theta[10000];
  int32_T c1_i176;
  static real_T c1_e_Phi[10000];
  static real_T c1_b_Z[10000];
  int32_T c1_i177;
  int32_T c1_i178;
  int32_T c1_i179;
  int32_T c1_i180;
  static real_T c1_u[10000];
  const mxArray *c1_y = NULL;
  int32_T c1_i181;
  static real_T c1_b_u[10000];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i182;
  real_T c1_c_u[10000];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i183;
  static char_T c1_cv8[9] = { 'E', 'd', 'g', 'e', 'C', 'o', 'l', 'o', 'r' };

  char_T c1_d_u[9];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i184;
  static char_T c1_cv9[4] = { 'n', 'o', 'n', 'e' };

  char_T c1_e_u[4];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i185;
  static char_T c1_cv10[3] = { '0', '.', '5' };

  char_T c1_f_u[3];
  const mxArray *c1_f_y = NULL;
  int32_T *c1_sfEvent;
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 9U, 11U, c1_f_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_Phi, MAX_uint32_T,
    c1_i_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_Theta, MAX_uint32_T, c1_i_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_X, 2U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Y, 3U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Z, 4U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Phi, MAX_uint32_T,
    c1_h_sf_marshallOut, c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_Theta, MAX_uint32_T,
    c1_h_sf_marshallOut, c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 5U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 6U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Rho, 7U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_phi_max, 8U, c1_b_sf_marshallOut,
    c1_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, *c1_sfEvent, 4);
  c1_linspace(chartInstance, -c1_phi_max, c1_phi_max, c1_dv24);
  for (c1_i169 = 0; c1_i169 < 100; c1_i169++) {
    c1_Phi[c1_i169] = c1_dv24[c1_i169];
  }

  sf_debug_symbol_switch(0U, 0U);
  _SFD_SCRIPT_CALL(3U, *c1_sfEvent, 5);
  for (c1_i170 = 0; c1_i170 < 100; c1_i170++) {
    c1_Theta[c1_i170] = 0.063466518254339258 * (real_T)c1_i170;
  }

  sf_debug_symbol_switch(1U, 1U);
  _SFD_SCRIPT_CALL(3U, *c1_sfEvent, 6);
  for (c1_i171 = 0; c1_i171 < 100; c1_i171++) {
    c1_c_Phi[c1_i171] = c1_Phi[c1_i171];
  }

  for (c1_i172 = 0; c1_i172 < 100; c1_i172++) {
    c1_dv25[c1_i172] = 0.063466518254339258 * (real_T)c1_i172;
  }

  c1_meshgrid(chartInstance, c1_c_Phi, c1_dv25, c1_d_Phi, c1_c_Theta);
  for (c1_i173 = 0; c1_i173 < 10000; c1_i173++) {
    c1_b_Phi[c1_i173] = c1_d_Phi[c1_i173];
  }

  sf_debug_symbol_switch(0U, 5U);
  for (c1_i174 = 0; c1_i174 < 10000; c1_i174++) {
    c1_b_Theta[c1_i174] = c1_c_Theta[c1_i174];
  }

  sf_debug_symbol_switch(1U, 6U);
  _SFD_SCRIPT_CALL(3U, *c1_sfEvent, 7);
  for (c1_i175 = 0; c1_i175 < 10000; c1_i175++) {
    c1_d_Theta[c1_i175] = c1_b_Theta[c1_i175];
  }

  for (c1_i176 = 0; c1_i176 < 10000; c1_i176++) {
    c1_e_Phi[c1_i176] = c1_b_Phi[c1_i176];
  }

  c1_sph2cart(chartInstance, c1_d_Theta, c1_e_Phi, c1_Rho, c1_d_Phi, c1_c_Theta,
              c1_b_Z);
  for (c1_i177 = 0; c1_i177 < 10000; c1_i177++) {
    c1_X[c1_i177] = c1_d_Phi[c1_i177];
  }

  for (c1_i178 = 0; c1_i178 < 10000; c1_i178++) {
    c1_Y[c1_i178] = c1_c_Theta[c1_i178];
  }

  for (c1_i179 = 0; c1_i179 < 10000; c1_i179++) {
    c1_Z[c1_i179] = c1_b_Z[c1_i179];
  }

  _SFD_SCRIPT_CALL(3U, *c1_sfEvent, 11);
  for (c1_i180 = 0; c1_i180 < 10000; c1_i180++) {
    c1_u[c1_i180] = c1_X[c1_i180];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c1_i181 = 0; c1_i181 < 10000; c1_i181++) {
    c1_b_u[c1_i181] = c1_Y[c1_i181];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c1_i182 = 0; c1_i182 < 10000; c1_i182++) {
    c1_c_u[c1_i182] = c1_Z[c1_i182];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c1_i183 = 0; c1_i183 < 9; c1_i183++) {
    c1_d_u[c1_i183] = c1_cv8[c1_i183];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  for (c1_i184 = 0; c1_i184 < 4; c1_i184++) {
    c1_e_u[c1_i184] = c1_cv9[c1_i184];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("surf", 0U, 5U, 14, c1_y, 14, c1_b_y, 14, c1_c_y, 14, c1_d_y,
                    14, c1_e_y);
  _SFD_SCRIPT_CALL(3U, *c1_sfEvent, 12);
  for (c1_i185 = 0; c1_i185 < 3; c1_i185++) {
    c1_f_u[c1_i185] = c1_cv10[c1_i185];
  }

  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_call_debug("alpha", 0U, 1U, 14, c1_f_y);
  _SFD_SCRIPT_CALL(3U, *c1_sfEvent, -12);
  sf_debug_symbol_scope_pop();
}

static void c1_linspace(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_d1, real_T c1_d2, real_T c1_y[100])
{
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_delta1;
  real_T c1_b_A;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_delta2;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_a;
  real_T c1_b;
  real_T c1_b_y;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_c_y;
  real_T c1_c_A;
  real_T c1_e_x;
  real_T c1_f_x;
  int32_T c1_c_k;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_d_y;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_eml_scalar_eg(chartInstance);
  c1_y[99] = c1_d2;
  c1_y[0] = c1_d1;
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (c1_d1 < 0.0 != c1_d2 < 0.0) {
    if (muDoubleScalarAbs(c1_d1) > 8.9884656743115785E+307) {
      guard2 = TRUE;
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    if (muDoubleScalarAbs(c1_d2) > 8.9884656743115785E+307) {
      guard2 = TRUE;
    } else if (muDoubleScalarAbs(0.0) > 8.9884656743115785E+307) {
      guard1 = TRUE;
    } else {
      c1_c_A = c1_d2 - c1_d1;
      c1_e_x = c1_c_A;
      c1_f_x = c1_e_x;
      c1_delta1 = c1_f_x / 99.0;
      for (c1_c_k = 0; c1_c_k < 98; c1_c_k++) {
        c1_b_k = 1.0 + (real_T)c1_c_k;
        c1_c_a = c1_b_k;
        c1_c_b = c1_delta1;
        c1_d_y = c1_c_a * c1_c_b;
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c1_b_k + 1.0), 1, 100, 1, 0) - 1] = c1_d1 + c1_d_y;
      }
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c1_A = c1_d1;
    c1_x = c1_A;
    c1_b_x = c1_x;
    c1_delta1 = c1_b_x / 99.0;
    c1_b_A = c1_d2;
    c1_c_x = c1_b_A;
    c1_d_x = c1_c_x;
    c1_delta2 = c1_d_x / 99.0;
    for (c1_k = 0; c1_k < 98; c1_k++) {
      c1_b_k = 1.0 + (real_T)c1_k;
      c1_a = c1_delta2;
      c1_b = c1_b_k;
      c1_b_y = c1_a * c1_b;
      c1_b_a = c1_delta1;
      c1_b_b = c1_b_k;
      c1_c_y = c1_b_a * c1_b_b;
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c1_b_k + 1.0), 1, 100, 1, 0) - 1] = (c1_d1 + c1_b_y) - c1_c_y;
    }
  }
}

static void c1_meshgrid(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_x[100], real_T c1_y[100], real_T c1_xx[10000], real_T c1_yy[10000])
{
  int32_T c1_i186;
  real_T c1_a[100];
  int32_T c1_ia;
  int32_T c1_ib;
  int32_T c1_iacol;
  int32_T c1_jcol;
  int32_T c1_itilerow;
  int32_T c1_b_a;
  int32_T c1_c_a;
  int32_T c1_i187;
  real_T c1_d_a[100];
  int32_T c1_b_ib;
  int32_T c1_jtilecol;
  int32_T c1_b_ia;
  int32_T c1_k;
  int32_T c1_e_a;
  int32_T c1_f_a;
  for (c1_i186 = 0; c1_i186 < 100; c1_i186++) {
    c1_a[c1_i186] = c1_x[c1_i186];
  }

  c1_ia = 0;
  c1_ib = 1;
  c1_iacol = 1;
  c1_check_forloop_overflow_error(chartInstance);
  for (c1_jcol = 1; c1_jcol < 101; c1_jcol++) {
    c1_check_forloop_overflow_error(chartInstance);
    for (c1_itilerow = 1; c1_itilerow < 101; c1_itilerow++) {
      c1_ia = c1_iacol;
      c1_xx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_ib), 1, 10000, 1, 0) - 1] = c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ia), 1, 100, 1, 0) - 1];
      c1_b_a = c1_ia;
      c1_ia = c1_b_a;
      c1_c_a = c1_ib + 1;
      c1_ib = c1_c_a;
    }

    c1_iacol = c1_ia + 1;
  }

  for (c1_i187 = 0; c1_i187 < 100; c1_i187++) {
    c1_d_a[c1_i187] = c1_y[c1_i187];
  }

  c1_b_ib = 1;
  c1_check_forloop_overflow_error(chartInstance);
  for (c1_jtilecol = 1; c1_jtilecol < 101; c1_jtilecol++) {
    c1_b_ia = 1;
    c1_check_forloop_overflow_error(chartInstance);
    for (c1_k = 1; c1_k < 101; c1_k++) {
      c1_yy[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_ib), 1, 10000, 1, 0) - 1] =
        c1_d_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c1_b_ia), 1, 100, 1, 0) - 1];
      c1_e_a = c1_b_ia + 1;
      c1_b_ia = c1_e_a;
      c1_f_a = c1_b_ib + 1;
      c1_b_ib = c1_f_a;
    }
  }
}

static void c1_check_forloop_overflow_error
  (SFc1_robot_dynamics_modelInstanceStruct *chartInstance)
{
}

static void c1_sph2cart(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
  real_T c1_az[10000], real_T c1_elev[10000], real_T c1_r, real_T c1_x[10000],
  real_T c1_y[10000], real_T c1_z[10000])
{
  int32_T c1_i188;
  int32_T c1_i189;
  int32_T c1_i190;
  int32_T c1_i191;
  int32_T c1_i192;
  int32_T c1_i193;
  int32_T c1_i194;
  real_T c1_dv26[10000];
  int32_T c1_i195;
  for (c1_i188 = 0; c1_i188 < 10000; c1_i188++) {
    c1_z[c1_i188] = c1_elev[c1_i188];
  }

  c1_b_sin(chartInstance, c1_z);
  for (c1_i189 = 0; c1_i189 < 10000; c1_i189++) {
    c1_z[c1_i189] *= c1_r;
  }

  for (c1_i190 = 0; c1_i190 < 10000; c1_i190++) {
    c1_y[c1_i190] = c1_elev[c1_i190];
  }

  c1_b_cos(chartInstance, c1_y);
  for (c1_i191 = 0; c1_i191 < 10000; c1_i191++) {
    c1_y[c1_i191] *= c1_r;
  }

  for (c1_i192 = 0; c1_i192 < 10000; c1_i192++) {
    c1_x[c1_i192] = c1_az[c1_i192];
  }

  c1_b_cos(chartInstance, c1_x);
  for (c1_i193 = 0; c1_i193 < 10000; c1_i193++) {
    c1_x[c1_i193] *= c1_y[c1_i193];
  }

  for (c1_i194 = 0; c1_i194 < 10000; c1_i194++) {
    c1_dv26[c1_i194] = c1_az[c1_i194];
  }

  c1_b_sin(chartInstance, c1_dv26);
  for (c1_i195 = 0; c1_i195 < 10000; c1_i195++) {
    c1_y[c1_i195] *= c1_dv26[c1_i195];
  }
}

static void c1_sin(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                   real_T c1_x[10000], real_T c1_b_x[10000])
{
  int32_T c1_i196;
  for (c1_i196 = 0; c1_i196 < 10000; c1_i196++) {
    c1_b_x[c1_i196] = c1_x[c1_i196];
  }

  c1_b_sin(chartInstance, c1_b_x);
}

static void c1_cos(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                   real_T c1_x[10000], real_T c1_b_x[10000])
{
  int32_T c1_i197;
  for (c1_i197 = 0; c1_i197 < 10000; c1_i197++) {
    c1_b_x[c1_i197] = c1_x[c1_i197];
  }

  c1_b_cos(chartInstance, c1_b_x);
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_i_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i198;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i198, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i198;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_robot_dynamics_model, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_is_active_c1_robot_dynamics_model), &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_robot_dynamics_model);
  return c1_y;
}

static uint8_T c1_k_emlrt_marshallIn(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sin(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                     real_T c1_x[10000])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  for (c1_k = 0; c1_k < 10000; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 10000, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_c_x = muDoubleScalarSin(c1_c_x);
    c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 10000, 1, 0) - 1] = c1_c_x;
  }
}

static void c1_b_cos(SFc1_robot_dynamics_modelInstanceStruct *chartInstance,
                     real_T c1_x[10000])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  for (c1_k = 0; c1_k < 10000; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 10000, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_c_x = muDoubleScalarCos(c1_c_x);
    c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 10000, 1, 0) - 1] = c1_c_x;
  }
}

static void init_dsm_address_info(SFc1_robot_dynamics_modelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_robot_dynamics_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1989056317U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1451011396U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1487815576U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1296084817U);
}

mxArray *sf_c1_robot_dynamics_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("33lZRLkVsu4YvjHaLgpf8E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_robot_dynamics_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_robot_dynamics_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_robot_dynamics_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
    chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_robot_dynamics_modelMachineNumber_,
           1,
           1,
           1,
           1,
           0,
           0,
           0,
           0,
           4,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_robot_dynamics_modelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_robot_dynamics_modelMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_robot_dynamics_modelMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1086);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"TRANS0_1",0,-1,205);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"TransformPoints",0,-1,121);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"TRANS1_2",0,-1,206);
        _SFD_CV_INIT_SCRIPT(3,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"WorkEnvelope2",0,-1,323);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c1_x)[4];
          c1_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_x);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_robot_dynamics_modelMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "RXWrwfeGzHMw1JmyEloRsF";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_robot_dynamics_model_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 1, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c1_robot_dynamics_model(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_robot_dynamics_model
    ((SFc1_robot_dynamics_modelInstanceStruct*) chartInstanceVar);
  initialize_c1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_robot_dynamics_model(void *chartInstanceVar)
{
  enable_c1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_robot_dynamics_model(void *chartInstanceVar)
{
  disable_c1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_robot_dynamics_model(void *chartInstanceVar)
{
  sf_c1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_robot_dynamics_model(void
  *chartInstanceVar)
{
  ext_mode_exec_c1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_robot_dynamics_model
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_robot_dynamics_model
    ((SFc1_robot_dynamics_modelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_robot_dynamics_model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_robot_dynamics_model(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_robot_dynamics_model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_robot_dynamics_model(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_robot_dynamics_model(S);
}

static void sf_opaque_set_sim_state_c1_robot_dynamics_model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_robot_dynamics_model(S, st);
}

static void sf_opaque_terminate_c1_robot_dynamics_model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_robot_dynamics_modelInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_robot_dynamics_model_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_robot_dynamics_model((SFc1_robot_dynamics_modelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_robot_dynamics_model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_robot_dynamics_model
      ((SFc1_robot_dynamics_modelInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_robot_dynamics_model_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c1_robot_dynamics_model\",T\"is_active_c1_robot_dynamics_model\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c1_robot_dynamics_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_robot_dynamics_model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(225306664U));
  ssSetChecksum1(S,(1449713696U));
  ssSetChecksum2(S,(712831367U));
  ssSetChecksum3(S,(4044847212U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_robot_dynamics_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_robot_dynamics_model(SimStruct *S)
{
  SFc1_robot_dynamics_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_dynamics_modelInstanceStruct *)malloc(sizeof
    (SFc1_robot_dynamics_modelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_robot_dynamics_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_robot_dynamics_model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_robot_dynamics_model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_robot_dynamics_model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_robot_dynamics_model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_robot_dynamics_model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_robot_dynamics_model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_robot_dynamics_model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_robot_dynamics_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_robot_dynamics_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_robot_dynamics_model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_robot_dynamics_model;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_robot_dynamics_model;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_robot_dynamics_model_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_robot_dynamics_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_robot_dynamics_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_robot_dynamics_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_robot_dynamics_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
