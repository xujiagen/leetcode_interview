/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
        std::vector<int> vecList = {1, 1};
        for (int i = 2; i < rowIndex + 1; i++) {
            std::vector<int> tmpList;
            tmpList.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                tmpList.push_back(vecList[j] + vecList[j + 1]);
            }
            tmpList.push_back(1);
            vecList = tmpList;
        }
        return vecList;
    }
};
// @lc code=end

