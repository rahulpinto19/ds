class Solution {
public:
    bool help(string s1,string s2)
    {
        if(s1.size()>s2.size())
            return 0;
        else if (s1.size() == s2.size())
            return s1 == s2;
        else
        {
            string sub1 = s2.substr(0,s1.size());
            string sub2 = s2.substr(s2.size()-s1.size(),s1.size());
            
            // reverse(sub2.begin(),sub2.end());
            cout<<sub1<<" "<<sub2<<endl;
            return  sub1 == s1 and sub2 == s1;
        }
    }
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int ans =0;
        for(int i=0;i<words.size();i++)
        {
            for(int j= i+1;j<words.size();j++)
            {
                ans += help(words[i],words[j]);
            }
        }
        return ans;
    }
};