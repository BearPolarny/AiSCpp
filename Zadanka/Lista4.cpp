#include <iostream>
#include "zad14.cpp"
#include "zad18.cpp"

int main()
{
    int zad = 1;

    while (zad)
    {
        std::cout << "Enter exercise number:\
        \n1. Eratosthenes' Sieve\
        \n2. Quadratic Formula\
        \n0. Exit\n";

        std::cin >> zad;

        switch (zad)
        {
        case 0:
            std::cout << "Goodbye\n";
            break;
        case 1:
            int limit;
            std::cout << "Set max prime: ";
            std::cin >> limit;
            sieve(limit);
            break;
        case 2:
            quadratic();
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }

    return 0;
}