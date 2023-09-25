//
// Created by 25467 on 2023/9/25.
//

#ifndef ALGORITHM_LFUCACHE_H
#define ALGORITHM_LFUCACHE_H

#include <unordered_map>

struct Node{
public:
    int key, value;
    int freq = 1;
    Node* prev, *next;
    Node(int k = 0, int v = 0) : key(k), value(v){}
};

class LFUCache {
public:
    LFUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    int min_freq;
    int m_cap;
    std::unordered_map<int, Node*> freq_dummy;
    std::unordered_map<int, Node*> key_node;
    Node* new_list(){
        auto dummy = new Node();
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }

    void push_front(int freq, Node* x){
        auto it = freq_dummy.find(freq);
        if(it == freq_dummy.end()){
            it = freq_dummy.emplace(freq, new_list()).first;
        }
        auto dummy = it->second;
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    void remove(Node* x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    Node* get_node(int key){
        auto it = key_node.find(key);
        if(it == key_node.end()){
            return nullptr;
        }
        auto node = it->second;
        remove(node);
        auto dummy = freq_dummy[node->freq];
        if(dummy->prev == dummy){
            freq_dummy.erase(node->freq);
            delete dummy;
            if(min_freq == node->freq){
                min_freq++;
            }
        }
        push_front(++node->freq, node);
        return node;
    }
};


#endif //ALGORITHM_LFUCACHE_H
