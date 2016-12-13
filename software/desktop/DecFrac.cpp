//
//  DecFrac.cpp
//  
//
//  Created by Jacob Meyerson on 12/4/16.
//
//

#include "DecFrac.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;
double x;
double b;
double c;
bool flag = true;
double num;
double den;

double Num (double x)
{
    string Str = static_cast<ostringstream*>( &(ostringstream() << x) )->str();
    int y = Str.length();
    int num = (x)*(pow(10, (y-1)));
    return num;
}

double Den (double x)
{
    string Str = static_cast<ostringstream*>( &(ostringstream() << x) )->str();
    int y = Str.length();
    int den = pow(10, (y-1));
    return den;
}

double SimpFrac (double num, double den)
{
    for (int x = max(num, den); 0 < x <= max(num, den); x--)
    {
        if (remainder(num, x) == 0 && remainder(den, x) == 0 && flag)
        {
            double n = (num)/(x);
            double d = (den)/(x);
            cout << n << "/" << d << endl;
            flag = false;
        }
        if (x == 0)
        {
            return 0;
        }
    }
    return 0;
}

int main( int argc, char *argv[])
{
    cout << "Enter Decimal: ";
    cin >> x;
    b = Num(x);
    c = Den(x);
    SimpFrac(b, c);
}

