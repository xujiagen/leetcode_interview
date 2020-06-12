/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.72%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    148.9K
 * Total Submissions: 209K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
#include <string>
#include <stack>
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
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> treeList;
        std::stack<TreeNode *> treeStack;
        TreeNode *cur = root;
        while (cur || treeStack.size())
        {
            while (cur)
            {
                treeStack.push(cur);
                cur = cur->left;
                //treeList.push_back(cur->val);
                //cur = cur->left;
            }
            cur = treeStack.top();
            treeStack.pop();
            treeList.push_back(cur->val);
            cur = cur->right;
        }
        return treeList;
    }
};
/*
int main(int argc, char **argv)
{
    TreeNode *top = new TreeNode(1);
    top->right = new TreeNode(2);
    top->right->right = new TreeNode(3);
    auto list = Solution().inorderTraversal(top);
    return 0;
}
*/
// @lc code=end
