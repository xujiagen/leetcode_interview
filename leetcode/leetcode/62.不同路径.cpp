/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start

#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        std::vector<std::vector<int>> vecList(m, std::vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                vecList[i][j] = vecList[i - 1][j] + vecList[i][j - 1];
            }
        }
        return vecList[m - 1][n - 1];
    }
};
/*
int main(int argc, char** argv) {
    std::cout << "path count: " << Solution().uniquePaths(7, 3) << std::endl;
    return 0;
}
*/
// @lc code=end

