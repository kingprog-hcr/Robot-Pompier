#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

//-- Include -------------------------------------------------
#include "config.h"
#include "stm32g4_sys.h"
#include <stdio.h>

// Macros

#define FLAME_THRESHOLD_ADC 2000 //Seuil de détection de flamme (12 bits: 0-4095)



//-- Prototypes ----------------------------------------------

void FLameSensor_Init(void);
uint16_t FlameSensor_Read(void);
#endif /* FLAME_SENSOR_H_ */
