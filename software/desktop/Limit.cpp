//
//  Limit.cpp
//  
//
//  Created by Jacob Meyerson on 12/4/16.
//
//

#include "Limit.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include </Users/jacobmeyerson/Desktop/exprtk/exprtk.hpp>
#include "Limit.hpp"
using namespace std;

typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>     expression_t;
typedef exprtk::parser<double>             parser_t;

symbol_table_t symbol_table;
expression_t   expression;
parser_t       parser;
double xt = 0;

float GetEquation (float x)
{
    xt = x;
    return expression.value();
}

float LeftLimit (float X)
{
    float LHL;
    float x;
    float a = pow(0.1, 5);
    x = X - a;
    float Fx = GetEquation(x);
    cout << "F(x) approaches " << Fx << " from the left" << endl;
    LHL = Fx;
    return LHL;
}

float RightLimit(float X)
{
    float RHL;
    float x;
    float a = pow(0.1, 5);
    x = X + a;
    float Fx = GetEquation(x);
    cout << "F(x) approaches " << Fx << " from the right" << endl;
    RHL = Fx;
    return RHL;
}

float limit (float L, float R)
{
    float Lim;
    if (R - L < 0.1 && R >= L )
    {
        Lim = (L + R)/2;
        return Lim;
    }
    
    else if (R - L > 0.1 || R < L)
    {
        cout << "The limit does not exist" << endl;
    }
    return Lim;
}

int main( int argc, char *argv[])
{
    cout << "Enter Function: y = ";
    std::string expression_string;
    cin >> expression_string;
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    float Xl;
    cout << "Enter x value: ";
    cin >> Xl;
    cout << endl;
    float L = LeftLimit (Xl);
    float R = RightLimit (Xl);
    float lmt = limit (L, R);
    
    cout << "Limit as x-> " << Xl << " = " << lmt << endl;
}

