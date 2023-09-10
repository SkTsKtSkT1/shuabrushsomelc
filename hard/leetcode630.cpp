//
// Created by skt on 2023/9/11.
//

#include "leetcode630.h"
#include <algorithm>
#include <queue>
int leetcode630::scheduleCourse(std::vector<std::vector<int>> &courses) {
    std::sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
        return c0[1] < c1[1];
    });

    std::priority_queue<int> q;
    // 优先队列中所有课程的总时间
    int total = 0;

    for (const auto& course: courses) {
        int ti = course[0], di = course[1];
        if (total + ti <= di) {
            total += ti;
            q.push(ti);
        }
        else if (!q.empty() && q.top() > ti) {
            total -= q.top() - ti;
            q.pop();
            q.push(ti);
        }
    }

    return q.size();
}
