/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//#include <priority_queue>
#include <queue>

/*
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> queue;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                queue.push(nums[i]);
                continue;
            }
            if (queue.top() < nums[i]) {
                queue.pop();
                queue.push(nums[i]);
            }
        }
        return queue.top();
    }
};
*/

/*
class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) queue.push(nums[i]);
            else if (queue.top() < nums[i]) {
                queue.pop();
                queue.push(nums[i]);
            }
        }
        return queue.top();
    }
};
*/
class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<int>> queue;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) queue.push(nums[i]);
            else if (queue.top() > nums[i]) {
                queue.pop();
                queue.push(nums[i]);
            }
        }
        return queue.top();
    }
};

int main(int argc, char** argv) {
    std::vector<int> input = {3, 2, 1, 5, 6, 4};
    std::cout << Solution().findKthLargest(input, 2) << std::endl; 
    return 0;
}
// @lc code=end

