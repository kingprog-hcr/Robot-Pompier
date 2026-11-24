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

void Test_Init(void){
	FLameSensor_Init();
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
}
