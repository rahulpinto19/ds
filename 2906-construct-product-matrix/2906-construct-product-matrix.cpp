class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        long long rProd = 1;
        int m = grid.size(),n = grid[0].size();
        int mod = 12345;
        vector<vector<int>>p(m,vector<int>(n,1));

        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                p[i][j] = rProd;
                rProd = (1LL*rProd*grid[i][j])%mod;
            }
        }
        rProd = 1;
        for(int i = m-1;i>=0;i--) {
            for(int j = n-1;j>=0;j--) {
                p[i][j] = (p[i][j]*rProd)%mod;
                rProd = (rProd*grid[i][j])%mod;
            }
        }
        return p;
    }
};