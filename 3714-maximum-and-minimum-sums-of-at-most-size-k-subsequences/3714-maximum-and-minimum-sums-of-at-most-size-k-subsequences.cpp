class Solution {
public:
#define ll long long
const int mod = 1e9 + 7;
vector<ll> fact, invFact;
// ll modPow(ll base, ll exp, int mod) {
//     ll result = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1) result = result * base % mod;
//         base = base * base % mod;
//         exp >>= 1;
//     }
//     return result;
// }
ll modPow(ll base,ll exp)
{
    ll result = 1;
    while(exp)
    {
        if(exp&1) result = result*base%mod;
        base = base*base%mod;
        exp>>=1;
    }
    return result;
}
void computeFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = invFact[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[n] = modPow(fact[n], mod - 2);
    for (int i = n - 1; i >= 1; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }
}

ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}


    int minMaxSums(vector<int>& nums, int k) 
    {
        int n =  nums.size();
        computeFactorials(n);
        long long res = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
        {
            for(int size = 1;size<=k;size++)
            {
                ll Min = nums[i] * nCr(n-i-1,size - 1) % mod;
                ll Max = nums[i] * nCr(i,size-1) % mod;
                res = (res + Min + Max) % mod;
            }
        }
        return res;
    }
};