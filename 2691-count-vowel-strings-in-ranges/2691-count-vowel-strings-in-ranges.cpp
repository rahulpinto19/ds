class Solution {
public:
    int isvowel(char cr)
    {
        if(cr == 'a' || cr == 'e' || cr == 'i' || cr == 'o' || cr == 'u')
            return 1;
        else 
            return 0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        vector<int>v;
        for(auto x:words)
        {
            v.push_back(isvowel(x[0]) and isvowel(x[x.size()-1]));
        }    
        for(int i=1;i<v.size();i++)
        {
            v[i]+=v[i-1];
        }
        vector<int>ans;

        for(auto x:queries)
        {
            if(x[0] == 0)
                ans.push_back(v[x[1]]);
            else
                ans.push_back(v[x[1]] - v[x[0]-1]);
        }
        return ans;
    }
};