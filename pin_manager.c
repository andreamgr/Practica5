
#include "pin_manager.h"
#include "mcc.h"

void PIN_MANAGER_Initialize(void)
{
    //configure ports below this line
    TRISAbits.TRISA0 = 1; //RA/0AN0 is an input
    //RA0/AN0 is the only analog pin
    ADCON1bits.PCFG = 0xE; 
}

void PIN_MANAGER_IOC(void)
{
    
    
}

void PIN_MANAGER_INT0(void)
{
    
}

void PIN_MANAGER_INT1(void)
{
    
}

void PIN_MANAGER_INT2(void)
{
    
}