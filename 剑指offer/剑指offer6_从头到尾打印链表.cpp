/*
完成这个程序有两种方式：
第一种是通过递归来实现，但是递归会导致使用的内存数量溢出
第二种是通过栈的形式实现，但是程序的返回值是vector,可以将数据存储在vector中，然后将vector的数据翻转
*/
#include <iostream>
#include <vector>
#include<algorithm>
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
//上面
class Solution
{
  public:
    void push_into_vec(std::vector<int>& vec_int,ListNode* head)
    {
        if(!head->next)
        {
            vec_int.push_back(head->val);
        }
        else
        {
            push_into_vec(vec_int,head->next);
            vec_int.push_back(head->val);
        }
    }

    std::vector<int> printListFromTailToHead(ListNode *head)
    {
        std::vector<int> vec_int;
        push_into_vec(vec_int,head);
        return vec_int;
    }
};

class solution
{
    public:
    std::vector<int> printListFromTailToHead(ListNode *head)
    {
        std::vector<int> vec_int;
        if(!head)
            return vec_int;
        else
        {
            while(head)
            {
                vec_int.push_back(head->val);
                head=head->next;
            }
            std::reverse(vec_int.begin(),vec_int.end());
            return vec_int;
        }
    }
};

int main()
{
    ListNode* head=new ListNode(1);
    ListNode* top=head;
    for(int i=2;i<10;i++)
    {
        top->next=new ListNode(i);
        top=top->next;
    }
    Solution a;
    solution a1;

    std::vector<int> vec_int;
    vec_int=a.printListFromTailToHead(head);
    for(int i=0;i<vec_int.size();i++)
        std::cout<<vec_int[i]<<"\t";
    std::cout<<std::endl;

    std::vector<int> vec_int1;
    vec_int1=a1.printListFromTailToHead(head);
    for(int i=0;i<vec_int1.size();i++)
        std::cout<<vec_int1[i]<<"\t";
    std::cout<<std::endl;
    return 0;
}
