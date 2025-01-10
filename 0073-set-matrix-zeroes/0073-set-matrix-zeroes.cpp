class Solution {
public:
    void change(vector<vector<int>>& array,int i,int j)
    {
        for(int l=0;l<array.size();l++)
        {
            array[l][j]=0;
        }
        for(int m=0;m<array[0].size();m++)
        {
            array[i][m]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<pair<int,int>> zeroes;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    zeroes.push_back({i,j});
                }
            }
        } 
        for (auto p: zeroes)   
        {
            change(matrix,p.first,p.second); 
        }
    }
};