/** TODO: 
 * Release:
 * Double check register map
 * Double check register definitions
 * Make development branch(Make register offset definition)
 */

/** FIXME:
 * 
 */

#ifndef __LSM6DS3US__
#define __LSM6DS3US__

#define USE_STATUS_REG

#include "main.h"
#include "stdlib.h"
#include "stm32l0xx_hal_spi.h"
#include "stm32l0xx_hal_i2c.h"

/**
 * @brief  LSM6DS3US status structures definition
 */
typedef enum{
  LSM6DS3US_OK  = 0x00U, 
  LSM6DS3US_ERR = 0x01U
} LSM6DS3US_StatusTypeDef;

/** @defgroup	LSM6DS3US SPI CS(NSS) pin definition
  * @{
  */
#define LSM6DS3US_NSS_LOW   HAL_GPIO_WritePin(LSM6DS3US_NSS_GPIO_Port, LSM6DS3US_NSS_Pin, GPIO_PIN_RESET)
#define LSM6DS3US_NSS_HIGH  HAL_GPIO_WritePin(LSM6DS3US_NSS_GPIO_Port, LSM6DS3US_NSS_Pin, GPIO_PIN_SET)
/**
  * @}
  */

/** @defgroup	LSM6DS3US register address map definition
  * @{
  */
#define FUNC_CFG_ACCESS         0x01
#define SENSOR_SYNC_TIME_FRAME  0x04
#define FIFO_CTRL1              0x06
#define FIFO_CTRL2              0x07
#define FIFO_CTRL3              0x08
#define FIFO_CTRL4              0x09
#define FIFO_CTRL5              0x0A
#define ORIENT_CFG_G            0x0B
#define INT1_CTRL               0x0D
#define INT2_CTRL               0x0E
#define WHO_AM_I                0x0F
#define CTRL1_XL                0x10
#define CTRL2_G                 0x11
#define CTRL3_C                 0x12
#define CTRL4_C                 0x13
#define CTRL5_C                 0x14
#define CTRL6_C                 0x15
#define CTRL7_G                 0x16
#define CTRL8_XL                0x17
#define CTRL9_XL                0x18
#define CTRL10_C                0x19
#define MASTER_CONFIG           0x1A
#define WAKE_UP_SRC             0x1B
#define TAP_SRC                 0x1C
#define D6D_SRC                 0x1D

#if defined(USE_STATUS_REG)
  #define STATUS_REG      0x1E
#else
  #define STATUS_SPI_Aux  0x1E
#endif

#define OUT_TEMP_L        0x20
#define OUT_TEMP_H        0x21
#define OUTX_L_G          0x22
#define OUTX_H_G          0x23
#define OUTY_L_G          0x24
#define OUTY_H_G          0x25
#define OUTZ_L_G          0x26
#define OUTZ_H_G          0x27
#define OUTX_L_XL         0x28
#define OUTX_H_XL         0x29
#define OUTY_L_XL         0x2A
#define OUTY_H_XL         0x2B
#define OUTZ_L_XL         0x2C
#define OUTZ_H_XL         0x2D
#define SENSORHUB1_REG    0x2E
#define SENSORHUB2_REG    0x2F
#define SENSORHUB3_REG    0x30
#define SENSORHUB4_REG    0x31
#define SENSORHUB5_REG    0x32
#define SENSORHUB6_REG    0x33
#define SENSORHUB7_REG    0x34
#define SENSORHUB8_REG    0x35
#define SENSORHUB9_REG    0x36
#define SENSORHUB10_REG   0x37
#define SENSORHUB11_REG   0x38
#define SENSORHUB12_REG   0x39
#define FIFO_STATUS1      0x3A
#define FIFO_STATUS2      0x3B
#define FIFO_STATUS3      0x3C
#define FIFO_STATUS4      0x3D
#define FIFO_DATA_OUT_L   0x3E
#define FIFO_DATA_OUT_H   0x3F
#define TIMESTAMP0_REG    0x40
#define TIMESTAMP1_REG    0x41
#define TIMESTAMP2_REG    0x42
#define STEP_TIMESTAMP_L  0x49
#define STEP_TIMESTAMP_H  0x4A
#define STEP_COUNTER_L    0x4B
#define STEP_COUNTER_H    0x4C
#define SENSORHUB13_REG   0x4D
#define SENSORHUB14_REG   0x4E
#define SENSORHUB15_REG   0x4F
#define SENSORHUB16_REG   0x50
#define SENSORHUB17_REG   0x51
#define SENSORHUB18_REG   0x52
#define FUNC_SRC          0x53
#define TAP_CFG           0x58
#define TAP_THS_6D        0x59
#define INT_DUR2          0x5A
#define WAKE_UP_THS       0x5B
#define WAKE_UP_DUR       0x5C
#define FREE_FALL         0x5D
#define MD1_CFG           0x5E
#define MD2_CFG           0x5F
#define OUT_MAG_RAW_X_L   0x66
#define OUT_MAG_RAW_X_H   0x67
#define OUT_MAG_RAW_Y_L   0x68
#define OUT_MAG_RAW_Y_H   0x69
#define OUT_MAG_RAW_Z_L   0x6A
#define OUT_MAG_RAW_Z_H   0x6B
#define CTRL_SPIAux       0x70
/**
  * @}
  */

