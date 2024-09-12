class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        set<char>st;
        for(auto x:allowed)
        {
            st.insert(x);
        }    
        int ans = words.size();
        for(auto x: words)
        {
            for(auto cr:x)
            {
                if(st.find(cr) == st.end())
                {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};