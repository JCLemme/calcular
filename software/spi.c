#include "spi.h"

static volatile uint8_t pinMosi, pinMiso, pinSclk;
static uint8_t* pinCS;
static volatile uint8_t send, recv, msg;

uint32_t stack[40+32];
uint8_t launchedCog;

int SPI_begin(uint8_t mosi, uint8_t miso, uint8_t sclk, uint8_t* cs)
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

int SPI_end()
{
    cogstop(launchedCog);
    
    return 0;
}

uint8_t SPI_transferSync(uint8_t cs, uint8_t mosi)
{
    while(SPI_transferBegin(cs, mosi) == -1) {}
    waitcnt(TRS_DELAY+CNT);
    while(SPI_transferState() == -1) {}
    return SPI_transferResult(cs);
}

int SPI_transferBegin(int cs, uint8_t mosi)
{
    if(msg != 255)
        return -1;
    
    OUTA &= ~(1<<cs);
    waitcnt(CNT+TRS_DELAY);
    
    send = mosi;
    msg = cs;
    
    return 0;
}

int SPI_transferState()
{
    if(msg != 255)
        return -1;
    else
        return 0;
}

uint8_t SPI_transferResult(int cs)
{
    OUTA |= (1<<cs);
    return recv;
}

inline void SPI_internal()
{
    while(msg == 255) {}
    
    OUTA &= ~(1<<pinSclk);
    waitcnt(CNT+TRS_DELAY);
    
    int i;
    recv = 0;
    
    for(i=0;i<8;i++)
    {
        OUTA |= (1<<pinSclk);
        
        recv |= ((INA & (1<<pinMiso)) << i);
        
        waitcnt(CNT+TRS_DELAY);
        
        OUTA &= ~(1<<pinSclk);
        
        OUTA &= ~(1<<pinMosi);
        OUTA |= (((send & (1 << i)) >> i) << pinMosi);
        
        waitcnt(CNT+TRS_DELAY);
    }
    
    msg = 255;
}
