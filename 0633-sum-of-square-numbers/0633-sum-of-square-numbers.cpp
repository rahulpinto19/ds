class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        if(c<=1)
        return 1;
        long long int start =0,end = sqrt(c);
        int flag =0;
        while(start<=end)
        {
            long long int val = start*start + end*end;
            val == c ? flag =1 : val<c ? start++ : end--; 
           if(flag)
           return 1;
        }    
        return 0;
    }
};