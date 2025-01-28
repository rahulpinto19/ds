class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int orig = count(nums.begin(),nums.end(),k),mx = 0;

        for(int m = 1;m<=50;m++)
        {
            if(m == k) continue;
            int cnt = 0,mxcnt = 0;
            for(int a:nums)
            {
                cnt+= (a == m) ? 1: a == k ? -1 : 0 ;
                cnt = max(cnt,0);
                mxcnt = max(mxcnt,cnt);
            }
            mx = max(mx,mxcnt);
        }
        return mx + orig;
    }
};