class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int dp[high +1];
        memset(dp,0,sizeof(dp));
        int mod = 1e9 + 7;
        dp[0] = 1;
        for(int i = min(zero,one);i<=high;i++)
        {
            if(i>=zero)
                dp[i] = (dp[i] + dp[i-zero])%mod;
            if(i>=one)
                dp[i] = (dp[i] + dp[i-one])%mod;
        }    
        int sum = 0;
        for(int i = low;i<=high;i++)
            sum = (sum + dp[i])%mod;

        return sum;
    }
};