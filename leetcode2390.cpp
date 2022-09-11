//
// Created by lzw on 2022/9/9.
//

#include "leetcode2390.h"
//#include "stack"
//#include "algorithm"
//using std::stack;
//string leetcode2390::removeStars(string s) {
//    int len=s.size();
//    string ans;
//    stack<char> st;
//    for(int i=0;i<len;){
//        if(s[i]!='*'){
//            st.push(s[i]);
//            i++;
//        }else{
//            if(!st.empty()) {
//                st.pop();
//            }
//            i++;
//        }
//    }
//    while(!st.empty()){
//        ans+=st.top();
//        st.pop();
//    }
//    std::reverse(ans.begin(), ans.end());
//    return ans;
//}
string leetcode2390::removeStars(std::string s) {
    string ans;
    for(int i=0;i<s.size();){
        if(s[i]!='*'){
            ans+=s[i];
            i++;
        }else{
            ans.pop_back();
            i++;
        }
    }
    return ans;
}