class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        int first = 0,second = n,max = 1001;
        for(int i =0;i<2*n;i++)
        {
            if(i&1)
                nums[i] = (nums[second++]%max)*max + nums[i];
            else 
            nums[i] = (nums[first++]%max)*max + nums[i];
        }    
        for(auto &x:nums)
            x/=max;
        return nums;
    }
};

// [2x+2 , 3x + 5, 5x + 1, x + 4,7x]
// [2,3,5,1,7]