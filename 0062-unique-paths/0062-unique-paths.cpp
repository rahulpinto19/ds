class Solution {
public:
    int count =0;
    int help(int i,int j,vector<vector<int>>&vis)
    {
        if(i>=vis.size()||j>=vis[0].size())
        {
            return 0;
        }
        if(i==vis.size()-1 and j==vis[0].size()-1)
        {return 1;}
        if(vis[i][j]!=-1)
        return vis[i][j];
        else 
        return vis[i][j]=
        help(i+1,j,vis)+
        help(i,j+1,vis);
    }
    int uniquePaths(int m, int n) 
    {
        // vector<vector<int>>grid(m,vector<int>(n,-1));
        // return  help(0,0,grid);   
        // vector<vector<int>>dp(m,vector<int>(n,0));

        // dp[0][0] = 1;
        // for(int i=0;i<dp.size();i++)
        // {
        //     for(int j=0;j<dp[0].size();j++)
        //     {
        //         if(i ==0 and j==0)
        //         continue;

        //         int a=0,b=0;
        //         if(i-1>=0)
        //         a=dp[i-1][j];
        //         if(j-1>=0)
        //         b = dp[i][j-1];
                
        //         dp[i][j] = a+b;
        //     }
        // }
        // return dp[m-1][n-1];
        
        m--;
        n--;
        long long res = 1;
        if(m>n)
            swap(m,n);
         for (int i = 1; i <= m; i++) {
            res = res * (n + i) / i;  // Multiply and divide in a single step
        }
        return int(res);

    }
};