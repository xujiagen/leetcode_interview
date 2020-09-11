/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;
        std::vector<std::vector<bool>> gridLabel(std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(), false)));
        islandCount = 0;
        rows = grid.size();
        cols = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (gridLabel[i][j]) continue;
                if (grid[i][j] == '0') {
                    gridLabel[i][j] = true;
                    continue;
                } else {
                    gridLabel[i][j] = true;
                    std::queue<std::pair<int, int>> positionQueue;
                    positionQueue.push(std::pair<int, int>(i, j));
                    islandCount++;
                    grow(grid, gridLabel, positionQueue);
                }
            }
        }
        return islandCount;
    }

    bool isValid(int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) return false;
        else return true;
    }

    void grow(std::vector<std::vector<char>> &grid, 
              std::vector<std::vector<bool>> &gridLabel, 
              std::queue<std::pair<int, int>> &positionQueue) {
        if (positionQueue.size() < 1) return;
        std::pair<int, int> &position = positionQueue.front();
        if (isValid(position.first - 1, position.second) && !gridLabel[position.first - 1][position.second] && grid[position.first - 1][position.second] == '1') {
            positionQueue.push(std::pair<int, int>(position.first - 1, position.second));
            gridLabel[position.first - 1][position.second] = true;
        }
        if (isValid(position.first + 1, position.second) && !gridLabel[position.first + 1][position.second] && grid[position.first + 1][position.second] == '1') {
            positionQueue.push(std::pair<int, int>(position.first + 1, position.second));
            gridLabel[position.first + 1][position.second] = true;
        }
        if (isValid(position.first, position.second - 1) && !gridLabel[position.first][position.second - 1] && grid[position.first][position.second - 1] == '1') {
            positionQueue.push(std::pair<int, int>(position.first, position.second - 1));
            gridLabel[position.first][position.second - 1] = true;
        }
        if (isValid(position.first, position.second + 1) && !gridLabel[position.first][position.second + 1] && grid[position.first][position.second + 1] == '1') {
            positionQueue.push(std::pair<int, int>(position.first, position.second + 1));
            gridLabel[position.first][position.second + 1] = true;
        }
        positionQueue.pop();
        grow(grid, gridLabel, positionQueue);
    }

public:
    int islandCount;
    int rows;
    int cols;
};
/*
int main(int argc, char** argv) {
    std::vector<std::vector<char>> grid;

    //grid.push_back({'1','1','1','1','0'});
    //grid.push_back({'1','1','0','1','0'});
    //grid.push_back({'1','1','0','0','0'});
    //grid.push_back({'0','0','0','0','0'});

    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'0','0','1','0','0'});
    grid.push_back({'0','0','0','1','1'});
    std::cout << Solution().numIslands(grid) << std::endl; 
    return 0;
}
*/
// @lc code=end

