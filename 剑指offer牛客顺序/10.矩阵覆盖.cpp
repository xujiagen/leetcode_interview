#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int rectCover(int number)
    {
        if (number == 0)
            return 0;
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
    std::cout << "rectCover: " << Solution().rectCover(3) << std::endl;
    return 0;
}