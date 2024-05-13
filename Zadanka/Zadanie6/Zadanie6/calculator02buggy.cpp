#include <iostream>
#include <cstdio>
#include <cmath>

#include "TokenStream.hpp"
#include "VariableTable.hpp"


double fact(double d);
double fact(double d, double min);
double primary(TokenStream* ts, VariableTable* variables);
double factorial(TokenStream* ts, VariableTable* variables);
double term(TokenStream* ts, VariableTable* variables);
double expression(TokenStream* ts, VariableTable* variables);
double statement(TokenStream* ts, VariableTable* variables);

double permutate(double n, double m);
double combinate(double n, double m);

void calculate(TokenStream* ts, VariableTable* variables);

double declaration(TokenStream* ts, VariableTable* variables);

void help(TokenStream* ts);
bool is_reserved(char c);


//------------------------------------------------------------------------------

int main() {
    try
    {
        std::cout<<"Welcome to simple calculator v1.\n\
Enter \"help h\" for list of commands\n";

        TokenStream ts;        // provides getToken() and putback() in non global way
        VariableTable variables;

        variables.define_name("PI", 3.14159265358979323846);
        variables.define_name("e", 2.7182818284);
        variables.define_name("k", 1000);

        calculate(&ts, &variables);
    }
    catch (...) {
        std::cout << "Oops: unknown exception!\n";
        return 2;
    }
}

//------------------------------------------------------------------------------
// deal with numbers and parentheses
double primary(TokenStream* ts, VariableTable* variables)
{
    Token t = ts->getToken();
    // std::cout<<"PP"<<t.getKind()<<' '<<t.getValue();

    switch (t.getKind()) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ')') throw std::runtime_error("')' expected");
        return d;
    }
    case 'P': case 'p':
    {
        t = ts->getToken();
        if (t.getKind() != '(') throw std::runtime_error("'(' expected. For more info use \"help p\" command");
        double n = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ',') throw std::runtime_error("',' expected. For more info use \"help p\" command");
        double m = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ')') throw std::runtime_error("')' expected. For more info use \"help p\" command");
        if (n < m) throw std::runtime_error("Amount in set cannot be bigger than set itself");
        return permutate(n, m);
    }
    case 'C': case 'c':
    {
        t = ts->getToken();
        if (t.getKind() != '(') throw std::runtime_error("'(' expected. For more info use \"help c\" command");
        double n = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ',') throw std::runtime_error("',' expected. For more info use \"help c\" command");
        double m = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ')') throw std::runtime_error("')' expected. For more info use \"help c\" command");
        if (n < m) throw std::runtime_error("Amount in set cannot be bigger than set itself");

        return combinate(n, m);
    }
    case 'r':
    {
        t = ts->getToken();
        if (t.getKind() != '(') throw std::runtime_error("'(' expected. For more info use \"help r\" command");
        double n = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ',') throw std::runtime_error("',' expected. For more info use \"help r\" command");
        double m = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ')') throw std::runtime_error("')' expected. For more info use \"help r\" command");

        return pow(n,1./m);
    }
    case 'o':
    {
        t = ts->getToken();
        if (t.getKind() != '(') throw std::runtime_error("'(' expected. For more info use \"help o\" command");
        double n = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ',') throw std::runtime_error("',' expected. For more info use \"help o\" command");
        double m = expression(ts, variables);
        t = ts->getToken();
        if (t.getKind() != ')') throw std::runtime_error("')' expected. For more info use \"help o\" command");

        return pow(n, m);
    }
    case ts->number : case '!':           // we use '8' to represent a number
        return t.getValue();  // return the number's value
    case ts->name:
        ts->putback(Token(ts->number, variables->getValue(t.getName())));
        return primary(ts, variables);
    default:
        throw std::runtime_error("primary expected");
    }
}

//------------------------------------------------------------------------------

double factorial(TokenStream* ts, VariableTable* variables)
{
    double left = primary(ts, variables);

    while (true)
    {
        Token t = ts->getToken();
        if (t.getKind() == '!')
        {
            if (left == int(left) && left > 0) {
                left = fact(left);
            }
            else throw std::domain_error("Factorial of non-Natural");
        }
        else
        {
            ts->putback(t);
            return left;
        }

    }

    /*while (true) {
        if (t.getKind() == '!')
        {
            if (left == int(left) && left > 0){
                left = fact(left);
            } else throw std::domain_error("Factorial of non-Natural");
        }
        ts->putback(t);
        return left;
    }*/
}

