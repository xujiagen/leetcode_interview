/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
/*
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> vecList;
        if (nums.size() < 3) return vecList;
        for (int i = 0; i < nums.size() - 2; i++) {
            int tempTarget = -1 * nums[i];
            std::map<int, int> valueIndex;
            for (int j = i + 1; j < nums.size(); j++) {
                valueIndex[nums[j]] = j;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (valueIndex.find(tempTarget - nums[j]) != valueIndex.end() && valueIndex[tempTarget - nums[j]] > j) {
                    std::vector<int> tmpList;
                    tmpList.push_back(nums[i]);
                    tmpList.push_back(nums[j]);
                    tmpList.push_back(tempTarget - nums[j]);
                    std::sort(tmpList.begin(), tmpList.end());
                    vecList.push_back(tmpList);
                }
            }
        }
        std::set<std::vector<int>> setList(vecList.begin(), vecList.end());
        return std::vector<std::vector<int>>(setList.begin(), setList.end());
    }
};*/

/*
class Solution {
    public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> vecList;
        if (nums.size() < 3) return vecList;
        std::sort(nums.begin(), nums.end());
        std::map<int, int> valueIndex;
        std::set<std::vector<int>> setList;
        for (int i = 0; i < nums.size(); i++) {
            valueIndex[nums[i]] = i;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            int tmpTarget = -1 * nums[i];
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (valueIndex.find(tmpTarget - nums[j]) != valueIndex.end() && valueIndex[tmpTarget - nums[j]] > j) {
                    std::vector<int> tmpList;
                    tmpList.push_back(nums[i]);
                    tmpList.push_back(nums[j]);
                    tmpList.push_back(tmpTarget - nums[j]);
                    //std::sort(tmpList.begin(), tmpList.end());
                    setList.insert(tmpList);
                    vecList.push_back(tmpList);
                }
            }
        }
        //return vecList;
        return std::vector<std::vector<int>>(setList.begin(), setList.end());
    }
};
*/

class Solution {
    public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> vecList;
        if (nums.size() < 3) return vecList;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size()-1;
            while (left < right) {
                //std::cout << "first: " << i << " left: " << left << " right: " << right << std::endl; 
                //std::cout << nums[i] << " " << nums[left] << " " << nums[right] << std::endl; 
                if (nums[i] + nums[left] + nums[right] == 0) {
                    std::vector<int> tmpList = {nums[i],  nums[left], nums[right]};
                    vecList.push_back(tmpList);
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[right] + nums[left] < 0) left++;
                
                
            }
        }
        return vecList;
    }
};

template <class T>
void printList(const typename std::vector<typename std::vector<T>> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        const std::vector<int> &vec = _VecList[i];
        for (int j = 0; j < vec.size(); j++) {
            std::cout << vec[j] << " ";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    int vec[] = {1,0,1,2,-1,-4, -1};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int)); 
    std::vector<std::vector<int>> result = Solution().threeSum(vecList);
    std::cout << result.size() << std::endl; 
    printList(result);
    return 0;
}


// @lc code=end

