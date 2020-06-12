/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (44.07%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    16.4K
 * Total Submissions: 37.2K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix)
    {
        if (matrix.size() < 1)
            return 0;
        if (matrix.size() == 1 && matrix[0].size() == 1)
        {
            if (matrix[0][0] == '1')
                return 1;
            else
                return 0;
        }
        const int &rows = matrix.size(), &cols = matrix[0].size();
        std::vector<std::vector<std::vector<int>>>
            vecList(rows, std::vector<std::vector<int>>(cols, {0, 0, 0}));
        int maxArea = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 && j == 0)
                    {
                        vecList[i][j] = {1, 1, 1};
                        if (vecList[i][j][2] > maxArea)
                            maxArea = vecList[i][j][2];
                        continue;
                    }
                    if (i == 0)
                    {
                        vecList[i][j] = {vecList[i][j - 1][0] + 1, 1, vecList[i][j - 1][0] + 1};
                        if (vecList[i][j][2] > maxArea)
                            maxArea = vecList[i][j][2];
                        continue;
                    }
                    if (j == 0)
                    {
                        vecList[i][j] = {1, vecList[i - 1][j][1] + 1, vecList[i - 1][j][1] + 1};
                        if (vecList[i][j][2] > maxArea)
                            maxArea = vecList[i][j][2];
                        continue;
                    }
                    vecList[i][j][0] = vecList[i][j - 1][0] + 1;
                    vecList[i][j][1] = vecList[i - 1][j][1] + 1;
                    int minCols = vecList[i][j][0], tmpMax = 0;
                    for (int k = 0; k < vecList[i][j][1]; k++)
                    {
                        if (vecList[i - k][j][0] < minCols)
                            minCols = vecList[i - k][j][0];
                        if (minCols * (k + 1) > tmpMax)
                            tmpMax = minCols * (k + 1);
                    }
                    //vecList[i][j][2] = minCols * vecList[i][j][1];
                    vecList[i][j][2] = tmpMax;
                    if (vecList[i][j][2] > maxArea)
                        maxArea = vecList[i][j][2];
                }
            }
        }
        /*
        for (int i = 0; i < vecList.size(); i++)
        {
            for (int j = 0; j < vecList[0].size(); j++)
            {
                const std::vector<int> &vec = vecList[i][j];
                std::cout << "(" << vec[0] << "," << vec[1] << "," << vec[2] << ")"
                          << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        */
        return maxArea;
    }
};
/*
int main(int argc, char **argv)
{
    std::vector<std::vector<char>> charList(5, std::vector<char>(5, '1'));
    charList[0][0] = '0';
    charList[0][3] = '0';
    charList[1][2] = '0';
    charList[1][4] = '0';
    charList[2][0] = '0';
    charList[2][4] = '0';
    charList[3][4] = '0';
    charList.push_back({'0', '0', '0', '0', '0'});
    std::cout << Solution().maximalRectangle(charList) << std::endl;
    return 0;
}
*/
// @lc code=end
