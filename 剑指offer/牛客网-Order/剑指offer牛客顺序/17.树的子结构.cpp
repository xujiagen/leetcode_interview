/*
输入两个二叉树a,b，判断b是不是a的子结构，这里设定空树不是任意一个树的子结构
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
class Solution 
{
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool flag=false;
        if(!pRoot1 || !pRoot2) return false;
        if(pRoot1->val == pRoot2->val) flag=find_subtree(pRoot1,pRoot2);
        if(!flag) flag=HasSubtree(pRoot1->left,pRoot2);
        if(!flag) flag=HasSubtree(pRoot1->right,pRoot2);
        return flag;
    }
    bool find_subtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(!pRoot2) return true;
        if(!pRoot1) return false;
        if(pRoot1->val!=pRoot2->val) return false;
        return find_subtree(pRoot1->left,pRoot2->left) && find_subtree(pRoot1->right,pRoot2->right);
    }
};
*/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

/*
class Solution
{
public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot2)
            return false;
        return SubTreeCheck(pRoot1, pRoot2);
        //return HasSubtree(pRoot1->left, pRoot2->left) || HasSubtree(pRoot1->right, pRoot2->right);
    }
    bool SubTreeCheck(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1)
            return false;
        return IsSubTree(pRoot1, pRoot2);
    }
    bool IsSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1 && pRoot2)
            return false;
        if (!pRoot2)
            return true;
        if (pRoot1->val == pRoot2->val)
            return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
    }
};
*/

class Solution
{
public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot2 || !pRoot1)
            return false;
        bool flag = false;
        if (pRoot1->val == pRoot2->val)
            flag = IsSubTree(pRoot1, pRoot2);
        if (!flag)
            flag = HasSubtree(pRoot1->left, pRoot2);
        if (!flag)
            flag = HasSubtree(pRoot1->right, pRoot2);
        return flag;
    }
    bool IsSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1 && pRoot2)
            return false;
        if (!pRoot2)
            return true;
        if (pRoot1->val == pRoot2->val)
            return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
        else
            return false;
    }
};

int main()
{
    TreeNode *top = new TreeNode(8);
    top->left = new TreeNode(8);
    top->right = new TreeNode(7);
    top->left->left = new TreeNode(9);
    top->left->right = new TreeNode(2);
    TreeNode *second = new TreeNode(8);
    second->left = new TreeNode(9);
    second->right = new TreeNode(2);
    std::cout << Solution().HasSubtree(top, second) << std::endl;
    return 0;
}