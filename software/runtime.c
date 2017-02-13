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
char operation[64];

char text[64];
int text_cnt = 0;
char input_type[64];

double xcoordinate[64];
double ycoordinate[64];
int coordinate_cnt = 0;

int button;
double q; //number to push from buttons
double g; //used in operations to push new numbers
double x; //variable on calculator
int run_yequals = 1;
double k = 15; //number of pixels from bottomof screen

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
char add[] = "add";
char subtract[] = "subtract";
char multiply[] = "multiply";
char divide[] = "divide";
char power[] = "power";
char X[] = "varx";
char space = ' ';
char logarithm[] = "log";
char ln[] = "ln";
char root[] = "root";
char swap[] = "swap";
char drop[] = "drop";
char roll[] = "roll";
char copy[] = "copy";
char sine[] = "sin";
char cosine[] = "cos";
char tangent[] = "tan";
char sec[] = "sec";
char csc[] = "csc";
char cot[] = "cot";
char arcsin[] = "arcsin";
char arccos[] = "arccos";
char arctan[] = "arctan";
char arcsec[] = "arcsec";
char arccsc[] = "arccsc";
char arccot[] = "arccot";
char togglesign[] = "togglesign";
char store[] = "store";
char functiontograph[] = "functiontograph";

//Mode Settings
int RadDeg = 1;

//Constants
double pi; //pi
double e; //e
double G; //Universal gravitation
double c; //speed of light

//Window Settings
double min_x = -5;
double max_x = 5;
double min_y = -6;
double max_y = 6;
double step_x = 1;
double step_y = 1;

//Functions
void push (double b);
double pop ();
void Swap ();
void Copy ();
void Drop ();
void Roll ();
void Add ();
void Subtract ();
void Multiply ();
void Divide ();
void Power ();
void Log ();
void Ln ();
void Root ();
void Sin ();
void Cos ();
void Tan ();
void Sec ();
void Csc ();
void Cot ();
void Arcsin ();
void Arccos ();
void Arctan ();
void Arcsec ();
void Arccsc ();
void Arccot ();
void ToggleSign ();
int GetButton ();
void Store ();
void FunctiontoGraph ();
void Graph ();
void DecimalFraction ();
void Interpreter ();
void Initialize ();
void NormalButton (int btn);
void SecondButton (int btn);
void AlphaButton (int btn);
void UpdateKeyboard ();
void UpdateDisplay ();
void UpdateKernel ();

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
    //printf("Number = %lf\n", g);
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

void FunctiontoGraph ()
{
    run_yequals = 0;
    for (double p = min_x; p <= max_x; p++)
    {
        x = p;
        Interpreter();
        printf("x = %lf\n", p);
        double l = pop();
        printf("y = %lf\n", l);
        xcoordinate[coordinate_cnt] = p;
        ycoordinate[coordinate_cnt] = l;
        coordinate_cnt++;
    }
    coordinate_cnt = 0;
    run_yequals = 1;
}

void Graph ()
{
    double delta_y = max_y - min_y;
    double delta_x = max_x - min_x;
    double ticks_y = (delta_y)/(step_y);
    double ticks_x = (delta_x)/(step_x);
    double tick_dist_x = (240)/(ticks_x);
    double tick_dist_y = (160-k)/(ticks_y);
    double one_pix_x = (delta_x)/(240);
    double one_pix_y = (delta_y)/(160-k);
}

void DecimalFraction ()
{
    double k = pop();
    k = .25;
    int num = (k)*(pow(10, 8));
    int den = pow(10, 8);
    for (unsigned int h = fmax(num, den); h <= fmax(num, den); h--)
    {
        if (num % h == 0 && den % h == 0)
        {
            double n = (num)/(h);
            double d = (den)/(h);
            printf("%lf/%lf\n", n, d);
            //print number to screen as a fraction
            push((n/d));
            break;
        }
    }
}

