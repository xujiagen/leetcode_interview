/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
/*
class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, 
                                       std::vector<std::string>& words) {
        std::set<std::string> strSet(words.begin(), words.end());
        std::vector<std::string> tmpWords(strSet.begin(), strSet.end());
        //words = std::vector<std::string>(strSet.begin(), strSet.end());
        rows = board.size();
        cols = board[0].size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        std::vector<std::string> result;
        for (auto &str : tmpWords) {
            bool flag = false;
            if (str.size() < 1) continue;
            for (int i =0; i < rows; i++) {
                if (flag) break;
                for (int j = 0; j < cols; j++) {
                    //if (board[i][j] == str[0] && match(board, str, i, j, 1)) result.push_back(str);
                    if (flag) break;
                    if (board[i][j] == str[0]) {
                        visited[i][j] = true;
                        if (match(board, visited, str, i, j, 1)) {
                            result.push_back(str);
                            flag = true;
                        }
                        visited[i][j] = false;
                    } 
                }
            }
        }
        return result;
    }
    bool isValid(int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) return false;
        else return true;
    }

    bool match(std::vector<std::vector<char>> &board, std::vector<std::vector<bool>> &visited, 
               std::string &words, int x, int y, int index) {
        if (index >= words.size()) return true;
        if (isValid(x - 1, y) && (board[x - 1][y] == words[index] && !visited[x - 1][y])) {
            visited[x - 1][y] = true;
            if(match(board, visited, words, x -1, y, index+1)) {
                visited[x - 1][y] = false;
                return true;
            }
            visited[x - 1][y] = false;
        }
        if (isValid(x + 1, y) && (board[x + 1][y] == words[index] && !visited[x + 1][y])) {
            visited[x + 1][y] = true;
            if(match(board, visited, words, x + 1, y, index+1)) {
                visited[x + 1][y] = false;
                return true;
            }
            visited[x + 1][y] = false;
        }
        if (isValid(x, y - 1) && (board[x][y - 1] == words[index] && !visited[x][y - 1])) {
            visited[x][y - 1] = true;
            if(match(board, visited, words, x, y - 1, index+1)) {
                visited[x][y - 1] = false;
                return true;
            }
            visited[x][y - 1] = false;
        }
        if (isValid(x, y + 1) && (board[x][y + 1] == words[index] && !visited[x][y + 1])) {
            visited[x][y + 1] = true;
            if(match(board, visited, words, x, y + 1, index+1)) {
                visited[x][y + 1] = false;
                return true;
            }
            visited[x][y + 1] = false;

        }
        return false; 
    }
private:
    int rows;
    int cols;
};
*/

/*
class TrieNode {
public:
    std::string word = "";
    std::vector<TrieNode*> nodes;
    TrieNode() : nodes(26, 0) {}
};

class Solution {
    int rows, cols;
    std::vector<std::string> res;
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if (rows == 0 || cols == 0) return res;

        TrieNode* root = new TrieNode();
        for (std::string word : words) {
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); i++) {
                int idx = word[i] - 'a';
                if (cur->nodes[idx] == 0) cur->nodes[idx] = new TrieNode();
                cur = cur->nodes[idx];
            }
            cur->word = word;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, root, i, j);
            }
        }
        return res;
    }

    void dfs(std::vector<std::vector<char>> &board, TrieNode* root, int x, int y) {
        char c = board[x][y];
        if (c == '.' || root->nodes[c - 'a'] == 0) return;
        root = root->nodes[c - 'a'];
        if (root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }
        board[x][y] = '.';
        if (x > 0) dfs(board, root, x - 1, y);
        if (y > 0) dfs(board,  root, x, y - 1);
        if (x + 1 < rows) dfs(board, root, x + 1, y);
        if (y + 1 < cols) dfs(board, root, x, y + 1);
        board[x][y] = c;
    }
};
*/

struct TrieNode {
    std::string word;
    std::vector<TrieNode*> nodes;
    TrieNode() : nodes(26, 0) {}
};

class Solution {
    int rows, cols;
    std::vector<std::string> res;
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, 
                                       std::vector<std::string> &words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if (rows == 0 || cols == 0) return res;

        TrieNode *root = new TrieNode();
        for (auto word : words) {
            if (word.size() < 1) continue;
            TrieNode *cur = root;
            for (int i = 0; i < word.size(); i++) {
                if (cur->nodes[word[i] - 'a']) cur = cur->nodes[word[i] - 'a'];
                else {
                    cur->nodes[word[i] - 'a'] = new TrieNode();
                    cur = cur->nodes[word[i] - 'a'];
                }
            }
            cur->word = word;
        }

        //dfs
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, root, i, j);
            }
        }
        return res;
    }
    void dfs(std::vector<std::vector<char>> &board, TrieNode* root, int x, int y) {
        if (board[x][y] == '.' || root->nodes[board[x][y] - 'a'] == 0) return;
        root = root->nodes[board[x][y] - 'a'];
        if (root->word != "") {
            res.push_back(root->word);
            root->word = "";
            return;
        }
        char c = board[x][y];
        board[x][y] = '.';
        if (x > 0) dfs(board, root, x - 1, y);
        if (y > 0) dfs(board, root, x, y - 1);
        if (x + 1 < rows) dfs(board, root, x + 1, y);
        if (y + 1 < cols) dfs(board, root, x, y + 1);
        board[x][y] = c;
    }
    /*
    void dfs(std::vector<std::vector<char>>& board, TrieNode* root, int x, int y){
        char c = board[x][y];
        //递归边界
        if(c=='.' || root->nodes[c-'a']==0) return;
        root = root->nodes[c-'a'];
        if(root->word!=""){
            res.push_back(root->word);
            root->word = "";
        }
        
        board[x][y] = '.';
        if(x>0) dfs(board, root, x-1, y);
        if(y>0) dfs(board, root, x, y-1);
        if(x+1<rows) dfs(board, root, x+1, y);
        if(y+1<cols) dfs(board, root, x, y+1);
        board[x][y] = c;
    } 
    */
};
void printStrList(const std::vector<std::string> &strList) {
    if (strList.size() < 1) return;
    for (auto &str : strList) std::cout << str << std::endl;
}

int main(int argc, char** argv) {
    std::vector<std::string> words = {"oath","pea","eat","rain"};
    std::vector<std::vector<char>> board = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
    //std::vector<std::string> words = {"aaa"};
    //std::vector<std::vector<char>> board = {{'a', 'a'}};
    auto res = Solution().findWords(board, words);
    printStrList(res);
    return 0;
}
// @lc code=end

