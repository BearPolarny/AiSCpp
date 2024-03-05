#include "iostream"
#include "string"
#define log(message) std::cout<<message<<std::endl

int main()
{
    int i1 = 1, i2 = 2;
    double d1 = 2.4, d2 = 3.0;
    char c1 = 'a', c2 = 97;

    log(c1);
    log(c2);

    log("");


    log("Int + Int:");
    log(i1 + i2);
    log(typeid(i1 + i2).name());

    log("");

    log("Double + Double:");
    log(d1 + d2);
    log(typeid(d1 + d2).name());
    
    log("");

    log("Int + Double:");
    log(i1 + d2);
    log(typeid(i1 + d2).name());

    log("");

    log("Ciekawostka:");
    log(c1 + i1);
    log(char(c1 + i1));
    log(typeid(c1 + i1).name());
    
    log("");

    log(typeid(double(i1)).name());
}