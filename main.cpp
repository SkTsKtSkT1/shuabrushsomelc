#include <iostream>
#include "mianshi/mianshi01_08.h"


int main() {
    mianshi01_08 ms0108;
    vector<vector<int>> matrix={
            {0,1,2,0},
            {3,4,5,2},
            {1,3,1,5}
    };
    ms0108.setZeroes(matrix);
    ms0108<<matrix;
    return 0;


}

