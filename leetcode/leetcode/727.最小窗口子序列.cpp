#include <iostream>
#include <vector>
#include <array>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string S, std::string T) {
        int rows = T.size(), cols = S.size();
        std::vector<std::vector<std::array<int, 2>>> table(rows, std::vector<std::array<int, 2>>(cols, {-1, -1}));
        for (int i = 0; i < T.size(); i++) {
            for (int j = 0; j < S.size(); j++) {
                if (i == 0 && j == 0) {
                    if (T[i] == S[j]) table[i][j] = {j, j};
                    continue;
                }
                if (i == 0 && j > 0) {
                    if (T[i] == S[j]) table[i][j] = {j, j};
                    else if (table[i][j - 1][0] != -1) {
                        table[i][j] = {table[i][j - 1][0], table[i][j - 1][1] + 1};
                    } 
                    continue;
                }
                if (j >= i && S[j] == T[i]) {
                    if (table[i - 1][j - 1][0] != -1) table[i][j] = {table[i - 1][j - 1][0], table[i - 1][j - 1][1] + 1}; 
                } else if (j >= i && S[j] != T[i]) {
                    if (table[i][j - 1][0] != -1) table[i][j] = {table[i][j - 1][0], table[i][j - 1][1] + 1};
                }
            }
        }
        for (int i = 0; i < table.size(); i++) {
            for (int j = 0; j < table[0].size(); j++) {
                std::cout << table[i][j][0] << "," << table[i][j][1] << "  ";
            }
            std::cout << std::endl; 
        }
        int min = INT_MAX, left = 0, right = 0; 
        for (int i = 0; i < cols; i++) {
            if (table[rows - 1][i][0] != -1) {
                if (table[rows - 1][i][1] - table[rows - 1][i][0] < min) {
                    //min = table[rows - 1][i][1] - table[rows - 1][i][0];
                    left = min = table[rows - 1][i][0];
                    right = table[rows - 1][i][1];
                    min = right - left;
                }
            }
        }
        std::cout << "min: " << min << " left: " << left << " right: " << right << std::endl; 
        if (min != INT_MAX) return S.substr(left, right - left + 1);
        else return "";
    }
};

int main(int argc, char** argv) {
    std::string S("cnhczmccqouqadqtmjjzl"), T("mm");
    std::cout << Solution().minWindow(S, T) << std::endl; 
    return 0;
}