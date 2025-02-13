class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& s) 
    {
        sort(s.begin(),s.end());

        vector<vector<int>>ans = {s[0]};

        for(int i=1;i<s.size();i++)
        {
            if(ans.back()[1]>=s[i][0] and s[i][0] >= ans.back()[0])
                ans.back()[1] = max(ans.back()[1],s[i][1]);
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};