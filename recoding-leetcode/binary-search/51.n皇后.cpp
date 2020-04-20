/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.59%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    32.6K
 * Total Submissions: 47.4K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

void printList(const std::vector<std::string> &_StrList)
{
    if (_StrList.size() < 1)
        return;
    for (int i = 0; i < _StrList.size(); i++)
    {
        const std::string &_Str = _StrList[i];
        for (int i = 0; i < _Str.size(); i++)
        {
            std::cout << _Str[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> strList;
        strList.reserve(n);
        for (int i = 0; i < n; i++)
            strList.push_back(std::string(n, '0'));
        //printList(strList);
        IterVector(res, strList, 0, n);
        return res;
    }
    void IterVector(std::vector<std::vector<std::string>> &_Res, std::vector<std::string> &_VecList, int index, int n)
    {
        if (index == n)
        {
            _Res.push_back(_VecList);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            std::vector<std::string> copyList(_VecList.begin(), _VecList.end());
            std::string &str = copyList[index];
            std::pair<int, int> position;
            if (str[i] == '0')
            {
                position.first = index;
                position.second = i;
                str[i] = 'Q';
                deleteSpace(copyList, position, n);
                //std::cout << "deleteSpace: " << std::endl;
                //printList(copyList);
                IterVector(_Res, copyList, index + 1, n);
            }
        }
    }

    void deleteSpace(std::vector<std::string> &_StrList, std::pair<int, int> _Position, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (_StrList[_Position.first][i] == '0')
                _StrList[_Position.first][i] = '.';
            if (_StrList[i][_Position.second] == '0')
                _StrList[i][_Position.second] = '.';
        }
        std::pair<int, int> copyPosition = _Position;
        while (copyPosition.first - 1 >= 0 && copyPosition.second - 1 >= 0)
        {
            copyPosition.first--, copyPosition.second--;
            if (_StrList[copyPosition.first][copyPosition.second] == '0')
                _StrList[copyPosition.first][copyPosition.second] = '.';
        }
        copyPosition = _Position;
        while (copyPosition.first + 1 < n && copyPosition.second + 1 < n)
        {
            copyPosition.first++, copyPosition.second++;
            if (_StrList[copyPosition.first][copyPosition.second] == '0')
                _StrList[copyPosition.first][copyPosition.second] = '.';
        }
        copyPosition = _Position;
        while (copyPosition.first - 1 >= 0 && copyPosition.second + 1 < n)
        {
            copyPosition.first--, copyPosition.second++;
            if (_StrList[copyPosition.first][copyPosition.second] == '0')
                _StrList[copyPosition.first][copyPosition.second] = '.';
        }
        copyPosition = _Position;
        while (copyPosition.first + 1 < n && copyPosition.second - 1 >= 0)
        {
            copyPosition.first++, copyPosition.second--;
            if (_StrList[copyPosition.first][copyPosition.second] == '0')
                _StrList[copyPosition.first][copyPosition.second] = '.';
        }
    }
};
int main(int argc, char **argv)
{
    for (int i = 1; i < 9; i++)
    {
        std::vector<std::vector<std::string>> vecList = Solution().solveNQueens(i);
        std::cout << "n queen: " << i << " " << vecList.size() << std::endl;
    }
    /*
    for (int i = 0; i < vecList.size(); i++)
    {
        printList(vecList[i]);
    }
    */
    return 0;
}
// @lc code=end
