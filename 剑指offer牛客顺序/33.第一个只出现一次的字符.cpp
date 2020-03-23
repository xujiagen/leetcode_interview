#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        std::map<char, int> charCount;
        for (int i = 0; i < str.size(); i++)
        {
            if (charCount.find(str[i]) != charCount.end())
                charCount[str[i]]++;
            else
                charCount[str[i]] = 1;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (charCount[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    return 0;
}