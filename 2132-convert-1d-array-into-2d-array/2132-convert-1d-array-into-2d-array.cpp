class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        int total = m*n;
        if(total!=original.size())
        return {};
        vector<int>temp;
        vector<vector<int>>ans;
        for(int i =0;i<original.size();i++)
        {
            temp.push_back(original[i]);
            if(i%n == n-1)
            {
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};