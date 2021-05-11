#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<int> tmpList;
        combineSolution(k, n, 1, tmpList);
        return results;
    }

    void combineSolution(int k, int n, int start, std::vector<int> &_VecList) {
        if (n < start) return;
        if (k == 1 && n <= 9) {

            _VecList.push_back(n);
            results.push_back(_VecList);
            _VecList.pop_back();
        }
        for (int i = start; i <= 9; i++) {
            _VecList.push_back(i);
            combineSolution(k - 1, n - i, i + 1, _VecList);
            _VecList.pop_back();
        }
    }
    std::vector<std::vector<int>> results;
};

template <class T>
void printList(const std::vector<typename std::vector<T>> &_VecList) {
    if (_VecList.size() < 1) return;
    for (auto list : _VecList) {
        for (auto val : list) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    std::vector<std::vector<int>> tmpList = std::move(Solution().combinationSum3(9, 45));
    printList(tmpList);
    return 0;
}