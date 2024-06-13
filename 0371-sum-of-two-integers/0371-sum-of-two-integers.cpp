class Solution {
public:
    int getSum(int a, int b) 
    {
        if(!b)return a;

        int sum = a^b;
        int add = (unsigned int)(a&b)<<1;

        return getSum(sum,add);    
    }
};