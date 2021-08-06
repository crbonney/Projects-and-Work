/* Include files */

#include "blascompat32.h"
#include "Joint_data_model_sfun.h"
#include "c2_Joint_data_model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Joint_data_model_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[11] = { "frame0_links", "frame1_links",
  "frame2_links", "rho", "phi_max", "f1", "f2", "nargin", "nargout", "theta1",
  "theta2" };

static const char * c2_b_debug_family_names[4] = { "nargin", "nargout", "theta",
  "T" };

static const char * c2_c_debug_family_names[7] = { "M", "N", "P", "nargin",
  "nargout", "TM", "Pv" };

static const char * c2_d_debug_family_names[4] = { "nargin", "nargout", "theta",
  "T" };

static const char * c2_e_debug_family_names[7] = { "M", "N", "P", "nargin",
  "nargout", "TM", "Pv" };

static const char * c2_f_debug_family_names[9] = { "Phi", "Theta", "X", "Y", "Z",
  "nargin", "nargout", "Rho", "phi_max" };

/* Function Declarations */
static void initialize_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void initialize_params_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance);
static void enable_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void disable_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance);
static void ext_mode_exec_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance);
static void set_sim_state_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void sf_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void initSimStructsc2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_b_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[15]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[20]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[8]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[10000]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[100]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[75]);
static void c2_eml_scalar_eg(SFc2_Joint_data_modelInstanceStruct *chartInstance);
static void c2_TRANS0_1(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_theta, real_T c2_T[16]);
static void c2_TransformPoints(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, real_T c2_TM[16], real_T c2_Pv[15], real_T c2_P[15]);
static void c2_b_eml_scalar_eg(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void c2_b_TransformPoints(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, real_T c2_TM[16], real_T c2_Pv[6], real_T c2_P[6]);
static void c2_c_eml_scalar_eg(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);
static void c2_WorkEnvelope2(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_Rho, real_T c2_phi_max);
static void c2_linspace(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_d1, real_T c2_d2, real_T c2_y[100]);
static void c2_meshgrid(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_x[100], real_T c2_y[100], real_T c2_xx[10000], real_T c2_yy[10000]);
static void c2_check_forloop_overflow_error(SFc2_Joint_data_modelInstanceStruct *
  chartInstance);
static void c2_sph2cart(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_az[10000], real_T c2_elev[10000], real_T c2_r, real_T c2_x[10000],
  real_T c2_y[10000], real_T c2_z[10000]);
static void c2_sin(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                   c2_x[10000], real_T c2_b_x[10000]);
static void c2_cos(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                   c2_x[10000], real_T c2_b_x[10000]);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_Joint_data_model, const char_T *
  c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sin(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                     c2_x[10000]);
static void c2_b_cos(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                     c2_x[10000]);
static void init_dsm_address_info(SFc2_Joint_data_modelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_Joint_data_model;
  c2_is_active_c2_Joint_data_model = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_Joint_data_model = 0U;
}

static void initialize_params_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance)
{
}

static void enable_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance)
{
  c2_update_debugger_state_c2_Joint_data_model(chartInstance);
}

static const mxArray *get_sim_state_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T *c2_is_active_c2_Joint_data_model;
  c2_is_active_c2_Joint_data_model = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(1), FALSE);
  c2_hoistedGlobal = *c2_is_active_c2_Joint_data_model;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_is_active_c2_Joint_data_model;
  c2_is_active_c2_Joint_data_model = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_is_active_c2_Joint_data_model = c2_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 0)), "is_active_c2_Joint_data_model");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Joint_data_model(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
}

