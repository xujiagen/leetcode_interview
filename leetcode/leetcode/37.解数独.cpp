/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (60.48%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    22.9K
 * Total Submissions: 37.9K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * Note:
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
/*
void printCharList(const std::vector<std::vector<char>> &_CharList)
{
    if (_CharList.size() < 1)
        return;
    for (int i = 0; i < _CharList.size(); i++)
    {
        for (int j = 0; j < _CharList[0].size(); j++)
        {
            std::cout << _CharList[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
*/
class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        std::vector<std::pair<int, int>> queueList;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                    queueList.push_back(std::pair<int, int>(i, j));
            }
        }
        IterSuduku(queueList, board, 0);
    }
    bool IterSuduku(std::vector<std::pair<int, int>> &_QueueList,
                    std::vector<std::vector<char>> &_Board, int _Index)
    {
        //printCharList(_Board);
        if (_Index >= _QueueList.size())
            return true;
        std::set<char> charSet;
        const std::pair<int, int> &intPair = _QueueList[_Index];
        for (int i = 0; i < 9; i++)
        {
            if (_Board[intPair.first][i] != '.')
                charSet.insert(_Board[intPair.first][i]);
            if (_Board[i][intPair.second] != '.')
                charSet.insert(_Board[i][intPair.second]);
            nineBox(_Board, intPair, charSet);
        }
        for (int i = 0; i < 9; i++)
        {
            if (charSet.find('1' + i) != charSet.end())
                continue;
            _Board[intPair.first][intPair.second] = '1' + i;
            bool flag = IterSuduku(_QueueList, _Board, _Index + 1);
            if (flag)
                return true;
            else
            {
                _Board[intPair.first][intPair.second] = '.';
                continue;
            }
        }
        return false;
    }

    void nineBox(const std::vector<std::vector<char>> &_Board,
                 const std::pair<int, int> &_Pair,
                 std::set<char> &_PairSet)
    {
        const int &posX = _Pair.first / 3, &posY = _Pair.second / 3;
        for (int i = 3 * posX; i < 3 * posX + 3; i++)
        {
            for (int j = 3 * posY; j < 3 * posY + 3; j++)
            {
                if (_Board[i][j != '.'])
                    _PairSet.insert(_Board[i][j]);
            }
        }
    }
};

/*
int main(int argc, char **argv)
{
    std::vector<std::vector<char>> charList = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    printCharList(charList);
    Solution().solveSudoku(charList);
    printCharList(charList);
    return 0;
}
*/
// @lc code=end
