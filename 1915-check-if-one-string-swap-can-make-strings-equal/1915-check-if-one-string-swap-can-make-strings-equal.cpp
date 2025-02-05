class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        int swaps = 0;
        
        for(int i = 0;i<s1.size();i++)
        {
            swaps += (s1[i] != s2[i]);
        }    
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1 != s2)
            return false;
            
        return (swaps==2 or swaps == 0);
    }
};