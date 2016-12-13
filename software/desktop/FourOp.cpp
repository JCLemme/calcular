//
//  FourOp.cpp
//  
//
//  Created by Jacob Meyerson on 12/5/16.
//
//

#include "FourOp.hpp"
#include <cmath>
#include <math.h>
#include <iostream>

using namespace std;
double u, v;

double Addition (double x, double y)
{
    double h = (x) + (y);
    cout << "Ans = " << h << endl;
    return 0;
}

double Subtraction (double x, double y)
{
    double h = (x) - (y);
    cout << "Ans = " << h << endl;
    return 0;
}

double Multiplication (double x, double y)
{
    double h = (x)*(y);
    cout << "Ans = " << h << endl;
    return 0;
}

double Division (double x, double y)
{
    double h = (x)/(y);
    cout << "Ans = " << h << endl;
    return 0;
}

int main( int argc, char *argv[])
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


