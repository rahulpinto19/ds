class Solution {
public:
    long long dividePlayers(vector<int>& s) 
    {
        sort(s.begin(),s.end());    
        long long ans = 0;
        long long set = s[0] + s[s.size() - 1];
        int l = 0,r = s.size() -1 ;
        while(l<r)
        {
            long long diff = s[l] + s[r];
            ans+= s[l++] * s[r--];
            if(diff != set) return -1;
        }
        return ans;
    }
};