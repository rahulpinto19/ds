class Solution {
public:
    int residuePrefixes(string s) {
        set<int>st;
        int cnt = 0;
        int prev = 0;
        for(int i = 0;i<s.size();i++) {
            st.insert(s[i]);

            if(st.size() == (i+1)%3 ) cnt++;
            
        }
        return cnt;
    }
};