static void sf_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
  int32_T *c2_sfEvent;
  real_T *c2_theta1;
  real_T *c2_theta2;
  c2_theta2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_theta1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_theta1, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_theta2, 1U);
  *c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Joint_data_model(chartInstance);
  sf_debug_check_for_state_inconsistency(_Joint_data_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Joint_data_model(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_theta1;
  real_T c2_theta2;
  uint32_T c2_debug_family_var_map[11];
  real_T c2_frame0_links[6];
  real_T c2_frame1_links[15];
  real_T c2_frame2_links[6];
  real_T c2_rho;
  real_T c2_phi_max;
  real_T c2_f1[15];
  real_T c2_f2[6];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 0.0;
  int32_T c2_i0;
  static real_T c2_dv0[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, -15.0 };

  int32_T c2_i1;
  static real_T c2_dv1[15] = { 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 6.0, -1.0,
    0.0, 6.0, 0.0, 0.0, 8.0, 0.0 };

  int32_T c2_i2;
  static real_T c2_dv2[6] = { 0.0, 0.0, 0.0, 0.0, 12.0, 0.0 };

  real_T c2_dv3[16];
  int32_T c2_i3;
  real_T c2_dv4[16];
  int32_T c2_i4;
  real_T c2_dv5[15];
  real_T c2_dv6[15];
  int32_T c2_i5;
  real_T c2_theta;
  uint32_T c2_b_debug_family_var_map[4];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_T[16];
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  int32_T c2_i6;
  int32_T c2_i7;
  static real_T c2_dv7[4] = { 0.0, 0.0, -1.0, 8.0 };

  int32_T c2_i8;
  int32_T c2_i9;
  static real_T c2_dv8[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c2_i10;
  real_T c2_b_T[16];
  int32_T c2_i11;
  real_T c2_dv9[6];
  real_T c2_dv10[6];
  int32_T c2_i12;
  real_T c2_dv11[16];
  int32_T c2_i13;
  real_T c2_dv12[6];
  real_T c2_dv13[6];
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  int32_T c2_i17;
  int32_T c2_i18;
  real_T c2_b_u[2];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i19;
  int32_T c2_i20;
  real_T c2_c_u[2];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i21;
  static char_T c2_cv0[3] = { 'b', 's', '-' };

  char_T c2_d_u[3];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i22;
  static char_T c2_cv1[9] = { 'L', 'i', 'n', 'e', 'W', 'i', 'd', 't', 'h' };

  char_T c2_e_u[9];
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i23;
  static real_T c2_dv14[6] = { -15.0, 15.0, -15.0, 15.0, -15.0, 15.0 };

  real_T c2_g_u[6];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i24;
  static char_T c2_cv2[2] = { 'o', 'n' };

  char_T c2_h_u[2];
  const mxArray *c2_h_y = NULL;
  int32_T c2_i25;
  char_T c2_i_u[2];
  const mxArray *c2_i_y = NULL;
  char_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  char_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  char_T c2_l_u;
  const mxArray *c2_l_y = NULL;
  int32_T c2_i26;
  int32_T c2_i27;
  real_T c2_m_u[5];
  const mxArray *c2_m_y = NULL;
  int32_T c2_i28;
  int32_T c2_i29;
  real_T c2_n_u[5];
  const mxArray *c2_n_y = NULL;
  int32_T c2_i30;
  int32_T c2_i31;
  real_T c2_o_u[5];
  const mxArray *c2_o_y = NULL;
  int32_T c2_i32;
  static char_T c2_cv3[3] = { 'r', 's', '-' };

  char_T c2_p_u[3];
  const mxArray *c2_p_y = NULL;
  int32_T c2_i33;
  char_T c2_q_u[9];
  const mxArray *c2_q_y = NULL;
  real_T c2_r_u;
  const mxArray *c2_r_y = NULL;
  int32_T c2_i34;
  int32_T c2_i35;
  real_T c2_s_u[2];
  const mxArray *c2_s_y = NULL;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_t_u[2];
  const mxArray *c2_t_y = NULL;
  int32_T c2_i38;
  int32_T c2_i39;
  real_T c2_u_u[2];
  const mxArray *c2_u_y = NULL;
  int32_T c2_i40;
  static char_T c2_cv4[3] = { 'g', 'o', '-' };

  char_T c2_v_u[3];
  const mxArray *c2_v_y = NULL;
  int32_T c2_i41;
  static char_T c2_cv5[15] = { 'M', 'a', 'r', 'k', 'e', 'r', 'F', 'a', 'c', 'e',
    'C', 'o', 'l', 'o', 'r' };

  char_T c2_w_u[15];
  const mxArray *c2_w_y = NULL;
  char_T c2_x_u;
  const mxArray *c2_x_y = NULL;
  int32_T c2_i42;
  static char_T c2_cv6[10] = { 'M', 'a', 'r', 'k', 'e', 'r', 'S', 'i', 'z', 'e'
  };

  char_T c2_y_u[10];
  const mxArray *c2_y_y = NULL;
  real_T c2_ab_u;
  const mxArray *c2_ab_y = NULL;
  int32_T c2_i43;
  char_T c2_bb_u[9];
  const mxArray *c2_bb_y = NULL;
  real_T c2_cb_u;
  const mxArray *c2_cb_y = NULL;
  real_T c2_db_u;
  const mxArray *c2_db_y = NULL;
  real_T c2_eb_u;
  const mxArray *c2_eb_y = NULL;
  real_T c2_fb_u;
  const mxArray *c2_fb_y = NULL;
  int32_T c2_i44;
  char_T c2_gb_u[3];
  const mxArray *c2_gb_y = NULL;
  int32_T c2_i45;
  char_T c2_hb_u[15];
  const mxArray *c2_hb_y = NULL;
  char_T c2_ib_u;
  const mxArray *c2_ib_y = NULL;
  int32_T c2_i46;
  char_T c2_jb_u[10];
  const mxArray *c2_jb_y = NULL;
  real_T c2_kb_u;
  const mxArray *c2_kb_y = NULL;
  int32_T c2_i47;
  char_T c2_lb_u[9];
  const mxArray *c2_lb_y = NULL;
  real_T c2_mb_u;
  const mxArray *c2_mb_y = NULL;
  int32_T c2_i48;
  real_T c2_nb_u[6];
  const mxArray *c2_nb_y = NULL;
  int32_T c2_i49;
  static char_T c2_cv7[3] = { 'o', 'f', 'f' };

  char_T c2_ob_u[3];
  const mxArray *c2_ob_y = NULL;
  real_T *c2_b_theta1;
  real_T *c2_b_theta2;
  int32_T *c2_sfEvent;
  c2_b_theta2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_theta1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c2_sfEvent);
  c2_hoistedGlobal = *c2_b_theta1;
  c2_b_hoistedGlobal = *c2_b_theta2;
  c2_theta1 = c2_hoistedGlobal;
  c2_theta2 = c2_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_frame0_links, 0U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_frame1_links, 1U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_frame2_links, 2U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_rho, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_phi_max, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_f1, 5U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_f2, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_theta1, 9U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta2, 10U, c2_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 2);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0++) {
    c2_frame0_links[c2_i0] = c2_dv0[c2_i0];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 7);
  for (c2_i1 = 0; c2_i1 < 15; c2_i1++) {
    c2_frame1_links[c2_i1] = c2_dv1[c2_i1];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 12);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    c2_frame2_links[c2_i2] = c2_dv2[c2_i2];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 17);
  c2_rho = 14.422205101855956;
  _SFD_EML_CALL(0U, *c2_sfEvent, 18);
  c2_phi_max = 0.982793723247329;
  _SFD_EML_CALL(0U, *c2_sfEvent, 20);
  c2_TRANS0_1(chartInstance, c2_theta1, c2_dv3);
  for (c2_i3 = 0; c2_i3 < 16; c2_i3++) {
    c2_dv4[c2_i3] = c2_dv3[c2_i3];
  }

  for (c2_i4 = 0; c2_i4 < 15; c2_i4++) {
    c2_dv5[c2_i4] = c2_dv1[c2_i4];
  }

  c2_TransformPoints(chartInstance, c2_dv4, c2_dv5, c2_dv6);
  for (c2_i5 = 0; c2_i5 < 15; c2_i5++) {
    c2_f1[c2_i5] = c2_dv6[c2_i5];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 21);
  c2_theta = c2_theta2;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_d_debug_family_names,
    c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_T, 3U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, *c2_sfEvent, 4);
  c2_x = c2_theta;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_theta;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_e_x = c2_theta;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_theta;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_T[0] = c2_b_x;
  c2_T[4] = -c2_d_x;
  c2_T[8] = 0.0;
  c2_T[12] = 0.0;
  c2_i6 = 0;
  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    c2_T[c2_i6 + 1] = c2_dv7[c2_i7];
    c2_i6 += 4;
  }

  c2_T[2] = c2_f_x;
  c2_T[6] = c2_h_x;
  c2_T[10] = 0.0;
  c2_T[14] = 0.0;
  c2_i8 = 0;
  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    c2_T[c2_i8 + 3] = c2_dv8[c2_i9];
    c2_i8 += 4;
  }

  _SFD_SCRIPT_CALL(2U, *c2_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  c2_TRANS0_1(chartInstance, c2_theta1, c2_dv3);
  for (c2_i10 = 0; c2_i10 < 16; c2_i10++) {
    c2_b_T[c2_i10] = c2_T[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 6; c2_i11++) {
    c2_dv9[c2_i11] = c2_dv2[c2_i11];
  }

  c2_b_TransformPoints(chartInstance, c2_b_T, c2_dv9, c2_dv10);
  for (c2_i12 = 0; c2_i12 < 16; c2_i12++) {
    c2_dv11[c2_i12] = c2_dv3[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 6; c2_i13++) {
    c2_dv12[c2_i13] = c2_dv10[c2_i13];
  }

  c2_b_TransformPoints(chartInstance, c2_dv11, c2_dv12, c2_dv13);
  for (c2_i14 = 0; c2_i14 < 6; c2_i14++) {
    c2_f2[c2_i14] = c2_dv13[c2_i14];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 24);
  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
    c2_u[c2_i16] = c2_frame0_links[c2_i15];
    c2_i15 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  c2_i17 = 0;
  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    c2_b_u[c2_i18] = c2_frame0_links[c2_i17 + 1];
    c2_i17 += 3;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  c2_i19 = 0;
  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    c2_c_u[c2_i20] = c2_frame0_links[c2_i19 + 2];
    c2_i19 += 3;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    c2_d_u[c2_i21] = c2_cv0[c2_i21];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c2_i22 = 0; c2_i22 < 9; c2_i22++) {
    c2_e_u[c2_i22] = c2_cv1[c2_i22];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c2_f_u = 3.0;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 6U, 14, c2_y, 14, c2_b_y, 14, c2_c_y, 14,
                    c2_d_y, 14, c2_e_y, 14, c2_f_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 25);
  for (c2_i23 = 0; c2_i23 < 6; c2_i23++) {
    c2_g_u[c2_i23] = c2_dv14[c2_i23];
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_g_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_call_debug("axis", 0U, 1U, 14, c2_g_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    c2_h_u[c2_i24] = c2_cv2[c2_i24];
  }

  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_h_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("grid", 0U, 1U, 14, c2_h_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 27);
  for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
    c2_i_u[c2_i25] = c2_cv2[c2_i25];
  }

  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_i_u, 10, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  sf_mex_call_debug("hold", 0U, 1U, 14, c2_i_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 28);
  c2_j_u = 'x';
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("xlabel", 0U, 1U, 14, c2_j_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 29);
  c2_k_u = 'y';
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("ylabel", 0U, 1U, 14, c2_k_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 30);
  c2_l_u = 'z';
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 10, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("zlabel", 0U, 1U, 14, c2_l_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 31);
  c2_i26 = 0;
  for (c2_i27 = 0; c2_i27 < 5; c2_i27++) {
    c2_m_u[c2_i27] = c2_f1[c2_i26];
    c2_i26 += 3;
  }

  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_m_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  c2_i28 = 0;
  for (c2_i29 = 0; c2_i29 < 5; c2_i29++) {
    c2_n_u[c2_i29] = c2_f1[c2_i28 + 1];
    c2_i28 += 3;
  }

  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_n_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 5; c2_i31++) {
    c2_o_u[c2_i31] = c2_f1[c2_i30 + 2];
    c2_i30 += 3;
  }

  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_o_u, 0, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  for (c2_i32 = 0; c2_i32 < 3; c2_i32++) {
    c2_p_u[c2_i32] = c2_cv3[c2_i32];
  }

  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_p_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c2_i33 = 0; c2_i33 < 9; c2_i33++) {
    c2_q_u[c2_i33] = c2_cv1[c2_i33];
  }

  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_q_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c2_r_u = 3.0;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_r_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 6U, 14, c2_m_y, 14, c2_n_y, 14, c2_o_y, 14,
                    c2_p_y, 14, c2_q_y, 14, c2_r_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 32);
  c2_i34 = 0;
  for (c2_i35 = 0; c2_i35 < 2; c2_i35++) {
    c2_s_u[c2_i35] = c2_f2[c2_i34];
    c2_i34 += 3;
  }

  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", c2_s_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  c2_i36 = 0;
  for (c2_i37 = 0; c2_i37 < 2; c2_i37++) {
    c2_t_u[c2_i37] = c2_f2[c2_i36 + 1];
    c2_i36 += 3;
  }

  c2_t_y = NULL;
  sf_mex_assign(&c2_t_y, sf_mex_create("y", c2_t_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  c2_i38 = 0;
  for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
    c2_u_u[c2_i39] = c2_f2[c2_i38 + 2];
    c2_i38 += 3;
  }

  c2_u_y = NULL;
  sf_mex_assign(&c2_u_y, sf_mex_create("y", c2_u_u, 0, 0U, 1U, 0U, 2, 1, 2),
                FALSE);
  for (c2_i40 = 0; c2_i40 < 3; c2_i40++) {
    c2_v_u[c2_i40] = c2_cv4[c2_i40];
  }

  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", c2_v_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c2_i41 = 0; c2_i41 < 15; c2_i41++) {
    c2_w_u[c2_i41] = c2_cv5[c2_i41];
  }

  c2_w_y = NULL;
  sf_mex_assign(&c2_w_y, sf_mex_create("y", c2_w_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  c2_x_u = 'c';
  c2_x_y = NULL;
  sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_x_u, 10, 0U, 0U, 0U, 0), FALSE);
  for (c2_i42 = 0; c2_i42 < 10; c2_i42++) {
    c2_y_u[c2_i42] = c2_cv6[c2_i42];
  }

  c2_y_y = NULL;
  sf_mex_assign(&c2_y_y, sf_mex_create("y", c2_y_u, 10, 0U, 1U, 0U, 2, 1, 10),
                FALSE);
  c2_ab_u = 5.0;
  c2_ab_y = NULL;
  sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_ab_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i43 = 0; c2_i43 < 9; c2_i43++) {
    c2_bb_u[c2_i43] = c2_cv1[c2_i43];
  }

  c2_bb_y = NULL;
  sf_mex_assign(&c2_bb_y, sf_mex_create("y", c2_bb_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c2_cb_u = 3.0;
  c2_cb_y = NULL;
  sf_mex_assign(&c2_cb_y, sf_mex_create("y", &c2_cb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 10U, 14, c2_s_y, 14, c2_t_y, 14, c2_u_y, 14,
                    c2_v_y, 14, c2_w_y, 14, c2_x_y, 14, c2_y_y, 14, c2_ab_y, 14,
                    c2_bb_y, 14, c2_cb_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 33);
  c2_db_u = c2_f2[3];
  c2_db_y = NULL;
  sf_mex_assign(&c2_db_y, sf_mex_create("y", &c2_db_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_eb_u = c2_f2[4];
  c2_eb_y = NULL;
  sf_mex_assign(&c2_eb_y, sf_mex_create("y", &c2_eb_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_fb_u = c2_f2[5];
  c2_fb_y = NULL;
  sf_mex_assign(&c2_fb_y, sf_mex_create("y", &c2_fb_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i44 = 0; c2_i44 < 3; c2_i44++) {
    c2_gb_u[c2_i44] = c2_cv4[c2_i44];
  }

  c2_gb_y = NULL;
  sf_mex_assign(&c2_gb_y, sf_mex_create("y", c2_gb_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  for (c2_i45 = 0; c2_i45 < 15; c2_i45++) {
    c2_hb_u[c2_i45] = c2_cv5[c2_i45];
  }

  c2_hb_y = NULL;
  sf_mex_assign(&c2_hb_y, sf_mex_create("y", c2_hb_u, 10, 0U, 1U, 0U, 2, 1, 15),
                FALSE);
  c2_ib_u = 'c';
  c2_ib_y = NULL;
  sf_mex_assign(&c2_ib_y, sf_mex_create("y", &c2_ib_u, 10, 0U, 0U, 0U, 0), FALSE);
  for (c2_i46 = 0; c2_i46 < 10; c2_i46++) {
    c2_jb_u[c2_i46] = c2_cv6[c2_i46];
  }

  c2_jb_y = NULL;
  sf_mex_assign(&c2_jb_y, sf_mex_create("y", c2_jb_u, 10, 0U, 1U, 0U, 2, 1, 10),
                FALSE);
  c2_kb_u = 5.0;
  c2_kb_y = NULL;
  sf_mex_assign(&c2_kb_y, sf_mex_create("y", &c2_kb_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c2_i47 = 0; c2_i47 < 9; c2_i47++) {
    c2_lb_u[c2_i47] = c2_cv1[c2_i47];
  }

  c2_lb_y = NULL;
  sf_mex_assign(&c2_lb_y, sf_mex_create("y", c2_lb_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  c2_mb_u = 3.0;
  c2_mb_y = NULL;
  sf_mex_assign(&c2_mb_y, sf_mex_create("y", &c2_mb_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("plot3", 0U, 10U, 14, c2_db_y, 14, c2_eb_y, 14, c2_fb_y, 14,
                    c2_gb_y, 14, c2_hb_y, 14, c2_ib_y, 14, c2_jb_y, 14, c2_kb_y,
                    14, c2_lb_y, 14, c2_mb_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 34);
  for (c2_i48 = 0; c2_i48 < 6; c2_i48++) {
    c2_nb_u[c2_i48] = c2_dv14[c2_i48];
  }

  c2_nb_y = NULL;
  sf_mex_assign(&c2_nb_y, sf_mex_create("y", c2_nb_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_call_debug("axis", 0U, 1U, 14, c2_nb_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, 35);
  c2_WorkEnvelope2(chartInstance, 14.422205101855956, 0.982793723247329);
  _SFD_EML_CALL(0U, *c2_sfEvent, 36);
  for (c2_i49 = 0; c2_i49 < 3; c2_i49++) {
    c2_ob_u[c2_i49] = c2_cv7[c2_i49];
  }

  c2_ob_y = NULL;
  sf_mex_assign(&c2_ob_y, sf_mex_create("y", c2_ob_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_call_debug("hold", 0U, 1U, 14, c2_ob_y);
  _SFD_EML_CALL(0U, *c2_sfEvent, -36);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c2_sfEvent);
}

static void initSimStructsc2_Joint_data_model
  (SFc2_Joint_data_modelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "H:/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 1U, sf_debug_get_script_id(
    "H:/My Documents/MATLAB/ESE447/Group 2/TransformPoints.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 2U, sf_debug_get_script_id(
    "H:/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 3U, sf_debug_get_script_id(
    "H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  real_T c2_b_inData[6];
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i50 = 0;
  for (c2_i51 = 0; c2_i51 < 2; c2_i51++) {
    for (c2_i52 = 0; c2_i52 < 3; c2_i52++) {
      c2_b_inData[c2_i52 + c2_i50] = (*(real_T (*)[6])c2_inData)[c2_i52 + c2_i50];
    }

    c2_i50 += 3;
  }

  c2_i53 = 0;
  for (c2_i54 = 0; c2_i54 < 2; c2_i54++) {
    for (c2_i55 = 0; c2_i55 < 3; c2_i55++) {
      c2_u[c2_i55 + c2_i53] = c2_b_inData[c2_i55 + c2_i53];
    }

    c2_i53 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_b_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6])
{
  real_T c2_dv15[6];
  int32_T c2_i56;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv15, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c2_i56 = 0; c2_i56 < 6; c2_i56++) {
    c2_y[c2_i56] = c2_dv15[c2_i56];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_f2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_f2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_f2), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_f2);
  c2_i57 = 0;
  for (c2_i58 = 0; c2_i58 < 2; c2_i58++) {
    for (c2_i59 = 0; c2_i59 < 3; c2_i59++) {
      (*(real_T (*)[6])c2_outData)[c2_i59 + c2_i57] = c2_y[c2_i59 + c2_i57];
    }

    c2_i57 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  real_T c2_b_inData[15];
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  real_T c2_u[15];
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i60 = 0;
  for (c2_i61 = 0; c2_i61 < 5; c2_i61++) {
    for (c2_i62 = 0; c2_i62 < 3; c2_i62++) {
      c2_b_inData[c2_i62 + c2_i60] = (*(real_T (*)[15])c2_inData)[c2_i62 +
        c2_i60];
    }

    c2_i60 += 3;
  }

  c2_i63 = 0;
  for (c2_i64 = 0; c2_i64 < 5; c2_i64++) {
    for (c2_i65 = 0; c2_i65 < 3; c2_i65++) {
      c2_u[c2_i65 + c2_i63] = c2_b_inData[c2_i65 + c2_i63];
    }

    c2_i63 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[15])
{
  real_T c2_dv16[15];
  int32_T c2_i66;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv16, 1, 0, 0U, 1, 0U, 2, 3, 5);
  for (c2_i66 = 0; c2_i66 < 15; c2_i66++) {
    c2_y[c2_i66] = c2_dv16[c2_i66];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_f1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[15];
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_f1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_f1), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_f1);
  c2_i67 = 0;
  for (c2_i68 = 0; c2_i68 < 5; c2_i68++) {
    for (c2_i69 = 0; c2_i69 < 3; c2_i69++) {
      (*(real_T (*)[15])c2_outData)[c2_i69 + c2_i67] = c2_y[c2_i69 + c2_i67];
    }

    c2_i67 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  real_T c2_b_inData[16];
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i70 = 0;
  for (c2_i71 = 0; c2_i71 < 4; c2_i71++) {
    for (c2_i72 = 0; c2_i72 < 4; c2_i72++) {
      c2_b_inData[c2_i72 + c2_i70] = (*(real_T (*)[16])c2_inData)[c2_i72 +
        c2_i70];
    }

    c2_i70 += 4;
  }

  c2_i73 = 0;
  for (c2_i74 = 0; c2_i74 < 4; c2_i74++) {
    for (c2_i75 = 0; c2_i75 < 4; c2_i75++) {
      c2_u[c2_i75 + c2_i73] = c2_b_inData[c2_i75 + c2_i73];
    }

    c2_i73 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_dv17[16];
  int32_T c2_i76;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv17, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i76 = 0; c2_i76 < 16; c2_i76++) {
    c2_y[c2_i76] = c2_dv17[c2_i76];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_T;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_T = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_T), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_T);
  c2_i77 = 0;
  for (c2_i78 = 0; c2_i78 < 4; c2_i78++) {
    for (c2_i79 = 0; c2_i79 < 4; c2_i79++) {
      (*(real_T (*)[16])c2_outData)[c2_i79 + c2_i77] = c2_y[c2_i79 + c2_i77];
    }

    c2_i77 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  real_T c2_b_inData[20];
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  real_T c2_u[20];
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i80 = 0;
  for (c2_i81 = 0; c2_i81 < 5; c2_i81++) {
    for (c2_i82 = 0; c2_i82 < 4; c2_i82++) {
      c2_b_inData[c2_i82 + c2_i80] = (*(real_T (*)[20])c2_inData)[c2_i82 +
        c2_i80];
    }

    c2_i80 += 4;
  }

  c2_i83 = 0;
  for (c2_i84 = 0; c2_i84 < 5; c2_i84++) {
    for (c2_i85 = 0; c2_i85 < 4; c2_i85++) {
      c2_u[c2_i85 + c2_i83] = c2_b_inData[c2_i85 + c2_i83];
    }

    c2_i83 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[20])
{
  real_T c2_dv18[20];
  int32_T c2_i86;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv18, 1, 0, 0U, 1, 0U, 2, 4, 5);
  for (c2_i86 = 0; c2_i86 < 20; c2_i86++) {
    c2_y[c2_i86] = c2_dv18[c2_i86];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_P;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[20];
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_P = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_P);
  c2_i87 = 0;
  for (c2_i88 = 0; c2_i88 < 5; c2_i88++) {
    for (c2_i89 = 0; c2_i89 < 4; c2_i89++) {
      (*(real_T (*)[20])c2_outData)[c2_i89 + c2_i87] = c2_y[c2_i89 + c2_i87];
    }

    c2_i87 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  real_T c2_b_inData[8];
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  real_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i90 = 0;
  for (c2_i91 = 0; c2_i91 < 2; c2_i91++) {
    for (c2_i92 = 0; c2_i92 < 4; c2_i92++) {
      c2_b_inData[c2_i92 + c2_i90] = (*(real_T (*)[8])c2_inData)[c2_i92 + c2_i90];
    }

    c2_i90 += 4;
  }

  c2_i93 = 0;
  for (c2_i94 = 0; c2_i94 < 2; c2_i94++) {
    for (c2_i95 = 0; c2_i95 < 4; c2_i95++) {
      c2_u[c2_i95 + c2_i93] = c2_b_inData[c2_i95 + c2_i93];
    }

    c2_i93 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[8])
{
  real_T c2_dv19[8];
  int32_T c2_i96;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv19, 1, 0, 0U, 1, 0U, 2, 4, 2);
  for (c2_i96 = 0; c2_i96 < 8; c2_i96++) {
    c2_y[c2_i96] = c2_dv19[c2_i96];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_P;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[8];
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_P = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_P);
  c2_i97 = 0;
  for (c2_i98 = 0; c2_i98 < 2; c2_i98++) {
    for (c2_i99 = 0; c2_i99 < 4; c2_i99++) {
      (*(real_T (*)[8])c2_outData)[c2_i99 + c2_i97] = c2_y[c2_i99 + c2_i97];
    }

    c2_i97 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  real_T c2_b_inData[10000];
  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i105;
  real_T c2_u[10000];
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i100 = 0;
  for (c2_i101 = 0; c2_i101 < 100; c2_i101++) {
    for (c2_i102 = 0; c2_i102 < 100; c2_i102++) {
      c2_b_inData[c2_i102 + c2_i100] = (*(real_T (*)[10000])c2_inData)[c2_i102 +
        c2_i100];
    }

    c2_i100 += 100;
  }

  c2_i103 = 0;
  for (c2_i104 = 0; c2_i104 < 100; c2_i104++) {
    for (c2_i105 = 0; c2_i105 < 100; c2_i105++) {
      c2_u[c2_i105 + c2_i103] = c2_b_inData[c2_i105 + c2_i103];
    }

    c2_i103 += 100;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[10000])
{
  real_T c2_dv20[10000];
  int32_T c2_i106;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv20, 1, 0, 0U, 1, 0U, 2, 100,
                100);
  for (c2_i106 = 0; c2_i106 < 10000; c2_i106++) {
    c2_y[c2_i106] = c2_dv20[c2_i106];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Theta;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[10000];
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_Theta = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Theta), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Theta);
  c2_i107 = 0;
  for (c2_i108 = 0; c2_i108 < 100; c2_i108++) {
    for (c2_i109 = 0; c2_i109 < 100; c2_i109++) {
      (*(real_T (*)[10000])c2_outData)[c2_i109 + c2_i107] = c2_y[c2_i109 +
        c2_i107];
    }

    c2_i107 += 100;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i110;
  real_T c2_b_inData[100];
  int32_T c2_i111;
  real_T c2_u[100];
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i110 = 0; c2_i110 < 100; c2_i110++) {
    c2_b_inData[c2_i110] = (*(real_T (*)[100])c2_inData)[c2_i110];
  }

  for (c2_i111 = 0; c2_i111 < 100; c2_i111++) {
    c2_u[c2_i111] = c2_b_inData[c2_i111];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 100), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[100])
{
  real_T c2_dv21[100];
  int32_T c2_i112;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv21, 1, 0, 0U, 1, 0U, 2, 1,
                100);
  for (c2_i112 = 0; c2_i112 < 100; c2_i112++) {
    c2_y[c2_i112] = c2_dv21[c2_i112];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Phi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[100];
  int32_T c2_i113;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_Phi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Phi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Phi);
  for (c2_i113 = 0; c2_i113 < 100; c2_i113++) {
    (*(real_T (*)[100])c2_outData)[c2_i113] = c2_y[c2_i113];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Joint_data_model_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[75];
  c2_ResolvedFunctionInfo (*c2_b_info)[75];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i114;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info = (c2_ResolvedFunctionInfo (*)[75])c2_info;
  (*c2_b_info)[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  (*c2_b_info)[64].name = "eml_index_times";
  (*c2_b_info)[64].dominantType = "coder.internal.indexInt";
  (*c2_b_info)[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c2_b_info)[64].fileTimeLo = 1286843980U;
  (*c2_b_info)[64].fileTimeHi = 0U;
  (*c2_b_info)[64].mFileTimeLo = 0U;
  (*c2_b_info)[64].mFileTimeHi = 0U;
  (*c2_b_info)[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c2_b_info)[65].name = "eml_index_class";
  (*c2_b_info)[65].dominantType = "";
  (*c2_b_info)[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c2_b_info)[65].fileTimeLo = 1323195778U;
  (*c2_b_info)[65].fileTimeHi = 0U;
  (*c2_b_info)[65].mFileTimeLo = 0U;
  (*c2_b_info)[65].mFileTimeHi = 0U;
  (*c2_b_info)[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  (*c2_b_info)[66].name = "eml_int_forloop_overflow_check";
  (*c2_b_info)[66].dominantType = "";
  (*c2_b_info)[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c2_b_info)[66].fileTimeLo = 1332190272U;
  (*c2_b_info)[66].fileTimeHi = 0U;
  (*c2_b_info)[66].mFileTimeLo = 0U;
  (*c2_b_info)[66].mFileTimeHi = 0U;
  (*c2_b_info)[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c2_b_info)[67].name = "intmax";
  (*c2_b_info)[67].dominantType = "char";
  (*c2_b_info)[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c2_b_info)[67].fileTimeLo = 1311280516U;
  (*c2_b_info)[67].fileTimeHi = 0U;
  (*c2_b_info)[67].mFileTimeLo = 0U;
  (*c2_b_info)[67].mFileTimeHi = 0U;
  (*c2_b_info)[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  (*c2_b_info)[68].name = "eml_index_plus";
  (*c2_b_info)[68].dominantType = "coder.internal.indexInt";
  (*c2_b_info)[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c2_b_info)[68].fileTimeLo = 1286843978U;
  (*c2_b_info)[68].fileTimeHi = 0U;
  (*c2_b_info)[68].mFileTimeLo = 0U;
  (*c2_b_info)[68].mFileTimeHi = 0U;
  (*c2_b_info)[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c2_b_info)[69].name = "eml_index_class";
  (*c2_b_info)[69].dominantType = "";
  (*c2_b_info)[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c2_b_info)[69].fileTimeLo = 1323195778U;
  (*c2_b_info)[69].fileTimeHi = 0U;
  (*c2_b_info)[69].mFileTimeLo = 0U;
  (*c2_b_info)[69].mFileTimeHi = 0U;
  (*c2_b_info)[70].context =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  (*c2_b_info)[70].name = "sph2cart";
  (*c2_b_info)[70].dominantType = "double";
  (*c2_b_info)[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m";
  (*c2_b_info)[70].fileTimeLo = 1286844056U;
  (*c2_b_info)[70].fileTimeHi = 0U;
  (*c2_b_info)[70].mFileTimeLo = 0U;
  (*c2_b_info)[70].mFileTimeHi = 0U;
  (*c2_b_info)[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m";
  (*c2_b_info)[71].name = "sin";
  (*c2_b_info)[71].dominantType = "double";
  (*c2_b_info)[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[71].fileTimeLo = 1286843950U;
  (*c2_b_info)[71].fileTimeHi = 0U;
  (*c2_b_info)[71].mFileTimeLo = 0U;
  (*c2_b_info)[71].mFileTimeHi = 0U;
  (*c2_b_info)[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/sph2cart.m";
  (*c2_b_info)[72].name = "cos";
  (*c2_b_info)[72].dominantType = "double";
  (*c2_b_info)[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[72].fileTimeLo = 1286843906U;
  (*c2_b_info)[72].fileTimeHi = 0U;
  (*c2_b_info)[72].mFileTimeLo = 0U;
  (*c2_b_info)[72].mFileTimeHi = 0U;
  (*c2_b_info)[73].context =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  (*c2_b_info)[73].name = "surf";
  (*c2_b_info)[73].dominantType = "double";
  (*c2_b_info)[73].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/surf.m";
  (*c2_b_info)[73].fileTimeLo = 1301761842U;
  (*c2_b_info)[73].fileTimeHi = 0U;
  (*c2_b_info)[73].mFileTimeLo = 0U;
  (*c2_b_info)[73].mFileTimeHi = 0U;
  (*c2_b_info)[74].context =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  (*c2_b_info)[74].name = "alpha";
  (*c2_b_info)[74].dominantType = "char";
  (*c2_b_info)[74].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/alpha.m";
  (*c2_b_info)[74].fileTimeLo = 1315194094U;
  (*c2_b_info)[74].fileTimeHi = 0U;
  (*c2_b_info)[74].mFileTimeLo = 0U;
  (*c2_b_info)[74].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 75), FALSE);
  for (c2_i114 = 0; c2_i114 < 75; c2_i114++) {
    c2_r0 = &c2_info[c2_i114];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i114);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[75])
{
  c2_info[0].context = "";
  c2_info[0].name = "mpower";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[0].fileTimeLo = 1286844042U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].name = "power";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[1].fileTimeLo = 1336547296U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[2].name = "eml_scalar_eg";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[2].fileTimeLo = 1286843996U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[3].name = "eml_scalexp_alloc";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[3].fileTimeLo = 1330633634U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[4].name = "floor";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[4].fileTimeLo = 1286843942U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[5].name = "eml_scalar_floor";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[5].fileTimeLo = 1286843926U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "sqrt";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[6].fileTimeLo = 1286843952U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[7].name = "eml_error";
  c2_info[7].dominantType = "char";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[7].fileTimeLo = 1305343200U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[8].name = "eml_scalar_sqrt";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[8].fileTimeLo = 1286843938U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "mrdivide";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[9].fileTimeLo = 1342836144U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 1319755166U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[10].name = "rdivide";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[10].fileTimeLo = 1286844044U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[11].name = "eml_div";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[11].fileTimeLo = 1313373010U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "atan";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[12].fileTimeLo = 1305343198U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[13].name = "eml_scalar_atan";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c2_info[13].fileTimeLo = 1286843918U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "TRANS0_1";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[E]H:/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m";
  c2_info[14].fileTimeLo = 1580841057U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "[E]H:/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m";
  c2_info[15].name = "cos";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[15].fileTimeLo = 1286843906U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[16].name = "eml_scalar_cos";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[16].fileTimeLo = 1286843922U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "[E]H:/My Documents/MATLAB/ESE447/Group 2/TRANS0_1.m";
  c2_info[17].name = "sin";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[17].fileTimeLo = 1286843950U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[18].name = "eml_scalar_sin";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[18].fileTimeLo = 1286843936U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context = "";
  c2_info[19].name = "TransformPoints";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/TransformPoints.m";
  c2_info[19].fileTimeLo = 1580835490U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/TransformPoints.m";
  c2_info[20].name = "mtimes";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[20].fileTimeLo = 1289544892U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[21].name = "eml_index_class";
  c2_info[21].dominantType = "";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[21].fileTimeLo = 1323195778U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[22].name = "eml_scalar_eg";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[22].fileTimeLo = 1286843996U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[23].name = "eml_xgemm";
  c2_info[23].dominantType = "char";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[23].fileTimeLo = 1299101972U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[24].name = "eml_blas_inline";
  c2_info[24].dominantType = "";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[24].fileTimeLo = 1299101968U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[25].name = "mtimes";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[25].fileTimeLo = 1289544892U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[26].name = "eml_index_class";
  c2_info[26].dominantType = "";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[26].fileTimeLo = 1323195778U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[27].name = "eml_scalar_eg";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[27].fileTimeLo = 1286843996U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[28].name = "eml_refblas_xgemm";
  c2_info[28].dominantType = "char";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[28].fileTimeLo = 1299101974U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context = "";
  c2_info[29].name = "TRANS1_2";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[E]H:/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m";
  c2_info[29].fileTimeLo = 1580841127U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context = "[E]H:/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m";
  c2_info[30].name = "cos";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[30].fileTimeLo = 1286843906U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context = "[E]H:/My Documents/MATLAB/ESE447/Group 2/TRANS1_2.m";
  c2_info[31].name = "sin";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[31].fileTimeLo = 1286843950U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context = "";
  c2_info[32].name = "plot3";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[IXMB]$matlabroot$/toolbox/matlab/graph3d/plot3";
  c2_info[32].fileTimeLo = MAX_uint32_T;
  c2_info[32].fileTimeHi = MAX_uint32_T;
  c2_info[32].mFileTimeLo = MAX_uint32_T;
  c2_info[32].mFileTimeHi = MAX_uint32_T;
  c2_info[33].context = "";
  c2_info[33].name = "axis";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/axis.m";
  c2_info[33].fileTimeLo = 1334606568U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context = "";
  c2_info[34].name = "grid";
  c2_info[34].dominantType = "char";
  c2_info[34].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/grid.m";
  c2_info[34].fileTimeLo = 1311280766U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context = "";
  c2_info[35].name = "hold";
  c2_info[35].dominantType = "char";
  c2_info[35].resolved = "[IXE]$matlabroot$/toolbox/matlab/graphics/hold.m";
  c2_info[35].fileTimeLo = 1305061498U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context = "";
  c2_info[36].name = "xlabel";
  c2_info[36].dominantType = "char";
  c2_info[36].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/xlabel.m";
  c2_info[36].fileTimeLo = 1303582146U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context = "";
  c2_info[37].name = "ylabel";
  c2_info[37].dominantType = "char";
  c2_info[37].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph2d/ylabel.m";
  c2_info[37].fileTimeLo = 1303582146U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context = "";
  c2_info[38].name = "zlabel";
  c2_info[38].dominantType = "char";
  c2_info[38].resolved = "[IXE]$matlabroot$/toolbox/matlab/graph3d/zlabel.m";
  c2_info[38].fileTimeLo = 1303582144U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context = "";
  c2_info[39].name = "WorkEnvelope2";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c2_info[39].fileTimeLo = 1581445557U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c2_info[40].name = "linspace";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[40].fileTimeLo = 1286843962U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[41].name = "eml_index_class";
  c2_info[41].dominantType = "";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[41].fileTimeLo = 1323195778U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[42].name = "eml_scalar_eg";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[42].fileTimeLo = 1286843996U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[43].name = "eml_scalar_floor";
  c2_info[43].dominantType = "coder.internal.indexInt";
  c2_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[43].fileTimeLo = 1286843926U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[44].name = "realmax";
  c2_info[44].dominantType = "char";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[44].fileTimeLo = 1307676442U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[45].name = "eml_realmax";
  c2_info[45].dominantType = "char";
  c2_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[45].fileTimeLo = 1326753196U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[46].name = "eml_float_model";
  c2_info[46].dominantType = "char";
  c2_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[46].fileTimeLo = 1326753196U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c2_info[47].name = "mtimes";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[47].fileTimeLo = 1289544892U;
  c2_info[47].fileTimeHi = 0U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[48].name = "mrdivide";
  c2_info[48].dominantType = "double";
  c2_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[48].fileTimeLo = 1342836144U;
  c2_info[48].fileTimeHi = 0U;
  c2_info[48].mFileTimeLo = 1319755166U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c2_info[49].name = "mtimes";
  c2_info[49].dominantType = "double";
  c2_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[49].fileTimeLo = 1289544892U;
  c2_info[49].fileTimeHi = 0U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c2_info[50].name = "mtimes";
  c2_info[50].dominantType = "double";
  c2_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[50].fileTimeLo = 1289544892U;
  c2_info[50].fileTimeHi = 0U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[E]H:/My Documents/MATLAB/ESE447/Group 2/WorkEnvelope2.m";
  c2_info[51].name = "meshgrid";
  c2_info[51].dominantType = "double";
  c2_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c2_info[51].fileTimeLo = 1294093142U;
  c2_info[51].fileTimeHi = 0U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c2_info[52].name = "repmat";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[52].fileTimeLo = 1297372434U;
  c2_info[52].fileTimeHi = 0U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[53].name = "eml_assert_valid_size_arg";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[53].fileTimeLo = 1286843894U;
  c2_info[53].fileTimeHi = 0U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c2_info[54].name = "isinf";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[54].fileTimeLo = 1286843960U;
  c2_info[54].fileTimeHi = 0U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c2_info[55].name = "mtimes";
  c2_info[55].dominantType = "double";
  c2_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[55].fileTimeLo = 1289544892U;
  c2_info[55].fileTimeHi = 0U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[56].name = "eml_index_class";
  c2_info[56].dominantType = "";
  c2_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[56].fileTimeLo = 1323195778U;
  c2_info[56].fileTimeHi = 0U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
  c2_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[57].name = "intmax";
  c2_info[57].dominantType = "char";
  c2_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[57].fileTimeLo = 1311280516U;
  c2_info[57].fileTimeHi = 0U;
  c2_info[57].mFileTimeLo = 0U;
  c2_info[57].mFileTimeHi = 0U;
  c2_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[58].name = "eml_index_class";
  c2_info[58].dominantType = "";
  c2_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[58].fileTimeLo = 1323195778U;
  c2_info[58].fileTimeHi = 0U;
  c2_info[58].mFileTimeLo = 0U;
  c2_info[58].mFileTimeHi = 0U;
  c2_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[59].name = "eml_index_minus";
  c2_info[59].dominantType = "coder.internal.indexInt";
  c2_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[59].fileTimeLo = 1286843978U;
  c2_info[59].fileTimeHi = 0U;
  c2_info[59].mFileTimeLo = 0U;
  c2_info[59].mFileTimeHi = 0U;
  c2_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[60].name = "eml_index_class";
  c2_info[60].dominantType = "";
  c2_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[60].fileTimeLo = 1323195778U;
  c2_info[60].fileTimeHi = 0U;
  c2_info[60].mFileTimeLo = 0U;
  c2_info[60].mFileTimeHi = 0U;
  c2_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[61].name = "eml_scalar_eg";
  c2_info[61].dominantType = "double";
  c2_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[61].fileTimeLo = 1286843996U;
  c2_info[61].fileTimeHi = 0U;
  c2_info[61].mFileTimeLo = 0U;
  c2_info[61].mFileTimeHi = 0U;
  c2_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[62].name = "eml_index_prod";
  c2_info[62].dominantType = "double";
  c2_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c2_info[62].fileTimeLo = 1286843980U;
  c2_info[62].fileTimeHi = 0U;
  c2_info[62].mFileTimeLo = 0U;
  c2_info[62].mFileTimeHi = 0U;
  c2_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c2_info[63].name = "eml_index_class";
  c2_info[63].dominantType = "";
  c2_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[63].fileTimeLo = 1323195778U;
  c2_info[63].fileTimeHi = 0U;
  c2_info[63].mFileTimeLo = 0U;
  c2_info[63].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_Joint_data_modelInstanceStruct *chartInstance)
{
}

static void c2_TRANS0_1(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_theta, real_T c2_T[16])
{
  uint32_T c2_debug_family_var_map[4];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  int32_T c2_i115;
  int32_T c2_i116;
  static real_T c2_dv22[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c2_i117;
  int32_T c2_i118;
  static real_T c2_dv23[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T *c2_sfEvent;
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_T, 3U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, 3);
  c2_x = c2_theta;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_theta;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_e_x = c2_theta;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_theta;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_T[0] = c2_b_x;
  c2_T[4] = -c2_d_x;
  c2_T[8] = 0.0;
  c2_T[12] = 0.0;
  c2_T[1] = c2_f_x;
  c2_T[5] = c2_h_x;
  c2_T[9] = 0.0;
  c2_T[13] = 0.0;
  c2_i115 = 0;
  for (c2_i116 = 0; c2_i116 < 4; c2_i116++) {
    c2_T[c2_i115 + 2] = c2_dv22[c2_i116];
    c2_i115 += 4;
  }

  c2_i117 = 0;
  for (c2_i118 = 0; c2_i118 < 4; c2_i118++) {
    c2_T[c2_i117 + 3] = c2_dv23[c2_i118];
    c2_i117 += 4;
  }

  _SFD_SCRIPT_CALL(0U, *c2_sfEvent, -3);
  sf_debug_symbol_scope_pop();
}

static void c2_TransformPoints(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, real_T c2_TM[16], real_T c2_Pv[15], real_T c2_P[15])
{
  uint32_T c2_debug_family_var_map[7];
  real_T c2_M;
  real_T c2_N;
  real_T c2_b_P[20];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i119;
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i125;
  real_T c2_a[16];
  int32_T c2_i126;
  real_T c2_b[20];
  int32_T c2_i127;
  int32_T c2_i128;
  int32_T c2_i129;
  real_T c2_C[20];
  int32_T c2_i130;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_i133;
  int32_T c2_i134;
  int32_T c2_i135;
  int32_T c2_i136;
  int32_T c2_i137;
  int32_T c2_i138;
  int32_T c2_i139;
  int32_T c2_i140;
  int32_T c2_i141;
  int32_T *c2_sfEvent;
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 7U, 8U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_M, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_N, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_b_P, MAX_uint32_T,
    c2_e_sf_marshallOut, c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_TM, 5U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Pv, 6U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P, MAX_uint32_T,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 3);
  c2_M = 3.0;
  c2_N = 5.0;
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 4);
  c2_i119 = 0;
  c2_i120 = 0;
  for (c2_i121 = 0; c2_i121 < 5; c2_i121++) {
    for (c2_i122 = 0; c2_i122 < 3; c2_i122++) {
      c2_b_P[c2_i122 + c2_i119] = c2_Pv[c2_i122 + c2_i120];
    }

    c2_i119 += 4;
    c2_i120 += 3;
  }

  c2_i123 = 0;
  for (c2_i124 = 0; c2_i124 < 5; c2_i124++) {
    c2_b_P[c2_i123 + 3] = 1.0;
    c2_i123 += 4;
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 5);
  for (c2_i125 = 0; c2_i125 < 16; c2_i125++) {
    c2_a[c2_i125] = c2_TM[c2_i125];
  }

  for (c2_i126 = 0; c2_i126 < 20; c2_i126++) {
    c2_b[c2_i126] = c2_b_P[c2_i126];
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  for (c2_i127 = 0; c2_i127 < 20; c2_i127++) {
    c2_b_P[c2_i127] = 0.0;
  }

  for (c2_i128 = 0; c2_i128 < 20; c2_i128++) {
    c2_b_P[c2_i128] = 0.0;
  }

  for (c2_i129 = 0; c2_i129 < 20; c2_i129++) {
    c2_C[c2_i129] = c2_b_P[c2_i129];
  }

  for (c2_i130 = 0; c2_i130 < 20; c2_i130++) {
    c2_b_P[c2_i130] = c2_C[c2_i130];
  }

  for (c2_i131 = 0; c2_i131 < 20; c2_i131++) {
    c2_C[c2_i131] = c2_b_P[c2_i131];
  }

  for (c2_i132 = 0; c2_i132 < 20; c2_i132++) {
    c2_b_P[c2_i132] = c2_C[c2_i132];
  }

  for (c2_i133 = 0; c2_i133 < 4; c2_i133++) {
    c2_i134 = 0;
    for (c2_i135 = 0; c2_i135 < 5; c2_i135++) {
      c2_b_P[c2_i134 + c2_i133] = 0.0;
      c2_i136 = 0;
      for (c2_i137 = 0; c2_i137 < 4; c2_i137++) {
        c2_b_P[c2_i134 + c2_i133] += c2_a[c2_i136 + c2_i133] * c2_b[c2_i137 +
          c2_i134];
        c2_i136 += 4;
      }

      c2_i134 += 4;
    }
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 6);
  c2_i138 = 0;
  c2_i139 = 0;
  for (c2_i140 = 0; c2_i140 < 5; c2_i140++) {
    for (c2_i141 = 0; c2_i141 < 3; c2_i141++) {
      c2_P[c2_i141 + c2_i138] = c2_b_P[c2_i141 + c2_i139];
    }

    c2_i138 += 3;
    c2_i139 += 4;
  }

  sf_debug_symbol_switch(2U, 7U);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, -6);
  sf_debug_symbol_scope_pop();
}

static void c2_b_eml_scalar_eg(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
}

static void c2_b_TransformPoints(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, real_T c2_TM[16], real_T c2_Pv[6], real_T c2_P[6])
{
  uint32_T c2_debug_family_var_map[7];
  real_T c2_M;
  real_T c2_N;
  real_T c2_b_P[8];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i142;
  int32_T c2_i143;
  int32_T c2_i144;
  int32_T c2_i145;
  int32_T c2_i146;
  int32_T c2_i147;
  int32_T c2_i148;
  real_T c2_a[16];
  int32_T c2_i149;
  real_T c2_b[8];
  int32_T c2_i150;
  int32_T c2_i151;
  int32_T c2_i152;
  real_T c2_C[8];
  int32_T c2_i153;
  int32_T c2_i154;
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_i157;
  int32_T c2_i158;
  int32_T c2_i159;
  int32_T c2_i160;
  int32_T c2_i161;
  int32_T c2_i162;
  int32_T c2_i163;
  int32_T c2_i164;
  int32_T *c2_sfEvent;
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 7U, 8U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_M, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_N, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_b_P, MAX_uint32_T,
    c2_f_sf_marshallOut, c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_TM, 5U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Pv, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_P, MAX_uint32_T,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 3);
  c2_M = 3.0;
  c2_N = 2.0;
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 4);
  c2_i142 = 0;
  c2_i143 = 0;
  for (c2_i144 = 0; c2_i144 < 2; c2_i144++) {
    for (c2_i145 = 0; c2_i145 < 3; c2_i145++) {
      c2_b_P[c2_i145 + c2_i142] = c2_Pv[c2_i145 + c2_i143];
    }

    c2_i142 += 4;
    c2_i143 += 3;
  }

  c2_i146 = 0;
  for (c2_i147 = 0; c2_i147 < 2; c2_i147++) {
    c2_b_P[c2_i146 + 3] = 1.0;
    c2_i146 += 4;
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 5);
  for (c2_i148 = 0; c2_i148 < 16; c2_i148++) {
    c2_a[c2_i148] = c2_TM[c2_i148];
  }

  for (c2_i149 = 0; c2_i149 < 8; c2_i149++) {
    c2_b[c2_i149] = c2_b_P[c2_i149];
  }

  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i150 = 0; c2_i150 < 8; c2_i150++) {
    c2_b_P[c2_i150] = 0.0;
  }

  for (c2_i151 = 0; c2_i151 < 8; c2_i151++) {
    c2_b_P[c2_i151] = 0.0;
  }

  for (c2_i152 = 0; c2_i152 < 8; c2_i152++) {
    c2_C[c2_i152] = c2_b_P[c2_i152];
  }

  for (c2_i153 = 0; c2_i153 < 8; c2_i153++) {
    c2_b_P[c2_i153] = c2_C[c2_i153];
  }

  for (c2_i154 = 0; c2_i154 < 8; c2_i154++) {
    c2_C[c2_i154] = c2_b_P[c2_i154];
  }

  for (c2_i155 = 0; c2_i155 < 8; c2_i155++) {
    c2_b_P[c2_i155] = c2_C[c2_i155];
  }

  for (c2_i156 = 0; c2_i156 < 4; c2_i156++) {
    c2_i157 = 0;
    for (c2_i158 = 0; c2_i158 < 2; c2_i158++) {
      c2_b_P[c2_i157 + c2_i156] = 0.0;
      c2_i159 = 0;
      for (c2_i160 = 0; c2_i160 < 4; c2_i160++) {
        c2_b_P[c2_i157 + c2_i156] += c2_a[c2_i159 + c2_i156] * c2_b[c2_i160 +
          c2_i157];
        c2_i159 += 4;
      }

      c2_i157 += 4;
    }
  }

  sf_debug_symbol_switch(2U, 2U);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, 6);
  c2_i161 = 0;
  c2_i162 = 0;
  for (c2_i163 = 0; c2_i163 < 2; c2_i163++) {
    for (c2_i164 = 0; c2_i164 < 3; c2_i164++) {
      c2_P[c2_i164 + c2_i161] = c2_b_P[c2_i164 + c2_i162];
    }

    c2_i161 += 3;
    c2_i162 += 4;
  }

  sf_debug_symbol_switch(2U, 7U);
  _SFD_SCRIPT_CALL(1U, *c2_sfEvent, -6);
  sf_debug_symbol_scope_pop();
}

static void c2_c_eml_scalar_eg(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
}

static void c2_WorkEnvelope2(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_Rho, real_T c2_phi_max)
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_Phi[100];
  real_T c2_Theta[100];
  static real_T c2_X[10000];
  static real_T c2_Y[10000];
  static real_T c2_Z[10000];
  static real_T c2_b_Phi[10000];
  static real_T c2_b_Theta[10000];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 0.0;
  real_T c2_dv24[100];
  int32_T c2_i165;
  int32_T c2_i166;
  int32_T c2_i167;
  real_T c2_c_Phi[100];
  int32_T c2_i168;
  real_T c2_dv25[100];
  static real_T c2_c_Theta[10000];
  static real_T c2_d_Phi[10000];
  int32_T c2_i169;
  int32_T c2_i170;
  int32_T c2_i171;
  static real_T c2_d_Theta[10000];
  int32_T c2_i172;
  static real_T c2_e_Phi[10000];
  static real_T c2_b_Z[10000];
  int32_T c2_i173;
  int32_T c2_i174;
  int32_T c2_i175;
  int32_T c2_i176;
  static real_T c2_u[10000];
  const mxArray *c2_y = NULL;
  int32_T c2_i177;
  static real_T c2_b_u[10000];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i178;
  real_T c2_c_u[10000];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i179;
  static char_T c2_cv8[9] = { 'E', 'd', 'g', 'e', 'C', 'o', 'l', 'o', 'r' };

  char_T c2_d_u[9];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i180;
  static char_T c2_cv9[4] = { 'n', 'o', 'n', 'e' };

  char_T c2_e_u[4];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i181;
  static char_T c2_cv10[3] = { '0', '.', '5' };

  char_T c2_f_u[3];
  const mxArray *c2_f_y = NULL;
  int32_T *c2_sfEvent;
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 9U, 11U, c2_f_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_Phi, MAX_uint32_T,
    c2_h_sf_marshallOut, c2_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_Theta, MAX_uint32_T, c2_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_X, 2U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Y, 3U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Z, 4U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_b_Phi, MAX_uint32_T,
    c2_g_sf_marshallOut, c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_b_Theta, MAX_uint32_T,
    c2_g_sf_marshallOut, c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Rho, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_phi_max, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, *c2_sfEvent, 4);
  c2_linspace(chartInstance, -c2_phi_max, c2_phi_max, c2_dv24);
  for (c2_i165 = 0; c2_i165 < 100; c2_i165++) {
    c2_Phi[c2_i165] = c2_dv24[c2_i165];
  }

  sf_debug_symbol_switch(0U, 0U);
  _SFD_SCRIPT_CALL(3U, *c2_sfEvent, 5);
  for (c2_i166 = 0; c2_i166 < 100; c2_i166++) {
    c2_Theta[c2_i166] = 0.063466518254339258 * (real_T)c2_i166;
  }

  sf_debug_symbol_switch(1U, 1U);
  _SFD_SCRIPT_CALL(3U, *c2_sfEvent, 6);
  for (c2_i167 = 0; c2_i167 < 100; c2_i167++) {
    c2_c_Phi[c2_i167] = c2_Phi[c2_i167];
  }

  for (c2_i168 = 0; c2_i168 < 100; c2_i168++) {
    c2_dv25[c2_i168] = 0.063466518254339258 * (real_T)c2_i168;
  }

  c2_meshgrid(chartInstance, c2_c_Phi, c2_dv25, c2_d_Phi, c2_c_Theta);
  for (c2_i169 = 0; c2_i169 < 10000; c2_i169++) {
    c2_b_Phi[c2_i169] = c2_d_Phi[c2_i169];
  }

  sf_debug_symbol_switch(0U, 5U);
  for (c2_i170 = 0; c2_i170 < 10000; c2_i170++) {
    c2_b_Theta[c2_i170] = c2_c_Theta[c2_i170];
  }

  sf_debug_symbol_switch(1U, 6U);
  _SFD_SCRIPT_CALL(3U, *c2_sfEvent, 7);
  for (c2_i171 = 0; c2_i171 < 10000; c2_i171++) {
    c2_d_Theta[c2_i171] = c2_b_Theta[c2_i171];
  }

  for (c2_i172 = 0; c2_i172 < 10000; c2_i172++) {
    c2_e_Phi[c2_i172] = c2_b_Phi[c2_i172];
  }

  c2_sph2cart(chartInstance, c2_d_Theta, c2_e_Phi, c2_Rho, c2_d_Phi, c2_c_Theta,
              c2_b_Z);
  for (c2_i173 = 0; c2_i173 < 10000; c2_i173++) {
    c2_X[c2_i173] = c2_d_Phi[c2_i173];
  }

  for (c2_i174 = 0; c2_i174 < 10000; c2_i174++) {
    c2_Y[c2_i174] = c2_c_Theta[c2_i174];
  }

  for (c2_i175 = 0; c2_i175 < 10000; c2_i175++) {
    c2_Z[c2_i175] = c2_b_Z[c2_i175];
  }

  _SFD_SCRIPT_CALL(3U, *c2_sfEvent, 11);
  for (c2_i176 = 0; c2_i176 < 10000; c2_i176++) {
    c2_u[c2_i176] = c2_X[c2_i176];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c2_i177 = 0; c2_i177 < 10000; c2_i177++) {
    c2_b_u[c2_i177] = c2_Y[c2_i177];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c2_i178 = 0; c2_i178 < 10000; c2_i178++) {
    c2_c_u[c2_i178] = c2_Z[c2_i178];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 100, 100),
                FALSE);
  for (c2_i179 = 0; c2_i179 < 9; c2_i179++) {
    c2_d_u[c2_i179] = c2_cv8[c2_i179];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 9),
                FALSE);
  for (c2_i180 = 0; c2_i180 < 4; c2_i180++) {
    c2_e_u[c2_i180] = c2_cv9[c2_i180];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("surf", 0U, 5U, 14, c2_y, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y,
                    14, c2_e_y);
  _SFD_SCRIPT_CALL(3U, *c2_sfEvent, 12);
  for (c2_i181 = 0; c2_i181 < 3; c2_i181++) {
    c2_f_u[c2_i181] = c2_cv10[c2_i181];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_f_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_call_debug("alpha", 0U, 1U, 14, c2_f_y);
  _SFD_SCRIPT_CALL(3U, *c2_sfEvent, -12);
  sf_debug_symbol_scope_pop();
}

static void c2_linspace(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_d1, real_T c2_d2, real_T c2_y[100])
{
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_delta1;
  real_T c2_b_A;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_delta2;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c_y;
  real_T c2_c_A;
  real_T c2_e_x;
  real_T c2_f_x;
  int32_T c2_c_k;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_d_y;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c2_eml_scalar_eg(chartInstance);
  c2_y[99] = c2_d2;
  c2_y[0] = c2_d1;
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (c2_d1 < 0.0 != c2_d2 < 0.0) {
    if (muDoubleScalarAbs(c2_d1) > 8.9884656743115785E+307) {
      guard2 = TRUE;
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    if (muDoubleScalarAbs(c2_d2) > 8.9884656743115785E+307) {
      guard2 = TRUE;
    } else if (muDoubleScalarAbs(0.0) > 8.9884656743115785E+307) {
      guard1 = TRUE;
    } else {
      c2_c_A = c2_d2 - c2_d1;
      c2_e_x = c2_c_A;
      c2_f_x = c2_e_x;
      c2_delta1 = c2_f_x / 99.0;
      for (c2_c_k = 0; c2_c_k < 98; c2_c_k++) {
        c2_b_k = 1.0 + (real_T)c2_c_k;
        c2_c_a = c2_b_k;
        c2_c_b = c2_delta1;
        c2_d_y = c2_c_a * c2_c_b;
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c2_b_k + 1.0), 1, 100, 1, 0) - 1] = c2_d1 + c2_d_y;
      }
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c2_A = c2_d1;
    c2_x = c2_A;
    c2_b_x = c2_x;
    c2_delta1 = c2_b_x / 99.0;
    c2_b_A = c2_d2;
    c2_c_x = c2_b_A;
    c2_d_x = c2_c_x;
    c2_delta2 = c2_d_x / 99.0;
    for (c2_k = 0; c2_k < 98; c2_k++) {
      c2_b_k = 1.0 + (real_T)c2_k;
      c2_a = c2_delta2;
      c2_b = c2_b_k;
      c2_b_y = c2_a * c2_b;
      c2_b_a = c2_delta1;
      c2_b_b = c2_b_k;
      c2_c_y = c2_b_a * c2_b_b;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_k + 1.0), 1, 100, 1, 0) - 1] = (c2_d1 + c2_b_y) - c2_c_y;
    }
  }
}

static void c2_meshgrid(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_x[100], real_T c2_y[100], real_T c2_xx[10000], real_T c2_yy[10000])
{
  int32_T c2_i182;
  real_T c2_a[100];
  int32_T c2_ia;
  int32_T c2_ib;
  int32_T c2_iacol;
  int32_T c2_jcol;
  int32_T c2_itilerow;
  int32_T c2_b_a;
  int32_T c2_c_a;
  int32_T c2_i183;
  real_T c2_d_a[100];
  int32_T c2_b_ib;
  int32_T c2_jtilecol;
  int32_T c2_b_ia;
  int32_T c2_k;
  int32_T c2_e_a;
  int32_T c2_f_a;
  for (c2_i182 = 0; c2_i182 < 100; c2_i182++) {
    c2_a[c2_i182] = c2_x[c2_i182];
  }

  c2_ia = 0;
  c2_ib = 1;
  c2_iacol = 1;
  c2_check_forloop_overflow_error(chartInstance);
  for (c2_jcol = 1; c2_jcol < 101; c2_jcol++) {
    c2_check_forloop_overflow_error(chartInstance);
    for (c2_itilerow = 1; c2_itilerow < 101; c2_itilerow++) {
      c2_ia = c2_iacol;
      c2_xx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_ib), 1, 10000, 1, 0) - 1] = c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ia), 1, 100, 1, 0) - 1];
      c2_b_a = c2_ia;
      c2_ia = c2_b_a;
      c2_c_a = c2_ib + 1;
      c2_ib = c2_c_a;
    }

    c2_iacol = c2_ia + 1;
  }

  for (c2_i183 = 0; c2_i183 < 100; c2_i183++) {
    c2_d_a[c2_i183] = c2_y[c2_i183];
  }

  c2_b_ib = 1;
  c2_check_forloop_overflow_error(chartInstance);
  for (c2_jtilecol = 1; c2_jtilecol < 101; c2_jtilecol++) {
    c2_b_ia = 1;
    c2_check_forloop_overflow_error(chartInstance);
    for (c2_k = 1; c2_k < 101; c2_k++) {
      c2_yy[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_ib), 1, 10000, 1, 0) - 1] =
        c2_d_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_ia), 1, 100, 1, 0) - 1];
      c2_e_a = c2_b_ia + 1;
      c2_b_ia = c2_e_a;
      c2_f_a = c2_b_ib + 1;
      c2_b_ib = c2_f_a;
    }
  }
}

