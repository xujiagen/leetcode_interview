#include<iostream>
#include<vector>
#include<stack>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) 
    {
        if( !pHead || !pHead->next)
            return pHead;
        
        ListNode *top=NULL;//创建一个空指针暂时不用
        ListNode* first=NULL;
        ListNode* second=pHead;
        while(second)
        {
            ListNode* pNext=second->next;
            if(!pNext)
                top=second;
            second->next=first;
            first=second;
            second=pNext;
        }
        return top;
    }
};

int main()
{
    ListNode* top=new ListNode(1);
    ListNode* head=top;
    for(int i=2;i<6;i++)
    {
        head->next=new ListNode(i);
        head=head->next;
    }
    head=top;
    while(head)
    {
        std::cout<<head->val<<"\t";
        head=head->next;
    }
    std::cout<<std::endl;

    Solution a;
    ListNode* back=a.ReverseList(top);
    while(back)
    {
        std::cout<<back->val<<"\t";
        back=back->next;
    }
    std::cout<<std::endl;
    return 0;

}