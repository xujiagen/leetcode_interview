#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        if (numbers.size() < 1)
            return std::string();
        else if (numbers.size() == 1)
            return std::to_string(numbers[0]);
        else
        {
            for (int i = 0; i < numbers.size() - 1; i++)
            {
                for (int j = i + 1; j < numbers.size(); j++)
                {
                    std::string tmpFirst = std::to_string(numbers[i]) + std::to_string(numbers[j]);
                    std::string tmpSecond = std::to_string(numbers[j]) + std::to_string(numbers[i]);
                    if (tmpFirst.compare(tmpSecond) > 0)
                        std::swap(numbers[i], numbers[j]);
                }
            }
        }
        std::string tmpStr;
        for (int i = 0; i < numbers.size(); i++)
        {
            tmpStr += std::to_string(numbers[i]);
        }
        return tmpStr;
    }
};

int main(int argc, char **argv)
{
    int vec[] = {3, 5, 1, 4, 2};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::cout << Solution().PrintMinNumber(vecList) << std::endl;
    return 0;
}