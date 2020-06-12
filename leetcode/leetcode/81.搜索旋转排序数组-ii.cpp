/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (35.25%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 65.2K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 * 
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 * 
 * 示例 1:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 0
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 3
 * 输出: false
 * 
 * 进阶:
 * 
 * 
 * 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
 * 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
/*
class Solution
{
public:
    bool search(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            while (left < right && nums[left] == nums[left + 1])
                left++;
            while (left < right && nums[right] == nums[right - 1])
                right--;
            int middle = left + (right - left) / 2;
            if (nums[middle] == target)
                return true;
            if (nums[middle] >= nums[left])
            {
                if (target < nums[middle] && target >= nums[left])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else
            {
                if (target > nums[middle] && target <= nums[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return false;
    }
};
*/

class Solution
{
public:
    bool search(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            while (left < right && nums[left] == nums[left + 1])
                left++;
            while (left < right && nums[right] == nums[right - 1])
                right--;
            int middle = left + (right - left) / 2;
            if (nums[middle] == target)
                return true;
            if (nums[middle] < nums[right])
            {
                //nums[middle] < nums[right] 右边有序
                if (target > nums[middle] && target <= nums[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
            else if (nums[middle] > nums[left])
            {
                if (target < nums[middle] && target >= nums[left])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else
            {
                if (nums[left] == nums[middle])
                    left++;
                if (nums[right] == nums[middle])
                    right--;
            }
        }
        return false;
    }
};
/*
int main(int argc, char **argv)
{
    std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 3;
    std::cout << Solution().search(nums, target) << std::endl;

    return 0;
}
*/
// @lc code=end
