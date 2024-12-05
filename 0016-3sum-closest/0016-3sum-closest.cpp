class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int closest  = INT_MAX;
        int n = nums.size();
        int ans = 0;
       for(int i=0;i<n-2;i++)
       {
            int j = i+1,k = n-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(sum-target) < closest)
                {
                    ans = sum;
                    closest = abs(sum-target);
                }
                if(sum < target)
                    j++;
                else if (sum>target)
                    k--;
                else
                    return sum;
            }
       }
        return ans;
    }
};