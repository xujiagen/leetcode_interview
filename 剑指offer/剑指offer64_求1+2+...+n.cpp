/*
求1+2+...+n
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;
//根据短路原理来求解这样的问题
//短路原理就是说 m&&n,当m等于0的时候不会在计算后面的结果

class Solution {
public:
    int Sum_Solution(int n) {
        int ans=n;
        ans && (ans+=Sum_Solution(n-1));
        return ans;
    }
};

//下面是通过创建数组的形式来计算

class solution
{
    public:
    int sum_solution(int n)
    {
        int a[n][n+1];//这个问题本身因为是创建一个bool数组 bool a[n][n+1];//判断这个数组的大小
        //但是在实际计算过程中发现int 类型计算的结果也是正确的，int[n+1][n+1]也是正确的
        return sizeof(a);
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    Solution a1;
    std::cout<<a.Sum_Solution(10)<<std::endl;
    std::cout<<a1.Sum_Solution(10)<<std::endl;
    std::cout<<sizeof(bool)<<std::endl;
    return 0;
}
