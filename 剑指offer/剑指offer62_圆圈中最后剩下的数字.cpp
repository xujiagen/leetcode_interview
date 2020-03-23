/*
问题的参考链接https://www.nowcoder.com/questionTerminal/f78a359491e64a50bce2d89cff857eb6
当第m个人被删除之后，从第(m+1)个人开始报数，这个问题变成了一个(n-1,m)的问题，但是顺序改变了
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<=1 || m<=1)
            return -1;
        //删除的数如果不满足条件，程序直接终止
        if(n==1)
            return 0;
        else
            return (LastRemaining_Solution(n-1,m)+m)%n;
    }
};