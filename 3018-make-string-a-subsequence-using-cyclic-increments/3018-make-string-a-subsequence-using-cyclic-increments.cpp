class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int i = 0,j = 0,cnt = 0;
        while(i<str1.size() and j<str2.size() and cnt != str2.size())
        {
            if(str1[i] == str2[j] or char((str1[i] - 'a'  + 1)%26 + 'a') == str2[j])
                    j++,cnt++;
            i++;
        }    
        return cnt == str2.size();
    }
};