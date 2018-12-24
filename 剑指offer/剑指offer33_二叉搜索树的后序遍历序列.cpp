/*
二叉搜索树的后序遍历序列
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
public:
    bool VerifySquenceOfBST(vector<int> sequence) 
    {
        if(sequence.size()<1)
            return false;
        return findtree(sequence,0,sequence.size()-1);
    }
    bool findtree(std::vector<int> sequence,int start,int end)
    {
        if(end-start<=0)
            return true;

        int i=start;
        for(;i<end;i++)
        {
            if(sequence[i]>sequence[end])
                break;
        }
        int j=i;
        for(;j<end;j++)
        {
            if(sequence[end]>sequence[j])
                return false;
        }
        bool left=true,right=true;
        if(i>start)
            left=findtree(sequence,start,i-1);
        if(j<end)
            right=findtree(sequence,start,end-1);
        return left && right;
    }
};

int main()
{
    Solution a;
    int b[]={4,8,6,12,16,14,10};
    std::vector<int> int_vec(b,b+sizeof(b)/sizeof(int));
    std::cout<<a.VerifySquenceOfBST(int_vec)<<std::endl;
    return 0;
}