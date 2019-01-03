/*
输入一个二叉树，判断这个二叉树的深度
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
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        return (left>right)?(left+1):(right+1);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
