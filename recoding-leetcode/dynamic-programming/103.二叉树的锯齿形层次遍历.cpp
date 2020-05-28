/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (53.99%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    45.5K
 * Total Submissions: 83.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

class Solution
{
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> res;
        if (!root)
            return res;
        std::queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        treeQueue.push(NULL);
        Iter(res, treeQueue, {});
        for (int i = 0; i < res.size(); i++)
        {
            if (i % 2 == 0)
                continue;
            std::reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    void Iter(std::vector<std::vector<int>> &_VecList,
              std::queue<TreeNode *> &_TreeQueue, std::vector<int> _Vec)
    {
        if (_TreeQueue.size() == 1 && _TreeQueue.front() == NULL)
        {
            _VecList.push_back(_Vec);
            return;
        }
        if (_TreeQueue.front() == NULL)
        {
            _TreeQueue.pop();
            _VecList.push_back(_Vec);
            _Vec.clear();
            _TreeQueue.push(NULL);
            Iter(_VecList, _TreeQueue, _Vec);
        }
        else
        {
            if (_TreeQueue.front()->left)
                _TreeQueue.push(_TreeQueue.front()->left);
            if (_TreeQueue.front()->right)
                _TreeQueue.push(_TreeQueue.front()->right);
            _Vec.push_back(_TreeQueue.front()->val);
            _TreeQueue.pop();
            Iter(_VecList, _TreeQueue, _Vec);
        }
    }
};
// @lc code=end
