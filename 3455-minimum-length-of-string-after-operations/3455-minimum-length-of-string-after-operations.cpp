class Solution {
public:
    int minimumLength(string s) 
    {
        vector<int>cnt(26,0);
        for(auto x:s)
        {
            cnt[x-'a']++;
        }    
        int ans = 0;
        for(auto x:cnt)
        {
            if(x%2) ans+=1;
            else ans += x ? 2:0; 
        }
        return ans;
    }
};