#include <iostream>
#include <algorithm>
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

class Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        std::vector<std::vector<int>> res;
        if (!pRoot)
            return res;
        std::queue<TreeNode *> treeQueue;
        treeQueue.push(pRoot);
        treeQueue.push(NULL);
        std::vector<int> tmpLine;
        bool reverseFlag = false;
        while (treeQueue.size())
        {
            if (treeQueue.front() == NULL)
            {
                if (reverseFlag)
                    std::reverse(tmpLine.begin(), tmpLine.end());
                reverseFlag = reverseFlag ? false : true;
                res.push_back(tmpLine);
                tmpLine.clear();
                if (treeQueue.size() == 1)
                    return res;
                else
                {
                    treeQueue.pop();
                    treeQueue.push(NULL);
                }
            }
            else
            {
                tmpLine.push_back(treeQueue.front()->val);
                if (treeQueue.front()->left)
                    treeQueue.push(treeQueue.front()->left);
                if (treeQueue.front()->right)
                    treeQueue.push(treeQueue.front()->right);
                treeQueue.pop();
            }
        }
    }
};

int main()
{
    return 0;
}