#include "Token.hpp"

Token::Token(char ch)    // make a Token from a char
	:kind(ch), value(0) { }

Token::Token(char ch, double val)     // make a Token from a char and a double
	:kind(ch), value(val) { }

Token::Token(char ch, std::string n)
	:kind(ch), name(n), value(0)
{
}
char Token::getKind()
{
	return kind;
}
double Token::getValue() {
	return value;
}

std::string Token::getName()
{
	return name;
}
