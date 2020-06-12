/*
二进制数中1的个数
输入一个整数输出该数二进制表示中1的个数 其中负数用补码表示
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
class Solution
{
    public:
    int NumberOf1(int n)
    {
        int flag=1;
        int number=0;
        while(flag)
        {
            if(n&flag) number++;
            flag=flag<<1;
        }
        return number;
    }
};
*/
/*
其实一开始是将输入的数右移来判断的
但是对于负数来说右移是会高位补1的
所以这里使用的是左移
*/

class Solution
{
public:
    int NumberOf1(int n)
    {
        int oneCount = 0;
        int flag = 1;
        while (flag)
        {
            if (n & flag)
                oneCount++;
            flag = flag << 1;
        }
        return oneCount;
    }
};
int main()
{
    Solution a;
    std::cout << "number:" << a.NumberOf1(-10) << std::endl;
    return 0;
}