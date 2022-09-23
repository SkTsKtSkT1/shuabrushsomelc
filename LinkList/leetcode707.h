//
// Created by lzw on 2022/9/23.
//

#ifndef ALGORITHM_LEETCODE707_H
#define ALGORITHM_LEETCODE707_H
#include "iostream"
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//_size:链表有多少个节点
//index:按照0开始的下标
//index+1=_size_index
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next= nullptr;
    }
};

class MyLinkedList {
public:
    MyLinkedList();
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    //void printLinkedList();
private:
    int _size;
    ListNode* _dummyHead;
};


#endif //ALGORITHM_LEETCODE707_H
