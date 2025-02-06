class Solution {
public:
    const int base = 31;
    const int mod = 1e9 + 7;
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size(),m = needle.size();
        if(needle.size() > haystack.size())
            return -1;
        long long pow = 1;
        long long textHash = 0,patternHash = 0;
        for(int i= 0;i<m;i++)
        {
            textHash = (textHash*base + (haystack[i]-'a' + 1))%mod;
            patternHash = (patternHash*base + (needle[i]-'a' + 1))%mod;

            if(i<m-1)
            pow = (pow*base)%mod;
        }
        for(int i=0;i<=n-m;i++)
        {
            cout<<textHash<<" "<<patternHash<<endl;
            if(textHash == patternHash)
            {
                if(haystack.substr(i,m) == needle)
                return i;
            }
            if(i<n-m)
            {
                textHash = (textHash - (haystack[i]-'a' + 1)*pow)%mod;
                textHash = (textHash*base + (haystack[i+m]-'a' + 1))%mod;

                if(textHash<0) textHash+=mod;
            }
        }
        return -1;
    }
};