static void c2_check_forloop_overflow_error(SFc2_Joint_data_modelInstanceStruct *
  chartInstance)
{
}

static void c2_sph2cart(SFc2_Joint_data_modelInstanceStruct *chartInstance,
  real_T c2_az[10000], real_T c2_elev[10000], real_T c2_r, real_T c2_x[10000],
  real_T c2_y[10000], real_T c2_z[10000])
{
  int32_T c2_i184;
  int32_T c2_i185;
  int32_T c2_i186;
  int32_T c2_i187;
  int32_T c2_i188;
  int32_T c2_i189;
  int32_T c2_i190;
  real_T c2_dv26[10000];
  int32_T c2_i191;
  for (c2_i184 = 0; c2_i184 < 10000; c2_i184++) {
    c2_z[c2_i184] = c2_elev[c2_i184];
  }

  c2_b_sin(chartInstance, c2_z);
  for (c2_i185 = 0; c2_i185 < 10000; c2_i185++) {
    c2_z[c2_i185] *= c2_r;
  }

  for (c2_i186 = 0; c2_i186 < 10000; c2_i186++) {
    c2_y[c2_i186] = c2_elev[c2_i186];
  }

  c2_b_cos(chartInstance, c2_y);
  for (c2_i187 = 0; c2_i187 < 10000; c2_i187++) {
    c2_y[c2_i187] *= c2_r;
  }

  for (c2_i188 = 0; c2_i188 < 10000; c2_i188++) {
    c2_x[c2_i188] = c2_az[c2_i188];
  }

  c2_b_cos(chartInstance, c2_x);
  for (c2_i189 = 0; c2_i189 < 10000; c2_i189++) {
    c2_x[c2_i189] *= c2_y[c2_i189];
  }

  for (c2_i190 = 0; c2_i190 < 10000; c2_i190++) {
    c2_dv26[c2_i190] = c2_az[c2_i190];
  }

  c2_b_sin(chartInstance, c2_dv26);
  for (c2_i191 = 0; c2_i191 < 10000; c2_i191++) {
    c2_y[c2_i191] *= c2_dv26[c2_i191];
  }
}

