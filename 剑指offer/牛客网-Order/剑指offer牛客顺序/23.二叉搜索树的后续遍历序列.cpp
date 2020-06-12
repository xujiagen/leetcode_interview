/*
输入一个整数数组，判断该数组是不是一个二叉搜索树的后续遍历序列，如果是输出yes,否则输出no
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() < 1)
            return false;
        return VerifySquenceOfList(sequence, 0, sequence.size() - 1);
    }
    bool VerifySquenceOfList(std::vector<int> &_Sequence, int _Front, int _Back)
    {
        if (_Front >= _Back)
            return true;
        int middle = _Front;
        while (middle < _Back && _Sequence[middle] < _Sequence[_Back])
            middle++;
        for (int i = middle; i < _Back; i++)
        {
            if (_Sequence[i] < _Sequence[_Back])
                return false;
        }
        return VerifySquenceOfList(_Sequence, _Front, middle - 1) && VerifySquenceOfList(_Sequence, middle, _Back - 1);
    }
};

int main(int argc, char **argv)
{
    int vec[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> vecList(vec, vec + sizeof(vec) / sizeof(int));
    std::cout << Solution().VerifySquenceOfBST(vecList) << std::endl;
    return 0;
}