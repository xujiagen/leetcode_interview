/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (67.45%)
 * Likes:    430
 * Dislikes: 0
 * Total Accepted:    69.6K
 * Total Submissions: 102.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 
 * 将图像顺时针旋转 90 度。
 * 
 * 说明：
 * 
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 * 
 * 示例 1:
 * 
 * 给定 matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 给定 matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * 原地旋转输入矩阵，使其变为:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.size() < 2)
            return;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i + 1; j < matrix[0].size(); j++)
                std::swap(matrix[i][j], matrix[j][i]);
        }
        for (int i = 0; i < matrix.size(); i++)
            std::reverse(matrix[i].begin(), matrix[i].end());
        return;
    }
};
/*
void printList(const std::vector<std::vector<int>> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        for (int j = 0; j < _VecList[0].size(); j++)
            std::cout << _VecList[i][j] << "   ";
        std::cout << std::endl;
    }
    return;
}

int main(int argc, char **argv)
{
    std::vector<std::vector<int>> vecList = {{1, 2, 3, 4, 5},
                                             {6, 7, 8, 9, 10},
                                             {11, 12, 13, 14, 15},
                                             {16, 17, 18, 19, 20},
                                             {21, 22, 23, 24, 25}};
    printList(vecList);
    Solution().rotate(vecList);
    printList(vecList);
    return 0;
}
*/
// @lc code=end
