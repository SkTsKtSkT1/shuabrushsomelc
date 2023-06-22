//
// Created by 25467 on 2023/6/22.
//

#ifndef ALGORITHM_MIANSHI_16_19_H
#define ALGORITHM_MIANSHI_16_19_H

#include "vector"

class mianshi_16_19 {
private:
    int x_dir[8] = {0 , 0, 1 , -1, 1, -1, 1, -1};
    int y_dir[8] = {1 , -1, 0, 0, 1, -1, -1, 1};
public:
    std::vector<int> pondSizes(std::vector<std::vector<int>>& land);
};


#endif //ALGORITHM_MIANSHI_16_19_H
