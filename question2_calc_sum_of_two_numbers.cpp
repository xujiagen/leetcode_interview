//题目的地址，计算两个数字的和，同时这个数据是保存在链表里面
#include<iostream>
#include<vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution
{
    public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
    {
        ListNode* point=NULL;
        ListNode* node1=l1;
        ListNode* node2=l2;
        int num=0;
        int sum_over_ten=0;
        if(l1)
        {
            num=node1->val+node2->val+sum_over_ten;//计算两个量的和
            if(num>10)
            {
                num=num%10;
                sum_over_ten=1;
            }
            else
            {
                sum_over_ten=0;
            }
            node1=node1->next;
            node2=node2->next;
            ListNode* temp=new ListNode;//创建一个缓存，暂时存储数据
            if(node1==first)
            {
                ListNode* temp=new ListNode(num);
                point=temp;
            }
            else
            {
                ListNode* temp=new ListNode(num);
                temp->next=point;
                point=temp;
            }
        }
        return point;
    }
};

class Solution
{
    public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode*l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        int num1,num2,num;
        int sum_of_num=0;
        ListNode* point=NULL;
        ListNode* first=l1;
        if(l1)
        {
            num1=l1->val;
            num2=l2->val;
            num=num1+num2+sum_of_num;
            if(num>10)
            {
                num=num%10;
                sum_of_num=1;
            }
            else
            {
                sum_of_num=0;
            }
            ListNode* temp=new ListNode(num);
            if(l1==first)
            {
                first=point=temp;
            }
            else
            {
                first=temp;
                first->next=point;
                point=temp;

            }
            l1=l1->next;
            l2=l2->next;
        }
        return first;
    }
};