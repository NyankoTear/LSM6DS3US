/** TODO: 
 * 
 */

/** FIXME:
 * 
 */

#include "LSM6DS3US.h"

uint32_t UserI2CTimeOut = 1;
uint32_t UserSPITimeOut = 1;

I2C_HandleTypeDef Userhi2c;
SPI_HandleTypeDef Userhspi;

/**
 * @brief  Configure I2C settings.
 * @note   None
 * @param  *hi2c: Pointer to a I2C_HandleTypeDef structure that contains
 *                the configuration information for I2C module.
 * @param  DeviceAddress: Specifies the slave device address to communicate with.
 * @param  I2CTimeOut: I2C timeout duration.
 * @retval None
 */
void USER_I2CConfiguration(I2C_HandleTypeDef *hi2c, uint16_t DeviceAddress, uint32_t I2CTimeOut)
{
  if(hi2c == NULL){
    _Error_Handler("NullI2CHandleTypeDef", 0);
  } else{
    Userhi2c = *hi2c;
  }
  
  UserI2CTimeOut = I2CTimeOut;
}

/**
 * @brief  Configure SPI settings.
 * @note   None
 * @param  *hspi: Pointer to a SPI_HandleTypeDef structure that contains
 *                the configuration information for SPI module.
 * @param  SPITimeOut: SPI timeout duration.
 * @retval None
 */
void USER_SPIConfiguration(SPI_HandleTypeDef *hspi, uint32_t SPITimeOut)
{
  if(hspi == NULL){
    _Error_Handler("NullSPIHandleTypeDef", 0);
  } else{
    Userhspi = *hspi;
  }
  
  UserSPITimeOut = SPITimeOut;
}
