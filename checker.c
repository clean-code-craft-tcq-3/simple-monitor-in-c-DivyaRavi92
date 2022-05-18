#include "checkerTypes.h"
#include <assert.h>


void convertTemperatureInCelcius(float *temperature, char temperatureUnit)
{
   if(temperatureUnit == 'F') 
   {
     *temperature =  (*temperature - 32)* (5/9) ;
   }

} 

void printMessage(paramChecked parameterName, float parameterVal, float minVal, float maxVal)
{
  
  if(parameterVal < minVal || parameterVal > maxVal)
  {
      printf("%d is out of Range", parameterName);
  }
  else
  {
    printf("%d is going to be exceeded", parameterName);
  }
}

bool isValueInRange(float parameterVal, float minVal, float maxVal, float tolerance, paramChecked parameterName)
{
  bool retVal = 1;  
  if(parameterVal < (minVal+tolerance)  || parameterVal > (maxVal-tolerance) )
  {
      printMessage(parameterName, parameterVal, minVal, maxVal);
      retVal = 0;
  }
  return retVal;
}



bool checkTemperature(float temperature, char temperatureUnit)
{
   bool retVal;
   float minValue =  0, maxValue = 45, tolerance = 2.25;
   convertTemperatureInCelcius(&temperature,temperatureUnit);
   retVal = isValueInRange(temperature, minValue, maxValue, tolerance, TEMPERATURE);
   return retVal;
 } 

bool checkSoc(float soc)
{
   bool retVal;
   float minValue =  20, maxValue = 80, tolerance = 4;
   retVal = isValueInRange(soc, minValue, maxValue,tolerance, SOC);
   return retVal;
 } 

bool checkChargeRate(float chargeRate)
{
   bool retVal;
   float minValue =  0, maxValue = 0.8, tolerance = 0.04;
   retVal = isValueInRange(chargeRate, minValue, maxValue, tolerance, CHARGERATE);
   return retVal;
} 

bool batteryIsOk(float temperature, char temperatureUnit, float soc, float chargeRate) {
 
  bool batteryOK = 1;
  batteryOK  = batteryOK & checkTemperature(temperature,temperatureUnit);
  batteryOK  = batteryOK & checkSoc(soc);
  batteryOK  = batteryOK & checkChargeRate(chargeRate);
  
  return batteryOK;
  
}

int main() {
  float temperature, soc, chrgRate;
  char temperatureUnit;
  printf("Enter temperature: ");
  scanf("%f\n", &temperature) ;
  printf("Enter temperature unit C for celcius F for Farenheit: ");
  scanf("%c\n", &temperatureUnit) ;
  printf("Enter SOC: ");
  scanf("%f\n", &soc) ;
  printf("Enter chargeRate: ");
  scanf("%f\n", &chrgRate) ;

  batteryIsOk(temperature,temperatureUnit,soc,chrgRate) ;
 
  
}
