#include <iostream>
#include <string>
#include <vector>

std::vector<double> split_into_numbers(std::string formula);

void quadratic()
{
    std::string formula;

    std::cout << "Enter formula in following form\
            \nAx2+Bx+C\
            \nWhere A, B, and C are given by you. You can choose between signs '+' and '-'";
            // \nIf you use decimals use '.'\n";
    std::cin >> formula;
    std::vector<double> numbers = split_into_numbers(formula);

    if (!numbers[0])
    {
        if (!numbers[1])
        {
            if (!numbers[2])
            {
                std::cout << "No roots\n";
            }
            else
                std::cout << "Infinietly many roots\n";
        }
        else
        {
            double root;
            root = -numbers[2] / numbers[1];
            std::cout << "Line with root in " << root << '\n';
        }
    }
    else
    {
        double discriminant = numbers[1] * numbers[1] - 4 * numbers[0] * numbers[2];
        // std::cout << "delta: " << discriminant << '\n';

        if (discriminant > 0)
        {
            double root1 = (-numbers[1] + sqrt(discriminant)) / (2 * numbers[0]);
            double root2 = (-numbers[1] - sqrt(discriminant)) / (2 * numbers[0]);
            std::cout << "Quadratic function with two roots in " << root1 << " and " << root2 << '\n';
        }
        else if (!discriminant)
        {
            double root1 = (-numbers[1] + sqrt(discriminant)) / (2 * numbers[0]);
            std::cout << "Quadratic function with one root in " << root1 << '\n';
        }
        else
        {
            std::cout << "Quadratic function with no roots\n";
        }
    }
}

std::vector<double> split_into_numbers(std::string formula)
{
    int posA, posB;
    std::vector<double> nums(3);
    posA = formula.find("x2");
    posB = formula.find("x", posA + 1);

    nums[0] = posA == -1 ? 0 : std::stod(formula.substr(0, posA));
    // brak A / Jest a: od pocz±tku do pozycji x2 lub 0

    nums[1] = posB == -1 ? 0 : posA == -1 ? std::stod(formula.substr(0, posB))   // Brak b - 0 / brak a jest b - do x
                                          : std::stod(formula.substr(posA + 2)); // od x2 + dwa znaki ( parser radzi sobie
                                                                                 //                  je¿eli b³±d to
                                                                                 //                   posB-posA-2 )

    if (posB == -1)                                         // Brak B
    {
        if (posA == -1)
            nums[2] = std::stod(formula);                   // Brak A
        else if (posA + 2 < formula.size())
            nums[2] = std::stod(formula.substr(posA + 2));  // Jest A i C
        else
            nums[2] = 0;                                    // Jest A i Brak C
    }
    else if (posB + 1 < formula.size())                     // Jest B i C
        nums[2] = std::stod(formula.substr(posB + 1)); 
    else
        nums[2] = 0;                                        // Jest B i brak C

    return nums;
}
