#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        std::vector<std::vector<int>> res;
        if (sum < 3)
            return res;
        int left = 1;
        int tmpSum = 0;
        std::vector<int> tmpList;
        for (int i = 1; i <= (sum + 1) / 2; i++)
        {
            int right = i;
            tmpSum += i;
            if (tmpSum == sum)
            {
                tmpList.clear();
                for (int i = left; i <= right; i++)
                    tmpList.push_back(i);
                res.push_back(tmpList);
            }
            if (tmpSum < sum)
                continue;
            if (tmpSum > sum)
            {
                while (tmpSum >= sum)
                {
                    if (tmpSum == sum)
                    {
                        tmpList.clear();
                        for (int i = left; i <= right; i++)
                            tmpList.push_back(i);
                        res.push_back(tmpList);
                        break;
                    }
                    else
                    {
                        tmpSum -= left;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    std::vector<std::vector<int>> res = Solution().FindContinuousSequence(3);
    for (int i = 0; i < res.size(); i++)
    {
        std::vector<int> &tmpList = res[i];
        for (int j = 0; j < tmpList.size(); j++)
        {
            std::cout << tmpList[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}