#include <propeller.h>
#include <cog.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRS_DELAY (_CLKFREQ >> 5)

/*

What this needs to do:

* Reset/clear the display
* Allow editing of framebuffer directly
* Blit graphics in memory to display
* Print text on display
* Scroll display
* Cog to update from framebuffer

*/


