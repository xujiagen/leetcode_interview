/*
和为s的连续正序列
给定一个数字，找出所有的能够和为这个序列的所有整数
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        std::vector<std::vector<int> > int_vec_vec;
        if(sum<3)
            return int_vec_vec;
        
        int small=1;
        int big=2;
        int middle=(1+sum)/2;

        int current_sum=small+big;

        while(small<middle)
        {
            if(current_sum==sum)
                push(int_vec_vec,small,big);
            
            while(current_sum>sum && small<middle)
            {
                current_sum-=small;
                small++;
                if(current_sum==sum)
                    push(int_vec_vec,small,big);
                
            }
            big++;
            current_sum+=big;
        }
        return int_vec_vec;
    }

    void push(std::vector<std::vector<int> >& int_vec_vec,int small,int big)
    {
        std::vector<int> int_vec;
        for(int i=small;i<=big;i++)
            int_vec.push_back(i);
        int_vec_vec.push_back(int_vec);
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    std::vector<std::vector<int> > int_vec_vec=a.FindContinuousSequence(100);

    if(int_vec_vec.size()>0)
    {
        for(int i=0;i<int_vec_vec.size();i++)
        {
            for(int j=0;j<int_vec_vec[i].size();j++)
            {
                std::cout<<int_vec_vec[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }
    }
    return 0;
}
