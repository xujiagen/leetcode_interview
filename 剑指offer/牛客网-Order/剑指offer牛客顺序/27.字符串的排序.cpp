#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> Permutation(std::string str)
    {
        std::vector<std::string> result;
        if (str.size() < 1)
            return result;
        sortString(result, str, 0, str.size());
        std::set<std::string> strSet(result.begin(), result.end());
        std::vector<std::string> strList(strSet.begin(), strSet.end());
        std::sort(strList.begin(), strList.end());
        return strList;
    }
    void sortString(std::vector<std::string> &_Res, std::string _Str, int index, int length)
    {
        if (index == length - 1)
        {
            _Res.push_back(_Str);
            return;
        }
        for (int i = index; i < length; i++)
        {
            std::swap(_Str[index], _Str[i]);
            sortString(_Res, _Str, index + 1, length);
            std::swap(_Str[index], _Str[i]);
        }
    }
};

int main(int argc, char **argv)
{
    std::string str("a");
    std::vector<std::string> strList = Solution().Permutation(str);
    for (int i = 0; i < strList.size(); i++)
    {
        std::cout << strList[i] << std::endl;
    }
    std::cout << "strList size: " << strList.size() << std::endl;
    return 0;
}