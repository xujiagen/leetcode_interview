#include <iostream>
#include <stdlib.h>
struct Linklist
{
    int data;
    Linklist *next;
    Linklist(int x) : data(x), next(NULL) {}
};
class Solution
{
    public:
    void quicksort(Linklist *top, Linklist *end)
    {
        if (top == NULL || top == end)
            return;//输入的指针是一个空指针
        int t;
        Linklist *p = top->next;//一开始top是排序的轴
        Linklist *min = top;
        while (p != end)
        {
            if (p->data < top->data)
            {
                min = min->next;
                t = min->data;
                min->data = p->data;
                p->data = t;
            }
            p = p->next;
        }

        t = top->data;
        top->data = min->data;
        min->data = t;
        //第一次排序完成之后,交换中心位置和轴的位置

        quicksort(top, min);
        quicksort(min->next, end);
        //递归
    }
};

int main()
{
    Linklist *top = new Linklist(25);
    Linklist *node = top;
    //下面创建的随机链表
    std::cout<<"创建随机链表"<<std::endl;
    for (int i = 0; i < 20; i++)
    {
        node->next = new Linklist((int)rand() % 20);
        std::cout << node->data << "\t";
        node = node->next;
    }
    std::cout << std::endl;

    //快速排序之后的链表
    std::cout<<"快速排序之后的链表"<<std::endl;
    Solution a;
    a.quicksort(top,NULL);
    for (Linklist *head = top; head != node; head = head->next)
    {
        std::cout << head->data << "\t";
    }
    std::cout << std::endl;
    return 0;
}