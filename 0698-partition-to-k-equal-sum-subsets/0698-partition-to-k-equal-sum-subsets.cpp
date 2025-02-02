class Solution {
public:
    int currsum;
    bool findAll(vector<int>&nums,vector<int>&vis,int target,int currsum,int pos,int nSubset)
    {
        if(nSubset == 1)
            return true;
        if(target == currsum)
        {
            return findAll(nums,vis,target,0,0,nSubset-1);;
        }
        for(int i = pos;i<nums.size();i++)
        {
            if(currsum + nums[i] > target) continue;
            if(!vis[i])
            {
                vis[i] = 1;
                if(findAll(nums,vis,target,currsum + nums[i],i+1,nSubset)) return true;
                vis[i] = 0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        currsum = k;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum<k || sum%k) return false;
        vector<int>vis(nums.size()+1,0);
        return findAll(nums,vis,sum/k,0,0,k);    
    }
};