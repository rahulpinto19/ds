class Solution {
public:
    int numSub(string s) {
        
        int mod = 1e9  + 7;
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++) {

            if(s[i] == '1') {
                cnt++;
                ans = (ans%mod + cnt%mod)%mod;
            }
            else{
                cnt = 0;
            }
        }
        return ans;
    }
};