#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.size() < 1)
            return 0;
        return FindPosition(data, double(k) + 0.5) - FindPosition(data, double(k) - 0.5);
    }
    int FindPosition(std::vector<int> &_Data, double K)
    {
        int left = 0, right = _Data.size() - 1;
        int middle = (left + right) >> 1;
        if (K <= double(_Data[left]))
            return -1;
        if (K >= double(_Data[right]))
            return right;
        while (left < right)
        {
            if (double(_Data[left]) < K && double(_Data[right]) > K && left + 1 == right)
                return left;
            int middle = (left + right) >> 1;
            //std::cout << "left: " << left << " middle: " << middle << " right: " << right << std::endl;
            if (double(_Data[middle]) < K)
                left = middle;
            if (double(_Data[middle]) > K)
                right = middle;
        }
        return left;
    }
};

int main(int argc, char **argv)
{
    int vec[] = {3, 3, 3, 3, 4, 5};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::cout << Solution().GetNumberOfK(vecList, 3) << std::endl;
    return 0;
}