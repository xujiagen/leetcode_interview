/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.size() < 1)
            return 0;
        if (obstacleGrid.size() == 1)
        {
            if (obstacleGrid[0].size() == 1)
                return 1 - obstacleGrid[0][0];
            for (int i = 0; i < obstacleGrid[0].size(); i++)
            {
                if (obstacleGrid[0][i] == 1)
                    return 0;
            }
        }
        std::vector<std::vector<long>> vecList(obstacleGrid.size() + 1, std::vector<long>(obstacleGrid[0].size() + 1, 0));
        vecList[1][1] = 1 - obstacleGrid[0][0];
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (obstacleGrid[i][j] == 1)
                    vecList[i + 1][j + 1] = 0;
                else
                    vecList[i + 1][j + 1] = vecList[i][j + 1] + vecList[i + 1][j];
            }
        }
        return vecList[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};
// @lc code=end
