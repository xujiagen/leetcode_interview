//输入一个数组，调整这个数组的顺序，使奇数都在这个数组的前面

/*
实现的方式是创建两个指针，一个指针在数组的前面，一个指针在数组的后面
每次遇到一个奇数和一个偶数，交换这两个数据的位置
*/
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) 
    {
        if(array.size()<1)
            return;
        int front=0,back=array.size()-1;
        while(front<back)
        {
            while(array[front]%2!=0 && front<back)
                front++;
            while(array[back]%2!=1 && front<back)
                back--;
            if(front<back)
                std::swap(array[front],array[back]);
        }
    }
};
//上面的代码在牛客网上面提交没有通过，因为计算出来的解不是按照顺序排列的