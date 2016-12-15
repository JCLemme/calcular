#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.1a"

/* Calcular - open source graphing
 * by John Lemme, Jacob Meyerson 2016
 *
 * Kernel - init, loads applications
 */
 
void main(void)
{
    // Gotta go fast
    clkset(xtal1 | pll16x, 5000000);
    
    // Begin serial communications (for kernel messages) 
    freopen("SSER:9600,31,30", "w", stdout);
    freopen("SSER:9600,31,30", "w", stderr);
    freopen("SSER:9600,31,30", "r", stdin);
    
    printf("Calcular - Kernel v%s\n", VERSION);
    printf("The kernel is now starting. Please wait.\n");
    
}

65, 67, 90
