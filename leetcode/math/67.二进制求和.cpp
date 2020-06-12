/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.29%)
 * Likes:    335
 * Dislikes: 0
 * Total Accepted:    73.9K
 * Total Submissions: 141.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        if (a.size() < b.size())
            return addBinary(b, a);
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        for (int i = 0; i < b.size(); i++)
        {
            a[i] = a[i] + (b[i] - '0');
        }
        int addUp = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int tmpAdd = (a[i] - '0' + addUp) / 2;
            a[i] = '0' + (a[i] - '0' + addUp) % 2;
            addUp = tmpAdd;
        }
        if (addUp == 1)
        {
            a = a + "1";
        }
        if (addUp == 2)
        {
            a = a + "01";
        }
        std::reverse(a.begin(), a.end());
        return a;
    }
};
/*
int main()
{
    std::cout << Solution().addBinary("1010", "1011") << std::endl;
    return 0;
}
*/
// @lc code=end
