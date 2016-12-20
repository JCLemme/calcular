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


double GetEquation (double x)
{
    char equation[100];
    scanf("%s", equation);
    for (int i = 0; i < strlen(equation); i++)
    {
        char tok = equation[i];
        printf("Reading: %c\n", tok);
        if(!isdigit(tok))
        {
            //it's not a number and do not number things
            printf("not a number\n");
            //check for all characters between either NULL and tok or between nth tok and (n+1)th tok
            for (int q = 0; q < i; q++) //doesn't work for multiple operations
            {
                //get all previous characters
                char number = equation[q];
                printf("Previous digit = %c\n", number);
            }
            //if an x is entered, treat it as a double variable
        }
    }
    //return equation with x's
    return 0;
}

int main (int argc, char *argv[])
{
    int x = 5;
    GetEquation(x);
}

//run through entire string and look for sh*t character by character

