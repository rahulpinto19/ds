class Solution {
public:
    void convertOnetoZero(int i,int j, vector<vector<int>>& grid)
    {
        grid[i][j] = 0;

        int dir[5] = {-1,0,1,0,-1};

        for(int ind = 1;ind<5;ind++)
        {
            int x = i + dir[ind];
            int y = j + dir[ind-1];

            if(x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y])
                convertOnetoZero(x,y,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        for(int i = 0;i<grid.size();i++)
        {
            if(grid[i][0])
            convertOnetoZero(i,0,grid);
            if(grid[i][grid[0].size()-1])
            convertOnetoZero(i,grid[0].size()-1,grid);

        }    
        for(int j =0;j<grid[0].size();j++)
        {
            if(grid[0][j])
                convertOnetoZero(0,j,grid);
            if(grid[grid.size()-1][j])
                convertOnetoZero(grid.size()-1,j,grid);
        }
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0 ;j<grid[0].size();j++)
                ans+=grid[i][j];
        }
        return ans;
    }
};