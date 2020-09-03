/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <array>
#include <climits>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        const int rows = dungeon.size(), cols =dungeon[0].size();
        std::vector<std::vector<int>> res(rows + 1, std::vector<int>(cols + 1, INT_MAX));
        res[rows][cols - 1] = 1, res[rows - 1][cols] = 1;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                int min = std::min(res[i + 1][j], res[i][j + 1]);
                res[i][j] = std::max(min - dungeon[i][j], 1);
            }
        }
        return res[0][0];
    }
};


// @lc code=end

