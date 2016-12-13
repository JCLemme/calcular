//
//  Graphing.cpp
//  
//
//  Created by Jacob Meyerson on 12/8/16.
//
//

#include "Graphing.hpp"
#include <stdio.h>
#include <unistd.h>
#include <cmath>
#include <math.h>
#include <iostream>

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <string.h>

#include </Users/jacobmeyerson/Desktop/exprtk/exprtk.hpp>

using namespace std;
//Parser
typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>     expression_t;
typedef exprtk::parser<double>             parser_t;

symbol_table_t symbol_table;
expression_t   expression;
parser_t       parser;
double xt = 0;
double Hx;
int minimum = (-5); //minimum x value for table
int maximum = (5); //maximum x value for table
double s = 1; //seconds in between printing table

double GetEquation (double x)
{
    xt = x;
    return expression.value();
}

void Table ()
{
    for (int X = minimum; minimum <= X; X++)
    {
        Hx = GetEquation(X);
        cout << "(" << X << ", " << Hx << ")" << endl;
        if (X == maximum)
        {
            // cout << "Max" << endl;
            break;
        }
        usleep(s*(pow(10, 6)));
    }
}


int main (int argc, char *argv[])
{
    cout << "Enter Function: y = ";
    std::string expression_string;
    cin >> expression_string;
    
    symbol_table.add_variable("x",xt);
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string,expression);
    
    Table();
}
