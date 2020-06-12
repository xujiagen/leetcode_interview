/*
和为s的两个数
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) 
    {
        std::vector<std::vector<int> > int_vec_vec;
        int head=array.size()-1;
        int back=0;
        while(back<head)
        {
            int current_sum=array[head]+array[back];
            if(current_sum==sum)
            {
                std::vector<int> int_vec;
                int_vec.push_back(array[back]);
                int_vec.push_back(array[head]);
                int_vec_vec.push_back(int_vec);
            }
            if(current_sum>sum)
                head--;
            else
                back++;
        }
        if(int_vec_vec.size()>0)
        {
            int small=INT_MAX;
            int index=0;
            for(int i=0;i<int_vec_vec.size();i++)
            {
                int current_sum=int_vec_vec[i][0]+int_vec_vec[i][1];
                if(current_sum<small)
                {
                    small=current_sum;
                    index=i;
                }
            }
            return int_vec_vec[index];
        }
        std::vector<int> int_vec1;
        return int_vec1;
    }
};