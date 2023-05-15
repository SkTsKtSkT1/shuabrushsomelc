//
// Created by 25467 on 2023/5/15.
//

#include "leetcode1072.h"
#include "unordered_map"

// count the pattern!
int leetcode1072::maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    //https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/solution/1072-an-lie-fan-zhuan-de-dao-zui-da-zhi-deng-xing-/
    // 容易过长
//    int mask = 0;
//    for(int i=0;i<n;i++){
//        mask = (mask<<1) |1;
//    }
    std::unordered_map<string,int> pattern;

//    //if 1 is 1 0 is 0;
//    for(int i=0;i<m;i++){
//        int val = 0;
//        for(int j=0;j<n;j++){
//            val = (val<<1)|matrix[i][j];
//        }
//        pattern[val]++; //全为1
//        pattern[val^mask]++; //全为0
//    }
    for(vector<int>& rows:matrix){
        pattern[get_mask_val(rows)]++;
    }
    int res=0;
    for(auto &[k,v]:pattern){
        res = std::max(res,v);
    }

    return res;
}

string leetcode1072::get_mask_val(vector<int> &rows) {
    string res;
    int temp = rows[0];
    int cnt=0;
    for(int& r:rows){
        if(r == temp){
            cnt++;
        }else{
            temp = r;
            res+= std::to_string(cnt);
            cnt=1;
        }
    }
    return res;
}
