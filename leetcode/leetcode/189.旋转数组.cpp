/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

/*
class Solution {
public:
    void printList(std::vector<int> &list) {
        if (list.size() < 1) return;
        for (const auto &val : list) {std::cout << val << " ";}
        std::cout <<std::endl; 
    }
    void rotate(std::vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        k = k % nums.size();
        std::vector<int> firstList = std::vector<int>(nums.end() - k, nums.end());
        std::copy(nums.begin(), nums.end() - k, nums.begin() + k);
        std::copy(firstList.begin(), firstList.end(), nums.begin());
    }
};
*/

class Solution {
public:
    void rotate(std::vector<int> &nums, int k) {
        k = k % nums.size();
        int count = 0;
        for (int start = 0; start < nums.size(); start ++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};


int main(int argc, char** argv) {
    std::vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto printValue = [](int &val) {std::cout << val << " ";};
    std::for_each(list.begin(), list.end(), printValue);
    std::cout << std::endl; 
    Solution().rotate(list, 3);
    std::for_each(list.begin(), list.end(), printValue);
    std::cout << std::endl; 
    return 0;
}
// @lc code=end

