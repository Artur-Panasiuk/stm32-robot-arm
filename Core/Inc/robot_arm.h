#ifndef ROBOT_ARM_H_
#define ROBOT_ARM_H_

//
// Adjust to use for translating [min, max] to universal scale [0, STEP_RANGE]
//
#define STEP_RANGE			180
//
// Servo min and max angle values
//
#define BASE_MIN_ANGLE		0
#define BASE_MAX_ANGLE		180
#define ARM_MIN_ANGLE		110
#define ARM_MAX_ANGLE		180
#define FOREARM_MIN_ANGLE	70
#define FOREARM_MAX_ANGLE	120
//
// Adjust for real world plug positions on PCA9685 board
//
#define BASE_CHANNEL 		0
#define ARM_CHANNEL 		1
#define FOREARM_CHANNEL 	2


void ROBOT_ARM_Init(I2C_HandleTypeDef *hi2c);
uint8_t ROBOT_ARM_StepCalc(uint8_t min, uint8_t max, uint8_t step, uint8_t step_range);
void ROBOT_ARM_Step(uint8_t channel, uint8_t min, uint8_t max, uint8_t step, uint8_t step_range);

#endif
