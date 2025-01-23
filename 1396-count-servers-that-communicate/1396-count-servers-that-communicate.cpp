class Solution {
public:
   
    int countServers(vector<vector<int>>& grid) 
    {
        

        unordered_map<int,int>x,y;
        for(int i = 0 ;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                    {
                        x[i]++;
                        y[j]++;
                    }
            }
        }
       
        int ans = 0;
        for(int i = 0 ;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] and (x[i] >1 or y[j] > 1))
                {
                     ans++;
                }
            }
        }
        return ans;
    }
};