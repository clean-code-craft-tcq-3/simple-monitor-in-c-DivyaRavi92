#include <stdio.h>
#include <assert.h>

int checkTemperature(float temperature)
{
   int retVal = 1;
   if(temperature < 0 || temperature > 45) 
   {
     printf("Temperature out of range!\n");
     retVal = 0;
   }
   return retVal;
 } 

int checkSoc(float soc)
{
   int retVal = 1;
   if(soc < 20 || soc > 80) {
     printf("State of Charge out of range!\n");
     retVal = 0;
   }
   return retVal;
 } 

int checkChargeRate(float chargeRate)
{
   int retVal = 1;
   if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
     retVal = 0;
   }
   return retVal;
 } 

int batteryIsOk(float temperature, float soc, float chargeRate) {
 
  int batteryOK = 1;
  batteryOK  = batteryOK & checkTemperature(temperature);
  batteryOK  = batteryOK & checkSoc(soc);
  batteryOK  = batteryOK & checkChargeRate(chargeRate);
  
  return batteryOK;
  
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == 1);
  assert(!batteryIsOk(50, 85, 0) == 1);
}
