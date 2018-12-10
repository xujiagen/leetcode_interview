/*
删除链表的倒数第N个节点

题目里面建议通过一次扫描实现。
*/
#include<iostream>
#include<vector>
#include<string>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* top=head;
        int num=0;
        while(top->next)
        {
            num++;
            top=top->next;
        }
        top=head;
        //这个链表一共有多少节
        num++;
        if(num<n)
        {
            //说明这个链表里面的元素没有办法删除
            return head;
        }
        else if(num==n)
        {
            //删除头结点；
            return top->next;
        }
        else
        {
            //需要删除的位置在链表中间
            int position=num-n;
            while(position-1)
            {
                top=top->next;
                position--;
            }
            //这里top指向的是需要删除的节点的上一个位置
            top->next=top->next->next;
            return head;
        }
    }
};

int main()
{
    return 0;
}