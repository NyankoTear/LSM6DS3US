/** TODO: 
 * 
 */

/** FIXME:
 * 
 */

#include "LSM6DS3US.h"

uint8_t UserTimeOut = 1;
SPI_HandleTypeDef Userhspi;

/** 
 * @brief  Configure SPI settings.
 * @note   None
 * @param  *hspi: Pointer to a SPI_HandleTypeDef structure that contains
 *                the configuration information for SPI module.
 * @retval None
 */
void USER_SPIConfiguration(SPI_HandleTypeDef *hspi, uint8_t SPITimeOut)
{
  if(hspi == NULL){
    _Error_Handler("NullSPIHandleTypeDef", 0);
  } else{
    Userhspi = *hspi;
  }
  
  UserTimeOut = SPITimeOut;
}

