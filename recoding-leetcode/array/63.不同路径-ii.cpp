/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <iostream>

/*
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() < 1) return 0;
        const int &rows = obstacleGrid.size();
        const int &cols = obstacleGrid[0].size();
        if (rows == 1) {
            for (int i = 0; i < cols; i++) if (obstacleGrid[0][i] == 0) return 0;
            else return 1;
        }
        if (cols == 1) {
            for (int i = 0; i < rows; i++) if (obstacleGrid[rows][0] == 0) return 0;
            else return 1;
        }
        std::vector<std::vector<int>> vecList(rows, std::vector<int>(cols, 1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) 
        }
    }
};
*/

/*
template <class T>
void printList(const typename std::vector<typename std::vector<T>> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        const std::vector<T> &vec = _VecList[i];
        for (int j = 0; j < vec.size(); j++) {
            std::cout << vec[j] << "\t";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}
*/

class Solution {
    public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        if (obstacleGrid.size() < 1) return 0;
        const int &rows = obstacleGrid.size();
        const int &cols = obstacleGrid[0].size();
        std::vector<std::vector<int>> vecList(rows + 1, std::vector<int>(cols + 1, 0));
        vecList[1][1] = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) {
                    if (obstacleGrid[i][j] == 1) return 0;
                    vecList[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    vecList[i + 1][j + 1] = 0;
                    continue;
                }
                vecList[i + 1][j + 1] = vecList[i][j + 1] + vecList[i + 1][j]; 
            }
        }
        //printList<int>(vecList);
        return vecList[rows][cols];
    }
};
/*
int main(int argc, char** argv) {
    std::vector<std::vector<int>> vecList(3, std::vector<int>(3, 0));
    vecList[1][1] = 1;
    std::cout << Solution().uniquePathsWithObstacles(vecList) << std::endl; 
    return 0;
}
*/
// @lc code=end

