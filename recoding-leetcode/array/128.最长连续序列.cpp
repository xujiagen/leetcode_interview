/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        std::set<int> setList(nums.begin(),  nums.end());
        int minPos = nums[0], maxPos = nums[0], maxCount = 1;
        int minValue = nums[0], maxValue = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int tmpCount = 0;
            //if (nums[i] < maxPos && nums[i] > minPos) continue;
            if (i > 0 && nums[i] > minValue && nums[i] < maxValue) continue;
            int checkNum = nums[i];
            int tmpMin = nums[i];
            while (setList.find(checkNum) != setList.end()) {
                tmpCount++;
                if (tmpCount > maxCount) {
                    maxCount = tmpCount;
                    minValue = tmpMin;
                    maxValue = checkNum;
                }
                checkNum++;
            }
        }
        return maxCount;
    }
};

int main(int argc, char** argv) {
    std::vector<int> vecList = {9000,8999,8998,8997,8996,8995,8994,8993,8992,8991,8990,8989,8988,8987,8986,8985,8984,8983,8982,8981,8980,8979,8978,8977,8976,8975,8974,8973,8972,8971,8970,8969,8968,8967,8966,8965,8964,8963,8962,8961,8960,8959,8958,8957,8956,8955,8954,8953,8952,8951,8950,8949,8948,8947,8946,8945,8944,8943,8942,8941,8940,8939,8938,8937,8936,8935,8934,8933,8932,8931,8930,8929,8928,8927,8926,8925,8924,8923,8922,8921,8920,8919,8918,8917,8916,8915,8914,8913,8912,8911,8910,8909,8908,8907,8906,8905,8904,8903,8902,8901,8900,8899,8898,8897,8896,8895,8894,8893,8892,8891,8890,8889,8888,8887,8886,8885,8884,8883,8882,8881,8880,8879,8878,8877,8876,8875,8874,8873,8872,8871,8870,8869,8868,8867,8866,8865,8864,8863,8862,8861,8860,8859};
    std::cout << Solution().longestConsecutive(vecList) << std::endl; 
    return 0;
}

// @lc code=end

