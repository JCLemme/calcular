//
//  Main.hpp
//  
//
//  Created by Jacob Meyerson on 12/5/16.
//
//

#ifndef Main_hpp
#define Main_hpp

#include "DecFrac.hpp"
#include "FracDec.hpp"
#include "Limit.hpp"
#include "Derivative.hpp"
#include "NthPower.hpp"
#include "NthRoot.hpp"
#include "SimpFrac.hpp"
#include "FourOp.hpp"
#include "Log.hpp"
#include "Table.hpp"
#include "QuadFormula.hpp"
#include "Interest.hpp"
#include "Distance.hpp"
#include "PythThrm.hpp"
#include "Midpoint.hpp"
#include "VoltageDivider.hpp"

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

//Global Variables
const double a = 1.0 * (pow(10, -10));
double x, b, c, n, g, u, v, num, den, Vout, Vin, R1, R2;
int minimum = (-5); //minimum x value for table
int maximum = (5); //maximum x value for table
double s = 1; //seconds in between printing
void (*fncPtr)();


#endif /* Main_hpp */
