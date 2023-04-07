#include <iostream>
#include "hard/leetcode1125.h"

int main() {
    leetcode1125 lc1125;
    vector<string> req_skills = {"java","nodejs","reactjs"};
    vector<vector<string>> people={
            {"java"},
            {"nodejs"},
            {"nodejs","reactjs"}
    };

    lc1125<<lc1125.smallestSufficientTeam(req_skills,people);
    return 0;
}

