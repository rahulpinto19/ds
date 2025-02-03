class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<n-3;i++)
        {
            long long req = target-nums[i];
            for(int j=i+1;j<n-2;j++)
            {
                long long req1 =req-nums[j]; 
                int start = j+1;
                int end = n-1;
                while(start<end)
                {
                    int sum = nums[start] + nums[end];
                    if( sum == req1)
                    {
                        ans.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if (sum > req1)
                    {
                        end--;
                    }
                    else
                        start++;
                }
            }
        }
        return {ans.begin(),ans.end()};
    }
};