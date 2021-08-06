/* Include files */

#include "blascompat32.h"
#include "Dynamics_Simon_sfun.h"
#include "c1_Dynamics_Simon.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Dynamics_Simon_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[27] = { "V1", "q1", "q1d", "q2", "q2d",
  "q1d2", "q2d2", "g", "theta1", "theta2", "theta3", "theta4", "theta5",
  "theta6", "Q", "Qd", "Qd2", "V", "M", "C", "G", "F", "nargin", "nargout", "u",
  "X", "Xd" };

/* Function Declarations */
static void initialize_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static void initialize_params_c1_Dynamics_Simon
  (SFc1_Dynamics_SimonInstanceStruct *chartInstance);
static void enable_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static void disable_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_Dynamics_Simon
  (SFc1_Dynamics_SimonInstanceStruct *chartInstance);
static void ext_mode_exec_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_Dynamics_Simon
  (SFc1_Dynamics_SimonInstanceStruct *chartInstance);
static void set_sim_state_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static void sf_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static void initSimStructsc1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct *chartInstance,
  const mxArray *c1_Xd, const char_T *c1_identifier, real_T c1_y[4]);
static void c1_b_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[41]);
static real_T c1_mpower(SFc1_Dynamics_SimonInstanceStruct *chartInstance, real_T
  c1_a);
static void c1_inv(SFc1_Dynamics_SimonInstanceStruct *chartInstance, real_T
                   c1_x[4], real_T c1_y[4]);
static real_T c1_norm(SFc1_Dynamics_SimonInstanceStruct *chartInstance, real_T
                      c1_x[4]);
static void c1_eml_warning(SFc1_Dynamics_SimonInstanceStruct *chartInstance);
static void c1_b_eml_warning(SFc1_Dynamics_SimonInstanceStruct *chartInstance,
  char_T c1_varargin_2[14]);
static void c1_eml_scalar_eg(SFc1_Dynamics_SimonInstanceStruct *chartInstance);
static void c1_f_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14]);
static void c1_g_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14]);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_h_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_i_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_Dynamics_Simon, const char_T
  *c1_identifier);
static uint8_T c1_j_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_Dynamics_Simon;
  c1_is_active_c1_Dynamics_Simon = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_Dynamics_Simon = 0U;
}

static void initialize_params_c1_Dynamics_Simon
  (SFc1_Dynamics_SimonInstanceStruct *chartInstance)
{
}

static void enable_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Dynamics_Simon
  (SFc1_Dynamics_SimonInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
  c1_update_debugger_state_c1_Dynamics_Simon(chartInstance);
}

static const mxArray *get_sim_state_c1_Dynamics_Simon
  (SFc1_Dynamics_SimonInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[4];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T *c1_is_active_c1_Dynamics_Simon;
  real_T (*c1_Xd)[4];
  c1_Xd = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_Dynamics_Simon = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_u[c1_i0] = (*c1_Xd)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = *c1_is_active_c1_Dynamics_Simon;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[4];
  int32_T c1_i1;
  boolean_T *c1_doneDoubleBufferReInit;
  uint8_T *c1_is_active_c1_Dynamics_Simon;
  real_T (*c1_Xd)[4];
  c1_Xd = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_Dynamics_Simon = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "Xd",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    (*c1_Xd)[c1_i1] = c1_dv0[c1_i1];
  }

  *c1_is_active_c1_Dynamics_Simon = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "is_active_c1_Dynamics_Simon");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Dynamics_Simon(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
}

