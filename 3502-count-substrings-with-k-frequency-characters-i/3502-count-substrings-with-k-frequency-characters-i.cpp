class Solution {
public:
    int numberOfSubstrings(string s, int k) 
    {
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            unordered_map<int,int>mp;
            for(int j=i;j<s.size();j++)
            {
                mp[s[j]]++;

                bool take = false;
                for(auto x:mp)
                {
                    if(x.second >=k)
                    take = true;
                }
                if(take)
                ans++;
            }
        }    
        return ans;
    }
};