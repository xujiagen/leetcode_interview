/*
输入一个矩阵，顺时针从外向里打印这个矩阵
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
class Solution 
{
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {
        std::cout<<1<<std::endl;
        std::vector<int> vec_int;
        if(!matrix.size()) return vec_int;
        int cols=matrix.size();//行
        if(cols==1) return matrix[0];//如果只有一行，那就返回这一行
        if(!matrix[0].size()) return vec_int;
        int rows=matrix[0].size();//列
        print_matrix(matrix,vec_int,0,cols-1,0,rows-1);
        return vec_int;
    }
    void print_matrix(std::vector<std::vector<int> > matrix,std::vector<int>& vec_int,int col,int cols,int row,int rows)
    {
        if(col>cols || row > rows) return;
        if(col==cols)
        {
            for(int i=row;i<=rows;i++) vec_int.push_back(matrix[col][i]);
            return;
        }
        if(row==rows)
        {
            for(int i=col;i<=cols;i++) vec_int.push_back(matrix[i][row]);
            return;
        }
        for(int i=row;i<rows;i++) vec_int.push_back(matrix[col][i]);
        for(int i=col;i<cols;i++) vec_int.push_back(matrix[i][rows]);
        for(int i=rows;i>row;i--) vec_int.push_back(matrix[cols][i]);
        for(int i=cols;i>col;i--) vec_int.push_back(matrix[i][row]);
        print_matrix(matrix,vec_int,col+1,cols-1,row+1,rows-1);
    }
};
*/

class Solution
{
public:
    std::vector<int> printMatrix(std::vector<std::vector<int>> matrix)
    {
        std::vector<int> result;
        if (matrix.size() < 1)
            return result;
        const int &rows = matrix.size();
        if (matrix[0].size() < 1)
            return result;
        const int &cols = matrix[0].size();
        int xLeft = 0, xRight = rows - 1, yUp = 0, yDown = cols - 1;
        std::vector<std::pair<int, int>> pairList;
        pairList.push_back(std::pair<int, int>(0, 1));
        pairList.push_back(std::pair<int, int>(1, 0));
        pairList.push_back(std::pair<int, int>(0, -1));
        pairList.push_back(std::pair<int, int>(-1, 0));
        std::pair<int, int> start(0, 0);
        int count = 0;
        while (xLeft <= xRight && yUp <= yDown)
        {
            result.push_back(matrix[start.first][start.second]);
            if (count % 4 == 0 && start.second == yDown)
            {
                count++;
                xLeft++;
            }
            if (count % 4 == 1 && start.first == xRight)
            {
                count++;
                yDown--;
            }
            if (count % 4 == 2 && start.second == yUp)
            {
                count++;
                xRight--;
            }
            if (count % 4 == 3 && start.first == xLeft)
            {
                count++;
                yUp++;
            }
            start.first += pairList[count % 4].first;
            start.second += pairList[count % 4].second;
        }
        return result;
    }
};

void print2DMatrix(std::vector<std::vector<int>> &_Matrix)
{
    if (_Matrix.size() < 1)
        return;
    if (_Matrix[0].size() < 1)
        return;
    for (int i = 0; i < _Matrix.size(); i++)
    {
        for (int j = 0; j < _Matrix[0].size(); j++)
        {
            std::cout << _Matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::vector<int>> vec_vec_int;
    for (int i = 0; i < 5; i++)
    {
        std::vector<int> vec_int;
        for (int j = 0; j < 5; j++)
        {
            vec_int.push_back(i * j);
        }
        vec_vec_int.push_back(vec_int);
    }
    print2DMatrix(vec_vec_int);
    std::vector<int> vec_int = Solution().printMatrix(vec_vec_int);
    for (int i = 0; i < vec_int.size(); i++)
    {
        std::cout << vec_int[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}