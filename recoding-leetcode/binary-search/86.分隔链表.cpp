/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (56.65%)
 * Likes:    189
 * Dislikes: 0
 * Total Accepted:    34.8K
 * Total Submissions: 60.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *first(NULL), *second(NULL);
        ListNode *top(head);
        while (top)
        {
            if (top->val < x)
            {
                first = top;
                break;
            }
            top = top->next;
        }
        if (!first)
            return head;
        top = head;
        while (top)
        {
            if (top->val >= x)
            {
                second = top;
                break;
            }
            top = top->next;
        }
        ListNode *while (top->next)
        {
            if (top->next->val < x)
            {
                second->next = top->next;
                second = second->next;
            }
            top = top->next;
        }
        top = head;
        while (top)
        {
            if (top->val >= x)
            {
                second->next = top;
                second = second->next;
            }
            top = top->next;
        }
        second->next = NULL;
        return first;
    }
};

void printList(ListNode *_Top)
{
    if (!_Top)
        return;
    ListNode *second(_Top);
    while (second)
    {
        std::cout << second->val << " ";
        second = second->next;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    ListNode *top = new ListNode(1);
    top->next = new ListNode(4);
    top->next->next = new ListNode(3);
    top->next->next->next = new ListNode(2);
    top->next->next->next->next = new ListNode(5);
    ListNode *&second(top->next->next->next->next);
    second->next = new ListNode(2);
    printList(top);
    ListNode *third = Solution().partition(top, 3);
    printList(third);
    return 0;
}
// @lc code=end
