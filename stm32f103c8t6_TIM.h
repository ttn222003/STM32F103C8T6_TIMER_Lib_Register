/*
 * stm32f103c8t6_TIM.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Truong Trong Nhan
 */

#ifndef INC_STM32F103C8T6_TIM_H_
#define INC_STM32F103C8T6_TIM_H_

#include "stm32f103c8t6.h"

void TIM_HSEEnable(void);
void TIM_PeripheralClockControl(TIMx_Reg_t* TIMx, uint8_t EnableOrDisable);
void TIM_BaseInit(TIMx_Reg_t* TIMx, uint16_t preScaler, uint16_t ARR);
void TIM_SetCounter(TIMx_Reg_t* TIMx, uint16_t setValue);
uint16_t TIM_GetCounter(TIMx_Reg_t* TIMx);
void delay_us(TIMx_Reg_t* TIMx, int delay_time);
void delay_ms(TIMx_Reg_t* TIMx, int delay_time);
#endif /* INC_STM32F103C8T6_TIM_H_ */
