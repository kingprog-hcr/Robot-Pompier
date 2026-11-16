
/**
 *
 *******************************************************************************
 * @file 	flame_sensor.c
 * @author 	Chrys-Renabell HASSAM
 * @date 	Nov 15, 2026
 * @brief	Fichier contenant les fonctions relatives au capteur de flamme
 *******************************************************************************
 */

#include "config.h"
#include "flame_sensor.h"
#include "stm32g4_adc.h"

void FLameSensor_Init(void) {
    // Initialisation de l'ADC et configuration de la broche PA1
	 BSP_ADC_init();
}

uint16_t FlameSensor_Read(void) {
	return BSP_ADC_getValue(ADC_2);
}
