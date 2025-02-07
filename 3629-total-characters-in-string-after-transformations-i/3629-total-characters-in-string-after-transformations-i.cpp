class Solution {
public:
    int lengthAfterTransformations(string s, int t) 
    {
        int mod = 1e9 + 7;
        vector<long long>freq(26,0);
        for(auto x:s)
        {
            freq[x-'a']++;
        }    
        for(int i = 0;i<t;i++)
        {
            int val = freq[25];
            for(int i = 25;i>=1;i--)
            {
                freq[i] = freq[i-1];
            }
            freq[0] = val;
            freq[1] =(freq[1]%mod  +  val)%mod;
        }
     
        int res = 0;
        for(auto x:freq)
        {
            res = (res%mod + x) %mod;
        }
        return res;
    }
};