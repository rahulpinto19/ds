class Solution {
public:
    string ans = "";
    void dfs(int n,int &k,string curr)
    {
        if(ans.size()) return;
        if(curr.size() == n)
        {
            k--;
            if(k == 0)
            ans = curr;
            return;
        }
        for(char c = 'a';c<='c';c++)
        {
            if(curr.size()==0 || curr.back() != c)
            {
                dfs(n,k,curr + c);
            }
        }
    }
    string getHappyString(int n, int k) 
    {
        if(k > 3 * pow(2,n-1))
            return "";
        dfs(n,k,"");
        return ans;
    }
};