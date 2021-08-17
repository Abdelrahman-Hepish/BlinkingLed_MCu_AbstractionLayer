#include "gpio.h"
#include "led.h"
#include "utilites.h"

#define DELAY_TIME  100000

static void LED_SetDirection(tLED led) ;
static void LED_Toggle(tLED led) ;

void LED_Init(tLED led,tLED_State init_state )
{
  /* initialize pin as output */
  LED_SetDirection(led) ;
  /* initialize pin state */
  LED_SetState(led , init_state) ;
}
void LED_Update(void)
{
   LED_Toggle(LED_1) ;
   LED_Toggle(LED_2) ;
   LED_Toggle(LED_3) ;
   LED_Toggle(LED_4) ;
   UTILITES_DelayMS(DELAY_TIME) ;
}
void LED_SetState(tLED led , tLED_State state)
{
  switch(led)
  {
  case LED_1 :
    GPIO_SetPinState(PORT_B,PIN_0,state) ;
    break ;
  case LED_2 :
    GPIO_SetPinState(PORT_B,PIN_1,state) ;
    break ;
  case LED_3 :
    GPIO_SetPinState(PORT_B,PIN_2,state) ;
    break ;
  case LED_4 :
    GPIO_SetPinState(PORT_B,PIN_3,state) ;
    break ;
  }
}
tLED_State LED_GetState(tLED led)
{
    tLED_State ret = LED_OFF ;
 switch(led)
  {
  case LED_1 :
    ret = GPIO_GetPinState(PORT_B,PIN_0) ;
    break ;
  case LED_2 :
    ret = GPIO_GetPinState(PORT_B,PIN_1) ;
    break ;
  case LED_3 :
    ret = GPIO_GetPinState(PORT_B,PIN_2) ;
    break ;
  case LED_4 :
    ret = GPIO_GetPinState(PORT_B,PIN_3) ;
    break ;
  }
  return ret ;
}

static void LED_SetDirection(tLED led)
{
 switch(led)
  {
  case LED_1 :
    GPIO_SetPinDirection(PORT_B,PIN_0,PIN_OUTPUT) ;
    break ;
  case LED_2 :
    GPIO_SetPinDirection(PORT_B,PIN_1,PIN_OUTPUT) ;
    break ;
  case LED_3 :
    GPIO_SetPinDirection(PORT_B,PIN_2,PIN_OUTPUT) ;
    break ;
  case LED_4 :
    GPIO_SetPinDirection(PORT_B,PIN_3,PIN_OUTPUT) ;
    break ;
  }
}
static void LED_Toggle(tLED led)
{
    if(LED_GetState(led) == LED_OFF)
    {
        LED_SetState(led,LED_ON) ;
    }else
    {
        LED_SetState(led,LED_OFF) ;
    }
}
