/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        if (triangle.size() < 1) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        std::vector<int> valueList(triangle[0].begin(), triangle[0].end());
        for (int i = 1; i < triangle.size(); i++) {
            std::vector<int> tmpList(triangle[i].begin(), triangle[i].end());
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) tmpList[0] = triangle[i][0] + valueList[0];
                else if (j == triangle[i].size() - 1) 
                    tmpList[j] = triangle[i][j] + valueList[triangle[i].size() - 2];
                else {
                    tmpList[j] = triangle[i][j] + std::min(valueList[j - 1], valueList[j]);
                } 
            }
            valueList = tmpList;
            /*
            for (int k = 0; k < valueList.size(); k++) {
                std::cout << valueList[k] << " ";
            }
            std::cout << std::endl;
            */
        }
        int tmpMin = valueList[0];
        for (int i = 1; i < valueList.size(); i++) {
            if (valueList[i] < tmpMin) tmpMin = valueList[i];
        }
        return tmpMin;
    }
};
/*
int main() {
    std::vector<std::vector<int>> vecList;
    vecList.push_back({2});
    vecList.push_back({3, 4});
    vecList.push_back({6, 5, 7});
    vecList.push_back({4, 1, 8, 3});
    std::cout << Solution().minimumTotal(vecList) << std::endl; 
    return 0;
}
*/

// @lc code=end

