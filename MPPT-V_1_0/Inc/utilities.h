#ifndef __utilities_H
#define __utilities_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdbool.h>

#define ARRAY_OK 1
#define ARRAY_ERROR 0

#define BATTERY_OK 1
#define BATTERY_ERROR 0

#define ARRAY_TURN_OFF_TH	325  // 13V
#define ARRAY_TURN_ON_TH	355  // 14V

#define BATTERY_ON_UPPER_TH 2310	    // 115 V
#define BATTERY_ON_BOTTOM_TH 1870	// 80 V
#define BATTERY_OFF_UPPER_TH 2350	// 120 V
#define BATTERY_OFF_BOTTOM_TH 1750  // 75V

#define NUMBER_OF_LAST_MEASUREMENTS 15
#define DELAY_BETWEEN_MEASUREMENTS 10

#define DUTY_CYCLE_INITIALIZED 800 // 800 per mille
#define DUTY_CYCLE_STEP 5 // step in per mille
#define MAX_COUNTER_VALUE 839 // PWM maximum value of counter
#define STEP_UP 1
#define STEP_DOWN 0

#define MPPT_STATE_RED 0
#define MPPT_STATE_YELLOW 1
#define MPPT_STATE_GREEN 2

/* Variables -----------------------------------------------------------------*/
uint8_t isMPPTInitialised;

uint32_t batteryCurrentADC;
uint32_t arrayCurrentADC;
uint32_t batteryVoltageADC;
uint32_t arrayVoltageADC;
uint32_t valueContainerADC[4];

uint8_t arrayStatus;
uint8_t batteryStatus;

uint8_t lastMeasurementsIterator;

uint32_t lastADCArrayVoltage[NUMBER_OF_LAST_MEASUREMENTS];
uint32_t lastADCArrayCurrent[NUMBER_OF_LAST_MEASUREMENTS];
uint32_t lastADCBatteryVoltage[NUMBER_OF_LAST_MEASUREMENTS];
uint32_t lastADCBatteryCurrent[NUMBER_OF_LAST_MEASUREMENTS];

uint32_t averageArrayVoltage;
uint32_t averageArrayCurrent;
uint32_t averageBatteryVoltage;
uint32_t averageBatteryCurrent;

uint32_t dutyCycle;
uint32_t inputPower;
uint8_t prevStepDirection;
uint8_t MPPTState;


 /* Functions Declaration ----------------------------------------------------*/

/* --- LED STATES FUNCTIONS -----------------------*/

void setYellowState(void);
void resetYellowState(void);

void setRedState(void);
void resetRedState(void);

void setGreenState(void);
void resetGreenState(void);

/* --- END OF LED STATES FUNCTIONS -----------------------*/

/* --- PWM CONTROL FUNCTIONS ----------------------------*/

void enablePWM(void);
void disablePWM(void);
void calculateInputPower(void);
void setDutyCycle(uint32_t );

/* --- END OF PWM CONTROL FUNCTIONS ----------------------------*/

void getArrayStatus(void);
void getBatteryStatus(void);
void checkArrayConnection(void);
void checkBatteryConnection(void);

/* --- MEASUREMENTS CONTROL FUNCTIONS -------------------------*/

void readVoltageAndCurrent(uint32_t * valueContainer);
void measurementsInit(void);
void storeMeasurements(void);
void calculateMeasurementsAverage(void);
void increaseDutyCycle(void);
void deacreseDutyCycle(void);

/* --- END OF MEASUREMENTS CONTROL FUNCTIONS -----------------*/

void MPPTInit(void);
#ifdef __cplusplus
}
#endif
#endif /*__ tim_H */
