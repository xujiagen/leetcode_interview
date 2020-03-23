/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> vecList;
        if (numRows == 0) return vecList;
        if (numRows == 1) {
            vecList.push_back({1});
            return vecList;
        }
        for (int i = 0; i < numRows; i++) {
            if (i == 0) vecList.push_back({1});
            if (i == 1) vecList.push_back({1, 1});
            if (i > 1) {
                std::vector<int> tmpList;
                tmpList.push_back(1);
                for (int j = 0; j < i - 1; j++) {
                    tmpList.push_back(vecList[i - 1][j] + vecList[i - 1][j + 1]);
                }
                tmpList.push_back(1);
                vecList.push_back(tmpList);
            }
        }
        return vecList;
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

int main() {
    auto vecList = Solution().generate(5);
    printList<int>(vecList);
    return 0;
}
*/
// @lc code=end

