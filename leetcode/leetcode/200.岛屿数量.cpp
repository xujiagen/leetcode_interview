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

class Solution {
public:
    typedef std::vector<std::vector<bool>> vec_vec_bool;
    int numIslands(std::vector<std::vector<char>>& grid) {
        vec_vec_bool visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        std::queue<std::pair<int, int>> neighbors;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (visited[i][j]) continue;
                neighbors.push(std::make_pair(i, j));
                while (neighbors.size()) {

                }
            }
        }
    }
    
    bool isValid(int x, int y, std::vector<std::vector<char>>& grid) {
        if (x >= 0 && x <grid.size() && y >= 0 && y < grid[0].size()) return true;
        else return false;
    }
    void growUp(std::vector<std::vector<int>> &gird, 
                std::vector<std::vector<bool>> &visited, 
                std::queue<std::pair<int, int>> &neighbors) {
        while 
    }
};
// @lc code=end

