/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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

/*
#include <iostream>
#include <vector>
#include <string>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        BSTList(root, middleTree);
        position =0;
    }
    void BSTList(TreeNode* root, std::vector<TreeNode*> &middleTree) {
        if (!root) return;
        if (root->left) BSTList(root->left, middleTree);
        middleTree.push_back(root);
        if (root->right) BSTList(root->right, middleTree);
    }
    
    /** @return the next smallest number */
    int next() {
        if (position < middleTree.size()) 
            return middleTree[position++]->val;
        return -1;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (position < middleTree.size()) return true;
        else return false;
    }
    std::vector<TreeNode*> middleTree;
    int position;
};
/*
int main(int argc,char* argv[]) {
    TreeNode* top = new TreeNode(7);
    top->left = new TreeNode(3);
    top->right = new TreeNode(15);
    top->right->left = new TreeNode(9);
    top->right->right = new TreeNode(20);
    
    BSTIterator* obj = new BSTIterator(nullptr);
    while (obj->hasNext()) {
        std::cout << obj->next() << std::endl;
    } 
    return 0;
}
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

