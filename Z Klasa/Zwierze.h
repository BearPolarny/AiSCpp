#include <iostream>
#define log(mes) std::cout<<mes<<std::endl

class Zwierze
{
protected:
    std::string name;
public:
    Zwierze();
    void setName(std::string n)
    {
        name = n;
    }

    std::string getName()
    {
        return name;
    }

    void bark()
    {
        log("generic animal noise");
    }
};
Zwierze::Zwierze()
{
    log("Mamy zwierza");
};