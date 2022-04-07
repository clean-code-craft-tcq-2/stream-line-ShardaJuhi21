#include "CurrentManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBER_OF_READINGS 150
int minValues[MAX_NUMBER_OF_READINGS] = {0};
int maxValues[MAX_NUMBER_OF_READINGS] = {0};
int countValues[MAX_NUMBER_OF_READINGS] = {0};

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
int* Sort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
        
    }
    return arr;
}
 
// Function to print an array
void printArray(int Sequence)
{
    for(int i=0; i<Sequence; i++)
    {
        printf("%d-%d, %d\n",minValues[i],maxValues[i],countValues[i]);
    }
}

int * CountReadings(int * SortedArray,int n){
    int *array;
    array = (int*)calloc(MAX_NUMBER_OF_READINGS, sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        int index = SortedArray[i];
        array[index]++;
    }
    return array;

}

int getMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++){
       if( min>arr[i]){
          min=arr[i] ;
       }
    }
    return min;
}
 
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if(max<arr[i]){
         max=arr[i]   ;
        }
    }
    return max;
}

int RangeOfSamples(int* Readings, int n) {
    int rangeCounter = 0, readingsCounter = 0;
  
    int max = getMax(Readings, n);
    int min = getMin(Readings, n);
    int range = max - min;
  if(range+1==n) // if the number of elements between max and min including themselves equals size of array then proceed
  {
    if(readingsCounter != 0){
    for(int i=0;i<n;i ++)
      {
           minValues[rangeCounter] = min;
            maxValues[rangeCounter] = max;
            countValues[rangeCounter] = readingsCounter;
           rangeCounter++;
        readingsCounter = 0;


    }}
    }
 
    return rangeCounter;
}

bool DetectRange(int *Array, int n){
 

   int* SortedArray = Sort(Array, n);
   int* Readings = CountReadings(SortedArray, n);
   int samples = RangeOfSamples( Readings,  n);
    (void)printArray(samples);
    return TRUE;
}



float  A2DConversion(int AnalogValue){
	float currentValue;	
	currentValue = 10 *( AnalogValue/ 4094);
	return currentValue;

}

int roundOffCurrentValue(float currentValue){
	int roundedChargingCurrentValue;
	roundedChargingCurrentValue = round(currentValue);
	return roundedChargingCurrentValue;
}

int AbsoluteValue(int roundedChargingCurrentValue){
	CurrentValue = abs(roundedChargingCurrentValue);
	return chargingCurrentValue;
}




int checkIfValueIsAbsoluteAndConvert(int *chargingCurrentValue) {
	return (*chargingCurrentValue < 0) ? AbsoluteValue(*chargingCurrentValue) : *chargingCurrentValue;
}

bool Sensors(int *Array, int n){
    int* chargingCurrentValues;
	float currentValue;
	int roundOffValue;
 
for (int i=0; i<n; i++){
	 currentValue =A2DConversion(Array[i]);
	 roundOffValue= roundOffCurrentValue(currentValue);
	 chargingCurrentValues[i] = roundOffCurrentValue(currentValue);
	 chargingCurrentValues[i] = checkIfValueIsAbsoluteAndConvert(&chargingCurrentValues[i]);
}
    return TRUE;
}
