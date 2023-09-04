//
// Created by 25467 on 2023/9/4.
//

#include "leetcode449.h"

std::string leetcode449::serialize(TreeNode *root) {
    std::vector<int> vals;
    preOrder(root, vals);
    return vec2str(vals);
}

TreeNode *leetcode449::deserialize(std::string data) {
    if(data.empty()) return nullptr;
    std::vector<int> vals = str2vec(data);
    TreeNode* root = new TreeNode(vals[0]);
    std::vector<int> left;
    std::vector<int> right;
    for(int val : vals){
        if(val < vals[0]){
            left.push_back(val);
        }else if(val > vals[0]){
            right.push_back(val);
        }
    }
    root->left = deserialize(vec2str(left));
    root->right = deserialize(vec2str(right));
    return root;

}

void leetcode449::preOrder(TreeNode *root, std::vector<int>& res) {
    if(root == nullptr) return;
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

std::string leetcode449::vec2str(std::vector<int> &vals) {
    std::string res;
    if(vals.empty()){
        return res;
    }
    for(int i = 0; i < vals.size(); ++i){
        res += std::to_string(vals[i]) + ",";
    }
    res.pop_back();
    return res;
}

std::vector<int> leetcode449::str2vec(std::string &str) {
    std::vector<int> res;
    size_t pos = 0;
    std::string token;
    while((pos = str.find(',')) != std::string::npos){
        token = str.substr(0, pos);
        res.push_back(std::stoi(token));
        str.erase(0, pos + 1);
    }
    res.push_back(stoi(str));
    return res;
}
