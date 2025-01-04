class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]].push_back(i);
            }
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            if(mp[s[i]].size()==1)
            {
                mp[s[i]].push_back(i);
            }
        }
        int result =0;
        for(auto x:mp)
        {
            vector<int>temp = x.second;
            if(temp[1]-temp[0]>1)
            {
                set<int>st;
                for(int i=temp[0]+1;i<s.size() and i<temp[1];i++)
                {
                    st.insert(s[i]);
                }
                result+=st.size();
            }
        }
        return result;
    }
};