class Solution {
public:
    string compressedString(string word) 
    {
        string ans  = "";
        char prev = word[0];
        int cnt  = 1;
        for(int i=1;i<word.size();i++)
        {
            if(prev == word[i] and cnt<9)
                cnt++;
            else
            {
                ans+= char(cnt + '0');
                ans+=prev;
                cnt = 1;
                prev = word[i]; 
            }
        }
         ans+= char(cnt + '0');
                ans+=prev;
        return ans;
        
    }
};