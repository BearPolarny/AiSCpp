#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <sstream>

void zad8();
std::vector<int> split(std::string str);

void print_vector(std::vector<long long> vec);
void print_vector(std::vector<int> vec);

std::vector<long long> fibo_slow(int n);

void bulls_and_cows();
int check_bulls(std::vector<int> check, std::vector<int> guess);
int check_cows(std::vector<int> check, std::vector<int> guess);

int main()
{
    int zad = 1;

    while (zad)
    {
        std::cout << "Enter exercise number:\
        \n1. Fibonacci\
        \n2. Bulls and Cows\
        \n3. Number Summer\
        \n0. Exit\n";

        std::cin >> zad;

        switch (zad)
        {
        case 0:
            std::cout << "Goodbye\n";
            break;
        case 1:
            int limit;
            std::cout << "Set number of Fibs: ";
            std::cin >> limit;
            if (limit < 1)
            {
                std::cout << "Number must be bigger than 0!\n";
            }
            else if (limit < 94)
                print_vector(fibo_slow(limit));
            else
                std::cout << "Biggest number will overflow!\n";

            int max;
            max = 0;
            for (int i = 1; i < 50; i++)
            {
                int a = fibo_slow(i).back();
                if (a < INT_MAX)
                    max = a;
                else
                    break;
            }
            std::cout << "max in int is " << max << "\n";

            break;
        case 2:
            bulls_and_cows();
            break;
        case 3:
            zad8();
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }

    return 0;
}

void bulls_and_cows()
{
    try
    {

        std::vector<int> num_set = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(std::begin(num_set), std::end(num_set), g);
        num_set.resize(4);
        print_vector(num_set);
        std::cout << "\n";

        std::vector<int> guess;

        bool end_condition = false;

        while (!end_condition)
        {
            std::cout << "Enter 4 digits: ";
            for (int i = 0; i < 4; i++)
            {
                int a;
                std::cin >> a;
                guess.push_back(a);
            }

            int bulls = check_bulls(num_set, guess);
            int cows = check_cows(num_set, guess);
            guess.clear();

            if (bulls != 4)
            {
                std::string output = "";
                output += std::to_string(bulls);
                output += bulls == 1 ? " Bull, " : " Bulls, ";
                output += std::to_string(cows);
                output += bulls == 1 ? " Cow\n" : " Cows\n";

                std::cout << output;
            }
            else
            {
                std::cout << "You Win!!\n";
                end_condition = true;
            }
        }
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    }
}

std::vector<long long> fibo_slow(int n)
{
    try
    {
        std::vector<long long> nums;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == 1)
                nums.push_back(i);
            else
                nums.push_back(nums[i - 1] + nums[i - 2]);
        }
        return nums;
    }
    catch (std::exception e)
    {
        std::cout << e.what();
        return std::vector<long long>{0};
    }
}

void zad8()
{
    try
    {
        std::vector<int> nums;

        std::cout << "Input whole numbers separated with spaces\n";
        std::string line;
        std::cin.ignore();
        std::getline(std::cin, line);

        nums = split(line);

        int n;
        std::cout << "How many numbers do you want to sum up?\n";
        std::cin >> n;

        if (n <= 0)
        {
            std::cout << "You entered non positive number\n";
        }
        if (n > nums.size())
        {
            std::cout << "There isn't as much numbers.\n";
        }
        int suma = 0;
        for (int i = 0; i < n; ++i)
            suma += nums[i];

        std::cout << "The sum of the first " << n << " numbers: ";
        nums.resize(n);
        print_vector(nums);
        std::cout << " is: " << suma << ".\n";
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    }
}

std::vector<int> split(std::string str)
{
    std::vector<int> a;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, ' '))
    {
        a.push_back(std::stoi(token));
    }
    return a;
}

void print_vector(std::vector<long long> vec)
{
    std::string output;
    for (int i = 0; i < vec.size(); i++)
    {
        output += std::to_string(vec[i]);
        output += ", ";
    }
    output.resize(output.length() - 2);

    std::cout << output << "\n";
}
void print_vector(std::vector<int> vec)
{
    std::string output;
    for (int i = 0; i < vec.size(); i++)
    {
        output += std::to_string(vec[i]);
        output += ", ";
    }
    output.resize(output.length() - 2);

    std::cout << output;
}

int check_bulls(std::vector<int> check, std::vector<int> guess)
{
    int bulls = 0;
    for (int i = 0; i < check.size(); i++)
    {

        if (guess.at(i) == check.at(i))
            ++bulls;
    }
    return bulls;
}

int check_cows(std::vector<int> check, std::vector<int> guess)
{
    int cows = 0;
    for (int i = 0; i < check.size(); i++)
    {
        for (int j = 0; j < guess.size(); j++)
        {
            if (check.at(i) == guess.at(j) && i != j)
            {
                cows++;
            }
        }
    }

    return cows;
}
