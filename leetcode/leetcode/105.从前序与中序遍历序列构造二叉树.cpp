/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <algorithm>

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, 
                        std::vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        return rebuildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* rebuildTree(std::vector<int> &_Pre, int _PreFront, 
                          int _PreBack, std::vector<int> &_In, 
                          int _InFront, int _InBack) {
        if (_PreFront > _PreBack) return NULL;
        TreeNode* node = new TreeNode(_Pre[_PreFront]);
        int tmpMiddle = _InFront;
        while (_In[tmpMiddle] != _Pre[_PreFront]) tmpMiddle++;
        node->left = rebuildTree(_Pre, _PreFront + 1, _PreFront + tmpMiddle - _InFront, _In, _InFront, tmpMiddle - 1);
        node->right = rebuildTree(_Pre, _PreFront + tmpMiddle - _InFront + 1, _PreBack, _In, tmpMiddle + 1, _InBack);
        return node;
    }
};
/*
void printNode(const TreeNode* &_Top) {
    if (!_Top) return;
    std::vector<TreeNode> nodeList;
    nodeList.push_back(_Top);
    nodeList.push_back(NULL);
    std::cout << _Top -> val << std::endl; 
    while (nodeList.size()) {
        if (nodeList.size() == 1 && nodeList[0] == NULL) {
            std::cout << std::endl; 
            break;
        }
        if (nodeList[0]) {
            if (nodeList[0]->left) {
                nodeList.push_back(nodeList[0]->left);
                std::cout << nodeList[0]->left->val << " ";
            }
            if (nodeList[0]->right) {
                nodeList.push_back(nodeList[0]->right);
                std::cout << nodeList[0]->right->val << " ";
            }
        } else {
            nodeList.push_back(NULL);
        }
        nodeList.erase(nodeList.begin());
    }
}

int main()
{
    std::vector<int> preOrder = {3,9,20,15,7};
    std::vector<int> inOrder = {9,3,15,20,7};
    TreeNode* node = Solution().buildTree(preorder, inOrder);
    printNode(node);
    return 0;
}
*/
// @lc code=end

