/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

//这种方法时间复杂度比较高，但是理解比较简单，主要是通过递归和没有去重增加了时间复杂度
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> vecList;
        if (candidates.size() < 1) return vecList;
        combineVec(vecList, {}, candidates, target);
        std::set<std::vector<int>> setList;
        for (int i = 0; i< vecList.size(); i++) {
            std::vector<int> tmpList = vecList[i];
            std::sort(tmpList.begin(), tmpList.end());
            setList.insert(tmpList);
        }
        return std::vector<std::vector<int>>(setList.begin(), setList.end());
    }
    void combineVec(std::vector<std::vector<int>> &_VecList, std::vector<int> _AddUp, std::vector<int> &_Candidate, int target) {
        //std::vector<int> tmpList(_AddUp.begin(), _AddUp.end());
        for (int i = 0; i < _Candidate.size(); i++) {
            std::vector<int> tmpList(_AddUp.begin(),  _AddUp.end());
            if (target < _Candidate[i]) continue;
            else if (target == _Candidate[i]) {
                //_AddUp.push_back(_Candidate[i]);
                tmpList.push_back(_Candidate[i]);
                _VecList.push_back(tmpList);
            } else {
                tmpList.push_back(_Candidate[i]);
                combineVec(_VecList, tmpList, _Candidate, target - _Candidate[i]);
            }
        }
        return;
    }
};

void printList(const std::vector<std::vector<int>> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        const std::vector<int> &vec = _VecList[i];
        for (int j =  0; j < vec.size(); j++) {
            std::cout << vec[j] << " ";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {2,3,6,7};
    std::vector<std::vector<int>> vec = Solution().combinationSum(vecList, 7);
    printList(vec);
    return 0;
}

// @lc code=end

