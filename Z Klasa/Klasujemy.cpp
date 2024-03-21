#include <iostream>
#include "Pies.h"
#include "Zwierze.h"

#define log(mes) std::cout<<mes<<std::endl


int main()
{
    Zwierze zwierz;

    zwierz.bark();
    
    Pies pies;

    pies.bark();

    pies.~Pies();
}