#include "spi.h"

static volatile uint8_t pinMosi, pinMiso, pinSclk;
static volatile uint8_t* pinCS;
static volatile uint8_t send, recv, msg;

uint32_t stack[40+32];
uint8_t launchedCog;

uint8_t SPI_begin(uint8_t mosi, uint8_t miso, uint8_t sclk, uint8_t* cs)
{
    pinMosi = mosi;
    pinMiso = miso;
    pinSclk = sclk;

    DIRA |= (1<<pinMosi) | (1<<pinSclk);
    DIRA &= ~(1<<pinMiso);
    
    int ptr = 0;
    while(cs[ptr] != 0)
    {
        DIRA |= (1<<cs[ptr]);
        OUTA |= (1<<cs[ptr]);
        ptr++;
    }
    
    pinCS = malloc(sizeof(uint8_t) * ptr);
    memcpy(pinCS, cs, sizeof(uint8_t) * ptr);
    
    send = 0;
    recv = 0;
    msg = 255;
    
    launchedCog = cogstart(SPI_internal, NULL, stack, sizeof(stack));
    
    return launchedCog;
}

uint8_t SPI_end()
{
    cogstop(launchedCog);
    
    return 0;
}

uint8_t SPI_transferSync(uint8_t cs, uint8_t mosi)
{
    return 0;
}

uint8_t SPI_transferBegin(int cs, uint8_t mosi)
{
    return 0;
}

uint8_t SPI_transferState()
{
    return 0;
}

uint8_t SPI_transferResult()
{
    return 0;
}

inline void SPI_internal()
{
    while(msg == 255) {}
    
    OUTA &= ~(1<<msg);
    waitcnt(cnt+(_CLKFREQ >> 5));
    
    OUTA &= ~(1<<pinSclk);
    waitcnt(cnt+(_CLKFREQ >> 5));
    
    int i;
    recv = 0;
    
    for(i=0;i<8;i++)
    {
        OUTA |= (1<<pinSclk);
        
        recv <<= 1;
        recv += (INA & (1<<pinMiso));
        
        waitcnt(cnt+(_CLKFREQ >> 5));
        
        OUTA &= ~(1<<pinSclk);
        
        OUTA &= ~(1<<pinMosi);
        OUTA |= (send
        
        waitcnt(cnt+(_CLKFREQ >> 5));
}
