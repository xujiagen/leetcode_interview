#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution 
{
public:
    int romanToInt(string s) 
    {
        int num=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s.substr(i,2)=="CM")
                s.replace(i,2,"1");
            else if(s.substr(i,2)=="CD")
                s.replace(i,2,"2");
            else if(s.substr(i,2)=="XC")
                s.replace(i,2,"3");
            else if(s.substr(i,2)=="XL")
                s.replace(i,2,"4");
            else if(s.substr(i,2)=="IX")
                s.replace(i,2,"5");
            else if(s.substr(i,2)=="IV")
                s.replace(i,2,"6");
        }
        
        int i=0;
        while(s[i])
        {
            switch(s[i])
            {
            case '1':num+=900;break;
            case '2':num+=400;break;
            case '3':num+=90;break;
            case '4':num+=40;break;
            case '5':num+=9;break;
            case '6':num+=4;break;

            case 'M':num+=1000;break;
            case 'D':num+=500;break;
            case 'C':num+=100;break;
            case 'L':num+=50;break;
            case 'X':num+=10;break;
            case 'V':num+=5;break;
            case 'I':num+=1;break;
            }
            i++;
        }
        
        return num;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    std::cout<<a.romanToInt("MCMXCIV")<<std::endl;
    return 0;
}
