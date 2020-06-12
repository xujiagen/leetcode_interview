/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode-cn.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (37.07%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    19.7K
 * Total Submissions: 53K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出: [[1,5],[6,9]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出: [[1,2],[3,10],[12,16]]
 * 解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
    {
        auto sortType = [](std::vector<int> &_First, std::vector<int> &_Second) {
            if (_First[0] < _Second[0])
                return true;
            else
                return false;
        };
        std::vector<std::vector<int>> vecList;
        if (intervals.size() < 1)
        {
            vecList.push_back(newInterval);
            return vecList;
        }
        if (newInterval.size() < 1)
            return intervals;
        int left = -1, right = -1;
        std::vector<int> deleteList;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (left == -1 && newInterval[0] <= intervals[i][1] && newInterval[0] >= intervals[i][0])
                left = i;
            if (right == -1 && newInterval[1] <= intervals[i][1] && newInterval[1] >= intervals[i][0])
                right = i;
        }
        if (left == -1 && right != -1)
        {
            intervals[right][0] = std::min(intervals[right][0], newInterval[0]);
            return intervals;
        }
        if (left != -1 && right == -1)
        {
            intervals[left][1] = std::max(intervals[left][1], newInterval[1]);
            return intervals;
        }
        if (left == -1 && right == -1)
        {
            intervals.push_back({newInterval});
            std::sort(intervals.begin(), intervals.end(), sortType);
            return intervals;
        }
        if (left == right && left != -1)
        {
            intervals[left][0] = std::min(intervals[left][0], newInterval[0]);
            intervals[left][1] = std::max(intervals[left][1], newInterval[1]);
            return intervals;
        }
        int newLeft = std::min(newInterval[0], intervals[left][0]);
        int newRight = std::max(newInterval[1], intervals[right][1]);
        for (int i = right; i >= left; i--)
            intervals.erase(intervals.begin() + i);
        intervals.push_back({newLeft, newRight});
        std::sort(intervals.begin(), intervals.end(), sortType);
        return intervals;
    }
};
*/

class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
    {
        std::vector<std::vector<int>> res;
        bool flag = false;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
                continue;
            }
            if (intervals[i][0] > newInterval[1])
            {
                flag = !flag;
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++)
                {
                    res.push_back(intervals[j]);
                }
                break;
            }
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
        if (!flag)
            res.push_back(newInterval);
        return res;
    }
};
/*
int main()
{
    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> newInterval = {2, 5};
    auto res = Solution().insert(intervals, newInterval);
    return 0;
}
*/
/*
void printList(const std::vector<int> &_Vec)
{
    for (int i = 0; i < _Vec.size(); i++)
        std::cout << _Vec[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    //std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    //std::vector<int> newInterval = {3, 4};
    std::vector<int> newInterval = {2, 5};
    std::vector<std::vector<int>> vecList = Solution().insert(intervals, newInterval);
    for (int i = 0; i < vecList.size(); i++)
        printList(vecList[i]);
    return 0;
}
*/
// @lc code=end
