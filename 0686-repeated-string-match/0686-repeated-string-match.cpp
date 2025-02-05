class Solution {
public:
    int help(string a,string b,int pos)
    {
        int cnt = !(!pos);
        int ptr = pos;
        for(int i=0;i<b.size();i++)
        {
            if(!(ptr%=a.size()))
                cnt++;
            if(b[i] == a[ptr])
                ptr++;
            else
                return INT_MAX;
        }
        return cnt;
    }
    int repeatedStringMatch(string a, string b) 
    {
        int ans = INT_MAX;
        for(int i = 0;i<a.size();i++)
        {
            if(a[i] == b[0])
            ans = min(ans,help(a,b,i));
        }    
        return ans == INT_MAX ? -1 : ans;
    }
};