/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (71.12%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    26K
 * Total Submissions: 36.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        std::vector<int> vecList;
        ListNode *top(head);
        while (top)
        {
            vecList.push_back(top->val);
            top = top->next;
        }
        return Iter(vecList, 0, vecList.size() - 1);
    }
    TreeNode *Iter(std::vector<int> &_VecList, int begin, int end)
    {
        if (end - begin < 0)
            return NULL;
        if (end - begin == 0)
        {
            TreeNode *top = new TreeNode(_VecList[begin]);
            return top;
        }
        int middle = (begin + end) >> 1;
        TreeNode *top = new TreeNode(_VecList[middle]);
        top->left = Iter(_VecList, begin, middle - 1);
        top->right = Iter(_VecList, middle + 1, end);
        return top;
    }
};
// @lc code=end
