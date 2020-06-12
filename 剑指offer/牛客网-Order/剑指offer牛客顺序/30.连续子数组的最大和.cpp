#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int FindGreatestSumOfSubArray(std::vector<int> array)
    {
        if (array.size() < 1)
            return 0;
        int sumUp = array[0];
        int front = 0, back = 0;
        int maxCount = array[0];
        for (int i = 0; i < array.size(); i++)
        {
            back = i;
            int tmpSum = 0;
            for (int i = front; i <= back; i++)
                tmpSum += array[i];
            maxCount = max(maxCount, max(tmpSum, array[i]));
            if (tmpSum < 0)
                front = i + 1;
        }
        return maxCount;
    }
};

int main(int argc, char **argv)
{
    int vec[] = {6, -3, -2, 7, -15, 1, 2, 2};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::cout << "max constant list: " << Solution().FindGreatestSumOfSubArray(vecList) << std::endl;
    return 0;
}