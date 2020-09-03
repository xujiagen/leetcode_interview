/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (57.26%)
 * Likes:    444
 * Dislikes: 0
 * Total Accepted:    49.3K
 * Total Submissions: 85.3K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
#include <string>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *_Top)
{
    while (_Top)
    {
        std::cout << _Top->val << " ";
        _Top = _Top->next;
    }
    std::cout << std::endl;
}

/*
class Solution {
public:
    ListNode *reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;
        std::vector<ListNode*> nodeList(k, nullptr);
        ListNode* top(head);
        int count = 0, index = 0;
        ListNode* second = NULL;
        ListNode* back = NULL;
        ListNode* first = NULL;
        while (top) {
            if (count >= k) {
                for (int i = 0; i < k; i++) {
                    if (i == 0) {
                        nodeList[i]->next = second;
                        second = nodeList.back();
                        back = nodeList[0];
                        continue;
                    }
                    if (!first) {
                        first = nodeList.back();
                    }
                    nodeList[i]->next = nodeList[i - 1];
                }
                count = 0;
            }
            nodeList[count++] = top;
            std::cout << "top: " << top->val << std::endl; 
            top = top->next;
        }
        if (count > 0) back->next = nodeList[0];
        else back->next = NULL;
        return first;
    }
};
*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;
        std::vector<ListNode*> nodeList(k, nullptr);
        ListNode* top(head);
        int count = 0, index = 0;
        ListNode* listFirst(NULL), *listEnd(NULL), *grounpTop(NULL), *grounpBack(NULL);
        while (top || count >= k) {
            if (count >= k) {
                for (int i = 0; i < k; i++) {
                    if (i == 0) {
                        if (!listFirst) listFirst = nodeList.back();
                        if (!listEnd) {
                            nodeList[i]->next = listEnd; 
                            listEnd = nodeList[0];
                        }
                        else {
                            listEnd->next = nodeList.back();
                            listEnd = nodeList[0];
                            listEnd->next = NULL;
                        }
                        continue;
                    }
                    nodeList[i]->next = nodeList[i - 1];
                }
                count = 0;
            }
            if (top) {
                nodeList[count++] = top;
                top = top->next;
            }
            //std::cout << "top: " << top->val << std::endl; 
            //top = top->next;
        }
        if (count > 0 && listEnd) listEnd->next = nodeList[0];
        return listFirst;
    }
};

int main(int argc, char **argv)
{
    ListNode *top = new ListNode(1);
    top->next = new ListNode(2);
    /*
    top->next->next = new ListNode(3);
    top->next->next->next = new ListNode(4);
    top->next->next->next->next = new ListNode(5);
    */
    printList(top);
    ListNode *first = Solution().reverseKGroup(top, 2);
    printList(first);
    return 0;
}

/*
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *first(head), *second(NULL), *last(NULL), *top(NULL);
        while (first && judgeK(first, second, k))
        {
            //ListNode *third(second->next);
            ListNode *third(NULL);
            third = second ? second->next : NULL;
            reverseList(first, second, last);
            if (!top)
                top = second;
            last = first;
            first = third;
        }
        last->next = first;
        if (!top)
            return head;
        else
            return top;
    }
    bool judgeK(ListNode *head, ListNode *&back, int k)
    {
        int n = 1;
        while (n < k && head)
        {
            head = head->next;
            n++;
        }
        if (n < k)
            return false;
        else
        {
            back = head;
            return true;
        }
    }
    void reverseList(ListNode *head, ListNode *back, ListNode *last)
    {
        ListNode *first(head);
        ListNode *second(head->next);
        while (second != back)
        {
            ListNode *tmp = second->next;
            first->next = last;
            second->next = first;
            last = first;
            first = second;
            second = tmp;
        }
    }
};
*/
// @lc code=end
