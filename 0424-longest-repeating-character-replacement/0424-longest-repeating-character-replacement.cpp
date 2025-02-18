class Solution {
public:
    int help(string s,int k,char c)
    {
        unordered_map<char,int>mp;
        int flips = 0;
        int end = 0;
        int ans = 0 ;
        for(int i = 0;i<s.size();i++)
        {

            if(s[i] != c)
                flips++;
            while(flips>k and end<=i)
            {
                mp[s[end]]--;
                if(mp[s[end]] == 0)
                    mp.erase(s[end]);
                if(s[end] != c)
                    flips--;
                end++;
            }
            ans = max(ans,i - end + 1);
            mp[s[i]]++;
        }
        return ans;
    }
    int characterReplacement(string s, int k) 
    {
        int ans = 0;
        for(char i = 'A';i<='Z';i++)
        {
            int getMax = help(s,k,i);
            ans = max(ans,getMax);
        }    
        return ans;
    }
};