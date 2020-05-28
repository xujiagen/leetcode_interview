/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (46.86%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 92K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
#include <stack>
#include <map>
#include <unordered_map>
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *top(head);
        std::unordered_map<int, int> mapValueCount;
        while (top)
        {
            if (mapValueCount.find(top->val) != mapValueCount.end())
            {
                mapValueCount[top->val]++;
            }
            else
                mapValueCount[top->val] = 1;
            top = top->next;
        }
        top = head;
        ListNode *first(NULL);
        while (top)
        {
            if (mapValueCount[top->val] == 1)
            {
                first = top;
                break;
            }
            else
                top = top->next;
        }
        if (!top)
            return NULL;
        ListNode *second(first);
        while (top->next)
        {
            if (mapValueCount[top->next->val] == 1)
            {
                second->next = top->next;
                second = second->next;
            }
            top = top->next;
        }
        second->next = NULL;
        return first;
    }
};
/*
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
    top->next = new ListNode(2);
    top->next->next = new ListNode(3);
    top->next->next->next = new ListNode(3);
    top->next->next->next->next = new ListNode(4);
    ListNode *&second(top->next->next->next->next);
    second->next = new ListNode(4);
    second->next->next = new ListNode(5);
    printList(top);

    ListNode *third = Solution().deleteDuplicates(top);
    printList(third);
    return 0;
}
*/
// @lc code=end
