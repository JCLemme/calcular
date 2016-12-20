//
//  Main.c
//  
//
//  Created by Jacob Meyerson on 12/15/16.
//
//

#include "Main.h"

//Sub- Functions
//------------------------------------------------------------------------
double Num (double x) //DecFrac
{
    char string[100];
    int y = sprintf(string, "%lf", x);
    int num = (x)*(pow(10, (y-1)));
    return num;
}

double Den (double x) //DecFrac
{
    char string[30];
    int y = sprintf(string, "%lf", x);
    int den = pow(10, (y-1));
    return den;
}

double SimpFrac (double num, double den) //SimpFrac & DecFrac
{
    for (unsigned int x = fmax(num, den); x <= fmax(num, den); x--)
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
    printf("Enter P ($), r (%%), n (times compounded per year), t (years): \n");
    scanf("%lf %lf %lf %lf", &P, &r, &n, &t);
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
    printf("Enter P ($), r (%%), t (year): \n");
    scanf("%lf %lf %lf", &P, &r, &t);
    double r1 = (r/100);
    double A4, A5;
    A4 = pow(e, (r1*t));
    A5 = P*A4;
    printf("Ans = %lf\n", A5);
    return 0;
}

double Sin () //trig
{
    printf("sin(");
    double x;
    scanf("%lf", &x);
    double y = sin((pi*x)/(180));
    printf("\nsin%lf = %lf\n", x, y);
    return 0;
}

double Cos () //trig
{
    printf("cos(");
    double x;
    scanf("%lf", &x);
    double y = cos((pi*x)/(180));
    printf("\ncos%lf = %lf\n", x, y);
    return 0;
}

double Tan () //trig
{
    printf("tan(");
    double x;
    scanf("%lf", &x);
    double y = tan((pi*x)/(180));
    printf("\ntan%lf = %lf\n", x, y);
    return 0;
}

double Sec () //trig
{
    printf("sec(");
    double x;
    scanf("%lf", &x);
    double y = 1/(cos((pi*x)/(180)));
    printf("\nsec%lf = %lf\n", x, y);
    return 0;
}

double Csc () //trig
{
    printf("csc(");
    double x;
    scanf("%lf", &x);
    double y = 1/(sin((pi*x)/(180)));
    printf("\ncsc%lf = %lf\n", x, y);
    return 0;
}

double Cot () //trig
{
    printf("cot(");
    double x;
    scanf("%lf", &x);
    double y = 1/(tan((pi*x)/(180)));
    printf("\ncot%lf = %lf\n", x, y);
    return 0;
}

double Arcsin () //trig
{
    printf("arcsin(");
    double x;
    scanf("%lf", &x);
    double y = asin(x);
    double z = (y*180)/(pi);
    printf("\narcsin%lf = %lf\n", x, z);
    return 0;
}

double Arccos () //trig
{
    printf("arccos(");
    double x;
    scanf("%lf", &x);
    double y = acos(x);
    double z = (y*180)/(pi);
    printf("\narccosn%lf = %lf\n", x, z);
    return 0;
}

double Arctan () //trig
{
    printf("arctan(");
    double x;
    scanf("%lf", &x);
    double y = atan(x);
    double z = (y*180)/(pi);
    printf("\narctan%lf = %lf\n", x, z);
    return 0;
}

double Arcsec () //trig
{
    printf("arcsec(");
    double x;
    scanf("%lf", &x);
    double y = acos(1/x);
    double z = (y*180)/(pi);
    printf("\narcsec%lf = %lf\n", x, z);
    return 0;
}

double Arccsc () //trig
{
    printf("arccsc(");
    double x;
    scanf("%lf", &x);
    double y = asin(1/x);
    double z = (y*180)/(pi);
    printf("\narccsc%lf = %lf\n", x, z);
    return 0;
}

