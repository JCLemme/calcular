#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spi.h"
#include "display.h"

#define VERSION "0.1a"

/* Calcular - open source graphing calculator
 * by John Lemme, Jacob Meyerson 2016
 *
 * Kernel - init, loads applications
 */

#define PIN_CS 0
#define PIN_A0 26
#define PIN_DAT 25
#define PIN_CLK 24
#define PIN_RST 27

#define HIGH(x) (OUTA |= (1<<x))
#define LOW(x) (OUTA &= ~(1<<x))

#define WAIT_MS 5000*16

void main(void)
{
    // Gotta go fast - 0x6F is XTAL1+PLL16X, should be clarified later
    clkset(0x6F, 5000000);
    
    // Begin serial communications (for kernel messages) 
    freopen("FDS:9600,31,30", "w", stdout);
    freopen("FDS:9600,31,30", "w", stderr);
    freopen("FDS:9600,31,30", "r", stdin);
    
    printf("Calcular - Kernel v%s\n", VERSION);
    printf("The kernel is now starting. Please wait.\n");
    
    // Start interface cogs for SPI and I2C
    Display_begin(25, 24, 0, 26, 27);
    
    Display_sendCommand(0x01, 0);
    waitcnt(150*WAIT_MS+CNT);
    Display_sendCommand(0x11, 0);
    waitcnt(150*WAIT_MS+CNT);
    Display_sendCommand(0x29, 0);
    waitcnt(5000*WAIT_MS+CNT);
    Display_sendCommand(0x23, 0);
    waitcnt(5000*WAIT_MS+CNT);
}

//65, 67, 90
