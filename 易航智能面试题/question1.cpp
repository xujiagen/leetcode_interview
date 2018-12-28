#include <iostream>

using namespace std;

/*  Project 1

    定义一个单向链表node, 每个节点值为int.
    定义函数void create_linklist(…, int n)来生成链表，链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，链表节点值为1,2,3...n。
    定义函数reverse_linklist(...),　对参数传入的链表进行逆转。
    定义函数insert_node(node *pHead, int Index, int Value ), 在指定链表位置Index插入指定Value
    定义函数delete_node(node *pHead,  int Index),删除链表位置Index所在的节点
    定义函数delete_linklist(),　删除整个链表


    main()函数：
    １．调用create_linklist()生成链表
    ２．调用insert_node()插入节点
    ３．调用delete_node()删除节点
    ４．调用reverse_linklist()逆转
    ５．打印链表所有值
    ６．结束程序工作
*/

struct node
{
    int v;
    node* n;
    node(int value):v(value),n(NULL){}
};

/* 链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，
   链表节点值为1,2,3...n
*/
void create_linklist(node **pHead, int n)
{
    if(n<1)
        return;//输入参数不满足要求，将控制权返回给程序
    (*pHead)=new node(1);//创建一个链表和上一个链表是一样的
    node* head=(*pHead);
    for(int i=2;i<=n;i++)
    {
        head->n=new node(i);
        head=head->n;
    }
}


//对参数传入的链表进行逆转
void reverse_linklist(node **pHead)
{
    if((*pHead)==NULL || (*pHead)->n==NULL)
        return;//如果传入的链表是空的，或者传入的链表的下一个是空的，返回
    node* reverse=NULL;
    node* first=(*pHead);
    node* second=NULL;
    while(first)
    {
        node* next=first->n;
        if(next==NULL)
            reverse=first;
        first->n=second;
        second=first;
        first=next;

    }
    *pHead=reverse;
}

//在指定链表位置Index插入指定Value
// Index 为 1 ~ n 代表 1 ~ n 个节点
// Index = 0 即为头添加
void insert_node(node **pHead,  int Index, int Value)
{
    if((*pHead)==NULL)
        return;//传进来的链表的指针是一个空指针，将程序的控制权返回给上一层程序
    if(Index==0)
    {
        node* second=(*pHead)->n;//当前地方头指针
        int now=(*pHead)->v;//保存头结点里面的元素
        (*pHead)->v=Value;
        (*pHead)->n=new node(Index);
        (*pHead)->n->n=second;
    }
    else
    {
        int count=1;
        node* first=(*pHead);
        node* third;
        while(count<=Index-1 && first)
        {
            count++;
            first=first->n;
        }
        if(count<Index-1)
            return;//链表里面根本没有这么标签
        third=first->n;
        first->n=new node(Value);
        std::cout<<first->v<<std::endl;
        first->n->n=third;
    }
}

//删除链表位置Index所在的节点
void delete_node(node **pHead,  int Index)
{
    if(Index==1)
    {
        (*pHead)=(*pHead)->n;
        return;
    }
    node* first=(*pHead);
    node* second;
    int count=1;
    while(count<Index-1 && first)
    {
        count++;
        first=first->n;
    }
    if(count<Index-1)
        return;//程序没有给定位置的节点可以删除
    first->n=first->n->n;
}

//删除整个链表
void delete_linklist(node **pHead)
{
    node* head=(*pHead);
    while(head)
    {
        node* second=head->n;
        delete (head);
        head=second;
    }
}

int main()
{
    // Project 1
    // 可将头尾指针及节点个数封装结构体，更方便操作
    cout << "==========Project1=================" << endl;
    node *pHead = NULL;
    // １．调用create_linklist()生成链表
    create_linklist(&pHead,9);
    node *pTemp = pHead;
    while (pTemp)
    {
        std::cout << pTemp->v << " ";
        pTemp = pTemp->n;
    }
    std::cout<<std::endl;
    // ２．调用insert_node()插入节点
    insert_node(&pHead,9,10);
    pTemp = pHead;
    while (pTemp)
    {
        std::cout << pTemp->v << " ";
        pTemp = pTemp->n;
    }
    std::cout<<std::endl;
    // ３．调用delete_node()删除节点
    delete_node(&pHead,10);
    
    std:;cout<<"第三题"<<std::endl;
    pTemp = pHead;
    while (pTemp)
    {
        std::cout << pTemp->v << " ";
        pTemp = pTemp->n;
    }
    std::cout<<std::endl;
    // ４．调用reverse_linklist()逆转
    reverse_linklist(&pHead);

    pTemp = pHead;
    while (pTemp)
    {
        std::cout << pTemp->v << " ";
        pTemp = pTemp->n;
    }
    cout << endl;
    cout << "==========Project1=================" << endl;
    cout << endl;
}