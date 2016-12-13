//
//  SimpFrac.cpp
//  
//
//  Created by Jacob Meyerson on 12/4/16.
//
//

#include "SimpFrac.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;
double Num;
double Den;
bool Flag = true;

double SimpFrac (double Num, double Den)
{
    for (int x = max(Num, Den); 0 < x <= max(Num, Den); x--)
    {
        if (remainder(Num, x) == 0 && remainder(Den, x) == 0 && Flag)
        {
            double N = (Num)/(x);
            double D = (Den)/(x);
            cout << N << "/" << D << endl;
            Flag = false;
        }
        //cout << x << endl;
        if (x == 0)
        {
            return 0;
        }
    }
    return 0;
}

int main( int argc, char *argv[])
{
    cout << "Enter Fraction: ";
    string frac;
    cin >> frac;
    
    int cpos=frac.find_first_of('/');
    string N = frac.substr (0, cpos);
    string D = frac.substr (cpos + 1, frac.size());
    //cout << n << endl << d << endl;
    float Num = atof(N.c_str());
    float Den = atof(D.c_str());
    SimpFrac(Num, Den);
}


