class Solution {
public:
   int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);

    // Base cases
    dp[0] = 1; 
    dp[1] = 1; 
  
    for (int i = 2; i <= n; ++i) 
    {
        for (int j = 1; j <= i; ++j) 
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    for(auto x:dp)
    {
        cout<<x<<" ";
    }
    return dp[n];
}
    
};