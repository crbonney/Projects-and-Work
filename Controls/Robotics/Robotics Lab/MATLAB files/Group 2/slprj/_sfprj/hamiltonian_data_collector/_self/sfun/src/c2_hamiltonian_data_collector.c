/* Include files */

#include "blascompat32.h"
#include "hamiltonian_data_collector_sfun.h"
#include "c2_hamiltonian_data_collector.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hamiltonian_data_collector_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[31] = { "J1", "m2", "L12", "L2", "Lc2",
  "beta1", "beta2", "Ra", "kt", "kr", "g", "theta1", "theta2", "theta3",
  "theta4", "theta5", "theta6", "q1", "q2", "q1dot", "q2dot", "v", "m", "c", "f",
  "acceleration", "nargin", "nargout", "x", "u", "xdot" };

/* Function Declarations */
static void initialize_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void initialize_params_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void enable_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void disable_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void ext_mode_exec_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void set_sim_state_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void sf_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void c2_chartstep_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void initSimStructsc2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance, const mxArray *c2_xdot, const char_T *c2_identifier, real_T
  c2_y[4]);
static void c2_b_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[33]);
static real_T c2_mpower(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance);
static void c2_eml_warning(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_is_active_c2_hamiltonian_data_collector, const char_T *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_hamiltonian_data_collector;
  c2_is_active_c2_hamiltonian_data_collector = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_hamiltonian_data_collector = 0U;
}

static void initialize_params_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
}

static void enable_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
  c2_update_debugger_state_c2_hamiltonian_data_collector(chartInstance);
}

static const mxArray *get_sim_state_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[4];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T *c2_is_active_c2_hamiltonian_data_collector;
  real_T (*c2_xdot)[4];
  c2_xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_hamiltonian_data_collector = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    c2_u[c2_i0] = (*c2_xdot)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *c2_is_active_c2_hamiltonian_data_collector;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[4];
  int32_T c2_i1;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_is_active_c2_hamiltonian_data_collector;
  real_T (*c2_xdot)[4];
  c2_xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_hamiltonian_data_collector = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "xdot",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    (*c2_xdot)[c2_i1] = c2_dv0[c2_i1];
  }

  *c2_is_active_c2_hamiltonian_data_collector = c2_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_hamiltonian_data_collector");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_hamiltonian_data_collector(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
}

