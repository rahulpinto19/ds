class Solution {
public:
    int maxDistance(string s, int k) 
    {
        char dir[4][2] = {{'N','W'},{'N','E'},{'S','W'},{'S','E'}};
        int ans = 0;
        
        for(auto d:dir)
        {
            int cnt = 0,rem = k;
            for(int i= 0;i<s.size();i++)
            {
                if(s[i] == d[0] || s[i] == d[1])
                {
                    if(rem>0){cnt++;rem--;}
                    else cnt--;
                }
                else
                cnt++;
                ans = max(cnt,ans);
            }
        }    
        return ans;
    }
};