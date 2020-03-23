/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// test part
/*
#include <iostream>

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
        ListNode l3(0);
        ListNode *l3Copy = &l3;
        while (addUp || l1 || l2)
        {
            int tmp = addUp + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l3Copy->next = new ListNode(tmp % 10);
            l3Copy = l3Copy->next;
            addUp = tmp / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return l3.next;
    }
};
// @lc code=end
