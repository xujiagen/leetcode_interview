#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

bool judgeStr(std::string str, int front, int middle)
{
    for (int i = 0; i < front; i++)
    {
        if (str[i] == str[i + front + middle])
            continue;
        else
            return false;
    }
    return true;
}

bool judge(std::string str, int k)
{
    for (int i = 1; i < str.size(); i++)
    {
        if (i + k * 2 > str.size())
            break;
        if ((str.size() - i) % 2 != 0)
            continue;
        int tmpSize = (str.size() - i) / 2;
        if (tmpSize < k)
            continue;
        if (judgeStr(str, tmpSize, i))
            return true;
        else
            continue;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::string str("abcabcabc");
    int k = 2;
    int tmpSum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i + 1; j <= str.size(); j++)
        {
            /*
            if (i != 0 && j != 8)
                continue;
                */
            //std::cout << "i: " << i + 1 << " j: " << j << " false" << std::endl;
            if (judge(str.substr(i, j - i), 2))
            {
                tmpSum++;
                std::cout << "i:" << i + 1 << " j: " << j << std::endl;
            }
        }
    }
    std::cout << tmpSum << std::endl;
    return 0;
}