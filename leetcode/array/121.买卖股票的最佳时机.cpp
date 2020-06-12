/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int index = 0;
        while (index < prices.size() - 1 && prices[index] > prices[index + 1]) index++;
        if (index == prices.size() - 1) return 0;
        int tmpMin = prices[index];
        int tmpDiff =  0;
        for (int i = index + 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                tmpDiff = tmpDiff > prices[i] - tmpMin ? tmpDiff : prices[i] - tmpMin;
            } else if (prices[i] < prices[i - 1]) {
                if (tmpMin > prices[i]) tmpMin = prices[i];
            }
            //std::cout << "tmpDiff: " << tmpDiff << " tmpMin: " << tmpMin << std::endl;
        }
        return tmpDiff;
    }
};
/*
int main() {
    std::vector<int> vecList = {7,1,5,3,6,4};
    std::cout << Solution().maxProfit(vecList) << std::endl; 
    return 0;
}
*/
// @lc code=end

