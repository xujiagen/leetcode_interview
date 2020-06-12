/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
//#include <pair>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        /*
        std::vector<std::vector<int>> vecList;
        if (n <= 0) return vecList;
        vecList.reverse(n);
        for (int i = 0; i < n; i++) {
            vecList.push_back(std::vector<int>(n, 0));
        }
        */
        std::vector<std::vector<int>> vecList(n, std::vector<int>(n, 0));
        if (n <= 0) return vecList;
        std::vector<std::pair<int, int>> pairList;
        pairList.push_back(std::pair<int, int>(0, 1)); 
        pairList.push_back(std::pair<int, int>(1, 0));
        pairList.push_back(std::pair<int, int>(0, -1));
        pairList.push_back(std::pair<int, int>(-1, 0));
        int dir = 0;
        std::pair<int, int> position(0, 0);
        int leftX = 0, leftY = 0, rightX = n - 1, rightY = n - 1;
        int countValue = 1;
        while (countValue <= n * n) {
            /*
            std::cout << "position: " << position.first << " " << position.second
                << " left: " << leftX << " " << leftY << " right: " << rightX << " "
                << rightY << std::endl;
                */ 
            vecList[position.first][position.second] = countValue++;
            if (dir % 4 == 0 && position.second == rightY) {
                leftX++, dir++;
            }
            if (dir % 4 == 1 && position.first == rightX) {
                rightY--, dir++;
            }
            if (dir % 4 == 2 && position.second == leftY) {
                rightX--, dir++;
            }
            if (dir % 4 == 3 && position.first == leftX) {
                leftY++, dir++;
            }
            position.first += pairList[dir % 4].first;
            position.second += pairList[dir % 4].second;
        }
        return vecList;
        /*
        while (leftX <= rightX && leftY <= rightY) {
            
        }
        *.
        return vecList;
        */
    }
};

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

int main(int argc, char** argv) {
    auto vecList = Solution().generateMatrix(1);
    printList(vecList);
    return 0;
}
*/
// @lc code=end

