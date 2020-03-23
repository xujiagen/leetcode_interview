#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/*
class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        int reverseCount = 0;
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 1; j < data.size() - i; j++)
            {
                if (data[j - 1] > data[j])
                {
                    std::swap(data[j - 1], data[j]);
                    reverseCount++;
                }
            }
        }
        return reverseCount;
    }
};
*/

class Solution
{
public:
    int InversePairs(std::vector<int> data)
    {
        if (data.size() < 2)
            return 0;
        reverseCount = 0;
        divideList(0, data.size() - 1, data);
        return (int)(reverseCount % 1000000007);
    }
    void divideList(int _Left, int _Right, std::vector<int> &_Data)
    {
        if (_Left == _Right)
            return;
        int middle = (_Left + _Right) >> 1;
        divideList(_Left, middle, _Data);
        divideList(middle + 1, _Right, _Data);
        mergeSort(_Left, _Right, middle, _Data);
    }
    void mergeSort(int _Left, int _Right, int _Middle, std::vector<int> &_Data)
    {
        std::vector<int> res(_Right - _Left + 1, 0);
        int leftCount = _Left, rightCount = _Middle + 1;
        int index = 0;
        while (leftCount <= _Middle && rightCount <= _Right)
        {
            if (_Data[leftCount] > _Data[rightCount])
            {
                res[index++] = _Data[rightCount++];
                reverseCount += _Middle - leftCount + 1;
            }
            else
                res[index++] = _Data[leftCount++];
        }
        while (leftCount <= _Middle)
            res[index++] = _Data[leftCount++];
        while (rightCount <= _Right)
            res[index++] = _Data[rightCount++];
        for (int i = _Left; i <= _Right; i++)
        {
            _Data[i] = res[i - _Left];
        }
    }

private:
    unsigned long reverseCount;
};

int main(int argc, char **argv)
{
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 0};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::vector<int> tempList;
    std::cout << Solution().InversePairs(vecList) << std::endl;
    //printList(Solution().InversePairs(vecList));
    return 0;
}