/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (42.16%)
 * Likes:    329
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 66.9K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [3,3,5,0,0,3,1,4]
 * 输出: 6
 * 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4,5]
 * 输出: 4
 * 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。   
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,6,4,3,1] 
 * 输出: 0 
 * 解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
/*
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        std::vector<int> diffList(prices.size() - 1, 0);
        for (int i = 1; i < prices.size(); i++)
            diffList[i - 1] = prices[i] - prices[i - 1];
        int left = 0;
        while (left < diffList.size() && diffList[left] < 0)
            left++;
        if (left == diffList.size())
            return 0;
        int sum = 0;
        int firstMax = 0, secondMax = 0;
        int tmpSum = 0;
        for (int i = left; i < diffList.size(); i++)
        {
            if (tmpSum == 0)
            {
                //tmpSum = diffList[i];
                tmpSum = tmpSum > diffList[i] ? tmpSum : diffList[i];
                continue;
            }
            else if (tmpSum > 0 && diffList[i] > 0)
            {
                tmpSum += diffList[i];
                continue;
            }
            else if (tmpSum > 0 && diffList[i] < 0)
            {
                if (tmpSum > firstMax)
                {
                    secondMax = firstMax;
                    firstMax = tmpSum;
                }
                else if (tmpSum > secondMax)
                {
                    secondMax = tmpSum;
                }
                //tmpSum = 0;
            }
        }
        if (tmpSum > 0 && tmpSum > firstMax)
        {
            secondMax = firstMax;
            firstMax = tmpSum;
        }
        else if (tmpSum > 0 && tmpSum > secondMax)
        {
            secondMax = tmpSum;
        }
        return firstMax + secondMax;
    }
};
*/

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        std::vector<int> p1(prices.size(), 0);
        std::vector<int> p2(prices.size(), 0);
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            minPrice = std::min(minPrice, prices[i]);
            p1[i] = std::max(p1[i - 1], prices[i] - minPrice);
        }
        int maxPrice = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            maxPrice = std::max(prices[i], maxPrice);
            p2[i] = std::max(p2[i + 1], maxPrice - prices[i]);
        }
        int max = 0;
        for (int i = 0; i < prices.size(); i++)
            max = max > p1[i] + p2[i] ? max : p1[i] + p2[i];
        return max;
    }
};
/*
int main(int argc, char **argv)
{
    //std::vector<int> vecList = {3, 2, 6, 5, 0, 3};
    std::vector<int> vecList = {1, 2, 3, 4, 5};
    std::cout << Solution().maxProfit(vecList) << std::endl;
    return 0;
}
*/
// @lc code=end
