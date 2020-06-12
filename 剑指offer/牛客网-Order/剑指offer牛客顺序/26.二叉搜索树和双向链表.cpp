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
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (!pRootOfTree)
            return NULL;
        std::vector<TreeNode *> TreeList;
        MiddleSort(pRootOfTree, TreeList);
        TreeList[0]->left = NULL;
        TreeNode *head(TreeList[0]);
        for (int i = 1; i < TreeList.size(); i++)
        {
            TreeList[i]->left = TreeList[i - 1];
            TreeList[i - 1]->right = TreeList[i];
        }
        TreeList[TreeList.size() - 1]->right = NULL;
        return head;
    }
    void MiddleSort(TreeNode *pRootOfTree, std::vector<TreeNode *> &_TreeList)
    {
        if (!pRootOfTree)
            return;
        MiddleSort(pRootOfTree->left, _TreeList);
        _TreeList.push_back(pRootOfTree);
        MiddleSort(pRootOfTree->right, _TreeList);
    }
};

void print2DirList(TreeNode *&_Top)
{
    TreeNode *copyTop(_Top);
    TreeNode *copySecond = copyTop;
    while (copyTop)
    {
        std::cout << copyTop->val << " ";
        copySecond = copyTop;
        copyTop = copyTop->right;
    }
    std::cout << std::endl;
    while (copySecond)
    {
        std::cout << copySecond->val << " ";
        copySecond = copySecond->left;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    TreeNode *top = new TreeNode(6);
    top->left = new TreeNode(4);
    top->right = new TreeNode(9);
    top->left->left = new TreeNode(2);
    //top->left->right = new TreeNode(5);
    //top->right->left = new TreeNode(7);
    top->right->right = new TreeNode(11);
    TreeNode *head = Solution().Convert(top);
    print2DirList(head);
    return 0;
}