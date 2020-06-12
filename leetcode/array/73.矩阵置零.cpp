/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if (matrix.size() < 1) return;
        //std::set<std::pair<int, int>> pairSet;
        std::set<int> iSet, jSet;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    iSet.insert(i), jSet.insert(j);
                }
            }
        }
        const int &rows = matrix.size(), &cols = matrix[0].size();
        std::vector<int> iVec(iSet.begin(),  iSet.end()), jVec(jSet.begin(), jSet.end());
        for (int i = 0; i < iVec.size(); i++) {
            for (int j = 0; j < cols; j++) matrix[iVec[i]][j] = 0;
        }
        for (int i = 0; i < jVec.size(); i++) {
            for (int j = 0; j < rows; j++) matrix[j][jVec[i]] = 0; 
        }
        return;
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
    std::vector<std::vector<int>> vecList(3, std::vector<int>(3, 1));
    vecList[1][1] = 0;
    printList<int>(vecList);
    Solution().setZeroes(vecList);
    printList<int>(vecList);
    return 0;
}
*/
// @lc code=end

