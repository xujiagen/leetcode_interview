/*
链表中倒数第k个节点
*/
#include<iostream>
#include<vector>

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        if(!pListHead)
            return NULL;
        //删除链表中倒数第k个节点
        ListNode* first=pListHead;
        ListNode* second=pListHead;
        for(int i=0;i<k;i++)
        {
            if(second)
                second=second->next;
            else
            {
                return NULL;
                //如果倒数的个数都没有那就凉了
            }
        }
        while(second)
        {
            second=second->next;
            first=first->next;
        }
        return first;
    }
};

int main()
{
    ListNode* head=new ListNode(1);
    ListNode* top=head;
    for(int i=2;i<10;i++)
    {
        top->next=new ListNode(i);
        top=top->next;
    }
    Solution a;
    a.FindKthToTail(head,4);
    ListNode* new1=head;
    while(new1)
    {
        std::cout<<new1->val<<"\t";
        new1=new1->next;  
    }
    std::cout<<std::endl;
    return 0;
}