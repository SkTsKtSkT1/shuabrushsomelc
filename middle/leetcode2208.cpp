//
// Created by 25467 on 2023/7/25.
//

#include "leetcode2208.h"
#include "queue"
#include "numeric"
#include "functional"
//https://blog.csdn.net/AAMahone/article/details/82787184
int leetcode2208::halveArray(std::vector<int> &nums) {
    //默认大根堆, 第三个参数 less<int>,优先队列队首指向最后，队尾指向最前面的缘故,所以less表示队尾小于队首，也就是大根堆
    std::priority_queue<float, std::vector<float>, std::less<>> pq;
    double preSum = std::accumulate(nums.begin(), nums.end(), 0.0);
    double subSum = 0;
    for(int& n : nums){
        pq.push(n * 1.0);
    }
    int cnt = 0;

    while(2 * subSum < preSum){
        subSum += (pq.top() / 2);
        pq.push(pq.top() / 2);
        pq.pop();
        cnt++;
    }

    return cnt;
}
