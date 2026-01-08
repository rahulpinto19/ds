class Solution {
public:
    int help(vector<int>&nums1,vector<int>&nums2,int i,int j) {
        
        if(i>=nums1.size() || j>=nums2.size()) {
            return -1e9;
        }

        int curr = (nums1[i] * nums2[j]);
        
        int a = 0,b=0,c=0,d=0;
        
            a = curr + help(nums1,nums2,i+1,j+1);
        
            b = help(nums1,nums2,i,j+1);
        
            c = help(nums1,nums2,i+1,j);

        return   max({curr,a,b,c});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        // return help(nums1,nums2,0,0);

        int n = nums1.size(),m = nums2.size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i = 0;i<nums1.size();i++) {
            for(int j = 0;j<nums2.size();j++) {

                dp[i][j] = nums1[i]*nums2[j];
            }
        }

        for(int i = 1;i<n;i++) {
            for(int j = 1;j<m;j++) {

                if(i-1>=0 and j-1 >=0) {
                    dp[i][j] = max({dp[i][j],dp[i-1][j-1] + dp[i][j],dp[i-1][j-1]});
                }
                if(i-1>=0) {
                    dp[i][j] = max({dp[i][j],dp[i-1][j]});
                }
                if(j-1>=0) {
                    dp[i][j] = max({dp[i][j],dp[i][j-1] });

                }
            }
        }

        for(auto x:dp) {
            for(auto y:x) {
                cout<<y<<" ";
            }
            cout<<endl;
        }
       return dp[n-1][m-1];
    }
};
