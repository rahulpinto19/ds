class Solution {
public:
    int help(int force,vector<int>&p,int m) {

        int prev = p[0];

        int balls  = 1;
        for(int i = 1;i<p.size();i++) {

            if(p[i] - prev >= force) {
                prev = p[i];
                balls++;
            }
            if(balls == m) break;
        }
        return balls == m;
    }
    int maxDistance(vector<int>& p, int m) {


        sort(p.begin(),p.end());
        int n = p.size();
        int low = 1,high = p[n-1] - p[0];

        int ans = 0;
        while(low <= high) {

            int mid = (low + high)/2;

            if(help(mid,p,m)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};


// 1 2 3 4 8

// 1 - 8 -> 


