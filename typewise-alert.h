#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

	
double lowerLimit[]= {0, 0,0};
double UpperLimit[]= {35, 45,40};

		      
typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;



BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
BreachType inferBreach(double value, double lowerboundary, double upperboundary);


typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

//typedef struct {
 // CoolingType coolingType;

//} BatteryCharacter;

//struct BatteryCharacter batteryChar;

BreachType checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
