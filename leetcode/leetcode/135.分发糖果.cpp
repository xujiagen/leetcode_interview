/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (42.46%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    20K
 * Total Submissions: 46.6K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 
 * 
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 
 * 示例 1:
 * 
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    int candy(std::vector<int> &ratings)
    {
        if (ratings.size() < 2) return ratings.size();
        std::vector<int> candyNum(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                candyNum[i + 1] = candyNum[i] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                if (candyNum[i - 1] > candyNum[i]) continue;
                else candyNum[i - 1] = candyNum[i] + 1; 
            }
        }
        int num = 0;
        for (int i = 0; i < candyNum.size(); i++) {
            num += candyNum[i];
        }
        return num;
    }
};
/*
int main(int argc, char** argv) {
    std::vector<int> ratings = {1, 2, 4, 3, 2, 1};
    std::cout << Solution().candy(ratings) << std::endl; 
    return 0;
}
*/
// @lc code=end
