
#include "typewise-alert.h"
#include <stdio.h>


BreachType inferBreach(double value, double lowerboundary, double upperboundary) {
  if(value < lowerboundary) {
    return TOO_LOW;
  }
  if(value > upperboundary) {
    return TOO_HIGH;
  }
  return NORMAL;
}



BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{

  return inferBreach(temperatureInC,lowerLimit[coolingType], upperLimit[coolingType]);
}



BreachType checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, double temperatureInC) 
{

  BreachType breachType = classifyTemperatureBreach(coolingType, temperatureInC);

  switch(alertTarget) 
  {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
  
  return breachType;
}



void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}



void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
