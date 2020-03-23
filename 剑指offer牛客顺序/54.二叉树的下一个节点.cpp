#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

/*
class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode)
            return NULL;
        if (pNode->right) {
            TreeLinkNode *copyNode(pNode->right);
            while (copyNode->left) {
                copyNode = copyNode->left;
            }
            return copyNode;
        }
        copyNode = pNode;
        while (copyNode->next)
        {
            if (copyNode->next->left == pNode)
                return pNode->next;
            
            TreeLinkNode *copyNode(pNode->next->left);
            while (copyNode) {
                copyNode = copyNode->right;
            }
        }
    }
};
*/

class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        TreeLinkNode *top(pNode);
        while (top->next)
        {
            top = top->next;
        }
        std::vector<TreeLinkNode *> treeList;
        middleList(top, treeList);
        for (int i = 0; i < treeList.size(); i++)
        {
            if (pNode == treeList[i])
            {
                if (i == treeList.size() - 1)
                    return NULL;
                else
                    return treeList[i + 1];
            }
        }
        return NULL;
    }
    void middleList(TreeLinkNode *pNode, std::vector<TreeLinkNode *> &_LinkList)
    {
        if (!pNode)
            return;
        middleList(pNode->left, _LinkList);
        _LinkList.push_back(pNode);
        middleList(pNode->right, _LinkList);
    }
};

int main()
{
    return 0;
}