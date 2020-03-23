/*
程序调试的环境https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
leetcode第47页
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) 
    {
        int rows=array.size();//获取二维数组的行数
        if(!rows)
            return false;
        int cols=array[0].size();
        if(!cols)
            return false;
        if(array[0][0]>target)
            return false;
        else if(array[0][0]==target)
            return true;
        else
        {
            int row=0,col=cols-1;
            while(row<rows && col>=0)
            {
                if(array[row][col]==target)
                {
                    return true;
                }
                else if(array[row][col]>target)
                    col--;
                else
                    row++;
            }
            return false;
        }
    }
};
*/

class Solution
{
public:
    bool Find(int target, std::vector<std::vector<int>> array)
    {
        }
};

template <class T>
void print(typename std::vector<std::vector<T>> &_VecList)
{
    const int &rows = _VecList.size();
    const int &cols = _VecList[0].size();
    if (rows < 1 || cols < 1)
        return;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << _VecList[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
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

    //print vec contests
    print<int>(int_vec_vec);

    //Solution a;
    //std::cout << a.Find(7, int_vec_vec) << std::endl;
    return 0;
}