static void sf_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T *c2_sfEvent;
  real_T *c2_u;
  real_T (*c2_xdot)[4];
  real_T (*c2_x)[4];
  c2_xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_x)[c2_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_u, 1U);
  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_xdot)[c2_i3], 2U);
  }

  *c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_hamiltonian_data_collector(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_hamiltonian_data_collectorMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  int32_T c2_i4;
  real_T c2_x[4];
  real_T c2_u;
  uint32_T c2_debug_family_var_map[31];
  real_T c2_J1;
  real_T c2_m2;
  real_T c2_L12;
  real_T c2_L2;
  real_T c2_Lc2;
  real_T c2_beta1;
  real_T c2_beta2;
  real_T c2_Ra;
  real_T c2_kt;
  real_T c2_kr;
  real_T c2_g;
  real_T c2_theta1;
  real_T c2_theta2;
  real_T c2_theta3;
  real_T c2_theta4;
  real_T c2_theta5;
  real_T c2_theta6;
  real_T c2_q1;
  real_T c2_q2;
  real_T c2_q1dot;
  real_T c2_q2dot;
  real_T c2_v[2];
  real_T c2_m[4];
  real_T c2_c[4];
  real_T c2_f[2];
  real_T c2_acceleration[2];
  real_T c2_b_g[2];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_xdot[4];
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b;
  real_T c2_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_a;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_b_a;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_h_b;
  real_T c2_h_y;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_c_a;
  real_T c2_i_b;
  real_T c2_i_y;
  real_T c2_d_a;
  real_T c2_j_b;
  real_T c2_j_y;
  real_T c2_k_b;
  real_T c2_k_y;
  real_T c2_l_b;
  real_T c2_l_y;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_m_b;
  real_T c2_m_y;
  int32_T c2_i5;
  real_T c2_e_a[4];
  real_T c2_n_b[2];
  int32_T c2_i6;
  real_T c2_n_y[2];
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_o_y;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_p_y;
  real_T c2_d;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_q_y;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_r_y;
  real_T c2_b_d;
  int32_T c2_r1;
  int32_T c2_r2;
  real_T c2_cb_x;
  real_T c2_s_y;
  real_T c2_a21;
  real_T c2_f_a;
  real_T c2_o_b;
  real_T c2_t_y;
  real_T c2_a22;
  real_T c2_g_a;
  real_T c2_p_b;
  real_T c2_u_y;
  real_T c2_db_x;
  real_T c2_v_y;
  real_T c2_z;
  real_T c2_h_a;
  real_T c2_q_b;
  real_T c2_w_y;
  real_T c2_eb_x;
  real_T c2_x_y;
  real_T c2_b_z;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T (*c2_b_xdot)[4];
  real_T *c2_b_u;
  real_T (*c2_fb_x)[4];
  int32_T *c2_sfEvent;
  boolean_T guard1 = FALSE;
  c2_b_xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_fb_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c2_sfEvent);
  c2_hoistedGlobal = *c2_b_u;
  for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
    c2_x[c2_i4] = (*c2_fb_x)[c2_i4];
  }

  c2_u = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 31U, 32U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_J1, 0U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_m2, 1U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_L12, 2U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_L2, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Lc2, 4U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_beta1, 5U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_beta2, 6U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Ra, 7U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_kt, 8U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_kr, 9U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_g, MAX_uint32_T, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta1, 11U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_theta2, 12U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta3, 13U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta4, 14U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta5, 15U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta6, 16U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_q1, 17U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q2, 18U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q1dot, 19U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q2dot, 20U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_v, 21U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_m, 22U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_c, 23U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_f, 24U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_acceleration, 25U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_b_g, MAX_uint32_T,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 26U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 27U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_x, 28U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_u, 29U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_xdot, 30U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 3);
  c2_J1 = 0.0012;
  _SFD_EML_CALL(0U, *c2_sfEvent, 4);
  c2_m2 = 0.127;
  _SFD_EML_CALL(0U, *c2_sfEvent, 5);
  c2_L12 = 0.2;
  _SFD_EML_CALL(0U, *c2_sfEvent, 6);
  c2_L2 = 0.3;
  _SFD_EML_CALL(0U, *c2_sfEvent, 7);
  c2_Lc2 = 0.15;
  _SFD_EML_CALL(0U, *c2_sfEvent, 8);
  c2_beta1 = 0.015;
  _SFD_EML_CALL(0U, *c2_sfEvent, 9);
  c2_beta2 = 0.002;
  _SFD_EML_CALL(0U, *c2_sfEvent, 10);
  c2_Ra = 2.6;
  _SFD_EML_CALL(0U, *c2_sfEvent, 11);
  c2_kt = 0.00768;
  _SFD_EML_CALL(0U, *c2_sfEvent, 12);
  c2_kr = 70.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 13);
  c2_g = 9.81;
  sf_debug_symbol_switch(10U, 10U);
  _SFD_EML_CALL(0U, *c2_sfEvent, 15);
  c2_theta1 = 0.030372023809523814;
  _SFD_EML_CALL(0U, *c2_sfEvent, 16);
  c2_theta2 = 0.018426339285714285;
  _SFD_EML_CALL(0U, *c2_sfEvent, 17);
  c2_theta3 = 0.018426339285714285;
  _SFD_EML_CALL(0U, *c2_sfEvent, 18);
  c2_theta4 = 0.092131696428571441;
  _SFD_EML_CALL(0U, *c2_sfEvent, 19);
  c2_theta5 = 0.61014464285714287;
  _SFD_EML_CALL(0U, *c2_sfEvent, 20);
  c2_theta6 = 0.00967261904761905;
  _SFD_EML_CALL(0U, *c2_sfEvent, 22);
  c2_q1 = c2_x[0];
  _SFD_EML_CALL(0U, *c2_sfEvent, 23);
  c2_q2 = c2_x[1];
  _SFD_EML_CALL(0U, *c2_sfEvent, 24);
  c2_q1dot = c2_x[2];
  _SFD_EML_CALL(0U, *c2_sfEvent, 25);
  c2_q2dot = c2_x[3];
  _SFD_EML_CALL(0U, *c2_sfEvent, 26);
  c2_v[0] = c2_u;
  c2_v[1] = 0.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 28);
  c2_b_x = c2_q2;
  c2_c_x = c2_b_x;
  c2_c_x = muDoubleScalarSin(c2_c_x);
  c2_b = c2_mpower(chartInstance, c2_c_x);
  c2_y = 0.018426339285714285 * c2_b;
  c2_d_x = c2_q2;
  c2_e_x = c2_d_x;
  c2_e_x = muDoubleScalarCos(c2_e_x);
  c2_b_b = c2_e_x;
  c2_b_y = 0.018426339285714285 * c2_b_b;
  c2_f_x = c2_q2;
  c2_g_x = c2_f_x;
  c2_g_x = muDoubleScalarCos(c2_g_x);
  c2_c_b = c2_g_x;
  c2_c_y = 0.018426339285714285 * c2_c_b;
  c2_m[0] = c2_theta1 + c2_y;
  c2_m[2] = c2_b_y;
  c2_m[1] = c2_c_y;
  c2_m[3] = c2_theta2;
  _SFD_EML_CALL(0U, *c2_sfEvent, 34);
  c2_h_x = c2_q2;
  c2_i_x = c2_h_x;
  c2_i_x = muDoubleScalarCos(c2_i_x);
  c2_d_b = c2_i_x;
  c2_d_y = 0.036852678571428571 * c2_d_b;
  c2_a = c2_d_y;
  c2_e_b = c2_q2dot;
  c2_e_y = c2_a * c2_e_b;
  c2_j_x = c2_q2;
  c2_k_x = c2_j_x;
  c2_k_x = muDoubleScalarSin(c2_k_x);
  c2_f_b = c2_k_x;
  c2_f_y = -0.018426339285714285 * c2_f_b;
  c2_b_a = c2_f_y;
  c2_g_b = c2_q2dot;
  c2_g_y = c2_b_a * c2_g_b;
  c2_l_x = c2_q2;
  c2_m_x = c2_l_x;
  c2_m_x = muDoubleScalarSin(c2_m_x);
  c2_h_b = c2_m_x;
  c2_h_y = -0.018426339285714285 * c2_h_b;
  c2_n_x = c2_q2;
  c2_o_x = c2_n_x;
  c2_o_x = muDoubleScalarCos(c2_o_x);
  c2_c_a = c2_h_y;
  c2_i_b = c2_o_x;
  c2_i_y = c2_c_a * c2_i_b;
  c2_d_a = c2_i_y;
  c2_j_b = c2_q1dot;
  c2_j_y = c2_d_a * c2_j_b;
  c2_c[0] = c2_e_y;
  c2_c[2] = c2_g_y;
  c2_c[1] = c2_j_y;
  c2_c[3] = 0.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 40);
  c2_k_b = c2_q1dot;
  c2_k_y = 0.61014464285714287 * c2_k_b;
  c2_l_b = c2_q2dot;
  c2_l_y = 0.00967261904761905 * c2_l_b;
  c2_f[0] = c2_k_y;
  c2_f[1] = c2_l_y;
  _SFD_EML_CALL(0U, *c2_sfEvent, 45);
  c2_p_x = c2_q2;
  c2_q_x = c2_p_x;
  c2_q_x = muDoubleScalarSin(c2_q_x);
  c2_m_b = c2_q_x;
  c2_m_y = -0.90381194196428594 * c2_m_b;
  c2_b_g[0] = 0.0;
  c2_b_g[1] = c2_m_y;
  sf_debug_symbol_switch(10U, 26U);
  _SFD_EML_CALL(0U, *c2_sfEvent, 51);
  for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
    c2_e_a[c2_i5] = c2_c[c2_i5];
  }

  c2_n_b[0] = c2_q1dot;
  c2_n_b[1] = c2_q2dot;
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
    c2_n_y[c2_i6] = 0.0;
    c2_i7 = 0;
    for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
      c2_n_y[c2_i6] += c2_e_a[c2_i7 + c2_i6] * c2_n_b[c2_i8];
      c2_i7 += 2;
    }
  }

  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    c2_e_a[c2_i9] = -c2_m[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    c2_n_y[c2_i10] = ((c2_n_y[c2_i10] + c2_f[c2_i10]) + c2_b_g[c2_i10]) -
      c2_v[c2_i10];
  }

  c2_r_x = c2_e_a[1];
  c2_s_x = c2_r_x;
  c2_t_x = c2_s_x;
  c2_o_y = muDoubleScalarAbs(c2_t_x);
  c2_u_x = 0.0;
  c2_v_x = c2_u_x;
  c2_p_y = muDoubleScalarAbs(c2_v_x);
  c2_d = c2_o_y + c2_p_y;
  c2_w_x = c2_e_a[0];
  c2_x_x = c2_w_x;
  c2_y_x = c2_x_x;
  c2_q_y = muDoubleScalarAbs(c2_y_x);
  c2_ab_x = 0.0;
  c2_bb_x = c2_ab_x;
  c2_r_y = muDoubleScalarAbs(c2_bb_x);
  c2_b_d = c2_q_y + c2_r_y;
  if (c2_d > c2_b_d) {
    c2_r1 = 2;
    c2_r2 = 1;
  } else {
    c2_r1 = 1;
    c2_r2 = 2;
  }

  c2_cb_x = c2_e_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c2_r2), 1, 2, 1, 0) - 1];
  c2_s_y = c2_e_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r1), 1, 2, 1, 0) - 1];
  c2_a21 = c2_cb_x / c2_s_y;
  c2_f_a = c2_a21;
  c2_o_b = c2_e_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r1), 1, 2, 1, 0) + 1];
  c2_t_y = c2_f_a * c2_o_b;
  c2_a22 = c2_e_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r2), 1, 2, 1, 0) + 1] - c2_t_y;
  guard1 = FALSE;
  if (c2_a22 == 0.0) {
    guard1 = TRUE;
  } else {
    if (c2_e_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_r1), 1, 2, 1, 0) - 1] == 0.0) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c2_eml_warning(chartInstance);
  }

  c2_eml_scalar_eg(chartInstance);
  c2_g_a = c2_n_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r1), 1, 2, 1, 0) - 1];
  c2_p_b = c2_a21;
  c2_u_y = c2_g_a * c2_p_b;
  c2_db_x = c2_n_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c2_r2), 1, 2, 1, 0) - 1] - c2_u_y;
  c2_v_y = c2_a22;
  c2_z = c2_db_x / c2_v_y;
  c2_acceleration[1] = c2_z;
  c2_h_a = c2_acceleration[1];
  c2_q_b = c2_e_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r1), 1, 2, 1, 0) + 1];
  c2_w_y = c2_h_a * c2_q_b;
  c2_eb_x = c2_n_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c2_r1), 1, 2, 1, 0) - 1] - c2_w_y;
  c2_x_y = c2_e_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r1), 1, 2, 1, 0) - 1];
  c2_b_z = c2_eb_x / c2_x_y;
  c2_acceleration[0] = c2_b_z;
  _SFD_EML_CALL(0U, *c2_sfEvent, 53);
  c2_xdot[0] = c2_q1dot;
  c2_xdot[1] = c2_q2dot;
  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    c2_xdot[c2_i11 + 2] = c2_acceleration[c2_i11];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, -53);
  sf_debug_symbol_scope_pop();
  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    (*c2_b_xdot)[c2_i12] = c2_xdot[c2_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c2_sfEvent);
}

