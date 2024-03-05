#include "iostream"

#define log(message) std::cout<<message<<std::endl

int main()
{
    std::string x;
    log("Podaj imie: ");
    std::cin>>x;
    log("Hello");
    log(x);

    
    return 0;
}