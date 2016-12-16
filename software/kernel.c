#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    freopen("SSER:9600,31,30", "w", stdout);
    freopen("SSER:9600,31,30", "w", stderr);
    freopen("SSER:9600,31,30", "r", stdin);
    
    printf("Calcular - Kernel v%s\n", VERSION);
    printf("The kernel is now starting. Please wait.\n");
    
    // Start interface cogs for SPI, I2C, etc.
}

//65, 67, 90
