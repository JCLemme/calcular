//
//  Derivative.cpp
//  
//
//  Created by Jacob Meyerson on 12/4/16.
//
//

#include "Derivative.hpp"
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include </Users/jacobmeyerson/Desktop/exprtk/exprtk.hpp>
#include "Derivative.hpp"
using namespace std;

typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>     expression_t;
typedef exprtk::parser<double>             parser_t;

symbol_table_t symbol_table;
expression_t   expression;
parser_t       parser;
double xt = 0;
const double a = 1.0 * (pow(10, -10));

double GetEquation (double x)
{
    xt = x;
    return expression.value();
}

double TheDsCancel (double x)
{
    double Fx = GetEquation(x);
    double b = x-a;
    double Fb = GetEquation(b);
    double dydx = (Fx - Fb)/(x - b);
    cout << "Dy/dx = " << dydx << endl;
    return dydx;
}

int main( int argc, char *argv[])
{
    cout << "Enter Function: y = ";
    std::string expression_string;
    cin >> expression_string;
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    double X;
    cout << "Enter x value: ";
    cin >> X;
    cout << endl;
    TheDsCancel(X);
}
