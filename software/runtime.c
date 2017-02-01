//
//  runtime.c
//
//
//  Created by Jacob Meyerson on 1/11/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//Global Variables

int w = 0; //0 = Normal, 1 = 2nd, 2 = Alpha
int Second_cnt = 0;
int Alpha_cnt = 0;

double stack[64];
int cnt = 0;
char number[64];
char text[64];
int text_cnt = 0;
char input_type[64];

int button;
double q; //number to push from buttons
double g; //used in operations to push new numbers
double x; //variable on calculator
int i; //used for reading string

char zero = '0';
char one = '1';
char two = '2';
char three = '3';
char four = '4';
char five = '5';
char six = '6';
char seven = '7';
char eight = '8';
char nine = '9';
char decimal = '.';
char add = '+';
char subtract = '-';
char multiply = '*';
char divide = '/';
char power = '^';
char X = 'x';
char space = ' ';
char logarithm = 'a';
char ln = 'b';
char root = 'c';
char swap = 'd';
char drop = 'e';
char roll = 'f';
char copy = 'g';
char sine = 'h';
char cosine = 'i';
char tangent = 'j';
char sec = 'k';
char csc = 'l';
char cot = 'm';
char arcsin = 'n';
char arccos = 'o';
char arctan = 'p';
char arcsec = 'q';
char arccsc = 'r';
char arccot = 's';
char togglesign = 't';
char store = 'u';



//Mode Settings
int RadDeg = 1;

//Constants
double pi = 3.14159265358979323846264;
double e = 2.71828182845904523536028747135266249775724709369995;

//calculator functions-------------------------------------------

void push (double b)
{
    stack[cnt] = b;
    cnt++;
    printf("push = %lf\n", b);
}

double pop ()
{
    stack[cnt] = 0;
    double h = stack[cnt-1];
    cnt--;
    return h;
}

void Swap ()
{
    double f = stack[0];
    double k = stack[1];
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
    stack[0] = k;
    stack[1] = f;
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
}

void Copy ()
{
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
    double t = pop();
    push(t);
    push(t);
    //printf("Stack 0 = %lf\n", stack[0]);
    //printf("Stack 1 = %lf\n", stack[1]);
}

void Drop ()
{
    pop();
}

void Roll ()
{
    double u = pop();
    double v = pop();
    double z = pop();
    push(v);
    push(u);
    push(z);
}

void Add () //works
{
    double a = pop();
    double b = pop();
    g = b + a;
    push(g);
    printf("Number = %lf\n", g);
}

void Subtract () //works
{
    double a = pop();
    double b = pop();
    g = b - a;
    push(g);
    //printf("Number = %lf\n", g);
}

void Multiply () //works
{
    double a = pop();
    double b = pop();
    g = b * a;
    push(g);
    //printf("Number = %lf\n", g);
}

void Divide () //works
{
    double a = pop();
    double b = pop();
    g = b / a;
    push(g);
    //printf("Number = %lf\n", g);
}

void Power () //works
{
    double a = pop();
    double b = pop();
    g = pow(b, a);
    push(g);
    //printf("Number = %lf\n", g);
}

void Log () //number, then base -------- works
{
    double a = pop();
    double b = pop();
    g = log(b)/log(a);
    push(g);
    //printf("Number = %lf\n", g);
}

void Ln () //works
{
    double a = pop();
    g = log(a);
    push(g);
    //printf("Number = %lf\n", g);
}

void Root () //number, then root ------------ works
{
    double a = pop();
    double b = pop();
    g = pow((b), (1.0/a));
    push(g);
}

void Sin () //works (DEG)
{
    double f = pop();
    printf("pop = %lf\n", f);
    if (RadDeg == 0) //radians
    {
        double y = sin(f);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = sin((pi*f)/(180));
        push(y);
    }
}

void Cos () //works (DEG)
{
    double f= pop();
    if (RadDeg == 0) //radians
    {
        double y = cos(f);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = cos((pi*f)/(180));
        push(y);
    }
}

void Tan () //works (DEG)
{
    double f= pop();
    if (RadDeg == 0) //radians
    {
        double y = tan(f);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = tan((pi*f)/(180));
        push(y);
    }
}

void Sec () //works (DEG)
{
    double f= pop();
    if (RadDeg == 0) //radians
    {
        double y = 1/cos(f);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = 1/cos((pi*f)/(180));
        push(y);
    }
}

void Csc () //works (DEG)
{
    double f= pop();
    if (RadDeg == 0) //radians
    {
        double p = 1/sin(f);
        push(p);
    }
    if (RadDeg == 1)
    {
        double p = 1/sin((pi*f)/(180));
        push(p);
    }
}

void Cot () //works (DEG)
{
    double f= pop();
    if (RadDeg == 0) //radians
    {
        double y = 1/tan(f);
        push(y);
    }
    if (RadDeg == 1)
    {
        double y = 1/tan((pi*f)/(180));
        push(y);
    }
}

