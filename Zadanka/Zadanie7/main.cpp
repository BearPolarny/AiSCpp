#include "Calculator.hpp"




void swap();

std::vector<int> swap_copy(std::vector<int> v);
void swap_in_place(std::vector<int>* v);


//------------------------------------------------------------------------------

int main() {
	try
	{
		std::cout << "Enter \"calc\" for calculator or \"swap\" for swap, q to exit!\n";
		std::string comm = "";
		while (true)
		{
			std::cin >> comm;
			if (comm == "q") return 0;
			else if (comm == "swap") swap();
			else if (comm == "calc")
			{
				Calculator();
			}
			else
			{
				std::cout << "Oops: unknown command!\n";
			}
		}
	}
	catch (...) {
		std::cout << "Oops: unknown exception!\n";
		return 2;
	}
}

//------------------------------------------------------------------------------


void swap()
{
	std::vector<int> vector = { 1, 2, 3, 4, 5 };
	std::cout << "Original vector:\n";
	for (int n : vector)
		std::cout << n << ' ';
	std::cout << '\n';
	std::cout << "First Swap\n";
	std::vector<int> new_vector = swap_copy(vector);
	std::cout << "Original vector:\n";
	for (int n : vector)
		std::cout << n << ' ';
	std::cout << '\n';
	std::cout << "New vector:\n";
	for (int n : new_vector)
		std::cout << n << ' ';
	std::cout << '\n';
	std::cout << "Second Swap\n";
	swap_in_place(&vector);
	std::cout << "Original vector:\n";
	for (int n : vector)
		std::cout << n << ' ';
	std::cout << '\n';
	return;
}

std::vector<int> swap_copy(std::vector<int> v)
{
	return std::vector<int> (v.rbegin(), v.rend());
}

void swap_in_place(std::vector<int>* v)
{
	std::reverse(v->begin(), v->end());
}
