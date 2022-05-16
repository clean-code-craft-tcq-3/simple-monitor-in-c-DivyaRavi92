#include <stdio.h>
#include <assert.h>

typedef enum
{
  LOW_SOC_BREACH = 0,
  LOW_SOC_WARNING =24,
  NORMAL_SOC =75,
  HIGH_SOC_WARNING = 79,
  HIGH_SOC_BREACH = 45
}socRange;

typedef enum
{
  LOW_TEMP_BREACH =0,
  LOW_TEMP_WARNING =3,
  NORMAL_TEMP =42,
  HIGH_TEMP_WARNING = 43,
  HIGH_TEMP_BREACH = 45
}temperatureRange;
