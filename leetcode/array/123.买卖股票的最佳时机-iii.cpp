/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int left = 0;
        while (left < prices.size() - 1 && prices[left] >= prices[left + 1]) 
            left++;
        if (left >= prices.size() - 1) return 0;
        int diffCount = 0;
        for (int i = left + 1; i < prices.size(); i++) {
            if (prices[i] > prices[i + 1])
        }
    }
};
// @lc code=end

