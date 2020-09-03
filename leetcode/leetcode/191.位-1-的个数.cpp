/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n) {
            if ((n & 0x01) == 1) sum++;
            n = n >> 1; 
        }
        return sum;
    }
};
/*
int main(int argc, char** argv) {
    std::cout << Solution().hammingWeight(11) << std::endl;
    return 0;
}
*/
// @lc code=end

