class Solution {
public:
    int help(vector<int>&nums)
    {
        int ans = 1,ptr=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                {ptr++;ans = max(ans,ptr);}
            else
                ptr=1;
        }
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = help(nums);
        reverse(nums.begin(),nums.end());
        return max(ans,help(nums));
    }
};