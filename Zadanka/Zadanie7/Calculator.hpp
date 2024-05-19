#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>

#include "TokenStream.hpp"
#include "VariableTable.hpp"

class Calculator
{
public:
	Calculator();
	Calculator(std::istream& str);
	void calculate();
private:
	double factorial(double d);
	double factorial(double d, double min);
	double primary_handler();
	double factorial_handler();
	double term_handler();
	double expression_handler();
	double statement_handler();

	double permutate(double n, double m);
	double combinate(double n, double m);

	double declaration();

	void help();
	bool is_reserved(char c);
	TokenStream* ts;
	VariableTable* variables;
};

