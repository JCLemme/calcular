//
//  Main.cpp
//  
//
//  Created by Jacob Meyerson on 12/5/16.
//
//

#include "Main.hpp"

//Sub- Functions
//------------------------------------------------------------------------
double Num (double x) //DecFrac
{
    string Str = static_cast<ostringstream*>( &(ostringstream() << x) )->str();
    int y = Str.length();
    int num = (x)*(pow(10, (y-1)));
    return num;
}

double Den (double x) //DecFrac
{
    string Str = static_cast<ostringstream*>( &(ostringstream() << x) )->str();
    int y = Str.length();
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
            cout << n << "/" << d << endl;
            break;
        }
    }
    return 0;
}

double NRoot (double x, double n) //Nth Root
{
    double y = pow((x), (1.0/n));
    cout << "Ans = " << y << endl;
    return 0;
}

double FracDec (double x, double z) //FracDec
{
    double y = (x)/(z);
    cout << "Ans = " << y << endl;
    return 0;
}

double NPower (double x, double n) //NthPower
{
    double y = pow((x), (n));
    cout << "Ans = " << y << endl;
    return 0;
}

double nTimes () //Interest
{
    //P(1+r/n)^nt
    double P, r, n, t;
    cout << "Enter P ($), r (%), n (times compounded per year), t (years): " << endl;
    cin >> P;
    cin >> r;
    cin >> n;
    cin >> t;
    double r1 = (r/100);
    double A1, A2, A3;
    A1 = (1 + (r1/n));
    A2 = pow(A1, (n*t));
    A3 = A2*P;
    cout << "A = " << A3 << endl;
    return 0;
}

double Cont () //Interest
{
    //Pe^rt
    double e = 2.71828182846;
    double P, r, n, t;
    cout << "Enter P ($), r (%), t (years): " << endl;
    cin >> P;
    cin >> r;
    cin >> t;
    double r1 = (r/100);
    double A4, A5;
    A4 = pow(e, (r1*t));
    A5 = P*A4;
    cout << "A = " << A5 << endl;
    return 0;
}


double GetEquation (double x) //DyDx & Limit
{
    xt = x;
    return expression.value();
}

double TheDsCancel (double x) //DyDx
{
    double Fx = GetEquation(x);
    double b = x-a;
    double Fb = GetEquation(b);
    double dydx = (Fx - Fb)/(x - b);
    cout << "Dy/dx = " << dydx << endl;
    return 0;
}

double LeftLimit (double X) //Limit
{
    double LHL;
    double x;
    double a = pow(0.1, 5);
    x = X - a;
    double Fx = GetEquation(x);
    cout << "F(x) approaches " << Fx << " from the left" << endl;
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
    cout << "F(x) approaches " << Fx << " from the right" << endl;
    RHL = Fx;
    return RHL;
}

double limit (double L, double R, double X) //Limit
{
    double Lim;
    if (R - L < 0.1 && R >= L )
    {
        Lim = (L + R)/2;
        cout << "Limit as x-> " << X << " = " << Lim << endl;
    }
    
    else if (R - L > 0.1 || R < L)
    {
        cout << "The limit does not exist" << endl;
    }
    return 0;
}

double GenTable () //Table
{
    for (int X = minimum; minimum <= X; X++)
    {
        double Hx = GetEquation(X);
        cout << "(" << X << ", " << Hx << ")" << endl;
        if (X == maximum)
        {
            // cout << "Max" << endl;
            break;
        }
        usleep(s*(pow(10, 6)));
    }
    return 0;
}

double LogBase (double g, double x) //Logarithm
{
    double Log = (log(x))/(log(g));
    cout << "Ans = " << Log << endl;
    return 0;
}

double Addition (double x, double y) //FourOp
{
    double h = (x) + (y);
    cout << "Ans = " << h << endl;
    return 0;
}

double Subtraction (double x, double y) //FourOp
{
    double h = (x) - (y);
    cout << "Ans = " << h << endl;
    return 0;
}

