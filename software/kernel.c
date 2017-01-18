#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spi.h"

#define VERSION "0.1a"

/* Calcular - open source graphing calculator
 * by John Lemme, Jacob Meyerson 2016
 *
 * Kernel - init, loads applications
 */

void main(void)
{
    // Gotta go fast - 0x6F is XTAL1+PLL16X, should be clarified later
    clkset(0x6F, 5000000);
       
    // Begin serial communications (for kernel messages) 
    freopen("FDS:", "w", stdout);
    freopen("FDS:", "w", stderr);
    freopen("FDS:", "r", stdin);
    
    printf("Calcular - Kernel v%s\n", VERSION);
    printf("The kernel is now starting. Please wait.\n");
    
    // Start interface cogs for SPI and I2C
}

//65, 67, 90
