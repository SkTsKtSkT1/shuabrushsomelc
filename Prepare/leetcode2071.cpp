//
// Created by 25467 on 2023/4/12.
//

#include "leetcode2071.h"

#include "algorithm"
#include "map"
//二分查找完成的任务数 + 固定的任务数下贪心选择厉害的工人+药丸分配给离tasks差最小的人
int leetcode2071::maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
    sort(workers.begin(),workers.end(),[&](int i,int j)->bool{
        return i>j; //such that __comp(*(i+1),*i) is false for every iterator i in the range [__first,__last-1)
    });//从大到小排列
    sort(tasks.begin(),tasks.end(),[&](int i,int j)->bool{
        return i>j; //such that __comp(*(i+1),*i) is false for every iterator i in the range [__first,__last-1)
    });//从难到易排列
    int min=0;
    int max=std::min(tasks.size(),workers.size());

    while(min<=max){
        int mid = min+((max-min)>>1);
        if(!verify_satisfy({tasks.cend()-mid,tasks.cend()}, {workers.begin(),workers.begin()+mid},pills,strength,mid)){
            max = mid -1;
        }else{
            min = mid+1;
        }
    }
    return max;
}

//最强的嗑药能不能做完最简单的 num 个任务
//指派也只需要最强的x个人
//超时。。。 但是貌似结果是对的
//bool leetcode2071::verify_satisfy(const vector<int> task, const vector<int> workers, int pills, int strength, int num) {
//    int cnt=0;
//    int work_index=0;
//    vector<int> used(workers.size(),0);
//    for(int i=0;i<task.size();++i){
//        while(work_index<workers.size() && used[work_index]!=0){
//            work_index++;
//        }
//        if(work_index>=workers.size()) break;
//        if(workers[work_index]>=task[i] ){
//            cnt++;
//            used[work_index]=1;
//            work_index++;
//
//            //否则就找一个吃完药能胜任的且power最弱的工人上
//        }else if(pills > 0){
//            for(int j= workers.size()-1;  j>= work_index; --j){
//                if(used[j]==1) continue;
//                if(workers[j]+strength >= task[i]){
//                    cnt++;
//                    pills--;
//                    used[j]=1;
//                    break;
//                }
//            }
//        }
//    }
//
//    return cnt>=num;
//}
bool leetcode2071::verify_satisfy(const vector<int> task, const vector<int> workers, int pills, int strength, int num) {
    std::map<int,int> works;
    for(const int w:workers) works[w]++; //按顺序插入
    for(const int t:task){
        if(works.empty()) return false;
        int cur = std::prev(works.end())->first;
        if(cur>=t){
            if(--works[cur] == 0) works.erase(cur);
        }else{
            if(pills==0) return false;
            auto it = works.lower_bound(t-strength);
            if(it==works.end()) return false;
            --pills;
            if( -- works[it->first]==0) works.erase(it->first);
        }
    }
    return true;
}
