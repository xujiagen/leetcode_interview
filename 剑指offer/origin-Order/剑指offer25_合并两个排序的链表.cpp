/*
合并两个排序的链表
*/
#include<iostream>
#include<vector>

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
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;

        if(pHead1->val>pHead2->val)
            return Merge(pHead2,pHead1);//保证第一个是最小的
        
        ListNode* top=new ListNode(pHead1->val);
        ListNode* left=pHead1->next;
        ListNode* right=pHead2;
        ListNode* top1=top;
        while(left || right)
        {
            std::cout<<1<<std::endl;
            if(left && right && left->val>right->val)
            {
                top1->next=new ListNode(right->val);
                right=right->next;
            }
            else if(left && right)
            {
                top1->next=new ListNode(left->val);
                left=left->next;
            }
            else if(!left && right)
            {
                top1->next=right;
                break;
            }
            else if(left && !right)
            {
                top1->next=left;
                break;
            }
        }
        return top;
    }
};

class solution
{
    public:
    ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
    {
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        
        ListNode* head;
        if(pHead1->val>pHead2->val)
        {
            head=pHead2;
            head->next=Merge(pHead1,pHead2->next);
        }
        else
        {
            head=pHead1;
            head->next=Merge(pHead1->next,pHead2);
        }
        return head;
    }
};

int main()
{
    ListNode* top=new ListNode(1);
    ListNode* top2=new ListNode(2);
    ListNode* head=top;
    ListNode* head2=top2;
    for(int i=1;i<12;i=i+2)
    {
        head->next=new ListNode(i);
        head=head->next;
    }
    for(int i=2;i<12;i=i+2)
    {
        head2->next=new ListNode(i);
        head=head->next;
    }
    head=top;
    head2=top2;
    while(head)
    {
        std::cout<<head->val<<"\t";
        head=head->next;
    }
    std::cout<<std::endl;
    while(head2)
    {
        std::cout<<head2->val<<"\t";
        head2=head2->next;
    }
    std::cout<<std::endl;
    solution a;
    ListNode* new1=a.Merge(top,top2);
    ListNode* new2=new1;
    while(new2)
    {
        std::cout<<new2->val<<"\t";
        new2=new2->next;
    }
    std::cout<<std::endl;
    return 0;
}