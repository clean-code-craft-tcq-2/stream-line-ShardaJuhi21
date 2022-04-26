#define NO_OF_READINGS 50

float ComputeSMA(float data[]);
float ComputeMax(float data[]);
float ComputeMin(float data[]);

void ReadBatteryReadingsfromConsole(float* Temperature, float* SOC, float* ChargeRate);
void BatteryReceiver(float* Temperature, float* SOC, float* ChargeRate);
void PrintComputedReadingsOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA);
