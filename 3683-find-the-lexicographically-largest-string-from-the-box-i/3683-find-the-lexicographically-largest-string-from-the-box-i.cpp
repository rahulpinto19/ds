class Solution {
public:
    string answerString(string word, int numFriends) 
    {
        if(numFriends == 1)
            return word;
        int n = word.size();

        int m = n - numFriends + 1;
        string ans = "";     
        for (int i = 0; i < n; i++) 
            ans = max(ans,word.substr(i,m));
        return ans;
    }
};