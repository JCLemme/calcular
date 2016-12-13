//
//  PythThrm.cpp
//  
//
//  Created by Jacob Meyerson on 12/12/16.
//
//

#include "PythThrm.hpp"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cmath>
#include <complex>

using namespace std;

double Leg ()
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

double Hyp ()
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

int main(int argc, char *argv[])
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

