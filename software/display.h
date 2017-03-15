#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HIGH(x) (OUTA |= (1<<x))
#define LOW(x) (OUTA &= ~(1<<x))

#define WAIT_MS 5000*16

int Display_begin(uint8_t data, uint8_t clock, uint8_t cs, uint8_t a0, uint8_t rst);
int Display_end();

int Display_sendCommand(uint8_t data, uint8_t adata);
int Display_writeBitmapFull(uint8_t* data, uint8_t format);
