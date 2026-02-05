class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>res(nums.size(),0);    
        for(int i =0;i<nums.size();i++)
            {
                if(nums[i]>=0)
                {
                    res[i] = nums[(i + nums[i])%n];
                }
                else
                {
                    
                    res[i] = nums[(n + i + nums[i]%n)%n];
                }
                
            }
        return res;
    }
};