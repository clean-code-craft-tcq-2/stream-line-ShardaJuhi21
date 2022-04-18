#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Sensor.h"

TEST_CASE("Test to verify the data read")
{
  float Temperature[No_of_Readings], SOC[No_of_Readings], ChargeRate[No_of_Readings] = {0};
  readBMSDataFromFile(Temperature, SOC, ChargeRate);
  float expectedOutput[3][3] = {{42,57,0.68}, {45,58,0.65},{48,60,0.34}};

  for(int i = 0; i < 3; i++)
  {
    REQUIRE(Temperature[i] == expectedOutput[i][0]);
    REQUIRE(SOC[i] == expectedOutput[i][1]);
    REQUIRE(ChargeRate[i] == expectedOutput[i][2]);
  }
}

