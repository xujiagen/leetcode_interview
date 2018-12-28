#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int v;
    node *n;
    node(int value) : v(value), n(NULL) {}
};

int sum_cals(int sum, int number, node *head)
{
    int branch1 = 0, branch2 = 0, branch3 = 0;
    if (!head)
    {
        if (sum == number)
            return 1;
        else
            return 0;
    }
    if (head)
    {
        branch1 = branch1 + sum_cals(sum - number, head->v, head->n);
        branch2 = branch2 + sum_cals(sum - number, -head->v, head->n);
        int pub = 0;
        if (number < 0)
        {
            pub = number * 10 - head->v;
        }
        else
        {
            pub = number * 10 + head->v;
        }
        branch3 = branch3 + sum_cals(sum, pub, head->n);
    }
    return branch1 + branch2 + branch3;
}

int Calculate(node *pHead, int k)
{
    int num;
    num = sum_cals(k, pHead->v, pHead->n);
    return num;
}

int main(int argc, char const *argv[])
{
    node *head = new node(1);
    node *top = head;
    for (int i = 2; i < 10; i++)
    {
        top->n = new node(i);
        top = top->n;
    }
    top = head;
    while (top)
    {
        std::cout << top->v << "\t";
        top = top->n;
    }
    std::cout << std::endl;
    std::cout << Calculate(head, 100) << std::endl;
    return 0;
}
