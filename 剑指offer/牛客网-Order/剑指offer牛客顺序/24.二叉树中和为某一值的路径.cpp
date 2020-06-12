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
    std::vector<std::vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        std::vector<std::vector<int>> result;
        if (!root)
            return result;
        std::vector<int> path;
        FindPathList(root, expectNumber, path, result);
        return result;
    }
    void FindPathList(TreeNode *root, int expectNumber, std::vector<int> _Path, std::vector<std::vector<int>> &_Res)
    {
        if (IsBeaf(root))
        {
            if (root->val == expectNumber)
            {
                _Path.push_back(root->val);
                _Res.push_back(_Path);
                return;
            }
            else
                return;
        }
        else
        {
            if (root->val > expectNumber)
                return;
            _Path.push_back(root->val);
            if (root->left)
                FindPathList(root->left, expectNumber - root->val, _Path, _Res);
            if (root->right)
                FindPathList(root->right, expectNumber - root->val, _Path, _Res);
            return;
        }
    }
    bool IsBeaf(TreeNode *&_Root)
    {
        if (!_Root->left && !_Root->right)
            return true;
        else
            return false;
    }
};

void print2DList(std::vector<std::vector<int>> &_VecList)
{
    for (int i = 0; i < _VecList.size(); i++)
    {
        for (int j = 0; j < _VecList[i].size(); j++)
            std::cout << _VecList[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(2);
    std::vector<std::vector<int>> result = Solution().FindPath(root, 9);
    print2DList(result);
    return 0;
}