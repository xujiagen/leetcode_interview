#include<iostream>
#include<vector>


class Solution
{
    public:
    Solution(std::vector<int> item1,std::vector<int> item2)
    :num1(item1),num2(item2)
    {
        std::cout<<findMedianSortedArrays(num1,num2);
    }
    double findMedianSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2)
    {
        if(nums1.size()==0)
            return middle_array(nums2);
        if(nums2.size()==0)
            return middle_array(nums1);
        int n=nums1.size(),m=nums2.size();
        std::vector<int> nums3;
        nums3.resize(m+n);
        for(int i=0,j=0;i<n,j<m;)
        {
            if(nums1[i]=<nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        return middle_array(nums3);
    }
    double middle_array(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
    private:
    std::vector<int> num1,num2;
};

int main()
{
    std::vector<int> int_vec1,int_vec2;
    for(int i=0;i<6;i++)
        int_vec1.push_back(i);
    for(int i=3;i<)
    return 0;
}