class Solution {
public:
    bool found = false;
    int dp[301];
    bool help(string s,int pos,vector<string>&word)
    {
        if(pos>=s.size())
        {
            return 1;
        }
        bool ans = 0;
        if(dp[pos] !=-1)
        return dp[pos];
        for(int i=0;i<word.size();i++)
        {
            if(word[i][0] == s[pos])
            {
                
                int flag = 1,j;
                for(j = 0; j<word[i].size();j++)
                {
                   
                    if(pos+j >= s.size() || s[pos+j] != word[i][j])
                    {
                        flag = 0;
                        break;
                    }
                }
               
                if(flag)
                {
                    ans|=help(s,pos+word[i].size(),word);
                }
            }
        }
        dp[pos] = ans;
        return ans;
    }
    bool wordBreak(string s, vector<string>& word) 
    {
        memset(dp,-1,sizeof(dp));
        return help(s,0,word);
    }
};