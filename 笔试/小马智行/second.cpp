#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

int globalValue = 0;

void Iter(std::vector<std::vector<char>> &_charList,
          std::vector<std::vector<char>> _BoolList,
          std::queue<std::pair<int, int>> &_PairQueue,
          int n)
{
    if (_PairQueue.size() == 1)
    {
        int numU = numu(_charList, _BoolList, _PairQueue.front().first, _PairQueue.front().second, n);
        int numX = numx(_charList, _BoolList, _PairQueue.front().first, _PairQueue.front().second, n);
        if (numU + numX == _charList[_PairQueue.front().first][_PairQueue.front().second] - '0')
        {
            globalValue++;
            return;
        }
    }
    else
    {
        if (_charList)
            int numU = numu(_charList, _BoolList, _PairQueue.front().first, _PairQueue.front().second, n);
        int numX = numx(_charList, _BoolList, _PairQueue.front().first, _PairQueue.front().second, n);
    }
}
// 判断周围的数字有效的数量
int numu(std::vector<std::vector<char>> &_CharList,
         std::vector<std::vector<char>> &_BoolList,
         int i, int j, int n)
{
    int value = 0;
    for (int first = i - 1; first <= i + 1; first++)
    {
        for (int second = j - 1; second <= j + 1; second++)
        {
            if (valid(n, first, second))
            {
                if (_BoolList[i - 1][j] == 'u')
                    value++;
            }
        }
    }
    return value;
}

int numx(std::vector<std::vector<char>> &_CharList,
         std::vector<std::vector<char>> &_BoolList,
         int i, int j, int n)
{
    int value = 0;
    if (valid(n, i - 1, j))
        if (_BoolList[i - 1][j] == 'x')
            value++;
    if (valid(n, i + 1, j))
        if (_BoolList[i + 1][j] == 'x')
            value++;
    if (valid(n, i, j - 1))
        if (_BoolList[i][j - 1] == 'x')
            value++;
    if (valid(n, i, j + 1))
        if (_BoolList[i][j + 1] == 'x')
            value++;
    return value;
}

// 检查是否有效
bool valid(int n, int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
        return true;
    else
        return false;
}
int main(int argc, char **argv)
{
    std::vector<std::vector<char>> charList = {{'1', '?', '1'}, {'?', '2', '?'}, {'1', '?', '1'}};
    int n = 3;
    std::vector<std::vector<char>> boolList(n, std::vector<char>(n, 'u'));
    std::queue<std::pair<int, int>> posQueue;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (charList[i][j] != '?')
            {
                boolList[i][j] = 'o';
                posQueue.push(std::pair<int, int>(i, j));
            }
        }
    }

    return 0;
}