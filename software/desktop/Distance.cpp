//
//  Distance.cpp
//  
//
//  Created by Jacob Meyerson on 12/12/16.
//
//

#include "Distance.hpp"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cmath>
#include <complex>

using namespace std;
double Dist (double x1, double x2, double y1, double y2)
{
    double D1, D2, D3;
    D1 = (x2 - x1)*(x2 - x1);
    D2 = (y2 - y1)*(y2 - y1);
    D3 = sqrt((D1+D2));
    cout << "Distance = " << D3 << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    double X2, X1, Y2, Y1;
    cout << "Enter X1, Y1, X2, Y2 (order specific)" << endl;
    cin >> X1,
    cin >> Y1;
    cin >> X2;
    cin >> Y2;
    Dist (X1, X2, Y1, Y2);

}



