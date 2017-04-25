#include "display.h"

static volatile uint8_t pinDat, pinClk, pinCS, pinA0, pinRst;
static volatile uint8_t framebuffer[9600];

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
    
    // Clear framebuffer
    memset(framebuffer, 0xFF, 9600);
    
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
        
    // Initialize DDRAM
    Display_sendCommand(0x3A, 0);
    Display_sendCommand(0x02, 1);
    
    // Set scan direction
    Display_sendCommand(0x36, 0);
    Display_sendCommand(0xC0, 1);
    
    // Duty 
    Display_sendCommand(0xB0, 0);
    Display_sendCommand(0x9F, 1);
    Display_sendCommand(0xB1, 0);
    Display_sendCommand(0x00, 1);
    
    // Analog stuff (contrast)
    Display_sendCommand(0xC0, 0);
    Display_sendCommand(0xFF, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x30, 0);
    Display_sendCommand(0x00, 1);
    
    return 0;
}

int Display_end()
{
    return 0;
}

int Display_sendCommand(uint8_t data, uint8_t adata)
{
    //Requires -O3
    
    HIGH(pinDat);
    HIGH(pinClk);
    LOW(pinCS);
    (adata) ? HIGH(pinA0) : LOW(pinA0);
    
    waitcnt(180+CNT);
    
    int i;
    for(i=0;i<8;i++)
    {
        LOW(pinClk);
        (data>>(7-i) & 1) ? HIGH(pinDat) : LOW(pinDat);
        waitcnt(150+CNT);
        HIGH(pinClk);
        waitcnt(130+CNT);
    }
    
    HIGH(pinCS);
    
    waitcnt(180+CNT);
        
    return 0;
}

int Display_setPixel(uint8_t x, uint8_t y, uint8_t value)
{
    framebuffer[(60*y)+(int)(x/4)] &= (0xFF & (~(0x3 << ((3-(x%4))*2))));
    framebuffer[(60*y)+(int)(x/4)] |= ((value&0x3) << ((3-(x%4))*2));
    return value;
}

int Display_drawBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t value)
{
    int i, j;
    
    for(i=x;i<x+w;i++)
        for(j=y;j<y+h;j++)
            Display_setPixel(i, j, value);
    
    return 0;
}

int Display_drawChar(uint8_t x, uint8_t y, uint8_t character, uint8_t *font)
{
    int h, n;
    
    for(n=0;n<12;n++)
        for(h=0;h<8;h++)
            Display_setPixel(h+x, n+y, 
            ( ( font[character|(n<<8)] & ( 1 << (7-h) ) ) > 0) ? 0 : 3);
    
    return 0;
}

int Display_drawStr(uint8_t x, uint8_t y, uint8_t* character, uint8_t len, uint8_t *font)
{
    int f;
    
    for(f=0;f<len;f++)
        Display_drawChar(x+(8*f), y, character[f], font);
        
    return 0;
}

int Display_update()
{
    Display_writeBitmapFull(&framebuffer, 0);
    return 0;
}

int Display_writeBitmapFull(uint8_t* data, uint8_t format)
{   
    // Kill the display for a sec
    //Display_sendCommand(0x28, 0);
    
    // Set range to edit (0->239, 0->160)
    Display_sendCommand(0x2A, 0);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x7F, 1);
    Display_sendCommand(0x2B, 0);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x00, 1);
    Display_sendCommand(0x9F, 1);
    
    // Set initial line
    Display_sendCommand(0x37, 0);
    Display_sendCommand(0x00, 1);
    
    // Send format code (monochrome or greyscale)
    Display_sendCommand(0x38 | (format & 1), 0);

        
    // Enter scanning mode
    Display_sendCommand(0x2C, 0);
    
    // Write the data
    uint16_t i, j;
    for(i=0;i<160;i++)
    {
            
        for(j=0;j<8;j++)
            Display_sendCommand(0xFF, 1);
            
        for(j=0;j<60;j++)
        {
            uint8_t work = data[(60*i)+j], first, second;
            
            switch((work&0x30) >> 4)
            {
                case(0): first = 0x00; break;
                case(1): first = 0x40; break;
                case(2): first = 0x80; break;
                case(3): first = 0xE0; break;
            }
            
            switch((work&0xC0) >> 6)
            {
                case(0): first |= 0x00; break;
                case(1): first |= 0x08; break;
                case(2): first |= 0x10; break;
                case(3): first |= 0x1C; break;
            }
            
            switch((work&0x03) >> 0)
            {
                case(0): second = 0x00; break;
                case(1): second = 0x40; break;
                case(2): second = 0x80; break;
                case(3): second = 0xE0; break;
            }
            
            switch((work&0x0C) >> 2)
            {
                case(0): second |= 0x00; break;
                case(1): second |= 0x08; break;
                case(2): second |= 0x10; break;
                case(3): second |= 0x1C; break;
            }
            
            Display_sendCommand(~first, 1);
            Display_sendCommand(~second, 1);
        }

    }
    
    // And turn the display back on
    Display_sendCommand(0x29, 0);
    
    return 0;
}
    
    
    
    
    
    