/** @defgroup	LSM6DS3US enable embedded functions register definition
  * @{
  */
#define FUNC_CFG_ACCESS_FUNC_CFG_EN 0x80
/**
  * @}
  */

/** @defgroup	LSM6DS3US FIFO control register 2 definition
  * @{
  */
#define FIFO_CTRL2_TIMER_PEDO_FIFO_EN    0x80
#define FIFO_CTRL2_TIMER_PEDO_FIFO_DRDY  0x40
/**
  * @}
  */

/** @defgroup	LSM6DS3US FIFO control register 3 definition
  * @{
  */
#define FIFO_CTRL3_DEC_FIFO_GYRO2  0x20
#define FIFO_CTRL3_DEC_FIFO_GYRO1  0x10
#define FIFO_CTRL3_DEC_FIFO_GYRO0  0x08
#define FIFO_CTRL3_DEC_FIFO_XL2    0x04
#define FIFO_CTRL3_DEC_FIFO_XL1    0x02
#define FIFO_CTRL3_DEC_FIFO_XL0    0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US FIFO control register 4 definition
  * @{
  */
#define FIFO_CTRL4_ONLY_HIGH_DATA  0x40
#define FIFO_CTRL4_DEC_DS4_FIFO2   0x02
#define FIFO_CTRL4_DEC_DS4_FIFO1   0x01
#define FIFO_CTRL4_DEC_DS4_FIFO0   0x08
#define FIFO_CTRL4_DEC_DS3_FIFO2   0x04
#define FIFO_CTRL4_DEC_DS3_FIFO1   0x02
#define FIFO_CTRL4_DEC_DS3_FIFO0   0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US FIFO control register 5 definition
  * @{
  */
#define FIFO_CTRL5_ODR_FIFO_3  0x40
#define FIFO_CTRL5_ODR_FIFO_2  0x20
#define FIFO_CTRL5_ODR_FIFO_1  0x10
#define FIFO_CTRL5_ODR_FIFO_0  0x08
#define FIFO_CTRL5_ODR_MODE_2  0x04
#define FIFO_CTRL5_ODR_MODE_1  0x02
#define FIFO_CTRL5_ODR_MODE_0  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US angular rate sensor sign and orientation register definition
  * @{
  */
#define ORIENT_CFG_G_SignX_G   0x20
#define ORIENT_CFG_G_SignY_G   0x10
#define ORIENT_CFG_G_SignZ_G   0x08
#define ORIENT_CFG_G_Oreient_2 0x04
#define ORIENT_CFG_G_Oreient_1 0x02
#define ORIENT_CFG_G_Oreient_0 0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US INT1 pad control register definition
  * @{
  */
#define INT1_CTRL_INT1_STEP_DETECTOR  0x80
#define INT1_CTRL_INT1_SIGN_MOT       0x40
#define INT1_CTRL_INT1_FULL_FLAG      0x20
#define INT1_CTRL_INT1_FIFO_OVR       0x10
#define INT1_CTRL_INT1_FTH            0x08
#define INT1_CTRL_INT1_BOOT           0x04
#define INT1_CTRL_INT1_DRDY_G         0x02
#define INT1_CTRL_INT1_DRDY_XL        0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US INT2 pad control register definition
  * @{
  */
#define INT2_CTRL_INT2_STEP_DELTA     0x80
#define INT2_CTRL_INT2_STEP_COUNT_OV  0x40
#define INT2_CTRL_INT2_FULL_FLAG      0x20
#define INT2_CTRL_INT2_FIFO_OVR       0x10
#define INT2_CTRL_INT2_FTH            0x08
#define INT2_CTRL_INT2_DRDY_TEMP      0x04
#define INT2_CTRL_INT2_DRDY_G         0x02
#define INT2_CTRL_INT2_DRDY_XL        0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US WHO_AM_I register definition
  * @{
  */
#define WHO_AM_I_ID  0x69
/**
  * @}
  */

/** @defgroup	LSM6DS3US linear acceleration sensor control register 1 definition
  * @{
  */
#define CTRL1_XL_ODR_XL3 0x80
#define CTRL1_XL_ODR_XL2 0x40
#define CTRL1_XL_ODR_XL1 0x20
#define CTRL1_XL_ODR_XL0 0x10
#define CTRL1_XL_FS_XL1  0x08
#define CTRL1_XL_FS_XL0  0x04
#define CTRL1_XL_BW_XL1  0x02
#define CTRL1_XL_BW_XL0  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US angular rate sensor control register 2 definition
  * @{
  */
#define CTRL2_G_ODR_G3  0x80
#define CTRL2_G_ODR_G2  0x40
#define CTRL2_G_ODR_G1  0x20
#define CTRL2_G_ODR_G0  0x10
#define CTRL2_G_FS_G1   0x08
#define CTRL2_G_FS_G0   0x04
#define CTRL2_G_FS_125  0x02
/**
  * @}
  */

/** @defgroup	LSM6DS3US control register 3 definition
  * @{
  */
#define CTRL3_C_BOOT      0x80
#define CTRL3_C_BDU       0x40
#define CTRL3_C_H_LACTIVE 0x20
#define CTRL3_C_PP_OD     0x10
#define CTRL3_C_SIM       0x08
#define CTRL3_C_IF_INC    0x04
#define CTRL3_C_BLE       0x02
#define CTRL3_C_SW_RESET  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US control register 4 definition
  * @{
  */
#define CTRL4_C_XL_BW_SCAL_ODR  0x80
#define CTRL4_C_SLEEP_G         0x40
#define CTRL4_C_INT2_on_INT1    0x20
#define CTRL4_C_FIFO_TEMP_EN    0x10
#define CTRL4_C_DRDY_MASK       0x08
#define CTRL4_C_I2C_disable     0x04
#define CTRL4_C_3_3kHz_ODR      0x02
#define CTRL4_C_STOP_ON_FTH     0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US control register 5 definition
  * @{
  */
#define CTRL5_C_ROUNDING2 0x80
#define CTRL5_C_ROUNDING1 0x40
#define CTRL5_C_ROUNDING0 0x20
#define CTRL5_C_ST1_G     0x08
#define CTRL5_C_ST0_G     0x04
#define CTRL5_C_ST1_XL    0x02
#define CTRL5_C_ST0_XL    0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US angular rate sensor control register 6 definition
  * @{
  */
#define CTRL6_C_TRIG_EN     0x80
#define CTRL6_C_LVLen       0x40
#define CTRL6_C_LVL2_EN     0x20
#define CTRL6_C_XL_HM_MODE  0x10
/**
  * @}
  */

/** @defgroup	LSM6DS3US angular rate sensor control register 7 definition
  * @{
  */
#define CTRL7_G_G_HM_MODE       0x80
#define CTRL7_G_HP_G_EN         0x40
#define CTRL7_G_HPCF_G1         0x20
#define CTRL7_G_HPCF_G0         0x10
#define CTRL7_G_HP_G_R_ST       0x08
#define CTRL7_G_ROUNDING_STATUS 0x04
/**
  * @}
  */

/** @defgroup	LSM6DS3US linear acceleration sensor control register 8 definition
  * @{
  */
#define CTRL8_XL_LPF2_XL_EN      0x80
#define CTRL8_XL_HPCF_XL1        0x40
#define CTRL8_XL_HPCF_XL0        0x20
#define CTRL8_XL_HP_SLOPE_XL_EN  0x04
#define CTRL8_XL_LOW_PASS_ON_6D  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US linear acceleration sensor control register 9 definition
  * @{
  */
#define CTRL9_XL_Zen_XL  0x20
#define CTRL9_XL_Yen_XL  0x10
#define CTRL9_XL_Xen_XL  0x08
#define CTRL9_XL_SOFT_EN 0x04
/**
  * @}
  */

/** @defgroup	LSM6DS3US control register 10 definition
  * @{
  */
#define CTRL10_C_Zen_G           0x20
#define CTRL10_C_Yen_G           0x10
#define CTRL10_C_Xen_G           0x08
#define CTRL10_C_FUNC_EN         0x04
#define CTRL10_C_PEDO_RST_STEP   0x02
#define CTRL10_C_SIGN_MOTION_EN  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US master configuration register definition
  * @{
  */
#define MASTER_CONFIG_DRDY_ON_INT1        0x80
#define MASTER_CONFIG_DATA_VALID_SEL_FIFO 0x40
#define MASTER_CONFIG_START_CONFIG        0x10
#define MASTER_CONFIG_PULL_UP_EN          0x08
#define MASTER_CONFIG_PASS_THROUGH_MODE   0x04
#define MASTER_CONFIG_IRON_EN             0x02
#define MASTER_CONFIG_MASTER_ON           0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US wake up interrupt source register definition
  * @{
  */
#define WAKE_UP_SRC_FF_IA           0x20
#define WAKE_UP_SRC_SLEEP_STATE_IA  0x10
#define WAKE_UP_SRC_WU_IA           0x08
#define WAKE_UP_SRC_X_WU            0x04
#define WAKE_UP_SRC_Y_WU            0x02
#define WAKE_UP_SRC_Z_WU            0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US tap source register definition
  * @{
  */
#define TAP_SRC_TAP_IA      0x40
#define TAP_SRC_SINGLE_TAP  0x20
#define TAP_SRC_DOUBLE_TAP  0x10
#define TAP_SRC_TAP_SIGN    0x08
#define TAP_SRC_X_TAP       0x04
#define TAP_SRC_Y_TAP       0x02
#define TAP_SRC_Z_TAP       0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US portrait, landscape, face-up and face-down source register definition
  * @{
  */
#define D6D_SRC_D6D_IA  0x40
#define D6D_SRC_ZH      0x20
#define D6D_SRC_ZL      0x10
#define D6D_SRC_YH      0x08
#define D6D_SRC_YL      0x04
#define D6D_SRC_XH      0x02
#define D6D_SRC_XL      0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US status register definition(The STATUS_REG register is read by the primary interface SPI or I2C)
  * @{
  */
#define STATUS_REG_TDA   0x04
#define STATUS_REG_GDA   0x02
#define STATUS_REG_XLDA  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US status register definition(The STATUS_SPIAux register is read by the auxiliary SPI)
  * @{
  */
#define STATUS_SPIAux_GTRO_SETTING  0x04
#define STATUS_SPIAux_GDA           0x02
/**
  * @}
  */

/** @defgroup	LSM6DS3US FIFO status control register definition
  * @{
  */
#define FIFO_STATUS2_FTH            0x80
#define FIFO_STATUS2_FIFO_OVER_RUN  0x40
#define FIFO_STATUS2_FIFO_FULL      0x20
#define FIFO_STATUS2_FIFO_EMPTY     0x10
/**
  * @}
  */

/** @defgroup	LSM6DS3US significant motion, tilt, step detector, hard/soft-iron and sensor hub interrupt source register definition
  * @{
  */
#define FUNC_SRC_STEP_COUNT_DELTA_IA   0x80
#define FUNC_SRC_SIGN_MOTION_IA        0x40
#define FUNC_SRC_TILT_IA               0x20
#define FUNC_SRC_STEP_DETECTED         0x10
#define FUNC_SRC_STEP_OVERFLOW         0x08
#define FUNC_SRC_SI_END_OP             0x02
#define FUNC_SRC_SENSOR_HUB_END_OP     0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US Timestamp, pedometer, tilt, filtering, and tap recognition functions configuration register definition
  * @{
  */
#define TAP_CFG_TIMER_EN    0x80
#define TAP_CFG_PEDO_EN     0x40
#define TAP_CFG_TILT_EN     0x20
#define TAP_CFG_SLOPE_FDS   0x10
#define TAP_CFG_TAP_X_EN    0x08
#define TAP_CFG_TAP_Y_EN    0x04
#define TAP_CFG_TAP_Z_EN    0x02
#define TAP_CFG_LIR         0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US portrait/landscape position and tap function htreshold register definition
  * @{
  */
#define TAP_THS_6D_D4D_EN      0x80
#define TAP_THS_6D_SIXD_THS_1  0x40
#define TAP_THS_6D_SIXD_THS_0  0x20
#define TAP_THS_6D_TAP_THS_4   0x10
#define TAP_THS_6D_TAP_THS_3   0x08
#define TAP_THS_6D_TAP_THS_2   0x04
#define TAP_THS_6D_TAP_THS_1   0x02
#define TAP_THS_6D_TAP_THS_0   0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US tap recongition function setting register definition
  * @{
  */
#define INT_DUR2_DUR3    0x80
#define INT_DUR2_DUR2    0x40
#define INT_DUR2_DUR1    0x20
#define INT_DUR2_DUR0    0x10
#define INT_DUR2_QUIET1  0x08
#define INT_DUR2_QUIET0  0x04
#define INT_DUR2_SHOCK1  0x02
#define INT_DUR2_SHOCK0  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US single and double-tap function threshold register definition
  * @{
  */
#define WAKE_UP_DUR_SINGLE_DOUBLE_TAP 0x80
#define WAKE_UP_DUR_INACTIVITY        0x40
#define WAKE_UP_DUR_WK_THS5           0x20
#define WAKE_UP_DUR_WK_THS4           0x10
#define WAKE_UP_DUR_WK_THS3           0x08
#define WAKE_UP_DUR_WK_THS2           0x04
#define WAKE_UP_DUR_WK_THS1           0x02
#define WAKE_UP_DUR_WK_THS0           0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US free-gall function duration setting register definition
  * @{
  */
#define FREE_FALL_FF_DUR4 0x80
#define FREE_FALL_FF_FUR3 0x40
#define FREE_FALL_FF_DUR2 0x20
#define FREE_FALL_FF_DUR1 0x10
#define FREE_FALL_FF_DUR0 0x08
#define FREE_FALL_FF_THS2 0x04
#define FREE_FALL_FF_THS1 0x02
#define FREE_FALL_FF_THS0 0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US functions routing on INT1 register definition
  * @{
  */
#define MD1_CFG_INT1_INACT_STATE  0x80
#define MD1_CFG_INT1_SINGLE_TAP   0x40
#define MD1_CFG_INT1_WU           0x20
#define MD1_CFG_INT1_FF           0x10
#define MD1_CFG_INT1_DOUBLE_TAP   0x08
#define MD1_CFG_INT1_6D           0x04
#define MD1_CFG_INT1_TILT         0x02
#define MD1_CFG_INT1_TIMER        0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US functinos routing on INT2 register definition
  * @{
  */
#define MD2_CFG_INT2_INACT_STATE  0x80
#define MD2_CFG_INT2_SINGLE_TAP   0x40
#define MD2_CFG_INT2_WU           0x20
#define MD2_CFG_INT2_FF           0x10
#define MD2_CFG_INT2_DOUBLE_TAP   0x08
#define MD2_CFG_INT2_6D           0x04
#define MD2_CFG_INT2_TILT         0x02
#define MD2_CFG_INT2_IRON         0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US CTRL_SPIAux register definition
  * @{
  */
#define CTRL_SPIAux_BLE_SPI2        0x80
#define CTRL_SPIAux_SPI_READ_EN     0x20
#define CTRL_SPIAux_3_3KHz_SPI2_EN  0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US embedded functions registers definition
  * @{
  */
#define SLV0_ADD                    0x02
#define SLV0_SUBADD                 0x03
#define SLAVE0_CONFIG               0x04
#define SLV1_ADD                    0x05
#define SLV1_SUBADD                 0x06
#define SLAVE1_CONFIG               0x07
#define SLV2_ADD                    0x08
#define SLV2_SUBADD                 0x09
#define SLAVE2_CONFIG               0x0A
#define SLV3_ADD                    0x0B
#define SLV3_SUBADD                 0x0C
#define SLAVE3_CONFIG               0x0D
#define DATAWRITE_SRC_MODE_SUB_SLV0 0x0E
#define PEDO_THS_REG                0x0F
#define SM_THS                      0x13
#define PEDO_DB_REG                 0x14
#define STEP_COUNT_DELTA            0x15
#define MAG_SI_XX                   0x24
#define MAG_SI_XY                   0x25
#define MAG_SI_XZ                   0x26
#define MAG_SI_YX                   0x27
#define MAG_SI_YY                   0x28
#define MAG_SI_YZ                   0x29
#define MAG_SI_ZX                   0x2A
#define MAG_SI_ZY                   0x2B
#define MAG_SI_ZZ                   0x2C
#define MAG_OFFX_L                  0x2D
#define MAG_OFFX_H                  0x2E
#define MAG_OFFY_L                  0x2F
#define MAG_OFFY_H                  0x30
#define MAG_OFFZ_L                  0x31
#define MAG_OFFZ_H                  0x32
/**
  * @}
  */

/** @defgroup	LSM6DS3US I2C slave address of the first ecternal sensor(Sensor 1) register definition
  * @{
  */
#define SLV0_ADD_Slave0_add6 0x80
#define SLV0_ADD_Slave0_add5 0x40
#define SLV0_ADD_Slave0_add4 0x20
#define SLV0_ADD_Slave0_add3 0x10
#define SLV0_ADD_Slave0_add2 0x08
#define SLV0_ADD_Slave0_add1 0x04
#define SLV0_ADD_Slave0_add0 0x02
#define SLV0_ADD_rw_0        0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US first external sensor(Sensor 1) configuration and sensor hub settings register definition
  * @{
  */
#define SLAVE0_CONFIG_Slave0_rate1  0x80
#define SLAVE0_CONFIG_Slave0_rate0  0x40
#define SLAVE0_CONFIG_Aux_sens_on1  0x20
#define SLAVE0_CONFIG_Aux_sens_on0  0x10
#define SLAVE0_CONFIG_Src_mode      0x08
#define SLAVE0_CONFIG_Slave0_numop2 0x04
#define SLAVE0_CONFIG_Slave0_numop1 0x02
#define SLAVE0_CONFIG_Slave0_numop0 0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US I2C alve address of the second external sensor(Sensor 2) register definition
  * @{
  */
#define SLV1_ADD_Slave1_add6 0x80
#define SLV1_ADD_Slave1_add5 0x40
#define SLV1_ADD_Slave1_add4 0x20
#define SLV1_ADD_Slave1_add3 0x10
#define SLV1_ADD_Slave1_add2 0x08
#define SLV1_ADD_Slave1_add1 0x04
#define SLV1_ADD_Slave1_add0 0x02
#define SLV1_ADD_r_1         0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US second external sensor(Sensor 2) configuration register definition
  * @{
  */
#define SLAVE1_CONFIG_Slave1_rate1  0x80
#define SLAVE1_CONFIG_Slave1_rate0  0x40
#define SLAVE1_CONFIG_Slave1_numop2 0x04
#define SLAVE1_CONFIG_Slave1_numop1 0x02
#define SLAVE1_CONFIG_Slave1_numop0 0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US I2C slave address of the third external sensor(Sensor 3) register definition
  * @{
  */
#define SLV2_ADD_Slave2_add6 0x80
#define SLV2_ADD_Slave2_add5 0x40
#define SLV2_ADD_Slave2_add4 0x20
#define SLV2_ADD_Slave2_add3 0x10
#define SLV2_ADD_Slave2_add2 0x08
#define SLV2_ADD_Slave2_add1 0x04
#define SLV2_ADD_Slave2_add0 0x02
#define SLV2_ADD_r_2         0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US third external senfor(Sensor 3) configuration register definition
  * @{
  */
#define SLAVE2_CONFIG_Slave2_rate1  0x80
#define SLAVE2_CONFIG_Slave2_rate0  0x40
#define SLAVE2_CONFIG_Slave2_numop2 0x04
#define SLAVE2_CONFIG_Slave2_numop1 0x02
#define SLAVE2_CONFIG_Slave2_numop0 0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US I2C slave address of the fourth external sensor(Sensor 4) register definition
  * @{
  */
#define SLV3_ADD_Slave3_add6 0x80
#define SLV3_ADD_Slave3_add5 0x40
#define SLV3_ADD_Slave3_add4 0x20
#define SLV3_ADD_Slave3_add3 0x10
#define SLV3_ADD_Slave3_add2 0x08
#define SLV3_ADD_Slave3_add1 0x04
#define SLV3_ADD_Slave3_add0 0x02
#define SLV3_ADD_r_3         0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US fourth external sensor(Sensor 4) configuration register definition
  * @{
  */
#define SLAVE3_CONFIG_Slave3_rate1  0x80
#define SLAVE3_CONFIG_Slave3_rate0  0x40
#define SLAVE3_CONFIG_Slave3_numop2 0x04
#define SLAVE3_CONFIG_Slave3_numop1 0x02
#define SLAVE3_CONFIG_Slave3_numop0 0x01
/**
  * @}
  */

/** @defgroup	LSM6DS3US pedometer debounce configuration register definition
  * @{
  */
#define PEDO_DEB_REG_DEB_TIME4 0x80
#define PEDO_DEB_REG_DEB_TIME3 0x40
#define PEDO_DEB_REG_DEB_TIME2 0x20
#define PEDO_DEB_REG_DEB_TIME1 0x10
#define PEDO_DEB_REG_DEB_TIME0 0x08
#define PEDO_DEB_REG_DEB_STEP2 0x04
#define PEDO_DEB_REG_DEB_STEP1 0x02
#define PEDO_DEB_REG_DEB_STEP0 0x01
/**
  * @}
  */

/** @defgroup	Interface I/O configuration function definition
  * @{
  */
void USER_I2CConfiguration(I2C_HandleTypeDef *hi2c, uint16_t DeviceAddress, uint32_t I2CTimeOut);
void USER_SPIConfiguration(SPI_HandleTypeDef *hspi, uint32_t SPITimeOut);
/**
  * @}
  */

/**
 * @defgroup Register control function definition
 * @{
 */
HAL_StatusTypeDef USER_LSM6DS3US_ReadRegisterData(uint8_t RegisterAddress, uint8_t *pReceiveData, uint16_t ReceiveDataSize);
HAL_StatusTypeDef USER_LSM6DS3US_WriteRegisterData(uint8_t RegisterAddress, uint8_t *pTransmitData, uint16_t TransmitDataSize);
HAL_StatusTypeDef USER_LSM6DS3US_BitFieldSet(uint8_t RegisterAddress, uint8_t *pTransmitData, uint16_t TransmitDataSize);
HAL_StatusTypeDef USER_LSM6DS3US_BitFieldClear(uint8_t RegisterAddress, uint8_t *pTransmitData, uint16_t TransmitDataSize);
/**
 * @}
 */

LSM6DS3US_StatusTypeDef USER_LSM6DS3US_CheckSensorID(void);

#endif /* __LSM6DS3US__ */
