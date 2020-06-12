/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
/*
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int left = 1, right = 1;
        while (right < nums.size()) {
            std::cout << "left: " << left << " right: " << right << " left value: " << nums[left] << " right value: " << nums[right] << std::endl; 
            printList(nums);
            while (nums[right] == nums[right - 1]) right++;
            if (right >= nums.size()) break;
            std::swap(nums[left], nums[right]);
            left++, right++;
        }
        return left;
    }
    template <class T>
    void printList(const typename std::vector<T> &_VecList) {
        if (_VecList.size() < 1) return;
        for (int i = 0; i < _VecList.size(); i++) {
            std::cout << _VecList[i] << " ";
        }
        std::cout << std::endl; 
    }
};
*/

class Solution {
    public:
    int removeDuplicates(std::vector<int> &nums) {
        if (nums.size() < 2) return nums.size();
        std::set<int> setList(nums.begin(), nums.end());
        std::copy(setList.begin(), setList.end(), nums.begin());
        return setList.size();
    }
};
/*
template <class T>
void printList(const typename std::vector<T> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> nums= {0,0,1,1,1,2,2,3,3,4};
    printList(nums);
    std::cout << "left position: " << Solution().removeDuplicates(nums) << std::endl; 
    std::cout << "final list: " << std::endl; 
    printList(nums);
    return 0;
}
*/
// @lc code=end

