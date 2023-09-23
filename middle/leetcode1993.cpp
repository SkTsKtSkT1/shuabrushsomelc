//
// Created by 25467 on 2023/9/23.
//

#include "leetcode1993.h"

LockingTree::LockingTree(std::vector<int> &parent)
    :parent(parent){
    lockUser = std::vector<int>(parent.size());
    child = std::vector<std::vector<int>>(parent.size());
    for (int i = 1; i < parent.size(); i++) {
        child[parent[i]].push_back(i);
    }
}

bool LockingTree::lock(int num, int user) {
    if (lockUser[num]) {
        return false;
    }
    lockUser[num] = user;
    return true;

}

bool LockingTree::unlock(int num, int user) {
   if(lockUser[num] == user){
       lockUser[num] = 0;
       return true;
   }
   return false;
}

bool LockingTree::upgrade(int num, int user) {
    if(!lockUser[num] && !hasLockedParent(num) && hasLockedChildAndUnlock(num)){
        lockUser[num] = user;
        return true;
    }
    return false;
}

bool LockingTree::hasLockedParent(int num) {
    while (parent[num] != -1) {
        num = parent[num];
        if (lockUser[num]) {
            return true;
        }
    }
    return false;
}

bool LockingTree::hasLockedChildAndUnlock(int num) {
    bool hasLockedChild = false;
    if (lockUser[num]) {
        lockUser[num] = 0;
        hasLockedChild = true;
    }
    for (int thisChild : child[num]) {
        hasLockedChild |= hasLockedChildAndUnlock(thisChild);
    }
    return hasLockedChild;

}
