class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        vector<vector<int>>v(mat.size()+1,vector<int>(mat[0].size()+1,0));

        for(int j = 1;j<=mat[0].size();j++) {
            for(int i = 1;i<=mat.size();i++) {

                v[i][j] += v[i-1][j] + mat[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i =1;i<=mat.size();i++) {
            for(int j = 1;j<=mat[0].size();j++) {

                int cnt = 1;
                v[i][j] += v[i][j-1];
                while(i-cnt>=0 and j-cnt >=0) {

                    if(v[i][j] - (v[i-cnt][j] + v[i][j-cnt] - v[i-cnt][j-cnt]) <= threshold) {
                        ans = max(ans,cnt);
                    }
                    cnt++;
                }
            }
        }
        return ans;
    }
};

