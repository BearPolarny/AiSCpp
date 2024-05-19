#pragma once

#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "Dictionary.cpp" // linker is problematic with hpp

class TokenStream {
public:
	TokenStream();   // make a Token_stream that reads from std::cin
	TokenStream(std::istream& stream);   // make a Token_stream that reads from std::cin
	Token getToken();      // get a Token (getToken() is defined elsewhere)
	void putback(Token t);    // put a Token back
	void ignore(char c);
	const char prompt = '>';
	const char result = '=';
	static constexpr char print = ';';

	enum keywords_desc
	{
		help, quit, declkey, p, c, root, pow
	};
	enum commands
	{
		quit_com, factorial, help_com, root_com, pow_com, number, name, let
	};
private:
	Dictionary<std::string, keywords_desc> keywords;
	std::istream* stream;
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};
