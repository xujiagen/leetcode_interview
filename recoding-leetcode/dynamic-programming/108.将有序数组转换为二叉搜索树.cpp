/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
#include <unordered_map>
#include <unordered_set>
#include <queue>
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printBST(TreeNode* &_Top) {
    std::queue<TreeNode *> treeQueue;
    treeQueue.push(_Top);
    treeQueue.push(NULL);
    while (treeQueue.size()) {
        if (treeQueue.size() == 1 && treeQueue.front() == NULL) return;
        if (treeQueue.front() == NULL) {
            treeQueue.pop();
            std::cout << std::endl; 
            continue;
        }
        if (treeQueue.front()->left) treeQueue.push(treeQueue.front()->left);
        if (treeQueue.front()->right) treeQueue.push(treeQueue.front()->right);
        std::cout << treeQueue.front()->val << " ";
        treeQueue.pop();
    }
}
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1, middle = (left + right) >> 1;
        return treeListToBST(nums, 0, nums.size()-1);
    }
    TreeNode* treeListToBST(std::vector<int> &_Nums, int _Left, int _Right) {
        if (_Left > _Right) return NULL;
        int middle = (_Left + _Right) >> 1;
        TreeNode* top = new TreeNode(_Nums[middle]);
        top->left = treeListToBST(_Nums, _Left, middle - 1);
        top->right = treeListToBST(_Nums, middle + 1, _Right);
        return top;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> vecList = {-10, -3, 0, 5, 9};
    TreeNode* top = Solution().sortedArrayToBST(vecList);
    printBST(top);
    return 0;
}
*/
// @lc code=end

