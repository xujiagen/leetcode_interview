/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

/*
bool pairSort (std::vector<int> &_Left, std::vector<int> &_Right) {
    if (_Right[0] < _Left[0]) return false;
    else return true;
}
*/

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        auto pairSort = [](std::vector<int> _Left, std::vector<int> _Right) {
            if (_Right[0] < _Left[0]) return false;
            else return true;
        };
        if (intervals.size() <= 1) return intervals;
        std::vector<std::vector<int>> vecList;
        std::sort(intervals.begin(), intervals.end(), pairSort);
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 0; i < intervals.size() - 1; i++) {
            //std::cout << "left: " << left << " right: " << right << std::endl;
            if (i < intervals.size() - 1 && right >= intervals[i + 1][0]) {
                right = std::max(right, intervals[i + 1][1]);
            } else {
                vecList.push_back({left, right});
                left = intervals[i + 1][0], right = intervals[i + 1][1];
            }
            
        }
        vecList.push_back({left, right});
        return vecList;
    }
};

/*
template <class T>
void printList(const typename std::vector<typename std::vector<T>> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        const std::vector<int> &vec = _VecList[i];
        for (int j = 0; j < vec.size(); j++) {
            std::cout << vec[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<std::vector<int>> vecList;
    vecList.push_back({1, 3});
    vecList.push_back({2, 6});
    vecList.push_back({8, 10});
    vecList.push_back({15, 18});
    printList<int>(vecList);
    std::vector<std::vector<int>> vec = Solution().merge(vecList);
    std::cout << "vecList size: " << vec.size() << std::endl; 
    printList<int>(vec);
    return 0;
}
*/

// @lc code=end

