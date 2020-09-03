/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num ^= nums[i];
            //std::cout << num << " ";
        }
        //std::cout << std::endl; 
        return num;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> vecList = {4, 1, 2, 1, 2};
    std::cout << Solution().singleNumber(vecList) << std::endl; 
    return 0;
}
*/
// @lc code=end

