#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        int ans = n;
        n && (ans = ans + Sum_Solution(n - 1));
        return ans;
    }
};