#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jumpFloor(int number)
    {
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        int front = 1, middle = 2, back;
        for (int i = 2; i < number; i++)
        {
            back = front + middle;
            front = middle;
            middle = back;
        }
        return back;
    }
};

int main(int argc, char **argv)
{
    std::cout << "jumpFloor: " << Solution().jumpFloor(3) << std::endl;
    return 0;
}