static void sf_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T *c1_sfEvent;
  real_T *c1_u;
  real_T (*c1_X)[4];
  real_T (*c1_Xd)[4];
  c1_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c1_Xd = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_u, 0U);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_Xd)[c1_i2], 1U);
  }

  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_X)[c1_i3], 2U);
  }

  *c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_Dynamics_Simon(chartInstance);
  sf_debug_check_for_state_inconsistency(_Dynamics_SimonMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_u;
  int32_T c1_i4;
  real_T c1_X[4];
  uint32_T c1_debug_family_var_map[27];
  real_T c1_V1;
  real_T c1_q1;
  real_T c1_q1d;
  real_T c1_q2;
  real_T c1_q2d;
  real_T c1_q1d2;
  real_T c1_q2d2;
  real_T c1_g;
  real_T c1_theta1;
  real_T c1_theta2;
  real_T c1_theta3;
  real_T c1_theta4;
  real_T c1_theta5;
  real_T c1_theta6;
  real_T c1_Q[2];
  real_T c1_Qd[2];
  real_T c1_Qd2[2];
  real_T c1_V[2];
  real_T c1_M[4];
  real_T c1_C[4];
  real_T c1_G[2];
  real_T c1_F[2];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_Xd[4];
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_b;
  real_T c1_y;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_a;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_b_a;
  real_T c1_f_b;
  real_T c1_f_y;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_g_b;
  real_T c1_g_y;
  real_T c1_c_a;
  real_T c1_h_b;
  real_T c1_h_y;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_i_b;
  real_T c1_i_y;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_d_a;
  real_T c1_j_b;
  real_T c1_j_y;
  real_T c1_e_a;
  real_T c1_k_b;
  real_T c1_k_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_l_b;
  real_T c1_l_y;
  real_T c1_m_b;
  real_T c1_m_y;
  real_T c1_n_b;
  real_T c1_n_y;
  int32_T c1_i5;
  real_T c1_f_a[4];
  int32_T c1_i6;
  real_T c1_o_b[2];
  int32_T c1_i7;
  real_T c1_o_y[2];
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  real_T c1_b_M[4];
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  real_T *c1_b_u;
  real_T (*c1_b_Xd)[4];
  real_T (*c1_b_X)[4];
  int32_T *c1_sfEvent;
  c1_b_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_Xd = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  c1_hoistedGlobal = *c1_b_u;
  c1_u = c1_hoistedGlobal;
  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    c1_X[c1_i4] = (*c1_b_X)[c1_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 27U, 27U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_V1, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_q1, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_q1d, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_q2, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_q2d, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_q1d2, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_q2d2, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_g, 7U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta1, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_theta2, 9U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_theta3, 10U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_theta4, 11U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_theta5, 12U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_theta6, 13U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_Q, 14U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Qd, 15U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Qd2, 16U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_V, 17U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_M, 18U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_C, 19U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_G, 20U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_F, 21U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 22U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 23U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_u, 24U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_X, 25U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_Xd, 26U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c1_sfEvent, 36);
  c1_V1 = c1_u;
  _SFD_EML_CALL(0U, *c1_sfEvent, 38);
  c1_q1 = c1_X[0];
  _SFD_EML_CALL(0U, *c1_sfEvent, 39);
  c1_q1d = c1_X[1];
  _SFD_EML_CALL(0U, *c1_sfEvent, 40);
  c1_q2 = c1_X[2];
  _SFD_EML_CALL(0U, *c1_sfEvent, 41);
  c1_q2d = c1_X[3];
  _SFD_EML_CALL(0U, *c1_sfEvent, 43);
  c1_q1d2 = 0.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 44);
  c1_q2d2 = 0.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 57);
  c1_g = 9.81;
  _SFD_EML_CALL(0U, *c1_sfEvent, 66);
  c1_theta1 = 0.0304;
  _SFD_EML_CALL(0U, *c1_sfEvent, 67);
  c1_theta2 = 0.0184;
  _SFD_EML_CALL(0U, *c1_sfEvent, 68);
  c1_theta3 = 0.0184;
  _SFD_EML_CALL(0U, *c1_sfEvent, 69);
  c1_theta4 = 0.0921;
  _SFD_EML_CALL(0U, *c1_sfEvent, 70);
  c1_theta5 = 0.6101;
  _SFD_EML_CALL(0U, *c1_sfEvent, 71);
  c1_theta6 = 0.0097;
  _SFD_EML_CALL(0U, *c1_sfEvent, 74);
  c1_Q[0] = c1_q1;
  c1_Q[1] = c1_q2;
  _SFD_EML_CALL(0U, *c1_sfEvent, 75);
  c1_Qd[0] = c1_q1d;
  c1_Qd[1] = c1_q2d;
  _SFD_EML_CALL(0U, *c1_sfEvent, 76);
  c1_Qd2[0] = c1_q1d2;
  c1_Qd2[1] = c1_q2d2;
  _SFD_EML_CALL(0U, *c1_sfEvent, 78);
  c1_V[0] = c1_V1;
  c1_V[1] = 0.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 79);
  c1_x = c1_q2;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarSin(c1_b_x);
  c1_b = c1_mpower(chartInstance, c1_b_x);
  c1_y = 0.0184 * c1_b;
  c1_c_x = c1_q2;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_b_b = c1_d_x;
  c1_b_y = 0.0184 * c1_b_b;
  c1_e_x = c1_q2;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarCos(c1_f_x);
  c1_c_b = c1_f_x;
  c1_c_y = 0.0184 * c1_c_b;
  c1_M[0] = c1_theta1 + c1_y;
  c1_M[2] = c1_b_y;
  c1_M[1] = c1_c_y;
  c1_M[3] = c1_theta2;
  _SFD_EML_CALL(0U, *c1_sfEvent, 82);
  c1_g_x = c1_q2;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_d_b = c1_h_x;
  c1_d_y = 0.0368 * c1_d_b;
  c1_i_x = c1_q2;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarCos(c1_j_x);
  c1_a = c1_d_y;
  c1_e_b = c1_j_x;
  c1_e_y = c1_a * c1_e_b;
  c1_b_a = c1_e_y;
  c1_f_b = c1_q2d;
  c1_f_y = c1_b_a * c1_f_b;
  c1_k_x = c1_q2;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarSin(c1_l_x);
  c1_g_b = c1_l_x;
  c1_g_y = -0.0184 * c1_g_b;
  c1_c_a = c1_g_y;
  c1_h_b = c1_q2d;
  c1_h_y = c1_c_a * c1_h_b;
  c1_m_x = c1_q2;
  c1_n_x = c1_m_x;
  c1_n_x = muDoubleScalarSin(c1_n_x);
  c1_i_b = c1_n_x;
  c1_i_y = -0.0184 * c1_i_b;
  c1_o_x = c1_q2;
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarCos(c1_p_x);
  c1_d_a = c1_i_y;
  c1_j_b = c1_p_x;
  c1_j_y = c1_d_a * c1_j_b;
  c1_e_a = c1_j_y;
  c1_k_b = c1_q1d;
  c1_k_y = c1_e_a * c1_k_b;
  c1_C[0] = c1_f_y;
  c1_C[2] = c1_h_y;
  c1_C[1] = c1_k_y;
  c1_C[3] = 0.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 85);
  c1_q_x = c1_q2;
  c1_r_x = c1_q_x;
  c1_r_x = muDoubleScalarSin(c1_r_x);
  c1_l_b = c1_r_x;
  c1_l_y = -0.90350100000000011 * c1_l_b;
  c1_G[0] = 0.0;
  c1_G[1] = c1_l_y;
  _SFD_EML_CALL(0U, *c1_sfEvent, 86);
  c1_m_b = c1_q1d;
  c1_m_y = 0.6101 * c1_m_b;
  c1_n_b = c1_q2d;
  c1_n_y = 0.0097 * c1_n_b;
  c1_F[0] = c1_m_y;
  c1_F[1] = c1_n_y;
  _SFD_EML_CALL(0U, *c1_sfEvent, 88);
  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_f_a[c1_i5] = c1_C[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    c1_o_b[c1_i6] = c1_Qd[c1_i6];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    c1_o_y[c1_i7] = 0.0;
    c1_i8 = 0;
    for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
      c1_o_y[c1_i7] += c1_f_a[c1_i8 + c1_i7] * c1_o_b[c1_i9];
      c1_i8 += 2;
    }
  }

  for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
    c1_b_M[c1_i10] = c1_M[c1_i10];
  }

  c1_inv(chartInstance, c1_b_M, c1_f_a);
  for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
    c1_o_y[c1_i11] = ((c1_V[c1_i11] - c1_o_y[c1_i11]) - c1_F[c1_i11]) -
      c1_G[c1_i11];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
    c1_Qd2[c1_i12] = 0.0;
  }

  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    c1_Qd2[c1_i13] = 0.0;
  }

  for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
    c1_o_b[c1_i14] = c1_Qd2[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
    c1_Qd2[c1_i15] = c1_o_b[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    c1_o_b[c1_i16] = c1_Qd2[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
    c1_Qd2[c1_i17] = c1_o_b[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
    c1_Qd2[c1_i18] = 0.0;
    c1_i19 = 0;
    for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
      c1_Qd2[c1_i18] += c1_f_a[c1_i19 + c1_i18] * c1_o_y[c1_i20];
      c1_i19 += 2;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 89);
  c1_q1d2 = c1_Qd2[0];
  _SFD_EML_CALL(0U, *c1_sfEvent, 90);
  c1_q2d2 = c1_Qd2[1];
  _SFD_EML_CALL(0U, *c1_sfEvent, 94);
  c1_Xd[0] = c1_q1d;
  c1_Xd[1] = c1_q1d2;
  c1_Xd[2] = c1_q2d;
  c1_Xd[3] = c1_q2d2;
  _SFD_EML_CALL(0U, *c1_sfEvent, -94);
  sf_debug_symbol_scope_pop();
  for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
    (*c1_b_Xd)[c1_i21] = c1_Xd[c1_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
}

static void initSimStructsc1_Dynamics_Simon(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i22;
  real_T c1_b_inData[4];
  int32_T c1_i23;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
    c1_b_inData[c1_i22] = (*(real_T (*)[4])c1_inData)[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
    c1_u[c1_i23] = c1_b_inData[c1_i23];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct *chartInstance,
  const mxArray *c1_Xd, const char_T *c1_identifier, real_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Xd), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Xd);
}

static void c1_b_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv1[4];
  int32_T c1_i24;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
    c1_y[c1_i24] = c1_dv1[c1_i24];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Xd;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i25;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_Xd = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Xd), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Xd);
  for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
    (*(real_T (*)[4])c1_outData)[c1_i25] = c1_y[c1_i25];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i26;
  real_T c1_b_inData[2];
  int32_T c1_i27;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_b_inData[c1_i26] = (*(real_T (*)[2])c1_inData)[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
    c1_u[c1_i27] = c1_b_inData[c1_i27];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv2[2];
  int32_T c1_i28;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
    c1_y[c1_i28] = c1_dv2[c1_i28];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_F;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i29;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_F = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_F), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_F);
  for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
    (*(real_T (*)[2])c1_outData)[c1_i29] = c1_y[c1_i29];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_b_inData[4];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
    for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
      c1_b_inData[c1_i32 + c1_i30] = (*(real_T (*)[4])c1_inData)[c1_i32 + c1_i30];
    }

    c1_i30 += 2;
  }

  c1_i33 = 0;
  for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
    for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
      c1_u[c1_i35 + c1_i33] = c1_b_inData[c1_i35 + c1_i33];
    }

    c1_i33 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv3[4];
  int32_T c1_i36;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c1_i36 = 0; c1_i36 < 4; c1_i36++) {
    c1_y[c1_i36] = c1_dv3[c1_i36];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_C;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_C = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_C), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_C);
  c1_i37 = 0;
  for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
    for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
      (*(real_T (*)[4])c1_outData)[c1_i39 + c1_i37] = c1_y[c1_i39 + c1_i37];
    }

    c1_i37 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Dynamics_Simon_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[41];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i40;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 41), FALSE);
  for (c1_i40 = 0; c1_i40 < 41; c1_i40++) {
    c1_r0 = &c1_info[c1_i40];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i40);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[41])
{
  c1_info[0].context = "";
  c1_info[0].name = "sin";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[0].fileTimeLo = 1286843950U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[1].name = "eml_scalar_sin";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[1].fileTimeLo = 1286843936U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "mpower";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[2].fileTimeLo = 1286844042U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[3].name = "power";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[3].fileTimeLo = 1336547296U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[4].name = "eml_scalar_eg";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[4].fileTimeLo = 1286843996U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[5].name = "eml_scalexp_alloc";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[5].fileTimeLo = 1330633634U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[6].name = "floor";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[6].fileTimeLo = 1286843942U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[7].name = "eml_scalar_floor";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[7].fileTimeLo = 1286843926U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "";
  c1_info[8].name = "mtimes";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].fileTimeLo = 1289544892U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "cos";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[9].fileTimeLo = 1286843906U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[10].name = "eml_scalar_cos";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[10].fileTimeLo = 1286843922U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "";
  c1_info[11].name = "inv";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c1_info[11].fileTimeLo = 1305343200U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c1_info[12].name = "eml_xcabs1";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[12].fileTimeLo = 1286843906U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[13].name = "abs";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[13].fileTimeLo = 1286843894U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[14].name = "eml_scalar_abs";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[14].fileTimeLo = 1286843912U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c1_info[15].name = "mrdivide";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[15].fileTimeLo = 1342836144U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 1319755166U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[16].name = "rdivide";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[16].fileTimeLo = 1286844044U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[17].name = "eml_div";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[17].fileTimeLo = 1313373010U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c1_info[18].name = "mtimes";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[18].fileTimeLo = 1289544892U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[19].name = "norm";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[19].fileTimeLo = 1336547294U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[20].name = "abs";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[20].fileTimeLo = 1286843894U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[21].name = "isnan";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[21].fileTimeLo = 1286843960U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[22].name = "eml_guarded_nan";
  c1_info[22].dominantType = "char";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[22].fileTimeLo = 1286843976U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[23].name = "eml_is_float_class";
  c1_info[23].dominantType = "char";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[23].fileTimeLo = 1286843982U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[24].name = "mtimes";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[24].fileTimeLo = 1289544892U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[25].name = "eml_warning";
  c1_info[25].dominantType = "char";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[25].fileTimeLo = 1286844002U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[26].name = "isnan";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[26].fileTimeLo = 1286843960U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[27].name = "eps";
  c1_info[27].dominantType = "char";
  c1_info[27].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[27].fileTimeLo = 1326753196U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[28].name = "eml_is_float_class";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[28].fileTimeLo = 1286843982U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[29].name = "eml_eps";
  c1_info[29].dominantType = "char";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[29].fileTimeLo = 1326753196U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[30].name = "eml_float_model";
  c1_info[30].dominantType = "char";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[30].fileTimeLo = 1326753196U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[31].name = "eml_flt2str";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[31].fileTimeLo = 1309476396U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[32].name = "char";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c1_info[32].fileTimeLo = 1319755168U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[33].name = "eml_index_class";
  c1_info[33].dominantType = "";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[33].fileTimeLo = 1323195778U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[34].name = "eml_scalar_eg";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[34].fileTimeLo = 1286843996U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[35].name = "eml_xgemm";
  c1_info[35].dominantType = "char";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[35].fileTimeLo = 1299101972U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[36].name = "eml_blas_inline";
  c1_info[36].dominantType = "";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[36].fileTimeLo = 1299101968U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[37].name = "mtimes";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[37].fileTimeLo = 1289544892U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[38].name = "eml_index_class";
  c1_info[38].dominantType = "";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[38].fileTimeLo = 1323195778U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[39].name = "eml_scalar_eg";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[39].fileTimeLo = 1286843996U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[40].name = "eml_refblas_xgemm";
  c1_info[40].dominantType = "char";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[40].fileTimeLo = 1299101974U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
}

