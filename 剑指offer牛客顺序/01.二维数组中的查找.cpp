/*
2019年6月3号
在二维数组中，每一行都按照从左到右的顺序排序，每一列按照从上到下递增的顺序排列，完成一个函数，输入这样一个二维数组和一个整数，判断数组中是否含有该整数
*/
#include<iostream>
#include<vector>

typedef std::vector<std::vector<int> > vec_vec_int;
class Solution
{
    public:
    bool find(int target,std::vector<std::vector<int> > array)
    {
        int cols=array.size();
        if(cols<=0) return false;
        int rows=array[0].size();
        if(rows<=0) return false;
        //上面是设置边界条件，只有二维数组里面有数据，才能继续进行下去

         int col=0;
         int row=rows-1;
         while(row>=0 && col<cols)
         {
             if(array[col][row]==target) return true;
             else if(array[col][row]>target) row--;
             else if(array[col][row]<target) col++;
         }
         return false;
    }
};

int main()
{
    Solution a;
    return 0;
}