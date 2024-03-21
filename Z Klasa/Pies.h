#include <iostream>
#include "Zwierze.h"
#define log(mes) std::cout<<mes<<std::endl

class Pies: Zwierze
{
    public:
    void bark()
    {
        log("bark");
    }
    Pies();
    ~Pies();
};

Pies::Pies()
{
    log("mamy psa");
}

Pies::~Pies()
{
    log(name + " zdech³");
}
