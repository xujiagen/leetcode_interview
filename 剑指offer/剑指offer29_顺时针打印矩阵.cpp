/*
顺时针打印一个矩阵
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {
        std::vector<int> int_vec;//这个容器里面存储的是要输出的元素
        int rows=matrix.size()-1;//4
        int cols;
        int col=0,row=0;
        if(matrix.size()<1)
            return int_vec;
        else if(matrix.size()==1)
        {
            return matrix[0];
        }
        else
        {
            cols=matrix[0].size()-1;//存储这个矩阵里面每一列的元素
        }
        print4(matrix,0,rows,0,cols,int_vec);
        return int_vec;
    }
    void print4(vector<vector<int> > matrix,int row,int rows,int col,int cols,std::vector<int>& int_vec)
    {
        if(rows-row>=1 && cols-col>=1)
        {
            for(int i=col;i<=cols;i++)
                int_vec.push_back(matrix[row][i]);
            for(int i=row+1;i<=rows;i++)
                int_vec.push_back(matrix[i][cols]);
            for(int i=cols-1;i>=col;i--)
                int_vec.push_back(matrix[rows][i]);
            for(int i=rows-1;i>=row+1;i--)
                int_vec.push_back(matrix[i][col]);
            if(col+1<=cols-1 && row+1<=rows-1)
            {
                print4(matrix,row+1,rows-1,col+1,cols-1,int_vec);
                return;
            }
            else
                return;
        }
        if(rows-row==0)
        {
            for(int i=col;i<=cols;i++)
                int_vec.push_back(matrix[row][i]);
            return;
        }
        if(cols-col==0)
        {
            for(int i=row;i<=rows;i++)
                int_vec.push_back(matrix[i][col]);
            return;
        }
    }
};

int main()
{
    std::vector<std::vector<int> > int_vec_vec(5);
    for(int i=0;i<5;i++)
        int_vec_vec[i].resize(5);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            int_vec_vec[i][j]=i*5+j;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            std::cout<<int_vec_vec[i][j]<<"\t";
        std::cout<<std::endl;
    }
    Solution a;
    std::vector<int> int_vec=a.printMatrix(int_vec_vec);
    for(int i=0;i<int_vec.size();i++)
    {
        std::cout<<int_vec[i]<<"\t";
        if((i+1)%10==0)
            std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}