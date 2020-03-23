#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        /*
        if (!numbers || length)
            return false;
            */
        for (int i = 0; i < length; i++)
        {
            if (numbers[i] == numbers[numbers[i]] && i != numbers[i])
            {
                *duplication = numbers[i];
                return true;
            }
            else if (i == numbers[i])
                continue;
            else if (numbers[i] != numbers[numbers[i]])
                std::swap(numbers[i], numbers[numbers[i]]);
        }
        return false;
    }
};
int main()
{
    int vec[] = {2, 1, 3, 1, 4};
    int value;
    std::cout << Solution().duplicate(vec, 5, &value) << " value: " << value << std::endl;
    return 0;
}