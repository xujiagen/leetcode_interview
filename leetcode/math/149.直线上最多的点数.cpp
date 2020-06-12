/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (21.31%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 48.3K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 * 
 * 示例 1:
 * 
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int maxPoints(std::vector<std::vector<int>> &points)
    {
        if (points.size() < 3)
            return points.size();
        int max = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int tmpMax = 0;
            std::unordered_map<std::string, int> kValueCount;
            int duplication = 0;
            for (int j = i + 1; j < points.size(); j++)
            {
                int kValueUp = points[j][1] - points[i][1];
                int kValueDown = points[j][0] - points[i][0];
                if (!kValueDown && !kValueUp)
                {
                    duplication++;
                    continue;
                }
                int gcbValue = gcb(kValueDown, kValueUp);
                kValueUp = kValueUp / gcbValue;
                kValueDown = kValueDown / gcbValue;

                std::string tmpStr = std::to_string(kValueDown) + "@" + std::to_string(kValueUp);
                if (kValueCount.find(tmpStr) != kValueCount.end())
                {
                    kValueCount[tmpStr]++;
                }
                else
                {
                    kValueCount[tmpStr] = 1;
                }
                tmpMax = tmpMax > kValueCount[tmpStr] ? tmpMax : kValueCount[tmpStr];
            }
            max = max > tmpMax + duplication + 1 ? max : tmpMax + duplication + 1;
        }
        return max;
    }
    int gcb(int a, int b)
    {
        while (b != 0)
        {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
};
/*
int main(int argc, char **argv)
{
    //std::vector<std::vector<int>> vecList = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    std::vector<std::vector<int>> vecList = {{0, 0}, {1, 1}, {0, 0}};
    std::cout << Solution().maxPoints(vecList) << std::endl;
    return 0;
}
*/
// @lc code=end