static real_T c1_mpower(SFc1_Dynamics_SimonInstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_ak = c1_c_a;
  return muDoubleScalarPower(c1_ak, 2.0);
}

static void c1_inv(SFc1_Dynamics_SimonInstanceStruct *chartInstance, real_T
                   c1_x[4], real_T c1_y[4])
{
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_y;
  real_T c1_d;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_d_y;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_e_y;
  real_T c1_b_d;
  real_T c1_A;
  real_T c1_B;
  real_T c1_l_x;
  real_T c1_f_y;
  real_T c1_m_x;
  real_T c1_g_y;
  real_T c1_r;
  real_T c1_a;
  real_T c1_b;
  real_T c1_h_y;
  real_T c1_b_B;
  real_T c1_i_y;
  real_T c1_j_y;
  real_T c1_t;
  real_T c1_b_A;
  real_T c1_c_B;
  real_T c1_n_x;
  real_T c1_k_y;
  real_T c1_o_x;
  real_T c1_l_y;
  real_T c1_m_y;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_n_y;
  real_T c1_c_A;
  real_T c1_d_B;
  real_T c1_p_x;
  real_T c1_o_y;
  real_T c1_q_x;
  real_T c1_p_y;
  real_T c1_q_y;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_r_y;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_s_y;
  real_T c1_d_A;
  real_T c1_e_B;
  real_T c1_r_x;
  real_T c1_t_y;
  real_T c1_s_x;
  real_T c1_u_y;
  real_T c1_e_a;
  real_T c1_e_b;
  real_T c1_v_y;
  real_T c1_f_B;
  real_T c1_w_y;
  real_T c1_x_y;
  real_T c1_e_A;
  real_T c1_g_B;
  real_T c1_t_x;
  real_T c1_y_y;
  real_T c1_u_x;
  real_T c1_ab_y;
  real_T c1_bb_y;
  real_T c1_f_a;
  real_T c1_f_b;
  real_T c1_cb_y;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_db_y;
  real_T c1_f_A;
  real_T c1_h_B;
  real_T c1_v_x;
  real_T c1_eb_y;
  real_T c1_w_x;
  real_T c1_fb_y;
  real_T c1_gb_y;
  real_T c1_h_a;
  real_T c1_h_b;
  real_T c1_hb_y;
  int32_T c1_i41;
  real_T c1_x_x[4];
  real_T c1_n1x;
  int32_T c1_i42;
  real_T c1_ib_y[4];
  real_T c1_n1xinv;
  real_T c1_i_a;
  real_T c1_i_b;
  real_T c1_jb_y;
  real_T c1_rc;
  real_T c1_y_x;
  boolean_T c1_j_b;
  real_T c1_ab_x;
  int32_T c1_i43;
  static char_T c1_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c1_u[8];
  const mxArray *c1_kb_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_lb_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_mb_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_nb_y = NULL;
  char_T c1_str[14];
  int32_T c1_i44;
  char_T c1_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_b_x = c1_x[1];
  c1_c_x = c1_b_x;
  c1_d_x = c1_c_x;
  c1_b_y = muDoubleScalarAbs(c1_d_x);
  c1_e_x = 0.0;
  c1_f_x = c1_e_x;
  c1_c_y = muDoubleScalarAbs(c1_f_x);
  c1_d = c1_b_y + c1_c_y;
  c1_g_x = c1_x[0];
  c1_h_x = c1_g_x;
  c1_i_x = c1_h_x;
  c1_d_y = muDoubleScalarAbs(c1_i_x);
  c1_j_x = 0.0;
  c1_k_x = c1_j_x;
  c1_e_y = muDoubleScalarAbs(c1_k_x);
  c1_b_d = c1_d_y + c1_e_y;
  if (c1_d > c1_b_d) {
    c1_A = c1_x[0];
    c1_B = c1_x[1];
    c1_l_x = c1_A;
    c1_f_y = c1_B;
    c1_m_x = c1_l_x;
    c1_g_y = c1_f_y;
    c1_r = c1_m_x / c1_g_y;
    c1_a = c1_r;
    c1_b = c1_x[3];
    c1_h_y = c1_a * c1_b;
    c1_b_B = c1_h_y - c1_x[2];
    c1_i_y = c1_b_B;
    c1_j_y = c1_i_y;
    c1_t = 1.0 / c1_j_y;
    c1_b_A = c1_x[3];
    c1_c_B = c1_x[1];
    c1_n_x = c1_b_A;
    c1_k_y = c1_c_B;
    c1_o_x = c1_n_x;
    c1_l_y = c1_k_y;
    c1_m_y = c1_o_x / c1_l_y;
    c1_b_a = c1_m_y;
    c1_b_b = c1_t;
    c1_n_y = c1_b_a * c1_b_b;
    c1_y[0] = c1_n_y;
    c1_y[1] = -c1_t;
    c1_c_A = -c1_x[2];
    c1_d_B = c1_x[1];
    c1_p_x = c1_c_A;
    c1_o_y = c1_d_B;
    c1_q_x = c1_p_x;
    c1_p_y = c1_o_y;
    c1_q_y = c1_q_x / c1_p_y;
    c1_c_a = c1_q_y;
    c1_c_b = c1_t;
    c1_r_y = c1_c_a * c1_c_b;
    c1_y[2] = c1_r_y;
    c1_d_a = c1_r;
    c1_d_b = c1_t;
    c1_s_y = c1_d_a * c1_d_b;
    c1_y[3] = c1_s_y;
  } else {
    c1_d_A = c1_x[1];
    c1_e_B = c1_x[0];
    c1_r_x = c1_d_A;
    c1_t_y = c1_e_B;
    c1_s_x = c1_r_x;
    c1_u_y = c1_t_y;
    c1_r = c1_s_x / c1_u_y;
    c1_e_a = c1_r;
    c1_e_b = c1_x[2];
    c1_v_y = c1_e_a * c1_e_b;
    c1_f_B = c1_x[3] - c1_v_y;
    c1_w_y = c1_f_B;
    c1_x_y = c1_w_y;
    c1_t = 1.0 / c1_x_y;
    c1_e_A = c1_x[3];
    c1_g_B = c1_x[0];
    c1_t_x = c1_e_A;
    c1_y_y = c1_g_B;
    c1_u_x = c1_t_x;
    c1_ab_y = c1_y_y;
    c1_bb_y = c1_u_x / c1_ab_y;
    c1_f_a = c1_bb_y;
    c1_f_b = c1_t;
    c1_cb_y = c1_f_a * c1_f_b;
    c1_y[0] = c1_cb_y;
    c1_g_a = -c1_r;
    c1_g_b = c1_t;
    c1_db_y = c1_g_a * c1_g_b;
    c1_y[1] = c1_db_y;
    c1_f_A = -c1_x[2];
    c1_h_B = c1_x[0];
    c1_v_x = c1_f_A;
    c1_eb_y = c1_h_B;
    c1_w_x = c1_v_x;
    c1_fb_y = c1_eb_y;
    c1_gb_y = c1_w_x / c1_fb_y;
    c1_h_a = c1_gb_y;
    c1_h_b = c1_t;
    c1_hb_y = c1_h_a * c1_h_b;
    c1_y[2] = c1_hb_y;
    c1_y[3] = c1_t;
  }

  for (c1_i41 = 0; c1_i41 < 4; c1_i41++) {
    c1_x_x[c1_i41] = c1_x[c1_i41];
  }

  c1_n1x = c1_norm(chartInstance, c1_x_x);
  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    c1_ib_y[c1_i42] = c1_y[c1_i42];
  }

  c1_n1xinv = c1_norm(chartInstance, c1_ib_y);
  c1_i_a = c1_n1x;
  c1_i_b = c1_n1xinv;
  c1_jb_y = c1_i_a * c1_i_b;
  c1_rc = 1.0 / c1_jb_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c1_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c1_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c1_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c1_y_x = c1_rc;
    c1_j_b = muDoubleScalarIsNaN(c1_y_x);
    guard3 = FALSE;
    if (c1_j_b) {
      guard3 = TRUE;
    } else {
      if (c1_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c1_ab_x = c1_rc;
      for (c1_i43 = 0; c1_i43 < 8; c1_i43++) {
        c1_u[c1_i43] = c1_cv0[c1_i43];
      }

      c1_kb_y = NULL;
      sf_mex_assign(&c1_kb_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c1_b_u = 14.0;
      c1_lb_y = NULL;
      sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_c_u = 6.0;
      c1_mb_y = NULL;
      sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_d_u = c1_ab_x;
      c1_nb_y = NULL;
      sf_mex_assign(&c1_nb_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_f_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c1_kb_y, 14, c1_lb_y, 14,
        c1_mb_y), 14, c1_nb_y), "sprintf", c1_str);
      for (c1_i44 = 0; c1_i44 < 14; c1_i44++) {
        c1_b_str[c1_i44] = c1_str[c1_i44];
      }

      c1_b_eml_warning(chartInstance, c1_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c1_eml_warning(chartInstance);
  }
}

