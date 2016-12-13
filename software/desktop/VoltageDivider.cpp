//
//  VoltageDivider.cpp
//  
//
//  Created by Jacob Meyerson on 12/12/16.
//
//

#include "VoltageDivider.hpp"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cmath>
#include <complex>

using namespace std;
double Vout, Vin, R1, R2;

double VOUT ()
{
    cout << "Enter: Vin, R1, R2" << endl;
    cin >> Vin;
    cin >> R1;
    cin >> R2;
    Vout = Vin * ((R2)/(R1+R2));
    cout << "Vout = " << Vout << endl;
    return 0;
}

double VIN ()
{
    cout << "Enter: Vout, R1, R2" << endl;
    cin >> Vout;
    cin >> R1;
    cin >> R2;
    Vin = (Vout * (R1 + R2))/(R2);
    cout << "Vin = " << Vin << endl;
    return 0;
}

double r1 ()
{
    cout << "Enter: Vout, Vin, R2" << endl;
    cin >> Vout;
    cin >> Vin;
    cin >> R2;
    R1 = (R2 * (Vin - Vout))/(Vout);
    cout << "R1 = " << R1 << endl;
    return 0;
}

double r2 ()
{
    cout << "Enter: Vout, Vin, R1" << endl;
    cin >> Vout;
    cin >> Vin;
    cin >> R1;
    R2 = (Vout * R1)/(Vin - Vout);
    cout << "R2 = " << R2 << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    cout << "1) Vout" << endl << "2) Vin" << endl << "3) R1" << endl << "4) R2" << endl;
    int input;
    cin >> input;
    switch (input)
    {
        case (1): VOUT();
            break;
        case (2): VIN();
            break;
        case (3): r1();
            break;
        case (4): r2();
            break;
    }
}
    
    
    
    
    
    
