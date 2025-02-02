class Solution {
public:
    int maxScore(vector<int>& nums, int k) 
    {
        int ans = 0;
        int currSum = 0;
        for(int i = nums.size()-k;i< nums.size();i++)
        {
            currSum+=nums[i];
        }
        ans = currSum;
        for(int i=0;i<k;i++)
        {
            currSum+=nums[i] - nums[nums.size()-k+i];
            ans = max(ans,currSum);
        }
        return ans;
    }
};