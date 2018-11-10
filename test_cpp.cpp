#include<iostream>
#include <limits.h>
#include<vector>
using namespace std;
/*
class Solution {
public:
    Solution(){}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() == 0)
            return MedofArray(nums2);
        if(nums2.size() == 0)
            return MedofArray(nums1);
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
            return findMedianSortedArrays(nums2,nums1);
        int L1,L2,R1,R2,c1,c2,lo = 0, hi = 2*n;
        while(lo <= hi)
        {
            c1 = (lo+hi)/2;
            c2 = m+n- c1;
            L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];
            R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
            L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
            R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

            if(L1 > R2)
                hi = c1-1;
            else if(L2 > R1)
                lo = c1+1;
            else
                break;
        }
        return (max(L1,L2)+ min(R1,R2))/2.0;
    }
    double MedofArray(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
};
*/

class Solution
{
    public:
    double findMedianSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2)
    {
        if(nums1.size()==0)
            return median_array(nums2);
        if(nums2.size()==0)
            return median_array(nums1);
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int left_1,left_2,right_1,right_2,median_1,median_2,lower=0,high=2*nums1.size();//2
        while(lower<=high)
        {
            median_1=(lower+high)/2;//1//2
            median_2=nums1.size()+nums2.size()-median_1;//3//2
            left_1=(median_1==0)?INT_MIN:nums1[(median_1-1)/2];//2//2
            right_1=(median_1==2*nums1.size())?INT_MAX:nums1[median_1/2];//2
            left_2=(median_2==0)?INT_MIN:nums2[(median_2-1)/2];//3
            right_2=(median_2==2*nums2.size())?INT_MAX:nums2[median_2/2];//3
            if(left_1>right_2)
                high=median_1-1;
            if(left_2>right_1)
                lower=median_1+1;//2
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

int main()
{
    std::vector<int> int_vec_1,int_vec_2;
    int_vec_1.push_back(2);
    int_vec_2.push_back(1);
    int_vec_2.push_back(3);
    int_vec_2.push_back(4);
    Solution name;
    std::cout<<name.findMedianSortedArrays(int_vec_1,int_vec_2)<<std::endl;
    return 0;
}

