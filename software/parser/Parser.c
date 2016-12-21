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

//Global Operations
char add = '+';
char subtract = '-';
char multiply = '*';
char divide = '/';
char power = '^';
char openparenthese = '(';
char closeparenthese = ')';
//multiple character: read first, then second, to the nth character
char Log[4] = "log(";
char ln[3] = "ln(";
char Sin[4] = "sin(";


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
        if(!isdigit(tok))
        {
            if (isdigit(equation[i-1]))
            {
                double num = atof(number);
                numbers[q] = num;
                q = q + 1;
                memset(number,0,sizeof number);
            }
        
            switch(tok)
            {
                case ('+'): printf("add\n");
                    break;
                case ('-'): printf("subtract\n");
                    break;
                case ('*'): printf("multiply\n");
                    break;
                case ('/'): printf("divide\n");
                    break;
                case ('^'): printf("power\n");
                    break;
                case ('('): printf("open parenthesis\n");
                    break;
                case (')'): printf("close parenthesis\n");
                    break;
                case ('l'): //could be log or ln so need to test again
                    break;
                case ('x'): //treat as a double variable
                    break;
            }
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
