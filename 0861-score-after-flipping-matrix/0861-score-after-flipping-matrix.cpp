class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        for(int i = 0;i<grid.size();i++) {
                if(grid[i][0]) continue;
            for(int j = 0;j<grid[0].size();j++) {
                
                grid[i][j] = !grid[i][j];
            }
        }

        int res = 0;
        int m = grid[0].size() - 1;
        for(int j = 0;j<grid[0].size();j++) {

            int zero = 0,one = 0;
            for(int i = 0;i<grid.size();i++) {

                grid[i][j] == 0 ? zero++ : one++;
            }

            res += (1<<(m-j)) * max(one,zero);
        }
        return res;
    }
};