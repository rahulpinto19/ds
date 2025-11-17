class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int lastOne = INT_MAX;

        for(int i = 0;i<nums.size();i++) {

            if(nums[i] == 1 ) {

                if(i - lastOne <= k and lastOne != INT_MAX) {
                    cout<<i;
                    return false;
                }
                
                lastOne = i;
            }
        }
        return true;
    }
};