#include "iostream"
#include "string"
#define log(message) std::cout<<message<<std::endl

double pole_trapezu(double a, double b, double h)
{
    return (a + b) * h / 2;
}

int main()
{
    double baza, top, wysokosc;

    std::cin>>baza>>top>>wysokosc;
    log(pole_trapezu(baza, top, wysokosc));
    
}