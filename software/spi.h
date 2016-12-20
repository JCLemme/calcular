#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRS_DELAY (_CLKFREQ >> 5)

int SPI_begin();
int SPI_end();

uint8_t SPI_transferSync(uint8_t cs, uint8_t mosi);

int SPI_transferBegin(int cs, uint8_t mosi);
int SPI_transferState();
uint8_t SPI_transferResult();

// WARNING! SPI_transferResult doesn't check to see if a transfer has completed. 
//          Use SPI_transferState before calling it to make sure the result is valid.
