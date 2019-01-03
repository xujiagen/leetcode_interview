/*
注意：
要求：实践复杂度是O(n)，空间复杂度是O(1)
数组里面的数字出去其中两个数以外，其他的数都出现的两次，找出这两个只出现一次的数

如果没有限制空间复杂度可以创建一个哈希表，将每一个数字出现的次数保存在里面，然后找出出现次数只有一次的数字

但是限制的空间复杂度
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.size() < 2)
            return; //输入的数组里面字符的长度没有两位数
        int temp = data[0];
        for (int i = 1; i < data.size(); i++)
        {
            //std::cout<<1<<std::endl;
            temp = temp ^ data[i];
        }
        if (temp == 0)
            return; //如果数组里面数字出现的次数都是两次，亦或的结果就是０
        int index = 0;
        //std::cout<<temp<<std::endl;
        while ((temp&1)== 0)
        {
            temp = temp >> 1;
            index++;
        }
        //std::cout<<index<<std::endl;
        //上面应该是根据低位1的位置来计算
        *num1=*num2=0;
        //std::cout<<(*num1)<<"\t"<<(*num2)<<std::endl;
        for (int i = 0; i < data.size(); i++)
        {
            //std::cout<<"最后"<<std::endl;
            if (isbits(data[i], index))
                (*num1) = (*num1) ^ data[i];
            else
                (*num2) = (*num2) ^ data[i];
        }
    }
    bool isbits(int num, int index)
    {
        num = num >> index;
        return num & 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    int a1[]={2,4,3,6,3,2,5,5};
    std::vector<int> int_vec(a1,a1+sizeof(a1)/sizeof(int));
    int num1,num2;
    a.FindNumsAppearOnce(int_vec,&num1,&num2);
    //std::cout<<*num1<<"\t"<<*num2<<std::endl;
    std::cout<<num1<<"\t"<<num2<<std::endl;
    return 0;
}
