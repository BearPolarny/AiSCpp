#pragma once
#include <string>
#include <vector>
#include "Variable.hpp"

class VariableTable
{
public:
	VariableTable();
    double getValue(std::string s);
    void setValue(std::string s, double d);
    bool is_declared(std::string d);
    double define_name(std::string n, double v);
private:
    std::vector<Variable> variables;
};

