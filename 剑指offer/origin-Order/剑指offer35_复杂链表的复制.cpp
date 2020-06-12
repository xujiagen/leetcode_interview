/*
复杂链表的复制
//代码没有运行成功，主要是不方便调试
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

/*
class Solution 
{
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //在原来链表的基础上面创建链表
        if(!pHead)
            return NULL;
        RandomListNode* top=pHead;
        RandomListNode* second=top->next;
        while(top)
        {
            top->next=new RandomListNode(top->label);
            top->next->next=second;
            top=top->next->next;
            second=second->next;
        }
        //上面在原来链表的基础上面创建了新的链表
        top=pHead;
        while(top)
        {
            if(top->random)
            {
                top->next->random=top->random->next;
                if(top->next->next)
                    top=top->next->next;
                else
                    break;
            }
        }

        //将上面的链表拆分成两个链表
        top=pHead;
        second=top->next;
        RandomListNode* third=second;
        while(top)
        {
            if(top->next->next)
            {
                top->next=top->next->next;
                top=top->next->next;
            }
            if(second->next->next)
            {
                second->next=second->next->next;
                second=second->next->next;
            }
        }
        return third;
    }
    
};
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;
        RandomListNode* top=pHead;
        RandomListNode* second;
        RandomListNode* third;
        while(top)
        {
            second=new RandomListNode(top->label);
            third=top->next;
            top->next=second;
            second->next=third;
            top=top->next->next;
        }
        
        //上面基本上将节点都复制了一遍，显示开始指向随机指针
        top=pHead;
        second=top->next;
        while(top)
        {
            second->random=top->random->next;
            top=top->next->next;
            second=second->next->next;
        }
        
        //下面开始将两个链表分开
        top=pHead;
        second=top->next;
        third=second;
        while(top)
        {
            top->next=second->next;
            second->next=top->next->next;
            top=top->next;
            second=second->next;
        }
        return third;
    }
};
//上面这一段代码是2019031６号写的，感觉没有什么问题，但是在牛客网上面显示递归的层数比较多


int main()
{
    Solution a;
    return 0;
}