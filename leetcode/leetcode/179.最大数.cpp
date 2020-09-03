/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::string res;
        if (nums.size() < 1) return res;
        if (nums.size() == 1) {
            res += std::to_string(nums[0]);
            return res;
        }
        bool flag = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) flag = false;
        }
        if (flag == true) return std::to_string(0);

        auto HighSort = [&](int &first, int &second) {
            return judge(first, second);
        };
        std::sort(nums.begin(), nums.end(), HighSort);
        for (int i = 0; i < nums.size(); ++i) {
            res += std::to_string(nums[i]);
        }
        return res;
    }
    

    int HighPosition(int value) {
        while (value > 10) value = value / 10;
        return value; 
    }
    bool judge(int first, int second) {

        std::string firstStr = std::to_string(first) + std::to_string(second);
        std::string secondStr = std::to_string(second) + std::to_string(first);
        if (firstStr > secondStr) return true;
        else return false;
    }
    /*
    bool judge(int first, int second) {
        std::vector<int> firstOrder, secondOrder;
        do {
            firstOrder.push_back(first % 10);
            first /= 10;
        } while (first);
        do {
            secondOrder.push_back(second % 10);
            second /= 10;
        } while (second);
        std::reverse(firstOrder.begin(), firstOrder.end());
        std::reverse(secondOrder.begin(), secondOrder.end());
        int firstIndex = 0, secondIndex = 0;
        for (int i = 0; i < std::max(firstOrder.size(), secondOrder.size()); i++) {
            if (firstOrder[firstIndex] > secondOrder[secondIndex]) return true;
            else if (firstOrder[firstIndex] < secondOrder[secondIndex]) return false;
            else {
                if (firstIndex < firstOrder.size() - 1) firstIndex++;
                if (secondIndex < secondOrder.size() - 1) secondIndex++;
            }
        }
        return true;
    }
    */
};
/*
int main(int argc, char** argv) {
    std::vector<int> input = {824,938,1399,5607,6973,5703,9609,4398,8247};
    std::cout << Solution().largestNumber(input) << std::endl; 
    return 0;
}
*/


// @lc code=end

