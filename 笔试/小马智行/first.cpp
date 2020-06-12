#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int main(int argc, char **argv)
{
    std::vector<int> vecList = {1, 2, 4, 1, 4, 2};
    std::vector<int> indexList(vecList.size(), 0);
    std::unordered_map<int, int> indexValue;
    indexValue[vecList[0]] = 0;
    for (int i = 1; i < vecList.size(); i++)
    {
        int tmpValue = indexList[i - 1] + 1;
        if (indexValue.find(vecList[i]) != indexValue.end())
        {
            tmpValue = tmpValue < indexValue[vecList[i]] + 1 ? tmpValue : indexValue[vecList[i]] + 1;
            indexValue[vecList[i]] = tmpValue;
        }
        else
        {
            indexValue[vecList[i]] = tmpValue;
        }
        indexList[i] = tmpValue;
    }
    for (int i = 0; i < indexList.size(); i++)
        std::cout << indexList[i] << " ";
    std::cout << std::endl;

    std::cout << indexList[indexList.size() - 1] << std::endl;
    return 0;
}