#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.size() < 1)
            return str;
        int front = 0;
        std::string finalStr;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                if (i - front > 0)
                {
                    std::string tmpStr = str.substr(front, i - front);
                    if (finalStr.size() < 1)
                        finalStr = tmpStr;
                    else
                        finalStr = tmpStr + ' ' + finalStr;
                }
                front = i + 1;
            }
        }
        if (front == 0)
            finalStr = str;
        else
            finalStr = str.substr(front, str.size() - front + 1) + " " + finalStr;
        return finalStr;
    }
};
*/

class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.size() < 1)
            return str;
        int front = 0;
        std::string res;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                if (i - front > 0)
                {
                    std::string tmpStr = str.substr(front, i - front);
                    front = i + 1;
                    //std::cout << tmpStr << std::endl;
                    if (res.size() < 1)
                        res = tmpStr;
                    else
                        res = tmpStr + " " + res;
                }
            }
        }
        if (str.size() - front > 0)
        {
            if (res.size() < 1)
                res = str.substr(front, str.size() - front);
            else
                res = str.substr(front, str.size() - front) + " " + res;
        }
        return res;
    }
};

int main()
{
    std::string tmpStr("wandeful");
    std::cout << Solution().ReverseSentence(tmpStr) << "11" << std::endl;
    return 0;
}