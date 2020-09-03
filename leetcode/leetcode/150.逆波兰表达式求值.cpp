/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        if (tokens.size() < 1) return 0;
        for (std::size_t index = 0; index < tokens.size(); index++) {
            int flag = isCalcFlag(tokens[index]);
            if (flag < 0) {
                valueStack.push(std::stoi(tokens[index]));
            } else {
                int firstValue = valueStack.top();
                valueStack.pop();
                int secondValue = valueStack.top();
                valueStack.pop();
                if (flag == 1) valueStack.push(firstValue + secondValue);
                else if (flag == 2) valueStack.push(secondValue - firstValue);
                else if (flag == 3) valueStack.push(firstValue * secondValue);
                else if (flag == 4) valueStack.push(secondValue / firstValue);
            }
        }
        return valueStack.top();
    }

    int isCalcFlag(std::string &str) {
        if (str == "+") return 1;
        else if (str == "-") return 2;
        else if (str == "*") return 3;
        else if (str == "/") return 4;
        else return -1;
    }
    std::stack<int> valueStack;
    std::vector<int> calcValue; 
};
// @lc code=end
/*
int main(int argc, char**  argv) {
    std::vector<std::string> strList = {"2", "1", "+", "3", "*"};
    std::cout << Solution().evalRPN(strList) << std::endl;
    return 0; 
}
*/
