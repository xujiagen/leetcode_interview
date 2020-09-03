/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void printList(const std::vector<std::vector<int>> &labels) {
    if (labels.size() < 1) return;
    for (std::size_t i = 0; i < labels.size(); i++) {
        for (std::size_t j = 0; j < labels[i].size(); j++) {
            std::cout << labels[i][j] << "\t";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        std::vector<std::vector<int>> labels(coins.size() + 1, std::vector<int>(amount + 1, INT_MAX));
        for (int i = 1; i < coins.size() + 1; i++) labels[i][0] = 0;
        //printList(labels);
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) labels[i + 1][j] = labels[i][j];
                else if (coins[i] == j) labels[i + 1][j] = 1;
                else {
                    int firstValue = labels[i + 1][j - coins[i]];
                    int secondValue = labels[i][j];
                    //std::cout << "i,j: " << i << " " << j << " firstV: " << firstValue << " secondV: " << secondValue << std::endl; 
                    if (firstValue == INT_MAX && secondValue == INT_MAX) labels[i + 1][j] = INT_MAX;
                    else if (firstValue == INT_MAX) labels[i + 1][j] = secondValue;
                    else if (secondValue == INT_MAX) labels[i + 1][j] = firstValue + 1;
                    else labels[i + 1][j] = std::min(firstValue + 1, secondValue);
                }
            }
        }
        //printList(labels);
        //return 0;
        if (labels.back().back() == INT_MAX) return -1;
        else return labels.back().back();
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> coins = {1, 2, 5};
    Solution().coinChange(coins, 11);
    return 0;
}
*/
// @lc code=end

