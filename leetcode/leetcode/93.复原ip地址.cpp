/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.19%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    33.9K
 * Total Submissions: 73.4K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

/*
class Solution
{
public:
    std::vector<std::string> restoreIpAddresses(std::string s)
    {
        std::vector<std::string> strList;
        Iter(s, 0, 0, "", strList);
        return strList;
    }
    void Iter(std::string str, int front, int Index, std::string res, std::vector<std::string> &_strList)
    {
        if (Index == 3)
        {
            if (str.size() - front > 3)
                return;
            int tmpValue = std::stoi(str.substr(front, str.size() - front));
            if (front < 1 || front > 255)
                return;
            if (tmpValue > 0 &&)
                res += str.substr(front, str.size() - front);
            _strList.push_back(res);
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            if (front + i + 1 >= str.size())
                continue;
            int val = std::stoi(str.substr(front, i + 1));
            if (val < 0 || val > 255)
                continue;
            std::string tmpStr(res);
            tmpStr = tmpStr + str.substr(front, i + 1) + ".";
            Iter(str, front + i + 1, Index + 1, tmpStr, _strList);
        }
    }
    std::vector<std::string> mStrList;
};
*/

class Solution {
    public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> strList;
        Iter(s, 0, 0, "", strList);
        return strList;
    }

    int NumSize(int _Num) {
        if (_Num >= 100) return 3;
        else if (_Num >= 10) return 2;
        else return 1;
    }
    void Iter(std::string _Str, int _Front, int _Index, 
              std::string _Res, std::vector<std::string> &_StrList) {
        if (_Index == 3) {
            if (_Str.size() - _Front > 3) return;
            int tmpValue = std::stoi(_Str.substr(_Front, _Str.size() - _Front));
            if (_Front < 1 || _Front > 255) return;
            if (tmpValue >= 0 && tmpValue <= 255 && _Str.size() - _Front == NumSize(tmpValue)) {
                _Res += _Str.substr(_Front, _Str.size() - _Front);
                _StrList.push_back(_Res);
                return;
            } 
        }
        for (int i = 0; i < 3; i++) {
            if (_Front + i + 1>= _Str.size()) continue;
            int val = std::stoi(_Str.substr(_Front, i + 1));
            if (val < 0 || val > 255 || NumSize(val) != i + 1) continue;
            std::string tmpStr(_Res);
            tmpStr = tmpStr + _Str.substr(_Front, i + 1) + ".";
            Iter(_Str, _Front + i + 1, _Index + 1, tmpStr, _StrList);
        }
    } 
};
/*
void printList(const std::vector<std::string> &_strList)
{
    if (_strList.size() < 1)
        return;
    for (int i = 0; i < _strList.size(); i++)
    {
        std::cout << _strList[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<std::string> strList = Solution().restoreIpAddresses("0000");
    printList(strList);
    return 0;
}

*/
// @lc code=end
