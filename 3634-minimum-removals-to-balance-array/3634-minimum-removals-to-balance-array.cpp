class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int end = 0,ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {

            int flag = 0;
            while (end < nums.size() and ((1LL*nums[i]*k)) >= nums[end]) {
                flag = 1;
                end++;
            }
            // cout<<i<<" "<<end<<endl;
            if(flag)
            ans = min(ans, (int(nums.size()) - abs(i - end)));
        }
        return ans == INT_MAX ? 1 : ans;
    }
};
// 1 2 6 9
// 18,22,58,68
