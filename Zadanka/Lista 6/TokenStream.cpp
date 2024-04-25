#include "TokenStream.h"
#include <iostream>

TokenStream::TokenStream()
    :full(false), buffer(0)    // no Token in buffer
{
}

void TokenStream::putback(Token t)
{
    if (full) throw std::runtime_error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token TokenStream::get()
{
    try{
        if (full) {       // do we already have a Token ready?
            // remove token from buffer
            full = false;
            return buffer;
        }

        char ch;
        std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

        switch (ch) {
        case '=':    // for "print"
        case 'q':    // for "quit"
        case '(': case ')': case '+': case '-': case '*': 
        case '/': case '%': case '!': case 'P': case 'p': case ',':
        case 'C': case 'c':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '9': case '8':
        {
            std::cin.putback(ch);         // put digit back into the input stream
            double val;
            std::cin >> val;              // read a floating-point number
            return Token('8', val);   // let '8' represent "a number"
        }
        default:
            throw std::runtime_error("Bad token:");
        }
    }
    catch (std::runtime_error e) {
        std::cout << "get: " << e.what() << '\n';
    }
}