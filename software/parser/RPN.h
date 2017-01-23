//
//  RPN.h
//  
//
//  Created by Jacob Meyerson on 1/9/17.
//
//

#ifndef RPN_h
#define RPN_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

double stack[64];
int cnt = 0;
char op;
char equation[64];
char number[64];
double g;
int i = 0;
int j = 0;
int l = 1;

//Mode Functions
int RadDeg = 1;
double pi = 3.14159265358979323846264;


#endif /* RPN_h */
