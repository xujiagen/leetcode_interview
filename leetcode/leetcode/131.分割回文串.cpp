/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (66.47%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 40.3K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
/*
class Solution
{
public:
    std::vector<std::vector<std::string>> res;
    int size;
    bool check(const std::string &_S, int i, int j) {
        if (i > j) return true;
        else if (_S[i] == _S[j]) return check(_S, i + 1, j - 1);
        else return false;
    }
    void backTracking(const std::string &_S,  int ps, std::vector<std::string> &_Temp) {
        if (ps >= size) {
            res.push_back(_Temp);
            return;
        }
        for (int i = ps; i < size; i++) {
            if (check(_S, ps, i)) {
                _Temp.push_back(_S.substr(ps, i - ps + 1));
                backTracking(_S, i + 1, _Temp);
                _Temp.pop_back();
            }
        }
    }
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        size = s.size();
        if (size == 0) return res;
        std::vector<std::string> temp;
        backTracking(s, 0, temp);
        return res;
    }
};
*/

class Solution {
    typedef std::vector<std::vector<std::string>> vec_vec_str;
    vec_vec_str res;
    int size;
    bool check(const std::string &_Str, int i, int j) {
        if (i > j) return true;
        else if (_Str[i] == _Str[j]) return check(_Str, i + 1, j - 1);
        else return false;
    }
    void backTracking(std::string &_Str, int _Index, std::vector<std::string>& _StrList) {
        if (_Index >= size) {
            res.push_back(_StrList);
            return;
        }
        for (int i = _Index; i < size; i++) {
            if (check(_Str, _Index, i)) {
                _StrList.push_back(_Str.substr(_Index, i - _Index + 1));
                backTracking(_Str, i + 1, _StrList);
                _StrList.pop_back();
            } 
        }
    }
    public:
    vec_vec_str partition(std::string s) {
        size = s.size();
        std::vector<std::string> temp;
        if (size == 0) return res;
        else backTracking(s, 0, temp);
        return res;
    }
};
void printList(const std::vector<std::vector<std::string>> &_Res) {
    if (_Res.size() < 1) return;
    for (int i = 0; i <  _Res.size(); i++) {
        for (int j = 0; j < _Res[i].size(); j++) {
            std::cout << _Res[i][j] << " ";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}
/*
int main(int argc, char **argv) {
    std::string str("aab");
    std::vector<std::vector<std::string>> res = Solution().partition(str);
    printList(res);
    return 0;
}
*/
// @lc code=end
