/*
反转链表，输出新的链表的表头
*/
/*
#include<iostream>
#include<vector>
#include<queue>

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
    ListNode* ReverseList(ListNode* pHead) 
    {
        if(!pHead || !pHead->next) return pHead;//链表的长度不够还是直接返回吧
        ListNode* first=NULL;
        ListNode* second=pHead;
        ListNode* top=NULL;
        while(second)
        {
            if(!second->next) top=second;
            std::cout<<"second->val:"<<second->val<<" ";
            ListNode* third=second->next;
            second->next=first;
            first=second;//移动第一个指针
            second=third;
        }
        std::cout<<std::endl;
        return top;
    }
};

void print_list(ListNode* top)
{
    ListNode* second=top;
    while (second)
    {
        std::cout<<second->val<<" ";
        second=second->next;
    }
    std::cout<<std::endl;
    
}

ListNode* construct_list(std::vector<int> vec_int,ListNode* top)
{
    if(!vec_int.size()) return NULL;
    top=new ListNode(vec_int[0]);
    if(vec_int.size()==1) return top;
    ListNode* second=top;
    for(int i=1;i<vec_int.size();i++)
    {
        second->next=new ListNode(vec_int[i]);
        second=second->next;
    }
    return top;
}

int main()
{
    int a1[]={1,2,3,4,5,6,7,8,9};
    std::vector<int> vec_int(a1,a1+sizeof(a1)/sizeof(int));
    ListNode* top;
    top=construct_list(vec_int,top);
    print_list(top);
    Solution a2;
    std::cout<<"reverse:"<<std::endl;
    top=a2.ReverseList(top);
    print_list(top);
    return 0;
}
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) 
    {
        if(!pHead || !pHead->next) return pHead;//如果链表的长度不够还是不行
        ListNode* first=NULL;
        ListNode* second=pHead;
        ListNode* top=NULL;
        while (second)
        {
            ListNode* third=second->next;
            if(!third) top=second;
            second->next=first;
            first=second;
            second=third;
        }
        return top;
    }
};
*/

class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode *top(pHead);
        ListNode *second(pHead->next);
        ListNode *third(pHead->next->next);
        top->next = NULL;
        second->next = top;
        while (third)
        {
            top = second;
            second = third;
            third = third->next;
            second->next = top;
        }
        return second;
    }
};

void printNode(ListNode *&_Top)
{
    ListNode *copyNode(_Top);
    while (copyNode)
    {
        std::cout << copyNode->val << " ";
        copyNode = copyNode->next;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    int vec[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    ListNode *top = new ListNode(0);
    ListNode *copyTop(top);
    for (int i = 0; i < vecList.size(); i++)
    {
        copyTop->next = new ListNode(vecList[i]);
        copyTop = copyTop->next;
    }
    printNode(top);
    ListNode *reverseTop = Solution().ReverseList(top);
    printNode(reverseTop);
    return 0;
}