static real_T c1_norm(SFc1_Dynamics_SimonInstanceStruct *chartInstance, real_T
                      c1_x[4])
{
  real_T c1_y;
  int32_T c1_j;
  real_T c1_b_j;
  real_T c1_s;
  int32_T c1_i;
  real_T c1_b_i;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_b_y;
  real_T c1_d_x;
  boolean_T c1_b;
  boolean_T exitg1;
  c1_y = 0.0;
  c1_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c1_j < 2)) {
    c1_b_j = 1.0 + (real_T)c1_j;
    c1_s = 0.0;
    for (c1_i = 0; c1_i < 2; c1_i++) {
      c1_b_i = 1.0 + (real_T)c1_i;
      c1_b_x = c1_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c1_b_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", c1_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c1_c_x = c1_b_x;
      c1_b_y = muDoubleScalarAbs(c1_c_x);
      c1_s += c1_b_y;
    }

    c1_d_x = c1_s;
    c1_b = muDoubleScalarIsNaN(c1_d_x);
    if (c1_b) {
      c1_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c1_s > c1_y) {
        c1_y = c1_s;
      }

      c1_j++;
    }
  }

  return c1_y;
}

static void c1_eml_warning(SFc1_Dynamics_SimonInstanceStruct *chartInstance)
{
  int32_T c1_i45;
  static char_T c1_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c1_u[27];
  const mxArray *c1_y = NULL;
  for (c1_i45 = 0; c1_i45 < 27; c1_i45++) {
    c1_u[c1_i45] = c1_varargin_1[c1_i45];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c1_y));
}

