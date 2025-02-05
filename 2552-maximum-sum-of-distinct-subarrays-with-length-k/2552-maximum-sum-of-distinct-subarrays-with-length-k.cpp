class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        long long ans = 0;
        long long sum = 0;

        int start = 0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            sum+=nums[i];

            if(i>=k)
            {
                mp[nums[start]]--;
                sum-=nums[start];
                
                if(mp[nums[start]] == 0)
                mp.erase(nums[start]);
                start++;
            }
            if(mp.size() == k)
                ans = max(ans,sum);
        }
        return ans;
    }
};