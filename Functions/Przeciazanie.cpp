#include "iostream"
#include "string"
#define log(message) std::cout<<message<<std::endl

void funkcja()
{
    log("Funkcja A");
}
void funkcja(int a)
{
    log("Funkcja B");
}
void funkcja(int a, int b)
{
    log("Funkcja C");
}

int main()
{
    funkcja();
    funkcja(1);
    funkcja(1,2);
}