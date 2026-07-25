#include "xc.h"

#define RED   0b001
#define GREEN 0b010
#define BLUE  0b100

#define ON 1
#define OFF 0

//init pins
void initPins()
{
    //set initial value
    LATG |= 0x03C0;
    // LATGbits.LATG6 = 1;
    // LATGbits.LATG7 = 1;
    // LATGbits.LATG8 = 1;
    // LATGbits.LATG9 = 1;
    LATF |= 0x0030;
    //set pin to output
    TRISG &= ~0x03C0;
    TRISF &= ~0x0030;
    //set pin to open drain
    ODCG |= 0x03C0;
    ODCF |= 0x0030;
}
//control pins
void blink(const uint8_t ledId, const uint8_t value)
{
    if(ledId & RED)
    {
        if(value == ON)
        {
            LATF &= ~0x0030;
        }
        else
        {
            LATF |= 0x0030;
        }
    }
    if(ledId & GREEN)
    {
        if(value == ON)
        {
            LATG &= ~0x00C0;
        }
        else
        {
            LATG |= 0x00C0;
        }
    }
    if(ledId & BLUE)
    {
        if(value == ON)
        {
            LATG &= ~0x00C0;
        }
        else
        {
            LATG |= 0x00C0;
        }
    }
}

int main(void) {
    initPins();
    blink(BLUE | RED | GREEN, ON);
    while(1){}
    return 0;
}
