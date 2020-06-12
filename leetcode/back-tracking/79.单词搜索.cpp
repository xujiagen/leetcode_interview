/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (word.size() < 1) return true;
        if (word.size() > 0 && board.size() < 1) return false;
        dirList.push_back(std::pair<int, int>(1, 0));
        dirList.push_back(std::pair<int, int>(0, 1));
        dirList.push_back(std::pair<int, int>(-1, 0));
        dirList.push_back(std::pair<int, int>(0, -1));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[0]) continue;
                std::set<std::pair<int, int>> setPair;
                std::pair<int, int> position(i, j);
                setPair.insert(position);
                if (judgeList(board, word, setPair, 1, position)) return true;
                else continue;
            }
        }
        return false;
    }
    bool judgeList(const std::vector<std::vector<char>> &_VecList, 
                   std::string word, std::set<std::pair<int, int>> _Select, 
                   int _Index, std::pair<int, int> _Pos) {
        if (_Index >= word.size()) return true;
        for (int i = 0; i < dirList.size(); i++) {
            //std::cout << "_Pos.first: " << _Pos.first << " " << _Pos.second << std::endl; 
            std::pair<int, int> newPos(_Pos.first + dirList[i].first, _Pos.second + dirList[i].second);
            if (validPos(_VecList, newPos)) {
                if (word[_Index] == _VecList[newPos.first][newPos.second] && _Select.find(newPos) == _Select.end()) {
                    std::set<std::pair<int, int>> newSelect(_Select.begin(), _Select.end());
                    newSelect.insert(newPos);
                    if (judgeList(_VecList, word, newSelect, _Index + 1, newPos)) return true;
                    else continue;
                }
            }
        }
        return false;
    }
    bool validPos(const std::vector<std::vector<char>> &_VecList, std::pair<int, int> &_Position) {
        const int &rows = _VecList.size(), &cols = _VecList[0].size();
        if (_Position.first >= 0 && _Position.first < rows && _Position.second >= 0 && _Position.second < cols) return true;
        else return false;
    }
    std::vector<std::pair<int, int>> dirList;
};
/*
int main(int argc, char** argv) {
    std::vector<std::vector<char>> charList;
    charList.push_back({'A','B','C','E'});
    charList.push_back({'S','F','C','S'});
    charList.push_back({'A','D','E','E'});
    std::cout << Solution().exist(charList, "SEE") << std::endl; 
    return 0;
}
*/
// @lc code=end

