#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        if (n == 0)
            return str;
        if (str.size() < 1)
            return str;
        int tmpRol = n % str.size();
        std::string tmpLeft = str.substr(0, tmpRol);
        std::string tmpRight = str.substr(tmpRol, str.size() - tmpRol);
        return tmpRight + tmpLeft;
    }
};