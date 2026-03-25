class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        long long totalSum = 0;
        for(auto x:grid) {
            for(auto y:x) {
                totalSum+=y;
            }
        }
        long long sum = 0;
        for(auto x:grid) {
            for(auto y:x) {
                sum+=y;
            }
            if(sum*2 == totalSum) return true;
        }
        sum = 0;
        for(int j = 0;j<grid[0].size();j++) {
            for(int i = 0;i<grid.size();i++) {
                sum+=grid[i][j];
            }
            if(sum*2 == totalSum) return true;
        }
        return false;
    }
};