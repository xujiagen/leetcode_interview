/*
输入一个链表，按照链表的值从未到头返回一个数组
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        std::vector<int> vec_int;
        if(!head)  return vec_int;//如果输入的之间第一个值就是空的，不用继续了
        ListNode* top=head;
        while(top)
        {
            vec_int.push_back(top->val);
            top=top->next;
        }
        std::reverse(vec_int.begin(),vec_int.end());
        return vec_int;
    }
};