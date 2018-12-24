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

int main()
{
    Solution a;
    return 0;
}