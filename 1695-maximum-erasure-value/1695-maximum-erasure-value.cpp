class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
    //    set<int>st;
    unordered_map<int,int>mp;
    int start = 0,sum = 0,ans = 0;
    for(int i = 0;i<nums.size();i++) {

        sum+=nums[i];
        mp[nums[i]]++;
        while(start<i and mp[nums[i]] > 1) {
            sum-=nums[start];
            mp[nums[start]]--;
            start++;
            
        }
        // cout<<sum<<" ";
        ans = max(ans,sum);
    }
        return ans;
    }
};