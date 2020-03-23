/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> vecList;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                vecList.push_back(std::vector<int>(nums.begin() + i, nums.begin() + j + 1));
            }
        }
        vecList.push_back({});
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
            std::cout << vec[j] << " ";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {1, 2, 3};
    auto vec = Solution().subsets(vecList);
    printList(vec);
    return 0;
}
*/
// @lc code=end

