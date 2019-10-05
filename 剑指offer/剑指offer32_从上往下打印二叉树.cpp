/*
从上往下打印二叉树
*/
#include<iostream>
#include<vector>
#include<string>
#include<deque>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
        std::deque<TreeNode*> tree_deque;
        std::vector<int> int_vec;
        if(!root)
            return int_vec;
        tree_deque.push_back(root);
        while(tree_deque.size())
        {
            int_vec.push_back(tree_deque.front()->val);
            if(tree_deque.front()->left)
                tree_deque.push_back(tree_deque.front()->left);
            if(tree_deque.front()->right)
                tree_deque.push_back(tree_deque.front()->right);
            tree_deque.pop_front();
        }
        return int_vec;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    return 0;
}
