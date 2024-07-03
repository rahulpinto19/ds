class Solution {
public:
    int minDifference(vector<int>& nums) 
    {
        if(nums.size()<=3)
        return 0;

        sort(nums.begin(),nums.end());
        
        int ans = INT_MAX;
        for(int i=0;i<=3;i++)
        {
            ans = min(ans,nums[nums.size()-1-i] - nums[3-i]);
        }
        return ans;
        
    }
};