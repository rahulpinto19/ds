class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long ans = 0;
        int lInd = s.size()-1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] == '1')
            {
                ans = ans + (lInd - i);
                lInd--;
            }
        }
        return ans;
    }
};