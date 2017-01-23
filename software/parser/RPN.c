//
//  RPN.c
//  
//
//  Created by Jacob Meyerson on 1/9/17.
//2
//

#include "RPN.h"

void push (double b)
{
    stack[cnt] = b;
    cnt++;
    printf("push = %lf\n", b);
}

double pop ()
{
    stack[cnt] = 0;
    double h = stack[cnt-1];
    cnt--;
    return h;
}

void Swap ()
{
    double f = stack[0];
    double k = stack[1];
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
    stack[0] = k;
    stack[1] = f;
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
}

void Copy ()
{
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
    double t = pop();
    push(t);
    push(t);
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
}

void Drop ()
{
    pop();
}

void Roll ()
{
    double u = pop();
    double v = pop();
    double z = pop();
    push(v);
    push(u);
    push(z);
}

void Add ()
{
    double a = pop();
    double b = pop();
    g = b + a;
    push(g);
    //printf("Number = %lf\n", g);
    printf("stack 0 = %lf\n", stack[0]);
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

void Sin ()
{
    double x = pop();
    printf("pop = %lf\n", x);
    if (RadDeg == 0) //radians
    {
        double y = sin(x);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = sin((pi*x)/(180));
        push(y);
    }
}

void Cos ()
{
    double x = pop();
    if (RadDeg == 0) //radians
    {
        double y = cos(x);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = cos((pi*x)/(180));
        push(y);
    }
}

void Tan ()
{
    double x = pop();
    if (RadDeg == 0) //radians
    {
        double y = tan(x);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = tan((pi*x)/(180));
        push(y);
    }
}

void Sec ()
{
    double x = pop();
    if (RadDeg == 0) //radians
    {
        double y = 1/cos(x);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = 1/cos((pi*x)/(180));
        push(y);
    }
}

void Csc ()
{
    double x = pop();
    if (RadDeg == 0) //radians
    {
        double p = 1/sin(x);
        push(p);
    }
    if (RadDeg == 1)
    {
        double p = 1/sin((pi*x)/(180));
        push(p);
    }
}

void Cot ()
{
    double x = pop();
    if (RadDeg == 0) //radians
    {
        double y = 1/tan(x);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = 1/tan((pi*x)/(180));
        push(y);
    }
}

void Arcsin ()
{
    double x = pop();
    double y = asin(x);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arccos ()
{
    double x = pop();
    double y = acos(x);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arctan ()
{
    double x = pop();
    double y = atan(x);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arcsec ()
{
    double x = pop();
    double y = acos(1/x);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arccsc ()
{
    double x = pop();
    double y = asin(1/x);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arccot ()
{
    double x = pop();
    double y = atan(1/x);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void GetInput()
{
    char inFunc[64];
    
    while(l)
    {
        int inIndex, funcIndex;
        inIndex = 0;
        memset(equation, 0, sizeof(equation));
        fgets(equation, 64, stdin);
        
        while(equation[inIndex] != 0 && inIndex < 64)
        {
            funcIndex = 0;
            memset(inFunc, 0, sizeof(inFunc));

            while(equation[inIndex] != 20 && equation[inIndex] != 0 && equation[inIndex] != 10)
            {
                inFunc[funcIndex] = equation[inIndex];
                funcIndex++;
                inIndex++;
                printf("FU\n");
            }
            
            inIndex++;
            
            if(strspn(inFunc, "-.0123456789 ") == strlen(inFunc))
            {
                push(strtod(inFunc, NULL));
            }
            else
            {
                if(strcmp(inFunc, "+"))
                {
                    Add();
                }
            }
        }
    }
}

void GetEquation ()
{
    while (l)
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
            if ((tok == ' ' || tok == 0x0A) && i == 1) //problem with ownership
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
                i = 0;
            }
            if (tok == 'q')
            {
                l = 0;
                printf("Answer = %lf\n", stack[0]);
            }
            if (tok == 's' && equation[t+1] != 'i')
            {
                Swap();
                i = 0;
            }
            if (tok == 'c' && equation[t+1] != 'o')
            {
                Copy();
                i = 0;
            }
            if (tok == 'd')
            {
                Drop();
                i = 0;
            }
            if (tok == 'r')
            {
                Roll();
                i = 0;
            }
            if (equation[t] == 's' && equation[t+1] == 'i' && equation[t+2] == 'n')
            {
                Sin();
                i = 0;
            }
            if (equation[t] == 'c' && equation[t+1] == 'o' && equation[t+2] == 's')
            {
                Cos();
                i = 0;
            }
            if (tok == '+')
            {
                Add();
                i = 0;
            }
            if (tok == '-')
            {
                Subtract();
                i = 0;
            }
            if (tok == '*')
            {
                Multiply();
                i = 0;
            }
            if (tok == '/')
            {
                Divide();
                i = 0;
            }
            if (tok == '^')
            {
                Power();
                i = 0;
            }
        }
        printf("0: %f\n1: %f\n2: %f\n\n", stack[cnt-1], stack[cnt-2], stack[cnt-3]);
    }
}

int main (int argc, char *argv[])
{
    GetInput();
}

