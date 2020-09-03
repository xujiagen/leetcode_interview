/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.29%)
 * Likes:    318
 * Dislikes: 0
 * Total Accepted:    39.3K
 * Total Submissions: 168.5K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
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
    int numDecodings(std::string s)
    {
        if (s.size() < 2)
            return s.size();
        int possible = 0;
        IterFind(s, 0, possible);
        return possible;
    }
    void IterFind(const std::string _Str, int _Index, int &_Possible)
    {
        if (_Index >= _Str.size())
            return;
        if (_Index == _Str.size() - 1)
        {
            _Possible++;
            return;
        }
        if (std::stoi(_Str.substr(_Index, 2)) <= 26)
        {
            _Possible += 2;
            IterFind(_Str, _Index + 1, _Possible);
            IterFind(_Str, _Index + 2, _Possible);
        }
        else
        {
            _Possible += 1;
            IterFind(_Str, _Index + 1, _Possible);
        }
    }
};
*/

/*
class Solution
{
public:
    int numDecodings(std::string s)
    {
        if (s.size() < 1)
            return 0;
        if (s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s.substr(i, 2) == "00")
                return 0;
            else if (s.substr(i + 1, 1) == "0" && std::stoi(s.substr(i, 1)) > 2)
                return 0;
        }
        return decodingsCount(s, s.size() - 1);
    }
    int decodingsCount(std::string s, int _Index)
    {
        if (_Index == 0)
            return 1;
        if (_Index == 1)
        {
            if (std::stoi(s.substr(0, 2)) > 26 || std::stoi(s.substr(1, 1)) == 0)
                return 1;
            else
                return 2;
        }
        if (std::stoi(s.substr(_Index - 1, 2)) > 26 || std::stoi(s.substr(_Index - 1, 1)) == 0)
            return decodingsCount(s, _Index - 1);
        else if (std::stoi(s.substr(_Index, 1)) == 0)
            return decodingsCount(s, _Index - 2);
        else
            return decodingsCount(s, _Index - 1) + decodingsCount(s, _Index - 2);
    }
};
*/
/*
class Solution
{
public:
    int numDecodings(std::string s)
    {
        if (s.size() < 1)
            return 0;
        if (s[0] == '0')
            return 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s.substr(i, 2) == "00")
                return 0;
            if (s.substr(i + 1, 1) == "0" && std::stoi(s.substr(i, 1)) > 2)
                return 0;
        }
        std::vector<int> vecList(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
            {
                vecList[i] = 1;
                continue;
            }
            if (i == 1)
            {
                if (s[i] == '0')
                {
                    vecList[i] = 1;
                    vecList[i - 1] = 0;
                }
                else if (std::stoi(s.substr(i - 1, 2)) > 26)
                    vecList[i] = 1;
                else
                    vecList[i] = 2;
                continue;
            }
            if (s[i] == '0')
            {
                vecList[i] = vecList[i - 2];
                vecList[i - 1] = 0;
            }
            else if (std::stoi(s.substr(i - 1, 2)) > 26)
                vecList[i] = vecList[i - 1];
            else
                vecList[i] = vecList[i - 1] + vecList[i - 2];
        }
        return vecList[s.size() - 1];
    }
};
*/
class Solution {
    public:
    int numDecodings(std::string s) {
        if (s.size() < 1) return 0;
        for (int i = 0; i < s.size() + 1; ++i) if (s.substr(i, 2) == "00") return 0;
        if (s[0] == '0') return 0;
        std::vector<int> labels(s.size() + 1, 0);
        labels[0] = 1;
        labels[1] = 1;
        int first = 0, second = 0;
        for (int i = 1; i < s.size(); i++) {
            first = 0, second = 0;
            int singV = s[i] - '0', douV = std::stoi(s.substr(i - 1, 2));
            if (singV > 0 && singV < 10 && douV > 9 && douV < 27) labels[i + 1] = labels[i] + labels[i - 1];
            else if (singV > 0 && singV < 10 && (douV < 10 || douV > 26)) labels[i + 1] = labels[i];
            else if (singV == 0 && douV > 9 && douV < 27) labels[i + 1] = labels[i - 1];
            else return 0;
        }
        auto printValue = [](int &value) {std::cout << value << " ";};
        std::for_each(labels.begin(), labels.end(), printValue);
        std::cout << std::endl; 
        return labels.back();
    }
};
/*
int main(int argc, char **argv)
{
    std::string str("99");
    std::cout << Solution().numDecodings(str) << std::endl;
    return 0;
}
*/
// @lc code=end
