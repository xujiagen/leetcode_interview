/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.46%)
 * Likes:    3825
 * Dislikes: 0
 * Total Accepted:    311.3K
 * Total Submissions: 853.7K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
#include <algorithm>
#include <iostream>
#include <vector>
/*
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        int addUp = 0;
        ListNode *first(l1), *second(l2);
        ListNode *top = new ListNode(0);
        ListNode *copy(top);
        while (first || second || addUp)
        {
            int tmpValue = (first ? first->val : 0) + (second ? second->val : 0) + addUp;
            copy->next = new ListNode(tmpValue % 10);
            copy = copy->next;
            addUp = tmpValue / 10;
            if (first)
                first = first->next;
            if (second)
                second = second->next;
        }
        return top->next;
    }
};
// @lc code=end
