#include "MCuAbstraction_layer.h"
#include "led.h"
unsigned int __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;

void main(void)
{
    /* initialization */
    LED_Init(LED_1 , LED_ON) ;
    LED_Init(LED_2 , LED_ON) ;
    LED_Init(LED_3 , LED_ON) ;
    LED_Init(LED_4 , LED_ON) ;
    while(1)
    {
      /* Task */
      LED_Update() ;
    }
}
