/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
#include <iostream>
#include <queue>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <climits>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        if (nums.size() < 1) return 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        std::unordered_set<int> queueSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (queueSet.find(nums[i]) != queueSet.end()) continue;
            if (queue.size() < 3) {
                queue.push(nums[i]);
                queueSet.insert(nums[i]);
            } else if (nums[i] > queue.top()) {
                queueSet.erase(queue.top());
                queue.pop();
                queue.push(nums[i]);
                queueSet.insert(nums[i]);
            }
        }
        //return queue.top();
        if (queue.size() == 3) return queue.top();
        int max = INT_MIN;
        std::vector<int> setList(queueSet.begin(), queueSet.end());
        for (int i = 0; i < setList.size(); i++) if (max < setList[i]) max = setList[i];
        return max;
    }
};

int main(int argc, char** argv) {
    std::vector<int> vecList = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    std::cout << Solution().thirdMax(vecList) << std::endl;
    return 0;    
}
// @lc code=end

