//
// Created by lzw on 2022/11/7.
//

#include "leetcode816.h"

vector<string> leetcode816::ambiguousCoordinates(string s) {
    //首先去掉传入参数的括号，然后先枚举逗号位置，然后在每个逗号枚举小数点位置
    int n = s.size();
    vector<string> res;
    for (int k = 1; k <= n - 3; k++) {//n-2 时候只有一个数字 不考虑
        string l = s.substr(1, k);
        string r = s.substr(k + 1, n - 2 - k);
        vector<string> xCor = getNums(l);
        vector<string> yCor = getNums(r);
        for(string &x:xCor){
            for(string &y:yCor){
                res.push_back("("+x+", "+y+")");
            }
        }
    }
    return res;
}

vector<string> leetcode816::getNums(string& s){
    int n=s.size();
    if(n==1){
        return {s};
    }

    if(s[0]=='0' && s[n-1]=='0') return {};

    if(s[n-1]=='0') return {s};

    if(s[0]=='0') return {"0."+s.substr(1)};

    vector<string> res;

    res.push_back(s);

    for(int i=1;i<n;i++){
        string a=s.substr(0,i);
        string b=s.substr(i);
        res.push_back(a+"."+b);
    }

    return  res;

}
