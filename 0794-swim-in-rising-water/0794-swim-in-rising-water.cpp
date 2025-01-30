class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j,int depth,vector<vector<int>>&vis)
    {
        vis[i][j] = 1;
        if(i == grid.size()-1 and j == grid[0].size()-1)
        {
            return depth >= grid[i][j];
        }
            
        int dir[5] = {-1,0,1,0,-1};
        int ans = 0;
        for(int k = 1;k<5;k++)
        {
            int nx = i+ dir[k] , ny = j + dir[k-1];
            if(nx >=0 and ny>=0 and nx < grid.size() and ny < grid[0].size() and 
            grid[nx][ny] !=-1 and grid[nx][ny]<=depth and !vis[nx][ny]
            )
            ans|=dfs(grid,nx,ny,depth,vis);
        }
        return ans;
    }
    int swimInWater(vector<vector<int>>& grid) 
    {
        int start = 0 ,end =   2501;
        int ans = INT_MAX;
        for(int i=14;i<16;i++)
        {
            vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
            cout<<dfs(grid,0,0,i,vis)<<endl;
        }
        

        while(start<end)
        {
            int mid = (start + end)/2;
            vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
            bool minpath = dfs(grid,0,0,mid,vis);
            if(minpath and grid[0][0]<=mid)
            {
                ans = min(ans,mid);
                end = mid;
            }
            else
            {
                start = mid+1;
                
            }
        }
        return ans;
    }
};