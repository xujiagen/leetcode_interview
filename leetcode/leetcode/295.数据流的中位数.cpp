/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <climits>
#include <iomanip>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (vecList.empty()) vecList.push_back(num);
        else {
            vecList.insert(std::lower_bound(vecList.begin(), vecList.end(), num), num);
        }
    }
    
    double findMedian() {
        if (vecList.empty()) return 0.0;
        return (double(vecList[vecList.size() / 2]) + double(vecList[(vecList.size() - 1)/ 2])) / 2;
    }
    std::vector<int> vecList;
};

int main(int argc, char** argv) {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    std::cout << obj->findMedian() << std::endl;
    obj->addNum(3);
    std::cout << obj->findMedian() << std::endl;
    return 0;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

