#include "display.h"

static volatile uint8_t pinDat, pinClk, pinCS, pinA0, pinRst;

int Display_begin(uint8_t data, uint8_t clock, uint8_t cs, uint8_t a0, uint8_t rst)
{
    // Initialize pin assignments
    pinDat = data;
    pinClk = clock;
    pinCS = cs;
    pinA0 = a0;
    pinRst = rst;
    
    DIRA |= (1<<pinDat) | (1<<pinClk) | (1<<pinCS) | (1<<pinA0) | (1<<pinRst);
    
    HIGH(pinRst);
    HIGH(pinCS);
    HIGH(pinClk);
    LOW(pinA0);
    
    // Reset display
    waitcnt(10*WAIT_MS+CNT);
    LOW(pinRst);
    waitcnt(15*WAIT_MS+CNT);
    HIGH(pinRst);
    waitcnt(150*WAIT_MS+CNT);
    
    return 0;
}

int Display_end()
{
    return 0;
}

int Display_sendCommand(uint8_t data, uint8_t adata)
{
    HIGH(pinDat);
    HIGH(pinClk);
    LOW(pinCS);
    (adata) ? HIGH(pinA0) : LOW(pinA0);
    
    waitcnt(10*WAIT_MS+CNT);
    
    int i;
    for(i=0;i<8;i++)
    {
        LOW(pinClk);
        (data>>(7-i) & 1) ? HIGH(pinDat) : LOW(pinDat);
        waitcnt(3*WAIT_MS+CNT);
        HIGH(pinClk);
        waitcnt(3*WAIT_MS+CNT);
    }
    
    HIGH(pinCS);
    
    return 0;
}

int Display_writeBitmap(uint8_t data, 
