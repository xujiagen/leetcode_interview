/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (58.96%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 75.6K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
/*
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution
{
public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int sum)
    {
        std::vector<std::vector<int>> res;
        if (!root)
            return res;
        TreePath(res, root, sum, {});
        return res;
    }
    void TreePath(std::vector<std::vector<int>> &_VecList, TreeNode *root,
                  int target, std::vector<int> _Vec)
    {
        if (!root)
            return;
        if (target == root->val && IsLeef(root))
        {
            _Vec.push_back(target);
            _VecList.push_back(_Vec);
            return;
        }
        else
        {
            _Vec.push_back(root->val);
            if (root->left)
                TreePath(_VecList, root->left, target - root->val, _Vec);
            if (root->right)
                TreePath(_VecList, root->right, target - root->val, _Vec);
        }
    }
    bool IsLeef(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        else
            return false;
    }
};
/*
int main(int argc, char **argv)
{
    TreeNode *top = new TreeNode(5);
    top->left = new TreeNode(4);
    top->right = new TreeNode(8);
    top->left->left = new TreeNode(11);
    top->left->left->left = new TreeNode(7);
    top->left->left->right = new TreeNode(2);
    top->right->left = new TreeNode(13);
    top->right->right = new TreeNode(4);
    top->right->right->left = new TreeNode(5);
    top->right->right->right = new TreeNode(1);
    auto vecList = Solution().pathSum(top, 22);
    return 0;
}
*/
// @lc code=end
