/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
void printList(ListNode *head) {
    if (!head) return;
    ListNode* top(head);
    while (top) {
        std::cout << top->val << " ";
        top = top->next;
    }
    std::cout << std::endl; 
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* copyFirst(first), *copySecond(second);
        while (head) {
            if (head->val >= x) {
                copyFirst->next = head;
                copyFirst = copyFirst->next;
            } else if (head->val < x) {
                copySecond->next = head;
                copySecond = copySecond->next;
            }
            head = head->next;
        }
        copyFirst->next = NULL;
        copySecond->next = NULL;
        //std::cout << "first List!" << std::endl; 
        //printList(first->next);
        //std::cout << "second List!" << std::endl; 
        //printList(second->next);
        //if (second->next) copySecond->next = first->next; 
        //copySecond->next = copyFirst->next;
        if (second->next) {
            copySecond->next = first->next;
            return second->next;
        }
        else return first->next;
    }
};
/*
int main(int argc, char** argv) {
Node *top = new ListNode(1);
    printList(top);
    ListNode* final = Solution().partition(top, 2);
    printList(final);
    return 0;
}
*/
// @lc code=end

