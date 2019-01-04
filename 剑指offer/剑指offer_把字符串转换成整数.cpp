#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution
{
  public:
    int StrToInt(string str)
    {
        if (str.size() < 1)
            return 0;

        int minus = 1;
        int number = 0;
        if (str[0] == '-')
            minus = -1;
        else
            minus = 1;
        for (int i = 0; i < str.size(); i++)
        {
            if ((str[0] == '+' || str[0] == '-') && i == 0)
                continue;
            else
            {
                int num = str[i] - '0';
                if (num >= 0 && num <= 9)
                {
                    if (minus == 1)
                    {
                        if ((INT_MAX - number*10) < num)
                            return INT_MAX;
                        else
                            number = number*10 + minus * num;
                    }
                    else if (minus == -1)
                    {
                        if ((INT_MIN-number*10)>minus*number)
                            return INT_MIN;
                        else
                            number = number*10 + minus * num;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
        return number;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    string a1="-72572542";
    std::cout<<INT_MIN<<std::endl;
    std::cout<<a.StrToInt(a1)<<std::endl;
    return 0;
}