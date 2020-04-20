/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (77.72%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    20.4K
 * Total Submissions: 26.1K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    int totalNQueens(int n)
    {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> strList;
        strList.reserve(n);
        for (int i = 0; i < n; i++)
            strList.push_back(std::string(n, '0'));
        //printList(strList);
        IterVector(res, strList, 0, n);
        return res.size();
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
// @lc code=end
