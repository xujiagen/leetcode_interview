/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.28%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 118.9K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
    void printList(const std::vector<std::vector<int>> &_VecList)
    {
        if (_VecList.size() < 1)
            std::cout << "nothing to print!" << std::endl;
        const int rows = _VecList.size();
        const int cols = _VecList[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << _VecList[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

public:
    int uniquePathsWithObstacles(vector<std::vector<int>> &obstacleGrid)
    {
        printList(obstacleGrid);
        if (obstacleGrid.size() < 1)
            return 0;
        const int rows = obstacleGrid.size() + 1;
        const int cols = obstacleGrid[0].size() + 1;
        std::vector<std::vector<int>> vecList(rows, std::vector<int>(cols, 0));
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (i == 1 && j == 1)
                {
                    vecList[i][j] = 1 - obstacleGrid[i - 1][j - 1];
                    continue;
                }
                if (obstacleGrid[i - 1][j - 1])
                    vecList[i][j] = 0;
                else
                    vecList[i][j] = vecList[i - 1][j] + vecList[i][j - 1];
            }
        }
        printList(vecList);
        return vecList[rows - 1][cols - 1];
    }
};
/*
int main()
{
    const int rows = 1;
    const int cols = 2;
    std::vector<std::vector<int>> vecList(rows, std::vector<int>(cols, 0));
    vecList[0][0] = 1;
    std::cout << Solution().uniquePathsWithObstacles(vecList) << std::endl;
    return 0;
}
*/
/*

void printList(const std::vector<std::vector<int>> &_VecList)
{
    if (_VecList.size() < 1)
        std::cout << "nothing to print!" << std::endl;
    const int rows = _VecList.size();
    const int cols = _VecList[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << _VecList[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.size() < 1)
            return 0;
        if (obstacleGrid[0][0] == 1)
            return 0;
        if (obstacleGrid.size() == 1)
        {
            for (int i = 0; i < obstacleGrid[0].size(); i++)
            {
                if (obstacleGrid[0][i] == 1)
                    return 0;
            }
            return 1;
        }
        const int rows = obstacleGrid.size();
        const int cols = obstacleGrid[0].size();
        if (cols == 1)
        {
            for (int i = 0; i < rows; i++)
                if (obstacleGrid[i][0] == 1)
                    return 0;
            return 1;
        }
        std::vector<std::vector<int>> vecList(rows, std::vector<int>(cols, 0));
        for (int i = 1; i < rows; i++)
            vecList[i][0] = 1 - obstacleGrid[i][0];
        for (int i = 1; i < cols; i++)
            vecList[0][i] = 1 - obstacleGrid[0][i];
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
                vecList[i][j] = obstacleGrid[i][j] == 1 ? 0 : vecList[i - 1][j] + vecList[i][j - 1];
        }
        //std::cout << "result map: " << std::endl;
        //printList(vecList);
        return vecList[rows - 1][cols - 1];
    }
};
*/
/*
int main(int argc, char **argv)
{
    const int rows = 3;
    const int cols = 3;
    std::vector<std::vector<int>> vecList(rows, std::vector<int>(cols, 0));
    vecList[1][1] = 1;
    std::cout << "obstacles: " << std::endl;
    //printList(vecList);
    std::cout << Solution().uniquePathsWithObstacles(vecList) << std::endl;
    return 0;
}
*/
// @lc code=end
