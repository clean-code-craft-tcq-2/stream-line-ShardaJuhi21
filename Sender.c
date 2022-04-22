
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Sender.h"

void readBMSDataFromFile(float* Temperature, float* SOC, float* ChargeRate)
{
  FILE* fp = fopen("./Sensor_Data.txt","r");
  float Temp_readings, SOC_readings, ChargeRate_readings;
  
  for(int i=0; fscanf(fp, "%f \t %f \t %f \n", &Temp_readings,&SOC_readings,&ChargeRate_readings)!=EOF; i++)
    {
      *(Temperature + i) = Temp_readings;
      *(SOC + i) = SOC_readings;
      *(ChargeRate + i) = ChargeRate_readings;
    }
  fclose(fp);
}

void sendBMSDataToConsole(float* Temperature, float* SOC, float* ChargeRate)
{
  float tempToPrint, SOCToPrint, chargeRateToPrint;
  
  for(int i=0;i<No_of_Readings; i++)
  {
    tempToPrint = *(Temperature + i);
    SOCToPrint = *(SOC + i);
    chargeRateToPrint = *(ChargeRate + i);
    printOnConsole(tempToPrint,SOCToPrint,chargeRateToPrint);
  }
}

void printOnConsole(float TempPrint, float SOCPrint, float ChargeRatePrint)
{
  printf("Temperature: %d\t SOC: %d\t ChargeRate: %.2f\n", TempPrint,SOCPrint,ChargeRatePrint);
}

void bms_DataSender()
{
  float Temperature[No_of_Readings], SOC[No_of_Readings], ChargeRate[No_of_Readings] = {0};
  readBMSDataFromFile(Temperature, SOC, ChargeRate);
  sendBMSDataToConsole(Temperature, SOC, ChargeRate);  
}
