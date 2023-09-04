//
// Created by 25467 on 2023/9/4.
//

#ifndef ALGORITHM_LEETCODE449_H
#define ALGORITHM_LEETCODE449_H

#include "../TreeNode.h"
#include <string>
#include <vector>
class leetcode449 {
public:
    void preOrder(TreeNode* root, std::vector<int>& res);
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data);

    std::string vec2str(std::vector<int>& vals);
    std::vector<int> str2vec(std::string& str);

};


#endif //ALGORITHM_LEETCODE449_H
