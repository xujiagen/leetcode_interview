/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (39.23%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    40.5K
 * Total Submissions: 103.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
/*
class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        int max = 0;
        if (heights.size() < 1)
            return max;
        for (int i = 0; i < heights.size(); i++)
            max = heights[i] > max ? heights[i] : max;
        for (int i = 0; i < heights.size(); i++)
        {
            int tmpMin = heights[i];
            for (int j = i - 1; j >= 0; j--)
            {
                tmpMin = tmpMin < heights[j] ? tmpMin : heights[j];
                max = tmpMin * (i - j + 1) > max ? tmpMin * (i - j + 1) : max;
            }
        }
        return max;
    }
};
*/

/*
class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        int ans = 0;
        std::vector<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.back()] > heights[i])
            {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = std::max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
*/
/*
int main(int argc, char **argv)
{
    std::vector<int> vecList = {2, 1, 5, 6, 2, 3};
    //std::cout << Solution().largestRectangleArea(vecList) << std::endl;
    std::cout << Solution().largestRectangleArea(vecList) << std::endl;
    return 0;
}
*/

/*
class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        if (heights.empty()) return 0;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left = i, right = i;
            while (left - 1>= 0 && heights[left - 1] >= heights[i]) left--;
            while (right + 1 < heights.size() && heights[right + 1] >= heights[i]) right++;
            maxArea = std::max(maxArea, heights[i] * (right - left + 1));
        }
        return maxArea;
    }
};
*/

class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        if (heights.empty()) return 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        std::stack<int> stackList;
        std::stack<int> valueList;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (stackList.size() < 1) {
                stackList.push(i);
                valueList.push(heights[i]);
                continue;
            }
            if (heights[stackList.top()] <= heights[i]) {
                stackList.push(i);
                valueList.push(heights[i]);
                continue;
            } else {
                while (stackList.size() && heights[stackList.top()] > heights[i]) {
                    //maxArea = std::max(maxArea, heights[stackList.top()] * (i - stackList.top()));
                    int stackLeft = stackList.top();
                    stackList.pop();
                    valueList.pop();
                    maxArea = std::max(maxArea, heights[stackLeft] * (i - stackList.top() - 1));
                }
                stackList.push(i);
                valueList.push(heights[i]);
            }
        }
        return maxArea;
    }
};

int main(int argc, char** argv) {
    std::vector<int> vecList = {2, 1, 5, 6, 2, 3};
    std::cout << Solution().largestRectangleArea(vecList) << std::endl;
    return 0;
}
// @lc code=end
