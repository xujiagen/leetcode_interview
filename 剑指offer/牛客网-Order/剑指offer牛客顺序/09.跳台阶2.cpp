#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int jumpFloorII(int number)
    {
        return std::pow(2, number - 1);
    }
};

int main(int argc, char **argv)
{
    return 0;
}