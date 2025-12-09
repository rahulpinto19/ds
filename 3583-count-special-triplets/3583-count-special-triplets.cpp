class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        const int mod = 1e9 + 7;

        unordered_map<int,int>prev,next;
        for(auto x:nums)next[x]++;
        long long res = 0;

        for(auto x:nums) {
            next[x]--;
            res = (res + ((long long )(prev[x*2]) * next[2*x] % mod))%mod;
            prev[x]++;
        }
        return res;
    }
};