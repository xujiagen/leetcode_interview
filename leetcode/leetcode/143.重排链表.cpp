/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        int count = 0;
        ListNode* copy(head);
        while (copy) {
            count++;
            copy = copy->next;
        }
        int middle = (count + 1)>> 1;
        ListNode* middleNode(head);
        while (--middle > 0) {
            middleNode = middleNode->next;
        }
        ListNode* reverseHead = reverseList(middleNode->next);
        
        //std::cout << "reverseHead: " << std::endl; 
        //printList(reverseHead);
        //std::cout << std::endl; 
        middleNode->next = NULL;
        
        //std::cout << "head: " << std::endl; 
        //printList(head);
        //std::cout << std::endl; 

        ListNode* top(head);
        while (top && reverseHead) {
            ListNode* topNext = top->next;
            ListNode* reverseHeadNext = reverseHead->next;
            top->next = reverseHead;
            reverseHead->next = topNext;
            top = topNext;
            reverseHead = reverseHeadNext;
        }
        //printList(head);
    }

    ListNode* reverseList(ListNode* top) {
        if (!top || !top->next) return top;
        ListNode *first(top);
        ListNode *second(top->next);
        first->next = NULL;
        while (second) {
            ListNode *third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        return first;
    }
    /*
    void printList(ListNode* top) {
    if (!top) return;
    ListNode* copyTop(top);
    while (copyTop) {
        std::cout << copyTop->val << " ";
        copyTop = copyTop->next;
    }
    std::cout << std::endl; 
}
*/
};

/*
void printList(ListNode* top) {
    if (!top) return;
    ListNode* copyTop(top);
    while (copyTop) {
        std::cout << copyTop->val << " ";
        copyTop = copyTop->next;
    }
    std::cout << std::endl; 
}
    


int main(int argc, char** argv) {
    ListNode* top = new ListNode(1);
    top->next = new ListNode(2);
    top->next->next = new ListNode(3);
    top->next->next->next = new ListNode(4);
    //top->next->next->next->next = new ListNode(5);

    //Solution().printList(top);
    //std::cout << std::endl; 

    Solution().reorderList(top);
    printList(top);
    //std::cout << Solution().reorderList(top) << std::endl; 
    return 0;

}
*/
// @lc code=end

