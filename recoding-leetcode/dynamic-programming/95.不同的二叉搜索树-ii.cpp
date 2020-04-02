/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (62.30%)
 * Likes:    325
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 39.8K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution
{
public:
    std::vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generate(1, n);
    }
    std::vector<TreeNode *> generate(int _Left, int _Right)
    {
        std::vector<TreeNode *> ans;
        if (_Left > _Right)
        {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = _Left; i <= _Right; i++)
        {
            std::vector<TreeNode *> left_nodes = generate(_Left, i - 1);
            std::vector<TreeNode *> right_nodes = generate(i + 1, _Right);
            for (TreeNode *left_node : left_nodes)
            {
                for (TreeNode *right_node : right_nodes)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = left_node;
                    node->right = right_node;
                    ans.push_back(node);
                }
            }
        }
        std::cout << "possible vecList size: " << ans.size() << std::endl;
        return ans;
    }
};
/*
void printNode(TreeNode *_Node)
{
    if (!_Node)
        return;
    else
    {
        std::vector<TreeNode *> treeList;
        treeList.push_back(_Node);
        treeList.push_back(NULL);
        while (treeList.size())
        {
            if (treeList.size() == 1 && treeList[0] == NULL)
            {
                std::cout << std::endl;
                return;
            }
            if (treeList[0] && treeList[0]->left)
                treeList.push_back(treeList[0]->left);
            if (treeList[0] && treeList[0]->right)
                treeList.push_back(treeList[0]->right);
            if (treeList[0])
                std::cout << treeList[0]->val << " ";
            treeList.erase(treeList.begin());
        }
    }
}

void printNodeList(std::vector<TreeNode *> &_VecTree)
{
    if (_VecTree.size() < 1)
        return;
    for (int i = 0; i < _VecTree.size(); i++)
        printNode(_VecTree[i]);
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<TreeNode *> vecTree = Solution().generateTrees(3);
    printNodeList(vecTree);
    return 0;
}
*/
/*
class Solution
{
public:
    std::vector<TreeNode *> generateTrees(int n)
    {
        std::vector<TreeNode *> vecTree;
        if (n == 0)
        {
            vecTree.push_back(NULL);
            return 0;
        }
        if (n == 1)
        {
            vecTree.push_back(new TreeNode(1));
            return vecTree;
        }
        std::vector<std::vector<TreeNode *>> treeList;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                std::vector<TreeNode *> tmpTree;
                tmpTree.push_back(NULL);
                treeList.push_back(tmpTree);
                continue;
            }
            if (i == 1)
            {
                std::vector<TreeNode *> tmpTree;
                tmpTree.push_back(new TreeNode(1));
                treeList.push_back(tmpTree);
                continue;
            }
            for (int j = 1; j <= i; j++)
            {
                for (int k = 0; k < )
                    TreeNode *tmpTree = new TreeNode(j);

            }
        }
    }
};
*/
// @lc code=end
