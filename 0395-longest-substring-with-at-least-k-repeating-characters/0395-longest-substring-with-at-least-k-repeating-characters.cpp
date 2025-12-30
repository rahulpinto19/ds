class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size();

        vector<int>freq(26,0);

        for(auto x:s) {
            freq[x-'a']++;
        }

        for(int i = 0;i<n;i++) {

            if(freq[s[i]-'a'] < k) {

                return max(
                    longestSubstring(s.substr(0,i),k),
                    longestSubstring(s.substr(i+1),k)
                );
            }

        }
        return n; 

    }
};