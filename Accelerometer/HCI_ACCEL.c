/*
 * HCI_ACCEL.c
 *
 *  Created on: April 29, 2020
 *      Author: Le Truong Thanh
 *      Purpose: Hardware Command Interface for ACCELEROMETER MMA8652
 *      Comment: Edit this file to communicate between APPLICATION and HARDWARE. Do not edit the APPLICAION Files. => for multiple MICROCONTROLLER
 *      First version for ORANGE DEV BOARD (RAK4200)
 */

#include "HCI_ACCEL.h"
#include "main.h"

/*****************************************************************************************************************/
/*													GLOBAL VARIABLES											 */
/*****************************************************************************************************************/
I2C_HandleTypeDef hi2c1;

/*****************************************************************************************************************/
/*													PRIVATE FUNCTION											 */
/*****************************************************************************************************************/

/*****************************************************************************************************************/
/*													PRIVATE VARIABLES											 */
/*****************************************************************************************************************/


/*****************************************************************************************************************/
/*													FUNCTION IMPLEMENT									 	 	 */
/*****************************************************************************************************************/
void HCI_ACCEL_I2C_INIT()
{
	hi2c1.Instance = I2C1;
	hi2c1.Init.Timing = 0x00303D5B;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	{
		Error_Handler();
	}
	/** Configure Analogue filter
	*/
	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		Error_Handler();
	}
	/** Configure Digital filter
	*/
	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
	{
		Error_Handler();
	}

	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* USER CODE BEGIN I2C1_MspInit 0 */

	/* USER CODE END I2C1_MspInit 0 */

	__HAL_RCC_GPIOB_CLK_ENABLE();
	/**I2C1 GPIO Configuration
	PB6     ------> I2C1_SCL
	PB7     ------> I2C1_SDA
	*/
	GPIO_InitStruct.Pin = SDA | SCL;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF1_I2C1;
	HAL_GPIO_Init(I2CPORT, &GPIO_InitStruct);

	/* I2C1 clock enable */
	__HAL_RCC_I2C1_CLK_ENABLE();
	/* USER CODE BEGIN I2C1_MspInit 1 */

	/* USER CODE END I2C1_MspInit 1 */
}

void HCI_ACCEL_I2C_DEINIT(void)
{
	/* Peripheral clock disable */
	__HAL_RCC_I2C1_CLK_DISABLE();

	/**I2C1 GPIO Configuration
	PB6     ------> I2C1_SCL
	PB7     ------> I2C1_SDA
	*/
	HAL_GPIO_DeInit(I2CPORT, SDA | SCL);
}

void HCI_ACCEL_I2C_WRITE(uint16_t adr, uint16_t value)
{
	HAL_I2C_Mem_Write(&hi2c1,ID,adr,I2C_MEMADD_SIZE_8BIT,&value,1,0xFFFF);
	HCI_ACCEL_DELAYMS(10);
}

void HCI_ACCEL_I2C_READ(uint16_t adr, uint8_t *buffer, uint16_t length)
{
	HAL_I2C_Mem_Read(&hi2c1,ID,adr,I2C_MEMADD_SIZE_8BIT,buffer,length,0xFFFF);
	HCI_ACCEL_DELAYMS(10);
}

uint8_t HCI_ACCEL_I2C_CHECK(uint16_t adr)
{
	uint8_t status=0;
	status = ( HAL_I2C_IsDeviceReady( &hi2c1, adr, 300, 4096 ) == HAL_OK )? 1:0;
	return status;
}

void HCI_ACCEL_GPIO_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin : PA9 */
	GPIO_InitStruct.Pin = INT_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(INT_PORT, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI4_15_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
}

void HCI_ACCEL_DELAYMS(uint32_t ms)
{
	HAL_Delay(ms);
}
