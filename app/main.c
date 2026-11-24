/**
 *
 *******************************************************************************
 * @file 	main.c
 * @author 	jjo
 * @date 	Mar 29, 2024
 * @brief	Fichier principal du projet sur carte Nucléo STM32G431KB
 *******************************************************************************
 */

#include "config.h"
#include "stm32g4_sys.h"

#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "stm32g4xx_it.h"
#include "tft_ili9341/stm32g4_ili9341.h"
#include "App/app_fsm.h"
#include <stdio.h>
#include "tests.h"
/**
  * @brief  Point d'entrée de votre application
  */
int main(void)
{
	static uint8_t u8_led_state 					= 0;

	//-- Initialization --------------------------------------------

	// Hardware layer
	HAL_Init();

	// GPIO
	BSP_GPIO_enable();

	// UART2
	BSP_UART_init(UART2_ID,115200);
	BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	// Configure output to control nucleo's green LED
	BSP_GPIO_pin_config(GPIOB, GPIO_PIN_8, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FAST, GPIO_NO_AF);


	Test_Init();

	BSP_GPIO_pin_config(BUZZER_PORT, BUZZER_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);

	//-- Application ------------------------------------------------
	while (1)
	{
		//DEMO_adc_statemachine();
		Test_FlameSensor();
		HAL_Delay(500);



		/*
		if(u8_FlagSysTick == 1u)
		{
			App_FSM();

			u8_FlagSysTick = 0u;
		}
		Test_FlameSensor();
		HAL_Delay(500);
		*/

	}
}
