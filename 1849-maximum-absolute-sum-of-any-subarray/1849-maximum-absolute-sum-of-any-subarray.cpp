class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        int currSum1 = 0,currSum2 = 0;

        for(auto x:nums)
        {
            if(currSum1<0)
            {
                currSum1 = 0;
            }
            if(currSum2>0)
           {
                currSum2 = 0;
           } 
           currSum1+=x;
           currSum2+=x;
           maxSum = max(currSum1,maxSum);
           minSum = min(minSum,currSum2);
        }
        return max(maxSum,abs(minSum));
    }
};