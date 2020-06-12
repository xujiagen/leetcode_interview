/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> vecList;
        if (nums.size() < 2) return vecList;
        std::map<int, int> valueIndex;
        for (int i = 0; i < nums.size(); i++) {
            valueIndex[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (valueIndex.find(target - nums[i]) != valueIndex.end() && valueIndex[target - nums[i]] != i) {
                vecList.push_back(i);
                vecList.push_back(valueIndex[target - nums[i]]);
                return vecList;
            }
        }
        return vecList;
    }
};

template <class T>
void printList(typename std::vector<int> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::vector<int> result = Solution().twoSum(vecList, 17);
    printList<int>(result);
    return 0;
}
// @lc code=end

