class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
       int ans = nums[0];
       int cnt = 0;
       for(auto x:nums)
       {
            if(ans == x)
                cnt++;
            else
                cnt--;
            if(cnt == 0)
            {
                cnt = 1;
                ans = x;
            }
       }
       return ans;
    }
};