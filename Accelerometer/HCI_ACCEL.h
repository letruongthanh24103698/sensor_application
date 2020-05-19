/*
 * HCI_ACCEL.h
 *
 *  Created on: April 29, 2020
 *      Author: Le Truong Thanh
 *      Purpose: Hardware Command Interface for ACCELEROMETER MMA8652
 *      Comment: Edit this file to communicate between APPLICATION and HARDWARE. Do not edit the APPLICAION Files. => for multiple MICROCONTROLLER
 *      First version for ORANGE DEV BOARD (RAK4200)
 *      Config Interrupt Handle for GPIO
 */

#ifndef SRC_HCI_ACCEL_H_
#define SRC_HCI_ACCEL_H_

#include <stdbool.h>
#include <stdint.h>
#include "main.h"

/*****************************************************************************************************************/
/*													MACROS DEFINITION											 */
/*****************************************************************************************************************/
#ifndef SDA
	#define SDA			GPIO_PIN_7
	#define SCL			GPIO_PIN_6
	#define I2CPORT		GPIOB
#endif
#define ID				0x1F

#define INT_PIN			GPIO_PIN_9
#define INT_PORT		GPIOA


/*****************************************************************************************************************/
/*													   DATA-STRUCTS												 */
/*****************************************************************************************************************/



/*****************************************************************************************************************/
/*											    Hardware Command Interface     									 */
/*****************************************************************************************************************/
void HCI_ACCEL_I2C_INIT(void);

void HCI_ACCEL_I2C_DEINIT(void);

void HCI_ACCEL_I2C_WRITE(uint16_t addr, uint16_t value);

void HCI_ACCEL_I2C_READ(uint16_t adr, uint8_t *buffer, uint16_t length);

uint8_t HCI_ACCEL_I2C_CHECK(uint16_t adr);

void HCI_ACCEL_GPIO_INIT(void);

void HCI_ACCEL_DELAYMS(uint32_t ms);


extern I2C_HandleTypeDef hi2c1;
#endif /*SRC_HCI_ACCEL_H_*/
