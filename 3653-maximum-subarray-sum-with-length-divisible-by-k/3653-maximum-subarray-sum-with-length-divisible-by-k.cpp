class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) 
    {
        vector<long long>psum(1);
        for(auto x:nums)
            psum.push_back(psum.back() + x);

        long long ans = LLONG_MIN;
        for(int i=0;i<k;i++)
        {
            long long sum = 0;
            for(int j=i;j+k<=nums.size();j+=k)
            {
                long long n = psum[j+k] - psum[j];
                sum = max(sum+n,n);
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};