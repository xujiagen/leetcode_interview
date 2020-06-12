#include <algorithm>
#include <iostream>
#include <vector>

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
    int TreeDepth(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        maxDepth = 0;
        TreeDepthCount(pRoot, 0);
        return maxDepth;
    }

private:
    void TreeDepthCount(TreeNode *pRoot, int depth)
    {
        if (maxDepth < depth + 1)
            maxDepth = depth + 1;
        if (pRoot->left)
            TreeDepthCount(pRoot->left, depth + 1);
        if (pRoot->right)
            TreeDepthCount(pRoot->right, depth + 1);
        return;
    }
    bool IsLeaf(TreeNode *pRoot)
    {
        if (pRoot->left || pRoot->right)
            return true;
        else
            return false;
    }
    int maxDepth;
};

int main()
{
    TreeNode *top = new TreeNode(0);
    top->left = new TreeNode(1);
    top->left->left = new TreeNode(2);
    std::cout << Solution().TreeDepth(NULL) << std::endl;
    return 0;
}