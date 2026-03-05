class Solution {
public:
    int minOperations(string s) {
        int cnt1 = 0,cnt2 = 0;

        char cur = '0';
        for(auto x: s) {
            if(x != cur)cnt1++;
            cur = '0' == cur ? '1' : '0';
        }
        cur = '1';
         for(auto x: s) {
            if(x != cur)cnt2++;
            cur = '0' == cur ? '1' : '0';
        }
        return min(cnt1,cnt2);
    }
};