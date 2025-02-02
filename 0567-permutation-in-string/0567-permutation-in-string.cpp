class Solution {
public:
    bool canform(string str,vector<int>v)
    {
        // cout<<str<<endl;
        for(auto x:str)
        {
            v[x-'a']--;
        }
        for(auto x:v)
        {
            if(x!=0)
                return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size())
            return 0;
        vector<int>hash(26,0);
        for(auto x:s1)
        hash[x-'a']++;
        for(int i = 0;i<=s2.size()-s1.size();i++)
        {

            if(canform(s2.substr(i,s1.size()),hash))
                return 1;
        }
        return 0;
    }
};