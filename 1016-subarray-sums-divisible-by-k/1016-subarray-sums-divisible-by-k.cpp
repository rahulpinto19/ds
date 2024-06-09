class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        int pref_sum = 0;
        mp[0]++;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
           pref_sum =(pref_sum + nums[i]%k + k)%k;
           ans+=mp[pref_sum];
           mp[pref_sum]++; 
        }    
        return ans;
    }
};