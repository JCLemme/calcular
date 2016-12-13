//
//  FracDec.cpp
//  
//
//  Created by Jacob Meyerson on 12/4/16.
//
//

#include "FracDec.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
float x, z;

float FracDec (float x, float z)
{
    float y = (x)/(z);
    return y;
}

int main( int argc, char *argv[])
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
    
    float b = FracDec(num, den);
    cout << "Ans = " << b << endl;
}

