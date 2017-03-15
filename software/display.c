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
    
    // And then initialize
    Display_sendCommand(0x01, 0);
    Display_sendCommand(0x11, 0);
    Display_sendCommand(0x29, 0);
    
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
    
    waitcnt(500+CNT);
    
    int i;
    for(i=0;i<8;i++)
    {
        LOW(pinClk);
        (data>>(7-i) & 1) ? HIGH(pinDat) : LOW(pinDat);
        waitcnt(500+CNT);
        HIGH(pinClk);
        waitcnt(500+CNT);
    }
    
    HIGH(pinCS);
    
    waitcnt(500+CNT);
        
    return 0;
}

int Display_writeBitmapFull(uint8_t* data, uint8_t format)
{   
    // Kill the display for a sec
    //Display_sendCommand(0x28, 0);
    
    // Analog stuff (contrast)
    Display_sendCommand(0xC0, 0);
    Display_sendCommand(0xFF, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0xB5, 0);
    Display_sendCommand(0x00, 1);
    
    // Set initial line
    Display_sendCommand(0x37, 0);
    Display_sendCommand(0x00, 1);
    
    // Send format code (monochrome or greyscale)
    Display_sendCommand(0x38 | (format & 1), 0);
    
    // Initialize DDRAM
    Display_sendCommand(0x3A, 0);
    Display_sendCommand(0x02, 1);
    
    // Set range to edit (0->239, 0->160)
    Display_sendCommand(0x2A, 0);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0xEF, 1);
    Display_sendCommand(0x2B, 0);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x01, 1);
    Display_sendCommand(0x9F, 1);
    
    // Set scan direction
    Display_sendCommand(0x36, 0);
    Display_sendCommand(0xC0, 1);
    
    // Duty 
    Display_sendCommand(0xB0, 0);
    Display_sendCommand(0x9F, 1);
    Display_sendCommand(0xB1, 0);
    Display_sendCommand(0x00, 1);
        
    // Enter scanning mode
    Display_sendCommand(0x2C, 0);
    
    // Write the data
    uint16_t i;
    for(i=0;i<12800;i++)
    {
        Display_sendCommand(data[i], 1);
        Display_sendCommand(data[i], 1);
    }
    
    // And turn the display back on
    Display_sendCommand(0x29, 0);
    
    return 0;
}
    
    
    
    
    
    
