class Solution {
public:
   
    int alternatingXOR(vector<int>& nums, int t1, int t2 , int index = 0) {

        unordered_map<int,int>mp1,mp2;

        int mod = 1e9 + 7;
        long long cnt1 = 0,cnt2 = 0 ,cur = 0;
        mp1[0] = 1;

        for(auto x:nums) {

            cur^=x;

            int a = cur^t1;
            int b = cur^t2;


            cnt2 = mp1.count(a) ? mp1[a] : 0;
            cnt1 = mp2.count(b) ? mp2[b] : 0;

            mp1[cur] = (mp1[cur] + cnt1)%mod;
            mp2[cur] = (mp2[cur] + cnt2)%mod;

        }

        return (cnt1 + cnt2)%mod;
        
    }
};