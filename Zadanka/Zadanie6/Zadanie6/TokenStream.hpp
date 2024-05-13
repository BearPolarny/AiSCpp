#pragma once
#include "Token.hpp"
#include "Dictionary.cpp" // linker is problematic with hpp

class TokenStream {
public:
    TokenStream();   // make a Token_stream that reads from std::cin
    Token getToken();      // get a Token (getToken() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore (char c);
    //const char quit_com = 'q';
    const char prompt = '>';
    const char print = '=';
    //const char help_com = 'h';
    //const char root_com = 'r';
    //const char pow_com = 'o';
    //static constexpr int number = '8';
    //static constexpr char name = 'a';
    //static constexpr char let = 'l';
    //const std::string declkey = "let";
    //const std::string help = "help";
    //const std::string quit = "quit";
    enum keywords_desc
    {
        help, quit, declkey, p, c, root, pow
    };
    enum commands
    {
        quit_com, result, factorial, help_com, root_com, pow_com, number, name, let, 
    };
private:
    Dictionary<std::string, keywords_desc> keywords;
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};
