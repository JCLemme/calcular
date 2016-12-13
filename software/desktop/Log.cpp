//
//  Log.cpp
//  
//
//  Created by Jacob Meyerson on 12/6/16.
//
//

#include "Log.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>

using namespace std;
double a;
double x;

double LogBase (double a, double x)
{
    double Log = (log(x))/(log(a));
    cout << "Ans = " << Log << endl;
    return Log;
}

int main( int argc, char *argv[])
{
    cout << "LogBASE a of x" << endl << "Enter base: ";
    cin >> a;
    cout << "Enter x: ";
    cin >> x;
    LogBase(a, x);
}
