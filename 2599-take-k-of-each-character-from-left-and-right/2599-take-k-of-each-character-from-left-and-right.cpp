class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        if(k == 0)
        return 0;
        int n = s.size();
        int ans = -1;
        int end = 0;
        vector<int>v(3,0);
        for(int i=n-1;i>=0;i--)
        {
            v[s[i]-'a']++;
            if(v[0]>=k and v[1]>=k and v[2]>=k)
            {ans = n-i;end = i;break;}
        }
        if(ans == -1)
            return -1;
        
        for(int start = 0;start<n;start++)
        {
            v[s[start]-'a']++;
            while(end<n and v[s[end]-'a']-1 >= k)
            {
                // cout<<start<<" "<<n-end<<endl;
                ans = min(ans,n - end + start );
                v[s[end]-'a']--;
                end++;
            }
        }
        return ans;
    }
};