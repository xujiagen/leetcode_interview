/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <queue>
/*
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> valueCount;
        int tmpMax = INT_MIN; 
        std::vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                tmpMax = tmpMax > nums[i] ? tmpMax : nums[i];
                if (valueCount.find(nums[i]) != valueCount.end()) valueCount[nums[i]]++;
                else valueCount[nums[i]] = 1;
                if (i == k - 1) {
                    res.push_back(tmpMax);
                    continue;
                } else continue;
            }
            if (valueCount[nums[i - k]] <= 1) valueCount.erase(nums[i - k]);
            else valueCount[nums[i - k]]--;
            if (valueCount.find(nums[i]) != valueCount.end()) valueCount[nums[i]]++;
            else valueCount[nums[i]] = 1;
            if (nums[i] > tmpMax) {
                tmpMax = nums[i];
                res.push_back(tmpMax);
                continue;
            }
            if (valueCount.find(tmpMax) != valueCount.end()) {
                res.push_back(tmpMax);
                continue;
            } else {
                tmpMax = valueCount.begin()->first;
                for (std::unordered_map<int, int>::iterator iter = valueCount.begin(); iter != valueCount.end(); iter++) {
                    if (iter->first > tmpMax) tmpMax = iter->first;
                }
                res.push_back(tmpMax);
                continue;
            }
        }
        return res;
    }
};
*/
class Solution {
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        std::vector<int> res;
        std::queue<int> queueList;
        int tmpMax = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                queueList.push(nums[i]);
                tmpMax = std::max(tmpMax, nums[i]);
                if (i == k) {
                    res.push_back(tmpMax);
                    continue;
                }
            }
            
        }
    }
};

int main(int argc, char** argv) {
    std::vector<int> res = {1, 3, -1, -3, 5, 3, 6, 7};
    auto printValue = [](int &val) {std::cout << val << " ";};
    std::for_each(res.begin(), res.end(), printValue);
    std::cout << std::endl; 
    std::vector<int> result = Solution().maxSlidingWindow(res, 3);
    std:for_each(result.begin(), result.end(), printValue);
    std::cout << std::endl; 
    return 0;
}
// @lc code=end

