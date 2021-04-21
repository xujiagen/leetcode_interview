/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
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
         if (s.size() > 0 && p.size() < 1) return false;
         std::vector<std::vector<bool>> vecList(p.size() + 1, std::vector<bool>(s.size() + 1, false));
         vecList[0][0] = true;
         for (int i = 0; i < p.size(); i++) {
             if (p[i] == '*' && vecList[i - 1][0]) vecList[i + 1][0] = true;
         }
         //printList<bool>(vecList);
         for (int i = 0; i < p.size() + 1; i++) {
             for (int j = 0; j < s.size(); j++) {
                 if (p[i] == s[j] || p[i] == '.') {
                     vecList[i + 1][j + 1] = vecList[i][j];
                 }
                 else if (p[i] == '*') {
                     if (p[i - 1] != s[j] && p[i - 1] != '.') {
                         vecList[i + 1][j + 1] = vecList[i - 1][j + 1];
                     } else {
                         vecList[i + 1][j + 1] = vecList[i + 1][j] || vecList[i][j + 1] || vecList[i - 1][j + 1];
                     }
                 }
             }
         }
         //printList<bool>(vecList);
         return vecList[p.size()][s.size()];
    }
    template <class T>
    void printList(const typename std::vector<std::vector<T>> &_VecList) {
        if (_VecList.size() < 1) return;
        for (int i = 0; i < _VecList.size(); i++) {
            const typename std::vector<T> &vec = _VecList[i];
            for (int j = 0; j < vec.size(); j++) {
                std::cout << vec[j] << " ";
            }
            std::cout << std::endl; 
        }
        std::cout << std::endl; 
    }
};
*/

#include <iostream>
#include <vector>
#include <string>


// void printList(const std::vector<std::vector<bool>> &labels) {
//     const int rows = labels.size();
//     const int cols = labels[0].size();
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             std::cout << labels[i][j] << " ";
//         }
//         std::cout << std::endl; 
//     }
//     std::cout << std::endl; 
// }

// class Solution {
//     public:
//     bool isMatch(std::string s, std::string p) {
//         //s =target p source
//         const int rows = p.size() + 1;
//         const int cols = s.size() + 1;
//         std::vector<std::vector<bool>> labels(rows, std::vector<bool>(cols, false));
//         labels[0][0] = true;
//         for (int i = 1; i < rows; i++)
//             if (i - 1 >= 0 && p[i] == '*') labels[i + 1][0] = labels[i - 1][0];
//         //printList(labels);
//         for (int i = 0; i < p.size(); i++) {
//             for (int j = 0; j < s.size(); j++) {
//                 //char &sValue = s[j], &pValue = p[i];
//                 if (p[i] == s[j] || p[i] == '.') {
//                     labels[i + 1][j + 1] = labels[i][j];
//                     continue;
//                 }
//                 //char &pDValue = p[i - 1];

//                 if (p[i] == '*' && (p[i - 1] == s[j] || p[i - 1] == '.')) labels[i + 1][j + 1] = labels[i][j] || labels[i][j + 1] || labels[i + 1][j];
//                 else if (p[i] == '*' && p[i - 1] != s[j]) labels[i + 1][j + 1] = labels[i - 1][j + 1];
//             }
//         }
//         //printList(labels);
//         return labels[p.size()][s.size()];
//     }
// };
/*
int main(int argc, char**) {
    std::string s("aasdfasdfasdfasdfas"), p("aasdfasdfasdfasdfas");
    std::cout << Solution().isMatch(s, p) << std::endl; 
    return 0;
}
*/
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        const int rows = p.size();
        const int cols = s.size();
        //if ((cols == 0 && rows > 0) || (cols > 0 && rows == 0)) return false;
        if (cols == 0 && rows == 0) return true;
        std::vector<std::vector<bool>> matchList(rows + 1, std::vector<bool>(cols + 1, false));
        matchList[0][0] = true;
        for (int i = 0; i < rows; i++) 
            if (p[i] == '*' && i > 0) matchList[i + 1][0] = matchList[i - 1][0];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (p[i] == s[j] || p[i] == '.') matchList[i + 1][j + 1] = matchList[i][j];
                if (p[i] == '*') {
                    if (p[i - 1] != s[j] && p[i - 1] != '.') matchList[i + 1][j + 1] = matchList[i - 1][j + 1];
                    else matchList[i + 1][j + 1] = matchList[i][j] || matchList[i - 1][j + 1] || matchList[i + 1][j];
                }
            }
        }
        //printList(matchList);
        return matchList[rows][cols];
    }

    // void printList(const std::vector<std::vector<bool>> &matchList) {
    //     const int rows = matchList.size();
    //     if (rows < 1) return;
    //     const int cols = matchList[0].size();
    //     if (cols < 1) return;
    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             std::cout << matchList[i][j] << " ";
    //         }
    //         std::cout << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
};

int main(int argc, char** argv) {
    std::cout << Solution().isMatch("", ".*") << std::endl;
    return 0;
}


// @lc code=end

