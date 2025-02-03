class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int cnt = 0;
        int ans = nums[0];
        for(auto x:nums)
        {
            if(ans == x)
                cnt++;
            else
                cnt--;
            if(cnt == 0)
            {
                ans = x;
                cnt = 1;
            }
        }    
        return ans;
    }
};