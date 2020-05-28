/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (29.53%)
 * Likes:    519
 * Dislikes: 0
 * Total Accepted:    97K
 * Total Submissions: 323.6K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
 * 
 * 
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
#include <algorithm>
#include <vector>

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        std::vector<int> treeList;
        Iter(treeList, root);
        for (int i = 0; i < treeList.size() - 1; i++)
        {
            if (treeList[i] >= treeList[i + 1])
                return false;
        }
        return true;
    }
    void Iter(std::vector<int> &_TreeList, TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            Iter(_TreeList, root->left);
        _TreeList.push_back(root->val);
        if (root->right)
            Iter(_TreeList, root->right);
    }
};
// @lc code=end
