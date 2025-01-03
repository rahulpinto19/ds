class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum1(0),sum2(0);
        for(auto x:nums) sum1+=x;

        int ans(0);
        for(int i = 0;i<nums.size()-1;i++)
        {
            sum2+=nums[i];
            sum1-=nums[i];

            ans+= (sum2 >= sum1);
        }
        return ans;
    }
};