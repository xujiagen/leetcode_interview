#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
    std::vector<int> big_number_multiple(std::vector<int> num1,std::vector<int> num2){
        std::vector<int> vec_int(num1.size()+num2.size(),0);

        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                vec_int[i+j+1]+=num1[i]*num2[j];
            }
        }
        for(int j=vec_int.size()-1;j>0;j--){
            if(vec_int[j]>=10) {
                vec_int[j-1]+=vec_int[j]/10;
                vec_int[j]=vec_int[j]%10;
            }
        }
        return vec_int;
    }
};
void print(std::vector<int>& vec_int){
    for(int i=0;i<vec_int.size();i++){
        std::cout<<vec_int[i]<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    std::vector<int> vec1,vec2;
    vec1.resize(9,0);
    vec2.resize(9,0);
    for(int i=1;i<10;i++)
    {
        vec1[i]=i;
        vec2[9-i]=i;
    }
    print(vec1);
    print(vec2);

    Solution a;
    std::vector<int> vec_int;
    vec_int=a.big_number_multiple(vec1,vec2);
    print(vec_int);

    return 0;
}

/*
首先理解大数相乘的基本思想：
    1 2 3 4 5 6
  × 2 3 4 5 6 7
  --------------
  乘数1的第i位和乘数2的第j位相乘生成结果的(i+j)位的数据
  但是上面这个忽视了进位的影响，这个一位可能超过10

  将结果存储在一个vector数组里面，后面从后面开始解决进位的问题，但是首先结果存储的数组最高为应该有一个空的位置让数组去进位
  这就是vec_int[i+j+1]=vec1[i]*vec[j]的意义
  在结果的最前面保留一个位置来存储我们的最高位的进位

  
 */