//
// Created by 25467 on 2023/9/23.
//

#ifndef ALGORITHM_LEETCODE1993_H
#define ALGORITHM_LEETCODE1993_H

#include <vector>
//https://leetcode.cn/problems/operations-on-tree/solutions/2455220/letmefly-1993shu-shang-de-cao-zuo-da-mo-1n5vz/?envType=daily-question&envId=2023-09-23
//parent[i]表示i的parent
//child[i]表示i的孩子们
//lockUser[i]表示i的上锁者（0表示未上锁）
class LockingTree {
public:
    LockingTree(std::vector<int>& parent);
    bool lock(int num, int user);
    bool unlock(int num, int user);
    bool upgrade(int num, int user);
private:
    std::vector<int> lockUser;
    std::vector<int> parent;
    std::vector<std::vector<int>> child;
    bool hasLockedParent(int num);
    bool hasLockedChildAndUnlock(int num);
};


#endif //ALGORITHM_LEETCODE1993_H
