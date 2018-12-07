#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int num=height.size();
        int size=0;
        for(int i=0;i<num-1;i++)
        {
            for(int j=i+1;j<num;j++)
            {
                int temp=(j-i)*(std::min(height[i],height[j]));
                size=temp>size?temp:size;
            }
        }
        return size;
    }
};

class solution
{
    public:
    int maxArea(std::vector<int>& height)
    {
        int num=height.size();
        int size();
        int left=0,right=height.size()-1,maxarea=0;
        while(left<right)
        {
            maxarea=std::max(maxarea,std::min(height[left],height[right]*(right-left)));
            height[left]<height[right]?(left++):(right--);
        }
        return maxarea;
    }
};

int main()
{
    Solution a;
    int temp[]={1,8,6,2,5,4,8,3,7};
    std::vector<int> int_vec(temp,temp+sizeof(temp)/sizeof(int));
    for(int i=0;i<int_vec.size();i++)
        std::cout<<int_vec[i]<<"\t";
    std::cout<<std::endl;
    std::cout<<a.maxArea(int_vec)<<std::endl;
    return 0;
}