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

typedef enum {
  AlertFailed,
  AlertPassed
}AlertType;


BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
BreachType inferBreach(double value, double, double);


typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE
} AlertTarget;


AlertType checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, double temperatureInC);

AlertType sendToController(BreachType breachType);
AlertType sendToEmail(BreachType breachType);
AlertType sendToConsole(BreachType breachType);
AlertType Displaystatus(BreachType breachType);
