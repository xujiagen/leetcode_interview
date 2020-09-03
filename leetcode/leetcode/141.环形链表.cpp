/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
#include <map>
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        std::map<ListNode*, int> NodeIndex;
        ListNode* top(head);
        int index = 0;
        while (head) {
            if (NodeIndex.find(head) != NodeIndex.end()) return true;
            else NodeIndex[head] = index++;
            head = head->next;
        }
        return false;
    }
};
// @lc code=end

