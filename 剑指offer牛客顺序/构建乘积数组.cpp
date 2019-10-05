/*
构建乘积数组，给定一个数组a,请构建一个数组b,其中b中的元素。。。，不能是使用除法
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A)
    {
        std::vector<int> vec_int;
        if(!A.size()) return vec_int;
        std::vector<int> vec_a(A.size(),1);
        std::vector<int> vec_b(A.size(),1);
        for(int i=0;i<A.size()-1;i++)
        {
            vec_a[i+1]=vec_a[i]*A[i];
            vec_b[A.size()-2-i]=vec_b[A.size()-1-i]*A[A.size()-1-i];
        }
        for(auto a:vec_a) std::cout<<a<<" ";
        std::cout<<std::endl;

        for(auto b:vec_b) std::cout<<b<<" ";
        std::cout<<std::endl;

        for(int i=0;i<A.size();i++)
            vec_a[i]=vec_a[i]*vec_b[i];
        return vec_a;
    }
};

int main()
{
    Solution A;
    int ab[]={1,2,3,4,5,6,7,8,9};
    std::vector<int> vec_int(ab,ab+sizeof(ab)/sizeof(int));
    std::vector<int> vec_int1=A.multiply(vec_int);
    for(auto a:vec_int1) std::cout<<a<<" ";
    std::cout<<std::endl;
    return 0;
}