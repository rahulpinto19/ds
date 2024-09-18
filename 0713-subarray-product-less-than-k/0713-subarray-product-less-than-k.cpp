class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int startIndex = 0,prod = 1;
        int ans = 0;
        for(int lastInd = 0;lastInd<nums.size();lastInd++)
        {
            prod *= nums[lastInd];
            while(prod>=k and startIndex<lastInd)
            {
                prod/=nums[startIndex++];
            }
            if(prod < k )
            ans += (lastInd - startIndex + 1);
        }
        return ans;
    }
};