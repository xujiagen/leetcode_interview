/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (47.65%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 57.8K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 
 * 要求返回这个链表的 深拷贝。 
 * 
 * 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 * 
 * 
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 * 
 * 
 * 示例 4：
 * 
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10000 <= Node.val <= 10000
 * Node.random 为空（null）或指向链表中的节点。
 * 节点数目不超过 1000 。
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <iostream>
/*
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void printList(Node *&_Top)
{
    Node *top(_Top);
    while (top)
    {
        std::cout << top->val << " ";
        if (top->random)
            std::cout << top->random->val << std::endl;
        else
            std::cout << "null" << std::endl;
        top = top->next;
    }
    std::cout << std::endl;
}
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        Node *top(head);
        while (top)
        {
            Node *next(top->next);
            top->next = new Node(top->val);
            top->next->next = next;
            top = top->next->next;
        }
        top = head;
        while (top)
        {
            if (top->random)
                top->next->random = top->random->next;
            top = top->next->next;
        }
        top = head;
        Node *second(top->next), *third(top->next);
        while (top)
        {
            top->next = top->next->next;
            if (top->next)
                third->next = top->next->next;
            else
                third->next = NULL;
            top = top->next;
            third = third->next;
        }
        return second;
    }
};
/*
int main()
{
    Node *top = new Node(7);
    top->next = new Node(13);
    top->next->next = new Node(11);
    top->next->next->next = new Node(10);
    top->next->next->next->next = new Node(1);
    top->next->random = top;
    top->next->next->random = top->next->next->next->next;
    top->next->next->next->random = top->next->next;
    top->next->next->next->next->random = top;
    printList(top);

    Node *second = Solution().copyRandomList(top);
    printList(second);

    return 0;
}
*/
// @lc code=end
