class Solution {
public:
    int dp[201][201];
    int dfs(vector<vector<int>>& mat,int i,int j,int prev)
    {
       
        if(mat[i][j] == -1e9)
            return 0;
        int count = 1;
       
        int temp = mat[i][j];

        if(dp[i][j] != -1)
        return dp[i][j];
        
        mat[i][j] = -1e9;
        int dir[5] = {-1,0,1,0,-1};
        for(int k =1;k<5;k++)
        {
            int x = i + dir[k] ,y = j + dir[k-1];
            if(x>=0 and y>=0 and x<mat.size() and y<mat[0].size() and mat[x][y] > prev)
            {
                count = max(count,1 + dfs(mat,x,y,mat[x][y]));
            }
        }
        mat[i][j] = temp;
        return dp[i][j] = count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int ans = 1;
        memset(dp,-1,sizeof(dp));
        for(int i =0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                int pathcount = dfs(matrix,i,j,matrix[i][j]);
                ans = max(ans,pathcount);
            }
        }
        return ans;
    }
};