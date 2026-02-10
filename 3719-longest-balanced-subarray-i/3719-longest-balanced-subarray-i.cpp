class Solution {
public:
    
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>v;
        int ans = 0;
        for(int i = 0;i<n;i++) {
            unordered_map<int,int>mp1,mp2;
            for(int j = i;j<n;j++) {
                 nums[j]&1 ? mp1[nums[j]]++ : mp2[nums[j]]++;
                    int cur = mp1.size() == mp2.size() ? (j-i + 1) : 0;
                    ans = max(ans,cur);
            }
        }
        for(auto x:v) {
            // ans = max(ans,help(nums,x));
        }

        return ans;
    }
};