static void c1_b_eml_warning(SFc1_Dynamics_SimonInstanceStruct *chartInstance,
  char_T c1_varargin_2[14])
{
  int32_T c1_i46;
  static char_T c1_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c1_u[33];
  const mxArray *c1_y = NULL;
  int32_T c1_i47;
  char_T c1_b_u[14];
  const mxArray *c1_b_y = NULL;
  for (c1_i46 = 0; c1_i46 < 33; c1_i46++) {
    c1_u[c1_i46] = c1_varargin_1[c1_i46];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c1_i47 = 0; c1_i47 < 14; c1_i47++) {
    c1_b_u[c1_i47] = c1_varargin_2[c1_i47];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c1_y, 14, c1_b_y));
}

static void c1_eml_scalar_eg(SFc1_Dynamics_SimonInstanceStruct *chartInstance)
{
}

static void c1_f_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sprintf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_sprintf);
}

static void c1_g_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14])
{
  char_T c1_cv1[14];
  int32_T c1_i48;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c1_i48 = 0; c1_i48 < 14; c1_i48++) {
    c1_y[c1_i48] = c1_cv1[c1_i48];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_h_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i49;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i49, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i49;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_Dynamics_Simon, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_is_active_c1_Dynamics_Simon), &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_Dynamics_Simon);
  return c1_y;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Dynamics_SimonInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_Dynamics_Simon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(643456633U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1799834227U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1840541559U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1274222204U);
}

