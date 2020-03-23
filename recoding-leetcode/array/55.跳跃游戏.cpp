/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        if (nums.size() <= 1) return true;
        return IterFinal(nums, 0);
    }
    bool IterFinal(const std::vector<int> &_VecList, int _Left) {
        if (_Left + _VecList[_Left] >= _VecList.size() - 1) return true;
        bool continueFlag = false;
        int maxStep = _VecList[_Left + 1] + _Left + 1;
        int tmpIndex = _Left + 1;
        for (int i = _Left + 1; i <= _Left + _VecList[_Left]; i++) {
            if (_VecList[i] != 0) continueFlag = true;
            if (i + _VecList[i] > maxStep) {
                maxStep = i + _VecList[i];
                tmpIndex = i;
            } 
        }
        if (!continueFlag) return false;
        else return IterFinal(_VecList, tmpIndex);
        return false;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> vecList = {3, 0, 8, 2, 0, 0, 2};
    std::cout << Solution().canJump(vecList) << std::endl;
    return 0;
}
*/


// @lc code=end

