/** TODO: 
 * 
 */

/** FIXME:
 * 
 */

#include "LSM6DS3US.h"
#include <string.h>

static uint16_t UserDeviceAddress;
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
  
  UserDeviceAddress = DeviceAddress;
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


/**
 * @brief  Read register value from LSM6DS3US
 * @note   
 * @param  RegisterAddress: Register address which you want to read.
 * @param  *pReceiveData: Pointer to receive data buffer.
 * @param  ReceiveDataSize: Amount of receive data to be received.
 * @retval HAL status
 */
HAL_StatusTypeDef USER_LSM6DS3US_ReadRegisterData(uint8_t RegisterAddress, uint8_t *pReceiveData, uint16_t ReceiveDataSize)
{
  HAL_StatusTypeDef StatusValue;

  //  Transmit the register address to set a start reading address.
  StatusValue = HAL_I2C_Master_Transmit(&Userhi2c, UserDeviceAddress, &RegisterAddress, 1, UserI2CTimeOut);
  if(StatusValue != HAL_OK){
    return StatusValue;
  }

  //  Receive the data from LSM6DS3US.
  StatusValue = HAL_I2C_Master_Receive(&Userhi2c, UserDeviceAddress, pReceiveData, ReceiveDataSize, UserI2CTimeOut);
  return StatusValue;
}

/**
 * @brief  Write register value to LSM6DS3US
 * @note   
 * @param  RegisterAddress: Register address which you want to write.
 * @param  *pTransmitData: Pointer to transmit data buffer.
 * @param  TransmitDataSize: Amount of transmit data to be transmited.
 * @retval HAL status.
 */
HAL_StatusTypeDef USER_LSM6DS3US_WriteRegisterData(uint8_t RegisterAddress, uint8_t *pTransmitData, uint16_t TransmitDataSize)
{
  HAL_StatusTypeDef StatusValue;
  uint8_t *pDataPayload;

  //  Allocate a payload buffer to store a register address and the data.
  pDataPayload = (uint8_t *)malloc(sizeof(uint8_t) * (TransmitDataSize + 1));

  //  Copy the register address value and the content of the pTransmitData.
  pDataPayload[0] = RegisterAddress;
  memcpy(pDataPayload + 1, pTransmitData, TransmitDataSize);

  //  Transmit the data to LSM6DS3US.
  StatusValue = HAL_I2C_Master_Transmit(&Userhi2c, UserDeviceAddress, pDataPayload, TransmitDataSize + 1, UserI2CTimeOut);
  if(StatusValue != HAL_OK){
    free(pDataPayload);
    return StatusValue;
  }

  free(pDataPayload);
  return StatusValue;
}

/**
 * @brief  Use the provided data byte to perform a bit-wise OR operation on the addressed register contents.
 * @note   
 * @param  RegisterAddress: Register address which you want to use the bit-wise OR operation.
 * @param  *pTransmitData: Pointer to transmit data buffer.
 * @param  TransmitDataSize: Amount of transmit data to be transmited.
 * @retval HAL status.
 */
HAL_StatusTypeDef USER_LSM6DS3US_BitFieldSet(uint8_t RegisterAddress, uint8_t *pTransmitData, uint16_t TransmitDataSize)
{
  HAL_StatusTypeDef StatusValue;
  uint8_t *pDataPayload;
  uint16_t i;

  //  Allocate a payload buffer to store a register address and the data.
  pDataPayload = (uint8_t *)malloc(sizeof(uint8_t) * TransmitDataSize);

  //  Read the content of the register.
  StatusValue = USER_LSM6DS3US_ReadRegisterData(RegisterAddress, pDataPayload, TransmitDataSize);
  if(StatusValue != HAL_OK){
    free(pDataPayload);  
    return StatusValue;
  }

  //  OR to the contents of the pDataPayload.
  for(i=0; i<TransmitDataSize; i++){
    pDataPayload[i] |= pTransmitData[i];
  }

  //  Write register value to LSM6DS3US.
  StatusValue = USER_LSM6DS3US_WriteRegisterData(RegisterAddress, pDataPayload, TransmitDataSize);
  if(StatusValue != HAL_OK){
    free(pDataPayload);  
    return StatusValue;
  }

  free(pDataPayload);
  return StatusValue;
}

/**
 * @brief  Use the provided data byte to perform a bit-wise NOTAND operation on the addressed register contents.
 * @note   
 * @param  RegisterAddress: Register address which you want to use the bit-wise NOTAND operation.
 * @param  *pTransmitData: Pointer to transmit data buffer.
 * @param  TransmitDataSize: Amount of transmit data to be transmited.
 * @retval HAL status.
 */
HAL_StatusTypeDef USER_LSM6DS3US_BitFieldClear(uint8_t RegisterAddress, uint8_t *pTransmitData, uint16_t TransmitDataSize)
{
  HAL_StatusTypeDef StatusValue;
  uint8_t *pDataPayload;
  uint16_t i;

  //  Allocate a payload buffer to store a register address and the data.
  pDataPayload = (uint8_t *)malloc(sizeof(uint8_t) * TransmitDataSize);

  //  Read the content of the register.
  StatusValue = USER_LSM6DS3US_ReadRegisterData(RegisterAddress, pDataPayload, TransmitDataSize);
  if(StatusValue != HAL_OK){
    free(pDataPayload);  
    return StatusValue;
  }

  //  NAND to the contents of the pDataPayload.
  for(i=0; i<TransmitDataSize; i++){
    pDataPayload[i] &= ~pTransmitData[i];
  }

  //  Write register value to LSM6DS3US.
  StatusValue = USER_LSM6DS3US_WriteRegisterData(RegisterAddress, pDataPayload, TransmitDataSize);
  if(StatusValue != HAL_OK){
    free(pDataPayload);  
    return StatusValue;
  }
  
  free(pDataPayload);
  return StatusValue;
}

/**
 * @brief  Read sensor ID(Sensor ID value is 0x69).
 * @note   Before you use this function, must set the I2C device address first(USER_I2CConfiguration function).
 * @retval LSM6DS3US status.
 */
LSM6DS3US_StatusTypeDef USER_LSM6DS3US_CheckSensorID(void)
{
  HAL_StatusTypeDef StatusValue;
  uint8_t SensorID = 0x00;

  StatusValue = USER_LSM6DS3US_ReadRegisterData(WHO_AM_I, &SensorID, 1);
  if(StatusValue != HAL_OK){
    return LSM6DS3US_ERR;
  }

  if(SensorID == WHO_AM_I_ID){
    return LSM6DS3US_OK;
  } else{
    return LSM6DS3US_ERR;
  }
}