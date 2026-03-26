class Solution {
public:
    vector<vector<int>>rotate(vector<vector<int>>&mat) {

        int n = mat.size(),m = mat[0].size();
        vector grid(m,vector<int>(n));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                grid[j][n-1-i] = mat[i][j];
            }
        }
        return grid;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {

        long long totSum = 0;
        long long cur = 0;
        int m = grid.size();
        int n = grid[0].size();
        long long tag = 0;
        unordered_set<long long>exist;

        for(auto x:grid) {
            for(auto y:x)
                totSum+=y;
        }     

        for(int k = 0;k<4;k++) {
            exist.clear();
            exist.insert(0);
            m = grid.size();
            n = grid[0].size();
            cur = 0;
            if(m < 2) {
                grid = rotate(grid);
                continue;
            }
            if(n == 1) {
                for(int i = 0;i<m-1;i++) {
                    cur+=grid[i][0];
                    tag = (cur*2) - totSum;
                    if(tag == 0 || tag == grid[0][0] || tag == grid[i][0])
                    return true;
                }
                grid = rotate(grid);
                continue;
            }

            for(int i = 0;i<m-1;i++) {
                // for(int j = 0;j<n;j++) {
                //     exist.insert(grid[i][j]);
                //     cur+=grid[i][j];
                // }
                for (int j = 0; j < n; j++) {
                        cur += grid[i][j];
                        exist.insert(grid[i][j]);
                }
                tag = (cur*2) - totSum;

                if(i == 0) {
                    if(tag == 0 || tag == grid[0][0])
                    return true;
                    continue;
                }
                if(exist.contains(tag)) return true;
            }
            grid = rotate(grid);
        }   
        return false;
    }
};
