/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int maxSum = nums[0];
        int tmpSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmpSum + nums[i] > nums[i]) tmpSum += nums[i];
            else tmpSum = nums[i];
            maxSum = maxSum > tmpSum ? maxSum : tmpSum;
        }
        return maxSum;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> vecList = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << Solution().maxSubArray(vecList) << std::endl;
    return 0;
}
*/
// @lc code=end

