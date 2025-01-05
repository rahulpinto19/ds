class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
         vector<int>v(s.size()+1,0);
        for(auto range:shifts)
        {
                int val;
                val = range[2] == 0 ? -1 : 1;

                v[range[0]] += val;
                v[range[1] + 1] -= val;
        }
        
        for(int i = 0;i<s.size();i++)
        {
            if(i>=1)
            v[i]+=v[i-1];
            s[i] = ((s[i] - 'a'  + 26 + v[i]%26 )%26 + 'a');
        }
        return s;
    }
};