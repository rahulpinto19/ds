class Solution {
public:
    long long minEnd(int n, int x) 
    {
       n--;
       long long ans = x;
       long long val = n;
       for(long long i=0;i<64;i++)
       {
            if(((ans>>i) & (1)) == 0 )
            {
                // cout<<((val&1)<<i)<<endl;
                ans = ((val&1)<<i)|ans;
                val/=2;
            }
       }
       return ans;
    }
};