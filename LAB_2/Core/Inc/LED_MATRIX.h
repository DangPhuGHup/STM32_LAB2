/*
 * LED_MATRIX.h
 *
 *  Created on: Oct 1, 2024
 *      Author: Admin
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_
#include "main.h"
#include "stdint.h"

extern int index_led_matrix;
extern uint8_t matrix_buffer[8];
void updateLEDMatrix(int index);
void offall();
void display(uint8_t index);
#endif /* INC_LED_MATRIX_H_ */