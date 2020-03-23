#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
class Solution 
{
public:
    void reOrderArray(vector<int> &array)
    {
        if(array.size()<2) return;
        for(int i=0;i<array.size();i++)
            for(int j=array.size()-1;j>i;j--)
            {
                if(array[j-1]%2==0 && array[j]%2)
                    std::swap(array[j-1],array[j]);
            }
    }
};

void print_vec(std::vector<int> vec_int)
{
    for(std::vector<int>::iterator iter=vec_int.begin();iter!=vec_int.end();iter++)
        std::cout<<*iter<<" ";
    std::cout<<std::endl;
}
*/

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        if (array.size() < 2)
            return;
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j - 1] % 2 == 0 && array[j] % 2 == 1)
                    std::swap(array[j - 1], array[j]);
            }
        }
    }
};

template <class T>
void printList(typename std::vector<T> &_VecList)
{
    for (int i = 0; i < _VecList.size(); i++)
    {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec_int(a1, a1 + sizeof(a1) / sizeof(int));
    printList(vec_int);

    Solution().reOrderArray(vec_int);
    printList(vec_int);
    return 0;
}