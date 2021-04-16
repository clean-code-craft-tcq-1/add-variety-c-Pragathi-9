/**********************************************
Include header files
***********************************************/
#include "typewise-alert.h"
#include <stdio.h>

double lowerboundary[]= {0,0,0};
double upperboundary[]= {35,45,40};

const char* breach[]= {"NORMAL", " too LOW", "too HIGH"};

AlertType AlertStatus= AlertFailed;

typedef AlertType (*SendtheAlertMessage) (BreachType breachType);
SendtheAlertMessage AlertDestination[] = 
    {
        sendToController, 
        sendToEmail, 
        sendToConsole
    };

/*********************************************
Function definitions
**********************************************/

/********************************************************************************
 * Function: inferBreach
 
 * Description: A function that checks if the passed attribute value is exceeding the lower
   and upper limits.
 
 * input: BMS attribute value here
 
 * returns: breach type as TOO LOW, HIGH OR NORMAL
 *********************************************************************************/
BreachType inferBreach(double value, double lowerlimit, double upperlimit) {
  if(value < lowerlimit) {
    return TOO_LOW;
  }
  if(value > upperlimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}


/********************************************************************************
 * Function: classifyTemperatureBreach
 
 * Description: A function that classifies the attribute value to different 
   breach categories dependent on the cooling type and respective ranges
 
 * input: attribute value and the cooling type
 
 * returns: breach type as TOO LOW, HIGH OR NORMAL
 *********************************************************************************/
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{

  return inferBreach(temperatureInC,lowerboundary[coolingType], upperboundary[coolingType]);
}


/********************************************************************************
 * Function: checkAndAlert
 
 * Description: A function that checks the breach type and sends the results to
   either the controller or via e-mail.
 
 * input: attribute value, cooling type to be checked and the the target to alert 
   about the breach
 
 * returns: breach type as TOO LOW, HIGH OR NORMAL
 *********************************************************************************/
AlertType checkAndAlert(AlertTarget alertTarget, CoolingType coolingType, double temperatureInC) 
{
 
  BreachType breachType = classifyTemperatureBreach(coolingType, temperatureInC);
  return(AlertDestination[alertTarget](breachType));
 
}


/********************************************************************************
 * Function: sendToController
 
 * Description: A function that prints the breach status thats passed on to the 
    controller
 
 * input: breach type
 
 *********************************************************************************/
AlertType sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  return(Displaystatus(breachType));
}

/********************************************************************************
 * Function: sendToEmail
 
 * Description: A function that sends the breach status via mail
 
 * input: breach type
 *********************************************************************************/

AlertType sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  return(Displaystatus(breachType));

}

/********************************************************************************
 * Function: sendToConsole
 
 * Description: A function that sends the breach status to the Console
 
 * input: breach type
 *********************************************************************************/

AlertType sendToConsole(BreachType breachType) 
{
  return(Displaystatus(breachType));
}


/********************************************************************************
 * Function: Displaystatus
 
 * Description: A prints the status of breach in the expected destination
 
 * input: breach type
 *********************************************************************************/
AlertType Displaystatus(BreachType breachType)
{
    printf("Hi, the BMS temperature is %s\n", breach[breachType]);
    return AlertPassed;
}
