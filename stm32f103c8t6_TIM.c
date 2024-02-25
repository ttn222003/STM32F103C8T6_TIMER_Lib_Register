/*
 * stm32f103c8t6_TIM.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Truong Trong Nhan
 */

#include "stm32f103c8t6_TIM.h"

RCC_Reg_t* RCC_TIMx = RCC;

void TIM_PeripheralClockControl(TIMx_Reg_t* TIMx, uint8_t EnableOrDisable)
{
	if(EnableOrDisable == ENABLE)
	{
		if(TIMx == TIM1)
		{
			RCC_TIMx->RCC_APB2ENR |= (1<<11);
		}
		else if(TIMx == TIM2)
		{
			RCC_TIMx->RCC_APB1ENR |= (1<<0);
		}
		else if(TIMx == TIM3)
		{
			RCC_TIMx->RCC_APB1ENR |= (1<<1);
		}
		else if(TIMx == TIM4)
		{
			RCC_TIMx->RCC_APB1ENR |= (1<<2);
		}
	}
	else if(EnableOrDisable == DISABLE)
	{
		if(TIMx == TIM1)
		{
			RCC_TIMx->RCC_APB2ENR &= ~(1<<11);
		}
		else if(TIMx == TIM2)
		{
			RCC_TIMx->RCC_APB1ENR &= (1<<0);
		}
		else if(TIMx == TIM3)
		{
			RCC_TIMx->RCC_APB1ENR &= (1<<1);
		}
		else if(TIMx == TIM4)
		{
			RCC_TIMx->RCC_APB1ENR &= (1<<2);
		}
	}
}

void TIM_BaseInit(TIMx_Reg_t* TIMx, uint16_t preScaler, uint16_t ARR)
{
	TIMx->TIMx_PSC = preScaler;
	TIMx->TIMx_ARR = ARR;
	TIMx->TIMx_CR1 |= 0x85;
}

void TIM_SetCounter(TIMx_Reg_t* TIMx, uint16_t setValue)
{
	TIMx->TIMx_CNT = setValue;
}

uint16_t TIM_GetCounter(TIMx_Reg_t* TIMx)
{
	static uint16_t counter = 0;
	counter = TIMx->TIMx_CNT;
	return counter;
}

// Time function
void delay_us(TIMx_Reg_t* TIMx, int delay_time)
{
	TIM_SetCounter(TIMx, 0);
	while(TIM_GetCounter(TIMx) < delay_time);
}

void delay_ms(TIMx_Reg_t* TIMx, int delay_time)
{
	int time = 0;
	while(time < delay_time)
	{
		delay_us(TIMx, 1000);
		time++;
	}
}
