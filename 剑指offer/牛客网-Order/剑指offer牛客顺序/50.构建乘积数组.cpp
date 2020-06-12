#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        std::vector<int> leftB(A.size(), 1);
        std::vector<int> rightB(A.size(), 1);
        for (int i = 1; i < A.size(); i++)
        {
            leftB[i] = leftB[i - 1] * A[i - 1];
            rightB[A.size() - i - 1] = rightB[A.size() - i] * A[A.size() - i];
        }
        std::vector<int> B(A.size(), 1);
        for (int i = 0; i < A.size(); i++)
            B[i] = leftB[i] * rightB[i];
        return B;
    }
};