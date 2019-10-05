/*
输入一个字符串，输出这个字符串的所有排列
注意:这个字符串了；里面可能存在字符的重复

//下面这种计算方式在牛客网上面提交没有通过，因为vector里面的string顺序还有要求
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<string> Permutation(string str)
    {
        std::vector<string> vec_str;
        if (str.size() < 1)
            return vec_str;
        permutation(vec_str, str, 0);
        return vec_str;
    }

    void permutation(std::vector<string> &vec_str, string str, int position)
    {
        if (position == str.size() - 1)
            vec_str.push_back(str);
        else
        {
            for (int i = position; i < str.size(); i++)
            {
                if (position != i && str[i] == str[position])
                    continue;
                else
                {
                    std::swap(str[position], str[i]);
                    permutation(vec_str, str, position + 1);
                    std::swap(str[position], str[i]);
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    string s = "aa";
    std::vector<string> vec_str = a.Permutation(s);
    for (int i = 0; i < vec_str.size(); i++)
    {
        std::cout << vec_str[i] << std::endl;
    }
    return 0;
}
