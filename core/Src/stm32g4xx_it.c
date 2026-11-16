/**
  ******************************************************************************
  * @file    stm32g4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "config.h"
#include "stm32g4xx_it.h"
#include "App/app_fsm.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
uint32_t u32_CntSysTick = 0u;

volatile uint8_t u8_FlagSysTick = 0u;


/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/


/* External variables --------------------------------------------------------*/



/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{

  while (1)
  {
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{


}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{


}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{


}

/**
  * @brief This function handles System tick timer.
  */
/* Since the use of HAL_SYSTICK_IRQHandler() has been discontinued by ST, implementation
 * of Systick_Handler is transfered to stm32g4_systick.c in order to manage callback functions
 */

void SysTick_Handler(void)
{
	HAL_IncTick();

	u8_FlagSysTick = 1u;
}

void EXTI9_5_IRQHandler(void)
{
	uint16_t gpio_pin;
	uint32_t u32_cnt = 10000;

	gpio_pin = (uint16_t)(1) << (uint16_t)(8);
	if(__HAL_GPIO_EXTI_GET_IT(gpio_pin))
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
		while((u32_cnt--) > 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		__HAL_GPIO_EXTI_CLEAR_IT(gpio_pin);

	}

}

/******************************************************************************/
/* STM32G4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g4xx.s).                    */
/******************************************************************************/

