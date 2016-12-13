//
//  Interest.cpp
//  
//
//  Created by Jacob Meyerson on 12/12/16.
//
//

#include "Interest.hpp"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cmath>
#include <complex>

using namespace std;

void nTimes ()
{
    //P(1+r/n)^nt
    double P, r, n, t;
    cout << "Enter P ($), r (%), n (times compounded per year), t (years): " << endl;
    cin >> P;
    cin >> r;
    cin >> n;
    cin >> t;
    double r1 = (r/100);
    double A1, A2, A3;
    A1 = (1 + (r1/n));
    A2 = pow(A1, (n*t));
    A3 = A2*P;
    cout << "A = " << A3 << endl;
}
void Cont ()
{
    //Pe^rt
    double e = 2.71828182846;
    double P, r, n, t;
    cout << "Enter P ($), r (%), t (years): " << endl;
    cin >> P;
    cin >> r;
    cin >> t;
    double r1 = (r/100);
    double A4, A5;
    A4 = pow(e, (r1*t));
    A5 = P*A4;
    cout << "A = " << A5 << endl;
}



int main (int argc, char *arg[])
{
int compound;
cout << "1) Compound Daily/ Weekly/ etc." << endl << "2) Compound Continuously" << endl;
cin >> compound;
switch (compound)
    {
        case (1): nTimes();
            break;
        case (2): Cont();
            break;
    }
}

