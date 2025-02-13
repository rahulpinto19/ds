class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i = 0,start = 0,end = nums.size()-1;
        while(i<=end)
        {
            if(nums[i] == 0)
            {
                swap(nums[i++],nums[start++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i],nums[end--]);
            }
            else
                i++;
        }
    }
};

/*
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
*/ 