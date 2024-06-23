class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
       int sum = 0,cnt = 0;
       unordered_map<int,int>mp;
       mp[0]++;
       for(auto &x:nums)
       x = x&1;

        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
            cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;

    }
};