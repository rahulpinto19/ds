class Solution {
public:
    int help(int number,unordered_map<int,int>&mp)
    {
        
        if(mp.find(number) == mp.end())
            return 0;
        if(mp[number] != 0)
            return mp[number];
        return mp[number] = 1 + help(number-1,mp);
    }
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x] = 0;
        int ans = 0;
        for(auto x:nums)
        {
            ans = max(ans,help(x,mp));
        }
        return ans;
            
    }
};