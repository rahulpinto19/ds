class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        {
            int first= (nums[n]*nums[n-1]*nums[n-2]);
            int second=(nums[0]*nums[1]*nums[n]);
            return max(first,second);
        }   
    }
};