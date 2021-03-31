#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef struct 
{
	double lowerLimit;
	double upperLimit;
} limittype;

limittype limit[]= {{0,35}, {0,45},{0,40}};


typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;



BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
BreachType inferBreach(double value, double lowerLimit, double upperLimit);


typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

//typedef struct {
 // CoolingType coolingType;

//} BatteryCharacter;

//struct BatteryCharacter batteryChar;

void checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
