/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false; 
        int tmpSum = 0;
        return PathSum(root, sum, tmpSum);
    }
    bool PathSum(TreeNode* root, int sum, int tmpSum) {
        if (!root) return false;
        if (IsLeef(root) && sum == tmpSum + root->val) return true;
        if (root->left) PathSum(root->left, sum, tmpSum + root->val);
        if (root->right) PathSum(root->right, sum, tmpSum + root->val);
        return false;
    }
    bool IsLeef(TreeNode* leef) {
        if (leef && !leef->left && !leef->right) return true;
        else return false;
    }
};
// @lc code=end

