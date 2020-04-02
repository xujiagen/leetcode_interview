/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        if (digits.size() < 1) return res;
        std::vector<std::string> vecStr;
        vecStr.push_back("abc");
        vecStr.push_back("def");
        vecStr.push_back("ghi");
        vecStr.push_back("jkl");
        vecStr.push_back("mno");
        vecStr.push_back("pqrs");
        vecStr.push_back("tuv");
        vecStr.push_back("wxyz");
        composeList(res, vecStr, 0, digits, "");
        return res;
    }

    void composeList(std::vector<std::string>&_Result, 
                     const std::vector<std::string> &_VecStr, 
                     int _Index, const std::string &_Str, std::string _TempStr) {
        if (_Index >= _Str.size()) {
            _Result.push_back(_TempStr);
            return;
        }
        int tmpOrder = _Str[_Index] - '2';
        const std::string &tmpStr = _VecStr[tmpOrder];
        for (int i = 0; i < tmpStr.size(); i++) {
            composeList(_Result, _VecStr, _Index + 1, _Str, _TempStr + tmpStr[i]);
        }
    }
};
/*
void printList(const std::vector<std::string> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::string str("5151");
    auto vecList = Solution().letterCombinations(str);
    printList(vecList);
    return 0;
}
*/
// @lc code=end