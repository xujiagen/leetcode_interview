#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string longestCommonPerfix(std::vector<std::string> &strs) {
        if (strs.size() < 1) return "";
        if (strs.size() == 1) return strs[0];
        std::string &originStr = strs[0];
        if (originStr.size() < 1) return "";
        int length = originStr.size();
        for (auto &str : strs) {
            length = std::min(int(str.size()), length);
            for (int i = 0; i < length; i++) {
                if (str[i] != originStr[i]) {
                    length = i;
                    break;
                }
            }
        }
        return originStr.substr(0, length);
    }
};

int main(int argc, char** argv) {
    std::vector<std::string> strList = {"flower","flow","flight"};
    std::cout << Solution().longestCommonPerfix(strList) << std::endl;
    return 0;
}