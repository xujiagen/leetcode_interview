/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::vector<int> firstVersion = splitStr(version1);
        std::vector<int> secondVersion = splitStr(version2);
        
        int firstEnd = firstVersion.size(), secondEnd = secondVersion.size();
        for (int index = firstVersion.size() - 1; index >= 0; index--) {
            if (firstVersion[index] == 0) firstEnd = index;
            else break;
        }
        for (int index = secondVersion.size() - 1; index >= 0; index--) {
            if (secondVersion[index] == 0) secondEnd = index;
            else break;
        }
        firstVersion = std::vector<int>(firstVersion.begin(), firstVersion.begin() + firstEnd);
        secondVersion = std::vector<int>(secondVersion.begin(), secondVersion.begin() + secondEnd);
        /*
        auto printValue = [](int a) {
            std::cout << a << " ";
        };
        std::for_each(firstVersion.begin(), firstVersion.end(), printValue);
        std::cout << std::endl; 
        std::for_each(secondVersion.begin(), secondVersion.end(), printValue);
        std::cout << std::endl; 
        */
        for (int i = 0; i < firstVersion.size() && i < secondVersion.size(); i++) {
            if (firstVersion[i] < secondVersion[i]) return -1;
            else if (secondVersion[i] < firstVersion[i]) return 1;
        }
        if (firstVersion.size() < secondVersion.size()) return -1;
        else if (secondVersion.size() < firstVersion.size()) return 1;
        return 0;
    }
    std::vector<int> splitStr(std::string &version) {
        std::vector<int> res;
        std::string str;
        for (int i = 0; i < version.size(); i++) {
            if (version[i] == '.') {
                if (str.size()) {
                    res.push_back(std::stoi(str));
                    str.clear();
                }
            } else {
                str += version[i];
            }
        }
        if (str.size()) res.push_back(std::stoi(str));
        return res;
    }
};
/*
int main(int argc, char* argv[]) {
    std::string version1 = "1", version2 = "1.0";
    std::cout << Solution().compareVersion(version1, version2) << std::endl; 
    return 0;    
}
*/
// @lc code=end

