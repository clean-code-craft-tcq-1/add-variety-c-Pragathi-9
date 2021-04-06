#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

		      
typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;



BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
BreachType inferBreach(double value, double, double);


typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE
} AlertTarget;

BreachType checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void sendToConsole(BreachType breachType);
typedef void (*SendtheAlertMessage) (BreachType breachType);
SendtheAlertMessage AlertDestination[] = 
    {
        sendToController, 
        sendToEmail, 
        sendToConsole
    };
