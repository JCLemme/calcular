//
//  Parser.c
//  
//
//  Created by Jacob Meyerson on 12/19/16.
//
//

#include "Parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//Global array
double numbers[128];
char operations[128];

double GetEquation (double x)
{
    int q = 0;
    char equation[100];
    scanf("%s", equation);
    char number[60];
    memset(number,0,sizeof number);
    for (int i = 0; i < strlen(equation)+1; i++)
    {
        char tok = equation[i];
        if (isdigit(tok))
        {
            strncat(number, &tok, 1);
        }
        else if(!isdigit(tok))
        {
            //convert string "number" to a number
            double num = atof(number);
            //pass the number to one spot in a dynamic array
            numbers[q] = num;
            q = q + 1;
            //reset string "number"
            memset(number,0,sizeof number);
        }
    }
    //return equation with x's
    //if an x is entered, treat it as a double variable
    printf("number 1 = %lf\n", numbers[0]);
    printf("number 2 = %lf\n", numbers[1]);
    printf("number 3 = %lf\n", numbers[2]);
    return 0;
}

int main (int argc, char *argv[])
{
    int x = 5;
    GetEquation(x);
}
