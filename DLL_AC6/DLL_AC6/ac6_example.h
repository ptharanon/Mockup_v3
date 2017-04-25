/*
 * ac6_example.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ac6_example".
 *
 * Model version              : 1.138
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C++ source code generated on : Sat Apr 15 16:16:54 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ac6_example_h_
#define RTW_HEADER_ac6_example_h_
#include <math.h>
#include <string.h>
#ifndef ac6_example_COMMON_INCLUDES_
# define ac6_example_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ac6_example_COMMON_INCLUDES_ */

#include "ac6_example_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Fcn1;                         /* '<S68>/Fcn1' */
  real_T SineWaveA;                    /* '<S5>/Sine Wave A' */
  real_T SineWaveB;                    /* '<S5>/Sine Wave B' */
  real_T SineWaveC;                    /* '<S5>/Sine Wave C' */
  real_T Switch[6];                    /* '<S288>/Switch' */
  real_T StateSpace_o1[22];            /* '<S336>/State-Space' */
  real_T StateSpace_o2[14];            /* '<S336>/State-Space' */
  real_T Reference;                    /* '<S80>/Rate Transition2' */
  real_T TorquereferenceNm;            /* '<S80>/Rate Transition2' */
  real_T DataTypeConversion[6];        /* '<S286>/Data Type Conversion' */
  real_T DataTypeConversion_o;         /* '<S27>/Data Type Conversion' */
  real_T Fcn_c;                        /* '<S64>/Fcn' */
  real_T RateTransition;               /* '<S80>/Rate Transition' */
  real_T rad2rpm;                      /* '<S80>/rad2rpm' */
  real_T ZeroOrderHold1;               /* '<S80>/Zero-Order Hold1' */
  real_T UnitDelay2[3];                /* '<S292>/Unit Delay2' */
  real_T ZeroOrderHold4[3];            /* '<S292>/Zero-Order Hold4' */
  real_T ZeroOrderHold3;               /* '<S292>/Zero-Order Hold3' */
  real_T Product[6];                   /* '<S287>/Product' */
  boolean_T RateTransition2[6];        /* '<S292>/Rate Transition2' */
} B_ac6_example_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[6];          /* '<S286>/Unit Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S64>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S71>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S70>/Discrete-Time Integrator' */
  real_T StateSpace_DSTATE[9];         /* '<S336>/State-Space' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S64>/Discrete-Time Integrator' */
  real_T UnitDelay1_DSTATE;            /* '<S21>/Unit Delay1' */
  real_T DiscreteTimeIntegrator1_DSTAT_j;/* '<S34>/Discrete-Time Integrator1' */
  real_T Lowpassfilter_states;         /* '<S80>/Low pass filter' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S80>/Discrete-Time Integrator2' */
  real_T UnitDelay2_DSTATE[3];         /* '<S292>/Unit Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S305>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S306>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S308>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S309>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_ar;/* '<S311>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S312>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_jn[6];/* '<S287>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_g[6];        /* '<S287>/Unit Delay' */
  real_T lastSin;                      /* '<S5>/Sine Wave A' */
  real_T lastCos;                      /* '<S5>/Sine Wave A' */
  real_T lastSin_i;                    /* '<S5>/Sine Wave B' */
  real_T lastCos_o;                    /* '<S5>/Sine Wave B' */
  real_T lastSin_c;                    /* '<S5>/Sine Wave C' */
  real_T lastCos_m;                    /* '<S5>/Sine Wave C' */
  real_T RateTransition2_3_Buffer0;    /* '<S80>/Rate Transition2' */
  real_T RateTransition2_1_Buffer0;    /* '<S80>/Rate Transition2' */
  real_T PrevY;                        /* '<S80>/Rate Limiter' */
  real_T RateTransition_Buffer0;       /* '<S80>/Rate Transition' */
  struct {
    void *AS;
    void *BS;
    void *CS;
    void *DS;
    void *DX_COL;
    void *BD_COL;
    void *TMP1;
    void *TMP2;
    void *XTMP;
    void *SWITCH_STATUS;
    void *SWITCH_STATUS_INIT;
    void *SW_CHG;
    void *CHOPPER;
    void *G_STATE;
    void *XKM12;
    void *XKP12;
    void *XLAST;
    void *ULAST;
    void *IDX_SW_CHG;
    void *Y_SWITCH;
    void *SWITCH_TYPES;
    void *IDX_OUT_SW;
  } StateSpace_PWORK;                  /* '<S336>/State-Space' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<Root>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace1_PWORK;              /* '<Root>/From Workspace1' */

  int32_T systemEnable;                /* '<S5>/Sine Wave A' */
  int32_T systemEnable_i;              /* '<S5>/Sine Wave B' */
  int32_T systemEnable_h;              /* '<S5>/Sine Wave C' */
  int_T StateSpace_IWORK[5];           /* '<S336>/State-Space' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<Root>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace1_IWORK;              /* '<Root>/From Workspace1' */

  boolean_T UnitDelay1_DSTATE_d;       /* '<S34>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S306>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_j;        /* '<S305>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S309>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S308>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S312>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_m;        /* '<S311>/Unit Delay' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S34>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S305>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S306>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_bl;/* '<S308>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_i;/* '<S309>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S311>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S312>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_k2[6];/* '<S287>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator2_SYSTEM_;/* '<S80>/Discrete-Time Integrator2' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S305>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_a;/* '<S306>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_d;/* '<S308>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_l;/* '<S309>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_k;/* '<S311>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_b;/* '<S312>/Discrete-Time Integrator' */
  boolean_T RateTransition2_Buffer0[6];/* '<S292>/Rate Transition2' */
  boolean_T Relay_Mode;                /* '<S21>/Relay' */
  boolean_T IC_FirstOutputTime;        /* '<S80>/IC' */
  boolean_T Relay_Mode_n;              /* '<S298>/Relay' */
  boolean_T Relay1_Mode;               /* '<S298>/Relay1' */
  boolean_T Relay2_Mode;               /* '<S298>/Relay2' */
  boolean_T Memory_PreviousInput;      /* '<S304>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S307>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S310>/Memory' */
  boolean_T Tail_MODE;                 /* '<S286>/Tail' */
} DW_ac6_example_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Statorcurrent;                /* '<Root>/Stator current' */
  real_T Rotorspeed[2];                /* '<Root>/Rotor speed' */
  real_T ElectromagneticTorque[2];     /* '<Root>/Electromagnetic Torque' */
  real_T DCbusvoltage;                 /* '<Root>/DC bus voltage' */
} ExtY_ac6_example_T;

