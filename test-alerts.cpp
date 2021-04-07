#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the temperature hasn't breached any limits according to given cooling type") 
{
  REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING, 12) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING, 50) == TOO_HIGH);
  REQUIRE(checkAndAlert(TO_CONSOLE, MED_ACTIVE_COOLING, -5) == TOO_LOW);
}


TEST_CASE("infers the temperature has breached the higher limit according to cooling type") 
{
  REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING, 36) == TOO_HIGH);
  REQUIRE(checkAndAlert(TO_CONSOLE, HI_ACTIVE_COOLING, 50) == TOO_HIGH);
  REQUIRE(checkAndAlert(TO_EMAIL, MED_ACTIVE_COOLING, 48) == TOO_HIGH);
}

TEST_CASE("infers the temperature has breached the lower limit according to cooling type") 
{
  REQUIRE(checkAndAlert(TO_CONTROLLER, PASSIVE_COOLING, -20) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING, -5) == TOO_LOW);
  REQUIRE(checkAndAlert(TO_CONSOLE, MED_ACTIVE_COOLING, -6) == TOO_LOW);
}

