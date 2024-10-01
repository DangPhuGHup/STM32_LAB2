/*
 * LED_MATRIX.c
 *
 *  Created on: Oct 1, 2024
 *      Author: Admin
 */

#include "LED_MATRIX.h"
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};
uint16_t ENM_Pin[8] = {ENM0_Pin, ENM1_Pin,ENM2_Pin, ENM3_Pin,ENM4_Pin, ENM5_Pin,ENM6_Pin, ENM7_Pin};

void offall()
{
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin, SET);
}

void display(uint8_t index)
{
	for(int col = 0; col < 8; col++)
	{
		if(index & (1 << (7 - col)))
		{
			HAL_GPIO_WritePin(GPIOA, ENM_Pin[col], RESET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOA, ENM_Pin[col], SET);
		}
	}
}
void updateLEDMatrix(int index)
{
	offall();
	switch(index)
	{
	    case 0:
	    	        HAL_GPIO_WritePin(GPIOB, ROW0_Pin, RESET);
	    	        display(matrix_buffer[0]);
	    	        matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	        break;
	    case 1:
	    	    	HAL_GPIO_WritePin(GPIOB, ROW1_Pin, RESET);
	    	    	display(matrix_buffer[1]);
	    	    	matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	    	break;
	    case 2:
	    	    	HAL_GPIO_WritePin(GPIOB, ROW2_Pin, RESET);
	    	    	display(matrix_buffer[2]);
	    	    	matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	    	break;
	    case 3:
	    	    	HAL_GPIO_WritePin(GPIOB, ROW3_Pin, RESET);
	    	    	display(matrix_buffer[3]);
	    	    	matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	    	break;
	    case 4:
	    	    	HAL_GPIO_WritePin(GPIOB, ROW4_Pin, RESET);
	    	    	display(matrix_buffer[4]);
	    	    	matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	    	break;
	    case 5:
	    	    	HAL_GPIO_WritePin(GPIOB, ROW5_Pin, RESET);
	    	    	display(matrix_buffer[5]);
	    	    	matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	    	break;
	    case 6:
	    	    	HAL_GPIO_WritePin(GPIOB, ROW6_Pin, RESET);
	    	    	display(matrix_buffer[6]);
	    	    	matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	    	break;
	    case 7:
	    	    	HAL_GPIO_WritePin(GPIOB, ROW7_Pin, RESET);
	    	    	display(matrix_buffer[7]);
	    	    	matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
	    	    	break;

	    default:
	    	        break;
	}



}