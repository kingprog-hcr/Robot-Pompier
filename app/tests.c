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

void Test_FlameSensor(void){
	uint16_t flame_value = FlameSensor_Read();
	printf("Valeur de l'adc : %d \n", flame_value);

	if(flame_value<= FLAME_THRESHOLD_ADC){
		printf("Flamme detectee !!");
	}
	else{
		printf("RAS !!");
	}
}
