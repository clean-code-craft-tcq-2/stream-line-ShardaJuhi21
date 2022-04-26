#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "BatteryReadingReceiver.h"

TEST_CASE("Tests to check whether sensor data is read from console") 
{
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  float Current_MaxValue, Current_MinValue, Current_SMAValue, expectedMaxValue, expectedMinValue, expectedSMAValue;
  
  BatteryReceiver(Temperature,SOC,ChargeRate);
  float expectedoutput[2][3] = {{0.68,57,42}, {0.65,58,45}};
  for(int i=0;i<2;i++)
  {
    REQUIRE(Temperature[i] == expectedoutput[i][0]);
    REQUIRE(SOC[i] == expectedoutput[i][1]);
    REQUIRE(ChargeRate[i] == expectedoutput[i][2]);
  }
  
  // Verify Max, Min values are correct for parameter Temperature
  expectedMaxValue = 1.000000;
  expectedMinValue = -0.5.000000;
  Current_MaxValue = ComputeMax(Temperature);
  Current_MinValue = ComputeMin(Temperature);
  REQUIRE(Current_MaxValue == expectedMaxValue);
  REQUIRE(Current_MinValue == expectedMinValue);
    
}
