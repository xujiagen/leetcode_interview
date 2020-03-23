#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.size() < 1)
            return false;
        int zeroCount = 0;
        std::vector<int> nonZeroList;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0)
            {
                zeroCount++;
                continue;
            };
            nonZeroList.push_back(numbers[i]);
        }
        std::sort(nonZeroList.begin(), nonZeroList.end());
        int diffCount = 0;
        int front = 0;
        for (int i = 1; i < nonZeroList.size(); i++)
        {
            if (nonZeroList[i - 1] == nonZeroList[i])
                return false;
            diffCount += nonZeroList[i] - nonZeroList[i - 1];
        }
        if (diffCount <= 4)
            return true;
        else
            return false;
    }
};