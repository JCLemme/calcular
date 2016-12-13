//
//  Midpoint.cpp
//  
//
//  Created by Jacob Meyerson on 12/12/16.
//
//

#include "Midpoint.hpp"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cmath>
#include <complex>

using namespace std;

double Mdpt (double x1, double y1, double x2, double y2)
{
    double M, M1, M2, M3;
    M = (x1 + x2)/2;
    M1 = (y1 + y2)/2;
    cout << "The midpoint is (" << M << ", " << M1 << ")" << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    double X1, X2, Y1, Y2;
    cout << "Enter X1, Y1, X2, Y2 (order specific)" << endl;
    cin >> X1;
    cin >> Y1;
    cin >> X2;
    cin >> Y2;
    Mdpt(X1, Y1, X2, Y2);
}

