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

int Display_setPixel(uint8_t x, uint8_t y, uint8_t value);
int Display_drawBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t value);
int Display_drawChar(uint8_t x, uint8_t y, uint8_t character, uint8_t *font);
int Display_drawStr(uint8_t x, uint8_t y, uint8_t* character, uint8_t len, uint8_t *font);

int Display_sendCommand(uint8_t data, uint8_t adata);
int Display_update();
int Display_writeBitmapFull(uint8_t* data, uint8_t format);
