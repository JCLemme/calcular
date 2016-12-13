//
//  Nth Root.cpp
//  
//
//  Created by Jacob Meyerson on 12/4/16.
//
//

#include "NthRoot.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;
double X;
double n;
double B;

double NthRoot (double X, double n)
{
    double y = pow((X), (1.0/n));
    return y;
}

int main( int argc, char *argv[])
{
    cout << "Nth root of x" << endl;
    cout << "Enter root: " << endl;
    cin >> n;
    cout << endl << "Enter x: " << endl;
    cin >> X;
    B = NthRoot(X, n);
    cout << "Ans = " << B << endl;
}
