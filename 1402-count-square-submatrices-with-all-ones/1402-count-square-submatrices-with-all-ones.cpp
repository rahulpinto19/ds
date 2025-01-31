class Solution {
public:
    int countSquares(vector<vector<int>>& mat) 
    {
        int res = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(i and j and mat[i][j])
                {
                    mat[i][j] = min({mat[i][j-1],mat[i-1][j],mat[i-1][j-1]})  + 1;
                }
                res+=mat[i][j];
            }
        }    
        return res;
    }
};