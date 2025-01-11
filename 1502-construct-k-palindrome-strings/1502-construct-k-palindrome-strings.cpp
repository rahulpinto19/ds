class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if(s.size() == k)
            return true;
        if(s.size() < k)
            return false;
        
        vector<int>v(26,0);
        
        for(auto x:s)
        {
            v[x-'a']++;
        }
        int ind = 0,cnt = 0;
        for(int i = 0;i<k;i++)
        {
            while(ind<26 and v[ind]<=1)
                ind++;
            if(ind<26 )
            {
                v[ind]-=2;
                cnt++;
            }
            else
                break;
        }
        int ReaminingCnt = 0;
        for(int i =0;i<26;i++)
            if(v[i]%2) ReaminingCnt++;
        
        return ReaminingCnt  <= k;
    }
};