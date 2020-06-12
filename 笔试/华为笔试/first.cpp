#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int main(int argc, char **argv)
{
    std::string str(",Tom,Lily,Tom,Lucy,Lucy,Tom,Jack");
    std::unordered_map<std::string, int> strCount;
    int start = 0;
    std::vector<std::string> strList;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
        {
            strList.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    strList.push_back(str.substr(start, str.size() - start));
    for (int i = 0; i < strList.size(); i++)
    {
        std::cout << strList[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < strList.size(); i++)
    {
        if (strCount.find(strList[i]) != strCount.end())
        {
            strCount[strList[i]]++;
        }
        else
        {
            strCount[strList[i]] = 1;
        }
    }
    int findMax = 0;
    for (int i = 0; i < strList.size(); i++)
    {
        if (strCount[strList[i]] > findMax)
            findMax = strCount[strList[i]];
    }
    //std::vector<std::string> maxStr;
    std::unordered_set<std::string> maxStr;
    for (int i = 0; i < strList.size(); i++)
    {
        if (strCount[strList[i]] == findMax)
        {
            maxStr.insert(strList[i]);
        }
    }
    std::vector<std::string> maxStrList(maxStr.begin(), maxStr.end());
    std::sort(maxStrList.begin(), maxStrList.end());
    std::cout << maxStrList[0] << std::endl;
    return 0;
}