/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int minStep;
    int jump(std::vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        minStep = nums.size();
        IterFinal(nums, 0, 0);
        return minStep;
    }
    void IterFinal(std::vector<int> &_VecList, int _Left, int _Step) {
        if (_Left + _VecList[_Left] >= _VecList.size() - 1) 
            minStep = minStep >  _Step + 1 ? _Step + 1 : minStep;
        else {
            int tmpNextPostion = _VecList[_Left + 1] + _Left + 1;
            int tmpIndex = _Left + 1;
            for (int i = _Left + 1; i <= _Left + _VecList[_Left]; i++) {
                if (_VecList[i] + i > tmpNextPostion) {
                    tmpNextPostion = _VecList[i] + i;
                    tmpIndex = i;
                }
            }
            IterFinal(_VecList, tmpIndex, _Step + 1);
        }
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> vecList = {2,3,1,1,4};
    std::cout << Solution().jump(vecList) << std::endl;
    return 0;
}
*/
// @lc code=end