double Multiplication (double x, double y) //FourOp
{
    double h = (x)*(y);
    cout << "Ans = " << h << endl;
    return 0;
}

double Division (double x, double y) //FourOp
{
    double h = (x)/(y);
    cout << "Ans = " << h << endl;
    return 0;
}

double Quad (double a, double b, double c) //Quadratic
{
    double x, y;
    x = ((-(b)) + (sqrt(((b)*(b))-4*(a)*(c))))/(2*(a));
    y = ((-(b)) - (sqrt(((b)*(b))-4*(a)*(c))))/(2*(a));
    cout << "x = " << x << ", " << y << endl;
    return 0;
}

double Dist (double x1, double x2, double y1, double y2) //Distance
{
    double D1, D2, D3;
    D1 = (x2 - x1)*(x2 - x1);
    D2 = (y2 - y1)*(y2 - y1);
    D3 = sqrt((D1+D2));
    cout << "Distance = " << D3 << endl;
    return 0;
}

double Mdpt (double x1, double y1, double x2, double y2) //Midpoint
{
    double M, M1, M2, M3;
    M = (x1 + x2)/2;
    M1 = (y1 + y2)/2;
    cout << "The midpoint is (" << M << ", " << M1 << ")" << endl;
    return 0;
}

double Leg () //Pythagorean
{
    //Solve for Missing Leg
    float a, c;
    cout << "Enter a (or b), c: " << endl;
    cin >> a;
    cin >> c;
    float b, b2;
    b = (pow(c, 2) - pow(a, 2));
    cout << "a (or b) = the square root of " << b << endl;
    b2 = sqrt(b);
    cout << "a (or b) = " << b2 << endl;
    return 0;
}

double Hyp () //Pythagorean
{
    //Solve for Hypotenuse
    double a, b;
    cout << "Enter a, b: " << endl;
    cin >> a;
    cin >> b;
    double c, c1;
    c = (pow(a, 2) + pow(b, 2));
    cout << "c = the square root of " << c << endl;
    c1 = sqrt(c);
    cout << "c = " << c1 << endl;
    return 0;
}

double VOUT () //VoltageDivider
{
    cout << "Enter: Vin, R1, R2" << endl;
    cin >> Vin;
    cin >> R1;
    cin >> R2;
    Vout = Vin * ((R2)/(R1+R2));
    cout << "Vout = " << Vout << endl;
    return 0;
}

double VIN () //VoltageDivider
{
    cout << "Enter: Vout, R1, R2" << endl;
    cin >> Vout;
    cin >> R1;
    cin >> R2;
    Vin = (Vout * (R1 + R2))/(R2);
    cout << "Vin = " << Vin << endl;
    return 0;
}

double r1 () //VoltageDivider
{
    cout << "Enter: Vout, Vin, R2" << endl;
    cin >> Vout;
    cin >> Vin;
    cin >> R2;
    R1 = (R2 * (Vin - Vout))/(Vout);
    cout << "R1 = " << R1 << endl;
    return 0;
}

double r2 () //VoltageDivider
{
    cout << "Enter: Vout, Vin, R1" << endl;
    cin >> Vout;
    cin >> Vin;
    cin >> R1;
    R2 = (Vout * R1)/(Vin - Vout);
    cout << "R2 = " << R2 << endl;
    return 0;
}

//Functions
//------------------------------------------------------------------------
void Pythagorean ()
{
    int pythagoras;
    cout << "1) Solve for Missing Leg" << endl << "2) Solve for Hypotenuse" << endl;
    cin >> pythagoras;
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
    cout << "1) Vout" << endl << "2) Vin" << endl << "3) R1" << endl << "4) R2" << endl;
    int input;
    cin >> input;
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
    cout << "Enter X1, Y1, X2, Y2 (order specific)" << endl;
    cin >> X1;
    cin >> Y1;
    cin >> X2;
    cin >> Y2;
    Mdpt(X1, Y1, X2, Y2);
}

