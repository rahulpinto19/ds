class Solution {
public:
    vector<string>ans;
   
    void help(string s,int pos,set<string>&st,string temp)
    {
        if(pos>=s.size())
        {
            temp.pop_back();
            ans.push_back(temp);
        }
        string currWord = ""; 
        for(int i=pos;i<s.size();i++)
        {
            currWord+=s[i];
            if(st.find(currWord) != st.end())
            {
                help(s,pos+currWord.size(),st,temp + currWord + ' ');   
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) 
    {
        set<string>st(word.begin(),word.end());
        help(s,0,st,"");
        return ans;
    }
};