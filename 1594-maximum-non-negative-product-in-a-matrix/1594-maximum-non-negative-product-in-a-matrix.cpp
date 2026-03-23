class Solution {
public:
    // int safe_mul(int a, int b, int m = 1e9+7) {
    // // Cast one to long long to ensure the product is 64-bit
    //     long long res = (1LL * a * b) % m;
    //     return (int)res;
    // }
    int maxProductPath(vector<vector<int>>& grid) {
        
        int m = grid.size(),n = grid[0].size();
        int mod = 1e9+7;
        vector<vector<pair<long long,long long>>>dp(m,vector<pair<long long,long long>>(n));
        dp[0][0] = {grid[0][0],grid[0][0]};
        // cout<<dp[0][0].first<<" "<<dp[0][0].second<<endl;
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {

                if(i==0 and j==0)continue;
                vector<long long>temp;
                if(i-1>=0) {
                    temp.push_back(1LL*grid[i][j]*dp[i-1][j].first);
                    temp.push_back(1LL*grid[i][j]*dp[i-1][j].second);
                }
                if(j-1>=0) {
                    temp.push_back(1LL*grid[i][j]*dp[i][j-1].first);
                    temp.push_back(1LL*grid[i][j]*dp[i][j-1].second);
                }
                sort(temp.begin(),temp.end());
                dp[i][j] = {temp[0],temp[temp.size()-1]};  
            }
        }
        long long cur = dp[m-1][n-1].second;
        return cur < 0 ? -1 : cur%mod;

    }
};
