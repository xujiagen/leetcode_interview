/*
输入两个二叉树a,b，判断b是不是a的子结构，这里设定空树不是任意一个树的子结构
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

int main()
{
    Solution a;
    return 0;
}