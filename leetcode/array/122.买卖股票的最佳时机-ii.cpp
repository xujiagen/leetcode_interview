/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int diffValue = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) 
                diffValue += prices[i] - prices[i - 1];
        }
        return diffValue;
    }
};
// @lc code=end

