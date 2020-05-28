#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
int main(int argc, char **argv)
{
    std::vector<int> vecList = {2, 1, 4, 3};
    int value = 21;
    int step = 0;
    int position = 0;
    int stayCount = 0;
    while (value && step < vecList.size())
    {
        //std::cout << "pos: " << position << " value: " << value << " stayCount: " << stayCount << std::endl;
        if (position == vecList.size())
            position = 0;
        if (value >= vecList[position])
        {
            stayCount++;
            value -= vecList[position];
        }
        else
        {
            step++;
        }
        position++;
    }
    std::cout << stayCount << std::endl;
    return 0;
}