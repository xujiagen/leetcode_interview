/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() < 1) return false;
        int positionX = 0, positionY = matrix[0].size() - 1;
        while (positionX >= 0 && positionX < matrix.size() && positionY >= 0  && positionY <= matrix[0].size() - 1) {
            //std::cout << "position value: " << matrix[positionX][positionY] << std::endl; 
            if (target == matrix[positionX][positionY]) return true;
            else if (target > matrix[positionX][positionY]) positionX++;
            else if (target < matrix[positionX][positionY]) positionY--;
        }
        return false;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<std::vector<int>> vecList;
    vecList.push_back({1, 3, 5, 7});
    vecList.push_back({10, 11, 16, 20});
    vecList.push_back({23, 30, 34, 50});
    std::cout << Solution().searchMatrix(vecList, 3) << std::endl;
    return 0;
}
*/
// @lc code=end

