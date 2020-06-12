/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.size() < 1) return 0;
        if (nums.size() == 1  && nums[0] == val) return 0;
        else if (nums.size() == 1) return 1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] != val) left++;
            while (left < right && nums[right] == val) right--;
            std::swap(nums[left], nums[right]);
        }
        if (left < nums.size() && nums[left] != val) return left + 1;
        else return left;
        //上面这两行主要是判断left所在的元素最后在结束的时候是不是target, 对于是否会存在两种结果
    }
};

template <class T>
void printList(const typename std::vector<T> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {3, 3};
    std::cout << "position: " << Solution().removeElement(vecList, 3) << std::endl;
    printList<int>(vecList);
    return 0;
}
// @lc code=end

