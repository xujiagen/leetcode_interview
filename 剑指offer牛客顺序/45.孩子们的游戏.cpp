#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1)
            return -1;
        std::vector<int> students;
        students.reserve(n);
        for (int i = 0; i < n; i++)
        {
            students.push_back(i);
        }
        int start = 0;
        while (students.size() > 1)
        {
            int tmpM = 1;
            while (tmpM++ < m)
            {
                if (start < students.size() - 1)
                {
                    start++;
                    continue;
                }
                if (start >= students.size() - 1)
                {
                    start = 0;
                    continue;
                }
            }

            //std::cout << "students: " << students[start] << std::endl;
            //printList(students);
            students.erase(students.begin() + start);
            //printList(students);
            if (start == students.size())
                start = 0;
            //std::cout << std::endl;
        }
        return students[0];
    }
};
void printList(std::vector<int> &_VecList)
{
    for (int i = 0; i < _VecList.size(); i++)
        std::cout << _VecList[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int students[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> studentsList(students, students + sizeof(students) / sizeof(int));
    std::cout << Solution().LastRemaining_Solution(6, 3) << std::endl;
    return 0;
}