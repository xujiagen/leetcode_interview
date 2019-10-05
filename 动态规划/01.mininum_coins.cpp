/*
现在你有2,5,7的硬币，数量不限，但是你你需要凑齐27块钱
你你确定一下最少需要多少个硬币
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    int mininum_coins(int target){
        std::vector<int> vec_int;
        vec_int.resize(target+1);

        vec_int[0]=0;
        int coin_num=0;
        for(int i=1;i<=target;i++)
        {
            vec_int[i]=three_min(coin(vec_int,i-2,target)+1,coin(vec_int,i-5,target)+1,coin(vec_int,i-7,target)+1);
        }
        return vec_int[target];
        
    }
    int three_min(int number1,int numbers2,int numbers3)
    {
        return std::min(number1,std::min(numbers2,numbers3));
    }
    int coin(std::vector<int>& vec_int,int number,int target)
    {
        if(number==0) return 0;
        if(number<0) return target*2;
        return vec_int[number];
    }
};

int main()
{
    Solution a;
    std::cout<<a.mininum_coins(27)<<std::endl;
    return 0;
}