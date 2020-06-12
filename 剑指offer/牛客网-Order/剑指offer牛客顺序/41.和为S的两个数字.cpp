#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        std::vector<int> res;
        if (array.size() < 2)
            return res;
        std::map<int, int> valueIndex;
        for (int i = 0; i < array.size(); i++)
        {
            valueIndex[array[i]] = i;
        }
        for (int i = 0; i < array.size(); i++)
        {
            if (valueIndex.find(sum - array[i]) != valueIndex.end())
            {
                res.push_back(array[i]);
                res.push_back(sum - array[i]);
                return res;
            }
        }
        return res;
    }
};