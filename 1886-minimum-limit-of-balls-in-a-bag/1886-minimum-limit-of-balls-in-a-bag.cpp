class Solution {
public:
    int help(vector<int>&nums,int divider,int maxOp)
    {
        int n = nums.size();
        int ans = 0; 
        for(int i = n-1; i>=0  ; i-- )
        {
            ans += (nums[i] / divider);
            ans += (!(!(nums[i] % divider)));
        } 
        
        return ans;
    }
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        sort(nums.begin(),nums.end());
        

        int n = nums.size();
           
        int start = 1,end = nums[n-1]; 
        int requiredBoxes = n + maxOperations;
        int ans = nums[n-1];
        while(start<=end)
        {
            int mid = (start + end)/2;
            
            int cValue = help(nums,mid,maxOperations);
            if(cValue <= requiredBoxes)
            {
                ans = min(ans,mid);
                end = mid -1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};