/* Parameters (auto storage) */
struct P_ac6_example_T_ {
  real_T u20V60Hz_Frequency;           /* Mask Parameter: u20V60Hz_Frequency
                                        * Referenced by:
                                        *   '<S5>/Sine Wave A'
                                        *   '<S5>/Sine Wave B'
                                        *   '<S5>/Sine Wave C'
                                        */
  real_T Tail_Tf;                      /* Mask Parameter: Tail_Tf
                                        * Referenced by:
                                        *   '<S287>/2'
                                        *   '<S289>/Constant2'
                                        *   '<S289>/-0.9//Tf'
                                        */
  real_T Tail_Tt;                      /* Mask Parameter: Tail_Tt
                                        * Referenced by:
                                        *   '<S287>/2'
                                        *   '<S289>/Constant2'
                                        *   '<S289>/0.1//Tt'
                                        */
  real_T Brakingchopper_activationVoltag;/* Mask Parameter: Brakingchopper_activationVoltag
                                          * Referenced by:
                                          *   '<S21>/Constant'
                                          *   '<S21>/Relay'
                                          */
  real_T VECT_freq_max;                /* Mask Parameter: VECT_freq_max
                                        * Referenced by:
                                        *   '<S305>/Constant1'
                                        *   '<S306>/Constant1'
                                        *   '<S308>/Constant1'
                                        *   '<S309>/Constant1'
                                        *   '<S311>/Constant1'
                                        *   '<S312>/Constant1'
                                        */
  real_T Brakingchopper_frequency;     /* Mask Parameter: Brakingchopper_frequency
                                        * Referenced by: '<S34>/fc'
                                        */
  real_T CoulombViscousFriction_gain;  /* Mask Parameter: CoulombViscousFriction_gain
                                        * Referenced by: '<S72>/Gain'
                                        */
  real_T VECT_h;                       /* Mask Parameter: VECT_h
                                        * Referenced by:
                                        *   '<S298>/Relay'
                                        *   '<S298>/Relay1'
                                        *   '<S298>/Relay2'
                                        */
  real_T SpeedController_ki;           /* Mask Parameter: SpeedController_ki
                                        * Referenced by: '<S80>/Integral gain'
                                        */
  real_T SpeedController_kp;           /* Mask Parameter: SpeedController_kp
                                        * Referenced by: '<S80>/Proportional gain'
                                        */
  real_T VECT_lambda;                  /* Mask Parameter: VECT_lambda
                                        * Referenced by: '<S292>/te2iq'
                                        */
  real_T VECT_nb_p;                    /* Mask Parameter: VECT_nb_p
                                        * Referenced by:
                                        *   '<S292>/Gain1'
                                        *   '<S292>/te2iq'
                                        */
  real_T CoulombViscousFriction_offset;/* Mask Parameter: CoulombViscousFriction_offset
                                        * Referenced by: '<S72>/Gain1'
                                        */
  real_T Brakingchopper_shutdownVoltage;/* Mask Parameter: Brakingchopper_shutdownVoltage
                                         * Referenced by: '<S21>/Relay'
                                         */
  boolean_T SRFlipFlop1_initial_condition;/* Mask Parameter: SRFlipFlop1_initial_condition
                                           * Referenced by: '<S304>/Memory'
                                           */
  boolean_T SRFlipFlop1_initial_condition_h;/* Mask Parameter: SRFlipFlop1_initial_condition_h
                                             * Referenced by: '<S307>/Memory'
                                             */
  boolean_T SRFlipFlop1_initial_condition_a;/* Mask Parameter: SRFlipFlop1_initial_condition_a
                                             * Referenced by: '<S310>/Memory'
                                             */
  real_T itail_Y0;                     /* Expression: 0
                                        * Referenced by: '<S287>/itail'
                                        */
  real_T u_Value;                      /* Expression: 1
                                        * Referenced by: '<S287>/1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S287>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S287>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value;               /* Expression: 0.9
                                        * Referenced by: '<S289>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0.9
                                        * Referenced by: '<S289>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S289>/Saturation1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 0.1
                                        * Referenced by: '<S289>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S289>/Saturation2'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S287>/Unit Delay'
                                        */
  real_T SwitchCurrents_Value[8];      /* Expression: zeros(8,1)
                                        * Referenced by: '<S338>/SwitchCurrents'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: 0
                                        * Referenced by: '<S286>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S64>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: PM.tho+PM.thOffest
                                        * Referenced by: '<S64>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                          * Referenced by: '<S71>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_o;  /* Expression: PM.isqo
                                        * Referenced by: '<S71>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                          * Referenced by: '<S70>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: PM.isdo
                                        * Referenced by: '<S70>/Discrete-Time Integrator'
                                        */
  real_T SineWaveA_Amp;                /* Expression: Aa
                                        * Referenced by: '<S5>/Sine Wave A'
                                        */
  real_T SineWaveA_Bias;               /* Expression: 0
                                        * Referenced by: '<S5>/Sine Wave A'
                                        */
  real_T SineWaveA_Hsin;               /* Computed Parameter: SineWaveA_Hsin
                                        * Referenced by: '<S5>/Sine Wave A'
                                        */
  real_T SineWaveA_HCos;               /* Computed Parameter: SineWaveA_HCos
                                        * Referenced by: '<S5>/Sine Wave A'
                                        */
  real_T SineWaveA_PSin;               /* Computed Parameter: SineWaveA_PSin
                                        * Referenced by: '<S5>/Sine Wave A'
                                        */
  real_T SineWaveA_PCos;               /* Computed Parameter: SineWaveA_PCos
                                        * Referenced by: '<S5>/Sine Wave A'
                                        */
  real_T SineWaveB_Amp;                /* Expression: Ab
                                        * Referenced by: '<S5>/Sine Wave B'
                                        */
  real_T SineWaveB_Bias;               /* Expression: 0
                                        * Referenced by: '<S5>/Sine Wave B'
                                        */
  real_T SineWaveB_Hsin;               /* Computed Parameter: SineWaveB_Hsin
                                        * Referenced by: '<S5>/Sine Wave B'
                                        */
  real_T SineWaveB_HCos;               /* Computed Parameter: SineWaveB_HCos
                                        * Referenced by: '<S5>/Sine Wave B'
                                        */
  real_T SineWaveB_PSin;               /* Computed Parameter: SineWaveB_PSin
                                        * Referenced by: '<S5>/Sine Wave B'
                                        */
  real_T SineWaveB_PCos;               /* Computed Parameter: SineWaveB_PCos
                                        * Referenced by: '<S5>/Sine Wave B'
                                        */
  real_T SineWaveC_Amp;                /* Expression: Ac
                                        * Referenced by: '<S5>/Sine Wave C'
                                        */
  real_T SineWaveC_Bias;               /* Expression: 0
                                        * Referenced by: '<S5>/Sine Wave C'
                                        */
  real_T SineWaveC_Hsin;               /* Computed Parameter: SineWaveC_Hsin
                                        * Referenced by: '<S5>/Sine Wave C'
                                        */
  real_T SineWaveC_HCos;               /* Computed Parameter: SineWaveC_HCos
                                        * Referenced by: '<S5>/Sine Wave C'
                                        */
  real_T SineWaveC_PSin;               /* Computed Parameter: SineWaveC_PSin
                                        * Referenced by: '<S5>/Sine Wave C'
                                        */
  real_T SineWaveC_PCos;               /* Computed Parameter: SineWaveC_PCos
                                        * Referenced by: '<S5>/Sine Wave C'
                                        */
  real_T eee_Value;                    /* Expression: Vf
                                        * Referenced by: '<S29>/eee'
                                        */
  real_T Constant_Value_g[6];          /* Expression: ForwardVoltage.*ones(1,Switches)
                                        * Referenced by: '<S73>/Constant'
                                        */
  real_T VfDevicesClampingDiodes_Value[6];/* Expression: Vf_SwitchOn
                                           * Referenced by: '<S288>/Vf Devices & Clamping Diodes'
                                           */
  real_T VfDiodes_Value[6];            /* Expression: Vf_DiodeOn
                                        * Referenced by: '<S288>/Vf Diodes'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                          * Referenced by: '<S64>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: PM.wmo
                                        * Referenced by: '<S64>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: 30/pi
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T RateTransition2_3_X0;         /* Expression: 0
                                        * Referenced by: '<S80>/Rate Transition2'
                                        */
  real_T RateTransition2_1_X0;         /* Expression: 0
                                        * Referenced by: '<S80>/Rate Transition2'
                                        */
  real_T donotdeletethisgain_Gain;     /* Expression: 1
                                        * Referenced by: '<S24>/do not delete this gain'
                                        */
  real_T u4_Value;                     /* Expression: 0
                                        * Referenced by: '<S286>/0 4'
                                        */
  real_T uRon_Gain;                    /* Expression: 1./Ron
                                        * Referenced by: '<S286>/1//Ron'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S286>/Switch'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S286>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S286>/Saturation'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S21>/Unit Delay1'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 1/100
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_a;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_a
                                          * Referenced by: '<S34>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_h; /* Expression: 0
                                        * Referenced by: '<S34>/Discrete-Time Integrator1'
                                        */
  real_T Relay_YOn;                    /* Expression: 1
                                        * Referenced by: '<S21>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: 0
                                        * Referenced by: '<S21>/Relay'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S34>/Constant3'
                                        */
  real_T donotdeletethisgain_Gain_i;   /* Expression: 1
                                        * Referenced by: '<S53>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_a;   /* Expression: 1
                                        * Referenced by: '<S54>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ie;  /* Expression: 1
                                        * Referenced by: '<S55>/do not delete this gain'
                                        */
  real_T uLd_Gain;                     /* Expression: 1/PM.Ld
                                        * Referenced by: '<S70>/1//Ld'
                                        */
  real_T Gain_Gain_a;                  /* Expression: PM.p
                                        * Referenced by: '<S64>/Gain'
                                        */
  real_T LqLd_Gain;                    /* Expression: PM.Lq/PM.Ld
                                        * Referenced by: '<S70>/Lq//Ld'
                                        */
  real_T RLd_Gain;                     /* Expression: PM.R/PM.Ld
                                        * Referenced by: '<S70>/R//Ld'
                                        */
  real_T uLq_Gain;                     /* Expression: 1/PM.Lq
                                        * Referenced by: '<S71>/1//Lq'
                                        */
  real_T LdLq_Gain;                    /* Expression: PM.Ld/PM.Lq
                                        * Referenced by: '<S71>/Ld//Lq'
                                        */
  real_T RLq_Gain;                     /* Expression: PM.R/PM.Lq
                                        * Referenced by: '<S71>/R//Lq'
                                        */
  real_T lamLq_Gain;                   /* Expression: PM.Flux/PM.Lq
                                        * Referenced by: '<S71>/lam//Lq'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/PM.J
                                        * Referenced by: '<S64>/Gain2'
                                        */
  real_T Constant1_Value;              /* Expression: reg_mode
                                        * Referenced by: '<S80>/Constant1'
                                        */
  real_T IC_Value;                     /* Expression: 0
                                        * Referenced by: '<S80>/IC'
                                        */
  real_T RateLimiter_RisingLim;        /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S80>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S80>/Rate Limiter'
                                        */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<S80>/Rate Limiter'
                                        */
  real_T Lowpassfilter_NumCoef;        /* Expression: [1-exp(-2*pi*fc*Tsc)]
                                        * Referenced by: '<S80>/Low pass filter'
                                        */
  real_T Lowpassfilter_DenCoef[2];     /* Expression: [1 -exp(-2*pi*fc*Tsc)]
                                        * Referenced by: '<S80>/Low pass filter'
                                        */
  real_T Lowpassfilter_InitialStates;  /* Expression: 0
                                        * Referenced by: '<S80>/Low pass filter'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<S80>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S80>/Discrete-Time Integrator2'
                                        */
  real_T DiscreteTimeIntegrator2_UpperSa;/* Expression: ctrl_sat(2)
                                          * Referenced by: '<S80>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_LowerSa;/* Expression: ctrl_sat(1)
                                          * Referenced by: '<S80>/Discrete-Time Integrator2'
                                          */
  real_T Ctrlsat_UpperSat;             /* Expression: ctrl_sat(2)
                                        * Referenced by: '<S80>/Ctrl sat.'
                                        */
  real_T Ctrlsat_LowerSat;             /* Expression: ctrl_sat(1)
                                        * Referenced by: '<S80>/Ctrl sat.'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S80>/Rate Transition'
                                        */
  real_T rad2rpm_Gain;                 /* Expression: 30/pi
                                        * Referenced by: '<S80>/rad2rpm'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S292>/Constant1'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S292>/Unit Delay2'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S299>/Gain2'
                                        */
  real_T Relay_YOn_m;                  /* Expression: 1
                                        * Referenced by: '<S298>/Relay'
                                        */
  real_T Relay_YOff_n;                 /* Expression: 0
                                        * Referenced by: '<S298>/Relay'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S299>/Gain3'
                                        */
  real_T Relay1_YOn;                   /* Expression: 1
                                        * Referenced by: '<S298>/Relay1'
                                        */
  real_T Relay1_YOff;                  /* Expression: 0
                                        * Referenced by: '<S298>/Relay1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S299>/Gain4'
                                        */
  real_T Relay2_YOn;                   /* Expression: 1
                                        * Referenced by: '<S298>/Relay2'
                                        */
  real_T Relay2_YOff;                  /* Expression: 0
                                        * Referenced by: '<S298>/Relay2'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S305>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_h;/* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                          * Referenced by: '<S305>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S305>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S306>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                          * Referenced by: '<S306>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S306>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_dm;            /* Expression: 1
                                        * Referenced by: '<S308>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                          * Referenced by: '<S308>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S308>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S309>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                          * Referenced by: '<S309>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_mc; /* Expression: 0
                                        * Referenced by: '<S309>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S311>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_d;/* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                          * Referenced by: '<S311>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_jn; /* Expression: 0
                                        * Referenced by: '<S311>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S312>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainv_p2;/* Computed Parameter: DiscreteTimeIntegrator_gainv_p2
                                          * Referenced by: '<S312>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_oq; /* Expression: 0
                                        * Referenced by: '<S312>/Discrete-Time Integrator'
                                        */
  real_T g_Value[6];                   /* Expression: zeros(1,6)
                                        * Referenced by: '<S11>/g'
                                        */
  boolean_T RateTransition2_X0;        /* Computed Parameter: RateTransition2_X0
                                        * Referenced by: '<S292>/Rate Transition2'
                                        */
  boolean_T u_Value_d;                 /* Expression: Tf_sps>0 | Tt_sps>0
                                        * Referenced by: '<S286>/2'
                                        */
  boolean_T UnitDelay1_InitialCondition_l;/* Computed Parameter: UnitDelay1_InitialCondition_l
                                           * Referenced by: '<S34>/Unit Delay1'
                                           */
  boolean_T UnitDelay_InitialCondition_p;/* Computed Parameter: UnitDelay_InitialCondition_p
                                          * Referenced by: '<S306>/Unit Delay'
                                          */
  boolean_T UnitDelay_InitialCondition_n;/* Computed Parameter: UnitDelay_InitialCondition_n
                                          * Referenced by: '<S305>/Unit Delay'
                                          */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S304>/Logic'
                                        */
  boolean_T UnitDelay_InitialCondition_a;/* Computed Parameter: UnitDelay_InitialCondition_a
                                          * Referenced by: '<S309>/Unit Delay'
                                          */
  boolean_T UnitDelay_InitialCondition_e;/* Computed Parameter: UnitDelay_InitialCondition_e
                                          * Referenced by: '<S308>/Unit Delay'
                                          */
  boolean_T Logic_table_b[16];         /* Computed Parameter: Logic_table_b
                                        * Referenced by: '<S307>/Logic'
                                        */
  boolean_T UnitDelay_InitialCondition_m;/* Computed Parameter: UnitDelay_InitialCondition_m
                                          * Referenced by: '<S312>/Unit Delay'
                                          */
  boolean_T UnitDelay_InitialCondition_kf;/* Computed Parameter: UnitDelay_InitialCondition_kf
                                           * Referenced by: '<S311>/Unit Delay'
                                           */
  boolean_T Logic_table_i[16];         /* Computed Parameter: Logic_table_i
                                        * Referenced by: '<S310>/Logic'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ac6_example_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
      uint8_T cLimit[3];
    } TaskCounters;

    struct {
      uint8_T TID0_1;
      uint8_T TID0_2;
      uint8_T TID1_2;
    } RateInteraction;
  } Timing;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

/* Class declaration for model ac6_example */
class ac6_exampleModelClass {
  /* public data and function members */
 public:
  /* External outputs */
  ExtY_ac6_example_T ac6_example_Y;

