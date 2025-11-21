class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<int>first(26,-1),last(26,-1);

        for(int i = 0;i<s.size();i++) {

            if(first[s[i]-'a'] == -1)
                first[s[i]-'a'] = i;
            last[s[i]-'a'] = i;
        }
        int ans = 0;
        for(int i = 0;i<26;i++) {
            set<int>st;
            for(int j = first[i]+1;j<last[i];j++) {
                st.insert(s[j]);
            }
            ans+=st.size();
        }
        return ans;
    }
};