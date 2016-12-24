//
//  Parser.c
//  
//
//  Created by Jacob Meyerson on 12/19/16.
//
//

#include "Parser.h"

struct MathToken functionTokens[64];

double DoMath ()
{
    for (int p = 0; p <= 64; p++)
    {
        double b = functionTokens[p].number; //the tokens in this array are the actual numbers
        char c = functionTokens[p].operation; //the tokens in this array are the operators
        
        if (c == '+')
        {
            double h = functionTokens[p-1].number;
            double s = functionTokens[p+1].number;
            double m =  h + s;
            if (functionTokens[p].number == 0) //no more numbers
            {
                printf("result is: %lf\n", m);
            }
        }
    }
    return 0;
}

double GetEquation (double x)
{
    int q = 0, v = 0;
    char equation[100];
    scanf("%s", equation);
    char number[60];
    memset(number,0,sizeof number);
    for (int i = 0; i < strlen(equation)+1; i++)
    {
        char tok = equation[i];
        
        if (isdigit(tok) || tok == '.')
        {
            strncat(number, &tok, 1);
        }
        if(!isdigit(tok) && tok != '.')
        {
            if (isdigit(equation[i-1]))
            {
                double num = atof(number);
                functionTokens[q].number = num;
                functionTokens[q].isoperation = 0;
                q++;
                memset(number,0,sizeof number);
            }
        
            functionTokens[q].operation = tok;
            functionTokens[q].isoperation = 1;
            q++;
        }
    }
    
    for(int o = 0; o < q ;o++)
    {
        if(functionTokens[o].isoperation == 1)
        {
            printf("Token %d: Operation \"%c\"\n", o, functionTokens[o].operation);
        }
        else if (functionTokens[o].isoperation == 0)
        {
            printf("Token %d: Number \"%f\"\n", o, functionTokens[o].number);
        }
    }
    DoMath();
    return 0;
}

int main (int argc, char *argv[])
{
    int x = 5;
    GetEquation(x);
}
