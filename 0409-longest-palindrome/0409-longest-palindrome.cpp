class Solution {
public:
    int longestPalindrome(string s) 
    {
        map<char,int>mp;
        for(auto x:s )
        mp[x]++;

        int odd = 0;

        int ans = 0;
        for(auto x:mp)
        {
            ans+= x.second & 1 ? x.second-1 : x.second; 
            x.second & 1 ? odd++ : odd;
        }    

        return !(!odd) + ans;
    }
};