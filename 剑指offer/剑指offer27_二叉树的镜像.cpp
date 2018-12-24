/*
输入一个二叉树，输出一个二叉树的镜像
是修改原来的数
*/

#include<iostream>

using namespace std;


struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void Mirror(TreeNode *pRoot) 
    {
        if(!pRoot)
            return;//如果这个树里面的是空的，说明这个时候该返回了
        std::swap(pRoot->left,pRoot->right);//交换两个指针
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};