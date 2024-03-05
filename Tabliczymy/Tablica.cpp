#include "iostream"
#define log(message) std::cout<<message<<std::endl

int main()
{
    const int SIZE = 10;
    int tablica1[3] = {0, 1, 2};
    int tablica2[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        tablica2[i] = i+1;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        std::cout<<tablica2[i]<<" ";
    }
    
}