/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <pair>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<std::pair<int, int>> pairList;
        pairList.push_back(std::pair<int, int>(0, 1));
        pairList.push_back(std::pair<int, int>(1, 0));
        pairList.push_back(std::pair<int, int>(0, -1));
        pairList.push_back(std::pair<int, int>(-1, 0));
        std::pair<int, int> tmpPair(0, 0);
        int tmpDir = 0;
        const int &rows = matrix.size(), &cols = matrix[0].size();
        int left = rows, right = cols;
        std::vector<int> result;
        while (left < right) {
            result.push_back(matrix[tmpPair.first][tmpPair.second]);
            if (tmpPair.first == left) {
                tmpDir++;
                left--;
            }
            if (tmpPair.second == right) {
                tmpDir++;
                right--;
            }
        }
    }
};
// @lc code=end

