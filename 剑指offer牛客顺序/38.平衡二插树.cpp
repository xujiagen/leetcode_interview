#include <iostream>
#include <vector>
#include <algorithm>

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

class Solution
{
public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        int depth;
        return TreeWithDepth(pRoot, depth);
    }
    bool TreeWithDepth(TreeNode *pRoot, int &_Depth)
    {
        if (!pRoot)
        {
            _Depth = 0;
            return true;
        }
        int leftDepth, rightDepth;
        bool leftFlag = TreeWithDepth(pRoot->left, leftDepth);
        bool rightFlag = TreeWithDepth(pRoot->right, rightDepth);
        if (leftFlag && rightFlag)
        {
            if (leftDepth - rightDepth <= 1 && rightDepth - leftDepth <= 1)
            {
                _Depth = max(leftDepth, rightDepth) + 1;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}