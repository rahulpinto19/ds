class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int start = 0,end = n-1,i = 0;
        while(i<=end)
        {
            if(nums[i] == 0)
            {
                swap(nums[start++],nums[i++]);
            }
            else if(nums[i] == 2)
            {
                swap(nums[end--],nums[i]);
            }
            else
            i++;
        }    
    }
};