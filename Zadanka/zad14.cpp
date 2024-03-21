#include <vector>
#include <iostream>

void sieve(int limit)
{
    std::vector<int> primes;
    if (limit < 2)
        std::cout << "None\n";
    else
    {
        primes.push_back(2);
        for (int current_num = 3; current_num <= limit; current_num++)
        {
            bool is_prime = true;
            // for (int i = 2; i * i <= current_num; i++)
            int i = 0;
            while (primes[i] <= sqrt(current_num))
            {
                if (!(current_num % primes[i++]))
                {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
            {
                primes.push_back(current_num);
            }
        }
        for (auto it = primes.begin(); it != primes.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }
}