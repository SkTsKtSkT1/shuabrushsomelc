#include <iostream>
#include "LinkList/leetcode707.h"


int main() {
    MyLinkedList* myLinkedList=new MyLinkedList();
    myLinkedList->printLinkedList();
    myLinkedList->addAtIndex(0,10);
    myLinkedList->printLinkedList();
    myLinkedList->addAtIndex(0,20);
    myLinkedList->printLinkedList();
    myLinkedList->addAtIndex(1,30);
    myLinkedList->printLinkedList();
    std::cout<<myLinkedList->get(0)<<std::endl;
    myLinkedList->printLinkedList();
    return 0;


}

