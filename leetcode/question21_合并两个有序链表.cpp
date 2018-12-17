/*
合并两个有序链表
*/
#include<iostream>
#include<vector>
#include<string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        //上面是判断输入的链表是不是空的链表，如果是空的链表直接返回另外一个链表
        if(l1->val>l2->val)
            return mergeTwoLists(l2,l1);
        //上面这一句的好处可以保证输入的第一个链表的第一个元素一定小于第二个链表的第一个元素
        ListNode* l_top=l1->next,*r_top=l2;
        ListNode* head=new ListNode(l1->val),*top=head;//head指针一定指向我们创建的第一个元素，是随着链表的增长一起移动的
        while(l_top!=NULL || r_top!=NULL)
        {
            //两个链表里面的元素都是空的，程序就运行结束了
            if(l_top==NULL)
            {
                top->next=r_top;
                return head;
            }
            else if(r_top==NULL)
            {
                top->next=l_top;
                return head;
            }
            else if(l_top->val<=r_top->val)
            {
                top->next=new ListNode(l_top->val);
                top=top->next;
                l_top=l_top->next;
            }
            else
            {
                top->next=new ListNode(r_top->val);
                top=top->next;
                r_top=r_top->next;
            }
        }
    }
};

int main()
{
    Solution a;
    return 0;
}