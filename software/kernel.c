#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spi.h"
#include "display.h"
#include "testcard_a.h"

#define VERSION "0.1a"

/* Calcular - open source graphing calculator
 * by John Lemme, Jacob Meyerson 2016
 *
 * Kernel - init, loads applications
 */

#define PIN_DSP_CS 0
#define PIN_DSP_A0 26
#define PIN_DSP_DAT 25
#define PIN_DSP_CLK 24
#define PIN_DSP_RST 27

#define PIN_SPI_MOSI 17
#define PIN_SPI_MISO 16
#define PIN_SPI_SCK 18
#define PIN_SPI_IOX 19
#define PIN_SPI_FPU 22
#define PIN_SPI_EXT 21
#define PIN_SPI_SDC 23
#define PIN_SPI_ADC 20

#define HIGH(x) (OUTA |= (1<<x))
#define LOW(x) (OUTA &= ~(1<<x))

#define WAIT_MS 5000*16

int main(void)
{
    // Gotta go fast - 0x6F is XTAL1+PLL16X, should be clarified later
    clkset(0x6F, 5000000);
    
    // Begin serial communications (for kernel messages) 
    freopen("FDS:9600,31,30", "w", stdout);
    freopen("FDS:9600,31,30", "w", stderr);
    freopen("FDS:9600,31,30", "r", stdin);
    
    printf("Calcular - Kernel v%s\n", VERSION);
    printf("The kernel is now starting. Please wait.\n");
    
    // Start interface cogs for submodules
    Display_begin(PIN_DSP_DAT, PIN_DSP_CLK, PIN_DSP_CS, PIN_DSP_A0, PIN_DSP_RST);
    
    uint8_t selectSPI[5] = {PIN_SPI_IOX, PIN_SPI_FPU, PIN_SPI_EXT, PIN_SPI_SDC, PIN_SPI_ADC};
    //SPI_begin(PIN_SPI_MOSI, PIN_SPI_MISO, PIN_SPI_SCK, &selectSPI);
    
    // Testing y'all
    /*SPI_transferSync(0, 0x41);
    SPI_transferSync(0, 0x00);
    SPI_transferSync(0, 0x00);
    SPI_transferSync(0, 0x41);
    SPI_transferSync(0, 0x09);
    SPI_transferSync(0, 0x00);*/
    
    Display_writeBitmapFull(&testcard, 0);
    waitcnt(10000*WAIT_MS+CNT);   
    
    return 0;
}

//65, 67, 90
