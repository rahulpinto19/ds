class Solution {
public:
    int maxScore(string s) 
    {
        int ones = 0,zeros = 0;
        for(auto x:s)
            if(x == '1')ones++;
        int ans = 0;

        for(int i = 0;i<s.size()-1;i++)
        {
            s[i] == '1' ? ones-- : zeros++;
            ans = max(ans,ones+zeros);
        }
        return ans;
    }
};