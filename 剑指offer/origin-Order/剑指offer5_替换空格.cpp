/*
该题的任务是将字符串中的空格替换成%20
从前往后将字符串中的空格替换成%20

return 表示停止当前的函数运行，并将操作权返回给调用者
在返回值是void类型的函数里面，可用return;来返回，表示将运行的操作权给操作系统
*/
#include<iostream>
#include<vector>
#include<string>

class Solution 
{
public:
	void replaceSpace(char *str,int length) {
        if(!str || length<=0)
            return;
        int originalLength=0;//原始字符串的长度
        int numberofblock=0;//空个的个数
        int i=0;
        while(str[i]!='\0')
        {
            originalLength++;
            if(str[i]==' ')
                numberofblock++;
            i++;
        }
        //上面计算出来传过来的字符串的长度和和这个字符串实际的长度
        int newlength=originalLength+2*numberofblock;//现在新的字符串需要的空间大小
        if(newlength>length)
            return;
        
        int indexoforiginal=originalLength;//原始的字符串指向最后一个字符
        int indexofnew=newlength;//新的字符串指向最后一个字符
        while(indexoforiginal>=0 && indexofnew>indexoforiginal)
        {
            //新的字符串的指针应该比旧了字符串的指针位置要靠后，但是当新的字符串的位置不比旧了字符串的位置靠后
            if(str[indexoforiginal]==' ')
            {
                str[indexofnew--]='0';
                str[indexofnew--]='2';
                str[indexofnew--]='%';
            }
            else
            {
                str[indexofnew--]=str[indexoforiginal];
            }
            --indexoforiginal;
        }
	}
};

class solution
{
    void replaceSpace(char* str,int length)
    {
        if(!str || !length)
            return;
        int length_first=0;
        int number_block=0;
        int i=0;
        while(str[i]!='\0')
        {
            length_first++;
            if(str[i]==' ')
                number_block++;
            i++;
        }
        int length_second=length_first+number_block*2;
        while(length_second>=0 && length_second>length_first)
        {
            if(str[length_first]==' ')
            {
                str[length_second--]='0';
                str[length_second--]='2';
                str[length_second--]='%';
            }
            else
            {
                str[length_second]=str[length_first];
            }
            length_first--;
        }
    }
};

int main()
{
    char a[15]="hello world";
    Solution a1;
    Solution a2;
    a2.replaceSpace(a,15);
    //a1.replaceSpace(a,15);
    std::cout<<a<<std::endl;
    return 0;
}