#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

void printRandomList(RandomListNode *&_Top)
{
    RandomListNode *copyTop(_Top);
    while (copyTop)
    {
        std::cout << copyTop->label << " ";
        if (copyTop->random)
            std::cout << copyTop->random->label;
        std::cout << std::endl;
        copyTop = copyTop->next;
    }
    std::cout << std::endl;
}

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (!pHead)
            return NULL;
        RandomListNode *copyTop(pHead);
        RandomListNode *copyNext(pHead->next);
        while (copyTop)
        {
            if (!copyTop->next)
            {
                copyTop->next = new RandomListNode(copyTop->label);
                break;
            }
            copyTop->next = new RandomListNode(copyTop->label);
            copyTop->next->next = copyNext;
            copyTop = copyNext;
            copyNext = copyNext->next;
        }
        std::cout << "first version: " << std::endl;
        printRandomList(pHead);

        copyTop = pHead;
        while (copyTop && copyTop->next)
        {
            copyTop->next->random = copyTop->random->next;
            copyTop = copyTop->next->next;
        }
        std::cout << "second version: " << std::endl;
        printRandomList(pHead);
        copyTop = pHead;
        copyNext = copyTop->next;
        RandomListNode *finalNext(copyNext);
        int count = 0;
        while (copyTop)
        {
            std::cout << count++ << std::endl;
            if (copyTop->next->next)
            {
                copyTop->next = copyTop->next->next;
                copyTop = copyTop->next;
            }
            std::cout << count << std::endl;
            if (copyNext->next)
            {
                copyNext->next = copyNext->next->next;
                copyNext = copyNext->next;
            }
            std::cout << count << std::endl;
        }

        return finalNext;
    }
};

int main(int argc, char **argv)
{
    RandomListNode *top = new RandomListNode(0);
    top->next = new RandomListNode(1);
    top->next->next = new RandomListNode(2);
    top->random = top->next->next;
    top->next->random = top;
    top->next->next->random = top;

    printRandomList(top);
    RandomListNode *result = Solution().Clone(top);
    printRandomList(result);

    return 0;
}