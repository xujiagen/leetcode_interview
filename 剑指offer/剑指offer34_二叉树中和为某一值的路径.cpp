/*
二叉树中和为某一值的所有路径
第二次编写的代码好像编译以及通过了，结果也没有什么问题，但是显示递归层数太多
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
};

/*
class Solution 
{
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
        //首先判断这个输入进来的节点是不是叶子节点
        std::vector<std::vector<int> > path_sum;
        if(!root)
            return path_sum;
        std::vector<int> path_one;
        int currentsum=0;
        findpath(root,expectNumber,currentsum,path_sum,path_one);
        return path_sum;
            
    }
    void findpath(TreeNode* root,int expectNumber,int currentsum,std::vector<std::vector<int> >& path_sum,std::vector<int> path_one)
    {
        currentsum+=root->val;
        path_one.push_back(root->val);

        bool isleaf=!root->left && !root->right;//判断这个节点是不是叶子节点
        if(isleaf && currentsum==expectNumber)
        {
            path_sum.push_back(path_one);
            return;
        }
        if(currentsum>expectNumber)
            return;

        if(root->left)
            findpath(root->left,expectNumber,currentsum,path_sum,path_one);
        if(root->right)
            findpath(root->right,expectNumber,currentsum,path_sum,path_one);
    }
};
*/

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
        TreeNode* top=root;
        std::vector<int> vec_int;
        std::vector<std::vector<int> > vec_vec_int;
        path(root,expectNumber,vec_int,vec_vec_int);
        return vec_vec_int;
    }
    
    void path(TreeNode* root,int target,std::vector<int> vec_int,std::vector<std::vector<int> > &vec_vec_int)
    {
        vec_int.push_back(root->val);
        std::cout<<"into::"<<root->val<<std::endl;
        if(isleaf(root))
        {
            int sum=sum_number(vec_int);
            std::cout<<"sum"<<sum<<"size:"<<vec_int.size()<<std::endl;
            if(sum==target)
            {
                vec_vec_int.push_back(vec_int);
                return;
            }
            else
                return;
        }
        if(root->left)
            path(root->left,target,vec_int,vec_vec_int);
        if(root->right)
            path(root->right,target,vec_int,vec_vec_int);
    }
    
    bool isleaf(TreeNode* root)
    {
        return root->left==NULL && root->right==NULL;
    }

    int sum_number(std::vector<int>& vec_int)
    {
        int num=0;
        for(std::vector<int>::iterator iter=vec_int.begin();iter!=vec_int.end();iter++)
        {
            num+=*iter;
        }
        return num;
    }
};

int main()
{
    TreeNode* root=new TreeNode(10);
    TreeNode* point=root;
    point->left=new TreeNode(5);
    point->right=new TreeNode(12);
    point=point->left;
    point->left=new TreeNode(4);
    point->right=new TreeNode(7);
    Solution a;
    std::vector<std::vector<int> > temp=a.FindPath(root,22);
    for(int i=0;i<temp.size();i++)
    {
        for(int j=0;j<temp[i].size();j++)
            std::cout<<temp[i][j]<<"\t";
        std::cout<<std::endl;
    }
    return 0;
}

