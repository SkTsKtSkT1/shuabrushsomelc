//
// Created by lzw on 2022/10/2.
//

#include "leetcode777.h"


bool leetcode777::canTransform(std::string start, std::string end) {
//XL->LX or RX->XR 所以如果start和end能转换得到，相当于L只能越过X往左走，R只能越过X往右走，所以start的L一定比end中的L的下标大，R则是小。并且两个之间的LR相对位置不能改变 比如LxxxxR 不能变成RxxxxL
//    string start="RXXLRXRXL";
//    string   end="XRLXXRRLX";
    int i=0;
    int j=0;
    while(i<start.size() || j<end.size()){
        while(i<start.size()&& start[i]=='X') i++;
        while(j<end.size()&& end[j]=='X') j++;
        if(i==start.size() ||j==end.size()) return i==j;//全是xxxx
        if(start[i]!=end[j])  return false; //相对位置不对
        if(start[i]=='L' && i<j) return false;
        if(start[i]=='R' && i>j) return false;

        i++;
        j++;
    }
    return true;
}