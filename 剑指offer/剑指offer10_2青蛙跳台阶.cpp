class Solution {
public:
    int jumpFloor(int number) 
    {
        if(!number)
            return 0;
        else if(number==1)
            return 1;
        else if(number==2)
            return 2;
        else
        {
            int last_1=2;
            int last_2=1;
            int last;
            for(int i=2;i<number;i++)
            {
                last=last_1+last_2;
                last_2=last_1;
                last_1=last;
            }
            return last;
        }
    }
};