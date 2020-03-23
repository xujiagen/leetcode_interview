#include<iostream>
#include<vector>

using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {
	}
};


/*
二叉树本身有两个节点，左子节点和右子节点
左子节点指向前一个位置，右子节点指向下一个位置

首先中序遍历会按照从小到大的顺序将链表进行排列
现在就是在中序排列的过程中改变各个指针指向的位置
*/
class Solution 
{
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* nodeinit=NULL;
		convert_node(pRootOfTree,&nodeinit);

		TreeNode* head=nodeinit;
		while(head!=NULL && head->left!=NULL)
			head=head->left;
		return head;
    }

	void convert_node(TreeNode* node,TreeNode** nodeinit)
	{
		if(node==NULL)
			return;//当输入的根节点空的时候，将程序的控制权返回给上一层程序
		TreeNode *current_node=node;//创建一个指针等于创建的根节点的指针
		if(current_node->left!=NULL)//判断根节点的左子节点是不是空的
			convert_node(current_node->left,nodeinit);//如果根节点的左子节点不是空的，程序递归进入下一层
		current_node->left=*nodeinit;//将当前指针的做指针指向一个kongjiedian
		if(*nodeinit!=NULL)
			(*nodeinit)->right=current_node;
		
		*nodeinit=current_node;//

		if(current_node->right!=NULL)
			convert_node(current_node->right,nodeinit);
	}
};

//中序遍历保证先找小的值再找大的值

int main()
{
	Solution a;
	TreeNode* top=new TreeNode(10);
	TreeNode* head=top;
	head->left=new TreeNode(6);
	head->right=new TreeNode(14);
	head=head->left;
	head->left=new TreeNode(4);
	head->right=new TreeNode(8);
	head=top;
	head=head->right;
	head->left=new TreeNode(12);
	head->right=new TreeNode(16);
	head=top;
	a.Convert(head);
	return 0;
}