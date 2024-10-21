class Solution {
public:
    int ans = INT_MIN;
    void help(string s,int ind,set<string>&st,string temp)
    {
        if(ind >= s.size())
        {
            ans = max(ans,int(st.size()));
            return;
        }
        temp+=s[ind];
        if(st.find(temp) == st.end())
        {
            st.insert(temp);
            help(s,ind+1,st,"");
            st.erase(temp);
            help(s,ind+1,st,temp);
        }
        else
        {
            help(s,ind+1,st,temp);
        }
    }
    int maxUniqueSplit(string s) 
    {
        set<string>st;
        help(s,0,st,"");
        return ans;
    }
};