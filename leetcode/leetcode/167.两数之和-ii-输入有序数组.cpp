/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        std::vector<int> res;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) break;
            else if (numbers[left] + numbers[right] > target) right--;
            else left++;
        }
        if (left != right) {
            res = {left + 1, right + 1};
            return res;
        } else return res;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> vecList = {2, 7, 11, 15};
    std::vector<int> res = Solution().twoSum(vecList, 13); 
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
*/
// @lc code=end

