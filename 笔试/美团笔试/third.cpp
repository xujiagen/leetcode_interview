#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>

int tmpMax(std::vector<int> &list, std::vector<double> &properties, int &count)
{
    int maxIndex = 0;
    double maxCount = properties[0];
    for (int i = 0; i < count; i++)
    {
        if (maxCount < properties[i])
        {
            maxCount = properties[i];
            maxIndex = i;
        }
    }
    count = count - maxIndex - 1;
    return maxIndex;
}
int main(int argc, char **argv)
{
    int size = 3;
    std::vector<double> properties = {0.9, 0.1, 0.1};
    std::vector<int> countList = {2, 1, 1};
    std::vector<double> proertiesList(countList.size(), 0);
    double res = 0;
    double proSum = 1;
    while (size)
    {
        int tmpIndex = tmpMax(countList, properties, size);
        res += proSum * properties[tmpIndex] * countList[tmpIndex];
        proSum = proSum * properties[tmpIndex];
    }
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpoint);
    std::cout.precision(2);
    std::cout << res << std::endl;
    //std::cout << std::setiosflags(std::fixed) << std::setprecision(2) << res << std::endl;
    return 0;
}