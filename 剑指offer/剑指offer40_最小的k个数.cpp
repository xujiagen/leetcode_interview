/*
最小的k个数
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

class Solution 
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        
        std::vector<int> int_vec;
        if(input.size()<k)
            return int_vec;
        std::vector<int>::iterator begin=input.begin();
        std::vector<int>::iterator end=input.end();
        qsort(begin,end);
        
        for(int i=0;i<k;i++)
            int_vec.push_back(input[i]);
        
        return int_vec;
    }

    void qsort(std::vector<int>::iterator left, std::vector<int>::iterator right)
    {
        if (left >= right)
            return;
        std::vector<int>::iterator mid = left;
        mid = partition(left + 1, right, bind2nd(less<int>(), *mid));
        iter_swap(mid - 1, left);
        qsort(left, mid - 1);
        qsort(mid, right);
    }
};

int main()
{
    int a[]={4,5,1,6,2,7,3,8};
    std::vector<int> int_vec(a,a+sizeof(a)/sizeof(int));

    Solution a1;
    std::vector<int> vec=a1.GetLeastNumbers_Solution(int_vec,4);
    for(int i=0;i<vec.size();i++)
        std::cout<<vec[i]<<"\t";
    std::cout<<std::endl;
    return 0;
}