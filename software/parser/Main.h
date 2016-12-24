//
//  Main.h
//  
//
//  Created by Jacob Meyerson on 12/15/16.
//
//

#ifndef Main_h
#define Main_h

#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

//Global Variables
const double a = 0.0000000001;
const double pi = 3.14159265358979323846264;
double x, b, c, n, g, u, v, num, den, Vout, Vin, R1, R2;
int minimum = (-5); //minimum x value for table
int maximum = (5); //maximum x value for table
double s = 1; //seconds in between printing
void (*fncPtr)();

#endif /* Main_h */
