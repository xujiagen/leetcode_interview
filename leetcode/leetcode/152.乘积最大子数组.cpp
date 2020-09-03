/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.size() < 1) return 0;
        else if (nums.size() == 1) return nums[0];
        int tmpMax = 1, tmpMin = 1, maxValue = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                tmpMax = 1;
                tmpMin = 1;
                if (maxValue < 0) maxValue = 0;
            } else {
                int Max = std::max(tmpMax *nums[i], std::max(tmpMin * nums[i], nums[i]));
                int Min = std::min(tmpMax * nums[i], std::min(tmpMin * nums[i], nums[i]));
                tmpMax = Max;
                tmpMin = Min;
                if (tmpMax > maxValue) maxValue = tmpMax;
            }
        }
        return maxValue;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> vecList = {2, 3, -2, 4};
    std::cout << Solution().maxProduct(vecList) << std::endl;
    return 0;
}
*/

// @lc code=end

