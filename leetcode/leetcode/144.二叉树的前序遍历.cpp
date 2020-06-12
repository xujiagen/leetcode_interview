/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (64.81%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    100.7K
 * Total Submissions: 153.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
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
 * 输出: [1,2,3]
 * 
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

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
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
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::stack<TreeNode *> treeStack;
        std::vector<int> vecList;
        TreeNode *cur = root;
        while (cur || treeStack.size())
        {
            while (cur)
            {
                vecList.push_back(cur->val);
                treeStack.push(cur);
                cur = cur->left;
            }
            //vecList.push_back(treeStack.top()->val);
            cur = treeStack.top()->right;
            treeStack.pop();
        }
        return vecList;
    }
};
/*
int main(int argc, char **argv)
{
    TreeNode *top = new TreeNode(1);
    top->right = new TreeNode(2);
    top->right->left = new TreeNode(3);
    std::vector<int> vec = Solution().preorderTraversal(top);
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    return 0;
}
*/
// @lc code=end
