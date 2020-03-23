#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int StrToInt(string str)
    {
        if (str.size() < 1)
            return 0;
        bool valueFlag = true;
        std::string valuePart;
        if (str[0] == '-')
        {
            valueFlag = false;
            valuePart = str.substr(1, str.size() - 1);
        }
        else if (str[0] == '+')
            valuePart = str.substr(1, str.size() - 1);
        else
            valuePart = str;
        if (valuePart.size() < 1)
            return 0;
        long sum = 0;
        for (int i = 0; i < valuePart.size(); i++)
        {
            int value = valuePart[i] - '0';
            if (value > 9 || value < 0)
                return 0;
            sum = sum * 10 + value;
        }
        if (!valueFlag)
            sum = -1 * sum;
        if (sum > INT_MAX)
            return 0;
        else if (sum < INT_MIN)
            return 0;
        return int(sum);
    }
};

int main()
{
    std::string tmpStr("-2147483649");
    std::cout << Solution().StrToInt(tmpStr) << std::endl;
    return 0;
}