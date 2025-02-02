class Solution {
public:
    void findMaxLength(vector<string>& arr,int pos,string currStr,int &ans)
    {
        if(pos>=arr.size())
        {
           vector<int>v(26,0);
            for(auto x:currStr)
            {
                if(v[x-'a']>=1)
                return;
                v[x-'a']++;
            }
            ans = ans>currStr.size() ? ans :currStr.size();
            return;
        }

        findMaxLength(arr,pos+1,currStr + arr[pos],ans);
        findMaxLength(arr,pos+1,currStr ,ans);
    }
    int maxLength(vector<string>& arr) 
    {
        int ans = 0;
        findMaxLength(arr,0,"",ans);     
        return ans;
    }
};