#include <iostream>
#include <string>
#include <stdexcept>
#define log(message) std::cout<<message<<std::endl

int fibb(int n);
int fibb(int n, int *cache);

int main()
{
    int n, *cache;
    std::cin>>n;
    cache = new int[n];
    std::fill_n(cache,n,-1);
    log(fibb(n, cache));
    for (int i = 0; i < n; i++)
    {
        std::cout<<cache[i]<< " ";
    }
    
    system("pause");
}


int fibb(int n)
{
    if (n == 1)
    {
        return 0;
    } else if (n == 2)
    {
        return 1;
    } else {
        return fibb(n-1)+fibb(n-2);
    }
    
    
    // if (n == 1 || n == 2)
    // {
    //     return 1;
    // } else {
    //     return fibb(n-1)+fibb(n-2);
    // }
}

int fibb(int n, int q[])
{
    try
    {
        if (q[n-1] != -1)
        {
            return q[n-1];
        } else {
            if (n == 1)
            {
                q[n-1] = 1;
                return q[n-1];
            } else 
                if (n == 2)
                {
                    q[n-1] = 2;
                    return q[n-1];
                } else {
                    long long a, b;
                    a = fibb(n-1, q);
                    b = fibb(n-2, q);
                    long long c = a+b;
                    bool t = a+b > INT_MAX;
                    if (t)
                    {
                        throw std::invalid_argument("to much for me");
                    } else q[n-1] = int(a + b);
                    
                    return q[n-1];
                }
        }  
    }
    catch(const std::exception& e)
    {
        log("Za du¿o dla int");
        system("pause");
        exit(1);
    }
    
     
}


/*
    1. sprawdz czy w q jest juz liczba
        1.1 jesli tak to zwroc
        1.2 koniec
    2. oblicz f(n-1)
        2.2 dodaj n-1 do q
*/