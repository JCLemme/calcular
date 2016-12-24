//
//  Parser.h
//  
//
//  Created by Jacob Meyerson on 12/19/16.
//
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct MathToken
{
    double number;
    char operation;
    int isoperation; //0 = number, 1 = operation
};

#endif /* Parser_h */
