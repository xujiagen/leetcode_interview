#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
struct data
{
    std::string str;
    std::string addr;
    std::string mask;
    std::string val;
};

std::string splitStr(std::string str, std::string check, std::unordered_set<char> &_CharSet)
{
    int left = 0;
    std::vector<std::string> strList;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '[' || str[i] == ',' || str[i] == ']')
        {
            strList.push_back(str.substr(left, i - left));
            left = i + 1;
        }
    }
    /*
    for (int i = 0; i < strList.size(); i++)
    {
        std::cout << strList[i] << " ";
    }
    std::cout << std::endl;
    */
    //std::cout << strList[0] << " " << check << std::endl;
    if (check != strList[0])
        return "";
    if (strList.size() != 4)
        return "";
    //return false;
    if (strList[1].substr(0, 5) != "addr=")
        return "";
    //return false;
    if (strList[2].substr(0, 5) != "mask=")
        return "";
    //return false;
    if (strList[3].substr(0, 4) != "val=")
        return "";
    //return false;
    std::string first = strList[1].substr(5, strList[1].size() - 5);
    std::string second = strList[2].substr(5, strList[2].size() - 5);
    std::string third = strList[3].substr(4, strList[3].size() - 4);
    if ((first.substr(0, 2) != "0x" || first.substr(0, 2) != "0X") && (second.substr(0, 2) != "0x" || second.substr(0, 2) != "0X") && (third.substr(0, 2) != "0x" || third.substr(0, 2) != "0X"))
        return "";
    //return false;
    for (int i = 2; i < first.size(); i++)
    {
        if (_CharSet.find(first[i]) == _CharSet.end())
            return "";
    }
    for (int i = 2; i < second.size(); i++)
    {
        if (_CharSet.find(second[i]) == _CharSet.end())
            return "";
    }
    for (int i = 2; i < third.size(); i++)
    {
        if (_CharSet.find(third[i]) == _CharSet.end())
            return "";
    }
    std::string tmp = first + " " + second + " " + third;
    return tmp;
    //std::string = std::cout << first << " " << second << " " << third << std::endl;
    //return true;
}
/*
data readData(std::string str)
{
    data tmp;
    for (int i = 0; i < str.size() - 4; i++)
    {
        if (str[i] == '[')
            tmp.str = str.substr(0, i);
        if (str.substr(i, 5) == "addr=")
        {
            tmp.addr = str.substr(i + 5)
        }
    }
*/
int main(int argc, char **argv)
{
    std::vector<char> vecChar = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F'};
    std::unordered_set<char> charSet(vecChar.begin(), vecChar.end());
    //std::string str("read read[addr=0x17,mask=0xff,val=0x7],read_his[addr=0xff,mask=0xff,val=0x1],read[addr=0xf0,mask=0xff,val=0x80]");
    std::string str;
    std::cin >> str;
    if (str.size() > 1024)
    {
        std::cout << "FAIL" << std::endl;
        return 0;
    }
    std::string targetStr, readingStr;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            targetStr = str.substr(0, i);
            readingStr = str.substr(i + 1, str.size() - i - 1);
            break;
        }
    }
    //std::cout << "target:" << targetStr << std::endl
    //          << "reading:" << readingStr << std::endl;
    std::vector<std::string> strList;
    int start = 0;
    for (int i = 0; i < readingStr.size(); i++)
    {
        if (readingStr[i] == ']')
        {
            strList.push_back(readingStr.substr(start, i - start + 1));
            start = i + 2;
        }
    }
    /*
    for (int i = 0; i < strList.size(); i++)
    {
        std::cout << strList[i] << std::endl;
    }
    */
    std::vector<std::string> final;
    for (int i = 0; i < strList.size(); i++)
    {
        std::string tmp = splitStr(strList[i], targetStr, charSet);
        if (tmp.size() > 1)
            final.push_back(tmp);
    }
    if (final.size() < 1)
        std::cout << "FAIL" << std::endl;
    else
    {
        std::unordered_set<std::string> finalSet(final.begin(), final.end());
        final = std::vector<std::string>(finalSet.begin(), finalSet.end());
        for (int i = 0; i < final.size(); i++)
        {
            std::cout << final[i] << std::endl;
        }
    }
    return 0;
}