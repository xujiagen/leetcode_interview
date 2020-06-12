#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        std::map<int, int> dataValue;
        for (int i = 0; i < data.size(); i++)
        {
            if (dataValue.find(data[i]) != dataValue.end())
                dataValue[data[i]]++;
            else
                dataValue[data[i]] = 1;
        }
        bool oneFlag = false, twoFlag = false;
        for (int i = 0; i < data.size(); i++)
        {
            if (dataValue[data[i]] == 1 && !oneFlag)
            {
                oneFlag = true;
                *num1 = data[i];
                continue;
            }
            if (dataValue[data[i]] == 1 && !twoFlag)
            {
                twoFlag = true;
                *num2 = data[i];
                break;
            }
        }
    }
};

int main()
{
    return 0;
}