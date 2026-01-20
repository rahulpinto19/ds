class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {


        vector<int>ans;
        for(auto x:nums) {

            int val = -1;
            for(int i = 1;i<=x;i++) {

                if((i|(i+1) )== x) {
                    val = i;
                    break;
                }
            }
            ans.push_back(val);
        }
        return ans;
         
    }
};