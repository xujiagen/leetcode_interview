#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
public:
    int InversePairs(vector<int> data) 
    {
        if(data.size()<1)
            return 0;
        std::vector<int> copy(data);

        for(auto i:copy)
            std::cout<<i<<"\t";
        std::cout<<std::endl;


        int count=inverse(data,copy,0,data.size()-1);
        return count;
    }

    int inverse(std::vector<int>& data,std::vector<int>& copy,int start,int end)
    {
        if(start==end)
        {
            copy[start]==data[start];
            return 0;
        }

        int length=(end-start)>>1;//长度是这个字符串的长度的一般
        std::cout<<length<<std::endl;
        int left=inverse(data,copy,start,start+length);
        int right=inverse(data,copy,start+length+1,end);

        int i=start+length;
        int j=end;
        int indexcopy=end;
        int count=0;
        while(i>=start && j>=start+length+1)
        {
            if(data[i]>data[j])
            {
                copy[indexcopy--]=data[i--];
                count+=j-start-length;
            }
            else
            {
                copy[indexcopy--]=data[j--];
            }
        }

        for(;i>=start;--i)
        {
            copy[indexcopy--]=data[i];
        }
        for(;j>=start+length;--j)
            copy[indexcopy--]=data[j];
        return left+right+count;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    int a1[]={1,2,3,4,5,6,7,0};
    std::vector<int> int_vec(a1,a1+sizeof(a1)/sizeof(int));
    for(int i:int_vec)
        std::cout<<i<<"\t";
    std::cout<<std::endl;

    std::cout<<a.InversePairs(int_vec)<<std::endl;
    return 0;
}
