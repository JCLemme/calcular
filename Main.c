//
//  Main.c
//  
//
//  Created by Jacob Meyerson on 12/15/16.
//
//

#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

using namespace std;

//Global Variables
const double a = 1.0 * (pow(10, -10));
double x, b, c, n, g, u, v, num, den, Vout, Vin, R1, R2;
int minimum = (-5); //minimum x value for table
int maximum = (5); //maximum x value for table
double s = 1; //seconds in between printing
void (*fncPtr)();


//Sub- Functions
//----------------------------------------------------------------------------
double Num (double x) //DecFrac
{
    char Str[30];
    Str = static_cast<ostringstream*>( &(ostringstream() << x) )->str();
    int y = Strlen(Str);
    int num = (x)*(pow(10, (y-1)));
    return num;
}

double Den (double x) //DecFrac
{
    char Str[30];
    Str = static_cast<ostringstream*>( &(ostringstream() << x) )->str();
    int y = Strlen(Str);
    int den = pow(10, (y-1));
    return den;
}

double SimpFrac (double num, double den) //SimpFrac & DecFrac
{
    for (unsigned int x = max(num, den); x <= max(num, den); x--)
    {
        if (remainder(num, x) == 0 && remainder(den, x) == 0)
        {
            double n = (num)/(x);
            double d = (den)/(x);
            printf("%lf/%lf\n", n, d);
            break;
        }
    }
    return 0;
}


double NRoot (double x, double n) //Nth Root
{
    double y = pow((x), (1.0/n));
    printf("Ans = %lf\n", y);
    return 0;
}

double FracDec (double x, double z) //FracDec
{
    double y = (x)/(z);
    printf("Ans = %lf\n", y);
    return 0;
}

double NPower (double x, double n) //NthPower
{
    double y = pow((x), (n));
    printf("Ans = %lf\n", y);
    return 0;
}

double nTimes () //Interest
{
    //P(1+r/n)^nt
    double P, r, n, t;
    printf("Enter P ($), r (%), n (times compounded per year), t (years): \n");
    scanf("%lf %lf %lf %lf", P, r, n, t);
    double r1 = (r/100);
    double A1, A2, A3;
    A1 = (1 + (r1/n));
    A2 = pow(A1, (n*t));
    A3 = A2*P;
    printf("Ans = %lf\n", A3);
    return 0;
}

double Cont () //Interest
{
    //Pe^rt
    double e = 2.71828182846;
    double P, r, n, t;
    printf("Enter P ($), r (%), t (years): \n");
    scanf("%lf %lf %lf", P, r, t);
    double r1 = (r/100);
    double A4, A5;
    A4 = pow(e, (r1*t));
    A5 = P*A4;
    printf("Ans = %lf\n", A5);
    return 0;
}


/*double TheDsCancel (double x) //DyDx
{
    
    double Fx = GetEquation(x);
    double b = x-a;
    double Fb = GetEquation(b);
    double dydx = (Fx - Fb)/(x - b);
    printf("Dy/dx = %lf\n", dydx);
    return 0;
}

double LeftLimit (double X) //Limit
{
    double LHL;
    double x;
    double a = pow(0.1, 5);
    x = X - a;
    double Fx = GetEquation(x);
    printf("F(x) approaches %lf from the left\n", Fx);
    LHL = Fx;
    return LHL;
}

double RightLimit(double X) //Limit
{
    double RHL;
    double x;
    double a = pow(0.1, 5);
    x = X + a;
    double Fx = GetEquation(x);
    printf("F(x) approaches %lf from the right\n", Fx);
    RHL = Fx;
    return RHL;
}

double limit (double L, double R, double X) //Limit
{
    double Lim;
    if (R - L < 0.1 && R >= L )
    {
        Lim = (L + R)/2;
        printf("Limit as x-> %lf = %lf\n", X, Lim);
    }
    
    else if (R - L > 0.1 || R < L)
    {
        printf("The limit does not exist\n");
    }
    return 0;
}
*/

double GenTable () //Table
{
    for (int X = minimum; minimum <= X; X++)
    {
        double Hx = GetEquation(X);
        printf("(%lf, %lf)\n", X, Hx);
        if (X == maximum)
        {
            break;
        }
        usleep(s*(pow(10, 6)));
    }
    return 0;
}

double LogBase (double g, double x) //Logarithm
{
    double Log = (log(x))/(log(g));
    printf("Ans = %lf\n", Log);
    return 0;
}

double Addition (double x, double y) //FourOp
{
    double h = (x) + (y);
    printf("Ans = %lf\n", h);
    return 0;
}

double Subtraction (double x, double y) //FourOp
{
    double h = (x) - (y);
    printf("Ans = %lf\n", h);
    return 0;
}

