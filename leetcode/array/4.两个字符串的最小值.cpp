#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        // nums1 = 
        int m = nums1.size();// first vector list small
        int n = nums2.size();// second vector list large
        int l = 0, r = m;
        int len = (m + n + 1) / 2;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = len - i;
            if ()
        }
        }
};

int main(int argc, char** argv) {

} 


/*
#include<iostream>
#include<string>
#include<vector>

using namespace std；

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() == 0)
            return MedofArray(nums2);
        if(nums2.size() == 0)
            return MedofArray(nums1);
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)   //保证数组1一定最短
            return findMedianSortedArrays(nums2,nums1);
        int L1,L2,R1,R2,c1,c2,lo = 0, hi = 2*n;  //我们目前是虚拟加了'#'所以数组1是2*n+1长度
        while(lo <= hi)   //二分
        {
            c1 = (lo+hi)/2;  //c1是二分的结果hi=2*n,c1=n，中心
            c2 = m+n- c1;//m
            L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //(n-1)/2(奇数-1/2是最中间的数，偶数-1/2是中间左边的数)
            R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];// n/2(奇数计算出来的就是最中间的数，偶数计算出来的就是中间右边的数)
            L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];//   (m-1)/2，奇数计算出来的就是最中间的数，偶数计算出来的就是中间右边的数
            R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];// m/2

            if(L1 > R2)//第一个字符串的左边大于第二个字符串右边，说明段的那个序列高位需要左移
                hi = c1-1;//
            else if(L2 > R1)//第二个字符串左边大于第一个字符串右边
                lo = c1+1;
            else
                break;
        }
        return (max(L1,L2)+ min(R1,R2))/2.0;
    }
    double MedofArray(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0);
    }
};

class Solution
{
    public:
    double findMedianSortedArrays(std::vector<int>&nums1,std::vector<int>&nums2)
    {
        if(nums1.size()==0)
            return middle_array(nums2);
        if(nums2.size()==0)
            return middle_array(nums1);
        
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        int L1,L2,R1,R2,middle_1,middle_2,lower=0,high=2*n;
        while(lower<high)
        {
            middle_1=(lower+high)/2;
            middle_2=m+n-middle_1;
            L1=nums1[middle_1-1];
            R1=nums1[middle_1];
            L2=nums2[middle_2-1];
            R2=nums2[middle_2];
            if(L1>R2)//说明左边计算的长了
                high=middle_1-1;
            else if(L2>R1)
                lower=middle_1+1;
            else
                break;
            
        }
        return (std::max(L1,L2)+std::min(R1,R2))/2.0;
    }
    double middle_array(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
};

//归并算法
class Solution
{
    public:
    double findMedianSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2)
    {
        if(nums1.size()==0)
            return middle_array(nums2);
        if(nums2.size()==0)
            return middle_array(nums1);
        int n=nums1.size(),m=nums2.size();
        std::vector<int> nums3;
        nums3.resize(m+n);
        for(int i=0,j=0;i<=n,j<=m;)
        {
            if(nums1[i]=<nums2[j] && i<n)
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else if(nums2[j]<nums1[i] && j<m)
            {
                nums3.push_back(nums2[j]);
                j++;
            }
            else if(i==n)
            {
                for(;j<m;j++)
                    nums3.push_back(nums2[j]);
                break;
            }
            else if(j==m)
            {
                for(;i<n;i++)
                    nums3.push_back(nums1[i]);
                break;
            }
        }
        return middle_array(nums3);
    }
    double middle_array(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
};

class Solution
{
    public:
    double findMedianSortedArrays(std::vector<int> &nums1,std::vector<int> &nums2)
    {
        int sum=nums1.size()+nums2.size();
        std::vector<int> nums3;
        nums3.resize(sum);
        int k1=0,k2=0;
        for(int i=0;i<sum;i++)
        {
            if(k2<nums2.size() && [k1]>=nums2[k2])
            {
                nums3.push_back(nums2[k2]);
                k2++;
            }
            else if(k1<nums1.size() && [k2]>nums1[k1])
            {
                nums3.push_back(nums1[k1]);
                k1++;
            }
            else if(k2==nums2.size() && k1!=nums1.size())
            {
                nums3.push_back(nums1[k1]);
                k1++;
            }
            else if(k1=nums1.size() && k2!=nums2.size())
            {
                nums3.push_back(nums2[k2])
            }
            else if(k1=nums1.size() && k2=nums2.size())
            {
                break;
            }
        }
    }
    double middle_array(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
}

class Solution
{
    public:
    double findMedianSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2)
    {
        if(nums1.size()==0)
            return median_array(nums2);
        if(!nums2.size())
            return median_array(nums1);
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        int lower=0,high=2*n,middle_1,middle_2;
        int left_1,left_2,right_1,right_2;
        while(lower<=high)
        {
            middle_1=(high+lower)/2;
            middle_2=m+n-middle_1;
            left_1=nums1[(middle_1-1)/2];
            left_2=nums2[(middle_2-1)/2];
            right_1=nums1[(middle_1)/2];
            right_2=nums2[(middle_2)/2];
            if(left_1>right_2)
                high=middle_1-1;
            else if(left_2>right_1)
                lower=middle_1+1;
            else
                break;
        }
        return (std::max(left_1,left_2)+std::min(right_1,right_2))/2.0;
    }
    double median_array(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
    
};

class Solution
{
    public:
    double findMedianSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2)
    {
        if(nums1.size()==0)
            return median_array(nums2);
        if(!nums2.size())
            return median_array(nums1);
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        if(nums1[nums1.size()-1]<=nums2[0])
        {
            if(nums1.size()==nums2.size())
                return (nums1[nums1.size()-1]+nums2[0])/2.0;
            else
                return (nums2[(nums2.size()+nums1.size()-1)/2-nums1.size()]+nums2[(nums1.size()+nums2.size())/2-nums1.size()])/2.0;
        }
        else if(nums1[0]>nums2[nums2.size()-1])
        {
            if(nums1.size()==nums2.size())
                return (nums2[nums2.size()-1]+nums1[0])/2.0;
            else
                return (nums2[(nums2.size()+nums1.size()-1)/2]+nums2[(nums1.size()+nums2.size())/2])/2.0;
        }
        int n=nums1.size();
        int m=nums2.size();
        int lower=0,high=2*n,middle_1,middle_2;
        int left_1,left_2,right_1,right_2;
        while(lower<=high)
        {
            middle_1=(high+lower)/2;
            middle_2=m+n-middle_1;
            left_1=nums1[(middle_1-1)/2];
            left_2=nums2[(middle_2-1)/2];
            right_1=nums1[(middle_1)/2];
            right_2=nums2[(middle_2)/2];
            if(left_1>right_2)
                high=middle_1-1;
            else if(left_2>right_1)
                lower=middle_1+1;
            else
                break;
        }
        return (std::max(left_1,left_2)+std::min(right_1,right_2))/2.0;
    }
    double median_array(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
    
};

*/