#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        if (!pRoot->left && pRoot->right)
            return false;
        if (!pRoot->right && pRoot->left)
            return false;
        if (!pRoot->left && !pRoot->right)
            return true;
        return CheckSymmetrical(pRoot->left, pRoot->right);
    }
    bool CheckSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 && !pRoot2)
            return false;
        if (!pRoot1 && pRoot2)
            return false;
        if (!pRoot1 && !pRoot2)
            return true;
        if (pRoot1->val == pRoot2->val)
            return CheckSymmetrical(pRoot1->left, pRoot2->right) && CheckSymmetrical(pRoot1->right, pRoot2->left);
        else
            return false;
    }
};