static void initSimStructsc2_hamiltonian_data_collector
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i13;
  real_T c2_b_inData[4];
  int32_T c2_i14;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_b_inData[c2_i13] = (*(real_T (*)[4])c2_inData)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
    c2_u[c2_i14] = c2_b_inData[c2_i14];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance, const mxArray *c2_xdot, const char_T *c2_identifier, real_T
  c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_xdot), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_xdot);
}

static void c2_b_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4])
{
  real_T c2_dv1[4];
  int32_T c2_i15;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i15 = 0; c2_i15 < 4; c2_i15++) {
    c2_y[c2_i15] = c2_dv1[c2_i15];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_xdot;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i16;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_xdot = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_xdot), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_xdot);
  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    (*(real_T (*)[4])c2_outData)[c2_i16] = c2_y[c2_i16];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i17;
  real_T c2_b_inData[2];
  int32_T c2_i18;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_b_inData[c2_i17] = (*(real_T (*)[2])c2_inData)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    c2_u[c2_i18] = c2_b_inData[c2_i18];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2])
{
  real_T c2_dv2[2];
  int32_T c2_i19;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_y[c2_i19] = c2_dv2[c2_i19];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_g;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i20;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_g = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_g), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_g);
  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    (*(real_T (*)[2])c2_outData)[c2_i20] = c2_y[c2_i20];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  real_T c2_b_inData[4];
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i21 = 0;
  for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
    for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
      c2_b_inData[c2_i23 + c2_i21] = (*(real_T (*)[4])c2_inData)[c2_i23 + c2_i21];
    }

    c2_i21 += 2;
  }

  c2_i24 = 0;
  for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
    for (c2_i26 = 0; c2_i26 < 2; c2_i26++) {
      c2_u[c2_i26 + c2_i24] = c2_b_inData[c2_i26 + c2_i24];
    }

    c2_i24 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4])
{
  real_T c2_dv3[4];
  int32_T c2_i27;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    c2_y[c2_i27] = c2_dv3[c2_i27];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_c;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_c = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_c);
  c2_i28 = 0;
  for (c2_i29 = 0; c2_i29 < 2; c2_i29++) {
    for (c2_i30 = 0; c2_i30 < 2; c2_i30++) {
      (*(real_T (*)[4])c2_outData)[c2_i30 + c2_i28] = c2_y[c2_i30 + c2_i28];
    }

    c2_i28 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_hamiltonian_data_collector_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[33];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i31;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 33), FALSE);
  for (c2_i31 = 0; c2_i31 < 33; c2_i31++) {
    c2_r0 = &c2_info[c2_i31];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i31);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i31);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i31);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i31);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i31);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i31);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i31);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i31);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[33])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1342836144U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1319755166U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1286844044U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_div";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[2].fileTimeLo = 1313373010U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mpower";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[3].fileTimeLo = 1286844042U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[4].name = "power";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[4].fileTimeLo = 1336547296U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[5].name = "eml_scalar_eg";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[5].fileTimeLo = 1286843996U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[6].name = "eml_scalexp_alloc";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[6].fileTimeLo = 1330633634U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[7].name = "floor";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[7].fileTimeLo = 1286843942U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[8].name = "eml_scalar_floor";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[8].fileTimeLo = 1286843926U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "mtimes";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].fileTimeLo = 1289544892U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "";
  c2_info[10].name = "sin";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[10].fileTimeLo = 1286843950U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[11].name = "eml_scalar_sin";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[11].fileTimeLo = 1286843936U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "cos";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[12].fileTimeLo = 1286843906U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[13].name = "eml_scalar_cos";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[13].fileTimeLo = 1286843922U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[14].name = "eml_index_class";
  c2_info[14].dominantType = "";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[14].fileTimeLo = 1323195778U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].name = "eml_scalar_eg";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[15].fileTimeLo = 1286843996U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[16].name = "eml_xgemm";
  c2_info[16].dominantType = "char";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[16].fileTimeLo = 1299101972U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[17].name = "eml_blas_inline";
  c2_info[17].dominantType = "";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[17].fileTimeLo = 1299101968U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[18].name = "mtimes";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[18].fileTimeLo = 1289544892U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[19].name = "eml_index_class";
  c2_info[19].dominantType = "";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[19].fileTimeLo = 1323195778U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[20].name = "eml_scalar_eg";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[20].fileTimeLo = 1286843996U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[21].name = "eml_refblas_xgemm";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[21].fileTimeLo = 1299101974U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context = "";
  c2_info[22].name = "mldivide";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[22].fileTimeLo = 1342836144U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 1319755166U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[23].name = "eml_lusolve";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[23].fileTimeLo = 1309476396U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[24].name = "eml_index_class";
  c2_info[24].dominantType = "";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[24].fileTimeLo = 1323195778U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c2_info[25].name = "eml_index_class";
  c2_info[25].dominantType = "";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[25].fileTimeLo = 1323195778U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c2_info[26].name = "eml_xcabs1";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[26].fileTimeLo = 1286843906U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[27].name = "abs";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[27].fileTimeLo = 1286843894U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[28].name = "eml_scalar_abs";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[28].fileTimeLo = 1286843912U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c2_info[29].name = "eml_div";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[29].fileTimeLo = 1313373010U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c2_info[30].name = "mtimes";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[30].fileTimeLo = 1289544892U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c2_info[31].name = "eml_warning";
  c2_info[31].dominantType = "char";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[31].fileTimeLo = 1286844002U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c2_info[32].name = "eml_scalar_eg";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[32].fileTimeLo = 1286843996U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
}

