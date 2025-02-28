class Solution {
public:
    string shortestCommonSupersequence(string a, string b) 
    {
        int m = a.size(),n = b.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
       for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                dp[i+1][j+1] = a[i] == b[j] ? dp[i][j] + 1 : max(dp[i+1][j],dp[i][j+1]);
            }
        } 
        int i=m,j=n;
        string ans = "";
        while(i>0 and j>0)
        {
            if(a[i-1] == b[j-1])
            {
                ans+=a[i-1];i--;j--;
            }
            else if (dp[i-1][j] > dp[i][j-1])
            {
                ans+=a[i-1];i--;
            }
            else
            {
                ans+=b[j-1];j--;
            }
        }
        while(i>0)
        {
            ans+=a[i-1];
            i--;
        }
        while(j>0)
        {ans+=b[j-1];j--;}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};