void Arcsin () //works (DEG)
{
    double f= pop();
    double y = asin(f);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arccos () //works (DEG)
{
    double f= pop();
    double y = acos(f);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arctan () //works (DEG)
{
    double f= pop();
    double y = atan(f);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arcsec ()
{
    double f= pop();
    double y = acos(1/f);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arccsc ()
{
    double f= pop();
    double y = asin(1/f);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void Arccot ()
{
    double f = pop();
    double y = atan(1/f);
    if (RadDeg == 0)
    {
        push(y);
    }
    if (RadDeg == 1)
    {
        double z = (y*180)/(pi);
        push(z);
    }
}

void ToggleSign ()
{
    double a = pop();
    g = (-1) * (a);
    push(g);
    printf("g = %lf\n", g);
}

int GetButton ()
{
    int bttn;
    scanf("%i", &bttn);
    return bttn;
}

void Store ()
{
    double a = pop();
    x = a;
}

void Interpreter ()
{
    for (int t = 0; t < strlen(input_type); t++)
    {
        char tok = input_type[t];
        
        if (isdigit(tok) || tok == '.')
        {
            strncat(number, &tok, 1);
            i = 1;
        }
        if (tok == ' ' && i == 1)
        {
            q = atof(number);
            printf("q = %lf\n", q);
            push(w);
            memset(number, 0, sizeof number);
        }
        
        if (tok == 'x')
        {
            push(x);
            i = 0;
        }
        if (tok == '+')
        {
            Add();
            i = 0;
        }
        if (tok == '-')
        {
            Subtract();
            i = 0;
        }
        if (tok == '*')
        {
            Multiply();
            i = 0;
        }
        if (tok == '/')
        {
            Divide();
            i = 0;
        }
        if (tok == '^')
        {
            Power();
            i = 0;
        }
        if (tok == 'a')
        {
            Log();
            i = 0;
        }
        if (tok == 'b')
        {
            Ln();
            i = 0;
        }
        if (tok == 'c')
        {
            Root();
            i = 0;
        }
        if (tok == 'd')
        {
            Swap();
            i = 0;
        }
        if (tok == 'e')
        {
            Drop();
            i = 0;
        }
        if (tok == 'f')
        {
            Roll();
            i = 0;
        }
        if (tok == 'g')
        {
            Copy();
            i = 0;
        }
        if (tok == 'h')
        {
            
        }
        if (tok == 'i')
        {
            
        }
        if (tok == 'j')
        {
            
        }
        if (tok == 'k')
        {
            
        }
        if (tok == 'l')
        {
            
        }
        if (tok == 'm')
        {
            
        }
        if (tok == 'n')
        {
            
        }
        if (tok == 'o')
        {
            
        }
        if (tok == 'p')
        {
            
        }
        if (tok == 'q')
        {
            
        }
        if (tok == 'r')
        {
            
        }
        if (tok == 's')
        {
            
        }
        if (tok == 't')
        {
            
        }
        if (tok == 'u')
        {
            Store();
            i = 0;
        }
    }
}

//runtime functions-------------------------------------------
void NormalButton (int btn)
{
    printf("button = %i\n", btn);
    switch (btn)
    {
            //NUMBERS--------------------------------------------
        case (8): strncat(input_type, &X, 1);
            break;
        case (13): strncat(input_type, &seven, 1);
            break;
        case (14): strncat(input_type, &four, 1);
            break;
        case (15): strncat(input_type, &one, 1);
            break;
        case (16): strncat(input_type, &zero, 1);
            break;
        case (21): strncat(input_type, &eight, 1);
            break;
        case (22): strncat(input_type, &five, 1);
            break;
        case (23): strncat(input_type, &two, 1);
            break;
        case (24): strncat(input_type, &decimal, 1);
            break;
        case (29): strncat(input_type, &nine, 1);
            break;
        case (30): strncat(input_type, &six, 1);
            break;
        case (31): strncat(input_type, &three, 1);
            break;
        case (32): strncat(input_type, &space, 1);
            break;
        case (40): printf("%s\n", input_type);
            Interpreter();
            break;
            //OPERATIONS-----------------------------------
        case (2): strncat(input_type, &swap, 1);
            break;
        case (4): strncat(input_type, &root, 1);
            break;
        case (5): strncat(input_type, &logarithm, 1);
            break;
        case (6): strncat(input_type, &ln, 1);
            break;
        case (10): strncat(input_type, &copy, 1);
            break;
        case (11): strncat(input_type, &sine, 1);
            break;
        case (12): strncat(input_type, &arcsin, 1);
            break;
        case (18): strncat(input_type, &drop, 1);
            break;
        case (19): strncat(input_type, &cosine, 1);
            break;
        case (20): strncat(input_type, &arccos, 1);
            break;
        case (26): strncat(input_type, &roll, 1);
            break;
        case (27): strncat(input_type, &tangent, 1);
            break;
        case (28): strncat(input_type, &arctan, 1);
            break;
        case (35): strncat(input_type, &power, 1);
            break;
        case (36): strncat(input_type, &add, 1);
            break;
        case (37): strncat(input_type, &subtract, 1);
            break;
        case (38): strncat(input_type, &multiply, 1);
            break;
        case (39): strncat(input_type, &divide, 1);
            break;
    }
}

void SecondButton (int btn)
{
    switch (btn)
    {
        case (8): strncat(input_type, &store, 1);
            break;
        case (11): strncat(input_type, &csc, 1);
            break;
        case (12): strncat(input_type, &arccsc, 1);
            break;
        case (19): strncat(input_type, &sec, 1);
            break;
        case (20): strncat(input_type, &arcsec, 1);
            break;
        case (27): strncat(input_type, &cot, 1);
            break;
        case (28): strncat(input_type, &arccot, 1);
            break;
        case (32): strncat(input_type, &togglesign, 1);
            break;
    }
}

void AlphaButton (int btn)
{
    //switch stmt for buttons 1-48
    switch (btn)
    {
        case (2): text[text_cnt] = 'A';
            text_cnt++;
            break;
        case (3): text[text_cnt] = 'F';
            text_cnt++;
            break;
        case (4): text[text_cnt] = 'K';
            text_cnt++;
            break;
        case (5): text[text_cnt] = 'P';
            text_cnt++;
            break;
        case (6): text[text_cnt] = 'U';
            text_cnt++;
            break;
        case (7): text[text_cnt] = 'Z';
            text_cnt++;
            break;
        case (10): text[text_cnt] = 'B';
            text_cnt++;
            break;
        case (11): text[text_cnt] = 'G';
            text_cnt++;
            break;
        case (12): text[text_cnt] = 'L';
            text_cnt++;
            break;
        case (13): text[text_cnt] = 'Q';
            text_cnt++;
            break;
        case (14): text[text_cnt] = 'V';
            text_cnt++;
            break;
        case (15): text[text_cnt] = '\'';
            text_cnt++;
            break;
        case (18): text[text_cnt] = 'C';
            text_cnt++;
            break;
        case (19): text[text_cnt] = 'H';
            text_cnt++;
            break;
        case (20): text[text_cnt] = 'M';
            text_cnt++;
            break;
        case (21): text[text_cnt] = 'R';
            text_cnt++;
            break;
        case (22): text[text_cnt] = 'W';
            text_cnt++;
            break;
        case (23): text[text_cnt] = '"';
            text_cnt++;
            break;
        case (24): text[text_cnt] = '.';
            text_cnt++;
            break;
        case (26): text[text_cnt] = 'D';
            text_cnt++;
            break;
        case (27): text[text_cnt] = 'I';
            //printf("%s\n", text);
            text_cnt++;
            break;
        case (28): text[text_cnt] = 'N';
            text_cnt++;
            break;
        case (29): text[text_cnt] = 'S';
            text_cnt++;
            break;
        case (30): text[text_cnt] = 'X';
            text_cnt++;
            //printf("%s\n", text);
            break;
        case (31): text[text_cnt] = ',';
            text_cnt++;
            break;
        case (32): text[text_cnt] = ' ';
            //printf("%s\n", text);
            text_cnt++;
            break;
        case (34): text[text_cnt] = 'E';
            text_cnt++;
            break;
        case (35): text[text_cnt] = 'J';
            text_cnt++;
            break;
        case (36): text[text_cnt] = 'O';
            text_cnt++;
            break;
        case (37): text[text_cnt] = 'T';
            text_cnt++;
            break;
        case (38): text[text_cnt] = 'Y';
            text_cnt++;
            break;
    }
}

void UpdateKeyboard ()
{
    int button = GetButton();
    if (button == 43)
    {
        w = 1;
        Second_cnt++;
        if (Second_cnt == 2)
        {
            w = 0;
            Second_cnt = 0;
        }
    }
    if (button == 44)
    {
        w = 2;
        Alpha_cnt++;
        if (Alpha_cnt == 2)
        {
            w = 0;
            Alpha_cnt = 0;
        }
    }
    if (button != 44 && button != 43)
    {
        switch (w)
        {
            case (0): NormalButton(button);
                break;
            case (1): SecondButton(button);
                break;
            case (2): AlphaButton(button);
                break;
        }
    }
}

void UpdateDisplay ()
{
    /*
     tell display what to print and where to print it
     */
    int g;
}

void UpdateKernel ()
{
    /*
     talk to kernel to read battery voltage and other stuff like that
     */
    int b;
}

void UpdateCalculator ()
{
    /*
     perform indicated math functions
     */
    int d;
}

int main (void)
{
    while (1)
    {
        UpdateKeyboard();
        //UpdateDisplay();
        //UpdateKernel();
        //UpdateCalculator();
    }
}
