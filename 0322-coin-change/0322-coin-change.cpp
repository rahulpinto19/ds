class Solution {
public:
    int dp[13][100001];
    int help(vector<int>&coins,int pos,int amount)
    {
        if(amount == 0) return 0;
        if(amount<0) return 1e9;
        if(pos>=coins.size()) return   1e9; 
        
        if(dp[pos][amount] != -1)
        return dp[pos][amount];

        int take = 1 + help(coins,pos,amount - coins[pos]);
        int nottake = help(coins,pos+1,amount);

        return dp[pos][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        // memset(dp,-1,sizeof(dp));
        // int maxCoins  = help(coins,0,amount);
        // return 1e9 == maxCoins ? -1 : maxCoins;
        // vector<vector<int>>DP(coins.size()+1,vector<int>(amount+1,0));
        vector<int>DP(amount+1,amount+1);
        DP[0] = 0;
        for(int a=1;a<amount+1;a++)
        {
            for(int ind = 0;ind<coins.size();ind++)
            {
                if(a-coins[ind] >= 0)
                {
                    DP[a] = min(DP[a],1 + DP[a-coins[ind]]);
                }
            }
        }
        if(DP[amount] == amount + 1) return -1;
        return DP[amount];
    }
};