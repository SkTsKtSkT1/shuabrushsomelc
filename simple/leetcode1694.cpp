//
// Created by skt on 2022/10/1.
//

#include "leetcode1694.h"

string leetcode1694::reformatNumber(std::string number) {
    int count=0;//' 'and'-'
    for(char c:number){
        if(c==' '||c=='-'){
            count++;
        }
    }
    if(count==0) return number;
    int n=number.size();
    int nNum=n-count;
    if(nNum<=4){
        return lessThan4(number,0,nNum);
    }
    int cur=0;
    int cnt=0;
    string ans;
    do{
        nNum-=3;
        do{
            if(number[cur]!=' '&&number[cur]!='-'){
                ans+=number[cur];
                cur++;
                cnt++;
            }else{
                cur++;
            }
        }while(cnt<3);
        ans+='-';
        cnt=0;
    }while(nNum>4);
    ans+= lessThan4(number,cur,nNum);
//    if(nNum!=4){
//        for(int i=cur;i<n;i++){
//            if(number[i]!=' '&&number[i]!='-'){
//                ans+=number[i];
//            }
//        }
//    }else{
//        for(int i=cur;i<n;i++){
//            if(number[i]!=' '&&number[i]!='-'){
//                ans+=number[i];
//                cnt++;
//                if(cnt==2){
//                    ans+="-";
//                }
//            }
//        }
//    }
    return ans;
}

string leetcode1694::lessThan4(std::string& number, int cur,int nNum) {
    string ans;
    int cnt=0;
    if(nNum!=4){
        for(int i=cur;i<number.size();i++){
            if(number[i]!=' '&&number[i]!='-'){
                ans+=number[i];
            }
        }
    }else{
        for(int i=cur;i<number.size();i++){
            if(number[i]!=' '&&number[i]!='-'){
                ans+=number[i];
                cnt++;
                if(cnt==2){
                    ans+="-";
                }
            }
        }
    }
    return ans;
}


string leetcode1694::reformatNumber1(std::string number) {
    int cnt=0;
    string ans;
    for(char c:number){
        if(c!=' '&&c!='-') {
            ans += c;
            cnt++;
            if (cnt == 3) {
                ans += '-';
                cnt=0;
            }
        }
    }
    //length=3*n则最后刚好分成n个3，最后一个'-'去掉
    if(ans.back()=='-'){
        ans.pop_back();
        return ans;
    }
    //length=3*n+2 余2,xxx-xxx-xx不需要考虑符合要求
    //length=3*n+1 余4 xxx-xxx-x->xxx-xx-xx
    if(ans[ans.size()-2]=='-'){
        std::swap(ans[ans.size()-2],ans[ans.size()-3]);
        return ans;
    }
    return ans;
}