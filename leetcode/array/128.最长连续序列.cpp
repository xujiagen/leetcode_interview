/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (48.25%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    36.7K
 * Total Submissions: 75.5K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        std::unordered_set<int> valueSet(nums.begin(), nums.end());
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (valueSet.find(nums[i] - 1) != valueSet.end())
                continue;
            int tmpLength = 1;
            int tmpValue = nums[i];
            while (valueSet.find(tmpValue + 1) != valueSet.end())
            {
                tmpLength++;
                tmpValue++;
            }
            maxLength = maxLength > tmpLength ? maxLength : tmpLength;
        }
        return maxLength;
    }
};
/*
int main()
{
    std::vector<int> vecList = {100, 4, 200, 1, 3, 2};
    std::cout << Solution().longestConsecutive(vecList) << std::endl;
    return 0;
}
*/
// @lc code=end
