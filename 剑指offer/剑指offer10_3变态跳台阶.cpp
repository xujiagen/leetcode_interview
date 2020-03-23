class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0)
            return 0;
        else
        {
            return pow(2,number-1);
        }
    }
};