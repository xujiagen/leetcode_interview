/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        if (nums.size() < 2) return;
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroCount++;
            else if (nums[i] == 1) oneCount++;
            else if (nums[i] == 2) twoCount++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < zeroCount) {
                nums[i] = 0; 
            } else if (i < zeroCount + oneCount) {
                nums[i] = 1;
            } else nums[i] = 2;
        }
        return;
    }
};
/*
void printList(std::vector<int> &_VecList) {
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {2, 0, 2, 1, 1, 0};
    Solution().sortColors(vecList);
    printList(vecList);
    return 0;
}
*/
// @lc code=end

