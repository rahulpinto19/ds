class Solution {
public:
    int findMaxProd(vector<int>& nums)
    {
        int maxi = INT_MIN;
        int prod = 1;
        for(int i=0;i<nums.size();i++)
        {
            prod*=nums[i];
            maxi = max(prod,maxi);
            if(prod == 0) prod =1;
        }
        return maxi;
    }
    int maxProduct(vector<int>& nums) 
    {
        vector<int>nums2 = nums;
        reverse(nums2.begin(),nums2.end());
        return max(findMaxProd(nums),findMaxProd(nums2));
        
    }
};