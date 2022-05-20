#include "checkerTypes.h"
#include "stdbool.h"
#include <assert.h>


void convertTemperatureInCelcius(float *temperature, char temperatureUnit)
{
   if(temperatureUnit == 'F') 
   {
     *temperature =  (*temperature - 32)* (5/9) ;
   }

} 

bool printMessage(paramChecked parameterName, float parameterVal, float minVal, float maxVal)
{
  bool retVal = TRUE;
  if(parameterVal < minVal || parameterVal > maxVal)
  {
      printf("%d is out of Range", parameterName);
      retVal = FALSE;
  }
  else
  {
    printf("%d is going to be exceeded", parameterName);
  }
  return retVal;
}

bool isValueInRange(float parameterVal, float minVal, float maxVal, float tolerance, paramChecked parameterName)
{
  bool retVal = TRUE;  
  if(parameterVal < (minVal+tolerance)  || parameterVal > (maxVal-tolerance) )
  {
      retVal = printMessage(parameterName, parameterVal, minVal, maxVal);
      
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
 
   batteryIsOk(50,'C',20,0.4) ;
   batteryIsOk(68,'F',18,0.9) ;
   batteryIsOk(44,'C',76,0.77) ;
   batteryIsOk(30,'C',81,0.6) ;
   batteryIsOk(100,'F',25,0) ;
   
}
