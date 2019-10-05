/*
操作给定的二叉树，将其变换成源二叉树的镜像
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
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
    void Mirror(TreeNode *pRoot) 
    {
        if(!root) return;
        std::swap(root->left,root->right);
        if(root->left) Mirror(root->left);
        if(root->right) Mirror(root->right);
    }
};