/**
 *
 *******************************************************************************
 * @file 	tests.c
 * @author 	Chrys-Renabell HASSAM
 * @date 	Nov 15, 2026
 * @brief	Fichier contenant les fonctions relatives aux tests unitaires effecute pour chaque les differents capteurs/peripheriques
 *******************************************************************************
 */

#include "tests.h"
#include "flame_sensor.h"
#include "stdint.h"
#include "config.h"
#include "stm32g4_hcsr04.h"
#include "stm32g4_uart.h"
#include "stm32g4_utils.h"
#include "stm32g4_gpio.h"
#include <stdio.h>

void Test_Init(void){
	FLameSensor_Init();
	// Pin du buzzer
	BSP_GPIO_pin_config(BUZZER_PORT, BUZZER_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);

	// Pin de la pompe a eau

	BSP_GPIO_pin_config(PUMP_GPIO_PORT, PUMP_GPIO_PIN, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);

}
void Test_FlameSensor(void){


	uint16_t flame_value = FlameSensor_Read();
	printf("Valeur de l'adc : %d \n", flame_value);

	if(flame_value<= FLAME_THRESHOLD_ADC){
		printf("Flamme detectee !!");
		HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET);

	}
	else{
		printf("RAS !!");
		HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);

	}
	HAL_Delay(500);
}


// Test du capteur ultrason


void Test_Ultrason_run(void)
{
    uint8_t id_ultrason;
    uint16_t distance_mm = 0;
    uint32_t t_last_measure = 0;


    printf("     LANCEMENT DU TEST UNITAIRE ULTRASON    \n");


    /* * Ajout du capteur ultrason avec les broches :
         * - Trigger : PB3 (GPIOB, GPIO_PIN_3)
         * - Echo    : PA7 (GPIOA, GPIO_PIN_7)
         */
        if (BSP_HCSR04_add(&id_ultrason, GPIOB, GPIO_PIN_3, GPIOA, GPIO_PIN_7) == HAL_OK) {
            printf("[SUCCESS] Capteur ultrason ajoute (Trig:PB3, Echo:PA7) - ID : %d\n", id_ultrason);
        } else {
            printf("[ERROR] Impossible d'ajouter le capteur ultrason.\n");
            while(1);
        }


    t_last_measure = HAL_GetTick();

    /* Boucle de test */
    while (1)
    {

        BSP_HCSR04_process_main();

        // Déclencher une mesure toutes les 60 ms (période standard pour un HC-SR04)
        if (HAL_GetTick() - t_last_measure >= 60)
        {
            BSP_HCSR04_run_measure(id_ultrason);
            t_last_measure = HAL_GetTick();
        }

        //  Récupérer et afficher la valeur dès qu'elle est prête
        switch (BSP_HCSR04_get_value(id_ultrason, &distance_mm))
        {
            case HAL_OK:
                // Affichage en cm (\r pour réécrire sur la même ligne)
                printf("Distance mesurée : %3d cm\r", distance_mm / 10);
                break;

            case HAL_TIMEOUT:
                printf("[WARN] Timeout : Aucun obstacle détecté à portée.\r");
                break;

            case HAL_ERROR:
                printf("[ERROR] Erreur interne du capteur.\r");
                break;

            case HAL_BUSY:
                // La mesure est en cours (l'onde sonore voyage), on attend le prochain tour
                break;
        }
    }
}


void Test_PUMP(void){
	uint8_t command = 0;

	if(BSP_UART_data_ready(UART2_ID)){ // liaison avec le PC
		command = BSP_UART_getc(UART2_ID);
		switch(command){

			case 'A':
							// Activation de la pompe a eau
				HAL_GPIO_WritePin(PUMP_GPIO_PORT, PUMP_GPIO_PIN, GPIO_PIN_SET);
				printf("Activation de la pompe a eau \n");
				break;

			case 'D':
					// Desactivation de la pompe a eau
				HAL_GPIO_WritePin(PUMP_GPIO_PORT, PUMP_GPIO_PIN, GPIO_PIN_RESET);
				printf("Desactivation de la pompe a eau \n");
				break;

			default :
				break;
					}
	}

}



