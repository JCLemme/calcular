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

double GetEquation ()
{
    char equation[100];
    scanf("%s", equation);
    for (int i = 0; i <= strlen(equation); i++)
    {
        char tok = equation[i];
        char TOK = equation[i-1];
        printf("%c\n", tok);
        if(isdigit(tok) && !isdigit(TOK))
        {
            //it's a number and do number things
            printf("a number\n");
        }
        else if(!isdigit(tok))
        {
            //it's not a number and do not number things
            printf("not a number\n");
        }
    }
    return 0;
}

int main (int argc, char *argv[])
{
    GetEquation();
}

//run through entire string and look for sh*t character by character

