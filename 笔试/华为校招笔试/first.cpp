/*
题目大意：给出两个长度为k的字符串a,b，两个长度为n的字符串c,d (k<=n)(k<=n)，求一个最小的ll，使得在c,dc,d中l开头的长度为k的子串刚好与a,ba,b匹配。
n,k<=1e6n,k<=1e6
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

int m, n;

bool isValid(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    else return true;
}

int dfs(std::vector<std::vector<int>> &vecList, 
         std::vector<std::vector<int>> &pathLength, int x, int y) {
    if (pathLength[x][y]) return pathLength[x][y];
    int first = 0, second = 0, third = 0, forth = 0;
    if (isValid(x - 1, y) && vecList[x][y] > vecList[x - 1][y]) first = dfs(vecList, pathLength, x - 1, y);
    if (isValid(x + 1, y) && vecList[x][y] > vecList[x + 1][y]) second = dfs(vecList, pathLength, x + 1, y);
    if (isValid(x, y - 1) && vecList[x][y] > vecList[x][y - 1]) third = dfs(vecList, pathLength, x, y - 1);
    if (isValid(x, y + 1) && vecList[x][y] > vecList[x][y + 1]) forth = dfs(vecList, pathLength, x, y + 1);
    if (first == 0 && second == 0 && third == 0 && forth == 0) {
        pathLength[x][y] = 1;
        return 1;
    } else {
        pathLength[x][y] = std::max(std::max(first, second), std::max(third, forth)) + 1;
        return pathLength[x][y];
    }
}

int main(int argc, char** argv) {
    std::cin >> m >> n;
    std::vector<std::vector<int>> vecList(m, std::vector<int>(n, 0));
    std::vector<std::vector<int>> pathLength(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) std::cin >> vecList[i][j];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = std::max(dfs(vecList, pathLength, i, j), ans);
        }
    }
    std::cout << ans << std::endl; 
    return 0;
}
/*
4 4
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7
*/