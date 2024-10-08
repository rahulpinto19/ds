class Solution {
public:
    int minSwaps(string s) 
    {
        vector<int>v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '[')
            v.push_back(i);
        }
        stack<char>st;
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if(st.size() and s[i] == ']' and st.top() == '[')
            st.pop();
            else if ( s[i] == '[')
            st.push(s[i]);
            else
            {
                if(v.size())
                {
                    int ind = v[v.size()-1];
                    cout<<i<<" "<<ind<<endl;
                    swap(s[i],s[ind]);
                    v.pop_back();
                    ans++;
                    st.push(s[i]);
                }
                
                
            }
        }
        return ans;
    }
};