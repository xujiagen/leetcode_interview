/*
2019年6月3号
在二维数组中，每一行都按照从左到右的顺序排序，每一列按照从上到下递增的顺序排列，完成一个函数，输入这样一个二维数组和一个整数，判断数组中是否含有该整数
*/
#include <iostream>
#include <vector>

/*
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
*/

class Solution
{
public:
    bool Find(int target, std::vector<std::vector<int>> array)
    {
        const int &rows = array.size();
        if (rows < 1)
            return false;
        const int &cols = array[0].size();
        if (cols < 1)
            return false;
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0)
        {
            if (array[row][col] == target)
                return true;
            else if (array[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};

template <class T>
void printVec(typename std::vector<std::vector<T>> &_VecList)
{
    if (_VecList.size() < 1)
        return;
    if (_VecList[0].size() < 1)
        return;
    for (int i = 0; i < _VecList.size(); i++)
    {
        for (int j = 0; j < _VecList[0].size(); j++)
            std::cout << _VecList[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int number[4][4] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
    std::vector<std::vector<int>> int_vec_vec(4);
    for (int i = 0; i < 4; i++)
        int_vec_vec[i].resize(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int_vec_vec[i][j] = number[i][j];
        }
    }
    std::cout << "print VecList" << std::endl;
    printVec(int_vec_vec);

    std::cout << Solution().Find(7, int_vec_vec) << std::endl;
    return 0;
}