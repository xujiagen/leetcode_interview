/*
在排序数组中查找数组，
第一题，判断这个数组在数组中出现的次数
*/

#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) 
    {
        return search(data,k+0.5)-search(data,k-0.5);
    }
    private:
    int search(std::vector<int> data,double k)
    {
        int start=0,end=data.size()-1;
        while(start<=end)
        {
            //std::cout<<1<<std::endl;
            int mid=(end-start)/2+start;
            //std::cout<<"k"<<k<<"\t"<<"start:"<<start<<"\t"<<"mid:"<<mid<<"\t"<<"end:"<<end<<std::endl;
            if(data[mid]>k)
                end=mid-1;
            else if(data[mid]<k)
                start=mid+1;
        }
        return start;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    std::vector<int> int_vec;
    for(int i=0;i<20;i++)
        int_vec.push_back(i);
    std::cout<<a.GetNumberOfK(int_vec,3)<<std::endl;
    return 0;
}
