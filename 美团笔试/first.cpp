#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
int main(int argc, char **argv)
{
    int thres = 2;
    std::vector<int> vecList = {1, 2, 2, 3, 5};
    std::map<int, int> valueCount;
    for (int i = 0; i < vecList.size(); i++)
    {
        if (valueCount.find(vecList[i]) != valueCount.end())
        {
            valueCount[vecList[i]]++;
        }
        else
            valueCount[vecList[i]] = 1;
    }
    int maxCount = 0;
    for (int i = 0; i < vecList.size(); i++)
    {
        int tmpCount = 0;
        for (int j = 0; j < vecList.size(); j++)
        {
            if (vecList[j] - vecList[i] <= thres && vecList[j] - vecList[i] >= 0)
                tmpCount++;
        }
        if (tmpCount > maxCount)
            maxCount = tmpCount;
    }
    std::cout << vecList.size() - maxCount << std::endl;
    return 0;
}