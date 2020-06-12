/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (49.60%)
 * Likes:    567
 * Dislikes: 0
 * Total Accepted:    94.7K
 * Total Submissions: 190.1K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
/*
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *&_Top)
{
    if (!_Top)
        return;
    ListNode *top(_Top);
    while (top)
    {
        std::cout << top->val << " ";
        top = top->next;
    }
    std::cout << std::endl;
}
*/
class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        std::vector<ListNode *> copyList(lists.begin(), lists.end());
        while (copyList.size() != 1)
        {
            std::vector<ListNode *> tmpList;
            for (int i = 0; i < copyList.size(); i += 2)
            {
                if (i + 1 == copyList.size())
                    continue;
                tmpList.push_back(mergeList(copyList[i], copyList[i + 1]));
            }
            if (copyList.size() % 2 == 1)
                tmpList.push_back(copyList[copyList.size() - 1]);
            copyList = tmpList;
        }
        return copyList[0];
    }
    ListNode *mergeList(ListNode *_First, ListNode *_Second)
    {
        if (!_First)
            return _Second;
        if (!_Second)
            return _First;
        if (_Second->val < _First->val)
            return mergeList(_Second, _First);
        ListNode *top = new ListNode(0);
        ListNode *copy(top);
        while (_First && _Second)
        {
            if (_First->val <= _Second->val)
            {
                copy->next = _First;
                copy = copy->next;
                _First = _First->next;
            }
            else
            {
                copy->next = _Second;
                copy = copy->next;
                _Second = _Second->next;
            }
        }
        if (_First)
            copy->next = _First;
        else if (_Second)
            copy->next = _Second;
        //printList(top->next);
        return top->next;
    }
};
/*
int main()
{
    std::vector<ListNode *> List;
    ListNode *top = new ListNode(1);
    top->next = new ListNode(4);
    top->next->next = new ListNode(5);

    ListNode *second = new ListNode(1);
    second->next = new ListNode(3);
    second->next->next = new ListNode(4);

    ListNode *third = new ListNode(2);
    third->next = new ListNode(6);

    List.push_back(top);
    List.push_back(second);
    List.push_back(third);

    ListNode *final = Solution().mergeKLists(List);
    printList(final);
    return 0;
}
*/
// @lc code=end
