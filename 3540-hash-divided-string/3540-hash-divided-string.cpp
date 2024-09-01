class Solution {
public:
    string stringHash(string s, int k) 
    {
        string res = "";
        for(int i=0;i<s.size();i+=k)
        {
            string substr = s.substr(i,k);
            int val = 0;
            for(auto x:substr)
            {
                val+= x-'a';
            }
            val%=26;
            res+=char('a' + val);
        }    
        return res;
    }
};