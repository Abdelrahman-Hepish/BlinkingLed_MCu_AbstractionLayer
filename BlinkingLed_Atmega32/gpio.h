#ifndef __GPIO_H__
#define __GPIO_H__
#include "utilites.h"
typedef enum
{
    PORT_A ,
    PORT_B ,
    PORT_C ,
    PORT_D ,
    PORT_E
}tPORT ;
typedef enum
{
    PIN_0 ,
    PIN_1 ,
    PIN_2 ,
    PIN_3 ,
    PIN_4 ,
    PIN_5 ,
    PIN_6 ,
    PIN_7 ,
}tPIN ;
typedef enum
{
    PIN_OUTPUT = 1 ,
    PIN_INPUT = 0
}tPIN_DIRECTION ;
typedef enum
{
    PORT_OUTPUT = 0XFF  ,
    PORT_INPUT = 0X00
}tPORT_DIRECTION ;
typedef enum
{
    LOW = 0 ,
    HIGH
}tSTATE ;
void GPIO_InitPort(tPORT port ,tPORT_DIRECTION direction ,tSTATE init_state) ;
void GPIO_InitPin(tPORT port , tPIN pin ,tPIN_DIRECTION direction ,tSTATE init_state) ;
void GPIO_UpdatePort(void) ;
void GPIO_UpdatePin(void) ;
void GPIO_SetPortData(tPORT port,unsigned char data);
void GPIO_SetPortDirection(tPORT port,tPORT_DIRECTION direction);
void GPIO_SetPinState(tPORT port , tPIN pin , tSTATE state);
void GPIO_SetPinDirection(tPORT port, tPIN pin ,tPIN_DIRECTION direction);
unsigned char GPIO_GetPortData(tPORT port);
unsigned char GPIO_GetPortDirection(tPORT port);
tSTATE GPIO_GetPinState(tPORT port , tPIN pin);
tPIN_DIRECTION GPIO_GetPinDirection(tPORT port, tPIN pin);
#endif // __GPIO_H__
