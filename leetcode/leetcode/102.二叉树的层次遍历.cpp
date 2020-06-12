/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (61.28%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    111.2K
 * Total Submissions: 180.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> res;
        if (!root)
            return res;
        std::queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        treeQueue.push(NULL);
        Iter(res, treeQueue, {});
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
/*
void printList(const std::vector<std::vector<int>> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        for (int j = 0; j < _VecList[i].size(); j++)
        {
            std::cout << _VecList[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    TreeNode *top = new TreeNode(3);
    top->left = new TreeNode(9);
    top->right = new TreeNode(20);
    top->right->right = new TreeNode(7);
    top->right->left = new TreeNode(15);
    auto List = Solution().levelOrder(top);
    printList(List);
    return 0;
}
*/
// @lc code=end
