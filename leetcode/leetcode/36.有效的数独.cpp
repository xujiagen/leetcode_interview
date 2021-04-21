/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        const int rows = board.size();
        if (rows != 9) return false;
        const int cols = board[0].size();
        if (cols != 9) return false;
        
        std::vector<std::unordered_set<char>> rowList(rows, std::unordered_set<char>());
        std::vector<std::unordered_set<char>> colList(cols, std::unordered_set<char>());
        std::vector<std::unordered_set<char>> boxList(9, std::unordered_set<char>());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '.') continue;
                
                if (rowList[i].find(board[i][j]) != rowList[i].end()) 
                    return false;
                else  
                    rowList[i].insert(board[i][j]);
                
                if (colList[j].find(board[i][j]) != colList[j].end()) 
                    return false;
                else 
                    colList[j].insert(board[i][j]);
                
                int index = 3 * (i / 3) + (j / 3);
                if (boxList[index].find(board[i][j]) != boxList[index].end()) 
                    return false;
                else 
                    boxList[index].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {

    //std::vector<std::vector<int>> vecList(6, std::vector<int>(6,5));
    // std::vector<std::vector<char>> charList = {
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'}};

    std::vector<std::vector<char>> charList = {
          {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    std::cout << Solution().isValidSudoku(charList) << std::endl;
    return 0;
}
// @lc code=end

