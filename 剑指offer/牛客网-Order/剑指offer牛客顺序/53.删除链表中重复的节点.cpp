#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead)
            return NULL;
        std::set<int> NodeSet;
        ListNode *top(pHead);
        while (top)
        {
            if (NodeSet.count(pHead->val) == 0)
            {
                NodeSet.insert(pHead->val);
            }
            else
            {
                NodeSet.erase(pHead->val);
            }
            top = top->next;
        }
        top = pHead;
        while (NodeSet.count(top->val) == 0)
            top = top->next;
        ListNode *next(top->next);
        ListNode *head(top);
        while (next)
        {
            if (NodeSet.count(next->val) == 0)
                next = next->next;
            else
            {
                head->next = next;
                head = head->next;
                next = next->next;
            }
        }
        return top;
    }
};

int main()
{
    return 0;
}