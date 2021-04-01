
#include "typewise-alert.h"
#include <stdio.h>

double lowerboundary[]= {0,0,0};
double upperboundary[]= {35,45,40};
const char* breachtype[]= {"NORMAL", " too LOW", "too HIGH"};

BreachType inferBreach(double value, double lowerlimit, double upperlimit) {
  if(value < lowerlimit) {
    return TOO_LOW;
  }
  if(value > upperlimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}



BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{

  return inferBreach(temperatureInC,lowerboundary[coolingType], upperboundary[coolingType]);
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
  printf("To: %s\n", recepient);
  printf("Hi, the BMS temperature is %s\n", breachtype[breachType]);
  
}
