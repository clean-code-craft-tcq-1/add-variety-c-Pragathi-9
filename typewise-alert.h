

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


const char* breachtype[]= {"NORMAL", " too LOW", "too HIGH"};
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
BreachType inferBreach(double value, double, double);


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
