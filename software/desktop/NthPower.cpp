//
//  Nth Root.cpp
//  
//
//  Created by Jacob Meyerson on 12/4/16.
//
//

#include "NthPower.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;
double x;
double n;
double b;

double NthPower (double x, double n)
{
    double y = pow((x), (n));
    return y;
}

int main( int argc, char *argv[])
{
    cout << "A to the Nth Power" << endl;
    cout << "Enter base: " << endl;
    cin >> x;
    cout << endl << "Enter power: " << endl;
    cin >> n;
    b = NthPower(x, n);
    cout << "Ans = " << b << endl;
}
