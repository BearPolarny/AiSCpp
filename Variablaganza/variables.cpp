#include "iostream"
#include "string"
#define log(message) std::cout<<message<<std::endl

int main()
{
    // podstawowe

    bool logiczna = true;
    int calkowita = 1;
    double rzeczywista = 2.0;
    char znak = 'a';
    std::string slowo = "slowo";

    // dodatkowe

    long long spory_intiger = 3;
    float rzeczywista_2 = 2.12344;

    // modyfikator unsingned

    unsigned int tylko_dodatnie = 5;

    // jak to wygl±da:

    log("Max int: " + std::to_string(INT_MAX));
    log("Min int: " + std::to_string(INT_MIN));

    log("Max unsingned int: " + std::to_string(UINT_MAX));

    log("Max long: " + std::to_string(LONG_MAX));
    log("Min long: " + std::to_string(LONG_MIN));
    
    log("Max unsingned long: " + std::to_string(ULONG_MAX));
    
    log("Max long long: " + std::to_string(LLONG_MAX));
    log("Min long long: " + std::to_string(LLONG_MIN));
    
    log("Max unsingned long long: " + std::to_string(ULLONG_MAX));
    
    log("Max char: " + std::to_string(CHAR_MAX));
    log("Min char: " + std::to_string(CHAR_MIN));
    
    log("Max unsingned char: " + std::to_string(UCHAR_MAX));

}