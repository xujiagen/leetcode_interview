/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/*
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        if (word2.size() == 0) return word1.size();
        if (word1.size() == 0) return word2.size();
        std::vector<std::vector<int>> vecList(word2.size()+1, std::vector<int>(word1.size() + 1, 0));
        for (int i = 0; i < word1.size(); i++) {
            vecList[0][i + 1] = i + 1;
        }
        for (int j = 0; j < word2.size(); j++) {
            vecList[j + 1][0] = j + 1;
        }
        for (int i = 0; i < word2.size(); i++) {
            for (int j = 0; j < word1.size(); j++) {
                if (word1[j] == word2[i]) vecList[i + 1][j + 1] = vecList[i][j];
                else {
                    vecList[i + 1][j + 1] = std::min(vecList[i + 1][j] + 1, std::min(vecList[i][j] + 1, vecList[i][j + 1] + 1));
                }
            }
        }
        return vecList[word2.size()][word1.size()];
    }
};
*/

void printList(const std::vector<std::vector<int>> &labels) {
    for (int i = 0; i < labels.size(); i++) {
        for (int j = 0; j < labels[i].size(); j++) {
            std::cout << labels[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; 
}
class Solution {
    public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> labels(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        for (int i = 0; i < word1.size() + 1; ++i) labels[i][0] = i;
        for (int i = 0; i < word2.size() + 1; ++i) labels[0][i] = i;
        for (int i = 0; i < word1.size(); ++i) {
            for (int j = 0; j < word2.size(); ++j) {
                if (word1[i] == word2[j]) labels[i + 1][j + 1] = labels[i][j];
                else labels[i + 1][j + 1] = std::min(labels[i][j], std::min(labels[i][j + 1], labels[i + 1][j])) + 1;
            }
        }
        printList(labels);
        return labels[word1.size()][word2.size()];
    }
};
/*
int main() {
    std::string first("intention"), second("execution");
    std::cout << Solution().minDistance(first, second) << std::endl; 
    return 0;
}
*/
// @lc code=end

