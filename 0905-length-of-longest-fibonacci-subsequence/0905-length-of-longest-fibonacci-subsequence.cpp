class Solution {
public:
    int ans = 0;
    unordered_map<int,int>mp;
    void help(vector<int>&arr,int a,int b,int c)
    {
        ans = max(ans,c);
       if(b == arr.size()-1)
        return;
       if(a == -1)
       {
            for(int i = 0;i<arr.size();i++)
            {
                help(arr,i,b,c+1);
            }
       }
       else if(b == -1)
       {
            for(int i = a+1;i<arr.size();i++)
            {
                help(arr,a,i,c+1);
            }
       }
       else
       {
            if(mp.find(arr[a]  + arr[b]) != mp.end())
            {
                help(arr,b,mp[arr[a] + arr[b]],c+1);
            }
            else
            {
                return;
            }
       }
    }
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        for(int i = 0;i<arr.size();i++)
            mp[arr[i]] = i;
        help(arr,-1,-1,0);    
        return ans>=3 ? ans : 0;
    }
};