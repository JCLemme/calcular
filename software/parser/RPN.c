//
//  RPN.c
//  
//
//  Created by Jacob Meyerson on 1/9/17.
//
//

#include "RPN.h"

void push (double b)
{
    stack[cnt] = b;
    cnt++;
    //printf("push = %lf\n", b);
}

double pop ()
{
    stack[cnt] = 0;
    double h = stack[cnt-1];
    cnt--;
    return h;
}

void Add ()
{
    double a = pop();
    double b = pop();
    g = b + a;
    push(g);
    //printf("Number = %lf\n", g);
}

void Subtract ()
{
    double a = pop();
    double b = pop();
    g = b - a;
    push(g);
    //printf("Number = %lf\n", g);
}

void Multiply ()
{
    double a = pop();
    double b = pop();
    g = b * a;
    push(g);
    //printf("Number = %lf\n", g);
}

void Divide ()
{
    double a = pop();
    double b = pop();
    g = b / a;
    push(g);
    //printf("Number = %lf\n", g);
}

void Power ()
{
    double a = pop();
    double b = pop();
    g = pow(b, a);
    push(g);
    //printf("Number = %lf\n", g);
}

void operation (char operation)
{
    operation = op;
    switch (operation)
    {
        case ('+'): Add();
            break;
        case ('-'): Subtract();
            break;
        case ('*'): Multiply();
            break;
        case ('/'): Divide();
            break;
        case ('^'): Power();
            break;
    }
}

void GetEquation ()
{
    while (l == 1)
    {
        double w, x;
        fgets(equation, 64, stdin);
        memset(number,0,sizeof number);
        for (int t = 0; t < strlen(equation); t++)
        {
            //printf("string length = %lu\n", strlen(equation));
            char tok = equation[t];
            
            if (isdigit(tok) || tok == '.')
            {
                strncat(number, &tok, 1);
                i = 1;
            }
            if (tok == ' ' && i == 1)
            {
                w = atof(number);
                //printf("w = %lf\n", w);
                push(w);
                memset(number,0,sizeof number);
            }
            if (tok == 'x')
            {
                if (j == 0)
                {
                    printf("Enter x: ");
                    scanf("%lf", &x);
                    j = 1;
                }
                push(x);
                i = 2;
            }
            if (!isdigit(tok) && tok != '.' && tok != ' ' && tok != '\0' && tok != 0x0A  && tok != 'x')
            {
                i = 0;
                //printf("Operation = %c\n", equation[t]);
                op = equation[t];
                operation(op);
            }
            if (equation[0] == 'q')
            {
                l = 0;
            }
        }
        if (equation[0] != 'q')
        {
            printf("Answer = %lf\n", stack[0]);
        }
    }
    
}

int main (int argc, char *argv[])
{
    GetEquation();
}

