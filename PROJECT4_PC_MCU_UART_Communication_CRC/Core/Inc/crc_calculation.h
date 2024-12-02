/*
 * crc_calculation.h
 *
 *  Created on: 27 Eki 2024
 *      Author: sezai
 */


#ifndef INC_CRC_CALCULATION_H_
#define INC_CRC_CALCULATION_H_

#include <stdint.h>  // uint16_t için gerekli
#include "stm32f4xx_hal.h"  // STM32 HAL kütüphanesi

unsigned char reflect(unsigned char n);
uint16_t crc_calculation();

#define   copy_rx_to_tx   memcpy(tx_data, rx_data, sizeof(rx_data));
#define   adding_crc_to_tx   sprintf(tx_data + sizeof(rx_data), "%02X%02X", (crc >> 8) & 0xFF,(crc & 0xFF));
#define   crc_index   4

void crc_control(uint16_t crc_modbus, uint16_t crc_cal);



#endif /* INC_CRC_CALCULATION_H_ */
