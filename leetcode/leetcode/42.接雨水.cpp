/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

// class Solution {
// public:
//     int trap(std::vector<int>& height) {
//         if (height.size() < 2) return 0;
//         int left = 0;
//         while (height[left] <= 0) left++;
//         int right = left;
//         while (right < height.size() && height[right] > height[right + 1]) right++;
//         while (right < height.size() && height[right] < height[right + 1]) right++;
        
//     }
// };


class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.size() < 2) return 0;
        std::vector<int> arrayList(height.size(), 0);
        int privt = height[0];
        for (int i = 0; i < height.size(); i++) {
            privt = std::max(height[i], privt);
            arrayList[i] = privt;
        }

        privt = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; i--) {
            privt = std::max(height[i], privt);
            arrayList[i] = std::min(arrayList[i], std::max(height[i], privt));
        }
        int trapCount = 0;
        for (int i = 0; i < height.size(); i++) {
            trapCount += arrayList[i] - height[i];
        }

        return trapCount;
    }
};

int main(int argc, char** argv) {
    std::vector<int> inputList = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << Solution().trap(inputList) << std::endl;
    return 0;
}
// @lc code=end

