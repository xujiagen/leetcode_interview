/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.74%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    34K
 * Total Submissions: 85.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
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
#include <climits>
#include <iostream>
#include <vector>
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
    int maxPathSum(TreeNode *root)
    {
        maxPath = root->val;
        IterPath(root);
        return maxPath;
    }
    int IterPath(TreeNode *&_Toot)
    {
        if (!_Toot)
            return INT8_MIN;
        int left = IterPath(_Toot->left);
        int right = IterPath(_Toot->right);
        if (left + _Toot->val > maxPath)
            maxPath = left + _Toot->val;
        if (right + _Toot->val > maxPath)
            maxPath = right + _Toot->val;
        if (left + right + _Toot->val > maxPath)
            maxPath = left + right + _Toot->val;
        if (_Toot->val > maxPath)
            maxPath = _Toot->val;
        return std::max(left + _Toot->val, std::max(right + _Toot->val, _Toot->val));
    }
    int maxPath;
};
/*
int main(int argc, char **argv)
{
    TreeNode *top = new TreeNode(-10);
    top->left = new TreeNode(9);
    top->right = new TreeNode(20);
    top->right->right = new TreeNode(7);
    top->right->left = new TreeNode(15);

    std::cout << Solution().maxPathSum(top) << std::endl;
    return 0;
}
*/
// @lc code=end
