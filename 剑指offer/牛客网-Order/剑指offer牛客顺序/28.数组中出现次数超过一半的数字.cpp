#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        std::sort(numbers.begin(), numbers.end());
        int &moreThanNum = numbers[numbers.size() / 2];
        int count = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == moreThanNum)
                count++;
        }
        if (count > numbers.size() / 2)
            return moreThanNum;
        else
            return 0;
    }
};

int main(int argc, char **argv)
{
    return 0;
}