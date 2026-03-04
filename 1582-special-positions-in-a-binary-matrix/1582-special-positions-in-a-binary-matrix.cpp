class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        vector<int>r(mat.size(),0),c(mat[0].size(),0);

        for(int i = 0;i<mat.size();i++) {
            for(int j = 0;j<mat[0].size();j++) {
                if(mat[i][j]) 
                    r[i]++,c[j]++;
            }
        }
        int ans = 0;
        for(int i = 0;i<mat.size();i++) {
            for(int j = 0;j<mat[0].size();j++) {
                if(mat[i][j] and r[i] == 1 and c[j] == 1) ans++;
            }
        }
        return ans;
    }
};