/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

/*
void printList(std::vector<int> _VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}
*/

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (m == 0) {
            std::copy(nums2.begin(), nums2.end(), nums1.begin());
            return;
        }
        if (n == 0) return;
        std::vector<int> vecList(m + n, 0);
        int firstLeft = 0, secondLeft = 0;
        int position = 0;
        while (firstLeft < m && secondLeft < n) {
            if (nums1[firstLeft] <= nums2[secondLeft]) {
                vecList[position++] = nums1[firstLeft];
                firstLeft++;
                continue;
            }
            if (nums2[secondLeft] <= nums1[firstLeft]) {
                vecList[position++] = nums2[secondLeft];
                secondLeft++;
                continue;
            }
        }
        if (firstLeft >= m) {
            std::copy(nums2.begin() + secondLeft, nums2.end(), vecList.begin() + position);
        } 
        if (secondLeft >= n) {
            std::copy(nums1.begin() + firstLeft, nums1.end(), vecList.begin() + position);
        }
        /*
        printList(nums1);
        printList(nums2);
        printList(vecList);
        */
        std::copy(vecList.begin(), vecList.end(), nums1.begin());
        return;
    }
};


/*
int main(int argc, char** argv) {
    std::vector<int> nums1 = {2, 0};
    std::vector<int> nums2 = {1};
    Solution().merge(nums1, 1, nums2, 1);
    printList(nums1);
    return 0;
}
*/
// @lc code=end

