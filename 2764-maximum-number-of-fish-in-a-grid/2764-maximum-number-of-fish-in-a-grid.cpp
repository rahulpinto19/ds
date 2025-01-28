class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    
    void bfs(int i, int j ,vector<vector<int>>& grid,int &sum)
    {
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j] ==0)
            return ;
        int curr = grid[i][j];
        grid[i][j] = 0;
        sum+=curr;
        for(int k = 1;k<5;k++)
        {
            int X = dir[k] + i,Y = dir[k-1] + j;
            if(X<0 ||  Y<0 || X>=grid.size() || Y>= grid[0].size() || grid[X][Y] ==0)
                continue;
            else
            {
                 bfs(X,Y,grid,sum); 
            }
        }
        return;
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    int sum = 0;
                    bfs(i,j,grid,sum);
                    ans = max(ans,sum);
                }
            }
        }    
        return ans;
    }
};