// deal with *, /, and %
double term(TokenStream* ts, VariableTable* variables)
{
    double left = factorial(ts, variables);
    // std::cout<<'f'<<left;

    Token t = ts->getToken();        // getToken the next token from token stream

    while (true) {
        switch (t.getKind()) {
        case '*':
            left *= primary(ts, variables);
            t = ts->getToken();
            break;
        case '/':
        {
            double right = primary(ts, variables);
            if (right == 0) throw std::domain_error("divide by zero");
            left /= right;
            t = ts->getToken();
            break;
        }
        case '%':
        {
            double right = primary(ts, variables);
            if (right == 0) throw std::domain_error("divide by zero");
            if (right == int(right) && right > 0 && left == int(left)){
                left = int(left) % int(right);
                t = ts->getToken();
            } else throw std::domain_error("Modulo is non-Natural");
            break;
        }
        default:
            ts->putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression(TokenStream* ts, VariableTable* variables)
{
    double left = term(ts, variables);      // read and evaluate a Term
    // std::cout<<'t'<<left;
    Token t = ts->getToken();        // getToken the next token from token stream

    while (true) {
        switch (t.getKind()) {
        case '+':
            left += term(ts, variables);    // evaluate Term and add
            t = ts->getToken();
            break;
        case '-':
            left -= term(ts, variables);    // evaluate Term and subtract
            t = ts->getToken();
            break;
        default:
            ts->putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double fact(double d)
{
    double res = 1;
    for (int i = 1; i <= d; i++)
    {
        res *= i;
    }
    return res;
}

double fact(double d, double min)
{
    double res = 1;
    for (double i = d; i >= min; i--)
    {
        res *= i;
    }
    //if (d==min) return min;
    //else return d * fact(d-1, min);
    return res;
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


double statement(TokenStream* ts, VariableTable* variables)
{
    Token t = ts->getToken();
    switch (t.getKind())
    {
    case ts->let:
        return declaration(ts, variables);
    default:
        ts->putback(t);
        return expression(ts, variables);
    }
}

void calculate(TokenStream* ts, VariableTable* variables)
{
        /* code */
        //double val{};
        while (std::cin) {
    try
    {
                std::cout<<ts->prompt;
                Token t = ts->getToken();
                while (t.getKind() == ts->print) t = ts->getToken();
                if (t.getKind() == ts->quit_com) return;
                if (t.getKind() == ts->help_com) help(ts);
                else {
                    ts->putback(t);
                    std::cout << ts->result << statement(ts, variables) << std::endl;
                }

                //if (t.getKind() == ts->quit) break; // 'q' for quit
                //if (t.getKind() == ts->print)        // ';' for "print now"
                //    std::cout << ts->result << val << '\n';
                //else
                //    ts->putback(t);
                //val = statement(ts);
            }
    catch (std::runtime_error& e)
    {
        std::cout<<e.what()<<std::endl;
        ts->ignore(ts->print);
    }
    catch (std::domain_error& e)
    {
        std::cout<<e.what()<<std::endl;
        ts->ignore(ts->print);
    }
    }
    
}

double declaration(TokenStream* ts, VariableTable* variables)
{
    Token t = ts->getToken();
    if (is_reserved(t.getKind())) throw std::domain_error("Name reserved for existing function");
    if (t.getKind() != ts->name) throw std::domain_error("Name expected");
    std::string var_name = t.getName();

    Token t2 = ts->getToken();
    if (t2.getKind() != ts->result) throw std::domain_error("= missing in declaration of " + var_name);

    double d = expression(ts, variables);
    variables->define_name(var_name, d);

    return d;
}

void help(TokenStream* ts)
{
    Token t = ts->getToken();
    if (t.getName() == "h") t = Token('h');
    switch (t.getKind())
    {
    case 'h':
        std::cout << "Here you can: \n\
1. Add and subtract with + and -\n\
2. Multiply, divide and modulo with *, \\ and %\n\
3. Calculate factorial with !\n\
4. Calculate permutation with p(n,m) -- help p for more\n\
5. Calculate permutation with c(n,m) -- help c for more\n\
6. Calculate power with pow(n,m) -- help o for more\n\
7. Calculate root with root(n,m) -- help r for more\n\
Evaluate with =\n\
quit to quit\n\
Enjoy!\n";
        break;
    case 'p':
        std::cout << "Permutaton must be in form [p/P]([expression],[expression])\n";
        break;
    case 'c':
        std::cout << "Combination must be in form [c/C]([expression],[expression])\n";
        break;
    case 'o':
        std::cout << "Power must be in form pow([base],[exponent])\n";
        break;
    case 'r':
        std::cout << "Root must be in form root([radicand],[index])\n";
        break;
    default:
        throw std::domain_error("Wrong help topic!");
    }
}

bool is_reserved(char c)
{
    return c == 'P' || c == 'p' || c == 'C' || c == 'c';
}
