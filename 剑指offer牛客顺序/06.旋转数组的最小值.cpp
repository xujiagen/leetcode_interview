/*
旋转数组的最小数字
把一个数组若干个元素搬到数组的末尾，称之为数组的旋转,输入一个非减排序数组的一个旋转，输出旋转数组的最小元素。

首尾关系
首小于尾　找中间　中间大于首，目标在中间为尾部之间，　　中间小于首，

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
class Solution 
{
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if(!rotateArray.size()) return 0;
        if(rotateArray[0]<rotateArray[rotateArray.size()-1]) return rotateArray[0];
        //第一个数小于最后一个数，返回第一个数，这种情况不包括这两个数相等。

        int rotate_front=0;
        int rotate_end=rotateArray.size()-1;
        int rotate_middle;
        while(rotateArray[rotate_front]>=rotateArray[rotate_end])
        {
            if(rotate_end-rotate_front==1)
            {
                rotate_middle=rotate_end;
                break;
            }
            rotate_middle=(rotate_end+rotate_front)/2;
            if(rotateArray[rotate_front]==rotateArray[rotate_middle] && rotateArray[rotate_middle]==rotateArray[rotate_end])
                return find_middle(rotateArray,rotate_front,rotate_end);
            else if(rotateArray[rotate_middle]>=rotateArray[rotate_front]) rotate_front=rotate_middle;
            else if(rotateArray[rotate_middle]<=rotateArray[rotate_end]) rotate_end=rotate_middle;
        }
        return rotateArray[rotate_middle];

    }
    int find_middle(std::vector<int> vec_int,int front,int end)
    {
        int mininum=vec_int[front];
        for(int i=front;i<end;i++)
        {
            if(vec_int[i]<mininum) mininum=vec_int[i];
        }
        return mininum;
    }
    //上面这一段是将二分查找退化为线性查找
};

int main()
{
    int a[]={3,4,5,1,2};
    std::vector<int> vec_int(a,a+sizeof(a)/sizeof(int));
    Solution a1;
    std::cout<<a1.minNumberInRotateArray(vec_int)<<std::endl;
    return 0;
}
*/

class Solution 
{
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if(!rotateArray.size()) return 0;//没有找到想要的
        if(rotateArray[0]<rotateArray[rotateArray.size()-1]) return rotateArray[0];
        int rotate_front=0;
        int rotate_end=rotateArray.size()-1;
        int rotate_mid=(rotate_front+rotate_end)/2;

        while(rotateArray[rotate_front]>=rotateArray[rotate_end])
        {
            if(rotate_end-rotate_front==1)
            {
                rotate_mid=rotate_end;
                break;
            }
            //上面是设置好这个程序的退出的条件
            rotate_mid=(rotate_front+rotate_end)/2;
            if(rotateArray[rotate_front]==rotateArray[rotate_mid] && rotateArray[rotate_mid]==rotateArray[rotate_end]) 
                return find_mini(rotateArray,rotate_front,rotate_end);
            else if(rotateArray[rotate_front]<=rotateArray[rotate_mid]) rotate_front=rotate_mid;
            else if(rotateArray[rotate_mid]<=rotateArray[rotate_end]) rotate_end=rotate_mid;
        }
        return rotateArray[rotate_mid];
    }
    int find_mini(std::vector<int>& vector_int,int rotate_front,int rotate_end)
    {
        int mininum=vector_int[rotate_front];
        for(int i=rotate_front;i<rotate_end;i++)
        {
            if(vector_int[i]<mininum) mininum=vector_int[i];
        }
        return mininum;
    }
};