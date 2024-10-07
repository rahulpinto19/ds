class Solution {
public:
    int minLength(string s) 
    {
        if(!s.length())
            return 0;
    int i=0;
    int count=0;
    string ans="";
    while(s[i]!='\0')
    {
        if(s[i]=='A'&&s[i+1]=='B'||s[i]=='C'&&s[i+1]=='D')
        {
            i++;
            count++;
        }
        else
            ans=ans+s[i];
        i++;
    }
        cout<<ans;
    if(count>0)
        return minLength(ans);
        return s.length();
    }
};