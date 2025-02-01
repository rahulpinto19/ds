class Solution {
public:
    bool isArraySpecial(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(i-1>=0 and nums[i-1]%2==nums[i]%2)
                return 0;
           
            if (i+1 == nums.size()-1 and nums[i]%2==nums[i+1]%2)
                return 0;
            
                
        }
        return 1;
    }
};