#include <iostream>
#include <vector>
#include <set>

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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (!pHead)
            return NULL;
        std::set<ListNode *> nodeSet;
        ListNode *top(pHead);
        while (top)
        {
            if (nodeSet.count(top) == 1)
                return top;
            else
            {
                nodeSet.insert(top);
                top = top->next;
            }
        }
        return NULL;
    }
};