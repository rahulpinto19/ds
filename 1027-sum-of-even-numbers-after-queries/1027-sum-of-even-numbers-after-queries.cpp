class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0;
        vector<int>res;
        vector<int>vis(nums.size(),0);
        for(int i = 0;i<nums.size();i++) {
            
            if(nums[i]%2 == 0) {
                sum+=nums[i];
                vis[i] = 1;
            }
        }
        for(auto x:queries) {

            if(vis[x[1]]) {
                sum-= nums[x[1]];
            }

            nums[x[1]] += x[0];

            if(nums[x[1]]%2 == 0) {
                
                vis[x[1]] = 1;
                sum+=nums[x[1]];
            }
            else vis[x[1]] = 0;

            res.push_back(sum);
        }
        return res;
    }
};