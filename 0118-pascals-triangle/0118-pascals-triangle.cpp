class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>ans;
        vector<int>prev;
        while(numRows--)
        {
            vector<int>curr(prev.size()+1,1);
            for(int i = 1;i<prev.size();i++)
            {
                curr[i] = prev[i-1] + prev[i];
            }
            ans.push_back(curr);
            prev = curr;
        }
        return ans;
    }
};