#include "main.h"
#include "i2c.h"
#include "pca9685.h"


void ROBOT_ARM_Init(I2C_HandleTypeDef *hi2c){
	PCA9685_Init(&hi2c1);
}

uint8_t ROBOT_ARM_StepCalc(uint8_t min, uint8_t max, uint8_t step, uint8_t step_range){
	uint8_t output;

	if(step >= step_range){
		output = max;
	}else if(step == 0){
		output = min;
	}else{
		//Linear Transformation from [min, max] to [0, step_range]
		output = ((max - min) / (step_range - 0)) * step + min;
	}
	return output;
}

void ROBOT_ARM_Step(uint8_t channel, uint8_t min, uint8_t max, uint8_t step, uint8_t step_range){
	PCA9685_SetServoAngle(channel, ROBOT_ARM_StepCalc(min, max, step, step_range));
}
