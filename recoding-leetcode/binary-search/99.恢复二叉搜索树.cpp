/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (55.94%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 27.4K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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
#include <string>
#include <vector>
#include <queue>
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution
{
public:
    void recoverTree(TreeNode* root) {
        mTreeList = {};
        middleOrder(root);
        //auto printValue = [](TreeNode* &_Node){std::cout << _Node->val << " ";};
        //auto printValue = ()[int &_Value]{std::cout << _Value << " "};
        //std::cout << "print for each: " << std::endl; 
        //std::for_each(mTreeList.begin(), mTreeList.end(), printValue);
        //std::cout << std::endl;
        for (int i = 0; i < mTreeList.size() - 1; i++) {
            if (mTreeList[i]->val > mTreeList[i + 1]->val) {
                std::swap(mTreeList[i]->val, mTreeList[i + 1]->val);
                break;
            }
        } 
        return;
    }
    void middleOrder(TreeNode* root) {
        if (!root) return;
        if (root->left) middleOrder(root->left);
        mTreeList.push_back(root);
        if (root->right) middleOrder(root->right);
    }
    std::vector<TreeNode *> mTreeList;
};
/*
void PrintBST(TreeNode* &_Top) {
    if (!_Top) return;
    std::queue<TreeNode *> treeQueue;
    treeQueue.push(_Top);
    treeQueue.push(NULL);
    while (treeQueue.size()) {
        if (treeQueue.size() == 1 && treeQueue.front() == NULL) {
            std::cout << std::endl; 
            return;
        };
        if (treeQueue.front() == NULL) {
            treeQueue.push(NULL);
            treeQueue.pop();
            std::cout << std::endl;
            continue;
        }
        std::cout << treeQueue.front()->val << " ";
        if (treeQueue.front()->left) treeQueue.push(treeQueue.front()->left);
        if (treeQueue.front()->right) treeQueue.push(treeQueue.front()->right);
        treeQueue.pop();
    }
}

int main(int argc, char** argv) {
    TreeNode* top = new TreeNode(1);
    top->left = new TreeNode(3);
    top->right = new TreeNode(2);
    std::cout << "print BST" << std::endl; 
    PrintBST(top);
    std::cout << std::endl; 
    Solution().recoverTree(top);
    std::cout << "print BST" << std::endl;
    PrintBST(top);
    std::cout << std::endl;
    return 0;
}
*/
// @lc code=end

