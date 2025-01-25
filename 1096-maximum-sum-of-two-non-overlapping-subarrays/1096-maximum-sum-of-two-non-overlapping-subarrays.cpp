class Solution {
public:
    int help(vector<int>&prefixsum,int firstl,int secondl)
    {
        int n = int(prefixsum.size())-1;
        int ans = 0;
        for(int i = 0;i<n-firstl;i++)
        {
            for(int j = i+firstl;j<n-secondl + 1;j++)
            {
                ans = max(ans,prefixsum[i+firstl] - prefixsum[i] + prefixsum[j+secondl] - prefixsum[j]);
            }
        }
        cout<<endl;
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstlen, int secondlen) 
    {
        vector<int>prefixsum = {0};
        for(int i = 0;i<nums.size();i++)
        {
            prefixsum.push_back(prefixsum[i] + nums[i]);
        }
        int ans = 0;
        ans = max(help(prefixsum,firstlen,secondlen),help(prefixsum,secondlen,firstlen));
        return ans;
    }
};