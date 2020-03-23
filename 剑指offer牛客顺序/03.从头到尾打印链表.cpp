/*
输入一个链表，按照链表的值从未到头返回一个数组
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

/*
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        std::vector<int> vec_int;
        if(!head)  return vec_int;//如果输入的之间第一个值就是空的，不用继续了
        ListNode* top=head;
        while(top)
        {
            vec_int.push_back(top->val);
            top=top->next;
        }
        std::reverse(vec_int.begin(),vec_int.end());
        return vec_int;
    }
};
*/

#include <algorithm>
#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    std::vector<int> printListFromTailToHead(ListNode *head)
    {
        std::vector<int> vecInt;
        if (!head)
            return vecInt;
        ListNode *copyNode(head);
        std::cout << "start printNode: " << std::endl;
        while (copyNode)
        {
            vecInt.push_back(copyNode->val);
            copyNode = copyNode->next;
        }
        std::reverse(vecInt.begin(), vecInt.end());
        return vecInt;
    }
};

template <class T>
void printVec(typename std::vector<T> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl;
}

void printNode(ListNode *&_Head)
{
    ListNode *top(_Head);
    while (top)
    {
        std::cout << top->val << " ";
        top = top->next;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    int vec[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::cout << "print VecList: " << std::endl;
    printVec<int>(vecList);
    ListNode *top = new ListNode(0);
    ListNode *copyNode(top);
    for (int i = 0; i < vecList.size(); i++)
    {
        copyNode->next = new ListNode(vecList[i]);
        copyNode = copyNode->next;
    }
    std::cout << "print ListNode value: " << std::endl;
    printNode(top);

    std::cout << "print reverseList: " << std::endl;
    std::vector<int> reverseList = Solution().printListFromTailToHead(top);
    printVec<int>(reverseList);
    return 0;
}