mxArray *sf_c1_Dynamics_Simon_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MgygAEsqYy37oU2SGBY9M");
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
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_Dynamics_Simon(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Xd\",},{M[8],M[0],T\"is_active_c1_Dynamics_Simon\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Dynamics_Simon_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Dynamics_SimonInstanceStruct *chartInstance;
    chartInstance = (SFc1_Dynamics_SimonInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Dynamics_SimonMachineNumber_,
           1,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Dynamics_SimonMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Dynamics_SimonMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Dynamics_SimonMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Xd");
          _SFD_SET_DATA_PROPS(2,1,1,0,"X");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",578,-1,1608);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c1_u;
          real_T (*c1_Xd)[4];
          real_T (*c1_X)[4];
          c1_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c1_Xd = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_Xd);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_X);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Dynamics_SimonMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "7wAUqfaIfuVicNF9KFCTrC";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Dynamics_Simon_optimization_info();
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

static void sf_opaque_initialize_c1_Dynamics_Simon(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_Dynamics_SimonInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_Dynamics_SimonInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Dynamics_Simon(void *chartInstanceVar)
{
  enable_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Dynamics_Simon(void *chartInstanceVar)
{
  disable_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Dynamics_Simon(void *chartInstanceVar)
{
  sf_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_Dynamics_Simon(void *chartInstanceVar)
{
  ext_mode_exec_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Dynamics_Simon(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Dynamics_Simon
    ((SFc1_Dynamics_SimonInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Dynamics_Simon();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Dynamics_Simon(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Dynamics_Simon();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Dynamics_Simon(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Dynamics_Simon(S);
}

static void sf_opaque_set_sim_state_c1_Dynamics_Simon(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_Dynamics_Simon(S, st);
}

static void sf_opaque_terminate_c1_Dynamics_Simon(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Dynamics_SimonInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Dynamics_Simon_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Dynamics_Simon(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Dynamics_Simon((SFc1_Dynamics_SimonInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_Dynamics_Simon_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c1_Dynamics_Simon\",T\"is_active_c1_Dynamics_Simon\"}}"
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

static void mdlSetWorkWidths_c1_Dynamics_Simon(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Dynamics_Simon_optimization_info();
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1693241501U));
  ssSetChecksum1(S,(2290463452U));
  ssSetChecksum2(S,(1583955333U));
  ssSetChecksum3(S,(347745626U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Dynamics_Simon(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Dynamics_Simon(SimStruct *S)
{
  SFc1_Dynamics_SimonInstanceStruct *chartInstance;
  chartInstance = (SFc1_Dynamics_SimonInstanceStruct *)malloc(sizeof
    (SFc1_Dynamics_SimonInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Dynamics_SimonInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Dynamics_Simon;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Dynamics_Simon;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Dynamics_Simon;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Dynamics_Simon;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Dynamics_Simon;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Dynamics_Simon;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Dynamics_Simon;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Dynamics_Simon;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Dynamics_Simon;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Dynamics_Simon;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Dynamics_Simon;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_Dynamics_Simon;
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

void c1_Dynamics_Simon_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Dynamics_Simon(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Dynamics_Simon(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Dynamics_Simon(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Dynamics_Simon_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