  /* Model entry point functions */

  /* model initialize function */
  void initialize();

  /* model initialize function */
  void customeInitializer(double speedInput[],double torqueInput[],double timeVector[]);

  /* model step function */
  void step0();

  /* model step function */
  void step1();

  /* model step function */
  void step2();

  /* model terminate function */
  void terminate();

  /* Constructor */
  ac6_exampleModelClass();

  /* Destructor */
  ~ac6_exampleModelClass();

  /* Real-Time Model get method */
  RT_MODEL_ac6_example_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  P_ac6_example_T ac6_example_P;

  /* Block signals */
  B_ac6_example_T ac6_example_B;

  /* Block states */
  DW_ac6_example_T ac6_example_DW;

  /* Real-Time Model */
  RT_MODEL_ac6_example_T ac6_example_M;
};

// Model step wrapper function for compatibility with a static main program
void ac6_example_step(ac6_exampleModelClass & ac6_example_Obj, int_T tid);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ac6_example'
 * '<S1>'   : 'ac6_example/220V 60Hz'
 * '<S2>'   : 'ac6_example/PM Synchronous Motor Drive'
 * '<S3>'   : 'ac6_example/demux'
 * '<S4>'   : 'ac6_example/powergui'
 * '<S5>'   : 'ac6_example/220V 60Hz/Model'
 * '<S6>'   : 'ac6_example/PM Synchronous Motor Drive/Braking chopper'
 * '<S7>'   : 'ac6_example/PM Synchronous Motor Drive/Measures'
 * '<S8>'   : 'ac6_example/PM Synchronous Motor Drive/Mux'
 * '<S9>'   : 'ac6_example/PM Synchronous Motor Drive/Output bus selection'
 * '<S10>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine'
 * '<S11>'  : 'ac6_example/PM Synchronous Motor Drive/Rectifier_3ph'
 * '<S12>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller'
 * '<S13>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter'
 * '<S14>'  : 'ac6_example/PM Synchronous Motor Drive/VECT'
 * '<S15>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper'
 * '<S16>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive'
 * '<S17>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive'
 * '<S18>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive'
 * '<S19>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper'
 * '<S20>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/I rectifier'
 * '<S21>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Proportional controller'
 * '<S22>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Braking chopper'
 * '<S23>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Current Measurement'
 * '<S24>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Voltage Measurement'
 * '<S25>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Braking chopper/Chopper switch'
 * '<S26>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Braking chopper/Diode1'
 * '<S27>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Braking chopper/Chopper switch/Model'
 * '<S28>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Braking chopper/Chopper switch/Model/Measurement list'
 * '<S29>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Braking chopper/Diode1/Model'
 * '<S30>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Braking chopper/Diode1/Model/Measurement list'
 * '<S31>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Current Measurement/Model'
 * '<S32>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Capacitive DC bus with braking chopper/Voltage Measurement/Model'
 * '<S33>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/I rectifier/Model'
 * '<S34>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/Capacitive/Capacitive/Proportional controller/Ramp_generator'
 * '<S35>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper'
 * '<S36>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Current Measurement1'
 * '<S37>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Six-step braking chopper control'
 * '<S38>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Voltage Measurement1'
 * '<S39>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Braking chopper'
 * '<S40>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Current Measurement'
 * '<S41>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Voltage Measurement'
 * '<S42>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Braking chopper/Chopper switch'
 * '<S43>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Braking chopper/Diode1'
 * '<S44>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Braking chopper/Chopper switch/Model'
 * '<S45>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Braking chopper/Chopper switch/Model/Measurement list'
 * '<S46>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Braking chopper/Diode1/Model'
 * '<S47>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Braking chopper/Diode1/Model/Measurement list'
 * '<S48>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Current Measurement/Model'
 * '<S49>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Capacitive DC bus with braking chopper/Voltage Measurement/Model'
 * '<S50>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Current Measurement1/Model'
 * '<S51>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Six-step braking chopper control/ramp_generator'
 * '<S52>'  : 'ac6_example/PM Synchronous Motor Drive/Braking chopper/DC bus and braking chopper/LC_six_step_drive/Voltage Measurement1/Model'
 * '<S53>'  : 'ac6_example/PM Synchronous Motor Drive/Measures/Current Measurement'
 * '<S54>'  : 'ac6_example/PM Synchronous Motor Drive/Measures/Current Measurement1'
 * '<S55>'  : 'ac6_example/PM Synchronous Motor Drive/Measures/Current Measurement2'
 * '<S56>'  : 'ac6_example/PM Synchronous Motor Drive/Measures/Current Measurement/Model'
 * '<S57>'  : 'ac6_example/PM Synchronous Motor Drive/Measures/Current Measurement1/Model'
 * '<S58>'  : 'ac6_example/PM Synchronous Motor Drive/Measures/Current Measurement2/Model'
 * '<S59>'  : 'ac6_example/PM Synchronous Motor Drive/Mux/Average'
 * '<S60>'  : 'ac6_example/PM Synchronous Motor Drive/Mux/Detailed'
 * '<S61>'  : 'ac6_example/PM Synchronous Motor Drive/Output bus selection/Multiple output buses'
 * '<S62>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model'
 * '<S63>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Measurements'
 * '<S64>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Mechanical model'
 * '<S65>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model/Hall effect sensor'
 * '<S66>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model/abc2qd'
 * '<S67>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model/iq,id'
 * '<S68>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model/qd2abc'
 * '<S69>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model/Hall effect sensor/Angle converter'
 * '<S70>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model/iq,id/id'
 * '<S71>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Electrical model/iq,id/iq'
 * '<S72>'  : 'ac6_example/PM Synchronous Motor Drive/Permanent Magnet Synchronous Machine/Mechanical model/Coulomb & Viscous Friction'
 * '<S73>'  : 'ac6_example/PM Synchronous Motor Drive/Rectifier_3ph/Model'
 * '<S74>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller/Speed Controller (AC)'
 * '<S75>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller/Speed Controller (AC)/AC345'
 * '<S76>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller/Speed Controller (AC)/AC678'
 * '<S77>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller/Speed Controller (AC)/AC345/Flux table'
 * '<S78>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller/Speed Controller (AC)/AC345/Speed controller (generic AC)'
 * '<S79>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller/Speed Controller (AC)/AC345/Speed controller (generic AC)/PI regulator'
 * '<S80>'  : 'ac6_example/PM Synchronous Motor Drive/Speed Controller/Speed Controller (AC)/AC678/AC678'
 * '<S81>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC'
 * '<S82>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC'
 * '<S83>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM'
 * '<S84>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM'
 * '<S85>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM'
 * '<S86>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Detailed'
 * '<S87>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Calcul de Icc'
 * '<S88>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Controlled Current Source2'
 * '<S89>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Controlled Voltage Source'
 * '<S90>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Controlled Voltage Source1'
 * '<S91>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements'
 * '<S92>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation'
 * '<S93>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Voltage Measurement3'
 * '<S94>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Current Measurement'
 * '<S95>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Current Measurement1'
 * '<S96>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Current Measurement2'
 * '<S97>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Voltage Measurement'
 * '<S98>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Voltage Measurement1'
 * '<S99>'  : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Current Measurement/Model'
 * '<S100>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Current Measurement1/Model'
 * '<S101>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Current Measurement2/Model'
 * '<S102>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Voltage Measurement/Model'
 * '<S103>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Measurements/Voltage Measurement1/Model'
 * '<S104>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Modes selection'
 * '<S105>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Rate limiter and  voltage calculation'
 * '<S106>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/d//dt = 0'
 * '<S107>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/d//dt ~0'
 * '<S108>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Modes selection/Detect Change'
 * '<S109>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Modes selection/Sample and Hold'
 * '<S110>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Modes selection/Saturation detection'
 * '<S111>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Modes selection/Sample and Hold/Model'
 * '<S112>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Modes selection/Saturation detection/Secondary rate limiter'
 * '<S113>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Modes selection/Saturation detection/Secondary rate limiter/Saturation Dynamic'
 * '<S114>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Rate limiter and  voltage calculation/Machine model'
 * '<S115>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Rate limiter and  voltage calculation/Primary rate limiter'
 * '<S116>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Rate limiter and  voltage calculation/Machine model/Discrete Derivative'
 * '<S117>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/Rate limiter and  voltage calculation/Primary rate limiter/Saturation Dynamic'
 * '<S118>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/d//dt = 0/Vab'
 * '<S119>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/d//dt = 0/Vac'
 * '<S120>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Rate limiter and reference voltage  calculation/d//dt = 0/Vbc'
 * '<S121>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_Brushless_DC/Voltage Measurement3/Model'
 * '<S122>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches'
 * '<S123>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Controlled Current Source'
 * '<S124>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Controlled Current Source1'
 * '<S125>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Controlled Current Source2'
 * '<S126>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Controlled Voltage Source'
 * '<S127>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Controlled Voltage Source1'
 * '<S128>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Current Measurement'
 * '<S129>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Current Measurement1'
 * '<S130>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Current Measurement2'
 * '<S131>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Id computation'
 * '<S132>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Limit detection'
 * '<S133>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction'
 * '<S134>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Voltage Measurement'
 * '<S135>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Voltage Measurement1'
 * '<S136>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Voltage Measurement3'
 * '<S137>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch1'
 * '<S138>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch2'
 * '<S139>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch3'
 * '<S140>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch4'
 * '<S141>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch5'
 * '<S142>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch6'
 * '<S143>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch1/Model'
 * '<S144>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch1/Model/Measurement list'
 * '<S145>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch2/Model'
 * '<S146>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch2/Model/Measurement list'
 * '<S147>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch3/Model'
 * '<S148>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch3/Model/Measurement list'
 * '<S149>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch4/Model'
 * '<S150>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch4/Model/Measurement list'
 * '<S151>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch5/Model'
 * '<S152>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch5/Model/Measurement list'
 * '<S153>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch6/Model'
 * '<S154>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Activation Switches/Ideal Switch6/Model/Measurement list'
 * '<S155>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Current Measurement/Model'
 * '<S156>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Current Measurement1/Model'
 * '<S157>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Current Measurement2/Model'
 * '<S158>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Id computation/Demux'
 * '<S159>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Id computation/Demux1'
 * '<S160>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Limit detection/S-R Flip-Flop'
 * '<S161>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction/dq0 to abc'
 * '<S162>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S163>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S164>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S165>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S166>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S167>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 * '<S168>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Voltage Measurement/Model'
 * '<S169>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Voltage Measurement1/Model'
 * '<S170>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_FOC/Voltage Measurement3/Model'
 * '<S171>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches'
 * '<S172>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Controlled Current Source'
 * '<S173>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Controlled Current Source1'
 * '<S174>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Controlled Current Source2'
 * '<S175>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Controlled Voltage Source'
 * '<S176>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Controlled Voltage Source1'
 * '<S177>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Current Measurement'
 * '<S178>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Current Measurement1'
 * '<S179>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Current Measurement2'
 * '<S180>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Id computation'
 * '<S181>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Limit detection'
 * '<S182>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction'
 * '<S183>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Voltage Measurement'
 * '<S184>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Voltage Measurement1'
 * '<S185>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Voltage Measurement3'
 * '<S186>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch1'
 * '<S187>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch2'
 * '<S188>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch3'
 * '<S189>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch4'
 * '<S190>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch5'
 * '<S191>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch6'
 * '<S192>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch1/Model'
 * '<S193>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch1/Model/Measurement list'
 * '<S194>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch2/Model'
 * '<S195>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch2/Model/Measurement list'
 * '<S196>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch3/Model'
 * '<S197>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch3/Model/Measurement list'
 * '<S198>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch4/Model'
 * '<S199>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch4/Model/Measurement list'
 * '<S200>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch5/Model'
 * '<S201>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch5/Model/Measurement list'
 * '<S202>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch6/Model'
 * '<S203>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Activation Switches/Ideal Switch6/Model/Measurement list'
 * '<S204>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Current Measurement/Model'
 * '<S205>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Current Measurement1/Model'
 * '<S206>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Current Measurement2/Model'
 * '<S207>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Id computation/Demux'
 * '<S208>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Id computation/Demux1'
 * '<S209>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Limit detection/S-R Flip-Flop'
 * '<S210>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction/dq0 to abc'
 * '<S211>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S212>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S213>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S214>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S215>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S216>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 * '<S217>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Voltage Measurement/Model'
 * '<S218>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Voltage Measurement1/Model'
 * '<S219>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_PMSM/Voltage Measurement3/Model'
 * '<S220>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Controlled Current Source'
 * '<S221>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Controlled Voltage Source'
 * '<S222>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Controlled Voltage Source1'
 * '<S223>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Controlled Voltage Source2'
 * '<S224>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Current Measurement'
 * '<S225>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Current Measurement1'
 * '<S226>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Current Measurement2'
 * '<S227>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Voltage Measurement'
 * '<S228>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Current Measurement/Model'
 * '<S229>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Current Measurement1/Model'
 * '<S230>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Current Measurement2/Model'
 * '<S231>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_SVM/Voltage Measurement/Model'
 * '<S232>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches'
 * '<S233>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Controlled Current Source'
 * '<S234>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Controlled Current Source1'
 * '<S235>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Controlled Current Source2'
 * '<S236>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Controlled Voltage Source'
 * '<S237>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Controlled Voltage Source1'
 * '<S238>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Controlled Voltage Source2'
 * '<S239>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Current Measurement'
 * '<S240>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Current Measurement1'
 * '<S241>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Current Measurement2'
 * '<S242>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Id computation'
 * '<S243>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Limit detection'
 * '<S244>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/On voltage'
 * '<S245>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction'
 * '<S246>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Voltage Measurement'
 * '<S247>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Voltage Measurement1'
 * '<S248>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Voltage Measurement3'
 * '<S249>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch1'
 * '<S250>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch2'
 * '<S251>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch3'
 * '<S252>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch4'
 * '<S253>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch5'
 * '<S254>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch6'
 * '<S255>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch1/Model'
 * '<S256>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch1/Model/Measurement list'
 * '<S257>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch2/Model'
 * '<S258>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch2/Model/Measurement list'
 * '<S259>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch3/Model'
 * '<S260>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch3/Model/Measurement list'
 * '<S261>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch4/Model'
 * '<S262>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch4/Model/Measurement list'
 * '<S263>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch5/Model'
 * '<S264>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch5/Model/Measurement list'
 * '<S265>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch6/Model'
 * '<S266>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Activation Switches/Ideal Switch6/Model/Measurement list'
 * '<S267>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Current Measurement/Model'
 * '<S268>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Current Measurement1/Model'
 * '<S269>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Current Measurement2/Model'
 * '<S270>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Id computation/Demux'
 * '<S271>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Id computation/Demux1'
 * '<S272>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Limit detection/S-R Flip-Flop'
 * '<S273>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/On voltage/Compare To Zero'
 * '<S274>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/On voltage/Compare To Zero1'
 * '<S275>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction/dq0 to abc'
 * '<S276>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction/dq0 to abc/Alpha-Beta-Zero to abc'
 * '<S277>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero'
 * '<S278>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant'
 * '<S279>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Compare To Constant1'
 * '<S280>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem - pi//2 delay'
 * '<S281>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Output Resistance correction/dq0 to abc/dq0 to Alpha-Beta-Zero/Subsystem1'
 * '<S282>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Voltage Measurement/Model'
 * '<S283>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Voltage Measurement1/Model'
 * '<S284>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Average_WFSM/Voltage Measurement3/Model'
 * '<S285>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Detailed/Detailed'
 * '<S286>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Detailed/Detailed/Model'
 * '<S287>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Detailed/Detailed/Model/Tail'
 * '<S288>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Detailed/Detailed/Model/Vf 1'
 * '<S289>' : 'ac6_example/PM Synchronous Motor Drive/Three-phase Inverter/Detailed/Detailed/Model/Tail/y=f(t)'
 * '<S290>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Average_3ph'
 * '<S291>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Average_5ph'
 * '<S292>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph'
 * '<S293>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph'
 * '<S294>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Average_3ph/Current Regulator'
 * '<S295>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Average_3ph/DQ-ABC'
 * '<S296>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Average_5ph/Current Regulator'
 * '<S297>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Average_5ph/DQ-ABCDE'
 * '<S298>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Current Regulator'
 * '<S299>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/DQ-ABC'
 * '<S300>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control'
 * '<S301>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 1-2'
 * '<S302>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 3-4'
 * '<S303>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 5-6'
 * '<S304>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 1-2/S-R Flip-Flop1'
 * '<S305>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 1-2/Subsystem1'
 * '<S306>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 1-2/Subsystem3'
 * '<S307>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 3-4/S-R Flip-Flop1'
 * '<S308>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 3-4/Subsystem1'
 * '<S309>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 3-4/Subsystem3'
 * '<S310>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 5-6/S-R Flip-Flop1'
 * '<S311>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 5-6/Subsystem1'
 * '<S312>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_3ph/Switching control/Control 5-6/Subsystem3'
 * '<S313>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Current Regulator'
 * '<S314>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/DQ-ABCDE'
 * '<S315>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control'
 * '<S316>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 1-2'
 * '<S317>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 3-4'
 * '<S318>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 5-6'
 * '<S319>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 7-8'
 * '<S320>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 9-10'
 * '<S321>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 1-2/S-R Flip-Flop1'
 * '<S322>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 1-2/Subsystem1'
 * '<S323>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 1-2/Subsystem3'
 * '<S324>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 3-4/S-R Flip-Flop1'
 * '<S325>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 3-4/Subsystem1'
 * '<S326>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 3-4/Subsystem3'
 * '<S327>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 5-6/S-R Flip-Flop1'
 * '<S328>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 5-6/Subsystem1'
 * '<S329>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 5-6/Subsystem3'
 * '<S330>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 7-8/S-R Flip-Flop1'
 * '<S331>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 7-8/Subsystem1'
 * '<S332>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 7-8/Subsystem3'
 * '<S333>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 9-10/S-R Flip-Flop1'
 * '<S334>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 9-10/Subsystem1'
 * '<S335>' : 'ac6_example/PM Synchronous Motor Drive/VECT/Detailed_5ph/Switching control/Control 9-10/Subsystem3'
 * '<S336>' : 'ac6_example/powergui/EquivalentModel1'
 * '<S337>' : 'ac6_example/powergui/EquivalentModel1/Gates'
 * '<S338>' : 'ac6_example/powergui/EquivalentModel1/Sources'
 * '<S339>' : 'ac6_example/powergui/EquivalentModel1/Status'
 * '<S340>' : 'ac6_example/powergui/EquivalentModel1/Yout'
 */
#endif                                 /* RTW_HEADER_ac6_example_h_ */
