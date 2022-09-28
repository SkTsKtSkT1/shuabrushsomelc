#include <iostream>
#include "mianshi/mianshi17_09.h"


int main() {
    mianshi17_09 ms1709;
    int k=10;
    for(int i=1;i<=k;i++){
        std::cout << ms1709.getKthMagicNumber(i) << std::endl;
    }
    return 0;


}

