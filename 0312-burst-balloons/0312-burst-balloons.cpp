class Solution {
public:
    int dp[301][301];
    int help(vector<int>& nums,int start,int end)
    {
        if(start>end)
            return 0;
        if(start == end)
        {
            int i = start;
            int temp = nums[i];
            temp*=nums[i-1];
            temp*=nums[i+1];
            return temp;
        }
        if(dp[start][end] != -1)
            return dp[start][end];
        int ans = 0;
        for(int i= start;i<=end;i++)
        {
            int temp = nums[i] * nums[start - 1] * nums[end + 1];
            
            temp+= help(nums,start,i-1) + help(nums,i+1,end);

            ans = max(ans,temp);
        }
        return dp[start][end] = ans;
    }
    int maxCoins(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        vector<int>v;
        v.push_back(1);
        for(auto x:nums) v.push_back(x);
        v.push_back(1);

        return help(v,1,v.size()-2);
    }
};