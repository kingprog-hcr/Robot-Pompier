#ifndef MOTOR_H_
#define MOTOR_H_

// Fréquence ARR maximale définie dans le .ioc (8499)
#define PWM_MAX 8499
#include <stm32g4_timer.h>

typedef struct {
timer_id_t timer_fin; // ID du timer pour la marche avant (Fin)
uint16_t channel_fin; // Canal pour la marche avant
timer_id_t timer_rin; // ID du timer pour la marche arrière (Rin)
uint16_t channel_rin; // Canal pour la marche arrière
} Motor_t;

// Initialisation des Timers PWM
void Motors_Init(void);

// Ajuste la vitesse d'un moteur (-1000 à 1000)
// Valeur positive = Sens Avant, Valeur négative = Sens Arrière
void Motors_SetSpeed(uint8_t motor_id, int16_t speed);



#endif /* INC_MOTOR_H_ */
