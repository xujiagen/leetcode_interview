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
        ListNode* first=new ListNode(0);
        ListNode* point=first;
        while(l1)
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
            
                point->next=new ListNode(num);
                point=point->next;

            }
            l1=l1->next;
            l2=l2->next;
        }
        return first->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* pHead=new ListNode(0);
        ListNode *pCurrent=pHead;
	   int overload=0;//是不是有进位；有进位为1；
        while(l1||l2||overload)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+overload;//某一位的值为l1/l2的值加上进位的值；
            if(sum>=10)//如果这个和大于10
            {
                sum%=10;//更新这个值
                overload=1;//并且产生进位；
            }
            else
                overload=0;
            pCurrent->next=new ListNode(sum);//将当前的值赋给第一位；也就是个位数；
            pCurrent=pCurrent->next;//当前的位置往下进行；也就是十位数
            if(l1) l1=l1->next;//l1链表往后遍历；
            if(l2) l2=l2->next;//l2链表往后遍历；
        }
        return pHead->next;
    }
};

//下面是最终提交版本
class Solution
{
    public:
    ListNode* addTwoNumbers(ListNode*l1,ListNode*l2)
    {
        int add_flag=0;
        int num1,num2,sum;
        ListNode *first=new ListNode(0);
        ListNode *point=first;
        while(l1||l2||add_flag)
        {
            sum=(l1?l1->val:0)+(l2?l2->val:0)+add_flag;
            if(sum>9)
            {
                sum=sum%10;
                add_flag=1;
            }
            else
            {
                add_flag=0;
            }
            point->next=new ListNode(sum);
            point=point->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            //上面这一行判断主要是这个链表可能已经计算完了，但是累加之后还有数
        }
        return first->next;
    }
};