static real_T c2_mpower(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_ak = c2_c_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_eml_scalar_eg(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance)
{
}

static void c2_eml_warning(SFc2_hamiltonian_data_collectorInstanceStruct
  *chartInstance)
{
  int32_T c2_i32;
  static char_T c2_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c2_u[27];
  const mxArray *c2_y = NULL;
  for (c2_i32 = 0; c2_i32 < 27; c2_i32++) {
    c2_u[c2_i32] = c2_varargin_1[c2_i32];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c2_y));
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i33;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i33, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i33;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
    chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_is_active_c2_hamiltonian_data_collector, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_is_active_c2_hamiltonian_data_collector), &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_hamiltonian_data_collector);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn
  (SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_hamiltonian_data_collectorInstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_hamiltonian_data_collector_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1115280032U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2688629906U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1550139059U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3686377785U);
}

mxArray *sf_c2_hamiltonian_data_collector_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("u4aECYgFsIh5714bPukpfF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c2_hamiltonian_data_collector(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"xdot\",},{M[8],M[0],T\"is_active_c2_hamiltonian_data_collector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_hamiltonian_data_collector_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
    chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_hamiltonian_data_collectorMachineNumber_,
           2,
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
          init_script_number_translation
            (_hamiltonian_data_collectorMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_hamiltonian_data_collectorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_hamiltonian_data_collectorMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u");
          _SFD_SET_DATA_PROPS(2,2,0,1,"xdot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,879);
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
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_u;
          real_T (*c2_x)[4];
          real_T (*c2_xdot)[4];
          c2_xdot = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_xdot);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_hamiltonian_data_collectorMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "FjpoQY6eyzfbYVwUnvrPtF";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_hamiltonian_data_collector_optimization_info();
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

static void sf_opaque_initialize_c2_hamiltonian_data_collector(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_hamiltonian_data_collectorInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_hamiltonian_data_collectorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
  initialize_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_hamiltonian_data_collector(void
  *chartInstanceVar)
{
  enable_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_hamiltonian_data_collector(void
  *chartInstanceVar)
{
  disable_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_hamiltonian_data_collector(void
  *chartInstanceVar)
{
  sf_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_hamiltonian_data_collector(void
  *chartInstanceVar)
{
  ext_mode_exec_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_hamiltonian_data_collector
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_hamiltonian_data_collector();/* state var info */
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

extern void sf_internal_set_sim_state_c2_hamiltonian_data_collector(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_hamiltonian_data_collector();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_hamiltonian_data_collector
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_hamiltonian_data_collector(S);
}

static void sf_opaque_set_sim_state_c2_hamiltonian_data_collector(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_hamiltonian_data_collector(S, st);
}

static void sf_opaque_terminate_c2_hamiltonian_data_collector(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_hamiltonian_data_collectorInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_hamiltonian_data_collector
      ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_hamiltonian_data_collector_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_hamiltonian_data_collector
    ((SFc2_hamiltonian_data_collectorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_hamiltonian_data_collector(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_hamiltonian_data_collector
      ((SFc2_hamiltonian_data_collectorInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_hamiltonian_data_collector_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_hamiltonian_data_collector\",T\"is_active_c2_hamiltonian_data_collector\"}}"
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

static void mdlSetWorkWidths_c2_hamiltonian_data_collector(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hamiltonian_data_collector_optimization_info();
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
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3100441447U));
  ssSetChecksum1(S,(3053400838U));
  ssSetChecksum2(S,(1191160535U));
  ssSetChecksum3(S,(556271763U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_hamiltonian_data_collector(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_hamiltonian_data_collector(SimStruct *S)
{
  SFc2_hamiltonian_data_collectorInstanceStruct *chartInstance;
  chartInstance = (SFc2_hamiltonian_data_collectorInstanceStruct *)malloc(sizeof
    (SFc2_hamiltonian_data_collectorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_hamiltonian_data_collectorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_hamiltonian_data_collector;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_hamiltonian_data_collector;
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

void c2_hamiltonian_data_collector_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_hamiltonian_data_collector(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_hamiltonian_data_collector(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_hamiltonian_data_collector(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_hamiltonian_data_collector_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