static void c2_sin(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                   c2_x[10000], real_T c2_b_x[10000])
{
  int32_T c2_i192;
  for (c2_i192 = 0; c2_i192 < 10000; c2_i192++) {
    c2_b_x[c2_i192] = c2_x[c2_i192];
  }

  c2_b_sin(chartInstance, c2_b_x);
}

static void c2_cos(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                   c2_x[10000], real_T c2_b_x[10000])
{
  int32_T c2_i193;
  for (c2_i193 = 0; c2_i193 < 10000; c2_i193++) {
    c2_b_x[c2_i193] = c2_x[c2_i193];
  }

  c2_b_cos(chartInstance, c2_b_x);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i194;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i194, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i194;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_Joint_data_model, const char_T *
  c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_is_active_c2_Joint_data_model), &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_Joint_data_model);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_Joint_data_modelInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sin(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                     c2_x[10000])
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  for (c2_k = 0; c2_k < 10000; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_k), 1, 10000, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_c_x = muDoubleScalarSin(c2_c_x);
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_k),
      1, 10000, 1, 0) - 1] = c2_c_x;
  }
}

static void c2_b_cos(SFc2_Joint_data_modelInstanceStruct *chartInstance, real_T
                     c2_x[10000])
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  for (c2_k = 0; c2_k < 10000; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_k), 1, 10000, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_c_x = muDoubleScalarCos(c2_c_x);
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_k),
      1, 10000, 1, 0) - 1] = c2_c_x;
  }
}

