//
// Created by lzw on 2022/10/19.
//

#include "leetcode1700.h"

int leetcode1700::countStudents(vector<int> &students, vector<int> &sandwiches) {
//由于student可以不断往后插，所以sandwich的排序决定了剩余的数量，所以遍历即可
    vector<int> needSandwich(2,0);
    for(int stu:students){
        needSandwich[stu]++;
    }
    for(int sandwich : sandwiches){
        if(needSandwich[sandwich]>0){
            needSandwich[sandwich]--;
        }else{
            break;
        }
    }
    return needSandwich[0]+needSandwich[1];
}