double Multiplication (double x, double y) //FourOp
{
    double h = (x)*(y);
    printf("Ans = %lf\n", h);
    return 0;
}

double Division (double x, double y) //FourOp
{
    double h = (x)/(y);
    printf("Ans = %lf\n", h);
    return 0;
}

double Quad (double a, double b, double c) //Quadratic
{
    double x, y;
    x = ((-(b)) + (sqrt(((b)*(b))-4*(a)*(c))))/(2*(a));
    y = ((-(b)) - (sqrt(((b)*(b))-4*(a)*(c))))/(2*(a));
    printf("x= %lf, %lf\n", x, y);
    return 0;
}

double Dist (double x1, double x2, double y1, double y2) //Distance
{
    double D1, D2, D3;
    D1 = (x2 - x1)*(x2 - x1);
    D2 = (y2 - y1)*(y2 - y1);
    D3 = sqrt((D1+D2));
    printf("Distance = %lf", D3);
    return 0;
}

double Mdpt (double x1, double y1, double x2, double y2) //Midpoint
{
    double M, M1, M2, M3;
    M = (x1 + x2)/2;
    M1 = (y1 + y2)/2;
    printf("The midpoint is (%lf, %lf)", M, M1);
    return 0;
}

double Leg () //Pythagorean
{
    //Solve for Missing Leg
    double a, c;
    printf("Enter a (or b), c:\n");
    scanf("%lf %lf", a, c);
    double b, b2;
    b = (pow(c, 2) - pow(a, 2));
    printf("a (or b) = the square root of %lf", b);
    b2 = sqrt(b);
    printf("a (or b) = %lf", b2);
    return 0;
}

double Hyp () //Pythagorean
{
    //Solve for Hypotenuse
    double a, b;
    printf("Enter a, b: \n");
    scanf("%lf %lf", a, c);
    double c, c1;
    c = (pow(a, 2) + pow(b, 2));
    printf("c = the square root of %lf\n", c);
    c1 = sqrt(c);
    printf("c = %lf\n", c1);
    return 0;
}

double VOUT () //VoltageDivider
{
    printf("Enter: Vin, R1, R2\n");
    scanf("%lf %lf %lf", Vin, R1, R2);
    Vout = Vin * ((R2)/(R1+R2));
    printf("Vout = %lf\n", Vout);
    return 0;
}

double VIN () //VoltageDivider
{
    printf("Enter Vout, R1, R2\n");
    scanf("%lf %lf %lf", Vout, R1, R2);
    Vin = (Vout * (R1 + R2))/(R2);
    printf("Vin = %lf\n", Vin);
    return 0;
}

double r1 () //VoltageDivider
{
    printf("Enter Vout, Vin, R2\n");
    scanf("%lf %lf %lf", Vout, Vin, R2);
    R1 = (R2 * (Vin - Vout))/(Vout);
    printf("R1 = %lf\n", R1);
    return 0;
}

double r2 () //VoltageDivider
{
    printf("Enter Vout, Vin, R1\n");
    scanf("%lf %lf %lf", Vout, Vin, R1);
    R2 = (Vout * R1)/(Vin - Vout);
    printf("R2 = %lf\n", R2);
    return 0;
}

//Functions
//----------------------------------------------------------------------------
void Pythagorean ()
{
    int pythagoras;
    printf("1) Solve for Missing Leg\n2) Solve for Hypotenuse\n");
    scanf("%i", pythagoras);
    switch (pythagoras)
    {
        case (1): Leg();
            break;
        case (2): Hyp();
            break;
    }
}

void VoltageDivider ()
{
    printf("1) Vout\n2) Vin\n3) R1\n4) R2\n");
    int input;
    scanf("%i", input);
    switch (input)
    {
        case (1): VOUT();
            break;
        case (2): VIN();
            break;
        case (3): r1();
            break;
        case (4): r2();
            break;
    }
}
void Midpoint ()
{
    double X1, X2, Y1, Y2;
    printf("Enter X1, Y1, X2, Y2 (order specific)\n");
    scanf("%lf %lf %lf %lf", X1, Y1, X2, Y2);
    Mdpt(X1, Y1, X2, Y2);
}

void Quadratic ()
{
    double A, B, C;
    printf("Enter a, b, c:\n");
    scanf("%lf %lf %lf", A, B, C);
    Quad(A, B, C);
}

void Distance ()
{
    double X2, X1, Y2, Y1;
    printf("Enter X1, Y1, X2, Y2 (order specific)\n");
    scanf("%lf %lf %lf %lf", X1, Y1, X2, Y2);
    Dist (X1, X2, Y1, Y2);
}

