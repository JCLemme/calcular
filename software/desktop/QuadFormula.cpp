//
//  QuadFormula.cpp
//  
//
//  Created by Jacob Meyerson on 12/12/16.
//
//

#include "QuadFormula.hpp"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cmath>
#include <complex>

using namespace std;

double Quad (double a, double b, double c)
{
    double x, y;
    x = ((-b) + (sqrt((b*b)-4*a*c)))/(2*a);
    y = ((-b) - (sqrt((b*b)-4*a*c)))/(2*a);
    cout << "x = " << x << ", " << y << endl;
    return 0;
}


int main(int argc, char *argv[])
{
    double A, B, C;
    cout << "Enter a, b, and c: " << endl;
    cin >> A;
    cin >> B;
    cin >> C;
    Quad(A, B, C);
}


