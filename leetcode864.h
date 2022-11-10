//
// Created by skt on 2022/11/10.
//

#ifndef ALGORITHM_LEETCODE864_H
#define ALGORITHM_LEETCODE864_H
#include "vector"
#include "string"

using std::vector;
using std::string;

class leetcode864 {
private:
    int xDir[4]={1,-1,0,0};
    int yDir[4]={0,0,1,-1};
public:
    int shortestPathAllKeys(vector<string>& grid);
};


#endif //ALGORITHM_LEETCODE864_H
