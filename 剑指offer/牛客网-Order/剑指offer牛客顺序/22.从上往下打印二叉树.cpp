/*
从上往下打印二叉树，同层节点从左往右打印
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        std::vector<int> vec_int;
        if(!root) return vec_int;
        TreeNode* tree=root;
        while(tree)
        {
            vec_int.push_back(tree->val);
            if(tree->left) queue_treenode.push(tree->left);
            if(tree->right) queue_treenode.push(tree->right);
            if(queue_treenode.size())
            {
                tree=queue_treenode.front();
                queue_treenode.pop();
            }
            else
                break;
        }
        return vec_int;
    }
    std::queue<TreeNode*> queue_treenode;
};
*/
class Solution
{
public:
    std::vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        std::vector<int> vecInt;
        if (!root)
            return vecInt;
        std::queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        while (treeQueue.size())
        {
            vecInt.push_back(treeQueue.front()->val);
            if (treeQueue.front()->left)
                treeQueue.push(treeQueue.front()->left);
            if (treeQueue.front()->right)
                treeQueue.push(treeQueue.front()->right);
            treeQueue.pop();
        }
        return vecInt;
    }
};

int main()
{

    return 0;
}