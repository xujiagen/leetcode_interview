/*
输入一个链表，输出该链表的倒数第k个节点

创建两个指针，这两个指针之间的距离是k

首先判断这个链表的长度有没有k


这个程序需要注意的是，如果这个链表的长度就是k,可能会存在错误，需要给这个第一指针先下移k-1,再给第二个指针赋值
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        if(!pListHead) return NULL;
        //如果这个链表的第一个指针是空的，返回值是空的

        ListNode* first=NULL;
        ListNode* second=pListHead;
        int k_cp=k-1;
        while(k_cp--)
        {
            second=second->next;
            if(!second) return NULL;
        }
        second=second->next;
        first=pListHead;
        while (second)
        {
            second=second->next;
            first=first->next;
        }
        return first;
    }
};
*/
class Solution
{
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        int ListCount = 0;
        ListNode *copyK(pListHead);
        while (copyK && ListCount < k)
        {
            copyK = copyK->next;
            ListCount++;
        }
        if (ListCount != k)
            return NULL;
        ListNode *copyTop(pListHead);
        while (copyK)
        {
            copyK = copyK->next;
            copyTop = copyTop->next;
        }
        return copyTop;
    }
};

int main()
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
    ListNode *kNode = Solution().FindKthToTail(top, 3);
    if (kNode == NULL)
        std::cout << "null point!" << std::endl;
    else
        std::cout << "k Num: " << kNode->val << std::endl;
    return 0;
}
