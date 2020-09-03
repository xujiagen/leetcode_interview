/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int val = box(root);
        if (val == -1) return false;
        else return true;
    }
    int box(TreeNode* root) {
        if (!root) return 0;
        int left = box(root->left);
        if (left == -1) return -1;
        int right = box(root->right);
        if (right == -1) return -1;
        return std::abs(left - right) < 2 ? std::max(left, right) + 1 : -1;
    }
};
// @lc code=end

