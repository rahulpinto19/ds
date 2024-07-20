class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) 
    {
        int m = r.size(),n = c.size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j] = min(r[i],c[j]);
                r[i]-=ans[i][j];
                c[j]-=ans[i][j];
            }
        } 
        return ans;
    }
};