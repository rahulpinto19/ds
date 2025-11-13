class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // int dp[amount +1][amount+1];
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;

        for(int i = 1 ;i<=amount;i++) {

            for(auto x:coins) {

                if(i - x >= 0) {
                    dp[i] = min(dp[i],1 + dp[i-x]);
                }
            }
        }
        if(dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];

    }
};
// 1 2 3 4 5 6 7 8 9 10 11
// [1,1,]