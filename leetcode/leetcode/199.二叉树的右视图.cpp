/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        if (root == NULL) return res;
        else res.push_back(root->val);
        TreeNode* leftTree = root->left;
        TreeNode* rightTree = root->right;
        while (leftTree || rightTree) {
            if (rightTree) res.push_back(rightTree->val);
            else res.push_back(leftTree->val);
            if (rightTree) {
                if (rightTree->right) rightTree = rightTree->right;
                else rightTree = rightTree->left;
            }
            if (leftTree) {
                if (leftTree->right) leftTree = leftTree->right;
                else leftTree = leftTree->left;
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;
        std::vector<TreeNode*> level;
        level.push_back(root);
        while (level.size()) {
            std::vector<TreeNode*> tmpLevel;
            for (const auto &node : level) {
                if (node->left) tmpLevel.push_back(node->left);
                if (node->right) tmpLevel.push_back(node->right);
            }
            res.push_back(level.back()->val);
            level = tmpLevel;
        }
        return res;
    }
};
/*
int main(int argc, char** argv) {
    TreeNode* top = new TreeNode(1);
    top->right = new TreeNode(2);
    top->right->right = new TreeNode(5);
    top->right->right->left = new TreeNode(4);
    top->right->right->right = new TreeNode(6);
    top->right->right->left->left = new TreeNode(3);
    auto printValue = [](int value) {std::cout << value << " ";};
    std::vector<int> res = Solution().rightSideView(top);
    std::for_each(res.begin(), res.end(), printValue);
    std::cout << std::endl; 
    return 0;
}
*/
// @lc code=end

