class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        for(int i = 0;i<points.size()-1;i++) {

            int x = points[i][0];
            int y = points[i][1];
            int nx = points[i+1][0];
            int ny = points[i+1][1];

            ans += max(abs(x-nx),abs(y-ny));
        }
        return ans;
    }
};