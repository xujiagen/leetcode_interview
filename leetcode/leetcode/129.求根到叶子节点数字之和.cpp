/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 *
 * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (62.43%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 40.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
 * 
 * 例如，从根到叶子节点路径 1->2->3 代表数字 123。
 * 
 * 计算从根到叶子节点生成的所有数字之和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * 输出: 25
 * 解释:
 * 从根到叶子节点路径 1->2 代表数字 12.
 * 从根到叶子节点路径 1->3 代表数字 13.
 * 因此，数字总和 = 12 + 13 = 25.
 * 
 * 示例 2:
 * 
 * 输入: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * 输出: 1026
 * 解释:
 * 从根到叶子节点路径 4->9->5 代表数字 495.
 * 从根到叶子节点路径 4->9->1 代表数字 491.
 * 从根到叶子节点路径 4->0 代表数字 40.
 * 因此，数字总和 = 495 + 491 + 40 = 1026.
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
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        std::vector<int> vecList;
        long long res;
        Iter(res, root, {});
        return res;
    }
    void Iter(long long &res, TreeNode *root,
              std::vector<int> _VecList)
    {
        if (IsLeef(root))
        {
            _VecList.push_back(root->val);
            res += Value(_VecList);
            return;
        }
        else
        {
            _VecList.push_back(root->val);
            if (root->left)
                Iter(res, root->left, _VecList);
            if (root->right)
                Iter(res, root->right, _VecList);
        }
    }
    bool IsLeef(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        else
            return false;
    }
    long long Value(const std::vector<int> &_VecList)
    {
        if (_VecList.size() < 1)
            return 0;
        long long tmpValue = 0;
        for (int i = 0; i < _VecList.size(); i++)
        {
            tmpValue *= 10;
            tmpValue += _VecList[i];
        }
        return tmpValue;
    }
};
// @lc code=end
