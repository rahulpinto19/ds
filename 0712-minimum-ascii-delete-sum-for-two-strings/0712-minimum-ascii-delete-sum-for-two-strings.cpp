class Solution {
public:
    int dp[1001][1001];
    int help(string t1,string t2,int i,int j) {

        if(i>=t1.size() || j>=t2.size()) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        if(t1[i] == t2[j])
            return dp[i][j] = t1[i] + help(t1,t2,i+1,j+1);
        else
            return dp[i][j] = max(
                help(t1,t2,i,j+1),
                help(t1,t2,i+1,j)
            );
    }
 
    int minimumDeleteSum(string s1, string s2) {
        
       

        int sum1 = 0,sum2 = 0;

        for(auto x:s1) sum1 +=x;
        
        for(auto x:s2) sum2 +=x;

       int n = s1.size(), m = s2.size();
       vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {

                if(s1[i] == s2[j]) {
                    dp[i+1][j+1] = s1[i] + dp[i][j];
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        
        return sum1 + sum2 - (2*dp[n][m]);
    }
};