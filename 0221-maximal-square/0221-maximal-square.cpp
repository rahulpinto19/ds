class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) 
    {
        int m = mat.size(),n = mat[0].size(),mx = 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(mat[i-1][j-1] == '1')
                {
                    dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
                    mx = max(mx,dp[i][j]);
                }
            }
        }
        return mx*mx;
    }
};