void Interpreter ()
{
    //printf("HERE\n");
    //printf("x = %lf\n", x);
    memset(operation, 0, sizeof operation);
    for (int t = 0; t < strlen(input_type); t++)
    {
        //printf("t = %i\n", t);
        //printf("string = %s\n", operation);
        char tok = input_type[t];
        
        if (tok != ' ')
        {
            strncat(operation, &tok, 1);
        }
        if (tok == ' ')
        {
            if (atof(operation))
            {
                q = atof(operation);
                push(q);
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, X) == 0)
            {
                printf("X = %lf\n", x);
                push(x);
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, logarithm) == 0)
            {
                Log();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, ln) == 0)
            {
                Ln();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, root) == 0)
            {
                Root();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, swap) == 0)
            {
                Swap();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, drop) == 0)
            {
                Drop();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, roll) == 0)
            {
                Roll();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, copy) == 0)
            {
                Copy();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, sine) == 0)
            {
                Sin();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, cosine) == 0)
            {
                Cos();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, tangent) == 0)
            {
                Tan();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, sec) == 0)
            {
                Sec();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, csc) == 0)
            {
                Csc();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, cot) == 0)
            {
                Cot();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, arcsin) == 0)
            {
                Arcsin();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, arccos) == 0)
            {
                Arccos();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, arctan) == 0)
            {
                Arctan();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, arcsec) == 0)
            {
                Arcsec();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, arccsc) == 0)
            {
                Arccsc();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, arccot) == 0)
            {
                Arccot();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, togglesign) == 0)
            {
                ToggleSign();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, store) == 0)
            {
                Store();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, add) == 0)
            {
                Add();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, subtract) == 0)
            {
                Subtract();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, multiply) == 0)
            {
                Multiply();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, divide) == 0)
            {
                Divide();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, power) == 0)
            {
                Power();
                memset(operation, 0, sizeof operation);
            }
            if (strcmp(operation, functiontograph) == 0)
            {
                if (run_yequals == 1)
                {
                    //printf("HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH\n");
                    FunctiontoGraph();
                }
                //printf("BBBBBBBBBBBBBBBBBBBBBBBBB\n");
                memset(operation, 0, sizeof operation);
            }
        }
    }
}

//runtime functions-------------------------------------------
void Initialize ()
{
    pi = 3.141592653589793;
    e = 2.718281828459045;
    G = pow(6.67, -11);
    c = pow(2.997924562, 10);
}

void NormalButton (int btn)
{
    switch (btn)
    {
            //NUMBERS--------------------------------------------
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
        case (40): strncat(input_type, &space, 1);
            printf("%s\n", input_type);
            Interpreter();
            memset(input_type, 0, sizeof input_type);
            break;
            //OPERATIONS-----------------------------------
        case (1): strncat(input_type, functiontograph, 15);
            break;
        case (2): strncat(input_type, swap, 4);
            break;
        case (4): strncat(input_type, root, 4);
            break;
        case (5): strncat(input_type, logarithm, 3);
            break;
        case (6): strncat(input_type, ln, 2);
            break;
        case (8): strncat(input_type, X, 4);
            break;
        case (10): strncat(input_type, copy, 4);
            break;
        case (11): strncat(input_type, sine, 3);
            break;
        case (12): strncat(input_type, arcsin, 6);
            break;
        case (18): strncat(input_type, drop, 4);
            break;
        case (19): strncat(input_type, cosine, 3);
            break;
        case (20): strncat(input_type, arccos, 6);
            break;
        case (26): strncat(input_type, roll, 4);
            break;
        case (27): strncat(input_type, tangent, 3);
            break;
        case (28): strncat(input_type, arctan, 6);
            break;
        case (35): strncat(input_type, power, 5);
            break;
        case (36): strncat(input_type, add, 3);
            break;
        case (37): strncat(input_type, subtract, 8);
            break;
        case (38): strncat(input_type, multiply, 8);
            break;
        case (39): strncat(input_type, divide, 6);
            break;
    }
}

void SecondButton (int btn)
{
    switch (btn)
    {
        case (8): strncat(input_type, store, 5);
            break;
        case (11): strncat(input_type, csc, 3);
            break;
        case (12): strncat(input_type, arccsc, 6);
            break;
        case (19): strncat(input_type, sec, 3);
            break;
        case (20): strncat(input_type, arcsec, 6);
            break;
        case (27): strncat(input_type, cot, 3);
            break;
        case (28): strncat(input_type, arccot, 6);
            break;
        case (32): strncat(input_type, togglesign, 10);
            break;
        case (42): //display home screen
            break;
    }
}

void AlphaButton (int btn)
{
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

int main (void)
{
    while (1)
    {
        DecimalFraction();
        Initialize();
        UpdateKeyboard();
        //UpdateDisplay();
        //UpdateKernel();
    }
}
