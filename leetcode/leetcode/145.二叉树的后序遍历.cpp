/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.72%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    72.3K
 * Total Submissions: 101.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
/*
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution
{
public:
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        if (!root) return res;
        std::stack<TreeNode *> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode *top = treeStack.top();
            treeStack.pop();
            if (top != nullptr) {
                treeStack.push(top);
                treeStack.push(nullptr);
                if (top->right) treeStack.push(top->right);
                if (top->left) treeStack.push(top->left);
            } else {
                res.push_back(treeStack.top()->val);
                treeStack.pop();
            }
        }
        return res;
    }
};
/*
int main() {
    TreeNode* top = new TreeNode(4);
    top->left = new TreeNode(2);
    top->left->left = new TreeNode(1);
    top->left->right = new TreeNode(3);
    top->right = new TreeNode(6);
    top->right->left = new TreeNode(5);
    top->right->right = new TreeNode(7);

    std::vector<int> res = Solution().postorderTraversal(top);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl; 
    return 0;
}
*/
// @lc code=end
