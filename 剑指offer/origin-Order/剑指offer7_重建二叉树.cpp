/*
重建二叉树
输入某二叉树的前序遍历和中序遍历中都不含有重复的数字
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//在二叉树的前序遍历和中序遍历过程中确定根节点的位置和左子树的值，右子树节点的值

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
    {
        if(pre.size()<1 || vin.size()<1 || pre.size()!=vin.size())
            return NULL;//如果字符串的前序遍历和中序遍历不能返回一个有效的值，返回一个空指针
        return constructcore(pre,0,pre.size()-1,vin,0,vin.size()-1);
        
    }
    TreeNode* constructcore(std::vector<int>pre,int pre_left,int pre_right,std::vector<int> vin,int vin_left,int vin_right)
    {
        //首先左子树的第一个节点
        TreeNode* root=new TreeNode(pre[pre_left]);
        if(pre_left==pre_right)
        {
            if(vin_left==vin_right && pre[pre_left]==vin[vin_left])
            {
                return root;
            }
            else
            {
                return NULL;
            }
        }
        //在中序遍历里面查找根节点的位置，
        int root_pos=vin_left;
        while(pre[pre_left]!=vin[root_pos] && root_pos<=vin_right)
            root_pos++;
        if(root_pos==vin_right && vin[root_pos]!=pre[pre_left])
            return NULL;//数据有问题找不到想要的节点
        
        int size_left=root_pos-vin_left;
        int size_right=vin_right-root_pos;
        if(size_left>0)
        {
            std::cout<<"左子树"<<std::endl;
            root->left=constructcore(pre,pre_left+1,pre_left+size_left,vin,root_pos-size_left,root_pos-1);
        }
        if(size_right>0)
        {
            std::cout<<"右子树"<<std::endl;
            root->right=constructcore(pre,pre_left+size_left+1,pre_right,vin,root_pos+1,root_pos+size_right);
        }
        return root;
    }

    //前序遍历
    void pre_look(TreeNode* root)
    {
        std::cout<<root->val<<"\t";
        if(root->left)
            pre_look(root->left);
        if(root->right)
            pre_look(root->right);
    }

    void vin_look(TreeNode* root)
    {
        if(root)
        {
            vin_look(root->left);
            std::cout<<root->val<<"\t";
            vin_look(root->right);
        }
    }

    void vin_look_pre(TreeNode* root)
    {
        if(root->left)
            vin_look_pre(root->left);
        std::cout<<root->val<<"\t";
        if(root->right)
            vin_look_pre(root->right);
    }
};

int main()
{
    std::vector<int> int_left,int_right;
    int_left.push_back(1);

    int_left.push_back(2);
    int_left.push_back(4);
    int_left.push_back(7);

    int_left.push_back(3);
    int_left.push_back(5);
    int_left.push_back(6);
    int_left.push_back(8);

    int_right.push_back(4);
    int_right.push_back(7);
    int_right.push_back(2);

    int_right.push_back(1);

    int_right.push_back(5);
    int_right.push_back(3);
    int_right.push_back(8);
    int_right.push_back(6);
    Solution a;
    TreeNode* root=a.reConstructBinaryTree(int_left,int_right);
    for(int a:int_left)
        std::cout<<a<<"\t";
    std::cout<<std::endl;

    for(int a:int_right)
        std::cout<<a<<"\t";
    std::cout<<std::endl;

    a.pre_look(root);
    std::cout<<std::endl;

    a.vin_look(root);
    std::cout<<std::endl;

    a.vin_look_pre(root);
    std::cout<<std::endl;
    return 0;
}