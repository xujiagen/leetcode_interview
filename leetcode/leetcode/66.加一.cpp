/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if (digits.size() < 1) return digits;
        std::vector<int> tmpNum(digits.begin(),  digits.end());
        int addUp = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int tmpValue = digits[i] + addUp;
            tmpNum[i] = tmpValue % 10;
            addUp = tmpValue / 10;
            if (addUp == 0) return tmpNum;
        }
        if (addUp > 0) tmpNum.insert(tmpNum.begin(), 1, addUp);
        return tmpNum;
    }
};
/*
void printList(std::vector<int> &_Digits) {
    if (_Digits.size() < 1) return;
    for (int i = 0; i < _Digits.size(); i++) {
        std::cout << _Digits[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {9, 9, 9};
    auto res = Solution().plusOne(vecList);
    printList(res);
    return 0;
}
*/
// @lc code=end

