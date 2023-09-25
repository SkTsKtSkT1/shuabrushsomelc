//
// Created by 25467 on 2023/9/25.
//

#include "LFUCache.h"

LFUCache::LFUCache(int capacity)
    :m_cap(capacity){

}

int LFUCache::get(int key) {
    auto node = get_node(key);
    return node ? node->value : -1;
}

void LFUCache::put(int key, int value) {
    auto node = get_node(key);
    if(node){
        node->value = value;
        return;
    }
    if(key_node.size() == m_cap){
        auto dummy = freq_dummy[min_freq];
        auto back_node = dummy->prev;
        key_node.erase(back_node->key);
        remove(back_node);
        delete back_node;
        if(dummy->prev == dummy){
            freq_dummy.erase(min_freq);
            delete dummy;
        }
    }
    key_node[key] = node = new Node(key, value);
    push_front(1, node);
    min_freq = 1;
}
