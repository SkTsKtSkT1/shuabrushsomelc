//
// Created by 25467 on 2023/9/24.
//

#ifndef ALGORITHM_LRUCACHE_H
#define ALGORITHM_LRUCACHE_H

#include <unordered_map>
struct Node{
public:
    int key, value;
    Node* prev, *next;
    Node(int k = 0, int v = 0) : key(k), value(v){}
};


class LRUCache {
public:
    LRUCache(int capacity)
    :m_cap(capacity),
    dummy(new Node()){}
    int get(int key);
    void put(int key, int value);
private:
    Node* dummy;
    std::unordered_map<int, Node*> key_node;
    int m_cap;

    void remove(Node* x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void push_front(Node *x){
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node* get_node(int key){
        auto it = key_node.find(key);
        if(it == key_node.end()){
            return nullptr;
        }
        auto node = it->second;
        remove(node);
        push_front(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


#endif //ALGORITHM_LRUCACHE_H
