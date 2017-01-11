//
//  Parser.c
//  
//
//  Created by Jacob Meyerson on 12/19/16.
//
//

#include "Parser.h"

struct MathToken functionTokens[64];

double DoMath (double x, MathToken tokenArray[64])
{
    int k = 0;
    int cnt = 0;
    int j;
    double h, s, m;
    for (int p = 0; p <= 64; p++)
    {
        double b = functionTokens[p].number; //the tokens in this array are the actual numbers
        char c = functionTokens[p].operation; //the tokens in this array are the operators
        
        if (c == '(')
        {
            j = p;
            cnt++;
            if (c == ')' && cnt > 0)
            {
                cnt--;
            }
            if (c == ')' && cnt == 0)
            {
                //p is the end
                struct MathToken parenthesesTokens[64];
                for (int g = 0; g <= p; g++)
                {
                    parenthesesTokens[g] = functionTokens[j];
                    j++;
                }
                
            }
        }
        
        /*
        if (c == '+')
        {
            h = functionTokens[p-1].number;
            s = functionTokens[p+1].number;
            m =  h + s;
            printf("result is: %lf\n", m);
        }
        if (c == '-')
        {
            h = functionTokens[p-1].number;
            s = functionTokens[p+1].number;
            m =  h - s;
            printf("result is: %lf\n", m);
        }
         */
    }
    return 0;
}

double GetEquation ()
{
    int q = 0, v = 0;
    char equation[100];
    scanf("%s", equation);
    printf("\n");
    //scan for x
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
    GetEquation();
}
