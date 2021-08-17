#include "gpio.h"
#include "utilites.h"
#include "MCuAbstraction_layer.h"

#define SetRegisterPin(Register,Pin,_1bitValue) ( Register = ((Register & (~(1<<Pin ))) | (_1bitValue << Pin)) )
#define SetRegister(Register,_U8Value)          (Register = _U8Value )
#define ReadRegisterPinValue(Register,Pin)       ((Register & ((1<<Pin)))>>Pin)
#define ReadRegisterValue(Register)              (Register)

void GPIO_InitPort(tPORT port ,tPORT_DIRECTION direction ,tSTATE init_data)
{
    /* initialize port direction */
    GPIO_SetPortDirection(port,direction) ;
    /* initialize port data     */
    GPIO_SetPortData(port,init_data) ;
}
void GPIO_InitPin(tPORT port , tPIN pin ,tPIN_DIRECTION direction ,tSTATE init_state)
{
   /* initialize pin direction */
   GPIO_SetPinDirection(port,pin ,direction) ;
   /* initialize pin state */
   GPIO_SetPinState(port ,pin ,init_state) ;
}

void GPIO_UpdatePort(void)
{
 /* should do no thing */
}
void GPIO_UpdatePin(void)
{
/*  should do no thing */
}
void GPIO_SetPortData(tPORT port,unsigned char data)
{
    switch(port)
    {
    case PORT_A :
        SetRegister(DATA_REGISTER_WRITE_PORTA,data) ;
    break;
    case PORT_B :
        SetRegister(DATA_REGISTER_WRITE_PORTB,data) ;
    break;
    case PORT_C :
        SetRegister(DATA_REGISTER_WRITE_PORTC,data) ;
    break;
    case PORT_D :
        SetRegister(DATA_REGISTER_WRITE_PORTD,data) ;
    break;
    case PORT_E :
     //   SetRegister(PORTE,data) ;
    break;
    default :
        /* should not be here */
    break ;
    }
}
void GPIO_SetPortDirection(tPORT port,U8 direction)
{
     switch(port)
    {
    case PORT_A :
        SetRegister(DIRECTION_REGISTER_PORTA,direction) ;
    break;
    case PORT_B :
        SetRegister(DIRECTION_REGISTER_PORTB,direction) ;
    break;
    case PORT_C :
        SetRegister(DIRECTION_REGISTER_PORTD,direction) ;
    break;
    case PORT_D :
        SetRegister(DIRECTION_REGISTER_PORTD,direction) ;
    break;
    case PORT_E :
      //  SetRegister(TRISE,direction) ;
    break;
    default :
        /* should not be here */
    break ;
    }
}
void GPIO_SetPinState(tPORT port , tPIN pin , tSTATE state)
{
    switch(port)
    {
    case PORT_A :
        SetRegisterPin(DATA_REGISTER_WRITE_PORTA,pin,state) ;
    break;
    case PORT_B :
        SetRegisterPin(DATA_REGISTER_WRITE_PORTB,pin,state) ;
    break;
    case PORT_C :
        SetRegisterPin(DATA_REGISTER_WRITE_PORTC,pin,state) ;
    break;
    case PORT_D :
        SetRegisterPin(DATA_REGISTER_WRITE_PORTD,pin,state) ;
    break;
    case PORT_E :
       // SetRegisterPin(PORTE,pin,state) ;
    break;
    default :
        /* should not be here */
    break ;
    }
}
void GPIO_SetPinDirection(tPORT port, tPIN pin ,tPIN_DIRECTION direction)
{
    switch(port)
    {
    case PORT_A :
        SetRegisterPin(DIRECTION_REGISTER_PORTA,pin,direction) ;
    break;
    case PORT_B :
        SetRegisterPin(DIRECTION_REGISTER_PORTB,pin,direction) ;
    break;
    case PORT_C :
        SetRegisterPin(DIRECTION_REGISTER_PORTC,pin,direction) ;
    break;
    case PORT_D :
        SetRegisterPin(DIRECTION_REGISTER_PORTD,pin,direction) ;
    break;
    case PORT_E :
      //  SetRegisterPin(DIRECTION_REGISTER_PORTE,pin,direction) ;
    break;
    default :
        /* should not be here */
    break ;
    }
}
U8 GPIO_GetPortData(tPORT port)
{
    U8 ret = 0 ;
    switch(port)
    {
    case PORT_A :
      ret=  ReadRegisterValue(DATA_REGISTER_READ_PORTA) ;
    break;
    case PORT_B :
      ret=  ReadRegisterValue(DATA_REGISTER_READ_PORTB) ;
    break;
    case PORT_C :
      ret=  ReadRegisterValue(DATA_REGISTER_READ_PORTC) ;
    break;
    case PORT_D :
      ret=  ReadRegisterValue(DATA_REGISTER_READ_PORTD) ;
    break;
    case PORT_E :
     // ret=  ReadRegisterValue(DATA_REGISTER_READ_PORTE) ;
    break;
    default :
        /* should not be here */
    break ;
    }
    return ret ;
}
U8 GPIO_GetPortDirection(tPORT port)
{
    U8 ret = 0 ;
    switch(port)
    {
    case PORT_A :
      ret=  ReadRegisterValue(DIRECTION_REGISTER_PORTA) ;
    break;
    case PORT_B :
      ret=  ReadRegisterValue(DIRECTION_REGISTER_PORTB) ;
    break;
    case PORT_C :
      ret=  ReadRegisterValue(DIRECTION_REGISTER_PORTC) ;
    break;
    case PORT_D :
      ret=  ReadRegisterValue(DIRECTION_REGISTER_PORTD) ;
    break;
    case PORT_E :
    //  ret=  ReadRegisterValue(DIRECTION_REGISTER_PORTE) ;
    break;
    default :
        /* should not be here */
    break ;
    }
    return ret ;
}
tSTATE GPIO_GetPinState(tPORT port , tPIN pin)
{
    tSTATE ret = LOW ;
    switch(port)
    {
    case PORT_A :
      ret=  ReadRegisterPinValue(DATA_REGISTER_READ_PORTA,pin) ;
    break;
    case PORT_B :
      ret=  ReadRegisterPinValue(DATA_REGISTER_READ_PORTB,pin) ;
    break;
    case PORT_C :
      ret=  ReadRegisterPinValue(DATA_REGISTER_READ_PORTC,pin) ;
    break;
    case PORT_D :
      ret=  ReadRegisterPinValue(DATA_REGISTER_READ_PORTD,pin) ;
    break;
    case PORT_E :
     // ret=  ReadRegisterPinValue(DATA_REGISTER_READ_PORTA,pin) ;
    break;
    default :
        /* should not be here */
    break ;
    }
    return ret ;
}
tPIN_DIRECTION GPIO_GetPinDirection(tPORT port, tPIN pin)
{
    tPIN_DIRECTION ret = PIN_OUTPUT ;
    switch(port)
    {
    case PORT_A :
      ret=  ReadRegisterPinValue(DIRECTION_REGISTER_PORTA,pin) ;
    break;
    case PORT_B :
      ret=  ReadRegisterPinValue(DIRECTION_REGISTER_PORTB,pin) ;
    break;
    case PORT_C :
      ret=  ReadRegisterPinValue(DIRECTION_REGISTER_PORTC,pin) ;
    break;
    case PORT_D :
      ret=  ReadRegisterPinValue(DIRECTION_REGISTER_PORTD,pin) ;
    break;
    case PORT_E :
     // ret=  ReadRegisterPinValue(DIRECTION_REGISTER_PORTE,pin) ;
    break;
    default :
        /* should not be here */
    break ;
    }
    return ret ;
}

