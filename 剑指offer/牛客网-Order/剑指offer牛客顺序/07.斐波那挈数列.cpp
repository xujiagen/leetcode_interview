#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int front = 1, middle = 1, back;
        for (int i = 2; i < n; i++)
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
    std::cout << "fibonacci: " << Solution().Fibonacci(3) << std::endl;
    return 0;
}