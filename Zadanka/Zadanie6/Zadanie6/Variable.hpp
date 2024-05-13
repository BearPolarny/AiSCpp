#pragma once
#include <string>

class Variable {
public:
    Variable(std::string n, double v);
    std::string getName();
    double getValue();
    void setValue(double v);
private:
    std::string name;
    double value;
};
