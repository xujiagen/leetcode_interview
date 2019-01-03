/*
找到两个链表，判断这两个链表的公共节点
*/

#include<iostream>
#include<vector>


using namespace std;

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        if(!pHead1)
            return pHead1;
        if(!pHead2)
            return pHead2;
        ListNode* top1=pHead1;
        ListNode* top2=pHead2;
        int count1=1,count2=1;
        while(top1->next)
        {
            count1++;
            top1=top1->next;
        }
        while(top2->next)
        {
            count2++;
            top2=top2->next;
        }

        if(count1>=count2)
        {
            top1=pHead1;
            top2=pHead2;
        }
        else
        {
            top1=pHead2;
            top2=pHead1;
            std::swap(count1,count2);
        }
        //上面将区分了两个链表的长度

        int distance=count1-count2;
        while(distance--)
        {
            top1=top1->next;
        }
        //现在判断两个节点的是不是指向同一个节点
        while(top1!=top2)
        {
            top1=top1->next;
            top2=top2->next;
        }
        return top1;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* node=new ListNode(0);
    ListNode* top=node;
    for(int i=0;i<10;i++)
    {
        top->next=new ListNode(i);
        top=top->next;
    }

    ListNode* hand=node->next->next;
    top=node;
    Solution a;
    ListNode* palce=a.FindFirstCommonNode(hand,top);
    std::cout<<palce->val<<std::endl;
    return 0;
}
