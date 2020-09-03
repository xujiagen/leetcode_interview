/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <string>
//#include <limits.h>
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        //mMinDepth = std::INT_MAX;
        mMinDepth = 2147483647;
        CalcDepth(root, 1);
        return mMinDepth;
    }
    void CalcDepth(TreeNode* root, int depth) {
        if (depth > mMinDepth) return;
        if (root->left == NULL) {
            mMinDepth = std::min(mMinDepth, depth);
            return;
        } else {
            CalcDepth(root->left, depth + 1);
        }
        if (root->right == NULL) {
            mMinDepth = std::min(mMinDepth, depth);
            CalcDepth(root->right, depth + 1);
        }
    }
    int mMinDepth;
};
*/

class Solution {
    public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!left || !right) return left + right + 1;
        //上面这一行的代码的含义是,当有一个变量是0,即深度是0的时候,直接是另外一个分支的深度+root为该节点段的深度
        //到这里的含义是: 如果两个都是0,这个就是叶子节点,left = 0, right = 0, 该节点段高度就是1
        return std::min(left, right) + 1;
    }
};
/*
int main(int argc, char** argv) {
    std::cout << Solution().minDepth(r)
}
*/
// @lc code=end

