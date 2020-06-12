/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int left = 0, value = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                value = nums[i], left = 1, count++;
                continue;
            } else if (value == nums[i]) {
                count++;
                if (count <= 2) {
                    nums[left++] = nums[i];
                }
            } else if (value != nums[i]) {
                value = nums[i];
                count = 1;
                nums[left++] = nums[i];
            }
        }
        return left;
    }
};
/*
void printList(const std::vector<int> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {0,0,1,1,1,1,2,3,3};
    printList(vecList);
    std::cout << Solution().removeDuplicates(vecList) << std::endl;
    printList(vecList);
    return 0;
}
*/
// @lc code=end

