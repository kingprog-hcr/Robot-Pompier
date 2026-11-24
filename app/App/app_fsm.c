//-- Include -------------------------------------------------
#include "app_fsm.h"
#include "tft_ili9341/stm32g4_ili9341.h"

//-- Define --------------------------------------------------
#define BUFFER_RX_SIZE	10
#define TICK_PERIOD_MS	1

//-- Enum ----------------------------------------------------
typedef enum
{
	ST_INIT = 0	,
	ST_WAIT		,
	ST_BLINK_LED,
	ST_NB
}e_State;

//-- Prototypes ----------------------------------------------

//------------------------------------------------------------
//
// APP_FSM : Main Finite State Machine
//
//------------------------------------------------------------
void App_FSM(void)
{
	static e_State e_current_state 					=  ST_INIT;
	static uint8_t u8_led_state 					= 0;
	static uint32_t u32_timer_ms 					= 0;

	// Increment time by 1 ms because the function APP_FSM is called every 1 ms
	u32_timer_ms += (uint32_t) TICK_PERIOD_MS;

	// State machine
	switch(e_current_state)
	{
		//-- Init ----------------------------------
		case ST_INIT :

			e_current_state = ST_WAIT;
			break;

		//-- Wait for 1s --------------
		case ST_WAIT :

			if(u32_timer_ms == 1000)
			{
				u32_timer_ms = 0;


				e_current_state = ST_BLINK_LED;
			}

			break;

		//-- Blink LED --------------
		// Toggle led's state with a XOR
		case ST_BLINK_LED :

			if(u32_timer_ms == 1000)
			{
				u32_timer_ms = 0;

				u8_led_state = u8_led_state ^ 1;
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, u8_led_state);
			}

			break;

		//-- Default state : normally never reached ---------
		default  :


			break;
		}
}


