#include<iostream>
#include<vector>

class Solution
{
    public:
    Solution(std::vector<int>& item1,std::vector<int> &item2)
    {
        std::cout<<findMedianSortedArrays(item1,item2);
    }
    double findMedianSortedArrays(std::vector<int> &nums1,std::vector<int> &nums2)
    {
        int sum=nums1.size()+nums2.size();
        std::vector<int> nums3;
        int k1=0,k2=0;
        std::cout<<nums1.size();
        std::cout<<nums2.size();
        std::cout<<sum<<std::endl;
        for(int i=0;i<sum;i++)
        {
            if(k2<nums2.size() && nums1[k1]>=nums2[k2])
            {
                nums3.push_back(nums2[k2]);
                k2++;
            }
            else if(k1<nums1.size() && nums2[k2]>nums1[k1])
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
                nums3.push_back(nums2[k2]);
            }
            else if(k1==nums1.size() && k2==nums2.size())
            {
                break;
            }
            
        }
        for(int i=0;i<nums3.size();i++)
            std::cout<<nums3[i]<<std::endl;
        return middle_array(nums3);
    }
    double middle_array(std::vector<int>& item)
    {
        return (item[item.size()/2]+item[(item.size()-1)/2])/2.0;
    }
};

int main()
{
    std::vector<int> int_vec_1,int_vec_2;
    int_vec_1.push_back(1);
    int_vec_1.push_back(3);
    int_vec_2.push_back(2);
    Solution item(int_vec_1,int_vec_2);
    return 0;
}