/*
合并两个排序的链表
输入两个单调递增的链表，输出这两个链表合成的链表，但是需要满足单调不减规则
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        //如果只有一个有效，输出有效的那一个

        ListNode* top;
        if(pHead1->val>=pHead2->val)
        {
            top=pHead2;
            top->next=Merge(pHead1,pHead2->next);
        }
        else if(pHead1->val<pHead2->val)
        {
            top=pHead1;
            top->next=Merge(pHead1->next,pHead2);
        }
        return top;
    }
};

int main()
{
    return 0;
}