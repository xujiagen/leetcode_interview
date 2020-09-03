/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/*
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (s.size() == 0 && p.size() == 0) return true;
        if (s.size() > 0 && p.size() == 0) return false;
        //std::vector<std::vector<bool>> vecList(p.size() + 1, std::vector<int>(s.size() + 1, false));
        std::vector<std::vector<bool>> vecList(p.size()+1, std::vector<bool>(s.size() + 1, false));
        vecList[0][0] =  true;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '*') vecList[i + 1][0] = vecList[i][0];
        }
        for (int i = 0; i < p.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (p[i] == '*') {
                    vecList[i + 1][j + 1] = vecList[i][j] || vecList[i + 1][j] || vecList[i][j + 1];
                    continue;
                }
                if (p[i] == s[j] || p[i] == '?') {
                    vecList[i + 1][j + 1] = vecList[i][j];
                }
            }
        }
        return vecList[p.size()][s.size()];
    }
};
*/

class Solution {
    public:
    bool isMatch(std::string s, std::string p) {
        std::vector<std::vector<bool>> labels(p.size() + 1, std::vector<bool>(s.size() + 1, false));
        labels[0][0] = true;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '*') labels[i + 1][0] = labels[i][0]; 
        }
        for (int i = 0; i < p.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                //std::cout << "i: " << i << " j: " << j << std::endl; 
                if (p[i] == s[j] || p[i] == '?') labels[i + 1][j + 1] = labels[i][j];
                if (p[i] ==  '*') labels[i + 1][j + 1] = labels[i + 1][j] || labels[i][j + 1];
            }
        }
        /*
        for (int i = 0; i < p.size() + 1; i++) {
            for (int j = 0; j < s.size() + 1; j++) {
                std::cout << labels[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        */ 
        return labels[p.size()][s.size()];
    }
};
/*
int main(int argc, char** argv) {
    std::string p("c*a*b"), s("aab");
    std::cout << Solution().isMatch(s, p) << std::endl;
    return 0;
}
*/
// @lc code=end

