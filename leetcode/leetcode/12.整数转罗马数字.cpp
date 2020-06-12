#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
    string intToRoman(int num) 
    {
        std::string str;
        int value[]={1000,500,100,50,10,5,1};
        char value_flag[]={'M','D','C','L','X','V','I'};
        int spaial_value[]={4,9,40,90,400,900};
        //char spcial_flag[]={""}
        std::vector<int> value_evc(value,value+sizeof(value)/sizeof(int));
        std::vector<char> flag_vec(value_flag,value_flag+sizeof(value_flag)/sizeof(char));
        
        //下面开始判断输入的字符串
        while(num)
        {
            if(num>=900 && num<1000)
            {
                num=num-900;
                str.append("CM");
                continue;
            }
            else if(num>=400 && num<500)
            {
                num=num-400;
                str.append("CD");
                continue;
            }
            else if(num>=90 && num<100)
            {
                num=num-90;
                str.append("XC");
                continue;
            }
            else if(num>=40 && num<50)
            {
                num=num-40;
                str.append("XL");
                continue;
            }
            else if(num==9)
            {
                num=num-9;
                str.append("IX");
                continue;
            }
            else if(num==4)
            {
                num=num-4;
                str.append("IV");
                continue;
            }
            //上面是一堆额外的判断条件
            
            char flag;
            for(int i=0;i<value_evc.size();i++)
                if(num>=value_evc[i])
                    {
                        num=num-value_evc[i];
                        flag=flag_vec[i];
                        break;
                    }
            std::string str1(1,flag);
            str.append(str1);

        }
        return str;
    }
};

int main()
{
    Solution a;
    std::cout<<a.intToRoman(40)<<std::endl;
    return 0;
}