double Arccot () //trig
{
    printf("arccot(");
    double x;
    scanf("%lf", &x);
    double y = atan(1/x);
    double z = (y*180)/(pi);
    printf("\narccot%lf = %lf\n", x, z);
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


double GenTable () //Table
{
    for (int X = minimum; minimum <= X; X++)
    {
        double Hx = GetEquation(X);
        printf("(%lf, %lf)\n", &X, &Hx);
        if (X == maximum)
        {
            break;
        }
        delay(s*(pow(10, 3)));
    }
    return 0;
}
*/

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

double Quad (double A, double B, double C) //Quadratic
{
    double x, y;
    x = ((-(B)) + (sqrt(((B)*(B))-4*(A)*(C))))/(2*(A));
    y = ((-(B)) - (sqrt(((B)*(B))-4*(A)*(C))))/(2*(A));
    printf("x= %lf, %lf\n", x, y);
    return 0;
}

double Dist (double x1, double x2, double y1, double y2) //Distance
{
    double D1, D2, D3;
    D1 = (x2 - x1)*(x2 - x1);
    D2 = (y2 - y1)*(y2 - y1);
    D3 = sqrt((D1+D2));
    printf("Distance = %lf\n", D3);
    return 0;
}

double Mdpt (double x1, double y1, double x2, double y2) //Midpoint
{
    double M, M1, M2, M3;
    M = (x1 + x2)/2;
    M1 = (y1 + y2)/2;
    printf("The midpoint is {%lf, %lf}\n", M, M1);
    return 0;
}

double Leg () //Pythagorean
{
    //Solve for Missing Leg
    double A, C;
    printf("Enter a {or b}, c:\n");
    scanf("%lf %lf", &A, &C);
    double B, B2;
    B = (pow(C, 2) - pow(A, 2));
    printf("a {or b} = the square root of %lf\n", B);
    B2 = sqrt(B);
    printf("a {or b} = %lf\n", B2);
    return 0;
}

double Hyp () //Pythagorean
{
    //Solve for Hypotenuse
    double A, B;
    printf("Enter a, b: \n");
    scanf("%lf %lf", &A, &B);
    double C, C1;
    C = (pow(A, 2) + pow(B, 2));
    printf("c = the square root of %lf\n", C);
    C1 = sqrt(C);
    printf("c = %lf\n", C1);
    return 0;
}

double VOUT () //VoltageDivider
{
    printf("Enter: Vin, R1, R2\n");
    scanf("%lf %lf %lf", &Vin, &R1, &R2);
    Vout = Vin * ((R2)/(R1+R2));
    printf("Vout = %lf\n", Vout);
    return 0;
}

double VIN () //VoltageDivider
{
    printf("Enter Vout, R1, R2\n");
    scanf("%lf %lf %lf", &Vout, &R1, &R2);
    Vin = (Vout * (R1 + R2))/(R2);
    printf("Vin = %lf\n", Vin);
    return 0;
}

double r1 () //VoltageDivider
{
    printf("Enter Vout, Vin, R2\n");
    scanf("%lf %lf %lf", &Vout, &Vin, &R2);
    R1 = (R2 * (Vin - Vout))/(Vout);
    printf("R1 = %lf\n", R1);
    return 0;
}

double r2 () //VoltageDivider
{
    printf("Enter Vout, Vin, R1\n");
    scanf("%lf %lf %lf", &Vout, &Vin, &R1);
    R2 = (Vout * R1)/(Vin - Vout);
    printf("R2 = %lf\n", R2);
    return 0;
}

double RadtoDeg () //radians degrees
{
    double x;
    scanf("%lf", &x);
    double y = (180*x)/(pi);
    printf("Ans = %lf\n", y);
    return 0;
}

double DegtoRad () //radians degrees
{
    double x;
    scanf("%lf", &x);
    double y = (pi*x)/(180);
    printf("Ans = %lf\n", y);
    return 0;
}

//Functions
//------------------------------------------------------------------------
void Pythagorean ()
{
    int pythagoras;
    printf("1) Solve for Missing Leg\n2) Solve for Hypotenuse\n");
    scanf("%i", &pythagoras);
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
    scanf("%i", &input);
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
    printf("Enter X1, Y1, X2, Y2 {order specific}\n");
    scanf("%lf %lf %lf %lf", &X1, &Y1, &X2, &Y2);
    Mdpt(X1, Y1, X2, Y2);
}

void Quadratic ()
{
    double A, B, C;
    printf("Enter a, b, c:\n");
    scanf("%lf %lf %lf", &A, &B, &C);
    Quad(A, B, C);
}

void Distance ()
{
    double X2, X1, Y2, Y1;
    printf("Enter X1, Y1, X2, Y2 {order specific}\n");
    scanf("%lf %lf %lf %lf", &X1, &Y1, &X2, &Y2);
    Dist (X1, X2, Y1, Y2);
}

void FourOperation ()
{
    printf("Enter equation: \n");
    char form[100];
    scanf("%s", form);
    
    char *saveptr;
    char *U, *V;
    U = strtok_r(form, "+", &saveptr);
    V = strtok_r(NULL, "+", &saveptr);
    if (V > 0)
    {
        printf("Add\n");
        double u = atof(U);
        double v = atof(V);
        Addition(u, v);
        printf("Adding\n");
    }
    
    U = strtok_r(form, "-", &saveptr);
    V = strtok_r(NULL, "-", &saveptr);
    if (V > 0)
    {
        printf("Subtract\n");
        double u = atof(U);
        double v = atof(V);
        Subtraction(u, v);
        printf("Subtracting\n");
    }
    
    U = strtok_r(form, "*", &saveptr);
    V = strtok_r(NULL, "*", &saveptr);
    if (V > 0)
    {
        printf("Multiply\n");
        double u = atof(U);
        double v = atof(V);
        Multiplication(u, v);
        printf("Multiplying\n");

    }
    
    U = strtok_r(form, "/", &saveptr);
    V = strtok_r(NULL, "/", &saveptr);
    if (V > 0)
    {
        printf("Divide\n");
        double u = atof(U);
        double v = atof(V);
        Division(u, v);
        printf("Dividing\n");
    }
}

void Logarithm ()
{
    printf("LogBASE a of x\nEnter base: \n");
    scanf("%lf", &g);
    printf("Enter x: \n");
    scanf("%lf", &x);
    LogBase(g, x);
}

void NthPower ()
{
    printf("Enter base: \n");
    scanf("%lf", &x);
    printf("Enter power: \n");
    scanf("%lf", &n);
    NPower(x, n);
}

void FractionDecimal ()
{
    printf("Enter fraction: \n");
    char frac[100];
    scanf("%s", frac);
    
    char *saveptr;
    char *numerator, *denominator;
    
    numerator = strtok_r(frac, "/", &saveptr);
    denominator = strtok_r(NULL, "/", &saveptr);
    double Num = atof(numerator);
    double Den = atof(denominator);
    FracDec(Num, Den);
}

void DecimalFraction ()
{
    printf("Enter decimal: \n");
    scanf("%lf", &x);
    b = Num(x);
    c = Den(x);
    SimpFrac(b, c);
}

void SimplifyFraction ()
{
    printf("Enter fraction: \n");
    char frac[100];
    scanf("%s", frac);
    
    char *saveptr;
    char *numerator, *denominator;
    
    numerator = strtok_r(frac, "/", &saveptr);
    denominator = strtok_r(NULL, "/", &saveptr);
    double Num = atof(numerator);
    double Den = atof(denominator);
    SimpFrac(Num, Den);
    
    /*char key[] = "/";
     char denominator[100];
     *denominator = strpbrk(frac,key);
     int lengths = strlen(frac);
     int lengthd = strlen(denominator);
     char numerator[100];
     strncpy( numerator, frac, (lengths-lengthd-1));
     */

}

void NthRoot ()
{
    printf("Enter root: \n");
    scanf("%lf", &n);
    printf("Enter x: \n");
    scanf("%lf", &x);
    NRoot(x, n);
}

void Derivative ()
{
    /*
    printf("Enter Function: y = \n");
    char expression_string[100];
    scanf("%s", &expression_string);
    
    //parser
    double X;
    printf("Enter x value: \n");
    scanf("%lf", X);
    printf("\n");
    TheDsCancel(X);
     */
    printf("not working\n");
}

void Limit ()
{
    /*
    printf("Enter Function: y = \n");
    char expression_string[100];
    scanf("%s", &expression_string);
    
    //parser
    double x;
    printf("Enter x value: \n");
    scanf("%lf", &x);
    printf("\n");
    double L = LeftLimit(x);
    double R = RightLimit(x);
    limit(L, R, x);
     */
    printf("not working\n");
}

void Table ()
{
    /*
    printf("Enter Function: y = \n");
    char expression_string[100];
    scanf("%s", &expression_string);
    
    //parser
    GenTable();
    */
    printf("not working\n");
}

void Interest ()
{
    int compound;
    printf("1) Compound Daily/ Weekly/ etc.\n2) Compound Cotinuously\n");
    scanf("%i", &compound);
    switch (compound)
    {
        case (1): nTimes();
            break;
        case (2): Cont();
            break;
    }
}

void Trigonometry ()
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

void RadiansDegrees ()
{
    int input;
    printf("1) RadtoDeg\n2) DegtoRad\n");
    scanf("%i", &input);
    switch(input)
    {
        case (1): RadtoDeg();
            break;
        case (2): DegtoRad();
            break;
    }
}

void ModeSelect ()
{
    int mode;
    printf("Select Mode: \n1) DecFrac\n2) FracDec\n3) Limit\n4) Derivative\n5) Power\n6) Root\n7) Simplify Fraction\n8) Four Operation\n9) Logarithm\n10) Table\n11) Quadratic\n12) Interest\n13) Distance\n14) Pythagorean Theorem\n15) Midpoint\n16) Voltage Divider\n17) Trig\n18) RadiansDegrees\n");
    scanf("%i", &mode);
    //replace above with button values and such
    switch(mode)
    {
        case (1): fncPtr = &DecimalFraction; //works
            break;
        case (2): fncPtr = &FractionDecimal; //works
            break;
        case (3): fncPtr = &Limit; //does not work (parser)
            break;
        case (4): fncPtr = &Derivative; //does not work (parser)
            break;
        case (5): fncPtr = &NthPower; //works
            break;
        case (6): fncPtr = &NthRoot; //works
            break;
        case (7): fncPtr = &SimplifyFraction; //works
            break;
        case (8): fncPtr = &FourOperation; //works
            break;
        case (9): fncPtr = &Logarithm; //works
            break;
        case (10): fncPtr = &Table; //does not work (parser)
            break;
        case (11): fncPtr = &Quadratic; //works
            break;
        case (12): fncPtr = &Interest; //works
            break;
        case (13): fncPtr = &Distance; //works
            break;
        case (14): fncPtr = &Pythagorean; //works
            break;
        case (15): fncPtr = &Midpoint; //works
            break;
        case (16): fncPtr = &VoltageDivider; //works
            break;
        case (17): fncPtr = &Trigonometry; //works (does not take pi)
            break;
        case (18): fncPtr = &RadiansDegrees; //works (does not take pi)
            break;
    }
}

//Main Loop
//------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    const double a = 1.0*(pow(10, -10));
    ModeSelect();
    (*fncPtr)();
}
