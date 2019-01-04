/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(std::vector<int> int_vec)
{
    for(int i=0;i<int_vec.size();i++)
        std::cout<<int_vec[i]<<"\t";
    std::cout<<std::endl;
}

class Solution
{
  public:
    vector<int> multiply(const vector<int> &A)
    {
        std::vector<int> int_vec;
        if (A.size() < 1)
            return int_vec;
        int_vec.resize(A.size());
        int_vec[0] = 1;
        for (int i = 1; i < A.size(); i++)
            int_vec[i] = int_vec[i - 1] * A[i - 1];

        //print(int_vec);
        //下三角矩阵计算完成

        int temp = 1;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            int_vec[i] = int_vec[i] * temp;
            temp *= A[i];
        }
       // print(int_vec);
        return int_vec;
    }
};



int main(int argc, char const *argv[])
{
    Solution a;
    int a1[]={1,2,3,4,5,6};
    std::vector<int> int_vec(a1,a1+sizeof(a1)/sizeof(int));
    print(int_vec);
    std::vector<int> vec=a.multiply(int_vec);
    for(int i=0;i<vec.size();i++)
        std::cout<<vec[i]<<"\t";
    std::cout<<std::endl;

    return 0;
}
