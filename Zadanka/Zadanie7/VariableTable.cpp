#include "VariableTable.hpp"

VariableTable::VariableTable()
{
}

double VariableTable::getValue(std::string name)
{
	for (Variable v : variables)
	{
		if (v.getName() == name)
		{
			return v.getValue();
		}
	}
	throw std::domain_error("get: Udefined variable");
}

void VariableTable::setValue(std::string name, double value)
{
	for (Variable v : variables)
	{
		if (v.getName() == name)
		{
			v.setValue(value);
			return;
		}
	}
	throw std::domain_error("set: Udefined variable");
}

bool VariableTable::is_declared(std::string name)
{
	for (Variable v : variables)
	{
		if (v.getName() == name) return true;
	}
	return false;
}

double VariableTable::define_name(std::string name, double value)
{
	if (is_declared(name)) throw std::domain_error("Already Declared");
	variables.push_back(Variable(name, value));
	return value;
}
