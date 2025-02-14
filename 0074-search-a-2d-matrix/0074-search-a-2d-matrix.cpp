class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
       int i = 0,j  = mat[0].size()-1;
       while(i<mat.size() and j>=0)
       {
            if(mat[i][j] == target)
                return true;
            if(i+1<mat.size() and mat[i+1][j] <= target )
                i+=1;
            else
                j-=1;
       }
       return false;
    }
};