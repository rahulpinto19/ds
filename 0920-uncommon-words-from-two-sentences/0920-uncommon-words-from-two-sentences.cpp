class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        unordered_map<string,int>mp;
        stringstream ss(s1);
        string word;
        while(ss>>word)
        {
            mp[word]++;
        }
        stringstream ss1(s2);
        while(ss1>>word)
        {
            mp[word]++;
        }
        vector<string>ans;
        for(auto x:mp)
        {
            if(x.second == 1)
            ans.push_back(x.first);
        }
        return ans;
    }
};