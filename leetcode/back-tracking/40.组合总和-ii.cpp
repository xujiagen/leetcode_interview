/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

//和上一个解法是一样的，很高的复杂度，主要是通过set进行去重，没有通过检测条件来进行去重，降低算法的复杂度
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> vecList;
        if (candidates.size() < 1) return vecList;
        combineVec(vecList, candidates, {}, target);
        std::set<std::vector<int>> setList;
        for (int i = 0; i < vecList.size(); i++) {
            std::vector<int> tmpList = vecList[i];
            std::sort(tmpList.begin(), tmpList.end());
            setList.insert(tmpList);
        }
        return std::vector<std::vector<int>>(setList.begin(), setList.end());
    }
    void combineVec(std::vector<std::vector<int>> &_VecList, std::vector<int> &_Candidate, std::vector<int> _Vec, int _Target) {
        
        for (int i = 0; i < _Candidate.size(); i++) {
            if (_Candidate[i] > _Target) continue;
            std::vector<int> tmpCandidate(_Candidate.begin(),  _Candidate.end());
            std::vector<int> tmpVec(_Vec.begin(),  _Vec.end());
            if (_Candidate[i] == _Target) {
                tmpVec.push_back(_Candidate[i]);
                _VecList.push_back(tmpVec);
            } else {
                tmpCandidate.erase(tmpCandidate.begin() + i);
                tmpVec.push_back(_Candidate[i]);
                combineVec(_VecList, tmpCandidate, tmpVec, _Target - _Candidate[i]);
            }
        }
        return;
    }
};
// @lc code=end

