/** TODO: 
 * 
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

/** @defgroup	LSM6DS3US SPI CS(NSS) pin definition
  * @{
  */
#define LSM6DS3US_NSS_LOW	  HAL_GPIO_WritePin(LSM6DS3US_NSS_GPIO_Port, LSM6DS3US_NSS_Pin, GPIO_PIN_RESET)
#define LSM6DS3US_NSS_HIGH  HAL_GPIO_WritePin(ELSM6DS3US_NSS_GPIO_Port, LSM6DS3US_NSS_Pin, GPIO_PIN_SET)
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
#define WHO_AM_I  0x69
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


/** @defgroup	LSM6DS33 register address map definition
  * @{
  */
#define FUNC_CFG_ACCESS   0x01
#define FIFO_CTRL1        0x06
#define FIFO_CTRL2        0x07
#define FIFO_CTRL3        0x08
#define FIFO_CTRL4        0x09
#define FIFO_CTRL5        0x0A
#define ORIENT_CFG_F      0x0B
#define INT1_CTRL         0x0D
#define INT2_CTRL         0x0E
#define WHO_AM_I          0x0F
#define CTRL1_XL          0x10
#define CTRL2_G           0x11
#define CTRL3_C           0x12
#define CTRL4_C           0x13
#define CTRL5_C           0x14
#define CTRL6_C           0x15
#define CTRL7_G           0x16
#define CTRL8_XL          0x17
#define CTRL9_XL          0x18
#define CTRL10_C          0x19
#define WAKE_UP_SRC       0x1B
#define TAP_SRC           0x1C
#define D6D_SRC           0x1D

#if defined(USE_STATUS_REG)
  #define STATUS_REG        0x1E
#else
  #define STATUS_SPI_Aux    0x1E
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

void USER_SPIConfiguration(SPI_HandleTypeDef *hspi, uint8_t SPITimeOut);

#endif /* __LSM6DS3US__ */