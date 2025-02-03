class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       unordered_set<char>st;

       int i=0,j = 0,n = s.size(), ans = 0;
       while(i<n and j<n)
       {
            if(st.find(s[j]) == st.end())
            {
                st.insert(s[j++]);
                ans = max(ans,j-i);
            }
            else
                st.erase(s[i++]);
       }
       return ans;

    }
};