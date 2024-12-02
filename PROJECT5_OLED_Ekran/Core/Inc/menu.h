/*
 * menu.h
 *
 *  Created on: 1 Eki 2024
 *      Author: sezai
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_

void menu( int count);
void menu2( int count);
void Flash_Write(uint32_t flash_address, uint8_t flash_data);
uint8_t Flash_Read(uint32_t flash_address);
void flash_init();


extern uint8_t picture1[64*128];
extern uint8_t picture2[64*128];
extern uint8_t picture3[64*128];
extern uint8_t picture4[64*55];
extern uint8_t logo[];
extern uint8_t LOGO_BW_map[];
extern uint8_t img[];
extern uint8_t fb[];



#endif /* INC_MENU_H_ */
