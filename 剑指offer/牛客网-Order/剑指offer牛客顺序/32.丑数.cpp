#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index < 2)
            return index;
        std::vector<int> vecList(index, 1);
        int twoIndex = 0, threeIndex = 0, fiveIndex = 0;
        for (int i = 1; i <= index; i++)
        {
            int tmpTarget = min(2 * vecList[twoIndex], min(3 * vecList[threeIndex], 5 * vecList[fiveIndex]));
            vecList[i] = tmpTarget;
            if (tmpTarget % 2 == 0)
                twoIndex++;
            if (tmpTarget % 3 == 0)
                threeIndex++;
            if (tmpTarget % 5 == 0)
                fiveIndex++;
        }
        return vecList[vecList.size() - 1];
    }
};

void printList(const std::vector<int> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    int uglyNum = Solution().GetUglyNumber_Solution(9);
    std::cout << uglyNum << std::endl;
    return 0;
}