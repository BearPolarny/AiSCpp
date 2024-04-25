#include <iostream>
#include <cstdio>
#include "TokenStream.h"


double fact(double d);
double fact(double d, double min);
double primary(TokenStream* ts);
double factorial(TokenStream* ts);
double term(TokenStream* ts);
double expression(TokenStream* ts);

double permutate(double n, double m);
double combinate(double n, double m);



//------------------------------------------------------------------------------

int main() {
    try
    {
        TokenStream ts;        // provides get() and putback() in non global way
        while (std::cin) {
            Token t = ts.get();

            double val;
            // std::cout<<t.kind<<' '<<t.value<<" "<<val<<'\n';

            if (t.kind == 'q') break; // 'q' for quit
            if (t.kind == '=')        // ';' for "print now"
                std::cout << "=" << val << '\n';
            else
                ts.putback(t);
            val = expression(&ts);
        }
    }
    catch (...) {
        std::cout << "Oops: unknown exception!\n";
        return 2;
    }
}

//------------------------------------------------------------------------------
// deal with numbers and parentheses
double primary(TokenStream* ts)
{
    try{
        Token t = ts->get();
        // std::cout<<"PP"<<t.kind<<' '<<t.value;

        switch (t.kind) {
        case '(':    // handle '(' expression ')'
        {
            double d = expression(ts);
            t = ts->get();
            if (t.kind != ')') throw std::runtime_error("')' expected");
            return d;
        }
        case 'P': case 'p':
        {
            t = ts->get();
            if (t.kind != '(') throw std::runtime_error("'(' expected");
            double n = expression(ts);
            t = ts->get();
            if (t.kind != ',') throw std::runtime_error("',' expected");
            double m = expression(ts);
            t = ts->get();
            if (t.kind != ')') throw std::runtime_error("')' expected");
            if (n < m) throw std::runtime_error("Amount in set cannot be bigger than set itself");
            return permutate(n, m);
        }
        case 'C': case 'c':
        {
            t = ts->get();
            if (t.kind != '(') throw std::runtime_error("'(' expected");
            double n = expression(ts);
            t = ts->get();
            if (t.kind != ',') throw std::runtime_error("',' expected");
            double m = expression(ts);
            t = ts->get();
            if (t.kind != ')') throw std::runtime_error("')' expected");
            if (n < m) throw std::runtime_error("Amount in set cannot be bigger than set itself");

            return combinate(n, m);
        }
        case '8': case '!':           // we use '8' to represent a number
            return t.value;  // return the number's value
        default:
            throw std::runtime_error("primary expected");
        }
    }
    catch (std::runtime_error e) {
        std::cout << "primary: " << e.what() << '\n';
    }
}

//------------------------------------------------------------------------------

double factorial(TokenStream* ts)
{
    double left = primary(ts);
    Token t = ts->get();
    while (true) {
        if (t.kind == '!')
        {
            if (left == int(left) && left > 0){
                left = fact(left);
                t = ts->get();
            } else throw std::domain_error("Factorial of non-Natural");
        }
        ts->putback(t);
        return left;
    }
}

// deal with *, /, and %
double term(TokenStream* ts)
{
    try{
        double left = factorial(ts);
        // std::cout<<'f'<<left;

        Token t = ts->get();        // get the next token from token stream

        while (true) {
            switch (t.kind) {
            case '*':
                left *= primary(ts);
                t = ts->get();
                break;
            case '/':
            {
                double right = primary(ts);
                if (right == 0) throw std::domain_error("divide by zero");
                left /= right;
                t = ts->get();
                break;
            }
            default:
                ts->putback(t);     // put t back into the token stream
                return left;
            }
        }
    }
    catch (std::domain_error e) {
        std::cout << "term: " << e.what() << '\n';
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression(TokenStream* ts)
{
    try {
        double left = term(ts);      // read and evaluate a Term
        // std::cout<<'t'<<left;
        Token t = ts->get();        // get the next token from token stream

        while (true) {
            switch (t.kind) {
            case '+':
                left += term(ts);    // evaluate Term and add
                t = ts->get();
                break;
            case '-':
                left -= term(ts);    // evaluate Term and subtract
                t = ts->get();
                break;
            default:
                ts->putback(t);     // put t back into the token stream
                return left;       // finally: no more + or -: return the answer
            }
        }
    }
    catch (std::exception e) {
        std::cout << "expression: " << e.what() << '\n';
    }
}

double fact(double d)
{

    if (d==1) return 1;
    else return d * fact(d-1);
}

double fact(double d, double min)
{
    if (d==min) return min;
    else return d * fact(d-1, min);
}

double permutate(double n, double m)
{
    double s = n - m;
    double result;
    // std::cout<<n<<' '<<m<<' '<<s<<' ';

    result = fact(n, s+1);
    // std::cout<<result;

    return result;
}

double combinate(double n, double m)
{
    return permutate(n, m) / fact(m);
}