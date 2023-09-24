//
// Created by 25467 on 2023/9/24.
//

#include "LRUCache.h"

int LRUCache::get(int key) {
    auto node = get_node(key);
    return node ? node->value : -1;
}

void LRUCache::put(int key, int value) {
    auto node = get_node(key);
    if(node){
        node->value = value;
        return;
    }
    key_node[key] = node = new Node(key, value);
    push_front(node);
    if(key_node.size() > m_cap){
        auto back_node = dummy->prev;
        key_node.erase(back_node->key);
        remove(back_node);
        delete back_node;
    }
}
