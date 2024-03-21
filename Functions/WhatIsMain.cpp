#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    int max;
    cout << "Wprowadz maksymalna wartosc:\n";
    cin >> max;

    vector<int> pierwsze;

    for (int obecnie_sprawdzana = 2; obecnie_sprawdzana <= max; ++obecnie_sprawdzana)
    {
        for (int dzielnik = 2; dzielnik * dzielnik <= obecnie_sprawdzana; ++dzielnik)
        {
            if (!(obecnie_sprawdzana % dzielnik))
            {
                break;
            }
            pierwsze.push_back(obecnie_sprawdzana);
        }
    }

    cout << "Pierwsze liczby miêdzy 1 i " << max << " to:\n";

    for (int i = 0; i < pierwsze.size(); ++i)
        cout << pierwsze[i] << " ";

    return 0;
}