//
// Created by 25467 on 2023/6/30.
//

#include "leetcode2490.h"

bool leetcode2490::isCircularSentence(std::string sentence) {
    char cBegin = sentence[0];
    char lEnd;
    char nBegin;
    for(int i = 0; i < sentence.size(); i++){
        while(i < sentence.size() && sentence[i] != ' '){
            i++;
        }
        if(i + 1 < sentence.size() && sentence[i] == ' '){ // is a word
            lEnd = sentence[i - 1];
            nBegin = sentence[i + 1];
            if(lEnd != nBegin){
                return false;
            }
        }else if(i == sentence.size()){ //reach the end
            lEnd = sentence[i - 1];
            return lEnd == cBegin;
        }
    }
    return true;
}
