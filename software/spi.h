#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t SPI_begin();
uint8_t SPI_end();

uint8_t SPI_transferSync(uint8_t cs, uint8_t mosi);

uint8_t SPI_transferBegin(int cs, uint8_t mosi);
uint8_t SPI_transferState();
uint8_t SPI_transferResult();
