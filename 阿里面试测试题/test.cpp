#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    /*
    std::string first, second;
    std::cin >> first >> second;
    if (first.size() != second.size()) {
        std::cout << - 1 << std::endl;
        return 0;
    }
    */
    std::string first("acdk"), second("ckad");
    std::string tmpFirst = first, tmpSecond = second;
    std::sort(tmpFirst.begin(), tmpFirst.end());
    std::sort(tmpSecond.begin(), tmpSecond.end());
    for (std::size_t i = 0; i < tmpFirst.size(); i++) {
        if (tmpFirst[i] != tmpSecond[i]) {
            std::cout << - 1 << std::endl;
            return 0;
        }
    }
    std::size_t firstIndex = 0, count = 0;
    for (std::size_t i = 0; i < second.size(); i++) {
        while (firstIndex < first.size() && first[firstIndex] != second[i]) firstIndex++;
        if (firstIndex < first.size()) count++;
        else break;
        firstIndex++;
    }
    std::cout << first.size() - count << std::endl; 
    return 0;
}