#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        if (charSet.count(ch) == 0)
        {
            charSet.insert(ch);
            vecList.push_back(ch);
        }
        else
        {
            charSet.erase(ch);
            for (int i = 0; i < vecList.size(); i++)
            {
                if (vecList[i] == ch)
                {
                    vecList.erase(vecList.begin() + i);
                }
            }
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if (vecList.size() < 1)
            return '#';
        else
            return vecList[0];
    }
    std::vector<char> vecList;
    std::set<char> charSet;
};
