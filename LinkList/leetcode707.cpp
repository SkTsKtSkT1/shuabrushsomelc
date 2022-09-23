//
// Created by lzw on 2022/9/23.
//

#include "leetcode707.h"

MyLinkedList::MyLinkedList() {
    _dummyHead=new ListNode(0);
    _size=0;
}

int MyLinkedList::get(int index) {
    if(_size-1<index||index<0){
        return -1;
    }
    ListNode* cur=_dummyHead;
    for(int i=0;i<index;i++){
        cur=cur->next;
    }
    return cur->next->val;
}

void MyLinkedList::addAtHead(int val) {
    ListNode* node=new ListNode(val);
    node->next=_dummyHead->next;
    _dummyHead->next=node;
    _size++;
    return ;
}

void MyLinkedList::addAtTail(int val) {
    ListNode* cur=_dummyHead;
    while(cur->next!= nullptr){
        cur=cur->next;
    }
    ListNode* node=new ListNode(val);
    cur->next=node;
    _size++;
    return ;
}

void MyLinkedList::addAtIndex(int index, int val) {
    if(index>_size){
        return ;
    }else if(index<0){
        addAtHead(val);
        return ;
    }else if(index==_size){
        addAtTail(val);
        return;
    }

    ListNode* cur=_dummyHead;
    for(int i=0;i<index;i++){
        cur=cur->next;
    }
    ListNode* node=new ListNode(val);
    node->next=cur->next;
    cur->next=node;
    _size++;
    return ;
}

void MyLinkedList::deleteAtIndex(int index) {
    if(index<0||index>_size-1){
        return ;
    }
    ListNode* cur=_dummyHead;
    for(int i=0;i<index;i++){
        cur=cur->next;
    }
    ListNode* node=cur->next;
    cur->next=node->next;
    delete node ;
    _size--;
    return ;

}

// 打印链表
//void MyLinkedList::printLinkedList() {
//    ListNode* cur = _dummyHead;
//    while (cur->next != nullptr) {
//        std::cout << cur->next->val << " ";
//        cur = cur->next;
//    }
//    std::cout << std::endl;
//    return ;
//}