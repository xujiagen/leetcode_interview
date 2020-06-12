#include <algorithm>
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

class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int firstList = 0, secondList = 0;
        ListNode *firstNode(pHead1);
        ListNode *secondNode(pHead2);
        while (firstNode)
        {
            firstNode = firstNode->next;
            firstList++;
        }
        while (secondNode)
        {
            secondNode = secondNode->next;
            secondList++;
        }
        if (firstList > secondList)
            return Handle(pHead1, pHead2, firstList, secondList);
        else
            return Handle(pHead2, pHead1, secondList, firstList);
    }
    ListNode *Handle(ListNode *pHead1, ListNode *pHead2, int FirstList, int SecondList)
    {
        int size = FirstList - SecondList;
        ListNode *firstNode(pHead1), *secondNode(pHead2);
        while (size--)
            firstNode = firstNode->next;
        while (firstNode != secondNode)
        {
            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }
        return firstNode;
    }
};