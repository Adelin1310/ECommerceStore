#include "converts.h"
#include <cmath>

template <typename T>
int std::DecToBin(T dec){
    int aux = 0, result = 0;
    while(dec)
    {
        aux = aux * 10;
        aux += dec%2;
        dec/=2;
    }
    while(aux){
        result*=10;
        result += aux%10;
        aux/=10;
    }
    return result;
}

template <typename T>
int std::BinToDec(T integer){
    unsigned int start = 0;
    unsigned int result = 0;
    while(integer)
    {
        result*=10;
        result = result + (integer%10 + pow(2, start));
        integer/=10;
        start++;
    }

    return result;

}