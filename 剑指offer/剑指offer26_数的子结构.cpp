/*
输入两个数，判断b树是不是a树的子树
约定：空树不是任何一个树的子结构
*/

#include<iostream>
#include<vector>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution 
{
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result=false;
        if(pRoot1 && pRoot2)//一开始这个树里面不是空的
        {
            if(pRoot1->val==pRoot2->val)
            {
                result=substree(pRoot1,pRoot2);//判断a数里面有没有b数的子树
            }
            if(!result)
                result=HasSubtree(pRoot1->left,pRoot2);//在树的左树里面查找
            if(!result)
                result=HasSubtree(pRoot1->right,pRoot2);//在数的右树里面查找
        }
        return result;
    }
    bool substree(TreeNode* pRoot1,TreeNode*pRoot2)
    {
        if(!pRoot2)
            return true;
        if(!pRoot1)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;
        
        return substree(pRoot1->left,pRoot2->left) && substree(pRoot1->right,pRoot2->right);
    }
};