#pragma once
#include <string>

struct Token{
public:
    Token(char ch);
    Token(char ch, double val);
    Token(char ch, std::string n);
    char getKind();
    double getValue();
    std::string getName();
private:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    std::string name;
};
