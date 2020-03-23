/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> vecList;
        if (nums.size() < 4) return vecList;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target / 4) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;//第一步进行去重
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;//第二步进行去重
                int left = j + 1, right = nums.size()-1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        std::vector<int> tmpList = {nums[i], nums[j], nums[left], nums[right]};
                        vecList.push_back(tmpList);
                        while (left < right && nums[left] == nums[left + 1]) left++;//第三步进行去重
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;//第四步进行去重
                        right--;
                    } else if (nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else if (nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                }
            }
        }
        return vecList;
    }
};
/*
template <class T>
void printList(const typename std::vector<typename std::vector<T>> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        const std::vector<int> &vec = _VecList[i];
        for (int j = 0; j < vec.size();j++) {
            std::cout << vec[j] << " ";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vec = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> vecList = Solution().fourSum(vec, 0);
    printList(vecList);
    return 0;
}
*/
// @lc code=end

