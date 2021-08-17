#include "MCuAbstraction_layer.h"
#include "led.h"


void main(void)
{
   /* initialization */
    LED_Init(LED_1 , LED_ON) ;
    LED_Init(LED_2 , LED_ON) ;
    LED_Init(LED_3 , LED_ON) ;
    LED_Init(LED_4 , LED_ON) ;
	while(1)
	{
        LED_Update() ;
	}

}
