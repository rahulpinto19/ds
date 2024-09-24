class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map<int,int>mp;
        for(auto x:arr1)
        {
            int val = x;
            while(val)
            {
                mp[val] =1;
                val/=10;
            }
        }   
        int ans = 0; 
        for(auto x:arr2)
        {
            int val = x;
            while(val)
            {
                if(mp.find(val) != mp.end())
                {
                    ans = max(ans,int(log10(val)+1));
                }
                val/=10;
            }
        }
        return ans;
    }
};