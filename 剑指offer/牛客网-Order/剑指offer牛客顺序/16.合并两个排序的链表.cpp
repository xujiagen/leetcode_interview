/*
合并两个排序的链表
输入两个单调递增的链表，输出这两个链表合成的链表，但是需要满足单调不减规则
*/
#include <iostream>
#include <vector>
#include <queue>

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        //如果只有一个有效，输出有效的那一个

        ListNode* top;
        if(pHead1->val>=pHead2->val)
        {
            top=pHead2;
            top->next=Merge(pHead1,pHead2->next);
        }
        else if(pHead1->val<pHead2->val)
        {
            top=pHead1;
            top->next=Merge(pHead1->next,pHead2);
        }
        return top;
    }
};
*/

class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1)
            return pHead2;
        if (!pHead2)
            return pHead1;
        if (pHead1->val > pHead2->val)
            return Merge(pHead2, pHead1);
        ListNode *first(pHead1->next);
        ListNode *final(pHead1);
        ListNode *second(pHead2);
        ListNode *copyF(first->next);
        ListNode *copyS(pHead2->next);
        while (first || second)
        {
            if (!first)
            {
                final->next = second;
                return pHead1;
            }
            if (!second)
            {
                final->next = first;
                return pHead1;
            }
            if (first->val <= second->val)
            {
                final->next = first;
                final = final->next;
                first = first->next;
            }
            else
            {
                final->next = second;
                final = final->next;
                second = second->next;
            }
        }
        return pHead1;
    }
};

void printNode(ListNode *top)
{
    ListNode *copyTop(top);
    while (copyTop)
    {
        std::cout << copyTop->val << " ";
        copyTop = copyTop->next;
    }
    std::cout << std::endl;
}

int main()
{
    int firstVal[] = {1, 2, 3, 4, 5, 6, 7};
    int secondVal[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> firstList(firstVal, firstVal + sizeof(firstVal) / sizeof(int));
    std::vector<int> secondList(secondVal, secondVal + sizeof(secondVal) / sizeof(int));
    ListNode *firstNode = new ListNode(0);
    ListNode *secondNode = new ListNode(0);
    ListNode *copyFirst(firstNode);
    ListNode *copySecond(secondNode);
    for (int i = 0; i < firstList.size(); i++)
    {
        copyFirst->next = new ListNode(firstList[i]);
        copyFirst = copyFirst->next;
    }
    for (int i = 0; i < secondList.size(); i++)
    {
        copySecond->next = new ListNode(secondList[i]);
        copySecond = copySecond->next;
    }
    std::cout << "first List: " << std::endl;
    printNode(firstNode);
    std::cout << "second List: " << std::endl;
    printNode(secondNode);
    ListNode *mergeList = Solution().Merge(firstNode, secondNode);
    std::cout << "merge List: " << std::endl;
    printNode(mergeList);
    return 0;
}