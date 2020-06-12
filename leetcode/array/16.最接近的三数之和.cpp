/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        std::sort(nums.begin(), nums.end());
        //printList(nums);
        int minDiff = INT_MAX;
        int closeSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target / 3) break;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                //std::cout << "left: " << left << " right: " << right << " i: " << i << std::endl; 
                //std::cout << "left nums: " << nums[left] << " right nums: " << nums[right] << " i nums: " << nums[i] << std::endl;
                int diff = nums[i] + nums[left] + nums[right] - target;
                //diff = diff > 0 ? diff : -diff;
                if (std::abs(diff) < minDiff) {
                    minDiff = std::abs(diff);
                    closeSum = nums[i] + nums[left] + nums[right];
                }
                if (diff == 0) return target;
                else if (diff > 0) right--;
                else if (diff < 0) left++;
            }
        }
        return closeSum;
    }
    /*
    void printList(const std::vector<int> &_VecList) {
        if (_VecList.size() < 1) return;
        for (int i = 0; i < _VecList.size(); i++) {
            std::cout << _VecList[i] << " ";
        }
        std::cout << std::endl; 
    }
    */
};

/*
int main(int argc, char** argv) {
    int vec[] = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::cout << Solution().threeSumClosest(vecList, -52) << std::endl;
    return 0;
}
*/

// @lc code=end

