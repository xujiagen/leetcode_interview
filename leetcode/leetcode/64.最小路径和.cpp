/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.size() < 1) return 0;
        const int &rows = grid.size(), &cols = grid[0].size();
        std::vector<std::vector<int>> vecList(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) {
                    vecList[i][j] = grid[i][j];
                    continue;
                }
                if (i == 0) {
                    vecList[i][j] = grid[i][j] + vecList[i][j - 1];
                    continue;
                }
                if (j == 0) {
                    vecList[i][j] = grid[i][j] + vecList[i - 1][j];
                    continue;
                }
                vecList[i][j] = std::min(vecList[i - 1][j], vecList[i][j - 1]) + grid[i][j];
            }
        }
        return vecList[rows - 1][cols - 1];
    }
};
/*
int main(int argc, char** argv) {
    std::vector<std::vector<int>> vecList(3, std::vector<int>(3, 1));
    vecList[0][1] = 3;
    vecList[1][1] = 5;
    vecList[2][0] = 4;
    vecList[2][1] = 2;
    std::cout << Solution().minPathSum(vecList) << std::endl; 
    return 0;
}
*/
// @lc code=end

