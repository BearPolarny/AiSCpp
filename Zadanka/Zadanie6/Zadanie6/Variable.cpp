#include "Variable.hpp"
#include <stdexcept>

Variable::Variable(std::string n, double v) : name(n), value(v) {}

std::string Variable::getName()
{
	return name;
}

double Variable::getValue()
{
	return value;
}

void Variable::setValue(double v)
{
	value = v;
}

