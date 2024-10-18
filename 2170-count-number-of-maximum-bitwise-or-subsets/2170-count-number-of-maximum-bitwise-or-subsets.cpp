class Solution {
public:
    int ans =0;
    void help(vector<int>&nums,int ind,int curr,int maxOr)
    {
        if(curr == maxOr)
        {
            ans++; 
        }
        for(int index = ind;index<nums.size();index++)
        {
            help(nums,index+1,curr|nums[index],maxOr);
        }

    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int maxOr = -0;

        for(auto x:nums)
        maxOr|=x;

        help(nums,0,0,maxOr);    
        return ans;
    }
};