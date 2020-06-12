#include <iostream>
#include <vector>
/*
首先输入的数据是数组的行数和列数,然后输入的数据是数组的内容
*/
int main(int argc, char** argv) {
    int rows = 3, cols = 5;
    //std::cin >> rows >> cols;
    std::vector<std::vector<int>> vecList;
    //(rows, std::vector<int>(cols, 0));
    vecList.push_back({5, 9, 5, 4, 4});
    vecList.push_back({4, 7, 4, 10, 3});
    vecList.push_back({2, 10, 9, 2, 3});
    std::cout << "'" << std::endl;
    /*
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) std::cin >> vecList[i][j];
    }
    */
    //if (vecList.size() < 0) return 0;
    //int sum = 0;
    /*
    if (vecList.size() == 1) {
        for (int i = 1; j < vecList[0].size(); j++) {
            sum += std::abs(vecList[0][i] - vecList[0][i - 1]);
        }
        return sum;
    }
    */
    std::vector<std::vector<int>> value(rows, std::vector<int>(cols, 0));
    for (int i = 1; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            int first = vecList[j][i] - vecList[0][i - 1] + value[0][i - 1];
            int second = vecList[j][i] - vecList[1][i - 1] + value[1][i - 1];
            int third = vecList[j][i] - vecList[2][i - 1] + value[2][i - 1];
            std::cout << first << " " << second << " " << third << std::endl;
            value[i][j] = std::min(first, std::min(second, third));
        }
    }
    int res = value[0][cols - 1];
    for (int i = 0; i < rows; i++) {
        if (value[i][cols - 1] < res) res = value[i][cols - 1];
    }
    return res;
}