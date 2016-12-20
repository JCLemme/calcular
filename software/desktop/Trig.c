//
//  Trig.c
//  
//
//  Created by Jacob Meyerson on 12/20/16.
//
//

#include "Trig.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
const double pi = 3.14159265358979323846264;

double Sin ()
{
    printf("sin(");
    double x;
    scanf("%lf", &x);
    double y = sin((pi*x)/(180));
    printf("\nsin%lf = %lf\n", x, y);
    return 0;
}

double Cos ()
{
    printf("cos(");
    double x;
    scanf("%lf", &x);
    double y = cos((pi*x)/(180));
    printf("\ncos%lf = %lf\n", x, y);
    return 0;
}

double Tan ()
{
    printf("tan(");
    double x;
    scanf("%lf", &x);
    double y = tan((pi*x)/(180));
    printf("\ntan%lf = %lf\n", x, y);
    return 0;
}

double Sec ()
{
    printf("sec(");
    double x;
    scanf("%lf", &x);
    double y = 1/(cos((pi*x)/(180)));
    printf("\nsec%lf = %lf\n", x, y);
    return 0;
}

double Csc ()
{
    printf("csc(");
    double x;
    scanf("%lf", &x);
    double y = 1/(sin((pi*x)/(180)));
    printf("\ncsc%lf = %lf\n", x, y);
    return 0;
}

double Cot ()
{
    printf("cot(");
    double x;
    scanf("%lf", &x);
    double y = 1/(tan((pi*x)/(180)));
    printf("\ncot%lf = %lf\n", x, y);
    return 0;
}

double Arcsin ()
{
    printf("arcsin(");
    double x;
    scanf("%lf", &x);
    double y = asin(x);
    double z = (y*180)/(pi);
    printf("\narcsin%lf = %lf\n", x, z);
    return 0;
}

double Arccos ()
{
    printf("arccos(");
    double x;
    scanf("%lf", &x);
    double y = acos(x);
    double z = (y*180)/(pi);
    printf("\narccosn%lf = %lf\n", x, z);
    return 0;
}

double Arctan ()
{
    printf("arctan(");
    double x;
    scanf("%lf", &x);
    double y = atan(x);
    double z = (y*180)/(pi);
    printf("\narctan%lf = %lf\n", x, z);
    return 0;
}

double Arcsec ()
{
    printf("arcsec(");
    double x;
    scanf("%lf", &x);
    double y = acos(1/x);
    double z = (y*180)/(pi);
    printf("\narcsec%lf = %lf\n", x, z);
    return 0;
}

double Arccsc ()
{
    printf("arccsc(");
    double x;
    scanf("%lf", &x);
    double y = asin(1/x);
    double z = (y*180)/(pi);
    printf("\narccsc%lf = %lf\n", x, z);
    return 0;
}

double Arccot ()
{
    printf("arccot(");
    double x;
    scanf("%lf", &x);
    double y = atan(1/x);
    double z = (y*180)/(pi);
    printf("\narccot%lf = %lf\n", x, z);
    return 0;
}

int main (int argc, char *argv[])
{
    printf("1) sin\n2) cos\n3) tan\n4) sec\n5) csc\n6) cot\n7) arcsin\n8) arccos\n9) arctan\n10) arcsec\n11) arccsc\n12) arccot\n");
    int input;
    scanf("%i", &input);
    switch (input)
    {
        case (1): Sin();
            break;
        case (2): Cos();
            break;
        case (3): Tan();
            break;
        case (4): Sec();
            break;
        case (5): Csc();
            break;
        case (6): Cot();
            break;
        case (7): Arcsin();
            break;
        case (8): Arccos();
            break;
        case (9): Arctan();
            break;
        case (10): Arcsec();
            break;
        case (11): Arccsc();
            break;
        case (12): Arccot();
            break;
    }

}

