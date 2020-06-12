#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::vector<int> kRes;
        if (input.size() < k)
            return kRes;
        else if (input.size() == k)
        {
            std::sort(input.begin(), input.end());
            return input;
        }
        else
        {
            std::sort(input.begin(), input.end());
            return std::vector<int>(input.begin(), input.begin() + k);
        }
    }
};

int main(int argc, char **argv)
{
    return 0;
}
