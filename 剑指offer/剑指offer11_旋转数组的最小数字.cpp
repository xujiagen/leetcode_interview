/*
34512
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        if(!rotateArray.size())
            return 0;//实在找不到你想要找的数据
        if(rotateArray[0]<rotateArray[rotateArray.size()-1])
            return rotateArray[0];
        //第一个数小于最后一个数说明第一个数就是最小的
        int index_1=0,index_e=rotateArray.size()-1;
        int middle;
        while(rotateArray[index_1]>=rotateArray[index_e])
        {
            if(index_e-index_1==1)
            {
                middle=index_e;
                break;
            }
            middle=(index_1+index_e)/2;//确定中间数据的位置
            if(rotateArray[index_1]==rotateArray[index_e] && rotateArray[index_1]==rotateArray[middle])
                return find_vec(rotateArray,index_1,index_e);//返回的是数组里面的第一个元素和数组里面最后一个元素
            if(rotateArray[middle]>=rotateArray[index_1])
                index_1=middle;
            else if(rotateArray[middle]<=rotateArray[index_e])
                index_e=middle;
        }
        return rotateArray[middle];
    }
    
    int find_vec(std::vector<int>& rotateArray,int index1,int index2)
    {
        int result=rotateArray[index1];
        for(int i=index1;i<index2;i++)
            if(rotateArray[i]<result)
                result=rotateArray[i];
        return result;
    }
};