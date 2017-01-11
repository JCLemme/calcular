//
//  RPNEquation.c
//  
//
//  Created by Jacob Meyerson on 1/10/17.
//
//

#include "RPNEquation.h"

double stack[64];
int cnt = 0;
char op;
char equation[64];
char number[64];
int i = 0;
double g;
int j = 0;

void push (double b)
{
    stack[cnt] = b;
    cnt++;
    //printf("Push %lf\n", b);
}

double pop ()
{
    stack[cnt] = 0;
    double h = stack[cnt-1];
    cnt--;
    return h;
}

double Add ()
{
    double a = pop();
    double b = pop();
    g = b + a;
    push(g);
    return g;
}

double Subtract ()
{
    double a = pop();
    double b = pop();
    g = b - a;
    push(g);
    return g;
}

double Multiply ()
{
    double a = pop();
    double b = pop();
    g = b * a;
    push(g);
    return g;
}

double Divide ()
{
    double a = pop();
    double b = pop();
    g = b / a;
    push(g);
    return g;
}

double Power ()
{
    double a = pop();
    double b = pop();
    g = pow(b, a);
    push(g);
    return g;
}

double operation (char operation)
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
    return g;
}

void GetEquation ()
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
    }
    printf("Answer = %lf\n", g);
}

int main (int argc, char *argv[])
{
    GetEquation();
}