void Quadratic ()
{
    double A, B, C;
    cout << "Enter a, b, and c: " << endl;
    cin >> A;
    cin >> B;
    cin >> C;
    Quad(A, B, C);
}

void Distance ()
{
    double X2, X1, Y2, Y1;
    cout << "Enter X1, Y1, X2, Y2 (order specific)" << endl;
    cin >> X1,
    cin >> Y1;
    cin >> X2;
    cin >> Y2;
    Dist (X1, X2, Y1, Y2);
}

void FourOperation ()
{
    cout << "Enter 1st number: ";
    cin >> u;
    cout << "Enter operation: ";
    string op;
    cin >> op;
    cout << "Enter 2nd number: ";
    cin >> v;
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
    cout << "LogBASE a of x" << endl << "Enter base: ";
    cin >> g;
    cout << "Enter x: ";
    cin >> x;
    LogBase(g, x);
}

void NthPower ()
{
    cout << "A to the Nth Power" << endl;
    cout << "Enter base: " << endl;
    cin >> x;
    cout << endl << "Enter power: " << endl;
    cin >> n;
    NPower(x, n);
}

void FractionDecimal ()
{
    cout << "Enter Fraction: ";
    string frac;
    cin >> frac;
    
    int cpos=frac.find_first_of('/');
    string n = frac.substr (0, cpos);
    string d = frac.substr (cpos + 1, frac.size());
    //cout << n << endl << d << endl;
    float num = atof(n.c_str());
    float den = atof(d.c_str());
    
    FracDec(num, den);
}

void DecimalFraction ()
{
    cout << "Enter Decimal: ";
    cin >> x;
    b = Num(x);
    c = Den(x);
    SimpFrac(b, c);
}

void SimplifyFraction ()
{
    cout << "Enter Fraction: ";
    string frac;
    cin >> frac;
    
    int cpos=frac.find_first_of('/');
    string N = frac.substr (0, cpos);
    string D = frac.substr (cpos + 1, frac.size());
    float Num = atof(N.c_str());
    float Den = atof(D.c_str());
    SimpFrac(Num, Den);
}

void NthRoot ()
{
    cout << "Nth root of x" << endl;
    cout << "Enter root: " << endl;
    cin >> n;
    cout << "Enter x: " << endl;
    cin >> x;
    NRoot(x, n);
}

void Derivative ()
{
    cout << "Enter Function: y = ";
    std::string expression_string;
    cin >> expression_string;
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    double X;
    cout << "Enter x value: ";
    cin >> X;
    cout << endl;
    TheDsCancel (X);
}

void Limit ()
{
    cout << "Enter Function: y = ";
    std::string expression_string;
    cin >> expression_string;
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    double x;
    cout << "Enter x value: ";
    cin >> x;
    cout << endl;
    double L = LeftLimit (x);
    double R = RightLimit (x);
    limit (L, R, x);
}

void Table ()
{
    cout << "Enter Function: y = ";
    std::string expression_string;
    cin >> expression_string;
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    GenTable();
}

void Interest ()
{
    int compound;
    cout << "1) Compound Daily/ Weekly/ etc." << endl << "2) Compound Continuously" << endl;
    cin >> compound;
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
    cout << "Select Mode: " << endl << "1) DecFrac" << endl << "2) FracDec" << endl << "3) Limit" << endl << "4) Derivative" << endl << "5) Power" << endl << "6) Root" << endl << "7) Simplify Fraction" << endl << "8) Four Operation" << endl << "9) Logarithm" << endl << "10) Table" << endl << "11) Quadratic" << endl << "12) Interest" << endl << "13) Distance" << endl << "14) Pythagorean Theorem" << endl << "15) Midpoint" << endl << "16) Voltage Divider" << endl;
    cin >> mode;
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
//------------------------------------------------------------------------

int main (int argc, char *argv[])
{
    ModeSelect();
    (*fncPtr)();
}



