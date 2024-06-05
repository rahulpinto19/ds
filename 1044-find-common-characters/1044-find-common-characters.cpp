class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<int>freq(26,101);
        for(auto x:words)
        {
            for(int alphabet = 'a';alphabet<='z';alphabet++)
            {
                int val = 0;
                for(auto word:x)
                {
                    if(alphabet == word)
                    val++;
                }
                freq[alphabet -'a'] = min(freq[alphabet-'a'],val);
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++)
        {
            string temp = "" ;
            while(freq[i])
            {
                
                ans.push_back(temp + char('a' + i));
                freq[i]--;
            }
        }    
        return ans;
    }
};