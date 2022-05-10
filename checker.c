#include <stdio.h>
#include <assert.h>

int checkTemperature(float temperature)
{
   boolean retVal = 1;
   if(temperature < 0 || temperature > 45) 
   {
     printf("Temperature out of range!\n");
     retVal = 0;
   }
   return retVal;
 } 

int checkSoc(float soc)
{
   boolean retVal = 1;
   if(soc < 20 || soc > 80) {
     printf("State of Charge out of range!\n");
     retVal = 0;
   }
   return retVal;
 } 

int checkChargeRate(float chargeRate)
{
   boolean retVal = 1;
   if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
     retVal = 0;
   }
   return retVal;
 } 

int batteryIsOk(float temperature, float soc, float chargeRate) {
  boolean isTempInRange,isSocInRange,isChargeRateInRange;
  int batteryOK = 0;
  batteryOK & = checkTemperature(temperature);
  batteryOK & = checkSoc(soc);
  batteryOK & = checkChargeRate(chargeRate);
  
  return batteryOK;
  
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == 1);
  assert(!batteryIsOk(50, 85, 0) == 1);
}
