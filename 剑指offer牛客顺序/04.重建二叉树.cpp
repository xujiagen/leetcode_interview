/*
输入一个二叉树的前序遍历和中序遍历，重建该二叉树
首先这一段代码不是很难，但是后面写了一点广度有优先便利
*/


/*
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
    {
        if(pre.size()!=vin.size() && pre.size()<1) return NULL;//如果输入和输出之间的数组的长度都是不一样的
        std::cout<<"pre.size:"<<pre.size()-1<<"　"<<"vin.size():"<<vin.size()-1<<std::endl; 
        return construct_tree(pre,vin,0,pre.size()-1,0,vin.size()-1);
    }
    TreeNode* construct_tree(vector<int> pre,vector<int> vin,int pre_front,int pre_end,int vin_front,int vin_end)
    {
        //std::cout<<1<<std::endl;
        TreeNode* root=new TreeNode(pre[pre_front]);
        if(pre_front==pre_end && vin_front==vin_end && pre[pre_front]==vin[vin_front]) return root;
        else if(pre_front==pre_end) return NULL;

        //std::cout<<1<<std::endl;

        int root_pose=vin_front;
        while(pre[pre_front]!=vin[root_pose] && root_pose<=vin_end) root_pose++;
        if(pre[pre_front]!=vin[root_pose] && root_pose==vin_end) return NULL;
        //上面是显示如果找不到想要的节点，那说明前序遍历和中序遍历的顺序对不上，那返回值就是null

        int size_left=root_pose-vin_front;
        int size_right=vin_end-root_pose;//这个在找到节点位置中序遍历两边的数据量
        //std::cout<<"size_left:"<<size_left<<" "<<"size_right:"<<size_right<<std::endl;
        std::cout<<"root value:"<<root->val<<std::endl;

        if(size_left>0) root->left=construct_tree(pre,vin,pre_front+1,pre_front+size_left,root_pose-size_left,root_pose-1);
        if(size_right>0) root->right=construct_tree(pre,vin,pre_front+size_left+1,pre_end,root_pose+1,vin_end);
        return root;
    }
};

template <class T>
void vector_point(std::vector<T> temp,std::string str)
{
    std::cout<<str<<std::endl;
    for(int i=0;i<temp.size();i++)
        std::cout<<temp[i]<<" ";
    std::cout<<std::endl;
}

void vec_print(std::vector<int> vec_int,std::string str)
{
    std::cout<<str<<std::endl;
    for(int i=0;i<vec_int.size();i++)
        std::cout<<vec_int[i]<<" ";
    std::cout<<std::endl;
}

//显示一个树各层的数据
void print_tree(TreeNode* root)
{
    std::queue<TreeNode*> queue_node;//表示这个队列里面存储是都是指向树的指针
    if(root==NULL) return;
    queue_node.push(root);//
    queue_node.push(NULL);
    std::vector<TreeNode*> vec_node;

    while(queue_node.size())
    {
        if(queue_node.front()==NULL && queue_node.size()==1)
        {
            queue_node.pop();
            continue;
        }
        else if(queue_node.front()==NULL)
        {
            vec_node.push_back(queue_node.front());
            queue_node.pop();
            queue_node.push(NULL);
            continue;
        }
        //上面是设置边界条件
        vec_node.push_back(queue_node.front());
        if(queue_node.front()->left!=NULL) queue_node.push(queue_node.front()->left);
        if(queue_node.front()->right!=NULL) queue_node.push(queue_node.front()->right);
        queue_node.pop();
    }

    for(int i=0;i<vec_node.size();i++)
    {
        if(vec_node[i]==NULL) std::cout<<std::endl;
        else std::cout<<vec_node[i]->val<<" ";
    }
    std::cout<<std::endl;

}

void print_tree1(TreeNode* root)
{
    std::queue<TreeNode*> queue_int;
    std::vector<TreeNode*> vector_int;
    queue_int.push(root);
    int flag;
    if(root->val) flag=1;
    while(queue_int.size() && flag)
    {
        queue_int.push(queue_int.front()->left);
        queue_int.push(queue_int.front()->right);
        if(queue_int.front()->left) flag++;
        if(queue_int.front()->right) flag++;
        if(queue_int.front()) flag--;
        vector_int.push_back(queue_int.front());
        queue_int.pop();
        std::cout<<"code run into this place!"<<std::endl;
    }

    for(int i=0;i<vector_int.size();i++) 
    {
        if(vector_int[i]) std::cout<<vector_int[i]->val<<" ";
        else std::cout<<0<<std::endl;  
    }
    std::cout<<std::endl;
}

int main()
{
    int a[]={1,2,4,5,3,5,6,8};
    int b[]={4,7,2,1,5,3,8,6};
    std::vector<int> pre(a,a+sizeof(a)/sizeof(int));
    std::vector<int> vin(b,b+sizeof(b)/sizeof(int));
    vec_print(pre,"pre");
    vec_print(vin,"vin");
    Solution a1;
    TreeNode* node;
    node=a1.reConstructBinaryTree(pre,vin);
    print_tree1(node);
    return 0;


   // return 0;
}
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution 
{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
    {
        if(pre.size()!=vin.size() && pre.size()<1) return NULL;
        return construct_tree(pre,0,pre.size()-1,vin,0,vin.size()-1);
    }
    TreeNode* construct_tree(std::vector<int> pre,int pre_front,int pre_end,std::vector<int> vin,int vin_front,int vin_end)
    {
        TreeNode* root=new TreeNode(pre[pre_front]);
        if(pre_front==pre_end && vin_front==vin_end && pre[pre_front]==vin[vin_front]) return root;
        else if((pre_front!=pre_end && vin_front==vin_end)||(pre_front==pre_end && vin_front!=vin_end)) return NULL;
        //上面是设置边界条件

        int vin_pose=vin_front;
        while(vin[vin_pose]!=pre[pre_front] && vin_pose<=vin_end) vin_pose++;
        if(vin[vin_pose]!=pre[pre_front]) return NULL;

        int size_front=vin_pose-vin_front;
        int size_end=vin_end-vin_pose;

        if(size_front>0) root->left=construct_tree(pre,pre_front+1,pre_front+size_front,vin,vin_front,vin_pose-1);
        if(size_end>0) root->right=construct_tree(pre,pre_front+size_front+1,pre_end,vin,vin_pose+1,vin_end);

        return root; 
    }
};

int main()
{
    Solution a;
    return 0;
}
