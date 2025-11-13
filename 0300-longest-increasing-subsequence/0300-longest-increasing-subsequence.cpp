class Solution {
public:
    int dp[2501][2502];
    int help(int ind,vector<int>&nums,int prev) {

        if(ind >= nums.size()) return 0;

        int a = 0,b = 0;
        
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];

        if(prev== -1 || nums[ind] > nums[prev]) {
            a = 1 + help(ind+1,nums,ind);
        }
        b = help(ind+1,nums,prev);

        return dp[ind][prev+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return help(0,nums,-1);

    }
};