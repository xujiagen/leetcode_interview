/*
实现一个函数将字符串中每一个空格替换成%20,
这里输入的是一个指针，指向我们创建的字符串数组，length表示这个字符串数组的总容量

c语言的字符串结束符是‘\0’ 判断字符串的结束符是不是‘\0’来判断输入字符串的长度
*/

/*
class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        if(str[0]=='\0') return;//第一个就是我们换行符说明这个数组到这里就足够了
        int distance=0;
        int space=0;
        while(str[distance]!='\0')
        {

            if(str[distance]==' ') space++;
            distance++;
        }
        if(space==0) return;
        int must_length=distance+space*2;
        if(length<must_length) return;//这里是应为字符串的长度不够
        
        //上面是在设计一个初始的步骤，下面开始向数组里面添加字符串
        while(must_length>distance && distance>=0)
        {
            if(str[distance]==' ')
            {
                distance--;
                str[must_length--]='0';
                str[must_length--]='2';
                str[must_length--]='%';
            }
            else
            {
                str[must_length--]=str[distance--];
            }
            
        }
        return;
    }
};
*/

/*
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        if (!str || length < 1)
            return;
        int wholeLength = 0;
        int spaceCount = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
                spaceCount++;
        }
        wholeLength = length + 2 * spaceCount;
        wholeLength--;
        for (int i = length - 1; i >= 0; i--)
        {
            if (i == wholeLength)
                return;
            if (str[i] == ' ')
            {
                str[wholeLength--] = '0';
                str[wholeLength--] = '2';
                str[wholeLength--] = '%';
            }
            else
            {
                str[wholeLength--] = str[i];
            }
        }
    }
};
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        if (length == 0 || str[0] == '\0')
            return;
        int wholeLength = 0;
        int spaceCount = 0;
        while (str[wholeLength] != '\0')
        {
            if (str[wholeLength] == ' ')
                spaceCount++;
            wholeLength++;
        }
        int finalLength = wholeLength + 2 * spaceCount;
        if (finalLength > length || spaceCount == 0)
            return;
        // calc length more than origin length
        while (finalLength > wholeLength && wholeLength >= 0)
        {
            if (str[wholeLength] == ' ')
            {
                str[finalLength--] = '0';
                str[finalLength--] = '2';
                str[finalLength--] = '%';
                wholeLength--;
            }
            else
            {
                str[finalLength--] = str[wholeLength--];
            }
        }
    }
};
/*
对于char类型的字符串，需要注意的是，在程序的结束位置是'/0'结束标识符
*/
int main(int argc, char **argv)
{
    char *str = "We are Happy          ";
    std::string originStr(str, str + 12 / sizeof(char));
    std::cout << "str size: " << sizeof(str) << std::endl;
    std::cout << "origin string: " << std::endl;
    std::cout << originStr << std::endl;
    return 0;
}