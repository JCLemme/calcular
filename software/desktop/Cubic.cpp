//
//  Cubic.cpp
//  
//
//  Created by Jacob Meyerson on 12/12/16.
//
//

#include "Cubic.hpp"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cmath>
#include <complex>

using namespace std;

double i = sqrt(-1);

double Cub (double a, double b, double c, double d)
{
    double m, n, o, p, q, r, s, t, u, v, w;
    r = ((2*b*b*b) - (9*a*b*c) + (27*a*a*d));
    m = pow((pow(((2*b*b*b) - (9*a*b*c) + (27*a*a*d)), 2)) - (4*pow(((b*b) - (a*c)), 3)), (1/2));
    n = pow(0.5*(r + m), (1/3));
    o = pow(0.5*(r - m), (1/3));
    p = (1 + i*(pow(3, (1/2))))/(6*a);
    q = (1 - i*(pow(3, (1/2))))/(6*a);
    u = ((-(b))/(3*a)) - ((n)/(3*a)) - ((o)/(3*a));
    v = ((-(b))/(3*a)) + ((p)*(n)) + ((q)*(o));
    w = ((-(b))/(3*a)) + ((q)*(n)) + ((p)*(o));
    cout << "x = " << u << ", " << v << ", " << w << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    double A, B, C, D;
    cout << "Enter a, b, c, and d: " << endl;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    Cub (A, B, C, D);
}






