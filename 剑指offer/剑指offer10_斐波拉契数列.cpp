class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        else if(n==1 || n==2)
            return 1;
        else
        {
            int last_1=1,last_2=0;
            int last;
            for(int i=2;i<=n;i++)
            {
                last=last_1+last_2;
                last_2=last_1;
                last_1=last;
            }
            return last;
        }
    }
};