void FourOperation ()
{
    printf("Enter 1st number\n");
    scanf("%lf", u);
    printf("Enter operation\n");
    char op[1];
    scanf("%s", op);
    printf("Enter 2nd number\n");
    scanf("%lf", v);
    if (op == "+")
    {
        Addition(u, v);
    }
    else if (op == "-")
    {
        Subtraction(u, v);
    }
    else if (op == "*")
    {
        Multiplication(u, v);
    }
    else if (op == "/")
    {
        Division(u, v);
    }
}

void Logarithm ()
{
    printf("LogBASE a of x\nEnter base: \n");
    scanf("%lf", g);
    printf("Enter x: \n");
    scanf("%lf", x);
    LogBase(g, x);
}

void NthPower ()
{
    printf("Enter base: \n");
    scanf("%lf", x);
    printf("Enter power: \n");
    scanf("%lf", n);
    NPower(x, n);
}

void FractionDecimal ()
{
    printf("Enter fraction: \n");
    char frac[30];
    scanf("%s", frac);
    
    int cpos=frac.find_first_of('/');
    char n[30];
    char d[30];
    n = frac.substr (0, cpos);
    d = frac.substr (cpos + 1, strlen(frac));
    float num = atof(n.c_str());
    float den = atof(d.c_str());
    
    FracDec(num, den);
}

void DecimalFraction ()
{
    printf("Enter decimal: \n");
    scanf("%lf", x);
    b = Num(x);
    c = Den(x);
    SimpFrac(b, c);
}

void SimplifyFraction ()
{
    printf("Enter fraction: \n");
    char frac[30];
    scanf("%s", frac);
    
    int cpos=frac.find_first_of('/');
    char n[30];
    char d[30];
    n = frac.substr (0, cpos);
    d = frac.substr (cpos + 1, strlen(frac));
    double Num = atof(N.c_str());
    double Den = atof(D.c_str());
    SimpFrac(Num, Den);
}

void NthRoot ()
{
    printf("Enter root: \n");
    scanf("%lf", n);
    printf("Enter x: \n");
    scanf("%lf", x);
    NRoot(x, n);
}

void Derivative ()
{
    printf("Enter Function: y = \n");
    char expression_string[30];
    scanf("%s", expression_string);
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    double X;
    printf("Enter x value: \n");
    scanf("%lf", X);
    printf("\n");
    TheDsCancel (X);
}

void Limit ()
{
    printf("Enter Function: y = \n");
   char expression_string[30];
    scanf("%s", expression_string);
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    double x;
    printf("Enter x value: \n");
    scanf("%lf", x);
    printf("\n");
    double L = LeftLimit (x);
    double R = RightLimit (x);
    limit (L, R, x);
}

void Table ()
{
    printf("Enter Function: y = \n");
    char expression_string[30];
    scanf("%s", expression_string);
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    GenTable();
}

void Interest ()
{
    int compound;
    printf("1) Compound Daily/ Weekly/ etc.\n2) Compound Cotinuously\n");
    scanf("%i", compound);
    switch (compound)
    {
        case (1): nTimes();
            break;
        case (2): Cont();
            break;
    }
}

void ModeSelect ()
{
    int mode;
    printf("Select Mode: \n1) DecFrac\n2) FracDec\n3) Limit\n4) Derivative\n5) Power\n6) Root\n7) Simplify Fraction\n8) Four Operation\n9) Logarithm\n10) Table\n11) Quadratic\n12) Interest\n13) Distance\n14) Pythagorean Theorem\n15) Midpoint\n16) Voltage Divider\n");
    scanf("%i", mode);
    //replace above with button values and such
    switch(mode)
    {
        case (1): fncPtr = &DecimalFraction;
            break;
        case (2): fncPtr = &FractionDecimal;
            break;
        case (3): fncPtr = &Limit;
            break;
        case (4): fncPtr = &Derivative;
            break;
        case (5): fncPtr = &NthPower;
            break;
        case (6): fncPtr = &NthRoot;
            break;
        case (7): fncPtr = &SimplifyFraction;
            break;
        case (8): fncPtr = &FourOperation;
            break;
        case (9): fncPtr = &Logarithm;
            break;
        case (10): fncPtr = &Table;
            break;
        case (11): fncPtr = &Quadratic;
            break;
        case (12): fncPtr = &Interest;
            break;
        case (13): fncPtr = &Distance;
            break;
        case (14): fncPtr = &Pythagorean;
            break;
        case (15): fncPtr = &Midpoint;
            break;
        case (16): fncPtr = &VoltageDivider;
    }
}

//Main Loop
//----------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    ModeSelect();
    (*fncPtr)();
}




