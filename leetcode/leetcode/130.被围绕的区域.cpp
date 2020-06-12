/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (39.76%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 82.6K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

class Solution
{
public:
    void solve(std::vector<std::vector<char>> &board)
    {
        if (board.size() < 2 || board[0].size() < 2)
            return;
        std::vector<std::vector<bool>> visited(
            std::vector<std::vector<bool>>(board.size(),
                                           std::vector<bool>(board[0].size(), false)));
        std::queue<std::pair<int, int>> pairQueue;
        rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'O')
            {
                visited[i][0] = true;
                pairQueue.push(std::pair<int, int>(i, 0));
            }
            if (board[i][cols - 1] == 'O')
            {
                visited[i][cols - 1] = true;
                pairQueue.push(std::pair<int, int>(i, cols - 1));
            }
        }
        for (int i = 1; i < cols - 1; i++)
        {
            if (board[0][i] == 'O')
            {
                visited[0][i] = true;
                pairQueue.push(std::pair<int, int>(0, i));
            }
            if (board[rows - 1][i] == 'O')
            {
                visited[rows - 1][i] = true;
                pairQueue.push(std::pair<int, int>(rows - 1, i));
            }
        }
        while (pairQueue.size())
        {
            if (valid(pairQueue.front().first - 1, pairQueue.front().second, visited, board))
            {
                pairQueue.push(std::pair<int, int>(pairQueue.front().first - 1, pairQueue.front().second));
            }
            if (valid(pairQueue.front().first + 1, pairQueue.front().second, visited, board))
            {
                pairQueue.push(std::pair<int, int>(pairQueue.front().first + 1, pairQueue.front().second));
            }
            if (valid(pairQueue.front().first, pairQueue.front().second - 1, visited, board))
            {
                pairQueue.push(std::pair<int, int>(pairQueue.front().first, pairQueue.front().second - 1));
            }
            if (valid(pairQueue.front().first, pairQueue.front().second + 1, visited, board))
            {
                pairQueue.push(std::pair<int, int>(pairQueue.front().first, pairQueue.front().second + 1));
            }
            pairQueue.pop();
        }
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 1; j < cols - 1; j++)
            {
                if (visited[i][j] == false && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return;
    }

    bool valid(int x, int y, std::vector<std::vector<bool>> &_visited, std::vector<std::vector<char>> &_List)
    {
        if (x >= 0 && x < rows && y >= 0 && y < cols)
        {
            if (_visited[x][y] == false && _List[x][y] == 'O')
            {
                _visited[x][y] = true;
                return true;
            }
        }
        return false;
    }

    int rows;
    int cols;
};
/*
int main()
{
    std::vector<std::vector<char>> charList = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution().solve(charList);
    return 0;
}
*/
// @lc code=end
