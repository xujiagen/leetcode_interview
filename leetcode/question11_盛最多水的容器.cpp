#include <iostream>
#include <vector>

class Solution
{
    public:

    int calcArea(int &_Front, int &_Back, int _Distance) {
        //   return static_cast<int>(std::min(_Front, _Back) * _Distance);

        return std::min(_Front, _Back) * _Distance;
    }

    int maxArea(std::vector<int> &height)
    {
        if (height.size() < 2)
            return -1;
        //std::size_t front = 0, back = height.size() - 1;
        int front = 0;
        int back = height.size() - 1;
        int maxSize = 0;
        while (front < back) {
            int area = calcArea(height[front], height[back], (back - front));
            if (area > maxSize)
                maxSize = area;
            if (height[front + 1] >= height[back - 1])
                front++;
            else
                back--;
        }
        return maxSize;
    }
};

/*
int main(int argc, char** argv)
{
    int[] a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> vecList(a, a + sizeof(a) / sizeof(int));
    std::cout << Solution().maxArea(vecList) << std::endl;
    return 0;
}
*/

int main() {
    int* a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> vecList(a, a + sizeof(a) / sizeof(int));
    std::cout << Solution().maxArea(vecList) << std::endl;
    return 0;
}

/*
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
*/