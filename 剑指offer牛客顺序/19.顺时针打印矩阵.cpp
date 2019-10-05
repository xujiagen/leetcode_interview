/*
输入一个矩阵，顺时针从外向里打印这个矩阵
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

int main()
{
    std::vector<std::vector<int> > vec_vec_int;
    for(int i=0;i<5;i++)
    {
        std::vector<int> vec_int;
        for(int j=0;j<5;j++)
        {
            vec_int.push_back(i*j);
        }
        vec_vec_int.push_back(vec_int);
    }
    Solution a;
    std::vector<int> vec_int;
    vec_int =a.printMatrix(vec_vec_int);

    for(int i=0;i<vec_int.size();i++)
    {
        std::cout<<vec_int[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}