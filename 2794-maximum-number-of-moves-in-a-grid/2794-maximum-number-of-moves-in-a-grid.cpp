class Solution {
public:
    int dp[1001][1001];
    int help(int i,int j,vector<vector<int>>&nums)
    {
        if(i>=nums.size() || i<0 || j>= nums[0].size())
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int a,b,c;
        a=b=c=0;
        if(j+1 < nums[0].size())
        {
            if(i-1 >=0 and nums[i][j] < nums[i-1][j+1])
            {
                a = 1+help(i-1,j+1,nums);
            }
            if( nums[i][j] < nums[i][j+1])
            {
                b = 1+help(i,j+1,nums);
            }
            if(i+1 <nums.size() and nums[i][j] < nums[i+1][j+1])
            {
                c = 1+help(i+1,j+1,nums);
            }
        }

        return dp[i][j] =  max({a,b,c});
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        int ans =0;
        for(int i=0;i<grid.size();i++)
        {
            ans = max(ans,help(i,0,grid));
        }
        return ans;
    }
};