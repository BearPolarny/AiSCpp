#include "TokenStream.hpp"

#include <iostream>

TokenStream::TokenStream()
    :full(false), buffer(0)   // no Token in buffer
{
    dict.append("help", help);
    dict.append("c", c);
    dict.append("p", p);
    dict.append("quit", quit);
    dict.append("pow", pow);
    dict.append("root", root);
    dict.append("let", declkey); // Add all keywords to dictionary
}

void TokenStream::putback(Token t)
{
    if (full) throw std::runtime_error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token TokenStream::getToken()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case '(': case ')': case '!':
    case '*': case '/': case '%':
    case '+': case '-':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9': case '8':
    {
        std::cin.putback(ch);         // put digit back into the input stream
        double val;
        std::cin >> val;              // read a floating-point number
        return Token(number, val);   // let '8' represent "a number"
    }
    case 'P': case 'p':  
    case 'C': case 'c':
    case 'r': case 'o':
    case ',':
        if (!isalnum(std::cin.peek()) || ch == ',')
        {
            return Token(ch);
        }
    default:
        if (isalpha(ch))
        {
            std::cin.putback(ch); 
            std::string s;
            //s += ch;
            while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            std::cin.putback(ch);
            if (dict.key_exists(s))
            {
                switch (dict[s])
                {
                case help:
                    return Token(help_com, 0);
                    break;
                case quit:
                    return Token(quit_com, 0);
                    break;
                case declkey:
                    return Token(let);
                    break;
                case root:
                    return Token(root_com, 0);
                    break;
                case pow:
                    return Token(pow_com, 0);
                    break;

                default:
                    break;
                }
            }
            //if (s == declkey)
            //{
            //    return Token(let);
            //}
            //if (s == help)
            //{
            //    return Token(help_com, 0);
            //}
            //if (s == quit)
            //{
            //    return Token(quit_com, 0);
            //}
            return Token(name, s);
        }
        throw std::runtime_error("Bad token:");
    }

}

void TokenStream::ignore(char c)
{
    if (full && c==buffer.getKind())
    {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (std::cin>>ch)
        if (ch == c) return;

}
