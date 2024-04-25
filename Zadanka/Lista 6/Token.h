#pragma once

class Token{
public:
    Token(char ch);
    Token(char ch, double val);
    char kind;        // what kind of token
    double value;     // for numbers: a value 
};