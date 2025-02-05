class Solution {
public:
    string reverseWords(string s) 
    {
        string temp = "";
        string ans = "";
        int i = 0;
        while(i<s.size())
        {
            while(i<s.size() and s[i] == ' ')
                i++;
            
            while(i<s.size() and s[i] != ' ')
                temp+=s[i++];
            
            reverse(temp.begin(),temp.end());
            ans+=temp;
            if(temp.size())
            ans+=' ';
            temp.clear();

        }    
       
        reverse(ans.begin(),ans.end());
        ans = (ans.substr(1,ans.size()));
        return ans;
    }
};