/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        const int rows = matrix.size();
        if (rows < 1) return {};
        const int cols = matrix[0].size();
        if (cols < 1) return {};
        std::vector<std::vector<int>> dirList = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int leftX = 0, leftY = 0, rightX = rows, rightY = cols;
        int dirIndex = 0;
        int positionX = 0, positionY = 0;
        std::vector<int> result;
        while (leftX <= rightX && leftY <= rightY) {
            std::cout << matrix[positionX][positionY] << " ";
            result.push_back(matrix[positionX][positionY]);
            if (dirIndex == 0) {
                if (positionY + dirList[dirIndex][1] >= rightY) {
                    dirIndex++;
                    leftY++;
                } else {
                    positionY += dirList[dirIndex][1];
                    continue;
                }
            }
            if (dirIndex == 1) {
                if (positionX + dirList[dirIndex][0] >= rightX) {
                    dirIndex++;
                    rightX--;
                } else {
                    positionX += dirList[dirIndex][0];
                    continue;
                }
            }
            if (dirIndex == 2) {
                if (positionY + dirList[dirIndex][1] <= leftY) {
                    dirIndex++;
                    rightY--;
                } else {
                    positionY += dirList[dirIndex][1];
                    continue;
                }
            }
            if (dirIndex == 3) {
                if (positionX + dirList[dirIndex][0] < leftX) {
                    dirIndex = 0;
                    leftY++;
                } else {
                    positionX += dirList[dirIndex][0];
                    continue;
                }
            }
        }
        std::cout << std::endl;
        return result;
    }
};

template <class T>
void printList(const std::vector<T> &_List) {
    for (int i = 0; i < _List.size(); i++) {
        std::cout << _List[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    std::vector<std::vector<int>> inputList = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} 
    };
    std::vector<int> result = Solution().spiralOrder(inputList);
    printList(result);
    return 0;
}
// @lc code=end