static void init_dsm_address_info(SFc2_Joint_data_modelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_Joint_data_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2154171796U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1772470316U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3562236645U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3060809406U);
}

mxArray *sf_c2_Joint_data_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KBipud2oAl54yhsCvSW4YG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c2_Joint_data_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c2_Joint_data_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Joint_data_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Joint_data_modelInstanceStruct *chartInstance;
    chartInstance = (SFc2_Joint_data_modelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Joint_data_modelMachineNumber_,
           2,
           1,
           1,
           2,
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
          init_script_number_translation(_Joint_data_modelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Joint_data_modelMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Joint_data_modelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"theta1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"theta2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1067);
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

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_theta1;
          real_T *c2_theta2;
          c2_theta2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_theta1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_theta1);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_theta2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Joint_data_modelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "CLe7VuqXo7aCKXhuo1imyE";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Joint_data_model_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 2, "dworkChecksum");
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

static void sf_opaque_initialize_c2_Joint_data_model(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar);
  initialize_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_Joint_data_model(void *chartInstanceVar)
{
  enable_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_Joint_data_model(void *chartInstanceVar)
{
  disable_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_Joint_data_model(void *chartInstanceVar)
{
  sf_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_Joint_data_model(void *chartInstanceVar)
{
  ext_mode_exec_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Joint_data_model(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Joint_data_model
    ((SFc2_Joint_data_modelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Joint_data_model();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Joint_data_model(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Joint_data_model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Joint_data_model(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Joint_data_model(S);
}

static void sf_opaque_set_sim_state_c2_Joint_data_model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_Joint_data_model(S, st);
}

static void sf_opaque_terminate_c2_Joint_data_model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Joint_data_modelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Joint_data_model_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Joint_data_model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Joint_data_model((SFc2_Joint_data_modelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_Joint_data_model_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_Joint_data_model\",T\"is_active_c2_Joint_data_model\"}}"
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

static void mdlSetWorkWidths_c2_Joint_data_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Joint_data_model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2309148782U));
  ssSetChecksum1(S,(270292225U));
  ssSetChecksum2(S,(2129633369U));
  ssSetChecksum3(S,(3201526848U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Joint_data_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Joint_data_model(SimStruct *S)
{
  SFc2_Joint_data_modelInstanceStruct *chartInstance;
  chartInstance = (SFc2_Joint_data_modelInstanceStruct *)malloc(sizeof
    (SFc2_Joint_data_modelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Joint_data_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Joint_data_model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Joint_data_model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Joint_data_model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Joint_data_model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Joint_data_model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Joint_data_model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Joint_data_model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Joint_data_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Joint_data_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Joint_data_model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Joint_data_model;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_Joint_data_model;
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

void c2_Joint_data_model_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Joint_data_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Joint_data_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Joint_data_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Joint_data_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
