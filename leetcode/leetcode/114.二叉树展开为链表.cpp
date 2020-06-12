/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (68.10%)
 * Likes:    334
 * Dislikes: 0
 * Total Accepted:    38.6K
 * Total Submissions: 56.2K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
/*
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printList(TreeNode *top)
{
    if (!top)
        return;
    std::queue<TreeNode *> treeQueue;
    treeQueue.push(top);
    treeQueue.push(NULL);
    while (treeQueue.size())
    {
        if (treeQueue.size() == 1 & treeQueue.front() == NULL)
        {
            std::cout << std::endl;
            return;
        }
        if (treeQueue.front() == NULL)
        {
            std::cout << std::endl;
            treeQueue.push(NULL);
        }
        else
        {
            if (treeQueue.front()->left)
                treeQueue.push(treeQueue.front()->left);
            if (treeQueue.front()->right)
                treeQueue.push(treeQueue.front()->right);
            std::cout << treeQueue.front()->val << " ";
        }
        treeQueue.pop();
    }
}
*/

//技巧: 将右树替换成左树, 将右树衔接在左树的末端
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *top(root);
        while (top)
        {
            TreeNode *left(top->left);
            TreeNode *right(top->right);
            if (!left && right)
            {
                top = top->right;
                continue;
            }
            top->left = NULL;
            top->right = left;
            if (!top->right)
                return;
            while (left->right)
                left = left->right;
            left->right = right;
            top = top->right;
        }
    }
};
/*
int main(int argc, char **argv)
{
    TreeNode *top = new TreeNode(1);
    top->left = new TreeNode(2);
    top->right = new TreeNode(5);
    top->left->left = new TreeNode(3);
    top->left->right = new TreeNode(4);
    top->right->right = new TreeNode(6);
    printList(top);
    Solution().flatten(top);
    printList(top);
    return 0;
}
*/
// @lc code=end
